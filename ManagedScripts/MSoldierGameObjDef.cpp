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
#include "MSoldierGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <SoldierGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MDialogueClass.h"

namespace RenSharp
{

#pragma managed(push, off)

	class SoldierGameObjDefHelper : public ::SoldierGameObjDef
	{
		private:
			SoldierGameObjDefHelper() = default;

		public:
			float &GetSkeletonHeight()
			{
				return SkeletonHeight;
			}

			float &GetSkeletonWidth()
			{
				return SkeletonWidth;
			}

			bool &GetIsSpy()
			{
				return IsSpy;
			}

			bool &GetCanRefill()
			{
				return CanRefill;
			}

			bool &GetIsUnsquishable()
			{
				return IsUnsquishable;
			}

			float &GetTurnRate()
			{
				return TurnRate;
			}

			float &GetJumpVelocity()
			{
				return JumpVelocity;
			}

			bool &GetUseInnateBehavior()
			{
				return UseInnateBehavior;
			}

			float &GetInnateAggressiveness()
			{
				return InnateAggressiveness;
			}

			float &GetInnateTakeCoverProbability()
			{
				return InnateTakeCoverProbability;
			}

			bool &GetInnateIsStationary()
			{
				return InnateIsStationary;
			}

			::StringClass &GetFirstPersonHands()
			{
				return FirstPersonHands;
			}

			int &GetHumanAnimOverrideDefID()
			{
				return HumanAnimOverrideDefID;
			}

			int &GetHumanLoiterCollectionDefID()
			{
				return HumanLoiterCollectionDefID;
			}

			int &GetDeathSoundPresetID()
			{
				return DeathSoundPresetID;
			}

			bool &GetCanStealVehicles()
			{
				return CanStealVehicles;
			}

			bool &GetCanDriveVehicles()
			{
				return CanDriveVehicles;
			}
	};

#pragma managed(pop)

	SoldierGameObjDef::SoldierGameObjDef(IntPtr pointer)
		: SmartGameObjDef(pointer)
	{

	}

	IntPtr SoldierGameObjDef::SoldierGameObjDefPointer::get()
	{
		return IntPtr(InternalSoldierGameObjDefPointer);
	}

	array<IDialogueClass ^> ^SoldierGameObjDef::DialogList::get()
	{
		auto dialogList = InternalSoldierGameObjDefPointer->Get_Dialog_List();

		array<IDialogueClass ^> ^result = gcnew array<IDialogueClass ^>(DIALOG_MAX);
		for (int x = 0; x < DIALOG_MAX; x++)
		{
			result[x] = gcnew DialogueClass(IntPtr(&dialogList[x]));
		}

		return result;
	}

	float SoldierGameObjDef::SkeletonHeight::get()
	{
		return InternalSoldierGameObjDefPointer->Get_Skeleton_Height();
	}

	void SoldierGameObjDef::SkeletonHeight::set(float value)
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &skeletonHeight = helper->GetSkeletonHeight();

