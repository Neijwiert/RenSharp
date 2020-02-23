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
#include "Mengine_vector.h"
#include "Mmultilist.h"

#pragma managed(push, off)

class VisDecompressionCacheClass;
class VisTableMgrClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IVisTableClass;
	interface class ICompressedVisTableClass;

	public interface class IVisDecompressionCacheClass : public IUnmanagedObject
	{
		property IntPtr VisDecompressionCacheClassPointer
		{
			IntPtr get();
		}

		property ISimpleVecClass<IVisTableClass^>^ Cache
		{
			ISimpleVecClass<IVisTableClass^>^ get();
			void set(ISimpleVecClass<IVisTableClass^>^ value);
		}

		property IMultiListClass<IVisTableClass^>^ TableList
		{
			IMultiListClass<IVisTableClass^>^ get();
		}

		property int TimeStamp
		{
			int get();
			void set(int value);
		}
	};

	public ref class VisDecompressionCacheClass : public AbstractUnmanagedObject, public IVisDecompressionCacheClass
	{
		private:
			VisDecompressionCacheClass();

		public:
			VisDecompressionCacheClass(IntPtr pointer);

			static IUnmanagedContainer<IVisDecompressionCacheClass^>^ CreateVisDecompressionCacheClass();

			bool Equals(Object^ other) override;

			property IntPtr VisDecompressionCacheClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property ISimpleVecClass<IVisTableClass^>^ Cache
			{
				virtual ISimpleVecClass<IVisTableClass^>^ get() sealed;
				virtual void set(ISimpleVecClass<IVisTableClass^>^ value) sealed;
			}

			property IMultiListClass<IVisTableClass^>^ TableList
			{
				virtual IMultiListClass<IVisTableClass^>^ get() sealed;
			}

			property int TimeStamp
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::VisDecompressionCacheClass* InternalVisDecompressionCacheClassPointer
			{
				virtual ::VisDecompressionCacheClass* get();
			}
	};

	public interface class IVisTableMgrClass : public IUnmanagedObject
	{
		bool HasVisTable(int table);

		property IntPtr VisTableMgrClassPointer
		{
			IntPtr get();
		}

		property int Count
		{
			int get();
			void set(int value);
		}

		property int Size
		{
			int get();
			void set(int value);
		}

		property ISimpleDynVecClass<ICompressedVisTableClass^>^ Tables
		{
			ISimpleDynVecClass<ICompressedVisTableClass^>^ get();
			void set(ISimpleDynVecClass<ICompressedVisTableClass^>^ value);
		}

		property IVisDecompressionCacheClass^ Cache
		{
			IVisDecompressionCacheClass^ get();
			void set(IVisDecompressionCacheClass^ value);
		}

		property int Frames
		{
			int get();
			void set(int value);
		}
	};

	public ref class VisTableMgrClass : public AbstractUnmanagedObject, public IVisTableMgrClass
	{
		public:
			VisTableMgrClass(IntPtr pointer);

			bool Equals(Object^ other) override;

			virtual bool HasVisTable(int table) sealed;

			property IntPtr VisTableMgrClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int Count
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int Size
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property ISimpleDynVecClass<ICompressedVisTableClass^>^ Tables
			{
				virtual ISimpleDynVecClass<ICompressedVisTableClass^>^ get() sealed;
				virtual void set(ISimpleDynVecClass<ICompressedVisTableClass^>^ value) sealed;
			}

			property IVisDecompressionCacheClass^ Cache
			{
				virtual IVisDecompressionCacheClass^ get() sealed;
				virtual void set(IVisDecompressionCacheClass^ value) sealed;
			}

			property int Frames
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			property ::VisTableMgrClass* InternalVisTableMgrClassPointer
			{
				virtual ::VisTableMgrClass* get();
			}
	};
}