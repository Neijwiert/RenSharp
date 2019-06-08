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

#include "stdafx.h"
#include "MControlClass.h"

#include "Imports.h"

namespace RenSharp
{
	ControlClass::ControlClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool ControlClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IControlClass ^otherThis = dynamic_cast<IControlClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return ControlClassPointer.Equals(otherThis->ControlClassPointer);
	}

	void ControlClass::ClearOneTimeBoolean()
	{
		InternalControlClassPointer->Clear_One_Time_Boolean();
	}

	void ControlClass::ClearAnalog()
	{
		InternalControlClassPointer->Clear_Analog();
	}

	void ControlClass::SetAnalog(IControlClass::AnalogControl control, float value)
	{
		InternalControlClassPointer->Set_Analog(static_cast<::ControlClass::AnalogControl>(control), value);
	}

	float ControlClass::GetAnalog(IControlClass::AnalogControl control)
	{
		return InternalControlClassPointer->Get_Analog(static_cast<::ControlClass::AnalogControl>(control));
	}

	IntPtr ControlClass::ControlClassPointer::get()
	{
		return IntPtr(InternalControlClassPointer);
	}

	bool ControlClass::ActionTrigger::get()
	{
		return InternalControlClassPointer->Get_Action_Trigger();
	}

	void ControlClass::ActionTrigger::set(bool value)
	{
		InternalControlClassPointer->Set_Action_Trigger(value);
	}

	unsigned long ControlClass::OneTimeBooleanBits::get()
	{
		return InternalControlClassPointer->Get_One_Time_Boolean_Bits();
	}

	unsigned char ControlClass::ContinuousBooleanBits::get()
	{
		return InternalControlClassPointer->Get_Continuous_Boolean_Bits();
	}

	bool ControlClass::InternalDestroyPointer()
	{
		Imports::DestroyControlClass(InternalControlClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::ControlClass *ControlClass::InternalControlClassPointer::get()
	{
		return reinterpret_cast<::ControlClass *>(Pointer.ToPointer());
	}
}