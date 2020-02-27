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

#include "Mscripts.h"
#include "IUnmanagedContainer.h"

#pragma managed(push, off)

class ObserverImpClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IObserverImpClass : public IGameObjObserverClass
	{
		property IntPtr ObserverImpClassPointer
		{
			IntPtr get();
		}
	};

	public ref class ObserverImpClass : public GameObjObserverClass, public IGameObjObserverClass
	{
		private:
			ObserverImpClass(String^ name);

		public:
			ObserverImpClass(IntPtr pointer);

			static IUnmanagedContainer<IGameObjObserverClass^>^ CreateObserverImpClass(String^ name);

			property IntPtr ObserverImpClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::GameObjObserverClass* InternalGameObjObserverClassPointer
			{
				::GameObjObserverClass* get() override;
			}

			property ::ObserverImpClass* InternalObserverImpClassPointer
			{
				virtual ::ObserverImpClass* get();
			}
	};
}