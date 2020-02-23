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

#include "Mengine_vector.h"

namespace RenSharp
{
	public interface class Iuint32SimpleVecClass : public ISimpleVecClass<uint32>
	{
		property IntPtr uint32SimpleVecClassPointer
		{
			IntPtr get();
		}
	};

	public ref class uint32SimpleVecClass : public SimpleVecClass<uint32>, public Iuint32SimpleVecClass
	{
		private:
			uint32SimpleVecClass();
			uint32SimpleVecClass(int size);

		public:
			uint32SimpleVecClass(IntPtr pointer);

			static IUnmanagedContainer<ISimpleVecClass<uint32> ^> ^Createuint32SimpleVecClass();
			static IUnmanagedContainer<ISimpleVecClass<uint32> ^> ^Createuint32SimpleVecClass(int size);

			bool Resize(int newSize) override sealed;
			bool UninitialisedGrow(int newSize) override sealed;
			void UninitializedResize(int newSize) override sealed;
			IntPtr Peek() override sealed;

#pragma push_macro("ZeroMemory")
#undef ZeroMemory
			void ZeroMemory() override sealed;
#pragma pop_macro("ZeroMemory")

			property int Length
			{
				int get() override sealed;
			}

			property uint32 default[int]
			{
				uint32 get(int index) override sealed;
				void set(int index, uint32 value) override sealed;
			}

			property IntPtr uint32SimpleVecClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::SimpleVecClass<uint32> *Internaluint32SimpleVecClassPointer
			{
				virtual ::SimpleVecClass<uint32> *get();
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