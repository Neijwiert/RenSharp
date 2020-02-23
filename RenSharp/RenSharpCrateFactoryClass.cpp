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

#include "General.h"
#include "RenSharpCrateFactoryClass.h"

#include "RenSharp.h"

RenSharpCrateFactoryClass::RenSharpCrateFactoryClass(const char* name, DACrateType::Type type)
	: DACrateFactoryClass(name, type), name(name == nullptr ? "" : name)
{
	if (name != nullptr)
	{
		Name = this->name.Peek_Buffer();
	}
}

RenSharpCrateFactoryClass::~RenSharpCrateFactoryClass()
{
	RenSharpRootEventClass::Get_Instance().CrateFactory_Destructed(this);
}

DACrateClass* RenSharpCrateFactoryClass::Create_Instance()
{
	return RenSharpRootEventClass::Get_Instance().CrateFactory_Create_Instance(this);
}