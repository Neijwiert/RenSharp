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

#include "MPersist.h"

#pragma managed(push, off)

class TDBCategoryClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class ITDBCategoryClass : public IPersistClass
	{
		property IntPtr TDBCategoryClassPointer
		{
			IntPtr get();
		}

		property String^ Name
		{
			String^ get();
			void set(String^ value);
		}

		property uint32 ID
		{
			uint32 get();
			void set(uint32 value);
		}
	};

	public ref class TDBCategoryClass : public PersistClass, public ITDBCategoryClass
	{
		public:
			TDBCategoryClass(IntPtr pointer);

			String^ ToString() override;

			property IntPtr TDBCategoryClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String^ Name
			{
				virtual String^ get() sealed;
				virtual void set(String^ value) sealed;
			}

			property uint32 ID
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

		protected:
			property ::PersistClass* InternalPersistClassPointer
			{
				::PersistClass* get() override;
			}

			property ::TDBCategoryClass* InternalTDBCategoryClassPointer
			{
				virtual ::TDBCategoryClass* get();
			}
	};
}