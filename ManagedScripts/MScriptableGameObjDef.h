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

#include "MBaseGameObjDef.h"
#include "Mengine_vector.h"

#pragma managed(push, off)

class ScriptableGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IScriptableGameObjDef : public IBaseGameObjDef
	{
		property IntPtr ScriptableGameObjDefPointer
		{
			IntPtr get();
		}

		property IDynamicVectorClass<String ^> ^ScriptNameList
		{
			IDynamicVectorClass<String ^> ^get();
			void set(IDynamicVectorClass<String ^> ^value);
		}

		property IDynamicVectorClass<String ^> ^ScriptParameterList
		{
			IDynamicVectorClass<String ^> ^get();
			void set(IDynamicVectorClass<String ^> ^value);
		}
	};

	public ref class ScriptableGameObjDef : public BaseGameObjDef, public IScriptableGameObjDef
	{
		public:
			ScriptableGameObjDef(IntPtr pointer);

			property IntPtr ScriptableGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDynamicVectorClass<String ^> ^ScriptNameList
			{
				virtual IDynamicVectorClass<String ^> ^get() sealed;
				virtual void set(IDynamicVectorClass<String ^> ^value) sealed;
			}

			property IDynamicVectorClass<String ^> ^ScriptParameterList
			{
				virtual IDynamicVectorClass<String ^> ^get() sealed;
				virtual void set(IDynamicVectorClass<String ^> ^value) sealed;
			}

		protected:
			property ::BaseGameObjDef *InternalBaseGameObjDefPointer
			{
				::BaseGameObjDef *get() override;
			}

			property ::ScriptableGameObjDef *InternalScriptableGameObjDefPointer
			{
				virtual ::ScriptableGameObjDef *get();
			}
	};
}