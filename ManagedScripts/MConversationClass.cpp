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
#include "MConversationClass.h"

#include "Imports.h"
#include "MPhysicalGameObj.h"
#include "MVector3.h"

using namespace System::Text;

namespace RenSharp
{
	ConversationRemarkClass::ConversationRemarkClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateConversationRemarkClass()))
	{

	}

	ConversationRemarkClass::ConversationRemarkClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IConversationRemarkClass^>^ ConversationRemarkClass::CreateConversationRemarkClass()
	{
		return gcnew UnmanagedContainer<IConversationRemarkClass^>(gcnew ConversationRemarkClass());
	}

	bool ConversationRemarkClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IConversationRemarkClass^ otherThis = dynamic_cast<IConversationRemarkClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return ConversationRemarkClassPointer.Equals(otherThis->ConversationRemarkClassPointer);
	}

	IntPtr ConversationRemarkClass::ConversationRemarkClassPointer::get()
	{
		return IntPtr(InternalConversationRemarkClassPointer);
	}

	int ConversationRemarkClass::OratorID::get()
	{
		return InternalConversationRemarkClassPointer->Get_Orator_ID();
	}

	void ConversationRemarkClass::OratorID::set(int value)
	{
		InternalConversationRemarkClassPointer->Set_Orator_ID(value);
	}

	uint32 ConversationRemarkClass::TextID::get()
	{
		return InternalConversationRemarkClassPointer->Get_Text_ID();
	}

	void ConversationRemarkClass::TextID::set(uint32 value)
	{
		InternalConversationRemarkClassPointer->Set_Text_ID(value);
	}

	String^ ConversationRemarkClass::AnimationName::get()
	{
		auto result = InternalConversationRemarkClassPointer->Get_Animation_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	void ConversationRemarkClass::AnimationName::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalConversationRemarkClassPointer->Set_Animation_Name(
				reinterpret_cast<char*>(valueHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	bool ConversationRemarkClass::InternalDestroyPointer()
	{
		Imports::DestroyConversationRemarkClass(InternalConversationRemarkClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::ConversationRemarkClass* ConversationRemarkClass::InternalConversationRemarkClassPointer::get()
	{
		return reinterpret_cast<::ConversationRemarkClass*>(Pointer.ToPointer());
	}

	OratorClass::OratorClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateOratorClass()))
	{

	}

	OratorClass::OratorClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IOratorClass^>^ OratorClass::CreateOratorClass()
	{
		return gcnew UnmanagedContainer<IOratorClass^>(gcnew OratorClass());
	}

	bool OratorClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IOratorClass^ otherThis = dynamic_cast<IOratorClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return OratorClassPointer.Equals(otherThis->OratorClassPointer);
	}

	bool OratorClass::GetFlag(int flag)
	{
		return InternalOratorClassPointer->Get_Flag(flag);
	}

	void OratorClass::SetFlag(int flag, bool onoff)
	{
		InternalOratorClassPointer->Set_Flag(flag, onoff);
	}

	void OratorClass::SetFlags(int newFlags)
	{
		InternalOratorClassPointer->Set_Flags(newFlags);
	}

	void OratorClass::SetArrived(bool arrived)
	{
		InternalOratorClassPointer->Set_Arrived(arrived);
	}

	void OratorClass::Initialize(IPhysicalGameObj^ obj)
	{
		if (obj == nullptr || obj->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			InternalOratorClassPointer->Initialize(nullptr);
		}
		else
		{
			InternalOratorClassPointer->Initialize(
				reinterpret_cast<::PhysicalGameObj*>(obj->PhysicalGameObjPointer.ToPointer()));
		}
	}

	void OratorClass::SetOratorID(int id)
	{
		InternalOratorClassPointer->Set_Orator_ID(id);
	}

	void OratorClass::SetFacingID(int id)
	{
		InternalOratorClassPointer->Set_Facing_ID(id);
	}

	IntPtr OratorClass::OratorClassPointer::get()
	{
		return IntPtr(InternalOratorClassPointer);
	}

	IPhysicalGameObj^ OratorClass::GameObj::get()
	{
		auto result = InternalOratorClassPointer->Get_Game_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IPhysicalGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	Vector3 OratorClass::Position::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalOratorClassPointer->Get_Position(), result);

		return result;
	}

	void OratorClass::Position::set(Vector3 value)
	{
		::Vector3 valueVec;

		Vector3::ManagedToUnmanagedVector3(value, InternalOratorClassPointer->Get_Position());
	}

	bool OratorClass::InternalDestroyPointer()
	{
		Imports::DestroyOratorClass(InternalOratorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::OratorClass* OratorClass::InternalOratorClassPointer::get()
	{
		return reinterpret_cast<::OratorClass*>(Pointer.ToPointer());
	}

	ConversationClass::ConversationClass(IntPtr pointer)
		: RefCountClass(pointer)
	{

	}

	String^ ConversationClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	IUnmanagedContainer<IConversationRemarkClass^>^ ConversationClass::GetRemarkInfo(int index)
	{
		if (index < 0 || index >= InternalConversationClassPointer->Get_Remark_Count())
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = ConversationRemarkClass::CreateConversationRemarkClass();
		try
		{
			if (!InternalConversationClassPointer->Get_Remark_Info(
				index,
				*reinterpret_cast<::ConversationRemarkClass*>(result->UnmanagedObject->ConversationRemarkClassPointer.ToPointer())))
			{
#pragma push_macro("delete")
#undef delete

				delete result;
				result = nullptr;

#pragma pop_macro("delete")
			}
			
			return result;
		}
		catch (Exception^)
		{
#pragma push_macro("delete")
#undef delete

			delete result;
			result = nullptr;

#pragma pop_macro("delete")

			throw;
		}
	}

	IntPtr ConversationClass::ConversationClassPointer::get()
	{
		return IntPtr(InternalConversationClassPointer);
	}

	int ConversationClass::OratorCount::get()
	{
		return InternalConversationClassPointer->Get_Orator_Count();
	}

	int ConversationClass::RemarkCount::get()
	{
		return InternalConversationClassPointer->Get_Remark_Count();
	}

	int ConversationClass::ID::get()
	{
		return InternalConversationClassPointer->Get_ID();
	}

	void ConversationClass::ID::set(int value)
	{
		InternalConversationClassPointer->Set_ID(value);
	}

	String^ ConversationClass::Name::get()
	{
		auto result = InternalConversationClassPointer->Get_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	void ConversationClass::Name::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalConversationClassPointer->Set_Name(
				reinterpret_cast<char*>(valueHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	SoldierAIState ConversationClass::AIState::get()
	{
		return static_cast<SoldierAIState>(InternalConversationClassPointer->Get_AI_State());
	}

	void ConversationClass::AIState::set(SoldierAIState value)
	{
		InternalConversationClassPointer->Set_AI_State(
			static_cast<::SoldierAIState>(value));
	}

	bool ConversationClass::IsInnate::get()
	{
		return InternalConversationClassPointer->Is_Innate();
	}

	void ConversationClass::IsInnate::set(bool value)
	{
		InternalConversationClassPointer->Set_Is_Innate(value);
	}

	bool ConversationClass::IsKey::get()
	{
		return InternalConversationClassPointer->Is_Key();
	}

	void ConversationClass::IsKey::set(bool value)
	{
		InternalConversationClassPointer->Set_Is_Key(value);
	}

	float ConversationClass::Probability::get()
	{
		return InternalConversationClassPointer->Get_Probability();
	}

	void ConversationClass::Probability::set(float value)
	{
		InternalConversationClassPointer->Set_Probability(value);
	}

	int ConversationClass::CategoryID::get()
	{
		return InternalConversationClassPointer->Get_Category_ID();
	}

	void ConversationClass::CategoryID::set(int value)
	{
		InternalConversationClassPointer->Set_Category_ID(value);
	}

	int ConversationClass::LookAtObjID::get()
	{
		return InternalConversationClassPointer->Get_Look_At_Obj_ID();
	}

	void ConversationClass::LookAtObjID::set(int value)
	{
		InternalConversationClassPointer->Set_Look_At_Obj_ID(value);
	}

	int ConversationClass::Priority::get()
	{
		return InternalConversationClassPointer->Get_Priority();
	}

	void ConversationClass::Priority::set(int value)
	{
		InternalConversationClassPointer->Set_Priority(value);
	}

	float ConversationClass::MaxDist::get()
	{
		return InternalConversationClassPointer->Get_Max_Dist();
	}

	void ConversationClass::MaxDist::set(float value)
	{
		InternalConversationClassPointer->Set_Max_Dist(value);
	}

	bool ConversationClass::IsInterruptable::get()
	{
		return InternalConversationClassPointer->Is_Interruptable();
	}

	void ConversationClass::IsInterruptable::set(bool value)
	{
		InternalConversationClassPointer->Set_Is_Interruptable(value);
	}

	::RefCountClass* ConversationClass::InternalRefCountClassPointer::get()
	{
		return InternalConversationClassPointer;
	}

	::ConversationClass* ConversationClass::InternalConversationClassPointer::get()
	{
		return reinterpret_cast<::ConversationClass*>(Pointer.ToPointer());
	}
}