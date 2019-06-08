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

#include "Mscripts.h"

#pragma managed(push, off)

class SafeActionParamsStruct;

#pragma managed(pop)

namespace RenSharp
{
	interface class IReferencerClass;
	interface class ISmartGameObj;

	public interface class ISafeActionParamsStruct : public IActionParamsStruct
	{
		void SetAnimation(String ^name, bool looping);

		void StartConversation(String ^name);

		property IntPtr SafeActionParamsStructPointer
		{
			IntPtr get();
		}

		property String ^AnimationName
		{
			String ^get();
			void set(String ^value);
		}

		property String ^ConversationName
		{
			String ^get();
			void set(String ^value);
		}

		property IReferencerClass ^MoveObjectRef
		{
			IReferencerClass ^get();
			void set(IReferencerClass ^value);
		}

		property IReferencerClass ^AttackObjectRef
		{
			IReferencerClass ^get();
			void set(IReferencerClass ^value);
		}

		property IReferencerClass ^LookObjectRef
		{
			IReferencerClass ^get();
			void set(IReferencerClass ^value);
		}

		property String ^SafeAnimationName
		{
			String ^get();
			void set(String ^value);
		}

		property String ^SafeConversationName
		{
			String ^get();
			void set(String ^value);
		}
	};

	public ref class SafeActionParamsStruct : public ActionParamsStructRef, public ISafeActionParamsStruct
	{
		private:
			SafeActionParamsStruct();
			SafeActionParamsStruct(ActionParamsStruct ^params);

		public:
			SafeActionParamsStruct(IntPtr pointer);

			static IUnmanagedContainer<ISafeActionParamsStruct ^> ^CreateSafeActionParamsStruct();
			static IUnmanagedContainer<ISafeActionParamsStruct ^> ^CreateSafeActionParamsStruct(ActionParamsStruct ^params);

			virtual void SetAnimation(String ^name, bool looping) sealed;
			virtual void StartConversation(String ^name) sealed;

			property IntPtr SafeActionParamsStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property IScriptableGameObj ^LookObject
			{
				IScriptableGameObj ^get() override;
				void set(IScriptableGameObj ^value) override;
			}

			property IScriptableGameObj ^MoveObject
			{
				IScriptableGameObj ^get() override;
				void set(IScriptableGameObj ^value) override;
			}

			property IScriptableGameObj ^AttackObject
			{
				IScriptableGameObj ^get() override;
				void set(IScriptableGameObj ^value) override;
			}

			property String ^AnimationName
			{
				virtual String ^get() override;
				virtual void set(String ^value)  sealed;
			}

			property String ^ConversationName
			{
				virtual String ^get() override;
				virtual void set(String ^value)  sealed;
			}

			property IReferencerClass ^MoveObjectRef
			{
				virtual IReferencerClass ^get() sealed;
				virtual void set(IReferencerClass ^value) sealed;
			}

			property IReferencerClass ^AttackObjectRef
			{
				virtual IReferencerClass ^get() sealed;
				virtual void set(IReferencerClass ^value) sealed;
			}

			property IReferencerClass ^LookObjectRef
			{
				virtual IReferencerClass ^get() sealed;
				virtual void set(IReferencerClass ^value) sealed;
			}

			property String ^SafeAnimationName
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property String ^SafeConversationName
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::ActionParamsStruct *InternalActionParamsStructPointer
			{
				::ActionParamsStruct *get() override;
			}

			property ::SafeActionParamsStruct *InternalSafeActionParamsStructPointer
			{
				virtual ::SafeActionParamsStruct *get();
			}
	};

	public interface class IActionClass : public IUnmanagedObject
	{
		property IntPtr ActionClassPointer
		{
			IntPtr get();
		}

		property ISmartGameObj ^ActionObj
		{
			ISmartGameObj ^get();
		}

		property ISafeActionParamsStruct ^Parameters
		{
			ISafeActionParamsStruct ^get();
			void set(ISafeActionParamsStruct ^value);
		}

		property bool IsActing
		{
			bool get();
		}

		property unsigned int ActCount
		{
			unsigned int get();
		}

		property bool IsPaused
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class ActionClass : public AbstractUnmanagedObject, public IActionClass
	{
		public:
			ActionClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			property IntPtr ActionClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property ISmartGameObj ^ActionObj
			{
				virtual ISmartGameObj ^get() sealed;

				protected:
					void set(ISmartGameObj ^value);
			}

			property ISafeActionParamsStruct ^Parameters
			{
				virtual ISafeActionParamsStruct ^get() sealed;
				virtual void set(ISafeActionParamsStruct ^value) sealed;
			}

			property bool IsActing
			{
				virtual bool get() sealed;
			}

			property unsigned int ActCount
			{
				virtual unsigned int get() sealed;

				protected:
					void set(unsigned int value);
			}

			property bool IsPaused
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::ActionClass *InternalActionClassPointer
			{
				virtual ::ActionClass *get();
			}

			property IntPtr ActionCode
			{
				IntPtr get();
				void set(IntPtr value);
			}
	};
}