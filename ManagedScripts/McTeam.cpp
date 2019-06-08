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
#include "McTeam.h"

namespace RenSharp
{
	cTeam::cTeam(IntPtr pointer)
		: NetworkObjectClass(pointer)
	{

	}

	String^ cTeam::ToString()
	{
		return Name;
	}

	IntPtr cTeam::cTeamPointer::get()
	{
		return IntPtr(InternalcTeamPointer);
	}

	String^ cTeam::Name::get()
	{
		::WideStringClass tmp = InternalcTeamPointer->Get_Name();

		return gcnew String(tmp.Peek_Buffer());
	}

	int cTeam::ID::get()
	{
		return InternalcTeamPointer->Get_Id();
	}

	int cTeam::Kills::get()
	{
		return InternalcTeamPointer->Get_Kills();
	}

	void cTeam::Kills::set(int value)
	{
		InternalcTeamPointer->Set_Kills(value);
	}

	int cTeam::Deaths::get()
	{
		return InternalcTeamPointer->Get_Deaths();
	}

	void cTeam::Deaths::set(int value)
	{
		InternalcTeamPointer->Set_Deaths(value);
	}

	float cTeam::Score::get()
	{
		return InternalcTeamPointer->Get_Score();
	}

	void cTeam::Score::set(float value)
	{
		InternalcTeamPointer->Set_Score(value);
	}

	float cTeam::KillToDeathRatio::get()
	{
		return InternalcTeamPointer->Get_Kill_To_Death_Ratio();
	}

	::NetworkObjectClass* cTeam::InternalNetworkObjectClassPointer::get()
	{
		return InternalcTeamPointer;
	}

	::cTeam* cTeam::InternalcTeamPointer::get()
	{
		return reinterpret_cast<::cTeam*>(Pointer.ToPointer());
	}
}