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

#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"

#pragma managed(push, off)

struct Gap_ListNode;
class ConsoleFunctionClass;

#pragma managed(pop)

namespace RenSharp
{
	ref class GapListNode;
	interface class IRenSharpConsoleFunctionClass;

	public interface class IGapListNode : public IUnmanagedObject
	{
		property IntPtr GapListNodePointer
		{
			IntPtr get();
		}

		property IGapListNode ^Next
		{
			IGapListNode ^get();
			void set(IGapListNode ^value);
		}

		property unsigned long UnitID
		{
			unsigned long get();
			void set(unsigned long value);
		}

		property float Range
		{
			float get();
			void set(float value);
		}

		property int TeamID
		{
			int get();
			void set(int value);
		}

		property bool Active
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class GapListNodeRef : public AbstractUnmanagedObject, public IGapListNode
	{
		private:
			GapListNodeRef();
			GapListNodeRef(GapListNode ^node);

		public:
			GapListNodeRef(IntPtr pointer);

			bool Equals(Object ^other) override;

			static IUnmanagedContainer<IGapListNode ^> ^CreateGapListNodeRef();
			static IUnmanagedContainer<IGapListNode ^> ^CreateGapListNodeRef(GapListNode ^node);

			property IntPtr GapListNodePointer
			{
				virtual IntPtr get();
			}

			property IGapListNode ^Next
			{
				virtual IGapListNode ^get();
				virtual void set(IGapListNode ^value);
			}

			property unsigned long UnitID
			{
				virtual unsigned long get();
				virtual void set(unsigned long value);
			}

			property float Range
			{
				virtual float get();
				virtual void set(float value);
			}

			property int TeamID
			{
				virtual int get();
				virtual void set(int value);
			}

			property bool Active
			{
				virtual bool get();
				virtual void set(bool value);
			}

		protected:
			property ::Gap_ListNode *InternalGapListNodePointer
			{
				virtual ::Gap_ListNode *get();
			}

		private:
			static ::Gap_ListNode *ConstructGapListNode(GapListNode ^currentManagedNode);
	};

	public ref class GapListNode
	{
		private:
			GapListNode ^next;
			unsigned long unitID;
			float range;
			int teamID;
			bool active;

		public:
			GapListNode();

			property GapListNode ^Next
			{
				virtual GapListNode ^get();
				virtual void set(GapListNode ^value);
			}

			property unsigned long UnitID
			{
				virtual unsigned long get();
				virtual void set(unsigned long value);
			}

			property float Range
			{
				virtual float get();
				virtual void set(float value);
			}

			property int TeamID
			{
				virtual int get();
				virtual void set(int value);
			}

			property bool Active
			{
				virtual bool get();
				virtual void set(bool value);
			}
	};

	public interface class IConsoleFunctionClass : public IUnmanagedObject
	{
		void Activate(String ^pArgs);

		IRenSharpConsoleFunctionClass^ AsManagedConsoleFunction();

		property IntPtr ConsoleFunctionClassPointer
		{
			IntPtr get();
		}

		property String ^Name
		{
			String ^get();
		}

		property String ^Alias
		{
			String ^get();
		}

		property String ^Help
		{
			String ^get();
		}

		property bool IsManagedConsoleFunction
		{
			bool get();
		}
	};

	public ref class ConsoleFunctionClass : public AbstractUnmanagedObject, public IConsoleFunctionClass
	{
		public:
			ConsoleFunctionClass(IntPtr pointer);

			String ^ToString() override;
			bool Equals(Object ^other) override;

			virtual void Activate(String ^pArgs) sealed;
			virtual IRenSharpConsoleFunctionClass^ AsManagedConsoleFunction() sealed;

			property IntPtr ConsoleFunctionClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String ^Name
			{
				virtual String ^get() sealed;
			}

			property String ^Alias
			{
				virtual String ^get() sealed;
			}

			property String ^Help
			{
				virtual String ^get() sealed;
			}

			property bool IsManagedConsoleFunction
			{
				virtual bool get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::ConsoleFunctionClass *InternalConsoleFunctionClassPointer
			{
				virtual ::ConsoleFunctionClass *get();
			}
	};
}