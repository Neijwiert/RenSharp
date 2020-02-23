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

#include "stdafx.h"
#include "Mengine_tt.h"

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "MEngine.h"
#include "RenSharpConsoleFunctionClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <engine_tt.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Text;

namespace RenSharp
{
	ref class GapListNodeUnmanagedContainer : public IUnmanagedContainer<IGapListNode ^>
	{
		private:
			bool disposedResources;
			IGapListNode ^unmanagedObject;

		public:
			GapListNodeUnmanagedContainer(IGapListNode ^unmanagedObject)
				: disposedResources(false), unmanagedObject(unmanagedObject)
			{
				if (unmanagedObject == nullptr || unmanagedObject->GapListNodePointer.ToPointer() == nullptr)
				{
					throw gcnew ArgumentNullException("unmanagedObject");
				}
			}

			~GapListNodeUnmanagedContainer()
			{
				this->!GapListNodeUnmanagedContainer();
			}

			bool Equals(Object ^other) override
			{
				if (other == nullptr)
				{
					return false;
				}
				else if (other == this)
				{
					return true;
				}

				IUnmanagedContainer<IGapListNode ^> ^otherContainer = dynamic_cast<IUnmanagedContainer<IGapListNode ^> ^>(other);
				if (otherContainer == nullptr)
				{
					return false;
				}

				if (unmanagedObject == nullptr)
				{
					return (otherContainer->UnmanagedObject == nullptr);
				}

				return unmanagedObject->Equals(otherContainer->UnmanagedObject);
			}

			int GetHashCode() override
			{
				if (UnmanagedObject == nullptr)
				{
					IntPtr zero = IntPtr::Zero;

					return zero.GetHashCode();
				}
				else
				{
					return unmanagedObject->GetHashCode();
				}
			}

			virtual void ReleaseObject() sealed
			{
				unmanagedObject = nullptr;
			}

			property IGapListNode ^UnmanagedObject
			{
				virtual IGapListNode ^get() sealed
				{
					return unmanagedObject;
				}

				protected:
					virtual void set(IGapListNode ^value) sealed
					{
						unmanagedObject = value;
					}
			}

		protected:
			!GapListNodeUnmanagedContainer()
			{
				if (!disposedResources)
				{
					IGapListNode ^current = unmanagedObject;
					while (current != nullptr && current->GapListNodePointer.ToPointer() != nullptr)
					{
						IGapListNode ^next = current->Next;

						current->DestroyPointer();

						current = next;
					}

					unmanagedObject = nullptr;

					disposedResources = true;
				}
			}
	};

