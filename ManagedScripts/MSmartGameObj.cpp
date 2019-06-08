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
#include "MSmartGameObj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <SmartGameObj.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MSmartGameObjDef.h"
#include "MPlayerDataClass.h"
#include "Maction.h"
#include "MMatrix3D.h"
#include "MVector3.h"
#include "MStealthEffectClass.h"
#include "MPhysControllerClass.h"

namespace RenSharp
{

#pragma managed(push, off)

	class SmartGameObjHelper : public ::SmartGameObj
	{
		private:
			SmartGameObjHelper() = default;

		public:
			::PhysControllerClass &GetController()
			{
				return Controller;
			}

			bool &GetStealthEnabled()
			{
				return StealthEnabled;
			}

			bool &GetStealthActive()
			{
				return StealthActive;
			}

			float &GetStealthPowerupTimer()
			{
				return StealthPowerupTimer;
			}

			float &GetStealthFiringTimer()
			{
				return StealthFiringTimer;
			}

			::StealthEffectClass *&GetStealthEffect()
			{
				return StealthEffect;
			}
	};

#pragma managed(pop)

	SmartGameObj::SmartGameObj(IntPtr pointer)
		: ArmedGameObj(pointer)
	{

	}

	ISmartGameObj ^SmartGameObj::AsSmartGameObj()
	{
		return this;
	}

	void SmartGameObj::SetAnalogControl(IControlClass::AnalogControl control, float value)
	{
		InternalSmartGameObjPointer->Set_Analog_Control(static_cast<::ControlClass::AnalogControl>(control), value);
	}

	void SmartGameObj::GenerateControl()
	{
		InternalSmartGameObjPointer->Generate_Control();
	}

	void SmartGameObj::ApplyControl()
	{
		InternalSmartGameObjPointer->Apply_Control();
	}

