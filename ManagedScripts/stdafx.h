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

#pragma once

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4561 4091 4251 4244 26495 26454)
#include <Defines.h>
#include <Standard.h>
#include <engine_vector.h>
#include <engine_io.h>
#include <straw.h>
#include <Vector3.h>
#include <da_settings.h>
#include <ReferenceableClass.h>
#include <da.h>
#pragma warning(pop) 
#pragma managed(pop)

#pragma managed(push, off)

namespace RenSharp
{
	template<typename Tag, typename Tag::type M>
	struct Rob
	{
		friend typename Tag::type get(Tag)
		{
			return M;
		}
	};
}

#pragma managed(pop)