	GapListNodeRef::GapListNodeRef()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateGap_ListNode()))
	{

	}

	GapListNodeRef::GapListNodeRef(GapListNode ^node)
	{
		if (node == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		Pointer = IntPtr(ConstructGapListNode(node));
	}

	GapListNodeRef::GapListNodeRef(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{
		
	}

	bool GapListNodeRef::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IGapListNode ^otherThis = dynamic_cast<IGapListNode ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return GapListNodePointer.Equals(otherThis->GapListNodePointer);
	}

	IUnmanagedContainer<IGapListNode ^> ^GapListNodeRef::CreateGapListNodeRef()
	{
		return gcnew UnmanagedContainer<IGapListNode ^>(gcnew GapListNodeRef());
	}

	IUnmanagedContainer<IGapListNode ^> ^GapListNodeRef::CreateGapListNodeRef(GapListNode ^node)
	{
		return gcnew GapListNodeUnmanagedContainer(gcnew GapListNodeRef(node));
	}

	IntPtr GapListNodeRef::GapListNodePointer::get()
	{
		return IntPtr(InternalGapListNodePointer);
	}

	IGapListNode ^GapListNodeRef::Next::get()
	{
		auto result = InternalGapListNodePointer->Next;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew GapListNodeRef(IntPtr(result));
		}
	}

	void GapListNodeRef::Next::set(IGapListNode ^value)
	{
		if (value == nullptr || value->GapListNodePointer.ToPointer() == nullptr)
		{
			InternalGapListNodePointer->Next = nullptr;
		}
		else
		{
			InternalGapListNodePointer->Next = reinterpret_cast<::Gap_ListNode *>(value->GapListNodePointer.ToPointer());
		}
	}

	unsigned long GapListNodeRef::UnitID::get()
	{
		return InternalGapListNodePointer->unitID;
	}

	void GapListNodeRef::UnitID::set(unsigned long value)
	{
		InternalGapListNodePointer->unitID = value;
	}

	float GapListNodeRef::Range::get()
	{
		return InternalGapListNodePointer->range;
	}

	void GapListNodeRef::Range::set(float value)
	{
		InternalGapListNodePointer->range = value;
	}

	int GapListNodeRef::TeamID::get()
	{
		return InternalGapListNodePointer->teamID;
	}

	void GapListNodeRef::TeamID::set(int value)
	{
		InternalGapListNodePointer->teamID = value;
	}

	bool GapListNodeRef::Active::get()
	{
		return InternalGapListNodePointer->active;
	}

	void GapListNodeRef::Active::set(bool value)
	{
		InternalGapListNodePointer->active = value;
	}

	::Gap_ListNode *GapListNodeRef::InternalGapListNodePointer::get()
	{
		return reinterpret_cast<::Gap_ListNode *>(Pointer.ToPointer());
	}

	::Gap_ListNode *GapListNodeRef::ConstructGapListNode(GapListNode ^currentManagedNode)
	{
		if (currentManagedNode == nullptr)
		{
			return nullptr;
		}

		::Gap_ListNode *currentUnmanagedNode = Imports::CreateGap_ListNode();
		try
		{
			currentUnmanagedNode->Next = ConstructGapListNode(currentManagedNode->Next);
			currentUnmanagedNode->unitID = currentManagedNode->UnitID;
			currentUnmanagedNode->range = currentManagedNode->Range;
			currentUnmanagedNode->teamID = currentManagedNode->TeamID;
			currentUnmanagedNode->active = currentManagedNode->Active;

			return currentUnmanagedNode;
		}
		catch (Exception ^)
		{
			Imports::DestroyGap_ListNode(currentUnmanagedNode);
			currentUnmanagedNode = nullptr;
			
			throw;
		}
	}

	GapListNode::GapListNode()
		: next(nullptr), unitID(0), range(0), teamID(0), active(false)
	{

	}

	GapListNode ^GapListNode::Next::get()
	{
		return next;
	}

	void GapListNode::Next::set(GapListNode ^value)
	{
		next = value;
	}

	unsigned long GapListNode::UnitID::get()
	{
		return unitID;
	}

	void GapListNode::UnitID::set(unsigned long value)
	{
		unitID = value;
	}

	float GapListNode::Range::get()
	{
		return range;
	}

	void GapListNode::Range::set(float value)
	{
		range = value;
	}

	int GapListNode::TeamID::get()
	{
		return teamID;
	}

	void GapListNode::TeamID::set(int value)
	{
		teamID = value;
	}

	bool GapListNode::Active::get()
	{
		return active;
	}

	void GapListNode::Active::set(bool value)
	{
		active = value;
	}

	ConsoleFunctionClass::ConsoleFunctionClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String ^ConsoleFunctionClass::ToString()
	{
		StringBuilder ^builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	bool ConsoleFunctionClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IRenSharpConsoleFunctionClass^ otherThis1 = dynamic_cast<IRenSharpConsoleFunctionClass^>(other);
		if (otherThis1 != nullptr && ConsoleFunctionClassPointer.Equals(otherThis1->ConsoleFunctionClassPointer))
		{
			return true;
		}

		IConsoleFunctionClass ^otherThis2 = dynamic_cast<IConsoleFunctionClass ^>(other);
		if (otherThis2 == nullptr)
		{
			return nullptr;
		}

		return ConsoleFunctionClassPointer.Equals(otherThis2->ConsoleFunctionClassPointer);
	}

	void ConsoleFunctionClass::Activate(String ^pArgs)
	{
		if (pArgs == nullptr)
		{
			throw gcnew ArgumentNullException("pArgs");
		}

		IntPtr pArgsHandle = Marshal::StringToHGlobalAnsi(pArgs);
		try
		{
			InternalConsoleFunctionClassPointer->Activate(reinterpret_cast<char *>(pArgsHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(pArgsHandle);
		}
	}

	IRenSharpConsoleFunctionClass^ ConsoleFunctionClass::AsManagedConsoleFunction()
	{
		return Engine::AsManagedConsoleFunction(this);
	}

	IntPtr ConsoleFunctionClass::ConsoleFunctionClassPointer::get()
	{
		return IntPtr(InternalConsoleFunctionClassPointer);
	}

	String ^ConsoleFunctionClass::Name::get()
	{
		auto result = InternalConsoleFunctionClassPointer->Get_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String ^ConsoleFunctionClass::Alias::get()
	{
		auto result = InternalConsoleFunctionClassPointer->Get_Alias();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String ^ConsoleFunctionClass::Help::get()
	{
		auto result = InternalConsoleFunctionClassPointer->Get_Help();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	bool ConsoleFunctionClass::IsManagedConsoleFunction::get()
	{
		return Engine::IsManagedConsoleFunction(this);
	}

	bool ConsoleFunctionClass::InternalDestroyPointer()
	{
		Imports::DestroyConsoleFunctionClass(InternalConsoleFunctionClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::ConsoleFunctionClass *ConsoleFunctionClass::InternalConsoleFunctionClassPointer::get()
	{
		return reinterpret_cast<::ConsoleFunctionClass *>(Pointer.ToPointer());
	}
}