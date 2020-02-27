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

#include "stdafx.h"
#include "MObserverImpClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <ObserverImpClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	ObserverImpClass::ObserverImpClass(String^ name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("command");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			Pointer = IntPtr(Imports::CreateObserverImpClass(
				reinterpret_cast<char*>(nameHandle.ToPointer())));
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	ObserverImpClass::ObserverImpClass(IntPtr pointer)
		: GameObjObserverClass(pointer)
	{

	}

	IUnmanagedContainer<IGameObjObserverClass^>^ ObserverImpClass::CreateObserverImpClass(String^ name)
	{
		return gcnew UnmanagedContainer<IGameObjObserverClass^>(gcnew ObserverImpClass(name));
	}

	IntPtr ObserverImpClass::ObserverImpClassPointer::get()
	{
		return IntPtr(InternalObserverImpClassPointer);
	}

	::GameObjObserverClass* ObserverImpClass::InternalGameObjObserverClassPointer::get()
	{
		return InternalObserverImpClassPointer;
	}

	::ObserverImpClass* ObserverImpClass::InternalObserverImpClassPointer::get()
	{
		return reinterpret_cast<::ObserverImpClass*>(Pointer.ToPointer());
	}
}