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

#include "MScriptableGameObj.h"

#pragma managed(push, off)

class ScriptZoneGameObj;

#pragma managed(pop)

namespace RenSharp
{

#pragma warning(push)
#pragma warning(disable : 4099 4251 4244 26495 26454)

	interface class IScriptZoneGameObjDef;
	value class Vector3;
	value class OBBoxClass;

#pragma warning(pop) 

	public interface class IScriptZoneGameObj : public IScriptableGameObj
	{
		property IntPtr ScriptZoneGameObjPointer
		{
			IntPtr get();
		}

		property IScriptZoneGameObjDef ^Definition
		{
			IScriptZoneGameObjDef ^get();
		}

		property OBBoxClass BoundingBox
		{
			OBBoxClass get();
			void set(OBBoxClass value);
		}

		property int PlayerType
		{
			int get();
			void set(int value);
		}

		property bool IsEnvironmentZone
		{
			bool get();
		}
	};

	public ref class ScriptZoneGameObj : public ScriptableGameObj, public IScriptZoneGameObj
	{
		public:
			ScriptZoneGameObj(IntPtr pointer);

			IScriptZoneGameObj ^AsScriptZoneGameObj() override;

			property IntPtr ScriptZoneGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

#pragma push_macro("new")
#undef new

			property IScriptZoneGameObjDef ^Definition
			{
				virtual IScriptZoneGameObjDef ^get() new sealed;
			}

#pragma pop_macro("new")

			property OBBoxClass BoundingBox
			{
				virtual OBBoxClass get() sealed;
				virtual void set(OBBoxClass value) sealed;
			}

			property int PlayerType
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool IsEnvironmentZone
			{
				virtual bool get() sealed;
			}

		protected:
			property ::ScriptableGameObj *InternalScriptableGameObjPointer
			{
				::ScriptableGameObj *get() override;
			}

			property ::ScriptZoneGameObj *InternalScriptZoneGameObjPointer
			{
				virtual ::ScriptZoneGameObj *get();
			}
	};
}