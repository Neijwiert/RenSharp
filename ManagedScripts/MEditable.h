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

#include "MPersist.h"
#include "IUnmanagedContainer.h"

#pragma managed(push, off)

class EditableClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IParameterClass;

	public interface class IEditableClass : public IPersistClass
	{
		IParameterClass^ LockParameter(int index);

		void UnlockParameter(int index);

		property IntPtr EditableClassPointer
		{
			IntPtr get();
		}

		property int ParameterCount
		{
			int get();
		}
	};

	public ref class EditableClass : public PersistClass, public IEditableClass
	{
		public:
			EditableClass(IntPtr pointer);

			virtual IParameterClass^ LockParameter(int index) sealed;
			virtual void UnlockParameter(int index) sealed;

			property IntPtr EditableClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int ParameterCount
			{
				virtual int get() sealed;
			}

		protected:
			property ::PersistClass *InternalPersistClassPointer
			{
				::PersistClass *get() override;
			}

			property ::EditableClass *InternalEditableClassPointer
			{
				virtual ::EditableClass *get();
			}
	};
}