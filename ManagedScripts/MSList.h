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
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <SList.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public interface class IGenericSLNode : public IAutoPoolClass<IGenericSLNode ^>
	{
		property IntPtr GenericSLNodePointer
		{
			IntPtr get();
		}
	};

	public ref class GenericSLNode : public AutoPoolClass<IGenericSLNode ^>
	{
		public:
			GenericSLNode(IntPtr pointer);

			bool Equals(Object ^other) override;

			property IntPtr AutoPoolClassPointer
			{
				IntPtr get();
			}

			property IntPtr GenericSLNodePointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			void InternalSetNext(IntPtr next);
			void InternalSetData(IntPtr data);

			property ::AutoPoolClass<::GenericSLNode, 256> *InternalAutoPoolClassPointer
			{
				virtual ::AutoPoolClass<::GenericSLNode, 256> *get();
			}

			property ::GenericSLNode *InternalGenericSLNodePointer
			{
				virtual ::GenericSLNode *get();
			}

			property IntPtr NodeNext
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IntPtr NodeData
			{
				IntPtr get();
				void set(IntPtr value);
			}
	};

	generic<typename T>
	public interface class ISLNode : public IGenericSLNode
	{
		void SetNext(ISLNode<T> ^next);

		property ISLNode<T> ^Next
		{
			ISLNode<T> ^get();
		}

		property T Data
		{
			T get();
		}
	};

	generic<typename T>
	public ref class SLNode abstract : public GenericSLNode, public ISLNode<T>
	{
		public:
			SLNode(IntPtr pointer)
				: GenericSLNode(pointer)
			{

			}

			virtual void SetNext(ISLNode<T> ^next) = 0;

			property ISLNode<T> ^Next
			{
				virtual ISLNode<T> ^get() = 0;
			}

			property T Data
			{
				virtual T get() = 0;
			}
	};

	generic<class T>
	public interface class ISList 
		: 
		public IUnmanagedObject,
		public Generic::ICollection<T>,
		public Collections::ICollection,
		public Generic::IEnumerable<T>,
		public Collections::IEnumerable
	{
		bool AddHead(T data);

		bool AddHead(ISList<T> ^list);

		bool AddTail(T data);

		bool AddTail(ISList<T> ^list);

		T RemoveHead();

		T RemoveTail();

		void RemoveAll();

		bool InsertBefore(T newNode, T oldNode);

		bool InsertAfter(T newNode, T oldNode);

		ISLNode<T> ^FindNode(T data);

		void InsertBefore(T data, ISLNode<T> ^node);

		void InsertAfter(T data, ISLNode<T> ^node);

		property bool IsEmpty
		{
			bool get();
		}

		property ISLNode<T> ^Head
		{
			ISLNode<T> ^get();
		}

		property ISLNode<T> ^Tail
		{
			ISLNode<T> ^get();
		}
	};

	generic<typename T>
	public interface class ISLIterator : public IUnmanagedObject
	{
		void Next();

		property bool IsDone
		{
			bool get();
		}

		property T Current
		{
			T get();
		}
	};

	generic<typename T>
	public ref class SList abstract : public AbstractUnmanagedObject, public ISList<T>
	{
		private:
			ref class Enumerator sealed : Generic::IEnumerator<T>
			{
				private:
					ISList<T> ^list;
					ISLNode<T> ^node;
					bool reset;

				public:
					Enumerator(ISList<T> ^list)
						: list(list), node(nullptr), reset(true)
					{
						
					}

					~Enumerator()
					{

					}

					virtual bool MoveNext() = Generic::IEnumerator<T>::MoveNext
					{
						if (reset)
						{
							node = list->Head;

							reset = false;

							return (node != nullptr);
						}

						if (node == nullptr)
						{
							return false;
						}

						auto next = node->Next;
						if (next == nullptr)
						{
							return false;
						}

						node = next;

						return true;
					}

					virtual void Reset() = Generic::IEnumerator<T>::Reset
					{
						node = nullptr;
						reset = true;
					}

					property T Current
					{
						virtual T get() = Generic::IEnumerator<T>::Current::get
						{
							if (node == nullptr)
							{
								return T();
							}
							else
							{
								return node->Data;
							}
						}
					}

					property Object ^Current2
					{
						virtual Object ^get() = Collections::IEnumerator::Current::get
						{
							return Current;
						}
					}
			};

		public:
			SList(IntPtr pointer)
				: AbstractUnmanagedObject(pointer)
			{

			}

			virtual bool AddHead(T data) = 0;
			virtual bool AddHead(ISList<T> ^list) = 0;
			virtual bool AddTail(T data) = 0;
			virtual bool AddTail(ISList<T> ^list) = 0;
			virtual T RemoveHead() = 0;
			virtual T RemoveTail() = 0;
			virtual bool Remove(T data) = 0;
			virtual void RemoveAll() = 0;
			virtual bool InsertBefore(T newNode, T oldNode) = 0;
			virtual bool InsertAfter(T newNode, T oldNode) = 0;
			virtual ISLNode<T> ^FindNode(T data) = 0;
			virtual void InsertBefore(T data, ISLNode<T> ^node) = 0;
			virtual void InsertAfter(T data, ISLNode<T> ^node) = 0;

			virtual void Add(T item)
			{
				AddTail(item);
			}

			virtual bool Contains(T item)
			{
				if (item == nullptr)
				{
					return false;
				}

				for each (auto currentItem in this)
				{
					if (Object::Equals(currentItem, item))
					{
						return true;
					}
				}

				return false;
			}

			virtual void Clear()
			{
				RemoveAll();
			}

			virtual void CopyTo(array<T> ^array, int arrayIndex)
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
				for each (auto currentItem in this)
				{
					if (index >= array->Length)
					{
						throw gcnew ArgumentException("The number of elements in the source ICollection<T> is greater than the available space from arrayIndex to the end of the destination array");
					}

					if (!T::typeid->IsAssignableFrom(array->GetType()->GetElementType()))
					{
						throw gcnew System::ArgumentException("The type of the source ICollection cannot be cast automatically to the type of the destination array");
					}

					array->SetValue(currentItem, index++);
				}
			}

			virtual Generic::IEnumerator<T> ^GetEnumerator() = Generic::IEnumerable<T>::GetEnumerator
			{
				return gcnew Enumerator(this);
			}

			virtual Collections::IEnumerator^ GetEnumerator2() = Collections::IEnumerable::GetEnumerator
			{
				return SList<T>::GetEnumerator();
			}

			property bool IsEmpty
			{
				virtual bool get() = 0;
			}

			property ISLNode<T> ^Head
			{
				virtual ISLNode<T> ^get() = 0;
			}

			property ISLNode<T> ^Tail
			{
				virtual ISLNode<T> ^get() = 0;
			}

			property int Count
			{
				virtual int get() = 0;
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
	};

	generic<typename T>
	public ref class SLIterator abstract : public AbstractUnmanagedObject, public ISLIterator<T>
	{
		public:
			SLIterator(IntPtr pointer)
				: AbstractUnmanagedObject(pointer)
			{

			}

			virtual void Next() = 0;

			property bool IsDone
			{
				virtual bool get() = 0;
			}

			property T Current
			{
				virtual T get() = 0;
			}
	};
}