		skeletonHeight = value;
	}

	float SoldierGameObjDef::SkeletonWidth::get()
	{
		return InternalSoldierGameObjDefPointer->Get_Skeleton_Width();
	}

	void SoldierGameObjDef::SkeletonWidth::set(float value)
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &skeletonWidth = helper->GetSkeletonWidth();

		skeletonWidth = value;
	}

	bool SoldierGameObjDef::IsSpy::get()
	{
		return InternalSoldierGameObjDefPointer->Is_Spy();
	}

	void SoldierGameObjDef::IsSpy::set(bool value)
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &isSpy = helper->GetIsSpy();

		isSpy = value;
	}

	bool SoldierGameObjDef::CanRefill::get()
	{
		return InternalSoldierGameObjDefPointer->Can_Refill();
	}

	void SoldierGameObjDef::CanRefill::set(bool value)
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &canRefill = helper->GetCanRefill();

		canRefill = value;
	}

	bool SoldierGameObjDef::IsUnsquishable::get()
	{
		return InternalSoldierGameObjDefPointer->Is_Unsquishable();
	}

	void SoldierGameObjDef::IsUnsquishable::set(bool value)
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &isUnsquishable = helper->GetIsUnsquishable();

		isUnsquishable = value;
	}

	::SmartGameObjDef *SoldierGameObjDef::InternalSmartGameObjDefPointer::get()
	{
		return InternalSoldierGameObjDefPointer;
	}

	::SoldierGameObjDef *SoldierGameObjDef::InternalSoldierGameObjDefPointer::get()
	{
		return reinterpret_cast<::SoldierGameObjDef *>(Pointer.ToPointer());
	}

	float SoldierGameObjDef::TurnRate::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &turnRate = helper->GetTurnRate();

		return turnRate;
	}

	void SoldierGameObjDef::TurnRate::set(float value)
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &turnRate = helper->GetTurnRate();

		turnRate = value;
	}

	float SoldierGameObjDef::JumpVelocity::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &jumpVelocity = helper->GetJumpVelocity();

		return jumpVelocity;
	}

	void SoldierGameObjDef::JumpVelocity::set(float value)
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &jumpVelocity = helper->GetJumpVelocity();

		jumpVelocity = value;
	}

	bool SoldierGameObjDef::UseInnateBehavior::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &useInnateBehavior = helper->GetUseInnateBehavior();

		return useInnateBehavior;
	}

	void SoldierGameObjDef::UseInnateBehavior::set(bool value)
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &useInnateBehavior = helper->GetUseInnateBehavior();

		useInnateBehavior = value;
	}

	float SoldierGameObjDef::InnateAggressiveness::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &innateAggressiveness = helper->GetInnateAggressiveness();

		return innateAggressiveness;
	}

	void SoldierGameObjDef::InnateAggressiveness::set(float value)
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &innateAggressiveness = helper->GetInnateAggressiveness();

		innateAggressiveness = value;
	}

	float SoldierGameObjDef::InnateTakeCoverProbability::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &innateTakeCoverProbability = helper->GetInnateTakeCoverProbability();

		return innateTakeCoverProbability;
	}

	void SoldierGameObjDef::InnateTakeCoverProbability::set(float value)
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &innateTakeCoverProbability = helper->GetInnateTakeCoverProbability();

		innateTakeCoverProbability = value;
	}

	bool SoldierGameObjDef::InnateIsStationary::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &innateIsStationary = helper->GetInnateIsStationary();

		return innateIsStationary;
	}

	void SoldierGameObjDef::InnateIsStationary::set(bool value)
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &innateIsStationary = helper->GetInnateIsStationary();

		innateIsStationary = value;
	}

	String ^SoldierGameObjDef::FirstPersonHands::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &firstPersonHands = helper->GetFirstPersonHands();

		return gcnew String(firstPersonHands.Peek_Buffer());
	}

	void SoldierGameObjDef::FirstPersonHands::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

			auto &firstPersonHands = helper->GetFirstPersonHands();

			firstPersonHands = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	int SoldierGameObjDef::HumanAnimOverrideDefID::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &humanAnimOverrideDefID = helper->GetHumanAnimOverrideDefID();

		return humanAnimOverrideDefID;
	}

	void SoldierGameObjDef::HumanAnimOverrideDefID::set(int value)
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &humanAnimOverrideDefID = helper->GetHumanAnimOverrideDefID();

		humanAnimOverrideDefID = value;
	}

	int SoldierGameObjDef::HumanLoiterCollectionDefID::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &humanLoiterCollectionDefID = helper->GetHumanLoiterCollectionDefID();

		return humanLoiterCollectionDefID;
	}

	void SoldierGameObjDef::HumanLoiterCollectionDefID::set(int value)
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &humanLoiterCollectionDefID = helper->GetHumanLoiterCollectionDefID();

		humanLoiterCollectionDefID = value;
	}

	int SoldierGameObjDef::DeathSoundPresetID::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &deathSoundPresetID = helper->GetDeathSoundPresetID();

		return deathSoundPresetID;
	}

	void SoldierGameObjDef::DeathSoundPresetID::set(int value)
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &deathSoundPresetID = helper->GetDeathSoundPresetID();

		deathSoundPresetID = value;
	}

	bool SoldierGameObjDef::CanStealVehicles::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &canStealVehicles = helper->GetCanStealVehicles();

		return canStealVehicles;
	}

	void SoldierGameObjDef::CanStealVehicles::set(bool value)
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &canStealVehicles = helper->GetCanStealVehicles();

		canStealVehicles = value;
	}

	bool SoldierGameObjDef::CanDriveVehicles::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &canDriveVehicles = helper->GetCanDriveVehicles();

		return canDriveVehicles;
	}

	void SoldierGameObjDef::CanDriveVehicles::set(bool value)
	{
		auto helper = reinterpret_cast<SoldierGameObjDefHelper *>(InternalSoldierGameObjDefPointer);

		auto &canDriveVehicles = helper->GetCanDriveVehicles();

		canDriveVehicles = value;
	}
}