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

#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <CriticalSectionClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public interface class ICriticalSectionClass : public IUnmanagedObject
	{
		void Enter();

		void Exit();

		property IntPtr CriticalSectionClassPointer
		{
			IntPtr get();
		}
	};

	public ref class CriticalSectionClass : public AbstractUnmanagedObject, public ICriticalSectionClass
	{
		private:
			CriticalSectionClass();

		public:
			interface class ILockClass : public IUnmanagedObject
			{
				property IntPtr LockClassPointer
				{
					IntPtr get();
				}
			};

			ref class LockClass : public AbstractUnmanagedObject, public ILockClass
			{
				public:
					LockClass(IntPtr pointer);

					bool Equals(Object^ other) override;

					property IntPtr LockClassPointer
					{
						virtual IntPtr get() sealed;
					}

				protected:
					property ::CriticalSectionClass::LockClass* InternalLockClassPointer
					{
						virtual ::CriticalSectionClass::LockClass* get();
					}
			};

			CriticalSectionClass(IntPtr pointer);

			static IUnmanagedContainer<ICriticalSectionClass^>^ CreateCriticalSectionClass();

			bool Equals(Object^ other) override;

			virtual void Enter() sealed;
			virtual void Exit() sealed;

			property IntPtr CriticalSectionClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::CriticalSectionClass* InternalCriticalSectionClassPointer
			{
				virtual ::CriticalSectionClass* get();
			}
	};

	public interface class IFastCriticalSectionClass : public IUnmanagedObject
	{
		property IntPtr FastCriticalSectionClassPointer
		{
			IntPtr get();
		}
	};

	public ref class FastCriticalSectionClass : public AbstractUnmanagedObject, public IFastCriticalSectionClass
	{
		private:
			FastCriticalSectionClass();

		public:
			interface class ILockClass : public IUnmanagedObject
			{
				property IntPtr LockClassPointer
				{
					IntPtr get();
				}
			};

			ref class LockClass : public AbstractUnmanagedObject, public ILockClass
			{
				private:
					LockClass(IFastCriticalSectionClass^ section);

				public:
					LockClass(IntPtr pointer);

					static IUnmanagedContainer<ILockClass^>^ CreateLockClass(IFastCriticalSectionClass^ section);

					bool Equals(Object^ other) override;

					property IntPtr LockClassPointer
					{
						virtual IntPtr get() sealed;
					}

				protected:
					bool InternalDestroyPointer() override;

					property ::FastCriticalSectionClass::LockClass* InternalLockClassPointer
					{
						virtual ::FastCriticalSectionClass::LockClass* get();
					}
			};
			
			FastCriticalSectionClass(IntPtr pointer);

			static IUnmanagedContainer<IFastCriticalSectionClass^>^ CreateFastCriticalSectionClass();

			bool Equals(Object^ other) override;

			property IntPtr FastCriticalSectionClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::FastCriticalSectionClass* InternalFastCriticalSectionClassPointer
			{
				virtual ::FastCriticalSectionClass* get();
			}
	};
}