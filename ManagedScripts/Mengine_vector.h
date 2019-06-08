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

#include "Imports.h"
#include "IUnmanagedObject.h"
#include "UnmanagedContainer.h"
#include "AbstractUnmanagedObject.h"

#pragma managed(push, off)

class DialogueOptionClass;

#pragma managed(pop)

using namespace System;
using namespace System::Collections;
using namespace System::Runtime::InteropServices;
using namespace System::Diagnostics;

namespace RenSharp
{
	interface class IGenericList;

	public interface class IGenericNode : public IUnmanagedObject
	{
		void Unlink();

		void Link(IGenericNode ^node);

		property IntPtr GenericNodePointer
		{
			IntPtr get();
		}

		[DebuggerBrowsable(DebuggerBrowsableState::Never)]
		[Obsolete("This property is unsafe", true)]
		property IGenericList ^MainList
		{
			IGenericList ^get();
		}

		property IGenericNode ^Next
		{
			IGenericNode ^get();
		}

		property IGenericNode ^NextValid
		{
			IGenericNode ^get();
		}

		property IGenericNode ^Prev
		{
			IGenericNode ^get();
		}

		property IGenericNode ^PrevValid
		{
			IGenericNode ^get();
		}

		property bool IsValid
		{
			bool get();
		}
	};

#pragma managed(push, off)

	class GenericNodeHelper : public ::GenericNode
	{
		private:
			GenericNodeHelper() = default;

		public:
			::GenericNode *GetNextNode() const
			{
				return NextNode;
			}

			void SetNextNode(::GenericNode *value)
			{
				NextNode = value;
			}

			::GenericNode *GetPrevNode() const
			{
				return PrevNode;
			}

			void SetPrevNode(::GenericNode *value)
			{
				PrevNode = value;
			}
	};

#pragma managed(pop)

	public ref class GenericNode : public AbstractUnmanagedObject, public IGenericNode
	{
		private:
			GenericNode()
				: AbstractUnmanagedObject(IntPtr(Imports::CreateGenericNode()))
			{

			}

		public:
			GenericNode(IntPtr pointer)
				: AbstractUnmanagedObject(pointer)
			{
			}

			static IUnmanagedContainer<IGenericNode ^> ^CreateGenericNode()
			{
				return gcnew UnmanagedContainer<IGenericNode ^>(gcnew GenericNode());
			}

			virtual void Unlink() sealed
			{
				InternalGenericNodePointer->Unlink();
			}

			virtual void Link(IGenericNode ^node) sealed
			{
				if (node == nullptr || node->Pointer.ToPointer() == nullptr)
				{
					throw gcnew ArgumentNullException("node");
				}

				InternalGenericNodePointer->Link(reinterpret_cast<::GenericNode *>(node->GenericNodePointer.ToPointer()));
			}

			property IntPtr GenericNodePointer
			{
				virtual IntPtr get() sealed
				{
					return IntPtr(InternalGenericNodePointer);
				}
			}

			[DebuggerBrowsable(DebuggerBrowsableState::Never)]
			[Obsolete("This property is unsafe", true)]
			property IGenericList ^MainList
			{
				virtual IGenericList ^get() sealed;
			}

			property IGenericNode ^Next
			{
				virtual IGenericNode ^get() sealed
				{
					auto next = InternalGenericNodePointer->Next();
					if (next == nullptr)
					{
						return nullptr;
					}
					else
					{
						return gcnew GenericNode(IntPtr(next));
					}
				}
			}

			property IGenericNode ^NextValid
			{
				virtual IGenericNode ^get() sealed
				{
					auto nextValid = InternalGenericNodePointer->Next_Valid();
					if (nextValid == nullptr)
					{
						return nullptr;
					}
					else
					{
						return gcnew GenericNode(IntPtr(nextValid));
					}
				}
			}

			property IGenericNode ^Prev
			{
				virtual IGenericNode ^get() sealed
				{
					auto prev = InternalGenericNodePointer->Prev();
					if (prev == nullptr)
					{
						return nullptr;
					}
					else
					{
						return gcnew GenericNode(IntPtr(prev));
					}
				}
			}

			property IGenericNode ^PrevValid
			{
				virtual IGenericNode ^get() sealed
				{
					auto prevValid = InternalGenericNodePointer->Prev_Valid();
					if (prevValid == nullptr)
					{
						return nullptr;
					}
					else
					{
						return gcnew GenericNode(IntPtr(prevValid));
					}
				}
			}

			property bool IsValid
			{
				virtual bool get() sealed
				{
					return InternalGenericNodePointer->Is_Valid();
				}
			}

		protected:
			bool InternalDestroyPointer() override
			{
				Imports::DestroyGenericNode(InternalGenericNodePointer);
				Pointer = IntPtr::Zero;

				return true;
			}

			property ::GenericNode *InternalGenericNodePointer
			{
				virtual ::GenericNode *get()
				{
					return reinterpret_cast<::GenericNode *>(Pointer.ToPointer());
				}
			}

			property IGenericNode ^NextNode
			{
				IGenericNode ^get()
				{
					auto *helper = reinterpret_cast<GenericNodeHelper *>(InternalGenericNodePointer);
					auto nextNode = helper->GetNextNode();
					if (nextNode == nullptr)
					{
						return nullptr;
					}
					else
					{
						return gcnew GenericNode(IntPtr(nextNode));
					}
				}

				void set(IGenericNode ^value)
				{
					auto *helper = reinterpret_cast<GenericNodeHelper *>(InternalGenericNodePointer);
					if (value == nullptr)
					{
						helper->SetNextNode(nullptr);
					}
					else
					{
						helper->SetNextNode(reinterpret_cast<::GenericNode *>(value->Pointer.ToPointer()));
					}
				}
			}

			property IGenericNode ^PrevNode
			{
				IGenericNode ^get()
				{
					auto *helper = reinterpret_cast<GenericNodeHelper *>(InternalGenericNodePointer);
					auto prevNode = helper->GetPrevNode();
					if (prevNode == nullptr)
					{
						return nullptr;
					}
					else
					{
						return gcnew GenericNode(IntPtr(prevNode));
					}
				}

				void set(IGenericNode ^value)
				{
					auto *helper = reinterpret_cast<GenericNodeHelper *>(InternalGenericNodePointer);
					if (value == nullptr)
					{
						helper->SetPrevNode(nullptr);
					}
					else
					{
						helper->SetPrevNode(reinterpret_cast<::GenericNode *>(value->GenericNodePointer.ToPointer()));
					}
				}
			}
	};

