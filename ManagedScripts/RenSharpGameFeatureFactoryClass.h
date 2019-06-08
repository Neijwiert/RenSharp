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

#include "RenSharpGameFeatureClass.h"
#include "IUnmanagedAttachable.h"
#include "UnmanagedContainer.h"
#include "Mda_gamefeature.h"
#include "Imports.h"
#include "Mda_game.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_gamefeature.h>
#include <da_game.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System;
using namespace System::Text;

namespace RenSharp
{
	public interface class IRenSharpGameFeatureFactoryClass : public IUnmanagedAttachable<IDAGameFeatureFactoryClass^>
	{
		IDAGameFeatureClass^ CreateInstance();

		property IntPtr DAGameFeatureFactoryClassPointer
		{
			IntPtr get();
		}

		property String^ Name
		{
			String^ get();
		}

		property String^ EnableSetting
		{
			String^ get();
		}

		property String^ RequiredData
		{
			String^ get();
		}

		property IDAGameFeatureClass^ Instance
		{
			IDAGameFeatureClass^ get();
		}
	};

	generic<typename T>
	where T : IRenSharpGameFeatureClass
	public ref class RenSharpGameFeatureFactoryClass abstract : public IRenSharpGameFeatureFactoryClass
	{
		private:
			bool disposedResources;
			bool destroyPointer;
			IntPtr daGameFeatureFactoryClassPointer;
			IDAGameFeatureFactoryClass^ daGameFeatureFactoryClass;
			String^ name;
			String^ enableSetting;
			String^ requiredData;

		public:
			RenSharpGameFeatureFactoryClass(String^ name, String^ enableSetting, String^ requiredData)
				: 
				disposedResources(false),
				destroyPointer(true),
				daGameFeatureFactoryClassPointer(IntPtr::Zero),
				daGameFeatureFactoryClass(nullptr),
				name(name),
				enableSetting(enableSetting),
				requiredData(requiredData)
			{
				if (name == nullptr)
				{
					throw gcnew ArgumentNullException("name");
				}
			}

			RenSharpGameFeatureFactoryClass(String^ name, String^ enableSetting)
				: RenSharpGameFeatureFactoryClass(name, enableSetting, nullptr)
			{

			}

			~RenSharpGameFeatureFactoryClass()
			{
				if (disposedResources)
				{
					return;
				}

				DAGameManager::UnregisterManagedGameFeatureFactory(this);

				this->!RenSharpGameFeatureFactoryClass();

				disposedResources = true;
			}

			!RenSharpGameFeatureFactoryClass()
			{
				if (IsAttached)
				{
					auto gameFeatureFactories = const_cast<::DynamicVectorClass<::DAGameFeatureFactoryClass*>*>(&::DAGameManager::Get_Game_Features());

					gameFeatureFactories->DeleteObj(InternalDAGameFeatureFactoryClassPointer);

					if (destroyPointer)
					{
						IntPtr tmp = daGameFeatureFactoryClassPointer;
						daGameFeatureFactoryClassPointer = IntPtr::Zero;
						Imports::DestroyDAGameFeatureFactoryClass(reinterpret_cast<::DAGameFeatureFactoryClass*>(tmp.ToPointer()));
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

				IDAGameFeatureFactoryClass^ otherThis1 = dynamic_cast<IDAGameFeatureFactoryClass^>(other);
				if (otherThis1 != nullptr && daGameFeatureFactoryClassPointer.Equals(otherThis1->DAGameFeatureFactoryClassPointer))
				{
					return true;
				}

				IRenSharpGameFeatureFactoryClass^ otherThis2 = dynamic_cast<IRenSharpGameFeatureFactoryClass^>(other);
				if (otherThis2 == nullptr)
				{
					return false;
				}

				return daGameFeatureFactoryClassPointer.Equals(otherThis2->DAGameFeatureFactoryClassPointer);
			}

			int GetHashCode() override sealed
			{
				return daGameFeatureFactoryClassPointer.GetHashCode();
			}

			virtual void AttachToUnmanagedObject() sealed
			{
				if (IsAttached)
				{
					throw gcnew NotSupportedException("Already attached.");
				}

				::RenSharpGameFeatureFactoryClass* newGameFeatureFactory = nullptr;
				try
				{
					IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
					try
					{
						if (enableSetting == nullptr)
						{
							if (requiredData == nullptr)
							{
								newGameFeatureFactory = Imports::CreateRenSharpGameFeatureFactoryClass(
									reinterpret_cast<char*>(nameHandle.ToPointer()),
									nullptr,
									nullptr);
							}
							else
							{
								IntPtr requiredDataHandle = Marshal::StringToHGlobalAnsi(requiredData);
								try
								{
									newGameFeatureFactory = Imports::CreateRenSharpGameFeatureFactoryClass(
										reinterpret_cast<char*>(nameHandle.ToPointer()),
										nullptr,
										reinterpret_cast<char*>(requiredDataHandle.ToPointer()));
								}
								finally
								{
									Marshal::FreeHGlobal(requiredDataHandle);
								}
							}
						}
						else
						{
							IntPtr enableSettingHandle = Marshal::StringToHGlobalAnsi(enableSetting);
							try
							{
								if (requiredData == nullptr)
								{
									newGameFeatureFactory = Imports::CreateRenSharpGameFeatureFactoryClass(
										reinterpret_cast<char*>(nameHandle.ToPointer()),
										reinterpret_cast<char*>(enableSettingHandle.ToPointer()),
										nullptr);
								}
								else
								{
									IntPtr requiredDataHandle = Marshal::StringToHGlobalAnsi(requiredData);
									try
									{
										newGameFeatureFactory = Imports::CreateRenSharpGameFeatureFactoryClass(
											reinterpret_cast<char*>(nameHandle.ToPointer()),
											reinterpret_cast<char*>(enableSettingHandle.ToPointer()),
											reinterpret_cast<char*>(requiredDataHandle.ToPointer()));
									}
									finally
									{
										Marshal::FreeHGlobal(requiredDataHandle);
									}
								}
							}
							finally
							{
								Marshal::FreeHGlobal(enableSettingHandle);
							}
						}
					}
					finally
					{
						Marshal::FreeHGlobal(nameHandle);
					}

					IntPtr newGameFeatureFactoryPtr = IntPtr(newGameFeatureFactory);

					daGameFeatureFactoryClassPointer = newGameFeatureFactoryPtr;
				}
				catch (Exception^)
				{
					if (newGameFeatureFactory != nullptr)
					{
						Imports::DestroyDAGameFeatureFactoryClass(reinterpret_cast<::DAGameFeatureFactoryClass*>(newGameFeatureFactory));
					}

					throw;
				}

				daGameFeatureFactoryClass = gcnew DAGameFeatureFactoryClass(daGameFeatureFactoryClassPointer);

				UnmanagedAttach();
			}

			virtual void RegisterManagedObject() sealed
			{
				DAGameManager::RegisterManagedGameFeatureFactory(this);

				ManagedRegistered();
			}

			virtual void ReleasePointer() sealed
			{
				daGameFeatureFactoryClassPointer = IntPtr::Zero;
				daGameFeatureFactoryClass = nullptr;
			}

			virtual void UnmanagedAttach()
			{

			}

			virtual void ManagedRegistered()
			{

			}

			virtual IDAGameFeatureFactoryClass^ AsUnmanagedObject() sealed
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				return daGameFeatureFactoryClass;
			}

			virtual IDAGameFeatureClass^ CreateInstance() sealed
			{
				T managedInstance = CreateManagedInstance();
				if (managedInstance == nullptr)
				{
					return nullptr;
				}
				else
				{
					return gcnew DAGameFeatureClass(managedInstance->DAGameFeatureClassPointer);
				}
			}

			T CreateManagedInstance()
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				auto helper = reinterpret_cast<DAGameFeatureFactoryClassHelper*>(InternalDAGameFeatureFactoryClassPointer);

				auto& instance = helper->GetInstance();

				if (instance == nullptr)
				{
					T managedInstance = InternalCreateInstance();
					try
					{
						managedInstance->AttachToUnmanagedObject();
						managedInstance->RegisterManagedObject();

						managedInstance->Factory = gcnew DAGameFeatureFactoryClass(daGameFeatureFactoryClassPointer);
						managedInstance->Init();

						instance = reinterpret_cast<::DAGameFeatureClass*>(managedInstance->DAGameFeatureClassPointer.ToPointer());

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
					auto managedInstance = DAGameManager::AsManagedGameFeature(IntPtr(instance));
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

			property IntPtr DAGameFeatureFactoryClassPointer
			{
				virtual IntPtr get() sealed
				{
					return daGameFeatureFactoryClassPointer;
				}
			}

			property IntPtr Pointer
			{
				virtual IntPtr get() sealed
				{
					return daGameFeatureFactoryClassPointer;
				}
			}

			property bool IsAttached
			{
				virtual bool get() sealed
				{
					return (daGameFeatureFactoryClassPointer != IntPtr::Zero);
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

			property String^ EnableSetting
			{
				virtual String^ get() sealed
				{
					return enableSetting;
				}
			}

			property String^ RequiredData
			{
				virtual String^ get() sealed
				{
					return requiredData;
				}
			}

			property IDAGameFeatureClass^ Instance
			{
				virtual IDAGameFeatureClass^ get() sealed
				{
					if (!IsAttached)
					{
						throw gcnew NotSupportedException("Not attached.");
					}

					return daGameFeatureFactoryClass->Instance;
				}

				protected:
					void set(IDAGameFeatureClass^ value)
					{
						if (!IsAttached)
						{
							throw gcnew NotSupportedException("Not attached.");
						}

						auto helper = reinterpret_cast<DAGameFeatureFactoryClassHelper*>(InternalDAGameFeatureFactoryClassPointer);

						auto& instance = helper->GetInstance();

						if (value == nullptr || value->DAGameFeatureClassPointer.ToPointer() == nullptr)
						{
							instance = nullptr;
						}
						else
						{
							instance = reinterpret_cast<::DAGameFeatureClass*>(value->DAGameFeatureClassPointer.ToPointer());
						}
					}
			}

		protected:
			virtual T InternalCreateInstance()
			{
				return safe_cast<T>(Activator::CreateInstance(T::typeid));
			}

			property ::DAGameFeatureFactoryClass* InternalDAGameFeatureFactoryClassPointer
			{
				virtual ::DAGameFeatureFactoryClass* get()
				{
					return reinterpret_cast<::DAGameFeatureFactoryClass*>(daGameFeatureFactoryClassPointer.ToPointer());
				}
			}
	};
}