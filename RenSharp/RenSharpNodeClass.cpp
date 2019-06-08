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
#include "RenSharpNodeClass.h"

#include "RenSharp.h"

RenSharpNodeClass::RenSharpNodeClass(const char* type)
	: type(type)
{

}

RenSharpNodeClass::~RenSharpNodeClass()
{
	RenSharpRootEventClass::Get_Instance().Node_Destructed(this);
}

const char* RenSharpNodeClass::Get_Type() const
{
	return type.Peek_Buffer();
}

void RenSharpNodeClass::Init(const INIClass* ini, const StringClass& header)
{
	RenSharpRootEventClass::Get_Instance().Node_Init(this, ini, header);
}

void RenSharpNodeClass::Contested_Event()
{
	RenSharpRootEventClass::Get_Instance().Node_Contested_Event(this);
}

void RenSharpNodeClass::Capture_Event()
{
	RenSharpRootEventClass::Get_Instance().Node_Capture_Event(this);
}