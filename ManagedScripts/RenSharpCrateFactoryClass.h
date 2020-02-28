/*
Copyright 2020 Neijwiert

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#pragma once

#include "RenSharpCrateClass.h"
#include "IUnmanagedAttachable.h"
#include "UnmanagedContainer.h"
#include "Mda_crate.h"
#include "Imports.h"
#include "Mda_cratemanager.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_crate.h>
#include <da_cratemanager.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System;
using namespace System::Text;

namespace RenSharp
{
	public interface class IRenSharpCrateFactoryClass : public IUnmanagedAttachable<IDACrateFactoryClass^>
	{
		IDACrateClass^ CreateInstance();

		void DestroyInstance();

		bool CheckEnabled();

		bool CheckType(DACrateType type);

		bool CheckEnabledType(DACrateType type);

		property IntPtr DACrateFactoryClassPointer
		{
			IntPtr get();
		}

		property String^ Name
		{
			String^ get();
		}

		property String^ Section
		{
			String^ get();
		}

		property DACrateType Type
		{
			DACrateType get();
		}

		property IDACrateClass^ Instance
		{
			IDACrateClass^ get();
		}
	};

	generic<typename T>
	where T : IRenSharpCrateClass
	public ref class RenSharpCrateFactoryClass abstract : public IRenSharpCrateFactoryClass
	{
		private:
			bool disposedResources;
			bool destroyPointer;
			IntPtr daCrateFactoryClassPointer;
			IDACrateFactoryClass^ daCrateFactoryClass;
			String^ name;
			DACrateType type;

		public:
			RenSharpCrateFactoryClass(String^ name, DACrateType type)
				:
				disposedResources(false),
				destroyPointer(true),
				daCrateFactoryClassPointer(IntPtr::Zero),
				daCrateFactoryClass(nullptr),
				name(name),
				type(type)
			{
				if (name == nullptr)
				{
					throw gcnew ArgumentNullException("name");
				}
			}

			~RenSharpCrateFactoryClass()
			{
				if (disposedResources)
				{
					return;
				}

				DACrateManager::UnregisterManagedCrateFactory(this);

				this->!RenSharpCrateFactoryClass();

				disposedResources = true;
			}

			!RenSharpCrateFactoryClass()
			{
				if (IsAttached)
				{
					auto& crates = DACrateManagerHelper::GetCrates();
					crates.DeleteObj(InternalDACrateFactoryClassPointer);

					if (destroyPointer)
					{
						IntPtr tmp = daCrateFactoryClassPointer;
						daCrateFactoryClassPointer = IntPtr::Zero;
						Imports::DestroyDACrateFactoryClass(reinterpret_cast<::DACrateFactoryClass*>(tmp.ToPointer()));
					}
				}

				ReleasePointer();
			}

			String^ ToString() override
			{
				return name;
			}

			bool Equals(Object^ other) override
			{
				if (ReferenceEquals(other, nullptr))
				{
					return false;
				}

				IDACrateFactoryClass^ otherThis1 = dynamic_cast<IDACrateFactoryClass^>(other);
				if (otherThis1 != nullptr && daCrateFactoryClassPointer.Equals(otherThis1->DACrateFactoryClassPointer))
				{
					return true;
				}

				IRenSharpCrateFactoryClass^ otherThis2 = dynamic_cast<IRenSharpCrateFactoryClass^>(other);
				if (otherThis2 == nullptr)
				{
					return false;
				}

				return daCrateFactoryClassPointer.Equals(otherThis2->DACrateFactoryClassPointer);
			}

			int GetHashCode() override sealed
			{
				return daCrateFactoryClassPointer.GetHashCode();
			}

			virtual void InitUnmanagedAttachable() sealed
			{
				AttachToUnmanagedObject();
				RegisterManagedObject();
			}

			virtual void AttachToUnmanagedObject() sealed
			{
				if (IsAttached)
				{
					throw gcnew NotSupportedException("Already attached.");
				}

				::RenSharpCrateFactoryClass* newCrateFactory = nullptr;
				try
				{
					IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
					try
					{
						newCrateFactory = Imports::CreateRenSharpCrateFactoryClass(
							reinterpret_cast<char*>(nameHandle.ToPointer()),
							static_cast<::DACrateType::Type>(type));
					}
					finally
					{
						Marshal::FreeHGlobal(nameHandle);
					}

					IntPtr newCrateFactoryPtr = IntPtr(newCrateFactory);

					daCrateFactoryClassPointer = newCrateFactoryPtr;
				}
				catch (Exception^)
				{
					if (newCrateFactory != nullptr)
					{
						Imports::DestroyDACrateFactoryClass(reinterpret_cast<::DACrateFactoryClass*>(newCrateFactory));
					}

					throw;
				}

				daCrateFactoryClass = gcnew DACrateFactoryClass(daCrateFactoryClassPointer);

				UnmanagedAttach();
			}

			virtual void RegisterManagedObject() sealed
			{
				DACrateManager::RegisterManagedCrateFactory(this);

				ManagedRegistered();
			}

			virtual void ReleasePointer() sealed
			{
				daCrateFactoryClassPointer = IntPtr::Zero;
				daCrateFactoryClass = nullptr;
			}

			virtual void UnmanagedAttach()
			{

			}

			virtual void ManagedRegistered()
			{

			}

			virtual IDACrateFactoryClass^ AsUnmanagedObject() sealed
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				return gcnew DACrateFactoryClass(daCrateFactoryClassPointer);
			}

			virtual IDACrateClass^ CreateInstance() sealed
			{
				T managedInstance = CreateManagedInstance();
				if (managedInstance == nullptr)
				{
					return nullptr;
				}
				else
				{
					return gcnew DACrateClass(managedInstance->DACrateClassPointer);
				}
			}

			T CreateManagedInstance()
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				auto helper = reinterpret_cast<DACrateFactoryClassHelper*>(InternalDACrateFactoryClassPointer);

				auto& instance = helper->GetInstance();

				if (instance == nullptr)
				{
					T managedInstance = InternalCreateInstance();
					try
					{
						managedInstance->InitUnmanagedAttachable();

						managedInstance->Factory = gcnew DACrateFactoryClass(daCrateFactoryClassPointer);
						managedInstance->Init();

						instance = reinterpret_cast<::DACrateClass*>(managedInstance->DACrateClassPointer.ToPointer());

						return managedInstance;
					}
					catch (Exception^)
					{
#pragma push_macro("delete")
#undef delete

						delete managedInstance;
						managedInstance = T();

#pragma pop_macro("delete")

						throw;
					}
				}
				else
				{
					auto managedInstance = DACrateManager::AsManagedCrate(IntPtr(instance));
					if (managedInstance == nullptr)
					{
						return T();
					}

					if (T::typeid->IsAssignableFrom(managedInstance->GetType()))
					{
						return static_cast<T>(managedInstance);
					}
					else
					{
						return T();
					}
				}
			}

			virtual void DestroyInstance() sealed
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				daCrateFactoryClass->DestroyInstance();
			}

			virtual bool CheckEnabled() sealed
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				return daCrateFactoryClass->CheckEnabled();
			}

			virtual bool CheckType(DACrateType type) sealed
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				return daCrateFactoryClass->CheckType(type);
			}

			virtual bool CheckEnabledType(DACrateType type) sealed
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				return daCrateFactoryClass->CheckEnabledType(type);
			}

			property IntPtr DACrateFactoryClassPointer
			{
				virtual IntPtr get() sealed
				{
					return daCrateFactoryClassPointer;
				}
			}

			property IntPtr Pointer
			{
				virtual IntPtr get() sealed
				{
					return daCrateFactoryClassPointer;
				}
			}

			property bool IsAttached
			{
				virtual bool get() sealed
				{
					return (daCrateFactoryClassPointer != IntPtr::Zero);
				}
			}

			property bool IsRegistered
			{
				virtual bool get() sealed
				{
					return (IsAttached && DACrateManager::IsManagedCrateFactory(daCrateFactoryClass));
				}
			}

			property bool DestroyPointer
			{
				virtual bool get() sealed
				{
					return destroyPointer;
				}

				virtual void set(bool value) sealed
				{
					destroyPointer = value;
				}
			}

			property String^ Name
			{
				virtual String^ get() sealed
				{
					return name;
				}
			}

			property String^ Section
			{
				virtual String^ get() sealed
				{
					if (!IsAttached)
					{
						throw gcnew NotSupportedException("Not attached.");
					}

					return daCrateFactoryClass->Section;
				}

				protected:
					void set(String^ value)
					{
						if (!IsAttached)
						{
							throw gcnew NotSupportedException("Not attached.");
						}
						else if (value == nullptr)
						{
							throw gcnew ArgumentNullException("value");
						}

						IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
						try
						{
							auto helper = reinterpret_cast<DACrateFactoryClassHelper*>(InternalDACrateFactoryClassPointer);

							auto& section = helper->GetSection();

							section = reinterpret_cast<char*>(valueHandle.ToPointer());
						}
						finally
						{
							Marshal::FreeHGlobal(valueHandle);
						}
					}
			}

			property DACrateType Type
			{
				virtual DACrateType get() sealed
				{
					return type;
				}

				protected:
					void set(DACrateType value)
					{
						if (IsAttached)
						{
							auto helper = reinterpret_cast<DACrateFactoryClassHelper*>(InternalDACrateFactoryClassPointer);

							auto& type = helper->GetType();

							type = static_cast<::DACrateType::Type>(value);
						}

						this->type = value;
					}
			}

			property IDACrateClass^ Instance
			{
				virtual IDACrateClass^ get() sealed
				{
					if (!IsAttached)
					{
						throw gcnew NotSupportedException("Not attached.");
					}

					return daCrateFactoryClass->Instance;
				}

				protected:
					void set(IDACrateClass^ value)
					{
						if (!IsAttached)
						{
							throw gcnew NotSupportedException("Not attached.");
						}

						auto helper = reinterpret_cast<DACrateFactoryClassHelper*>(InternalDACrateFactoryClassPointer);

						auto& instance = helper->GetInstance();

						if (value == nullptr || value->DACrateClassPointer.ToPointer() == nullptr)
						{
							instance = nullptr;
						}
						else
						{
							instance = reinterpret_cast<::DACrateClass*>(value->DACrateClassPointer.ToPointer());
						}
					}
			}

		protected:
			virtual T InternalCreateInstance()
			{
				return safe_cast<T>(Activator::CreateInstance(T::typeid));
			}

			property ::DACrateFactoryClass* InternalDACrateFactoryClassPointer
			{
				virtual ::DACrateFactoryClass* get()
				{
					return reinterpret_cast<::DACrateFactoryClass*>(daCrateFactoryClassPointer.ToPointer());
				}
			}
	};
}