	public interface class IGenericList : 
		public IUnmanagedObject, 
		public Collections::ICollection, 
		public Collections::IEnumerable
	{
		void AddHead(IGenericNode ^node);

		void AddTail(IGenericNode ^node);

		property IntPtr GenericListPointer
		{
			IntPtr get();
		}

		property IGenericNode ^First
		{
			IGenericNode ^get();
		}

		property IGenericNode ^FirstValid
		{
			IGenericNode ^get();
		}

		property IGenericNode ^Last
		{
			IGenericNode ^get();
		}

		property IGenericNode ^LastValid
		{
			IGenericNode ^get();
		}

		property bool IsEmpty
		{
			bool get();
		}

		property int ValidCount
		{
			int get();
		}
	};

#pragma managed(push, off)

	class GenericListHelper : public ::GenericList
	{
		private:
			GenericListHelper() = default;

		public:
			::GenericNode &GetFirstNode()
			{
				return FirstNode;
			}

			void SetFirstNode(::GenericNode &value)
			{
				FirstNode = value;
			}

			::GenericNode &GetLastNode()
			{
				return LastNode;
			}

			void SetLastNode(::GenericNode &value)
			{
				LastNode = value;
			}
	};

#pragma managed(pop)

	public ref class GenericList : public AbstractUnmanagedObject, public IGenericList
	{
		private:
			ref class Enumerator sealed : Generic::IEnumerator<IGenericNode^>
			{
				private:
					GenericList^ list;
					IGenericNode^ current;
					bool reset;

				public:
					Enumerator(GenericList^ list)
						: list(list), current(nullptr), reset(true)
					{

					}

					~Enumerator()
					{

					}

					virtual bool MoveNext() = Generic::IEnumerator<IGenericNode^>::MoveNext
					{
						if (reset)
						{
							current = list->FirstValid;

							reset = false;

							return (current != nullptr);
						}

						if (current == nullptr)
						{
							return false;
						}

						current = current->NextValid;

						return (current != nullptr);
					}

					virtual void Reset() = Generic::IEnumerator<IGenericNode^>::Reset
					{
						current = nullptr;
						reset = true;
					}

					property IGenericNode^ Current
					{
						virtual IGenericNode^ get() = Generic::IEnumerator<IGenericNode^>::Current::get
						{
							return current;
						}
					}

					property Object^ Current2
					{
						virtual Object^ get() = Collections::IEnumerator::Current::get
						{
							return Current;
						}
					}
			};

			GenericList()
				: AbstractUnmanagedObject(IntPtr(Imports::CreateGenericList()))
			{

			}

		public:
			GenericList(IntPtr pointer)
				: AbstractUnmanagedObject(pointer)
			{

			}

			static IUnmanagedContainer<IGenericList ^> ^CreateGenericList()
			{
				return gcnew UnmanagedContainer<IGenericList ^>(gcnew GenericList());
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
				for (auto node = InternalGenericListPointer->First(); node != nullptr && node->Is_Valid(); node = node->Next())
				{
					if (index >= array->Length)
					{
						throw gcnew ArgumentException("The number of elements in the source ICollection<T> is greater than the available space from arrayIndex to the end of the destination array");
					}

					if (!IGenericNode::typeid->IsAssignableFrom(array->GetType()->GetElementType()))
					{
						throw gcnew System::ArgumentException("The type of the source ICollection cannot be cast automatically to the type of the destination array");
					}

					array->SetValue(gcnew GenericNode(IntPtr(node)), index++);
				}
			}

			virtual Collections::IEnumerator^ GetEnumerator2() = Collections::IEnumerable::GetEnumerator
			{
				return gcnew Enumerator(this);
			}

			property IntPtr GenericListPointer
			{
				virtual IntPtr get() sealed
				{
					return IntPtr(InternalGenericListPointer);
				}
			}

			virtual property int Count
			{
				int get()
				{
					return ValidCount;
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

			virtual void AddHead(IGenericNode ^node)
			{
				if (node == nullptr || node->Pointer.ToPointer() == nullptr)
				{
					throw gcnew ArgumentNullException("node");
				}

				InternalGenericListPointer->Add_Head(reinterpret_cast<::GenericNode *>(node->GenericNodePointer.ToPointer()));
			}

			virtual void AddTail(IGenericNode ^node)
			{
				if (node == nullptr || node->Pointer.ToPointer() == nullptr)
				{
					throw gcnew ArgumentNullException("node");
				}

				InternalGenericListPointer->Add_Tail(reinterpret_cast<::GenericNode *>(node->GenericNodePointer.ToPointer()));
			}

			property IGenericNode ^First
			{
				virtual IGenericNode ^get() sealed
				{
					::GenericNode *first = InternalGenericListPointer->First();
					if (first == nullptr)
					{
						return nullptr;
					}
					else
					{
						return gcnew GenericNode(IntPtr(first));
					}
				}
			}

			property IGenericNode ^FirstValid
			{
				virtual IGenericNode ^get() sealed
				{
					::GenericNode *firstValid = InternalGenericListPointer->First_Valid();
					if (firstValid == nullptr)
					{
						return nullptr;
					}
					else
					{
						return gcnew GenericNode(IntPtr(firstValid));
					}
				}
			}

			property IGenericNode ^Last
			{
				virtual IGenericNode ^get() sealed
				{
					::GenericNode *last = InternalGenericListPointer->Last();
					if (last == nullptr)
					{
						return nullptr;
					}
					else
					{
						return gcnew GenericNode(IntPtr(last));
					}
				}
			}

			property IGenericNode ^LastValid
			{
				virtual IGenericNode ^get() sealed
				{
					::GenericNode *lastValid = InternalGenericListPointer->Last_Valid();
					if (lastValid == nullptr)
					{
						return nullptr;
					}
					else
					{
						return gcnew GenericNode(IntPtr(lastValid));
					}
				}
			}

			property bool IsEmpty
			{
				virtual bool get() sealed
				{
					return InternalGenericListPointer->Is_Empty();
				}
			}

			property int ValidCount
			{
				virtual int get() sealed
				{
					return InternalGenericListPointer->Get_Valid_Count();
				}
			}

		protected:
			bool InternalDestroyPointer() override
			{
				Imports::DestroyGenericList(InternalGenericListPointer);
				Pointer = IntPtr::Zero;

				return true;
			}

			property ::GenericList *InternalGenericListPointer
			{
				virtual ::GenericList *get()
				{
					return reinterpret_cast<::GenericList *>(Pointer.ToPointer());
				}
			}

			property IGenericNode ^FirstNode
			{
				IGenericNode ^get()
				{
					auto helper = reinterpret_cast<GenericListHelper *>(InternalGenericListPointer);

					return gcnew GenericNode(IntPtr(&helper->GetFirstNode()));
				}

				void set(IGenericNode ^value)
				{
					if (value == nullptr || value->Pointer.ToPointer() == nullptr)
					{
						throw gcnew ArgumentNullException("value");
					}

					auto helper = reinterpret_cast<GenericListHelper *>(InternalGenericListPointer);

					helper->SetFirstNode(*reinterpret_cast<::GenericNode *>(value->GenericNodePointer.ToPointer()));
				}
			}

			property IGenericNode ^LastNode
			{
				IGenericNode ^get()
				{
					auto helper = reinterpret_cast<GenericListHelper *>(InternalGenericListPointer);

					return gcnew GenericNode(IntPtr(&helper->GetLastNode()));
				}

				void set(IGenericNode ^value)
				{
					if (value == nullptr || value->Pointer.ToPointer() == nullptr)
					{
						throw gcnew ArgumentNullException("value");
					}

					auto helper = reinterpret_cast<GenericListHelper *>(InternalGenericListPointer);

					helper->SetLastNode(*reinterpret_cast<::GenericNode *>(value->GenericNodePointer.ToPointer()));
				}
			}
	};

	generic<typename T> 
	interface class IList;

	generic<typename T>
	public interface class INode : public IGenericNode
	{
		[DebuggerBrowsable(DebuggerBrowsableState::Never)]
		[Obsolete("This property is unsafe", true)]
		property IList<T> ^TMainList
		{
			IList<T> ^get();
		}

		property T TNext
		{
			T get();
		}

		property T TNextValid
		{
			T get();
		}

		property T TPrev
		{
			T get();
		}

		property T TPrevValid
		{
			T get();
		}
	};

	generic<typename T>
	where T : ref class, INode<T>
	public ref class Node abstract : public GenericNode, public INode<T>
	{
		public:
			Node(IntPtr pointer)
				: GenericNode(pointer)
			{

			}

			[DebuggerBrowsable(DebuggerBrowsableState::Never)]
			[Obsolete("This property is unsafe", true)]
			property IList<T> ^TMainList
			{
				virtual IList<T> ^get() = 0;
			}

			property T TNext
			{
				virtual T get() = 0;
			}

			property T TNextValid
			{
				virtual T get() = 0;
			}

			property T TPrev
			{
				virtual T get() = 0;
			}

			property T TPrevValid
			{
				virtual T get() = 0;
			}
	};

	generic<typename T>
	public interface class IList : 
		public IGenericList,
		public Generic::ICollection<T>,
		public Generic::IEnumerable<T>
	{
		void Delete();

		property T TFirst
		{
			T get();
		}

		property T TFirstValid
		{
			T get();
		}

		property T TLast
		{
			T get();
		}

		property T TLastValid
		{
			T get();
		}
	};

	generic<typename T>
	where T : ref class, INode<T>
	public ref class List abstract : public GenericList, public IList<T>
	{
		private:
			ref class Enumerator sealed : Generic::IEnumerator<T>
			{
				private:
					List<T> ^list;
					T current;
					bool reset;

				public:
					Enumerator(List<T> ^list) 
						: list(list), current(T()), reset(true)
					{
						
					}

					~Enumerator()
					{

					}

					virtual bool MoveNext() = Generic::IEnumerator<T>::MoveNext
					{
						if (reset)
						{
							current = list->TFirstValid;

							reset = false;

							return (current != nullptr);
						}

						if (current == nullptr)
						{
							return false;
						}
						
						current = current->TNextValid;

						return (current != nullptr);
					}

					virtual void Reset() = Generic::IEnumerator<T>::Reset
					{
						current = T();
						reset = true;
					}

					property T Current
					{
						virtual T get() = Generic::IEnumerator<T>::Current::get
						{
							return current;
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
			List(IntPtr pointer)
				: GenericList(pointer)
			{

			}

			virtual void Delete() = 0;

			property T TFirst
			{
				virtual T get() = 0;
			}

			property T TFirstValid
			{
				virtual T get() = 0;
			}

			property T TLast
			{
				virtual T get() = 0;
			}

			property T TLastValid
			{
				virtual T get() = 0;
			}

			virtual void Add(T item)
			{
				AddTail(item);
			}

			virtual void Clear()
			{
				for (auto node = InternalGenericListPointer->First(); node != nullptr && node->Is_Valid(); node = InternalGenericListPointer->First())
				{
					node->Unlink();
				}
			}

			virtual bool Contains(T item)
			{
				if (item == nullptr || item->Pointer.ToPointer() == nullptr)
				{
					return false;
				}

				for (auto node = InternalGenericListPointer->First(); node != nullptr && node->Is_Valid(); node = node->Next())
				{
					if (node == item->GenericNodePointer.ToPointer())
					{
						return true;
					}
				}

				return false;
			}

			virtual void CopyTo(array<T> ^array, int arrayIndex)
			{
				CopyTo(safe_cast<Array ^>(array), arrayIndex);
			}

			virtual bool Remove(T item)
			{
				if (item == nullptr || item->Pointer.ToPointer() == nullptr)
				{
					return false;
				}

				for (auto node = InternalGenericListPointer->First(); node != nullptr && node->Is_Valid(); node = node->Next())
				{
					if (node == item->GenericNodePointer.ToPointer())
					{
						node->Unlink();

						return true;
					}
				}

				return false;
			}

#pragma push_macro("new")
#undef new

			virtual Generic::IEnumerator<T> ^GetEnumerator()
			{
				return gcnew Enumerator(this);
			}

#pragma pop_macro("new")

			Collections::IEnumerator^ GetEnumerator2() override
			{
				return List<T>::GetEnumerator();
			}

			virtual property bool IsReadOnly
			{
				bool get()
				{
					return false;
				}
			}
	};

	generic<typename K, typename V>
	public interface class IIndexClass : public IUnmanagedObject, public Generic::IDictionary<K, V>
	{
		bool RemoveIndex(K id);

		bool IsPresent(K id);

		bool AddIndex(K id, V data);

		void InvalidateArchive();

		void Clear();

		bool IsArchiveSame(K id);

		bool IncreaseTableSize(int amount);

		K FetchIDByPosition(int position);

		V FetchByPosition(int position);

		property int Count
		{
			int get();
		}

		property V default[K]
		{
			V get(K key);
		}
	};

	generic<typename K, typename V>
	public ref class IndexClass abstract : public AbstractUnmanagedObject, public IIndexClass<K, V>
	{
		private:
			ref class Enumerator sealed : Generic::IEnumerator<Generic::KeyValuePair<K, V>>
			{
				private:
					IndexClass<K, V> ^indexClass;
					int position;

				public:
					Enumerator(IndexClass<K, V> ^indexClass)
						: indexClass(indexClass), position(-1)
					{

					}

					~Enumerator()
					{

					}

					virtual bool MoveNext() = Generic::IEnumerator<Generic::KeyValuePair<K, V>>::MoveNext
					{
						position++;

						if (position >= indexClass->Count)
						{
							return false;
						}

						return true;
					}

					virtual void Reset() = Generic::IEnumerator<Generic::KeyValuePair<K, V>>::Reset
					{
						position = -1;
					}

					property Generic::KeyValuePair<K, V> Current
					{
						virtual Generic::KeyValuePair<K, V> get() = Generic::IEnumerator<Generic::KeyValuePair<K, V>>::Current::get
						{
							if (position < 0 || position >= indexClass->Count)
							{
								throw gcnew IndexOutOfRangeException();
							}

							K key = indexClass->FetchIDByPosition(position);
							V value = indexClass->FetchByPosition(position);

							return Collections::Generic::KeyValuePair<K, V>(key, value);
						}
					}

					property Object ^Current2
					{
						virtual Object ^get() = System::Collections::IEnumerator::Current::get
						{
							return Current;
						}
					}
			};
		public:
			IndexClass(IntPtr pointer)
				: AbstractUnmanagedObject(pointer)
			{

			}

			virtual bool RemoveIndex(K id) = 0;

			virtual bool IsPresent(K id) = 0;

			virtual bool AddIndex(K id, V data) = 0;

			virtual void InvalidateArchive() = 0;

			virtual void Clear() = 0;

			virtual bool IsArchiveSame(K id) = 0;

			virtual bool IncreaseTableSize(int amount) = 0;

			virtual K FetchIDByPosition(int position) = 0;

			virtual V FetchByPosition(int position) = 0;

			virtual Generic::IEnumerator<Generic::KeyValuePair<K, V>> ^ GetEnumerator() = Generic::IEnumerable<Generic::KeyValuePair<K, V>>::GetEnumerator
			{
				return gcnew Enumerator(this);
			}

			virtual Collections::IEnumerator ^GetEnumerator2() = Collections::IEnumerable::GetEnumerator
			{
				return GetEnumerator();
			}

			virtual void Add(Generic::KeyValuePair<K, V> item)
			{
				Add(item.Key, item.Value);
			}

			virtual bool Contains(Generic::KeyValuePair<K, V> item)
			{
				if (!IsPresent(item.Key))
				{
					return false;
				}
				
				return Object::Equals(this[item.Key], item.Value);
			}

			virtual void CopyTo(array<Generic::KeyValuePair<K, V>> ^array, int arrayIndex)
			{
				if (array == nullptr)
				{
					throw gcnew ArgumentNullException("array");
				}
				else if (arrayIndex < 0)
				{
					throw gcnew ArgumentOutOfRangeException("arrayIndex");
				}

				int count = Count;
				int targetIndex = arrayIndex;
				for (int x = 0; x < count; x++, targetIndex++)
				{
					if (targetIndex >= array->Length)
					{
						throw gcnew ArgumentException("The number of elements in the source ICollection<T> is greater than the available space from arrayIndex to the end of the destination array");
					}

					K key = FetchIDByPosition(x);
					V value = FetchByPosition(x);

					array[targetIndex] = Generic::KeyValuePair<K, V>(key, value);
				}
			}

			virtual bool Remove(Generic::KeyValuePair<K, V> item)
			{
				if (Contains(item))
				{
					return RemoveIndex(item.Key);
				}

				return false;
			}

			virtual bool Remove(K key)
			{
				return RemoveIndex(key);
			}

			virtual bool ContainsKey(K key)
			{
				return IsPresent(key);
			}

			virtual void Add(K key, V value)
			{
				if (ContainsKey(key))
				{
					throw gcnew ArgumentException(String::Format("Key '{0}' already exists", key));
				}

				AddIndex(key, value);
			}

			virtual bool TryGetValue(K key, [Out] V %value)
			{
				value = V();

				if (!ContainsKey(key))
				{
					return false;
				}

				value = this[key];

				return true;
			}

			virtual property bool IsReadOnly
			{
				bool get()
				{
					return false;
				}
			}

			virtual property Generic::ICollection<K> ^Keys
			{
				Generic::ICollection<K> ^get()
				{
					int count = Count;
					Generic::ICollection<K> ^result = gcnew Generic::List<K>(count);
					for (int x = 0; x < count; x++)
					{
						result->Add(FetchIDByPosition(x));
					}

					return result;
				}
			}

			virtual property Generic::ICollection<V> ^Values
			{
				Generic::ICollection<V> ^get()
				{
					int count = Count;
					Generic::ICollection<V> ^result = gcnew Generic::List<V>(count);
					for (int x = 0; x < count; x++)
					{
						result->Add(FetchByPosition(x));
					}

					return result;
				}
			}

			property int Count
			{
				virtual int get() = 0;
			}

			property V default[K]
			{
				virtual V get(K key) = 0;

				virtual void set(K key, V value)
				{
					if (!RemoveIndex(key))
					{
						throw gcnew Collections::Generic::KeyNotFoundException();
					}

					AddIndex(key, value);
				}
			}
	};

	generic<typename T>
	public interface class ISimpleVecClass : 
		public IUnmanagedObject,
		public Collections::IEnumerable,
		public Generic::IEnumerable<T>
	{
		bool Resize(int newSize);

		bool UninitialisedGrow(int newSize);

		void UninitializedResize(int newSize);

		IntPtr Peek();

#pragma push_macro("ZeroMemory")
#undef ZeroMemory
		void (ZeroMemory)();
#pragma pop_macro("ZeroMemory")

		property int Length
		{
			int get();
		}

		property T default[int]
		{
			T get(int index);
			void set(int index, T value);
		}
	};

	generic<typename T>
	public ref class SimpleVecClass abstract : public AbstractUnmanagedObject, public ISimpleVecClass<T>
	{
		private:
			ref class Enumerator sealed : Generic::IEnumerator<T>
			{
				private:
					SimpleVecClass<T> ^simpleVecClass;
					int index;

				public:
					Enumerator(SimpleVecClass<T> ^simpleVecClass)
						: simpleVecClass(simpleVecClass), index(-1)
					{

					}

					~Enumerator()
					{

					}

					virtual bool MoveNext() = Generic::IEnumerator<T>::MoveNext
					{
						index++;

						if (index >= simpleVecClass->Length)
						{
							return false;
						}

						return true;
					}

					virtual void Reset() = Generic::IEnumerator<T>::Reset
					{
						index = -1;
					}

					property T Current
					{
						virtual T get() = Generic::IEnumerator<T>::Current::get
						{
							if (index < 0 || index >= simpleVecClass->Length)
							{
								throw gcnew IndexOutOfRangeException();
							}

							return simpleVecClass[index];
						}
					}

					property Object ^Current2
					{
						virtual Object ^get() = System::Collections::IEnumerator::Current::get
						{
							return Current;
						}
					}
			};

		protected:
			SimpleVecClass()
				: AbstractUnmanagedObject()
			{

			}

		public:
			SimpleVecClass(IntPtr pointer)
				: AbstractUnmanagedObject(pointer)
			{

			}

			virtual Generic::IEnumerator<T> ^ GetEnumerator() = Generic::IEnumerable<T>::GetEnumerator
			{
				return gcnew Enumerator(this);
			}

			virtual Collections::IEnumerator ^GetEnumerator2() = Collections::IEnumerable::GetEnumerator
			{
				return GetEnumerator();
			}

			virtual bool Resize(int newSize) = 0;
			virtual bool UninitialisedGrow(int newSize) = 0;
			virtual void UninitializedResize(int newSize) = 0;
			virtual IntPtr Peek() = 0;

#pragma push_macro("ZeroMemory")
#undef ZeroMemory
			virtual void ZeroMemory() = 0;
#pragma pop_macro("ZeroMemory")

			property int Length
			{
				virtual int get() = 0;
			}

			property T default[int]
			{
				virtual T get(int index) = 0;
				virtual void set(int index, T value) = 0;
			}

		protected:
			property IntPtr Vector
			{
				virtual IntPtr get() = 0;
				virtual void set(IntPtr value) = 0;
			}

			property int VectorMax
			{
				virtual int get() = 0;
				virtual void set(int value) = 0;
			}
	};

#pragma managed(push, off)

	template<class T>
	class SimpleVecClassHelper : public ::SimpleVecClass<T>
	{
		private:
			SimpleVecClassHelper() = default;

		public:
			T *&GetVector()
			{
				return Vector;
			}

			int &GetVectorMax()
			{
				return VectorMax;
			}
	};

#pragma managed(pop)

	generic<typename T>
	public interface class ISimpleDynVecClass : 
		public ISimpleVecClass<T>,
		public Collections::IList,
		public Generic::IList<T>
	{
		int FindIndex(T object);

		bool Add(T data, int newSizeHint);

		int AddMultiple(int numberToAdd);

		bool AddHead(T object);

		bool DeleteIndex(int index, bool allowShrink);

		bool DeleteIndex(int index);

		bool DeleteObject(T object, bool allowShrink);

		bool DeleteObject(T object);

		bool DeleteRange(int start, int count, bool allowShrink);

		bool DeleteRange(int start, int count);

		void DeleteAll(bool allowShrink);

		void DeleteAll();

		property bool IsEmpty
		{
			bool get();
		}
	};

	generic<typename T>
	public ref class SimpleDynVecClass abstract : public SimpleVecClass<T>, public ISimpleDynVecClass<T>
	{
		private:
			ref class Enumerator sealed : Generic::IEnumerator<T>
			{
				private:
					SimpleDynVecClass<T> ^simpleDynVecClass;
					int index;

				public:
					Enumerator(SimpleDynVecClass<T> ^simpleDynVecClass)
						: simpleDynVecClass(simpleDynVecClass), index(-1)
					{

					}

					~Enumerator()
					{

					}

					virtual bool MoveNext() = Generic::IEnumerator<T>::MoveNext
					{
						index++;

						if (index >= simpleDynVecClass->Count)
						{
							return false;
						}

						return true;
					}

					virtual void Reset() = Generic::IEnumerator<T>::Reset
					{
						index = -1;
					}

					property T Current
					{
						virtual T get() = Generic::IEnumerator<T>::Current::get
						{
							if (index < 0 || index >= simpleDynVecClass->Length)
							{
								throw gcnew IndexOutOfRangeException();
							}

							return simpleDynVecClass[index];
						}
					}

					property Object ^Current2
					{
						virtual Object ^get() = System::Collections::IEnumerator::Current::get
						{
							return Current;
						}
					}
			};
		protected:
			SimpleDynVecClass()
				: SimpleVecClass<T>()
			{

			}

		public:
			SimpleDynVecClass(IntPtr pointer)
				: SimpleVecClass<T>(pointer)
			{

			}

			virtual Generic::IEnumerator<T> ^GetEnumerator() override
			{
				return gcnew Enumerator(this);
			}

			virtual void CopyTo(array<T> ^array, int index)
			{
				CopyTo(safe_cast<Array ^>(array), index);
			}

			virtual void CopyTo(Array ^array, int index)
			{
				if (array == nullptr)
				{
					throw gcnew ArgumentNullException("array");
				}
				else if (index < 0)
				{
					throw gcnew ArgumentOutOfRangeException("index");
				}

				int count = Count;
				int targetIndex = index;
				for (int x = 0; x < count; x++, targetIndex++)
				{
					if (targetIndex >= array->Length)
					{
						throw gcnew ArgumentException("The number of elements in the source ICollection<T> is greater than the available space from arrayIndex to the end of the destination array");
					}

					T value = this[x];

					array->SetValue(value, targetIndex);
				}
			}

			virtual int Add(Object ^obj)
			{
				if (obj == nullptr)
				{
					throw gcnew ArgumentNullException("obj");
				}
				else if (!T::typeid->IsAssignableFrom(obj->GetType()))
				{
					throw gcnew ArgumentException(String::Format("'obj' Must be of type '{0}'", T::typeid->FullName));
				}

				int index = Count;
				if (Add(safe_cast<T>(obj)))
				{
					return index;
				}
				else
				{
					return -1;
				}
			}

			virtual bool Contains(T item)
			{
				return (FindIndex(item) != -1);
			}

			virtual bool Contains(Object ^obj)
			{
				if (obj == nullptr)
				{
					throw gcnew ArgumentNullException("obj");
				}
				else if (!T::typeid->IsAssignableFrom(obj->GetType()))
				{
					throw gcnew ArgumentException(String::Format("'obj' Must be of type '{0}'", T::typeid->FullName));
				}

				return Contains(safe_cast<T>(obj));
			}

			virtual void Clear()
			{
				DeleteAll();
			}

			virtual int IndexOf(T item)
			{
				return FindIndex(item);
			}

			virtual int IndexOf(Object ^obj)
			{
				if (obj == nullptr)
				{
					throw gcnew ArgumentNullException("obj");
				}
				else if (!T::typeid->IsAssignableFrom(obj->GetType()))
				{
					throw gcnew ArgumentException(String::Format("'obj' Must be of type '{0}'", T::typeid->FullName));
				}

				return IndexOf(safe_cast<T>(obj));
			}

			virtual bool Remove(T item)
			{
				return DeleteObject(item);
			}

			virtual void Remove(Object ^obj)
			{
				if (obj == nullptr)
				{
					throw gcnew ArgumentNullException("obj");
				}
				else if (!T::typeid->IsAssignableFrom(obj->GetType()))
				{
					throw gcnew ArgumentException(String::Format("'obj' Must be of type '{0}'", T::typeid->FullName));
				}

				Remove(safe_cast<T>(obj));
			}

			virtual void RemoveAt(int index)
			{
				DeleteIndex(index);
			}

			virtual void Insert(int index, Object ^obj)
			{
				if (obj == nullptr)
				{
					throw gcnew ArgumentNullException("obj");
				}
				else if (!T::typeid->IsAssignableFrom(obj->GetType()))
				{
					throw gcnew ArgumentException(String::Format("'obj' Must be of type '{0}'", T::typeid->FullName));
				}

				Insert(index, safe_cast<T>(obj));
			}

			virtual void AddIListT(T item) = Generic::IList<T>::Add
			{
				Add(item);
			}

			virtual int FindIndex(T object) = 0;
			virtual bool Add(T data, int newSizeHint) = 0;
			virtual bool Add(T data) = 0;
			virtual int AddMultiple(int numberToAdd) = 0;
			virtual bool AddHead(T object) = 0;
			virtual void Insert(int index, T item) = 0;
			virtual bool DeleteIndex(int index, bool allowShrink) = 0;
			virtual bool DeleteIndex(int index) = 0;
			virtual bool DeleteObject(T object, bool allowShrink) = 0;
			virtual bool DeleteObject(T object) = 0;
			virtual bool DeleteRange(int start, int count, bool allowShrink) = 0;
			virtual bool DeleteRange(int start, int count) = 0;
			virtual void DeleteAll(bool allowShrink) = 0;
			virtual void DeleteAll() = 0;

			property bool IsEmpty
			{
				virtual bool get() = 0;
			}

			property int Count
			{
				virtual int get() = 0;
			}

			property Object ^SyncRoot
			{
				virtual Object ^get()
				{
					return nullptr;
				}
			}

			property bool IsSynchronized
			{
				virtual bool get()
				{
					return false;
				}
			}

			property bool IsReadOnly
			{
				virtual bool get()
				{
					return false;
				}
			}

			property bool IsFixedSize
			{
				virtual bool get()
				{
					return false;
				}
			}

			property Object ^IListItems[int]
			{
				virtual Object ^get(int index) = Collections::IList::default::get
				{
					return this[index];
				}

				virtual void set(int index, Object ^value) = Collections::IList::default::set
				{
					if (value == nullptr)
					{
						throw gcnew ArgumentNullException("value");
					}
					else if (!T::typeid->IsAssignableFrom(value->GetType()))
					{
						throw gcnew ArgumentException(String::Format("'value' Must be of type '{0}'", T::typeid->FullName));
					}

					this[index] = safe_cast<T>(value);
				}
			}

		protected:
			virtual bool Grow(int newSizeHint) = 0;
			virtual bool Shrink() = 0;

			property int ActiveCount
			{
				virtual int get() = 0;
				virtual void set(int value) = 0;
			}
	};

	generic<typename T>
	public interface class IVectorClass : 
		public IUnmanagedObject,
		public Collections::IEnumerable,
		public Generic::IEnumerable<T>
	{
		bool Resize(int newSize);

		void Clear();

		int ID(T object);

		property T default[int]
		{
			T get(int index);
			void set(int index, T value);
		}

		property int Length
		{
			int get();
		}
	};

	generic<typename T>
	public ref class VectorClass abstract : public AbstractUnmanagedObject, public IVectorClass<T>
	{
		private:
			ref class Enumerator sealed : Generic::IEnumerator<T>
			{
				private:
					VectorClass<T> ^vectorClass;
					int index;

				public:
					Enumerator(VectorClass<T> ^vectorClass)
						: vectorClass(vectorClass), index(-1)
					{

					}

					~Enumerator()
					{

					}

					virtual bool MoveNext() = Generic::IEnumerator<T>::MoveNext
					{
						index++;

						if (index >= vectorClass->Length)
						{
							return false;
						}

						return true;
					}

					virtual void Reset() = Generic::IEnumerator<T>::Reset
					{
						index = -1;
					}

					property T Current
					{
						virtual T get() = Generic::IEnumerator<T>::Current::get
						{
							if (index < 0 || index >= vectorClass->Length)
							{
								throw gcnew IndexOutOfRangeException();
							}

							return vectorClass[index];
						}
					}

					property Object ^Current2
					{
						virtual Object ^get() = System::Collections::IEnumerator::Current::get
						{
							return Current;
						}
					}
			};

		protected:
			VectorClass()
				: AbstractUnmanagedObject()
			{

			}

		public:
			VectorClass(IntPtr pointer)
				: AbstractUnmanagedObject(pointer)
			{

			}

			virtual Generic::IEnumerator<T> ^GetEnumerator() = Generic::IEnumerable<T>::GetEnumerator
			{
				return gcnew Enumerator(this);
			}

			virtual Collections::IEnumerator ^GetEnumerator2() = Collections::IEnumerable::GetEnumerator
			{
				return GetEnumerator();
			}

			virtual bool Resize(int newSize) = 0;
			virtual void Clear() = 0;
			virtual int ID(T object) = 0;

			property T default[int]
			{
				virtual T get(int index) = 0;
				virtual void set(int index, T value) = 0;
			}

			property int Length
			{
				virtual int get() = 0;
			}

		protected:
			property IntPtr Vector
			{
				virtual IntPtr get() = 0;
				virtual void set(IntPtr value) = 0;
			}

			property int VectorMax
			{
				virtual int get() = 0;
				virtual void set(int value) = 0;
			}

			property bool IsValid
			{
				virtual bool get() = 0;
				virtual void set(bool value) = 0;
			}

			property bool IsAllocated
			{
				virtual bool get() = 0;
				virtual void set(bool value) = 0;
			}
	};

	generic<typename T>
	public interface class IDynamicVectorClass : 
		public IVectorClass<T>,
		public Collections::IList,
		public Generic::IList<T>
	{
		void ResetActive();

		bool AddHead(T object);

		bool DeleteObj(T object);

		bool Delete(int index);

		void DeleteAll();

		int UninitializedAdd();

		void AddMultiple(int numberToAdd);

		property int Count
		{
			int get();
			void set(int value);
		}

		property int GrowthStep
		{
			int get();
			void set(int value);
		}
	};

	generic<typename T>
	public ref class DynamicVectorClass abstract : public VectorClass<T>, public IDynamicVectorClass<T>
	{
		private:
			ref class Enumerator sealed : Generic::IEnumerator<T>
			{
				private:
					DynamicVectorClass<T> ^dynamicVectorClass;
					int index;

				public:
					Enumerator(DynamicVectorClass<T> ^dynamicVectorClass)
						: dynamicVectorClass(dynamicVectorClass), index(-1)
					{

					}

					~Enumerator()
					{

					}

					virtual bool MoveNext() = Generic::IEnumerator<T>::MoveNext
					{
						index++;

						if (index >= dynamicVectorClass->Count)
						{
							return false;
						}

						return true;
					}

					virtual void Reset() = Generic::IEnumerator<T>::Reset
					{
						index = -1;
					}

					property T Current
					{
						virtual T get() = Generic::IEnumerator<T>::Current::get
						{
							if (index < 0 || index >= dynamicVectorClass->Count)
							{
								throw gcnew IndexOutOfRangeException();
							}

							return dynamicVectorClass[index];
						}
					}

					property Object ^Current2
					{
						virtual Object ^get() = System::Collections::IEnumerator::Current::get
						{
							return Current;
						}
					}
			};
		protected:
			DynamicVectorClass()
				: VectorClass<T>()
			{

			}

		public:
			DynamicVectorClass(IntPtr pointer)
				: VectorClass<T>(pointer)
			{

			}

			Generic::IEnumerator<T> ^GetEnumerator() override
			{
				return gcnew Enumerator(this);
			}

			virtual void CopyTo(array<T> ^array, int index)
			{
				CopyTo(safe_cast<Array ^>(array), index);
			}

			virtual void CopyTo(Array ^array, int index)
			{
				if (array == nullptr)
				{
					throw gcnew ArgumentNullException("array");
				}
				else if (index < 0)
				{
					throw gcnew ArgumentOutOfRangeException("index");
				}

				int count = Count;
				int targetIndex = index;
				for (int x = 0; x < count; x++, targetIndex++)
				{
					if (targetIndex >= array->Length)
					{
						throw gcnew ArgumentException("The number of elements in the source ICollection<T> is greater than the available space from arrayIndex to the end of the destination array");
					}

					T value = this[x];

					array->SetValue(value, targetIndex);
				}
			}

			virtual int Add(Object ^obj)
			{
				if (obj == nullptr)
				{
					throw gcnew ArgumentNullException("obj");
				}
				else if (!T::typeid->IsAssignableFrom(obj->GetType()))
				{
					throw gcnew ArgumentException(String::Format("'obj' Must be of type '{0}'", T::typeid->FullName));
				}

				int index = Count;
				if (Add(safe_cast<T>(obj)))
				{
					return index;
				}
				else
				{
					return -1;
				}
			}

			virtual bool Contains(T item)
			{
				return (ID(item) != -1);
			}

			virtual bool Contains(Object ^obj)
			{
				if (obj == nullptr)
				{
					throw gcnew ArgumentNullException("obj");
				}
				else if (!T::typeid->IsAssignableFrom(obj->GetType()))
				{
					throw gcnew ArgumentException(String::Format("'obj' Must be of type '{0}'", T::typeid->FullName));
				}

				return Contains(safe_cast<T>(obj));
			}

			virtual int IndexOf(T item)
			{
				return ID(item);
			}

			virtual int IndexOf(Object ^obj)
			{
				if (obj == nullptr)
				{
					throw gcnew ArgumentNullException("obj");
				}
				else if (!T::typeid->IsAssignableFrom(obj->GetType()))
				{
					throw gcnew ArgumentException(String::Format("'obj' Must be of type '{0}'", T::typeid->FullName));
				}

				return IndexOf(safe_cast<T>(obj));
			}

			virtual bool Remove(T item)
			{
				return DeleteObj(item);
			}

			virtual void Remove(Object ^obj)
			{
				if (obj == nullptr)
				{
					throw gcnew ArgumentNullException("obj");
				}
				else if (!T::typeid->IsAssignableFrom(obj->GetType()))
				{
					throw gcnew ArgumentException(String::Format("'obj' Must be of type '{0}'", T::typeid->FullName));
				}

				Remove(safe_cast<T>(obj));
			}

			virtual void RemoveAt(int index)
			{
				Delete(index);
			}

			virtual void Insert(int index, Object ^obj)
			{
				if (obj == nullptr)
				{
					throw gcnew ArgumentNullException("obj");
				}
				else if (!T::typeid->IsAssignableFrom(obj->GetType()))
				{
					throw gcnew ArgumentException(String::Format("'obj' Must be of type '{0}'", T::typeid->FullName));
				}

				Insert(index, safe_cast<T>(obj));
			}

			virtual void AddIListT(T item) = Generic::IList<T>::Add
			{
				Add(item);
			}

			virtual void Insert(int index, T object) = 0;
			virtual bool Add(T object) = 0;
			virtual void ResetActive() = 0;
			virtual bool AddHead(T object) = 0;
			virtual bool DeleteObj(T object) = 0;
			virtual bool Delete(int index) = 0;
			virtual void DeleteAll() = 0;
			virtual int UninitializedAdd() = 0;
			virtual void AddMultiple(int numberToAdd) = 0;

			property int Count
			{
				virtual int get() = 0;
				virtual void set(int value) = 0;
			}

			property int GrowthStep
			{
				virtual int get() = 0;
				virtual void set(int value) = 0;
			}

			property Object ^SyncRoot
			{
				virtual Object ^get()
				{
					return nullptr;
				}
			}

			property bool IsSynchronized
			{
				virtual bool get()
				{
					return false;
				}
			}

			property bool IsReadOnly
			{
				virtual bool get()
				{
					return false;
				}
			}

			property bool IsFixedSize
			{
				virtual bool get()
				{
					return false;
				}
			}

			property Object ^IListItems[int]
			{
				virtual Object ^get(int index) = Collections::IList::default::get
				{
					return this[index];
				}

				virtual void set(int index, Object ^value) = Collections::IList::default::set
				{
					if (value == nullptr)
					{
						throw gcnew ArgumentNullException("value");
					}
					else if (!T::typeid->IsAssignableFrom(value->GetType()))
					{
						throw gcnew ArgumentException(String::Format("'value' Must be of type '{0}'", T::typeid->FullName));
					}

					this[index] = safe_cast<T>(value);
				}
			}

		protected:
			property int ActiveCount
			{
				virtual int get() = 0;
				virtual void set(int value) = 0;
			}
	};

#pragma managed(push, off)

	template<class T>
	class VectorClassHelper : public ::VectorClass<T>
	{
		private:
			VectorClassHelper() = default;

		public:
			T *GetVector() 
			{
				return Vector;
			}

			void SetVector(T *value)
			{
				Vector = value;
			}

			int GetVectorMax() const
			{
				return VectorMax;
			}

			void SetVectorMax(int value)
			{
				VectorMax = value;
			}

			bool GetIsValid() const
			{
				return IsValid;
			}

			void SetIsValid(bool value)
			{
				IsValid = value;
			}

			bool GetIsAllocated() const
			{
				return IsAllocated;
			}

			void SetIsAllocated(bool value)
			{
				IsAllocated = value;
			}
	};

	template<class T>
	class SimpleDynVecClassHelper : public ::SimpleDynVecClass<T>
	{
		private:
			SimpleDynVecClassHelper() = default;

		public:
			bool Grow(int newSizeHint)
			{
				return ::SimpleDynVecClass<T>::Grow(newSizeHint);
			}

			bool Shrink()
			{
				return ::SimpleDynVecClass<T>::Shrink();
			}

			T *GetVector() const
			{
				return Vector;
			}

			void SetVector(T *value)
			{
				Vector = value;
			}

			int GetVectorMax() const
			{
				return VectorMax;
			}

			void SetVectorMax(int value)
			{
				VectorMax = value;
			}

			int GetActiveCount() const
			{
				return ActiveCount;
			}

			void SetActiveCount(int value)
			{
				ActiveCount = value;
			}
	};

	template<class T> 
	class DynamicVectorClassHelper : public ::DynamicVectorClass<T>
	{
		private:
			DynamicVectorClassHelper() = default;

		public:
			T *GetVector() const
			{
				return Vector;
			}

			void SetVector(T *value)
			{
				Vector = value;
			}

			int GetVectorMax() const
			{
				return VectorMax;
			}

			void SetVectorMax(int value)
			{
				VectorMax = value;
			}

			bool GetIsValid() const
			{
				return IsValid;
			}

			void SetIsValid(bool value)
			{
				IsValid = value;
			}

			bool GetIsAllocated() const
			{
				return IsAllocated;
			}

			void SetIsAllocated(bool value)
			{
				IsAllocated = value;
			}

			int GetActiveCount() const
			{
				return ActiveCount;
			}

			void SetActiveCount(int value)
			{
				ActiveCount = value;
			}
	};

#pragma managed(pop)

	public interface class IRefCountClass : public IUnmanagedObject
	{
		void DeleteThis();

		void ReleaseRef();

		void AddRef();

		void Release();

		property IntPtr RefCountClassPointer
		{
			IntPtr get();
		}

		property int NumRefs
		{
			int get();
		}
	};

	public ref class RefCountClass : public AbstractUnmanagedObject, public IRefCountClass
	{
		private:
			RefCountClass();

		public:
			RefCountClass(IntPtr pointer);

			static IUnmanagedContainer<IRefCountClass ^> ^CreateRefCountClass();

			bool Equals(Object ^other) override;

			virtual void DeleteThis() sealed;
			virtual void ReleaseRef() sealed;
			virtual void AddRef() sealed;
			virtual void Release() sealed;

			property IntPtr RefCountClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int NumRefs
			{
				virtual int get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::RefCountClass *InternalRefCountClassPointer
			{
				virtual ::RefCountClass *get();
			}
	};

	generic<typename T>
	public interface class IObjectPoolClass : public IUnmanagedObject
	{
		T AllocateObjectMemory();

		void FreeObjectMemory(T object);

		void writeDummyPattern();
	};

	generic<typename T>
	public ref class ObjectPoolClass abstract : public AbstractUnmanagedObject, public IObjectPoolClass<T>
	{
		public:
			ObjectPoolClass(IntPtr pointer)
				: AbstractUnmanagedObject(pointer)
			{

			}

			virtual T AllocateObjectMemory() = 0;
			virtual void FreeObjectMemory(T object) = 0;
			virtual void writeDummyPattern() = 0;
	};

	generic<typename T>
	public interface class IAutoPoolClass : public IUnmanagedObject
	{

	};

	generic<typename T>
	public ref class AutoPoolClass abstract : public AbstractUnmanagedObject, public IAutoPoolClass<T>
	{
		public:
			AutoPoolClass(IntPtr pointer)
				: AbstractUnmanagedObject(pointer)
			{

			}
	};
}