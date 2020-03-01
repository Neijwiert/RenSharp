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
#include "MWarFactoryGameObj.h"

#include "MWarFactoryGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4091 4251 4244 26495 26454)
#include <WarFactoryGameObj.h>
#include <WarFactoryGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{

#pragma managed(push, off)

	class WarFactoryGameObjHelper : public ::WarFactoryGameObj
	{
		private:
			WarFactoryGameObjHelper() = default;

		public:
			int &GetCreationAnimationID()
			{
				return CreationAnimationID;
			}

			float &GetCreationFinishedTimer()
			{
				return CreationFinishedTimer;
			}
	};

#pragma managed(pop)

	WarFactoryGameObj::WarFactoryGameObj(IntPtr pointer)
		: VehicleFactoryGameObj(pointer)
	{

	}

	IntPtr WarFactoryGameObj::WarFactoryGameObjPointer::get()
	{
		return IntPtr(InternalWarFactoryGameObjPointer);
	}

	IWarFactoryGameObjDef ^WarFactoryGameObj::Definition::get()
	{
		return safe_cast<IWarFactoryGameObjDef^>(DefinitionClass::CreateDefinitionClassWrapper(&InternalWarFactoryGameObjPointer->Get_Definition()));
	}

	::VehicleFactoryGameObj *WarFactoryGameObj::InternalVehicleFactoryGameObjPointer::get()
	{
		return InternalWarFactoryGameObjPointer;
	}

	::WarFactoryGameObj *WarFactoryGameObj::InternalWarFactoryGameObjPointer::get()
	{
		return reinterpret_cast<::WarFactoryGameObj *>(Pointer.ToPointer());
	}

	int WarFactoryGameObj::CreationAnimationID::get()
	{
		auto helper = reinterpret_cast<WarFactoryGameObjHelper *>(InternalWarFactoryGameObjPointer);

		auto &creationAnimationId = helper->GetCreationAnimationID();

		return creationAnimationId;
	}

	void WarFactoryGameObj::CreationAnimationID::set(int value)
	{
		auto helper = reinterpret_cast<WarFactoryGameObjHelper *>(InternalWarFactoryGameObjPointer);

		auto &creationAnimationId = helper->GetCreationAnimationID();

		creationAnimationId = value;
	}

	float WarFactoryGameObj::CreationFinishedTimer::get()
	{
		auto helper = reinterpret_cast<WarFactoryGameObjHelper *>(InternalWarFactoryGameObjPointer);

		auto &creationFinishedTimer = helper->GetCreationFinishedTimer();

		return creationFinishedTimer;
	}

	void WarFactoryGameObj::CreationFinishedTimer::set(float value)
	{
		auto helper = reinterpret_cast<WarFactoryGameObjHelper *>(InternalWarFactoryGameObjPointer);

		auto &creationFinishedTimer = helper->GetCreationFinishedTimer();

		creationFinishedTimer = value;
	}
}