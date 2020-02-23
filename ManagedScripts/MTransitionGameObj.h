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

#include "MBaseGameObj.h"

#pragma managed(push, off)

class TransitionGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class ITransitionGameObjDef;
	value class Matrix3D;
	interface class ITransitionInstanceClass;

	public interface class ITransitionGameObj : public IBaseGameObj
	{
		ITransitionInstanceClass^ GetTransition(int trans);

		property IntPtr TransitionGameObjPointer
		{
			IntPtr get();
		}

		property ITransitionGameObjDef^ Definition
		{
			ITransitionGameObjDef^ get();
		}

		property Matrix3D Transform
		{
			Matrix3D get();
			void set(Matrix3D value);
		}

		property int TransitionCount
		{
			int get();
		}

		property int LadderIndex
		{
			int get();
		}
	};

	public ref class TransitionGameObj : public BaseGameObj, public ITransitionGameObj
	{
		public:
			TransitionGameObj(IntPtr pointer);

			virtual ITransitionInstanceClass^ GetTransition(int trans) sealed;

			property IntPtr TransitionGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

			property ITransitionGameObjDef^ Definition
			{
#pragma push_macro("new")
#undef new
				virtual ITransitionGameObjDef^ get() new sealed;
#pragma pop_macro("new")
			}

			property Matrix3D Transform
			{
				virtual Matrix3D get() sealed;
				virtual void set(Matrix3D value) sealed;
			}

			property int TransitionCount
			{
				virtual int get() sealed;
			}

			property int LadderIndex
			{
				virtual int get() sealed;
			}

		protected:
			property ::PostLoadableClass* InternalPostLoadableClassPointer
			{
				::PostLoadableClass* get() override;
			}

			property ::PersistClass* InternalPersistClassPointer
			{
				::PersistClass* get() override;
			}

			property ::BaseGameObj* InternalBaseGameObjPointer
			{
				::BaseGameObj* get() override;
			}

			property ::TransitionGameObj* InternalTransitionGameObjPointer
			{
				virtual ::TransitionGameObj* get();
			}
	};
}