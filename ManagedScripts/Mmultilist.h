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

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <multilist.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System;
using namespace System::Collections;

namespace RenSharp
{
	interface class IGenericMultiListClass;
	interface class IMultiListNodeClass;

	public interface class IMultiListObjectClass : public IUnmanagedObject
	{
		property IntPtr MultiListObjectClassPointer
		{
			IntPtr get();
		}

		property IMultiListNodeClass ^ListNode
		{
			IMultiListNodeClass ^get();
			void set(IMultiListNodeClass ^value);
		}
	};

	public ref class MultiListObjectClass : public AbstractUnmanagedObject, public IMultiListObjectClass
	{
		private:
			MultiListObjectClass();

		public:
			MultiListObjectClass(IntPtr pointer);

			static IUnmanagedContainer<IMultiListObjectClass ^> ^CreateMultiListObjectClass();

			bool Equals(Object ^other) override;

			property IntPtr MultiListObjectClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IMultiListNodeClass ^ListNode
			{
				virtual IMultiListNodeClass ^get() sealed;
				virtual void set(IMultiListNodeClass ^value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::MultiListObjectClass *InternalMultiListObjectClassPointer
			{
				virtual ::MultiListObjectClass *get();
			}
	};

	public interface class IMultiListNodeClass : public IAutoPoolClass<IMultiListNodeClass ^>
	{
		property IntPtr AutoPoolClassPointer
		{
			IntPtr get();
		}

		property IntPtr MultiListNodeClassPointer
		{
			IntPtr get();
		}

		property IMultiListNodeClass ^Prev
		{
			IMultiListNodeClass ^get();
			void set(IMultiListNodeClass ^value);
		}

		property IMultiListNodeClass ^Next
		{
			IMultiListNodeClass ^get();
			void set(IMultiListNodeClass ^value);
		}

		property IMultiListNodeClass ^NextList
		{
			IMultiListNodeClass ^get();
			void set(IMultiListNodeClass ^value);
		}

		property IMultiListObjectClass ^Object
		{
			IMultiListObjectClass ^get();
			void set(IMultiListObjectClass ^value);
		}

		property IGenericMultiListClass ^List
		{
			IGenericMultiListClass ^get();
			void set(IGenericMultiListClass ^value);
		}
	};

	public ref class MultiListNodeClass : public AutoPoolClass<IMultiListNodeClass ^>, public IMultiListNodeClass
	{
		private:
			MultiListNodeClass();

		public:
			MultiListNodeClass(IntPtr pointer);

			static IUnmanagedContainer<IMultiListNodeClass ^> ^CreateMultiListNodeClass();

			bool Equals(Object ^other) override;

			property IntPtr AutoPoolClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr MultiListNodeClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IMultiListNodeClass ^Prev
			{
				virtual IMultiListNodeClass ^get() sealed;
				virtual void set(IMultiListNodeClass ^value) sealed;
			}

			property IMultiListNodeClass ^Next
			{
				virtual IMultiListNodeClass ^get() sealed;
				virtual void set(IMultiListNodeClass ^value) sealed;
			}

			property IMultiListNodeClass ^NextList
			{
				virtual IMultiListNodeClass ^get() sealed;
				virtual void set(IMultiListNodeClass ^value) sealed;
			}

			property IMultiListObjectClass ^Object
			{
				virtual IMultiListObjectClass ^get() sealed;
				virtual void set(IMultiListObjectClass ^value) sealed;
			}

			property IGenericMultiListClass ^List
			{
				virtual IGenericMultiListClass ^get() sealed;
				virtual void set(IGenericMultiListClass ^value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::AutoPoolClass<::MultiListNodeClass, 256> *InternalAutoPoolClassPointer
			{
				virtual ::AutoPoolClass<::MultiListNodeClass, 256> *get();
			}

			property ::MultiListNodeClass *InternalMultiListNodeClassPointer
			{
				virtual ::MultiListNodeClass *get();
			}
	};

	public interface class IGenericMultiListClass : public IUnmanagedObject
	{
		bool IsInList(IMultiListObjectClass ^obj);

		bool GenericContains(IMultiListObjectClass ^obj);

		property IntPtr GenericMultiListClassPointer
		{
			IntPtr get();
		}

		property bool IsEmpty
		{
			bool get();
		}

		property int Count
		{
			int get();
		}
	};

	public ref class GenericMultiListClass : public AbstractUnmanagedObject, public IGenericMultiListClass
	{
		private:
			GenericMultiListClass();

		public:
			GenericMultiListClass(IntPtr pointer);

			static IUnmanagedContainer<IGenericMultiListClass ^> ^CreateGenericMultiListClass();

			bool Equals(Object ^other) override;

			virtual bool IsInList(IMultiListObjectClass ^obj) sealed;
			virtual bool GenericContains(IMultiListObjectClass ^obj) sealed;

			property IntPtr GenericMultiListClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsEmpty
			{
				virtual bool get() sealed;
			}

			property int Count
			{
				virtual int get();
			}

		protected:
			bool InternalDestroyPointer() override;

			bool InternalAdd(IMultiListObjectClass ^obj, bool onlyOnce);
			bool InternalAdd(IMultiListObjectClass ^obj);
			bool InternalAddTail(IMultiListObjectClass ^obj, bool onlyOnce);
			bool InternalAddTail(IMultiListObjectClass ^obj);
			bool InternalAddAfter(IMultiListObjectClass ^obj, IMultiListObjectClass ^existingListMember, bool onlyOnce);
			bool InternalAddAfter(IMultiListObjectClass ^obj, IMultiListObjectClass ^existingListMember);
			bool InternalRemove(IMultiListObjectClass ^obj);
			IMultiListObjectClass ^InternalRemoveListHead();

			property ::GenericMultiListClass *InternalGenericMultiListClassPointer
			{
				virtual ::GenericMultiListClass *get();
			}

			property IMultiListObjectClass ^ListHead
			{
				IMultiListObjectClass ^get();
			}
	};

	public interface class IGenericMultiListIterator : public IUnmanagedObject
	{
		void First(IGenericMultiListClass ^list);

		void First();

		void Next();

		void Prev();

		property IntPtr GenericMultiListIteratorPointer
		{
			IntPtr get();
		}

		property bool IsDone
		{
			bool get();
		}
	};

	public ref class GenericMultiListIterator : public AbstractUnmanagedObject, public IGenericMultiListIterator
	{
		private:
			GenericMultiListIterator(IGenericMultiListClass ^list);

		protected:
			GenericMultiListIterator()
			{

			}

		public:
			GenericMultiListIterator(IntPtr pointer);

			static IUnmanagedContainer<IGenericMultiListIterator ^> ^CreateGenericMultiListIterator(IGenericMultiListClass ^list);

			bool Equals(Object ^other) override;

			virtual void First(IGenericMultiListClass ^list) sealed;
			virtual void First() sealed;
			virtual void Next() sealed;
			virtual void Prev() sealed;

			property IntPtr GenericMultiListIteratorPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsDone
			{
				virtual bool get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::GenericMultiListIterator *InternalGenericMultiListIteratorPointer
			{
				virtual ::GenericMultiListIterator *get();
			}

			property IMultiListObjectClass ^CurrentObject
			{
				IMultiListObjectClass ^get();
			}

			property IGenericMultiListClass ^List
			{
				IGenericMultiListClass ^get();
			}

			property IMultiListNodeClass ^CurNode
			{
				IMultiListNodeClass ^get();
			}
	};

	generic<typename T>
	interface class IRefMultiListIterator;

	generic<typename T>
	public interface class IRefMultiListClass :
		public IGenericMultiListClass,
		public Generic::ICollection<T>,
		public Collections::ICollection,
		public Generic::IEnumerable<T>,
		public Collections::IEnumerable
	{
		bool Add(T obj, bool onlyOnce);

		bool AddTail(T obj, bool onlyOnce);

		bool AddTail(T obj);

		bool AddAfter(T obj, T existingListMember, bool onlyOnce);

		bool AddAfter(T obj, T existingListMember);

		bool ReleaseHead();

		T GetHead();

		T PeekHead();

		T RemoveHead();

		void ResetList();

		property IUnmanagedContainer<IRefMultiListIterator<T> ^> ^Iterator
		{
			IUnmanagedContainer<IRefMultiListIterator<T> ^> ^get();
		}
	};

	generic<typename T>
	public interface class IRefMultiListIterator : public IGenericMultiListIterator
	{
		T GetObj();

		T PeekObj();

		void RemoveCurrentObject();
	};

	generic<typename T>
	public ref class RefMultiListIterator abstract : public GenericMultiListIterator, public IRefMultiListIterator<T>
	{
		protected:
			RefMultiListIterator()
			{

			}

		public:
			RefMultiListIterator(IntPtr pointer)
				: GenericMultiListIterator(pointer)
			{

			}

			virtual T GetObj() = 0;
			virtual T PeekObj() = 0;
			virtual void RemoveCurrentObject() = 0;
	};

	generic<typename T>
	public ref class RefMultiListClass abstract : public GenericMultiListClass, public IRefMultiListClass<T>
	{
		private:
			ref class Enumerator sealed : Generic::IEnumerator<T>
			{
				private:
					IUnmanagedContainer<IRefMultiListIterator<T> ^> ^iterator;
					bool reset;

				public:
					Enumerator(IUnmanagedContainer<IRefMultiListIterator<T> ^> ^iterator)
						: iterator(iterator), reset(true)
					{
						if (iterator == nullptr)
						{
							throw gcnew ArgumentNullException("iterator");
						}
					}

					~Enumerator()
					{
#pragma push_macro("delete")
#undef delete

						delete iterator;
						iterator = nullptr;

#pragma pop_macro("delete")
					}

					virtual bool MoveNext() = Generic::IEnumerator<T>::MoveNext
					{
						if (reset)
						{
							iterator->UnmanagedObject->First();

							reset = false;

							return (iterator->UnmanagedObject->PeekObj() != nullptr);
						}

						if (iterator->UnmanagedObject->IsDone)
						{
							return false;
						}

						iterator->UnmanagedObject->Next();

						return (iterator->UnmanagedObject->PeekObj() != nullptr);
					}

					virtual void Reset() = Generic::IEnumerator<T>::Reset
					{
						iterator->UnmanagedObject->First();
						reset = true;
					}

					property T Current
					{
						virtual T get() = Generic::IEnumerator<T>::Current::get
						{
							return iterator->UnmanagedObject->PeekObj();
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
			RefMultiListClass(IntPtr pointer)
				: GenericMultiListClass(pointer)
			{

			}

			virtual Generic::IEnumerator<T> ^GetEnumerator() = Generic::IEnumerable<T>::GetEnumerator
			{
				return gcnew Enumerator(Iterator);
			}

			virtual Collections::IEnumerator ^GetEnumerator2() = Collections::IEnumerable::GetEnumerator
			{
				return GetEnumerator();
			}

			virtual void Clear()
			{
				ResetList();
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
				for each(T item in this)
				{
					if (index >= array->Length)
					{
						throw gcnew ArgumentException("The number of elements in the source ICollection<T> is greater than the available space from arrayIndex to the end of the destination array");
					}

					if (!T::typeid->IsAssignableFrom(array->GetType()->GetElementType()))
					{
						throw gcnew System::ArgumentException("The type of the source ICollection cannot be cast automatically to the type of the destination array");
					}

					array->SetValue(item, index++);
				}
			}

			virtual void CopyTo(array<T> ^array, int arrayIndex)
			{
				CopyTo(safe_cast<Array ^>(array), arrayIndex);
			}

			virtual void Add(T obj)
			{
				Add(obj, false);
			}

			virtual bool Contains(T obj) = 0;
			virtual bool Add(T obj, bool onlyOnce) = 0;
			virtual bool AddTail(T obj, bool onlyOnce) = 0;
			virtual bool AddTail(T obj) = 0;
			virtual bool AddAfter(T obj, T existingListMember, bool onlyOnce) = 0;
			virtual bool AddAfter(T obj, T existingListMember) = 0;
			virtual bool ReleaseHead() = 0;
			virtual T GetHead() = 0;
			virtual T PeekHead() = 0;
			virtual T RemoveHead() = 0;
			virtual void ResetList() = 0;
			virtual bool Remove(T item) = 0;

			property IUnmanagedContainer<IRefMultiListIterator<T> ^> ^Iterator
			{
				virtual IUnmanagedContainer<IRefMultiListIterator<T> ^> ^get() = 0;
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
	};

	generic<typename T>
	public interface class IMultiListIterator : public IGenericMultiListIterator
	{
		T GetObj();

		T PeekObj();

		void RemoveCurrentObject();
	};

	generic<typename T>
	public ref class MultiListIterator abstract : public GenericMultiListIterator, public IMultiListIterator<T>
	{
		protected:
			MultiListIterator()
			{

			}

		public:
			MultiListIterator(IntPtr pointer)
				: GenericMultiListIterator(pointer)
			{

			}

			virtual T GetObj() = 0;
			virtual T PeekObj() = 0;
			virtual void RemoveCurrentObject() = 0;
	};

	generic<typename T>
	public interface class IMultiListClass :
		public IGenericMultiListClass,
		public Generic::ICollection<T>,
		public Collections::ICollection,
		public Generic::IEnumerable<T>,
		public Collections::IEnumerable
	{
		bool Add(T obj, bool onlyOnce);

		bool AddTail(T obj, bool onlyOnce);

		bool AddTail(T obj);

		bool AddAfter(T obj, T existingListMember, bool onlyOnce);

		bool AddAfter(T obj, T existingListMember);

		T GetHead();

		T PeekHead();

		T RemoveHead();

		void ResetList();

		property IUnmanagedContainer<IMultiListIterator<T> ^> ^Iterator
		{
			IUnmanagedContainer<IMultiListIterator<T> ^> ^get();
		}
	};

	generic<typename T>
	public ref class MultiListClass abstract : public GenericMultiListClass, public IMultiListClass<T>
	{
		private:
			ref class Enumerator sealed : Generic::IEnumerator<T>
			{
				private:
					IUnmanagedContainer<IMultiListIterator<T> ^> ^iterator;
					bool reset;

				public:
					Enumerator(IUnmanagedContainer<IMultiListIterator<T> ^> ^iterator)
						: iterator(iterator), reset(true)
					{
						if (iterator == nullptr)
						{
							throw gcnew ArgumentNullException("iterator");
						}
					}

					~Enumerator()
					{
#pragma push_macro("delete")
#undef delete

						delete iterator;
						iterator = nullptr;

#pragma pop_macro("delete")
					}

					virtual bool MoveNext() = Generic::IEnumerator<T>::MoveNext
					{
						if (reset)
						{
							iterator->UnmanagedObject->First();

							reset = false;

							return (iterator->UnmanagedObject->PeekObj() != nullptr);
						}

						if (iterator->UnmanagedObject->IsDone)
						{
							return false;
						}

						iterator->UnmanagedObject->Next();

						return (iterator->UnmanagedObject->PeekObj() != nullptr);
					}

					virtual void Reset() = Generic::IEnumerator<T>::Reset
					{
						iterator->UnmanagedObject->First();
						reset = true;
					}

					property T Current
					{
						virtual T get() = Generic::IEnumerator<T>::Current::get
						{
							return iterator->UnmanagedObject->PeekObj();
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
			MultiListClass(IntPtr pointer)
				: GenericMultiListClass(pointer)
			{

			}

			virtual Generic::IEnumerator<T> ^GetEnumerator() = Generic::IEnumerable<T>::GetEnumerator
			{
				return gcnew Enumerator(Iterator);
			}

			virtual Collections::IEnumerator ^GetEnumerator2() = Collections::IEnumerable::GetEnumerator
			{
				return GetEnumerator();
			}

			virtual void Clear()
			{
				ResetList();
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
				for each(T item in this)
				{
					if (index >= array->Length)
					{
						throw gcnew ArgumentException("The number of elements in the source ICollection<T> is greater than the available space from arrayIndex to the end of the destination array");
					}

					if (!T::typeid->IsAssignableFrom(array->GetType()->GetElementType()))
					{
						throw gcnew System::ArgumentException("The type of the source ICollection cannot be cast automatically to the type of the destination array");
					}

					array->SetValue(item, index++);
				}
			}

			virtual void CopyTo(array<T> ^array, int arrayIndex)
			{
				CopyTo(safe_cast<Array ^>(array), arrayIndex);
			}

			virtual void Add(T obj)
			{
				Add(obj, false);
			}

			virtual bool Contains(T obj) = 0;
			virtual bool Add(T obj, bool onlyOnce) = 0;
			virtual bool AddTail(T obj, bool onlyOnce) = 0;
			virtual bool AddTail(T obj) = 0;
			virtual bool AddAfter(T obj, T existingListMember, bool onlyOnce) = 0;
			virtual bool AddAfter(T obj, T existingListMember) = 0;;
			virtual T GetHead() = 0;
			virtual T PeekHead() = 0;
			virtual T RemoveHead() = 0;
			virtual void ResetList() = 0;
			virtual bool Remove(T item) = 0;

			property IUnmanagedContainer<IMultiListIterator<T> ^> ^Iterator
			{
				virtual IUnmanagedContainer<IMultiListIterator<T> ^> ^get() = 0;
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
	};

#pragma managed(push, off)

	template<class ObjectType>
	class PriorityMultiListIteratorHelper : public ::PriorityMultiListIterator<ObjectType>
	{
		private:
			PriorityMultiListIteratorHelper(::MultiListClass<ObjectType> *list)
				: ::PriorityMultiListIterator<ObjectType>(list)
			{

			}

		public:
			::MultiListNodeClass *GetOriginalHead()
			{
				return OriginalHead;
			}
	};

#pragma managed(pop)

	generic<typename T>
	public interface class IPriorityMultiListIterator : public IMultiListIterator<T>
	{
		bool ProcessHead(T %object);
	};

	generic<typename T>
	public ref class PriorityMultiListIterator abstract : public MultiListIterator<T>, public IPriorityMultiListIterator<T>
	{
		public:
			PriorityMultiListIterator(IntPtr pointer)
				: MultiListIterator<T>(pointer)
			{

			}

			virtual bool ProcessHead(T %object) = 0;
	};
}