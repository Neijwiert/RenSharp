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

#include "Mda_gameobj.h"
#include "Mda_event.h"
#include "Mengine_vector.h"

#pragma managed(push, off)

class DATeleporterClass;
class DATeleporterManagerClass;

#pragma managed(pop)

namespace RenSharp
{
	value class Vector3;
	interface class IINIClass;

	public interface class IDATeleporterClass : public IDAGameObjObserverClass
	{
		void TeleportPlayer(IScriptableGameObj^ obj);

		void AddIgnoreList(IScriptableGameObj^ obj);

		void RemoveIgnoreList(IScriptableGameObj^ obj);

		bool IsInIgnoreList(IScriptableGameObj^ obj);

		property IntPtr DATeleporterClassPointer
		{
			IntPtr get();
		}

		property IDynamicVectorClass<Vector3>^ Spawners
		{
			IDynamicVectorClass<Vector3>^ get();
		}

		property bool IsEnabled
		{
			bool get();
			void set(bool value);
		}

		property int Team
		{
			int get();
			void set(int value);
		}

		property String^ Group
		{
			String^ get();
		}

		property String^ TeleporterName
		{
			String^ get();
		}
	};

	public ref class DATeleporterClass : public DAGameObjObserverClass, public IDATeleporterClass
	{
		public:
			DATeleporterClass(IntPtr pointer);

			virtual void TeleportPlayer(IScriptableGameObj^ obj) sealed;
			virtual void AddIgnoreList(IScriptableGameObj^ obj) sealed;
			virtual void RemoveIgnoreList(IScriptableGameObj^ obj) sealed;
			virtual bool IsInIgnoreList(IScriptableGameObj^ obj) sealed;

			property IntPtr DATeleporterClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDynamicVectorClass<Vector3>^ Spawners
			{
				virtual IDynamicVectorClass<Vector3>^ get() sealed;
			}

			property bool IsEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int Team
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property String^ Group
			{
				virtual String^ get() sealed;
			}

			property String^ TeleporterName
			{
				virtual String^ get() sealed;
			}

		protected:
			property ::DAGameObjObserverClass* InternalDAGameObjObserverClassPointer
			{
				::DAGameObjObserverClass* get() override;
			}

			property ::DATeleporterClass* InternalDATeleporterClassPointer
			{
				virtual ::DATeleporterClass* get();
			}
	};

	public interface class IDATeleporterManagerClass : public IDASingleton<IDATeleporterManagerClass^>
	{
		IDATeleporterClass^ CreateTeleporter(IINIClass^ ini, String^ header);

		IDATeleporterClass^ FindTeleporter(String^ group);

		property IntPtr DATeleporterManagerClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DATeleporterManagerClass : public DASingleton<IDATeleporterManagerClass^>, public IDATeleporterManagerClass
	{
		public:
			DATeleporterManagerClass(IntPtr pointer);

			static IDATeleporterManagerClass^ CreateInstance();
			static void DestroyInstance();

			bool Equals(Object^ other) override;

			virtual IDATeleporterClass^ CreateTeleporter(IINIClass^ ini, String^ header) sealed;
			virtual IDATeleporterClass^ FindTeleporter(String^ group) sealed;

			static property IDATeleporterManagerClass^ Instance
			{
				IDATeleporterManagerClass^ get();
			}

			property IntPtr DATeleporterManagerClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DATeleporterManagerClass* InternalDATeleporterManagerClassPointer
			{
				virtual ::DATeleporterManagerClass* get();
			}
	};
}