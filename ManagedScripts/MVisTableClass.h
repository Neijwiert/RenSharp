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
#include "Mmultilist.h"

#pragma managed(push, off)

class VisTableClass;
class CompressedVisTableClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IVisTableClass : public IRefCountClass, public IMultiListObjectClass
	{
		property IntPtr VisTableClassPointer
		{
			IntPtr get();
		}

		property IntPtr Bytes
		{
			IntPtr get();
		}

		property IntPtr Longs
		{
			IntPtr get();
		}

		property int BitCount
		{
			int get();
		}

		property int VisSectorID
		{
			int get();
			void set(int value);
		}

		property int TimeStamp
		{
			int get();
			void set(int value);
		}
	};

	public ref class VisTableClass : public RefCountClass, public IVisTableClass
	{
		private:
			IMultiListObjectClass^ multiListObjectClass;

		public:
			VisTableClass(IntPtr pointer);

			bool Equals(Object^ other) override;

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr VisTableClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr MultiListObjectClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IMultiListNodeClass^ ListNode
			{
				virtual IMultiListNodeClass^ get() sealed;
				virtual void set(IMultiListNodeClass^ value) sealed;
			}

			property IntPtr Bytes
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr Longs
			{
				virtual IntPtr get() sealed;
			}

			property int BitCount
			{
				virtual int get() sealed;
			}

			property int VisSectorID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int TimeStamp
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			property ::RefCountClass* InternalRefCountClassPointer
			{
				::RefCountClass* get() override;
			}

			property ::MultiListObjectClass* InternalMultiListObjectClassPointer
			{
				virtual ::MultiListObjectClass* get();
			}

			property ::VisTableClass* InternalVisTableClassPointer
			{
				virtual ::VisTableClass* get();
			}
	};

	public interface class ICompressedVisTableClass : public IUnmanagedObject
	{
		property IntPtr CompressedVisTableClassPointer
		{
			IntPtr get();
		}

		property IntPtr Bytes
		{
			IntPtr get();
		}

		property int ByteCount
		{
			int get();
		}
	};

	public ref class CompressedVisTableClass : public AbstractUnmanagedObject, public ICompressedVisTableClass
	{
		private:
			CompressedVisTableClass();

		public:
			CompressedVisTableClass(IntPtr pointer);

			static IUnmanagedContainer<ICompressedVisTableClass^>^ CreateCompressedVisTableClass();

			bool Equals(Object^ other) override;

			property IntPtr CompressedVisTableClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr Bytes
			{
				virtual IntPtr get() sealed;
			}

			property int ByteCount
			{
				virtual int get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::CompressedVisTableClass* InternalCompressedVisTableClassPointer
			{
				virtual ::CompressedVisTableClass* get();
			}
	};
}