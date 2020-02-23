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
#include "RenSharpConsoleFunctionClass.h"
#include "RenSharp.h"

RenSharpConsoleFunctionClass::RenSharpConsoleFunctionClass(const char *name, const char *alias, const char *help)
	: name(name), help(help), aliasNull(alias == nullptr)
{
	if (!aliasNull)
	{
		this->alias = alias;
	}
}

RenSharpConsoleFunctionClass::~RenSharpConsoleFunctionClass()
{
	RenSharpRootEventClass::Get_Instance().ConsoleFunction_Destructed(this);
}

const char *RenSharpConsoleFunctionClass::Get_Name()
{
	return name.Peek_Buffer();
}

const char *RenSharpConsoleFunctionClass::Get_Alias()
{
	if (aliasNull)
	{
		return nullptr;
	}
	else
	{
		return alias.Peek_Buffer();
	}
}

const char *RenSharpConsoleFunctionClass::Get_Help()
{
	return help.Peek_Buffer();
}

void RenSharpConsoleFunctionClass::Activate(const char *pArgs)
{
	RenSharpRootEventClass::Get_Instance().ConsoleFunction_Activate(this, pArgs);
}