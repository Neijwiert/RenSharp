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
#include "RenSharpPlayerDataClass.h"

#include "RenSharp.h"

RenSharpPlayerDataClass::RenSharpPlayerDataClass()
{

}

RenSharpPlayerDataClass::~RenSharpPlayerDataClass()
{
	RenSharpRootEventClass::Get_Instance().PlayerData_Destructed(this);
}

void RenSharpPlayerDataClass::Init()
{
	RenSharpRootEventClass::Get_Instance().PlayerData_Init(this);
}

void RenSharpPlayerDataClass::Clear_Level()
{
	RenSharpRootEventClass::Get_Instance().PlayerData_Clear_Level(this);
}

void RenSharpPlayerDataClass::Clear_Session()
{
	RenSharpRootEventClass::Get_Instance().PlayerData_Clear_Session(this);
}