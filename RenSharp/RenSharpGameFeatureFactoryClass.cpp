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
#include "RenSharpGameFeatureFactoryClass.h"

#include "RenSharp.h"

RenSharpGameFeatureFactoryClass::RenSharpGameFeatureFactoryClass(const char* name, const char* enableSetting, const char* requiredData)
	:
	DAGameFeatureFactoryClass(name, enableSetting, requiredData),
	name(name == nullptr ? "" : name),
	enableSetting(enableSetting == nullptr ? "" : enableSetting),
	requiredData(requiredData == nullptr ? "" : requiredData)
{
	if (name != nullptr)
	{
		Name = this->name.Peek_Buffer();
	}

	if (enableSetting != nullptr)
	{
		EnableSetting = this->enableSetting.Peek_Buffer();
	}

	if (requiredData != nullptr)
	{
		RequiredData = this->requiredData.Peek_Buffer();
	}
}

RenSharpGameFeatureFactoryClass::~RenSharpGameFeatureFactoryClass()
{
	RenSharpRootEventClass::Get_Instance().GameFeatureFactory_Destructed(this);
}

DAGameFeatureClass* RenSharpGameFeatureFactoryClass::Create_Instance()
{
	return RenSharpRootEventClass::Get_Instance().GameFeatureFactory_Create_Instance(this);
}