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

#include "McNetEvent.h"
#include "Mengine_ttdef.h"

#pragma managed(push, off)

class cScTextObj;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IcScTextObj : public IcNetEvent
	{
		void SetDirtyBitForTeam(DirtyBit dirtyBits, int teamId);

		property IntPtr cScTextObjPointer
		{
			IntPtr get();
		}

		property int SenderId
		{
			int get();
			void set(int value);
		}

		property int ReceiverId
		{
			int get();
			void set(int value);
		}

		property TextMessageEnum Type
		{
			TextMessageEnum get();
			void set(TextMessageEnum value);
		}

		property String ^Message
		{
			String ^get();
			void set(String ^value);
		}

		property bool PopUp
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class cScTextObj : public cNetEvent, public IcScTextObj
	{
		public:
			cScTextObj(IntPtr pointer);

			virtual void SetDirtyBitForTeam(DirtyBit dirtyBits, int teamId) sealed;

			property IntPtr cScTextObjPointer
			{
				virtual IntPtr get() sealed;
			}

			property int SenderId
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int ReceiverId
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property TextMessageEnum Type
			{
				virtual TextMessageEnum get() sealed;
				virtual void set(TextMessageEnum value) sealed;
			}

			property String ^Message
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property bool PopUp
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::cNetEvent *InternalcNetEventPointer
			{
				::cNetEvent *get() override;
			}

			property ::cScTextObj *InternalcScTextObjPointer
			{
				virtual ::cScTextObj *get();
			}
	};
}