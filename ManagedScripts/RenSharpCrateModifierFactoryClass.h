/*
Copyright 2019 Neijwiert

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

#include "RenSharpCrateModifierClass.h"
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
	public interface class IRenSharpCrateModifierFactoryClass : public IUnmanagedAttachable<IDACrateModifierFactoryClass^>
	{
		IUnmanagedContainer<IDACrateModifierClass^>^ Create(String^ parameters);

		property IntPtr DACrateModifierFactoryClassPointer
		{
			IntPtr get();
		}

		property String^ Name
		{
			String^ get();
		}
	};

	generic<typename T>
	where T : IRenSharpCrateModifierClass
	public ref class RenSharpCrateModifierFactoryClass abstract : public IRenSharpCrateModifierFactoryClass
	{
		private:
			bool disposedResources;
			bool destroyPointer;
			IntPtr daCrateModifierFactoryClassPointer;
			IDACrateModifierFactoryClass^ daCrateModifierFactoryClass;
			String^ name;

		public:
			RenSharpCrateModifierFactoryClass(String^ name)
				:
				disposedResources(false),
				destroyPointer(true),
				daCrateModifierFactoryClassPointer(IntPtr::Zero),
				daCrateModifierFactoryClass(nullptr),
				name(name)
			{
				if (name == nullptr)
				{
					throw gcnew ArgumentNullException("name");
				}
			}

			~RenSharpCrateModifierFactoryClass()
			{
				if (disposedResources)
				{
					return;
				}

				DACrateManager::UnregisterManagedCrateModifierFactory(this);

				this->!RenSharpCrateModifierFactoryClass();

				disposedResources = true;
			}

			!RenSharpCrateModifierFactoryClass()
			{
				if (IsAttached)
				{
					auto& modifiers = DACrateManagerHelper::GetCrateModifiers();
					modifiers.DeleteObj(InternalDACrateModifierFactoryClassPointer);

					if (destroyPointer)
					{
						IntPtr tmp = daCrateModifierFactoryClassPointer;
						daCrateModifierFactoryClassPointer = IntPtr::Zero;
						Imports::DestroyDACrateModifierFactoryClass(reinterpret_cast<::DACrateModifierFactoryClass*>(tmp.ToPointer()));
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

				IDACrateModifierFactoryClass^ otherThis1 = dynamic_cast<IDACrateModifierFactoryClass^>(other);
				if (otherThis1 != nullptr && daCrateModifierFactoryClassPointer.Equals(otherThis1->DACrateModifierFactoryClassPointer))
				{
					return true;
				}

				IRenSharpCrateModifierFactoryClass^ otherThis2 = dynamic_cast<IRenSharpCrateModifierFactoryClass^>(other);
				if (otherThis2 == nullptr)
				{
					return false;
				}

				return daCrateModifierFactoryClassPointer.Equals(otherThis2->DACrateModifierFactoryClassPointer);
			}

			int GetHashCode() override sealed
			{
				return daCrateModifierFactoryClassPointer.GetHashCode();
			}

			virtual void AttachToUnmanagedObject() sealed
			{
				if (IsAttached)
				{
					throw gcnew NotSupportedException("Already attached.");
				}

				::RenSharpCrateModifierFactoryClass* newCrateModifierFactory = nullptr;
				try
				{
					IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
					try
					{
						newCrateModifierFactory = Imports::CreateRenSharpCrateModifierFactoryClass(
							reinterpret_cast<char*>(nameHandle.ToPointer()));
					}
					finally
					{
						Marshal::FreeHGlobal(nameHandle);
					}

					IntPtr newCrateModifierFactoryPtr = IntPtr(newCrateModifierFactory);

					daCrateModifierFactoryClassPointer = newCrateModifierFactoryPtr;
				}
				catch (Exception^)
				{
					if (newCrateModifierFactory != nullptr)
					{
						Imports::DestroyDACrateModifierFactoryClass(reinterpret_cast<::DACrateModifierFactoryClass*>(newCrateModifierFactory));
					}

					throw;
				}

				daCrateModifierFactoryClass = gcnew DACrateModifierFactoryClass(daCrateModifierFactoryClassPointer);

				UnmanagedAttach();
			}

			virtual void RegisterManagedObject() sealed
			{
				DACrateManager::RegisterManagedCrateModifierFactory(this);

				ManagedRegistered();
			}

			virtual void ReleasePointer() sealed
			{
				daCrateModifierFactoryClassPointer = IntPtr::Zero;
				daCrateModifierFactoryClass = nullptr;
			}

			virtual void UnmanagedAttach()
			{

			}

			virtual void ManagedRegistered()
			{

			}

			virtual IDACrateModifierFactoryClass^ AsUnmanagedObject() sealed
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				return daCrateModifierFactoryClass;
			}

			virtual IUnmanagedContainer<IDACrateModifierClass^>^ Create(String^ parameters) sealed
			{
				T managedInstance = CreateManaged(parameters);
				if (managedInstance == nullptr)
				{
					return nullptr;
				}
				else
				{
					return gcnew UnmanagedContainer<IDACrateModifierClass^>(gcnew DACrateModifierClass(managedInstance->DACrateModifierClassPointer));
				}
			}

			T CreateManaged(String^ parameters)
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}
				else if (parameters == nullptr)
				{
					throw gcnew ArgumentNullException("parameters");
				}

				T managedInstance = InternalCreate(parameters);
				try
				{
					managedInstance->AttachToUnmanagedObject();
					managedInstance->RegisterManagedObject();

					managedInstance->Factory = gcnew DACrateModifierFactoryClass(daCrateModifierFactoryClassPointer);
					managedInstance->Init(parameters);

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

			property IntPtr DACrateModifierFactoryClassPointer
			{
				virtual IntPtr get() sealed
				{
					return daCrateModifierFactoryClassPointer;
				}
			}

			property IntPtr Pointer
			{
				virtual IntPtr get() sealed
				{
					return daCrateModifierFactoryClassPointer;
				}
			}

			property bool IsAttached
			{
				virtual bool get() sealed
				{
					return (daCrateModifierFactoryClassPointer != IntPtr::Zero);
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

		protected:
			virtual T InternalCreate(String^ parameters)
			{
				return safe_cast<T>(Activator::CreateInstance(T::typeid));
			}

			property ::DACrateModifierFactoryClass* InternalDACrateModifierFactoryClassPointer
			{
				virtual ::DACrateModifierFactoryClass* get()
				{
					return reinterpret_cast<::DACrateModifierFactoryClass*>(daCrateModifierFactoryClassPointer.ToPointer());
				}
			}
	};
}