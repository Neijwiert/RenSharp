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

#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"
#include "Mengine_vector.h"
#include "Mscripts.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <ConversationClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	interface class IPhysicalGameObj;
	value class Vector3;

	public interface class IConversationRemarkClass : public IUnmanagedObject
	{
		property IntPtr ConversationRemarkClassPointer
		{
			IntPtr get();
		}

		property int OratorID
		{
			int get();
			void set(int value);
		}

		property uint32 TextID
		{
			uint32 get();
			void set(uint32 value);
		}

		property String^ AnimationName
		{
			String^ get();
			void set(String^ value);
		}
	};

	public ref class ConversationRemarkClass : public AbstractUnmanagedObject, public IConversationRemarkClass
	{
		private:
			ConversationRemarkClass();

		public:
			ConversationRemarkClass(IntPtr pointer);

			static IUnmanagedContainer<IConversationRemarkClass^>^ CreateConversationRemarkClass();

			bool Equals(Object^ other) override;

			property IntPtr ConversationRemarkClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int OratorID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property uint32 TextID
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

			property String^ AnimationName
			{
				virtual String^ get() sealed;
				virtual void set(String^ value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::ConversationRemarkClass* InternalConversationRemarkClassPointer
			{
				virtual ::ConversationRemarkClass* get();
			}
	};

	public interface class IOratorClass : public IUnmanagedObject
	{
		[Flags]
		enum class OratorFlags : int
		{
			FlagDontMove = ::OratorClass::FLAG_DONT_MOVE,
			FlagDontTurnHead = ::OratorClass::FLAG_DONT_TURN_HEAD,
			FlagTempDontFace = ::OratorClass::FLAG_TEMP_DONT_FACE,
			FlagDontFace = ::OratorClass::FLAG_DONT_FACE
		};

		bool GetFlag(int flag);

		void SetFlag(int flag, bool onoff);

		void SetFlags(int newFlags);

		void SetArrived(bool arrived);

		void Initialize(IPhysicalGameObj^ obj);

		void SetOratorID(int id);

		void SetFacingID(int id);

		property IntPtr OratorClassPointer
		{
			IntPtr get();
		}

		property IPhysicalGameObj^ GameObj
		{
			IPhysicalGameObj^ get();
		}

		property Vector3 Position
		{
			Vector3 get();
		}
	};

	public ref class OratorClass : public AbstractUnmanagedObject, public IOratorClass
	{
		private:
			OratorClass();

		public:
			OratorClass(IntPtr pointer);

			static IUnmanagedContainer<IOratorClass^>^ CreateOratorClass();

			bool Equals(Object^ other) override;

			virtual bool GetFlag(int flag) sealed;
			virtual void SetFlag(int flag, bool onoff) sealed;
			virtual void SetFlags(int newFlags) sealed;
			virtual void SetArrived(bool arrived) sealed;
			virtual void Initialize(IPhysicalGameObj^ obj) sealed;
			virtual void SetOratorID(int id) sealed;
			virtual void SetFacingID(int id) sealed;

			property IntPtr OratorClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IPhysicalGameObj^ GameObj
			{
				virtual IPhysicalGameObj^ get() sealed;
			}

			property Vector3 Position
			{
				virtual Vector3 get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::OratorClass* InternalOratorClassPointer
			{
				virtual ::OratorClass* get();
			}
	};

	public interface class IConversationClass : public IRefCountClass
	{
		IUnmanagedContainer<IConversationRemarkClass^>^ GetRemarkInfo(int index);

		property IntPtr ConversationClassPointer
		{
			IntPtr get();
		}

		property int OratorCount
		{
			int get();
		}

		property int RemarkCount
		{
			int get();
		}

		property int ID
		{
			int get();
			void set(int value);
		}

		property String^ Name
		{
			String^ get();
			void set(String^ value);
		}

		property SoldierAIState AIState
		{
			SoldierAIState get();
			void set(SoldierAIState value);
		}

		property bool IsInnate
		{
			bool get();
			void set(bool value);
		}

		property bool IsKey
		{
			bool get();
			void set(bool value);
		}

		property float Probability
		{
			float get();
			void set(float value);
		}

		property int CategoryID
		{
			int get();
			void set(int value);
		}

		property int LookAtObjID
		{
			int get();
			void set(int value);
		}

		property int Priority
		{
			int get();
			void set(int value);
		}

		property float MaxDist
		{
			float get();
			void set(float value);
		}

		property bool IsInterruptable
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class ConversationClass : public RefCountClass, public IConversationClass
	{
		public:
			ConversationClass(IntPtr pointer);

			String^ ToString() override;

			virtual IUnmanagedContainer<IConversationRemarkClass^>^ GetRemarkInfo(int index) sealed;

			property IntPtr ConversationClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int OratorCount
			{
				virtual int get() sealed;
			}

			property int RemarkCount
			{
				virtual int get() sealed;
			}

			property int ID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property String^ Name
			{
				virtual String^ get() sealed;
				virtual void set(String^ value) sealed;
			}

			property SoldierAIState AIState
			{
				virtual SoldierAIState get() sealed;
				virtual void set(SoldierAIState value) sealed;
			}

			property bool IsInnate
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsKey
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property float Probability
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int CategoryID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int LookAtObjID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int Priority
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float MaxDist
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool IsInterruptable
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::RefCountClass* InternalRefCountClassPointer
			{
				::RefCountClass* get() override;
			}

			property ::ConversationClass* InternalConversationClassPointer
			{
				virtual ::ConversationClass* get();
			}
	};
}