	bool SmartGameObj::IsObjVisible(IPhysicalGameObj ^obj)
	{
		if (obj == nullptr || obj->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalSmartGameObjPointer->Is_Obj_Visible(reinterpret_cast<::PhysicalGameObj *>(obj->PhysicalGameObjPointer.ToPointer()));
	}

	bool SmartGameObj::IsSplashPossible(IPhysicalGameObj ^obj)
	{
		if (obj == nullptr || obj->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalSmartGameObjPointer->Is_Splash_Possible(reinterpret_cast<::PhysicalGameObj *>(obj->PhysicalGameObjPointer.ToPointer()));
	}

	IntPtr SmartGameObj::SmartGameObjPointer::get()
	{
		return IntPtr(InternalSmartGameObjPointer);
	}

	ISmartGameObjDef ^SmartGameObj::Definition::get()
	{
		return gcnew SmartGameObjDef(IntPtr(const_cast<::SmartGameObjDef *>(&InternalSmartGameObjPointer->Get_Definition())));
	}

	IControlClass ^SmartGameObj::Control::get()
	{
		return gcnew ControlClass(IntPtr(&InternalSmartGameObjPointer->Get_Control()));
	}

	void SmartGameObj::Control::set(IControlClass ^value)
	{
		if (value == nullptr || value->ControlClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto &control = InternalSmartGameObjPointer->Get_Control();

		control = *reinterpret_cast<::ControlClass *>(value->ControlClassPointer.ToPointer());
	}

	bool SmartGameObj::ControlEnabled::get()
	{
		return InternalSmartGameObjPointer->Is_Control_Enabled();
	}

	void SmartGameObj::ControlEnabled::set(bool value)
	{
		InternalSmartGameObjPointer->Control_Enable(value);
	}

	int SmartGameObj::ControlOwner::get()
	{
		return InternalSmartGameObjPointer->Get_Control_Owner();
	}

	void SmartGameObj::ControlOwner::set(int value)
	{
		InternalSmartGameObjPointer->Set_Control_Owner(value);
	}

	int SmartGameObj::WeaponControlOwner::get()
	{
		return InternalSmartGameObjPointer->Get_Weapon_Control_Owner();
	}

	IPlayerDataClass ^SmartGameObj::PlayerData::get()
	{
		auto result = InternalSmartGameObjPointer->Get_Player_Data();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PlayerDataClass(IntPtr(result));
		}
	}

	bool SmartGameObj::HasPlayer::get()
	{
		return InternalSmartGameObjPointer->Has_Player();
	}

	bool SmartGameObj::IsHumanControlled::get()
	{
		return InternalSmartGameObjPointer->Is_Human_Controlled();
	}

	float SmartGameObj::MaxSpeed::get()
	{
		return InternalSmartGameObjPointer->Get_Max_Speed();
	}

	float SmartGameObj::TurnRate::get()
	{
		return InternalSmartGameObjPointer->Get_Turn_Rate();
	}

	IActionClass ^SmartGameObj::Action::get()
	{
		auto result = InternalSmartGameObjPointer->Get_Action();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ActionClass(IntPtr(result));
		}
	}

	bool SmartGameObj::IsEnemySeenEnabled::get()
	{
		return InternalSmartGameObjPointer->Is_Enemy_Seen_Enabled();
	}

	void SmartGameObj::IsEnemySeenEnabled::set(bool value)
	{
		InternalSmartGameObjPointer->Set_Enemy_Seen_Enabled(value);
	}

	Matrix3D SmartGameObj::LookTransform::get()
	{
		Matrix3D result;
		Matrix3D::UnmanagedToManagedMatrix3D(InternalSmartGameObjPointer->Get_Look_Transform(), result);

		return result;
	}

	Vector3 SmartGameObj::Velocity::get()
	{
		::Vector3 tmp;

		InternalSmartGameObjPointer->Get_Velocity(tmp);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	bool SmartGameObj::IsVisible::get()
	{
		return InternalSmartGameObjPointer->Is_Visible();
	}

	bool SmartGameObj::IsStealthEnabled::get()
	{
		return InternalSmartGameObjPointer->Is_Stealth_Enabled();
	}

	bool SmartGameObj::IsStealthed::get()
	{
		return InternalSmartGameObjPointer->Is_Stealthed();
	}

	float SmartGameObj::StealthFadeDistance::get()
	{
		return InternalSmartGameObjPointer->Get_Stealth_Fade_Distance();
	}

	IStealthEffectClass ^SmartGameObj::StealthEffect::get()
	{
		auto result = InternalSmartGameObjPointer->Peek_Stealth_Effect();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew StealthEffectClass(IntPtr(result));
		}
	}

	void SmartGameObj::StealthEffect::set(IStealthEffectClass ^value)
	{
		auto helper = reinterpret_cast<SmartGameObjHelper *>(InternalSmartGameObjPointer);

		auto &stealthEffect = helper->GetStealthEffect();

		if (value == nullptr || value->StealthEffectClassPointer.ToPointer() == nullptr)
		{
			stealthEffect = nullptr;
		}
		else
		{
			stealthEffect = reinterpret_cast<::StealthEffectClass *>(value->StealthEffectClassPointer.ToPointer());
		}
	}

	bool SmartGameObj::IsStealthActive::get()
	{
		return InternalSmartGameObjPointer->Get_Stealth_Active();
	}

	void SmartGameObj::IsStealthActive::set(bool value)
	{
		InternalSmartGameObjPointer->Set_Stealth_Active(value);
	}

	::ArmedGameObj *SmartGameObj::InternalArmedGameObjPointer::get()
	{
		return InternalSmartGameObjPointer;
	}

	::SmartGameObj *SmartGameObj::InternalSmartGameObjPointer::get()
	{
		return reinterpret_cast<::SmartGameObj *>(Pointer.ToPointer());
	}

	IPhysControllerClass ^SmartGameObj::Controller::get()
	{
		auto helper = reinterpret_cast<SmartGameObjHelper *>(InternalSmartGameObjPointer);

		auto &controller = helper->GetController();

		return gcnew PhysControllerClass(IntPtr(&controller));
	}

	void SmartGameObj::Controller::set(IPhysControllerClass ^value)
	{
		if (value == nullptr || value->PhysControllerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<SmartGameObjHelper *>(InternalSmartGameObjPointer);

		auto &controller = helper->GetController();

		controller = *reinterpret_cast<::PhysControllerClass *>(value->PhysControllerClassPointer.ToPointer());
	}

	bool SmartGameObj::StealthEnabled::get()
	{
		auto helper = reinterpret_cast<SmartGameObjHelper *>(InternalSmartGameObjPointer);

		auto &stealthEnabled = helper->GetStealthEnabled();

		return stealthEnabled;
	}

	void SmartGameObj::StealthEnabled::set(bool value)
	{
		auto helper = reinterpret_cast<SmartGameObjHelper *>(InternalSmartGameObjPointer);

		auto &stealthEnabled = helper->GetStealthEnabled();

		stealthEnabled = value;
	}

	bool SmartGameObj::StealthActive::get()
	{
		auto helper = reinterpret_cast<SmartGameObjHelper *>(InternalSmartGameObjPointer);

		auto &stealthActive = helper->GetStealthActive();

		return stealthActive;
	}

	void SmartGameObj::StealthActive::set(bool value)
	{
		auto helper = reinterpret_cast<SmartGameObjHelper *>(InternalSmartGameObjPointer);

		auto &stealthActive = helper->GetStealthActive();

		stealthActive = value;
	}

	float SmartGameObj::StealthPowerupTimer::get()
	{
		auto helper = reinterpret_cast<SmartGameObjHelper *>(InternalSmartGameObjPointer);

		auto &stealthPowerupTimer = helper->GetStealthPowerupTimer();

		return stealthPowerupTimer;
	}

	void SmartGameObj::StealthPowerupTimer::set(float value)
	{
		auto helper = reinterpret_cast<SmartGameObjHelper *>(InternalSmartGameObjPointer);

		auto &stealthPowerupTimer = helper->GetStealthPowerupTimer();

		stealthPowerupTimer = value;
	}

	float SmartGameObj::StealthFiringTimer::get()
	{
		auto helper = reinterpret_cast<SmartGameObjHelper *>(InternalSmartGameObjPointer);

		auto &stealthFiringTimer = helper->GetStealthFiringTimer();

		return stealthFiringTimer;
	}

	void SmartGameObj::StealthFiringTimer::set(float value)
	{
		auto helper = reinterpret_cast<SmartGameObjHelper *>(InternalSmartGameObjPointer);

		auto &stealthFiringTimer = helper->GetStealthFiringTimer();

		stealthFiringTimer = value;
	}
}