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

#include "Mda_gameobj.h"
#include "IUnmanagedContainer.h"

#pragma managed(push, off)

class DATimedInvincibilityObserverClass;
class DAAttachToObjectWithZOffsetObserverClass;
class DANoPointsUntilEnteredObserverClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IDATimedInvincibilityObserverClass : public IDAGameObjObserverClass
	{
		property IntPtr DATimedInvincibilityObserverClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DATimedInvincibilityObserverClass : public DAGameObjObserverClass, public IDATimedInvincibilityObserverClass
	{
		private:
			DATimedInvincibilityObserverClass(TimeSpan protectTime);

		public:
			DATimedInvincibilityObserverClass(IntPtr pointer);

			static IUnmanagedContainer<IDATimedInvincibilityObserverClass^>^ CreateDATimedInvincibilityObserverClass(TimeSpan protectTime);

			property IntPtr DATimedInvincibilityObserverClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DAGameObjObserverClass* InternalDAGameObjObserverClassPointer
			{
				::DAGameObjObserverClass* get() override;
			}

			property ::DATimedInvincibilityObserverClass* InternalDATimedInvincibilityObserverClassPointer
			{
				virtual ::DATimedInvincibilityObserverClass* get();
			}
	};

	public interface class IDAAttachToObjectWithZOffsetObserverClass : public IDAGameObjObserverClass
	{
		property IntPtr DAAttachToObjectWithZOffsetObserverClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DAAttachToObjectWithZOffsetObserverClass : public DAGameObjObserverClass, public IDAAttachToObjectWithZOffsetObserverClass
	{
		private:
			DAAttachToObjectWithZOffsetObserverClass(IScriptableGameObj^ host, float offset, TimeSpan syncTime);

		public:
			DAAttachToObjectWithZOffsetObserverClass(IntPtr pointer);

			static IUnmanagedContainer<IDAAttachToObjectWithZOffsetObserverClass^>^ CreateDAAttachToObjectWithZOffsetObserverClass(IScriptableGameObj^ host, float offset, TimeSpan syncTime);

			property IntPtr DAAttachToObjectWithZOffsetObserverClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DAGameObjObserverClass* InternalDAGameObjObserverClassPointer
			{
				::DAGameObjObserverClass* get() override;
			}

			property ::DAAttachToObjectWithZOffsetObserverClass* InternalDAAttachToObjectWithZOffsetObserverClassPointer
			{
				virtual ::DAAttachToObjectWithZOffsetObserverClass* get();
			}
	};

	public interface class IDANoPointsUntilEnteredObserverClass : public IDAGameObjObserverClass
	{
		property IntPtr DANoPointsUntilEnteredObserverClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DANoPointsUntilEnteredObserverClass : public DAGameObjObserverClass, public IDANoPointsUntilEnteredObserverClass
	{
		private:
			DANoPointsUntilEnteredObserverClass();

		public:
			DANoPointsUntilEnteredObserverClass(IntPtr pointer);

			static IUnmanagedContainer<IDANoPointsUntilEnteredObserverClass^>^ CreateDANoPointsUntilEnteredObserverClass();

			property IntPtr DANoPointsUntilEnteredObserverClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DAGameObjObserverClass* InternalDAGameObjObserverClassPointer
			{
				::DAGameObjObserverClass* get() override;
			}

			property ::DANoPointsUntilEnteredObserverClass* InternalDANoPointsUntilEnteredObserverClassPointer
			{
				virtual ::DANoPointsUntilEnteredObserverClass* get();
			}
	};
}