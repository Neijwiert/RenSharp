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

namespace RenSharp
{
	interface class IScriptableGameObj;

	public ref class ScriptableGameObjPtrSimpleDynVecClass : public SimpleDynVecClass<IScriptableGameObj ^>
	{
		private:
			ScriptableGameObjPtrSimpleDynVecClass();
			ScriptableGameObjPtrSimpleDynVecClass(int size);

		public:
			ScriptableGameObjPtrSimpleDynVecClass(IntPtr pointer);

			static IUnmanagedContainer<ISimpleDynVecClass<IScriptableGameObj ^> ^> ^CreateScriptableGameObjPtrSimpleDynVecClass();
			static IUnmanagedContainer<ISimpleDynVecClass<IScriptableGameObj ^> ^> ^CreateScriptableGameObjPtrSimpleDynVecClass(int size);

			bool Resize(int newSize) override sealed;
			bool UninitialisedGrow(int newSize) override sealed;
			void UninitializedResize(int newSize) override sealed;
			IntPtr Peek() override sealed;

#pragma push_macro("ZeroMemory")
#undef ZeroMemory
			void ZeroMemory() override sealed;
#pragma pop_macro("ZeroMemory")

			int FindIndex(IScriptableGameObj ^object) override sealed;
			bool Add(IScriptableGameObj ^data, int newSizeHint) override sealed;
			bool Add(IScriptableGameObj ^data) override;
			int AddMultiple(int numberToAdd) override sealed;
			bool AddHead(IScriptableGameObj ^object) override sealed;
			void Insert(int index, IScriptableGameObj ^item) override;
			bool DeleteIndex(int index, bool allowShrink) override sealed;
			bool DeleteIndex(int index) override sealed;
			bool DeleteObject(IScriptableGameObj ^object, bool allowShrink) override sealed;
			bool DeleteObject(IScriptableGameObj ^object) override sealed;
			bool DeleteRange(int start, int count, bool allowShrink) override sealed;
			bool DeleteRange(int start, int count) override sealed;
			void DeleteAll(bool allowShrink) override sealed;
			void DeleteAll() override sealed;

			property IntPtr ScriptableGameObjPtrSimpleDynVecClassPointer
			{
				IntPtr get();
			}

			property int Length
			{
				int get() override sealed;
			}

			property IScriptableGameObj ^default[int]
			{
				IScriptableGameObj ^get(int index) override;
				void set(int index, IScriptableGameObj ^value) override;
			}

			property bool IsEmpty
			{
				bool get() override;
			}

			property int Count
			{
				virtual int get() override;
			}

		protected:
			bool InternalDestroyPointer() override;
			bool Grow(int newSizeHint) override sealed;
			bool Shrink() override sealed;

			property ::SimpleDynVecClass<::ScriptableGameObj *> *InternalScriptableGameObjPtrSimpleDynVecClassPointer
			{
				virtual ::SimpleDynVecClass<::ScriptableGameObj *> *get();
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

			property int ActiveCount
			{
				int get() override sealed;
				void set(int value) override sealed;
			}
	};
}