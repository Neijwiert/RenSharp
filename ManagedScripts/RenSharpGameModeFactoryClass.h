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

#include "RenSharpGameModeClass.h"
#include "IUnmanagedAttachable.h"
#include "UnmanagedContainer.h"
#include "Mda_gamemode.h"
#include "Imports.h"
#include "Mda_game.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_gamemode.h>
#include <da_game.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System;
using namespace System::Text;

namespace RenSharp
{
	public interface class IRenSharpGameModeFactoryClass : public IUnmanagedAttachable<IDAGameModeFactoryClass^>
	{
		IDAGameModeClass^ CreateInstance();

		property IntPtr DAGameModeFactoryClassPointer
		{
			IntPtr get();
		}

		property String^ LongName
		{
			String^ get();
		}

		property String^ ShortName
		{
			String^ get();
		}

		property String^ RequiredData
		{
			String^ get();
		}

		property IDAGameModeClass^ Instance
		{
			IDAGameModeClass^ get();
		}
	};

	generic<typename T>
	where T : IRenSharpGameModeClass
	public ref class RenSharpGameModeFactoryClass abstract : public IRenSharpGameModeFactoryClass
	{
		private:
			bool disposedResources;
			bool destroyPointer;
			IntPtr daGameModeFactoryClassPointer;
			IDAGameModeFactoryClass^ daGameModeFactoryClass;
			String^ longName;
			String^ shortName;
			String^ requiredData;

		public:
			RenSharpGameModeFactoryClass(String^ longName, String^ shortName, String^ requiredData)
				:
				disposedResources(false),
				destroyPointer(true),
				daGameModeFactoryClassPointer(IntPtr::Zero),
				daGameModeFactoryClass(nullptr),
				longName(longName),
				shortName(shortName),
				requiredData(requiredData)
			{
				if (longName == nullptr)
				{
					throw gcnew ArgumentNullException("longName");
				}
				else if (shortName == nullptr)
				{
					throw gcnew ArgumentNullException("shortName");
				}
			}

			RenSharpGameModeFactoryClass(String^ longName, String^ shortName)
				: RenSharpGameModeFactoryClass(longName, shortName, nullptr)
			{

			}

			~RenSharpGameModeFactoryClass()
			{
				if (disposedResources)
				{
					return;
				}

				DAGameManager::UnregisterManagedGameModeFactory(this);

				this->!RenSharpGameModeFactoryClass();

				disposedResources = true;
			}

			!RenSharpGameModeFactoryClass()
			{
				if (IsAttached)
				{
					if (Imports::IsShuttingDown())
					{
						auto currentGameModeFactory = ::DAGameManager::Get_Game_Mode();
						if (currentGameModeFactory == InternalDAGameModeFactoryClassPointer)
						{
							destroyPointer = false; // We need to leak this memory, because there is no clean way to set that gamemode to null
						}
					}

					if (destroyPointer)
					{
						IntPtr tmp = daGameModeFactoryClassPointer;
						daGameModeFactoryClassPointer = IntPtr::Zero;
						Imports::DestroyDAGameModeFactoryClass(reinterpret_cast<::DAGameModeFactoryClass*>(tmp.ToPointer()));
					}
				}

				ReleasePointer();
			}

			String^ ToString() override
			{
				return longName;
			}

			bool Equals(Object^ other) override
			{
				if (ReferenceEquals(other, nullptr))
				{
					return false;
				}

				IDAGameModeFactoryClass^ otherThis1 = dynamic_cast<IDAGameModeFactoryClass^>(other);
				if (otherThis1 != nullptr && daGameModeFactoryClassPointer.Equals(otherThis1->DAGameModeFactoryClassPointer))
				{
					return true;
				}

				IRenSharpGameModeFactoryClass^ otherThis2 = dynamic_cast<IRenSharpGameModeFactoryClass^>(other);
				if (otherThis2 == nullptr)
				{
					return false;
				}

				return daGameModeFactoryClassPointer.Equals(otherThis2->DAGameModeFactoryClassPointer);
			}

			int GetHashCode() override sealed
			{
				return daGameModeFactoryClassPointer.GetHashCode();
			}

			virtual void AttachToUnmanagedObject() sealed
			{
				if (IsAttached)
				{
					throw gcnew NotSupportedException("Already attached.");
				}

				::RenSharpGameModeFactoryClass* newGameModeFactoryClass = nullptr;
				try
				{
					IntPtr longNameHandle = Marshal::StringToHGlobalAnsi(longName);
					try
					{
						IntPtr shortNameHandle = Marshal::StringToHGlobalAnsi(shortName);
						try
						{
							if (requiredData == nullptr)
							{
								newGameModeFactoryClass = Imports::CreateRenSharpGameModeFactoryClass(
									reinterpret_cast<char*>(shortNameHandle.ToPointer()),
									reinterpret_cast<char*>(longNameHandle.ToPointer()),
									nullptr);
							}
							else
							{
								IntPtr requiredDataHandle = Marshal::StringToHGlobalAnsi(requiredData);
								try
								{
									newGameModeFactoryClass = Imports::CreateRenSharpGameModeFactoryClass(
										reinterpret_cast<char*>(shortNameHandle.ToPointer()),
										reinterpret_cast<char*>(longNameHandle.ToPointer()),
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
							Marshal::FreeHGlobal(shortNameHandle);
						}
					}
					finally
					{
						Marshal::FreeHGlobal(longNameHandle);
					}

					IntPtr newGameModeFactoryPtr = IntPtr(newGameModeFactoryClass);

					daGameModeFactoryClassPointer = newGameModeFactoryPtr;
				}
				catch (Exception^)
				{
					if (newGameModeFactoryClass != nullptr)
					{
						Imports::DestroyDAGameModeFactoryClass(reinterpret_cast<::DAGameModeFactoryClass*>(newGameModeFactoryClass));
					}

					throw;
				}

				daGameModeFactoryClass = gcnew DAGameModeFactoryClass(daGameModeFactoryClassPointer);

				UnmanagedAttach();
			}

			virtual void RegisterManagedObject() sealed
			{
				DAGameManager::RegisterManagedGameModeFactory(this);

				ManagedRegistered();
			}

			virtual void ReleasePointer() sealed
			{
				daGameModeFactoryClassPointer = IntPtr::Zero;
				daGameModeFactoryClass = nullptr;
			}

			virtual void UnmanagedAttach()
			{

			}

			virtual void ManagedRegistered()
			{

			}

			virtual IDAGameModeFactoryClass^ AsUnmanagedObject() sealed
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				return gcnew DAGameModeFactoryClass(daGameModeFactoryClassPointer);
			}

			virtual IDAGameModeClass^ CreateInstance() sealed
			{
				T managedInstance = CreateManagedInstance();
				if (managedInstance == nullptr)
				{
					return nullptr;
				}
				else
				{
					return gcnew DAGameModeClass(managedInstance->DAGameModeClassPointer);
				}
			}

			T CreateManagedInstance()
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				auto helper = reinterpret_cast<DAGameModeFactoryClassHelper*>(InternalDAGameModeFactoryClassPointer);

				auto& instance = helper->GetInstance();

				if (instance == nullptr)
				{
					T managedInstance = InternalCreateInstance();
					try
					{
						managedInstance->AttachToUnmanagedObject();
						managedInstance->RegisterManagedObject();

						managedInstance->Factory = gcnew DAGameModeFactoryClass(daGameModeFactoryClassPointer);
						managedInstance->Init();

						instance = reinterpret_cast<::DAGameModeClass*>(managedInstance->DAGameModeClassPointer.ToPointer());

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
					auto managedInstance = DAGameManager::AsManagedGameMode(IntPtr(instance));
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

			property IntPtr DAGameModeFactoryClassPointer
			{
				virtual IntPtr get() sealed
				{
					return daGameModeFactoryClassPointer;
				}
			}

			property IntPtr Pointer
			{
				virtual IntPtr get() sealed
				{
					return daGameModeFactoryClassPointer;
				}
			}

			property bool IsAttached
			{
				virtual bool get() sealed
				{
					return (daGameModeFactoryClassPointer != IntPtr::Zero);
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

			property String^ LongName
			{
				virtual String^ get() sealed
				{
					return longName;
				}
			}

			property String^ ShortName
			{
				virtual String^ get() sealed
				{
					return shortName;
				}
			}

			property String^ RequiredData
			{
				virtual String^ get() sealed
				{
					return requiredData;
				}
			}

			property IDAGameModeClass^ Instance
			{
				virtual IDAGameModeClass^ get() sealed
				{
					if (!IsAttached)
					{
						throw gcnew NotSupportedException("Not attached.");
					}

					return daGameModeFactoryClass->Instance;
				}

				protected:
					void set(IDAGameModeClass^ value)
					{
						if (!IsAttached)
						{
							throw gcnew NotSupportedException("Not attached.");
						}

						auto helper = reinterpret_cast<DAGameModeFactoryClassHelper*>(InternalDAGameModeFactoryClassPointer);

						auto& instance = helper->GetInstance();

						if (value == nullptr || value->DAGameModeClassPointer.ToPointer() == nullptr)
						{
							instance = nullptr;
						}
						else
						{
							instance = reinterpret_cast<::DAGameModeClass*>(value->DAGameModeClassPointer.ToPointer());
						}
					}
			}

		protected:
			virtual T InternalCreateInstance()
			{
				return safe_cast<T>(Activator::CreateInstance(T::typeid));
			}

			property ::DAGameModeFactoryClass* InternalDAGameModeFactoryClassPointer
			{
				virtual ::DAGameModeFactoryClass* get()
				{
					return reinterpret_cast<::DAGameModeFactoryClass*>(daGameModeFactoryClassPointer.ToPointer());
				}
			}
	};
}