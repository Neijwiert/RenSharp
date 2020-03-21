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

#include "IUnmanagedContainer.h"
#include "Mengine_vector.h"

namespace RenSharp
{
	generic<typename T>
	where T : ref class, IRefCountClass
	public ref class RefCountClassUnmanagedContainer : public IUnmanagedContainer<T>
	{
		private:
			bool disposedResources;
			T unmanagedObject;

		public:
			RefCountClassUnmanagedContainer(T unmanagedObject)
				: disposedResources(false), unmanagedObject(unmanagedObject)
			{
				if (unmanagedObject == nullptr || unmanagedObject->Pointer.ToPointer() == nullptr)
				{
					throw gcnew ArgumentNullException("unmanagedObject");
				}
			}

			~RefCountClassUnmanagedContainer()
			{
				this->!RefCountClassUnmanagedContainer();
			}

			bool Equals(Object ^other) override
			{
				if (other == nullptr)
				{
					return false;
				}
				else if (other == this)
				{
					return true;
				}

				IUnmanagedContainer<T> ^otherContainer = dynamic_cast<IUnmanagedContainer<T> ^>(other);
				if (otherContainer == nullptr)
				{
					return false;
				}

				if (unmanagedObject == nullptr)
				{
					return (otherContainer->UnmanagedObject == nullptr);
				}

				return unmanagedObject->Equals(otherContainer->UnmanagedObject);
			}

			int GetHashCode() override
			{
				if (UnmanagedObject == nullptr)
				{
					IntPtr zero = IntPtr::Zero;

					return zero.GetHashCode();
				}
				else
				{
					return unmanagedObject->GetHashCode();
				}
			}

			virtual void ReleaseObject() sealed
			{
				unmanagedObject = T();
			}

			property T UnmanagedObject
			{
				virtual T get() sealed
				{
					return unmanagedObject;
				}

				protected:
					virtual void set(T value) sealed
					{
						unmanagedObject = value;
					}
			}

		protected:
			!RefCountClassUnmanagedContainer()
			{
				if (!disposedResources)
				{
					if (unmanagedObject != nullptr && unmanagedObject->Pointer != IntPtr::Zero)
					{
						bool isGoingToBeDeleted = (unmanagedObject->NumRefs == 1);
						unmanagedObject->Release();

						if (isGoingToBeDeleted)
						{
							unmanagedObject = T();
						}
					}

					disposedResources = true;
				}
			}
	};
}