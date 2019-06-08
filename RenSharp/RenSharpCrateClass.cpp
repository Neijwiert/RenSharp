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

#include "General.h"
#include "RenSharpCrateClass.h"

#include "RenSharp.h"

RenSharpCrateClass::RenSharpCrateClass()
{

}

RenSharpCrateClass::~RenSharpCrateClass()
{
	RenSharpRootEventClass::Get_Instance().Crate_Destructed(this);
}

void RenSharpCrateClass::Init()
{
	RenSharpRootEventClass::Get_Instance().Crate_Init(this);
}

void RenSharpCrateClass::Settings_Loaded()
{
	RenSharpRootEventClass::Get_Instance().Crate_Settings_Loaded(this);
}

void RenSharpCrateClass::Calculate_Odds(cPlayer* player)
{
	RenSharpRootEventClass::Get_Instance().Crate_Calculate_Odds(this, player);
}

bool RenSharpCrateClass::Can_Activate(cPlayer* player)
{
	return RenSharpRootEventClass::Get_Instance().Crate_Can_Activate(this, player);
}

void RenSharpCrateClass::Activate(cPlayer* player)
{
	RenSharpRootEventClass::Get_Instance().Crate_Activate(this, player);
}