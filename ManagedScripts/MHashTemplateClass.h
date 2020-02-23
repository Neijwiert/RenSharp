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
#include <HashTemplateClass.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System;
using namespace System::Collections;
using namespace System::Runtime::InteropServices;

namespace RenSharp
{
	generic<typename TKey, typename TValue>
	public interface class IHashTemplateIterator : public IUnmanagedObject
	{
		void Reset();

		void Remove();

		void Next();

		property TKey CurrentKey
		{
			TKey get();
		}

		property TValue CurrentValue
		{
			TValue get();
		}

		property bool IsDone
		{
			bool get();
		}
	};


	generic<typename TKey, typename TValue>
	public interface class IHashTemplateClass 
		: 
		public IUnmanagedObject,
		public Collections::IDictionary,
		public Generic::IDictionary<TKey, TValue>
	{
		TValue Get(TKey key);

		void Get(TKey key, TValue defaultValue, TValue %result);

		bool Exists(TKey key);

		void Insert(TKey key, TValue value);

		void RemoveAll();

		void GetValueByIndex(int index, TValue %result);

		property uint Size
		{
			uint get();
		}
	};

	generic<typename TKey, typename TValue>
	public ref class HashTemplateClass abstract : public AbstractUnmanagedObject, public IHashTemplateClass<TKey, TValue>
	{
		private:
			ref class Enumerator sealed : Generic::IEnumerator<Generic::KeyValuePair<TKey, TValue>>, Collections::IDictionaryEnumerator
			{
				private:
					HashTemplateClass<TKey, TValue> ^hashList;
					IUnmanagedContainer<IHashTemplateIterator<TKey, TValue> ^> ^iterator;
					bool reset;

				public:
					Enumerator(HashTemplateClass<TKey, TValue> ^hashList)
						: hashList(hashList), iterator(hashList->Iterator), reset(true)
					{
						
					}

					~Enumerator()
					{
#pragma push_macro("delete")
#undef delete
						delete iterator;
						iterator = nullptr;

#pragma pop_macro("delete")
					}

					virtual bool MoveNext() = Generic::IEnumerator<Generic::KeyValuePair<TKey, TValue>>::MoveNext
					{
						if (reset)
						{
							iterator->UnmanagedObject->Reset();

							reset = false;

							return (!iterator->UnmanagedObject->IsDone);
						}

						if (iterator->UnmanagedObject->IsDone)
						{
							return false;
						}

						iterator->UnmanagedObject->Next();

						return (!iterator->UnmanagedObject->IsDone);
					}

					virtual void Reset() = Generic::IEnumerator<Generic::KeyValuePair<TKey, TValue>>::Reset
					{
						iterator->UnmanagedObject->Reset();

						reset = true;
					}

					property Generic::KeyValuePair<TKey, TValue> Current
					{
						virtual Generic::KeyValuePair<TKey, TValue> get() = Generic::IEnumerator<Generic::KeyValuePair<TKey, TValue>>::Current::get
						{
							if (iterator->UnmanagedObject->IsDone)
							{
								throw gcnew ArgumentOutOfRangeException();
							}

							return Generic::KeyValuePair<TKey, TValue>(iterator->UnmanagedObject->CurrentKey, iterator->UnmanagedObject->CurrentValue);
						}
					}

					property Object ^Current2
					{
						virtual Object ^get() = Collections::IEnumerator::Current::get
						{
							return Current;
						}
					}

					property Object ^Key
					{
						virtual Object ^get()
						{
							if (iterator->UnmanagedObject->IsDone)
							{
								throw gcnew ArgumentOutOfRangeException();
							}

							return iterator->UnmanagedObject->CurrentKey;
						}
					}

					property Object ^Value
					{
						virtual Object ^get()
						{
							if (iterator->UnmanagedObject->IsDone)
							{
								throw gcnew ArgumentOutOfRangeException();
							}

							return iterator->UnmanagedObject->CurrentValue;
						}
					}

					property Collections::DictionaryEntry Entry
					{
						virtual Collections::DictionaryEntry get()
						{
							if (iterator->UnmanagedObject->IsDone)
							{
								throw gcnew ArgumentOutOfRangeException();
							}

							return Collections::DictionaryEntry(iterator->UnmanagedObject->CurrentKey, iterator->UnmanagedObject->CurrentValue);
						}
					}
			};

		public:
			HashTemplateClass(IntPtr pointer)
				: AbstractUnmanagedObject(pointer)
			{

			}

			virtual TValue Get(TKey key) = 0;
			virtual void Get(TKey key, TValue defaultValue, TValue %result) = 0;
			virtual bool Exists(TKey key) = 0;
			virtual void Insert(TKey key, TValue value) = 0;
			virtual void RemoveAll() = 0;
			virtual void GetValueByIndex(int index, TValue %result) = 0;
			virtual bool Remove(TKey key) = 0;
			virtual bool Remove(Generic::KeyValuePair<TKey, TValue> pair) = 0;
			virtual bool Contains(Generic::KeyValuePair<TKey, TValue> pair) = 0;
			virtual bool Contains(Object ^key) = 0;
			virtual void Add(Object ^key, Object ^value) = 0;
			virtual void Remove(Object ^key) = 0;

			virtual void Add(Generic::KeyValuePair<TKey, TValue> pair)
			{
				Insert(pair.Key, pair.Value);
			}

			virtual void Add(TKey key, TValue value)
			{
				Insert(key, value);
			}

			virtual void Clear()
			{
				RemoveAll();
			}

			virtual void CopyTo(array<Generic::KeyValuePair<TKey, TValue>> ^array, int arrayIndex)
			{
				CopyTo(safe_cast<Array ^>(array), arrayIndex);
			}

			virtual void CopyTo(Array ^array, int arrayIndex)
			{
				if (array == nullptr)
				{
					throw gcnew ArgumentNullException("array");
				}
				else if (arrayIndex < 0)
				{
					throw gcnew ArgumentOutOfRangeException("arrayIndex");
				}

				int index = arrayIndex;
				for each (auto pair in this)
				{
					if (index >= array->Length)
					{
						throw gcnew ArgumentException("The number of elements in the source ICollection<T> is greater than the available space from arrayIndex to the end of the destination array");
					}
					if (!Generic::KeyValuePair<TKey, TValue>::typeid->IsAssignableFrom(array->GetType()->GetElementType()))
					{
						throw gcnew System::ArgumentException("The type of the source ICollection cannot be cast automatically to the type of the destination array");
					}

					array->SetValue(pair, index++);
				}
			}

			virtual Generic::IEnumerator<Generic::KeyValuePair<TKey, TValue>> ^GetEnumerator() = Generic::IEnumerable<Generic::KeyValuePair<TKey, TValue>>::GetEnumerator
			{
				return gcnew Enumerator(this);
			}

			virtual Collections::IEnumerator^ GetEnumerator2() = Collections::IEnumerable::GetEnumerator
			{
				return GetEnumerator();
			}

			virtual Collections::IDictionaryEnumerator ^GetDictionaryEnumerator() = Collections::IDictionary::GetEnumerator
			{
				return gcnew Enumerator(this);
			}

			virtual bool TryGetValue(TKey key, [Out] TValue %value)
			{
				if (!Exists(key))
				{
					value = TValue();
					
					return false;
				}

				value = Get(key);

				return true;
			}

			virtual bool ContainsKey(TKey key)
			{
				return Exists(key);
			}

			property uint Size
			{
				virtual uint get() = 0;
			}

			virtual property int Count
			{
				int get()
				{
					return static_cast<int>(Size);
				}
			}

			virtual property bool IsReadOnly
			{
				bool get()
				{
					return false;
				}
			}

			virtual property Object ^SyncRoot
			{
				Object ^get()
				{
					return nullptr;
				}
			}

			virtual property bool IsSynchronized
			{
				bool get()
				{
					return false;
				}
			}

			virtual property TValue default[TKey]
			{
				TValue get(TKey key)
				{
					TValue result;
					if (!TryGetValue(key, result))
					{
						throw gcnew Generic::KeyNotFoundException();
					}

					return result;
				}

				void set(TKey key, TValue value)
				{
					Insert(key, value);
				}
			}

			property Object ^default[Object ^]
			{
				virtual Object ^get(Object ^key) = 0;
				virtual void set(Object ^key, Object ^value) = 0;
			}

			property Generic::ICollection<TKey> ^Keys
			{
				virtual Generic::ICollection<TKey> ^get() = Generic::IDictionary<TKey, TValue>::Keys::get
				{
					auto result = gcnew Generic::List<TKey>();

					for each (auto pair in this)
					{
						result->Add(pair.Key);
					}

					return result;
				}
			}

			property Collections::ICollection ^Keys2
			{
				virtual Collections::ICollection ^get() = Collections::IDictionary::Keys::get
				{
					return safe_cast<Collections::ICollection ^>(Keys);
				}
			}

			property Generic::ICollection<TValue> ^Values
			{
				virtual Generic::ICollection<TValue> ^get() = Generic::IDictionary<TKey, TValue>::Values::get
				{
					auto result = gcnew Generic::List<TValue>();

					for each (auto pair in this)
					{
						result->Add(pair.Value);
					}

					return result;
				}
			}

			property Collections::ICollection ^Values2
			{
				virtual Collections::ICollection ^get() = Collections::IDictionary::Values::get
				{
					return safe_cast<Collections::ICollection ^>(Values);
				}
			}

			property bool IsFixedSize
			{
				virtual bool get()
				{
					return false;
				}
			}

		protected:
			property IUnmanagedContainer<IHashTemplateIterator<TKey, TValue> ^> ^Iterator
			{
				virtual IUnmanagedContainer<IHashTemplateIterator<TKey, TValue> ^> ^get() = 0;
			}
	};
}