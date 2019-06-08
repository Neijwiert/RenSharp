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
#include "RenSharpGameModeFactoryClass.h"

#include "RenSharp.h"

RenSharpGameModeFactoryClass::RenSharpGameModeFactoryClass(const char* shortName, const char* longName, const char* requiredData)
	:
	DAGameModeFactoryClass(shortName, longName, requiredData),
	shortName(shortName == nullptr ? "" : shortName),
	longName(longName == nullptr ? "" : longName),
	requiredData(requiredData == nullptr ? "" : requiredData)
{
	if (shortName != nullptr)
	{
		ShortName = this->shortName.Peek_Buffer();
	}

	if (longName != nullptr)
	{
		LongName = this->longName.Peek_Buffer();
	}

	if (requiredData != nullptr)
	{
		RequiredData = this->requiredData.Peek_Buffer();
	}
}

RenSharpGameModeFactoryClass::~RenSharpGameModeFactoryClass()
{
	RenSharpRootEventClass::Get_Instance().GameModeFactory_Destructed(this);
}

DAGameModeClass* RenSharpGameModeFactoryClass::Create_Instance()
{
	return RenSharpRootEventClass::Get_Instance().GameModeFactory_Create_Instance(this);
}