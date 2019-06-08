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

class VisTableClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IVisTableClass;

	public ref class VisTableClassPtrSimpleVecClass : public SimpleVecClass<IVisTableClass^>
	{
		private:
			VisTableClassPtrSimpleVecClass();
			VisTableClassPtrSimpleVecClass(int size);

		public:
			VisTableClassPtrSimpleVecClass(IntPtr pointer);

			bool Resize(int newSize) override sealed;
			bool UninitialisedGrow(int newSize) override sealed;
			void UninitializedResize(int newSize) override sealed;
			IntPtr Peek() override sealed;

#pragma push_macro("ZeroMemory")
#undef ZeroMemory
			void ZeroMemory() override sealed;
#pragma pop_macro("ZeroMemory")

			property IntPtr VisTableClassPtrSimpleVecClassPointer
			{
				IntPtr get();
			}

			property int Length
			{
				int get() override sealed;
			}

			property IVisTableClass^ default[int]
			{
				IVisTableClass^ get(int index) override;
				void set(int index, IVisTableClass^ value) override;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::SimpleVecClass<::VisTableClass*>* InternalVisTableClassPtrSimpleVecClassPointer
			{
				virtual ::SimpleVecClass<::VisTableClass*>* get();
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
	};
}