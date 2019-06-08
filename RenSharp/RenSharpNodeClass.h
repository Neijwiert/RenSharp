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

#pragma once

#include <engine_player.h>
#include <engine_da.h>
#include <da_nodemanager.h>

class RenSharpNodeClass : public DABaseNodeClass
{
	private:
		StringClass type;

	public:
		RenSharpNodeClass(const char* type);
		virtual ~RenSharpNodeClass();

		virtual const char* Get_Type() const;
		virtual void Init(const INIClass* ini, const StringClass& header);
		virtual void Contested_Event();
		virtual void Capture_Event();
};