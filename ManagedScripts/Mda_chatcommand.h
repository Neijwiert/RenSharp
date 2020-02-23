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

#include "Mda_event.h"
#include "Mengine_vector.h"

#pragma managed(push, off)

class DAChatCommandClass;
struct DAEventChatCommandStruct;
class DAKeyHookClass;
struct DAEventKeyHookStruct;
class DAChatCommandManager;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IDAChatCommandClass : public IUnmanagedObject
	{
		bool Activate(IcPlayer^ player, IDATokenClass^ text, TextMessageEnum chatType);

		property IntPtr DAChatCommandClassPointer
		{
			IntPtr get();
		}

		property IDynamicVectorClass<String^>^ Triggers
		{
			IDynamicVectorClass<String^>^ get();
			void set(IDynamicVectorClass<String^>^ value);
		}

		property DAAccessLevel AccessLevel
		{
			DAAccessLevel get();
			void set(DAAccessLevel value);
		}

		property DAChatType ChatType
		{
			DAChatType get();
			void set(DAChatType value);
		}

		property int Parameters
		{
			int get();
			void set(int value);
		}
	};

	public ref class DAChatCommandClass : public AbstractUnmanagedObject, public IDAChatCommandClass
	{
		public:
			DAChatCommandClass(IntPtr pointer);

			bool Equals(Object^ other) override;

			virtual bool Activate(IcPlayer^ player, IDATokenClass^ text, TextMessageEnum chatType) sealed;

			property IntPtr DAChatCommandClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDynamicVectorClass<String^>^ Triggers
			{
				virtual IDynamicVectorClass<String^>^ get() sealed;
				virtual void set(IDynamicVectorClass<String^>^ value) sealed;
			}

			property DAAccessLevel AccessLevel
			{
				virtual DAAccessLevel get() sealed;
				virtual void set(DAAccessLevel value) sealed;
			}

			property DAChatType ChatType
			{
				virtual DAChatType get() sealed;
				virtual void set(DAChatType value) sealed;
			}

			property int Parameters
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DAChatCommandClass* InternalDAChatCommandClassPointer
			{
				virtual ::DAChatCommandClass* get();
			}
	};

	public interface class IDAEventChatCommandStruct : public IUnmanagedObject
	{
		bool Invoke(IDAEventClass^ base, IcPlayer^ player, IDATokenClass^ text, TextMessageEnum chatType);

		property IntPtr DAEventChatCommandStructPointer
		{
			IntPtr get();	
		}

		property IDynamicVectorClass<String^>^ Triggers
		{
			IDynamicVectorClass<String^>^ get();
			void set(IDynamicVectorClass<String^>^ value);
		}

		property DAAccessLevel AccessLevel
		{
			DAAccessLevel get();
			void set(DAAccessLevel value);
		}

		property DAChatType ChatType
		{
			DAChatType get();
			void set(DAChatType value);
		}

		property int Parameters
		{
			int get();
			void set(int value);
		}

		property IDAEventClass^ Base
		{
			IDAEventClass^ get();
			void set(IDAEventClass^ value);
		}
	};

	public ref class DAEventChatCommandStruct : public AbstractUnmanagedObject, public IDAEventChatCommandStruct
	{
		private:
			DAEventChatCommandStruct();

		public:
			DAEventChatCommandStruct(IntPtr pointer);

			static IUnmanagedContainer<IDAEventChatCommandStruct^>^ CreateDAEventChatCommandStruct();

			bool Equals(Object^ other) override;

			virtual bool Invoke(IDAEventClass^ base, IcPlayer^ player, IDATokenClass^ text, TextMessageEnum chatType) sealed;

			property IntPtr DAEventChatCommandStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDynamicVectorClass<String^>^ Triggers
			{
				virtual IDynamicVectorClass<String^>^ get() sealed;
				virtual void set(IDynamicVectorClass<String^>^ value) sealed;
			}

			property DAAccessLevel AccessLevel
			{
				virtual DAAccessLevel get() sealed;
				virtual void set(DAAccessLevel value) sealed;
			}

			property DAChatType ChatType
			{
				virtual DAChatType get() sealed;
				virtual void set(DAChatType value) sealed;
			}

			property int Parameters
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property IDAEventClass^ Base
			{
				virtual IDAEventClass^ get() sealed;
				virtual void set(IDAEventClass^ value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DAEventChatCommandStruct* InternalDAEventChatCommandStructPointer
			{
				virtual ::DAEventChatCommandStruct* get();
			}
	};

	public interface class IDAKeyHookClass : public IUnmanagedObject
	{
		void Activate(IcPlayer^ player);

		property IntPtr DAKeyHookClassPointer
		{
			IntPtr get();
		}

		property IDynamicVectorClass<String^>^ Triggers
		{
			IDynamicVectorClass<String^>^ get();
			void set(IDynamicVectorClass<String^>^ value);
		}
	};

	public ref class DAKeyHookClass : public AbstractUnmanagedObject, public IDAKeyHookClass
	{
		public:
			DAKeyHookClass(IntPtr pointer);

			bool Equals(Object^ other) override;

			virtual void Activate(IcPlayer^ player) sealed;

			property IntPtr DAKeyHookClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDynamicVectorClass<String^>^ Triggers
			{
				virtual IDynamicVectorClass<String^>^ get() sealed;
				virtual void set(IDynamicVectorClass<String^>^ value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DAKeyHookClass* InternalDAKeyHookClassPointer
			{
				virtual ::DAKeyHookClass* get();
			}
	};

	public interface class IDAEventKeyHookStruct : public IUnmanagedObject
	{
		void Invoke(IDAEventClass^ base, IcPlayer^ player);

		property IntPtr DAEventKeyHookStructPointer
		{
			IntPtr get();
		}

		property IDynamicVectorClass<String^>^ Triggers
		{
			IDynamicVectorClass<String^>^ get();
			void set(IDynamicVectorClass<String^>^ value);
		}

		property IDAEventClass^ Base
		{
			IDAEventClass^ get();
			void set(IDAEventClass^ value);
		}
	};

	public ref class DAEventKeyHookStruct : public AbstractUnmanagedObject, public IDAEventKeyHookStruct
	{
		private:
			DAEventKeyHookStruct();

		public:
			DAEventKeyHookStruct(IntPtr pointer);

			static IUnmanagedContainer<IDAEventKeyHookStruct^>^ CreateDAEventKeyHookStruct();

			bool Equals(Object^ other) override;

			virtual void Invoke(IDAEventClass^ base, IcPlayer^ player) sealed;

			property IntPtr DAEventKeyHookStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDynamicVectorClass<String^>^ Triggers
			{
				virtual IDynamicVectorClass<String^>^ get() sealed;
				virtual void set(IDynamicVectorClass<String^>^ value) sealed;
			}

			property IDAEventClass^ Base
			{
				virtual IDAEventClass^ get() sealed;
				virtual void set(IDAEventClass^ value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DAEventKeyHookStruct* InternalDAEventKeyHookStructPointer
			{
				virtual ::DAEventKeyHookStruct* get();
			}
	};

	public interface class IDAChatCommandManager : public IDAEventClass
	{
		property IntPtr DAChatCommandManagerPointer
		{
			IntPtr get();
		}
	};

	public ref class DAChatCommandManager : public DAEventClass, public IDAChatCommandManager
	{
		// Although you can instantiate a DAChatCommandManager class, it doesn't make any sense so I left it out
		public:
			DAChatCommandManager(IntPtr pointer);

			static void RegisterChatCommand(IDAChatCommandClass^ base, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType);
			static void RegisterChatCommand(IDAChatCommandClass^ base, String^ triggers, int parameters, DAAccessLevel accessLevel);
			static void RegisterChatCommand(IDAChatCommandClass^ base, String^ triggers, int parameters);
			static void RegisterChatCommand(IDAChatCommandClass^ base, String^ triggers);
			static void RegisterKeyHook(IDAKeyHookClass^ base, String^ triggers);
			static void UnregisterChatCommand(String^ trigger);
			static void UnregisterEventChatCommand(IDAEventClass^ base, String^ trigger);
			static void UnregisterKeyHook(String^ trigger);
			static void UnregisterEventKeyHook(IDAEventClass^ base, String^ trigger);
			static void ClearEventChatCommands(IDAEventClass^ base);
			static void ClearEventKeyHooks(IDAEventClass^ base);

			property IntPtr DAChatCommandManagerPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DAChatCommandManager* InternalDAChatCommandManagerPointer
			{
				virtual ::DAChatCommandManager* get();
			}
	};
}