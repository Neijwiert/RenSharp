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

#include "RenSharpPlayerDataClass.h"
#include "IUnmanagedAttachable.h"
#include "UnmanagedContainer.h"
#include "Mda_player.h"
#include "Imports.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_player.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System;

namespace RenSharp
{
	public interface class IRenSharpPlayerDataFactoryClass : public IUnmanagedAttachable<IDAPlayerDataFactoryClass^>
	{
		IUnmanagedContainer<IDAPlayerDataClass^>^ CreateData();

		property IntPtr DAPlayerDataFactoryClassPointer
		{
			IntPtr get();
		}
	};

	generic<typename T>
	where T : IRenSharpPlayerDataClass
	public ref class RenSharpPlayerDataFactoryClass abstract : public IRenSharpPlayerDataFactoryClass
	{
		private:
			bool disposedResources;
			bool destroyPointer;
			IntPtr daPlayerDataFactoryClassPointer;
			IDAPlayerDataFactoryClass^ daPlayerDataFactoryClass;

		public:
			RenSharpPlayerDataFactoryClass()
				:
				disposedResources(false),
				destroyPointer(true),
				daPlayerDataFactoryClassPointer(IntPtr::Zero),
				daPlayerDataFactoryClass(nullptr)
			{

			}

			~RenSharpPlayerDataFactoryClass()
			{
				if (disposedResources)
				{
					return;
				}

				DAPlayerManager::UnregisterManagedPlayerDataFactory(this);

				this->!RenSharpPlayerDataFactoryClass();

				disposedResources = true;
			}

			!RenSharpPlayerDataFactoryClass()
			{
				if (IsAttached)
				{
					::DAPlayerManager::Remove_Data_Factory(InternalDAPlayerDataFactoryClassPointer);

					if (destroyPointer)
					{
						IntPtr tmp = daPlayerDataFactoryClassPointer;
						daPlayerDataFactoryClassPointer = IntPtr::Zero;
						Imports::DestroyDAPlayerDataFactoryClass(reinterpret_cast<::DAPlayerDataFactoryClass*>(tmp.ToPointer()));
					}
				}

				ReleasePointer();
			}

			bool Equals(Object^ other) override
			{
				if (ReferenceEquals(other, nullptr))
				{
					return false;
				}

				IDAPlayerDataFactoryClass^ otherThis1 = dynamic_cast<IDAPlayerDataFactoryClass^>(other);
				if (otherThis1 != nullptr && daPlayerDataFactoryClassPointer.Equals(otherThis1->DAPlayerDataFactoryClassPointer))
				{
					return true;
				}

				IRenSharpPlayerDataFactoryClass^ otherThis2 = dynamic_cast<IRenSharpPlayerDataFactoryClass^>(other);
				if (otherThis2 == nullptr)
				{
					return false;
				}

				return daPlayerDataFactoryClassPointer.Equals(otherThis2->DAPlayerDataFactoryClassPointer);
			}

			int GetHashCode() override sealed
			{
				return daPlayerDataFactoryClassPointer.GetHashCode();
			}

			virtual void AttachToUnmanagedObject() sealed
			{
				if (IsAttached)
				{
					throw gcnew NotSupportedException("Already attached.");
				}

				::RenSharpPlayerDataFactoryClass* newFactory = Imports::CreateRenSharpPlayerDataFactoryClass();
				try
				{
					IntPtr newFactoryPtr = IntPtr(newFactory);

					daPlayerDataFactoryClassPointer = newFactoryPtr;
				}
				catch (Exception^)
				{
					if (newFactory != nullptr)
					{
						Imports::DestroyDAPlayerDataFactoryClass(reinterpret_cast<::DAPlayerDataFactoryClass*>(newFactory));
					}

					throw;
				}

				daPlayerDataFactoryClass = gcnew DAPlayerDataFactoryClass(daPlayerDataFactoryClassPointer);

				UnmanagedAttach();
			}

			virtual void RegisterManagedObject() sealed
			{
				DAPlayerManager::RegisterManagedPlayerDataFactory(this);

				ManagedRegistered();
			}

			virtual void ReleasePointer() sealed
			{
				daPlayerDataFactoryClassPointer = IntPtr::Zero;
				daPlayerDataFactoryClass = nullptr;
			}

			virtual void UnmanagedAttach()
			{

			}

			virtual void ManagedRegistered()
			{

			}

			virtual IDAPlayerDataFactoryClass^ AsUnmanagedObject() sealed
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				return daPlayerDataFactoryClass;
			}

			virtual IUnmanagedContainer<IDAPlayerDataClass^>^ CreateData() sealed
			{
				T managedData = CreateManagedData();
				if (managedData == nullptr)
				{
					return nullptr;
				}
				else
				{
					return gcnew UnmanagedContainer<IDAPlayerDataClass^>(gcnew DAPlayerDataClass(managedData->DAPlayerDataClassPointer));
				}
			}

			T CreateManagedData()
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				T managedData = InternalCreateData();
				try
				{
					managedData->AttachToUnmanagedObject();
					managedData->RegisterManagedObject();

					managedData->Factory = gcnew DAPlayerDataFactoryClass(daPlayerDataFactoryClassPointer);

					return managedData;
				}
				catch (Exception^)
				{
#pragma push_macro("delete")
#undef delete

					delete managedData;
					managedData = T();

#pragma pop_macro("delete")

					throw;
				}
			}

			property IntPtr DAPlayerDataFactoryClassPointer
			{
				virtual IntPtr get() sealed
				{
					return daPlayerDataFactoryClassPointer;
				}
			}

			property IntPtr Pointer
			{
				virtual IntPtr get() sealed
				{
					return daPlayerDataFactoryClassPointer;
				}
			}

			property bool IsAttached
			{
				virtual bool get() sealed
				{
					return (daPlayerDataFactoryClassPointer != IntPtr::Zero);
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

		protected:
			virtual T InternalCreateData()
			{
				return safe_cast<T>(Activator::CreateInstance(T::typeid));
			}

			property ::DAPlayerDataFactoryClass* InternalDAPlayerDataFactoryClassPointer
			{
				virtual ::DAPlayerDataFactoryClass* get()
				{
					return reinterpret_cast<::DAPlayerDataFactoryClass*>(daPlayerDataFactoryClassPointer.ToPointer());
				}
			}
	};
}