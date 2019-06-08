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

#include "Mengine_vector.h"

#pragma managed(push, off)

class SoldierGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class ISoldierGameObj;

	public ref class SoldierGameObjPtrVectorClass : public VectorClass<ISoldierGameObj ^>
	{
		private:
			SoldierGameObjPtrVectorClass();
			SoldierGameObjPtrVectorClass(int size);

		public:
			SoldierGameObjPtrVectorClass(IntPtr pointer);

			static IUnmanagedContainer<IVectorClass<ISoldierGameObj ^> ^> ^CreateSoldierGameObjPtrVectorClass();
			static IUnmanagedContainer<IVectorClass<ISoldierGameObj ^> ^> ^CreateSoldierGameObjPtrVectorClass(int size);

			bool Resize(int newSize) override sealed;
			void Clear() override sealed;
			int ID(ISoldierGameObj ^object) override sealed;

			property IntPtr SoldierGameObjPtrVectorClassPointer
			{
				IntPtr get();
			}

			property ISoldierGameObj ^default[int]
			{
				ISoldierGameObj ^get(int index) override sealed;
				void set(int index, ISoldierGameObj ^value) override sealed;
			}

			property int Length
			{
				int get() override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::VectorClass<::SoldierGameObj *> *InternalSoldierGameObjPtrVectorClassPointer
			{
				virtual ::VectorClass<::SoldierGameObj *> *get();
			}

			property IntPtr Vector
			{
				IntPtr get() override sealed;
				void set(IntPtr value) override sealed;
			}

			property int VectorMax
			{
				int get() override sealed;
				void set(int value) override sealed;
			}

			property bool IsValid
			{
				bool get() override sealed;
				void set(bool value) override sealed;
			}

			property bool IsAllocated
			{
				bool get() override sealed;
				void set(bool value) override sealed;
			}
	};
}