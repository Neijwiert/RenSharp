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

#include "IUnmanagedAttachable.h"
#include "Mda_player.h"

#pragma managed(push, off)

class DAPlayerDataClass;

#pragma managed(pop)

using namespace System;

namespace RenSharp
{
	interface class IRenSharpPlayerDataFactoryClass;

	interface class IcPlayer;
	interface class ISoldierGameObj;

	public interface class IRenSharpPlayerDataClass : public IUnmanagedAttachable<IDAPlayerDataClass^>
	{
		void Init();

		void ClearLevel();

		void ClearSession();

		property IntPtr DAPlayerDataClassPointer
		{
			IntPtr get();
		}

		property IcPlayer^ Owner
		{
			IcPlayer^ get();
			void set(IcPlayer^ value);
		}

		property IDAPlayerDataFactoryClass^ Factory
		{
			IDAPlayerDataFactoryClass^ get();
			void set(IDAPlayerDataFactoryClass^ value);
		}

		property int ID
		{
			int get();
		}

		property String^ Name
		{
			String^ get();
		}

		property ISoldierGameObj^ GameObj
		{
			ISoldierGameObj^ get();
		}

		property int Team
		{
			int get();
		}
	};

	public ref class RenSharpPlayerDataClass abstract : public IRenSharpPlayerDataClass
	{
		private:
			bool disposedResources;
			bool destroyPointer;
			IntPtr daPlayerDataClassPointer;
			IDAPlayerDataClass^ daPlayerDataClass;

		public:
			RenSharpPlayerDataClass();
			~RenSharpPlayerDataClass();
			!RenSharpPlayerDataClass();

			String^ ToString() override;
			bool Equals(Object^ other) override;
			int GetHashCode() override sealed;

			virtual void InitUnmanagedAttachable() sealed;
			virtual void AttachToUnmanagedObject() sealed;
			virtual void RegisterManagedObject() sealed;
			virtual void ReleasePointer() sealed;
			virtual void UnmanagedAttach();
			virtual void ManagedRegistered();
			virtual IDAPlayerDataClass^ AsUnmanagedObject() sealed;

			virtual void Init();
			virtual void ClearLevel();
			virtual void ClearSession();

			property IntPtr DAPlayerDataClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr Pointer
			{
				virtual IntPtr get() sealed;
			}
	
			property bool IsAttached
			{
				virtual bool get() sealed;
			}

			property bool IsRegistered
			{
				virtual bool get() sealed;
			}

			property bool DestroyPointer
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property IcPlayer^ Owner
			{
				virtual IcPlayer^ get() sealed;
				virtual void set(IcPlayer^ value) sealed;
			}

			property IDAPlayerDataFactoryClass^ Factory
			{
				virtual IDAPlayerDataFactoryClass^ get() sealed;
				virtual void set(IDAPlayerDataFactoryClass^ value) sealed;
			}

			property int ID
			{
				virtual int get() sealed;
			}

			property String^ Name
			{
				virtual String^ get() sealed;
			}

			property ISoldierGameObj^ GameObj
			{
				virtual ISoldierGameObj^ get() sealed;
			}

			property int Team
			{
				virtual int get() sealed;
			}

		protected:
			property ::DAPlayerDataClass* InternalDAPlayerDataClassPointer
			{
				virtual ::DAPlayerDataClass* get();
			}
	};
}