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

class SysTimeClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class ISysTimeClass : public IUnmanagedObject
	{
		uint32 Get();

		void Reset();

		property IntPtr SysTimeClassPointer
		{
			IntPtr get();
		}
	};

	public ref class SysTimeClass : public AbstractUnmanagedObject, public ISysTimeClass
	{
		private:
			SysTimeClass();

		public:
			SysTimeClass(IntPtr pointer);

			static IUnmanagedContainer<ISysTimeClass^>^ CreateSysTimeClass();

			bool Equals(Object^ other) override;

			virtual uint32 Get() sealed;
			virtual void Reset() sealed;

			static property bool IsInit
			{
				bool get();
				void set(bool value);
			}

			static property ISysTimeClass^ SystemTime
			{
				ISysTimeClass^ get();
				void set(ISysTimeClass^ value);
			}

			property IntPtr SysTimeClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::SysTimeClass* InternalSysTimeClassPointer
			{
				virtual ::SysTimeClass* get();
			}
	};
}