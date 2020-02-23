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
#include "Mda_gameobjobservers.h"

#include "Imports.h"
#include "MScriptableGameObj.h"
#include "UnmanagedContainer.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_gameobjobservers.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DATimedInvincibilityObserverClass::DATimedInvincibilityObserverClass(TimeSpan protectTime)
		: DAGameObjObserverClass(IntPtr(Imports::CreateDATimedInvincibilityObserverClass(static_cast<float>(protectTime.TotalSeconds))))
	{

	}

	DATimedInvincibilityObserverClass::DATimedInvincibilityObserverClass(IntPtr pointer)
		: DAGameObjObserverClass(pointer)
	{

	}

	IUnmanagedContainer<IDATimedInvincibilityObserverClass^>^ DATimedInvincibilityObserverClass::CreateDATimedInvincibilityObserverClass(TimeSpan protectTime)
	{
		return gcnew UnmanagedContainer<IDATimedInvincibilityObserverClass^>(gcnew DATimedInvincibilityObserverClass(protectTime));
	}

	IntPtr DATimedInvincibilityObserverClass::DATimedInvincibilityObserverClassPointer::get()
	{
		return IntPtr(InternalDATimedInvincibilityObserverClassPointer);
	}

	::DAGameObjObserverClass* DATimedInvincibilityObserverClass::InternalDAGameObjObserverClassPointer::get()
	{
		return InternalDATimedInvincibilityObserverClassPointer;
	}

	::DATimedInvincibilityObserverClass* DATimedInvincibilityObserverClass::InternalDATimedInvincibilityObserverClassPointer::get()
	{
		return reinterpret_cast<::DATimedInvincibilityObserverClass*>(Pointer.ToPointer());
	}

	DAAttachToObjectWithZOffsetObserverClass::DAAttachToObjectWithZOffsetObserverClass(IScriptableGameObj^ host, float offset, TimeSpan syncTime)
		: DAGameObjObserverClass(IntPtr(Imports::CreateDAAttachToObjectWithZOffsetObserverClass(
		((host == nullptr || host->ScriptableGameObjPointer.ToPointer() == nullptr) ? nullptr : reinterpret_cast<::ScriptableGameObj*>(host->ScriptableGameObjPointer.ToPointer())),
			offset,
			static_cast<float>(syncTime.TotalSeconds))))
	{

	}

	DAAttachToObjectWithZOffsetObserverClass::DAAttachToObjectWithZOffsetObserverClass(IntPtr pointer)
		: DAGameObjObserverClass(pointer)
	{

	}

	IUnmanagedContainer<IDAAttachToObjectWithZOffsetObserverClass^>^ DAAttachToObjectWithZOffsetObserverClass::CreateDAAttachToObjectWithZOffsetObserverClass(IScriptableGameObj^ host, float offset, TimeSpan syncTime)
	{
		return gcnew UnmanagedContainer<IDAAttachToObjectWithZOffsetObserverClass^>(gcnew DAAttachToObjectWithZOffsetObserverClass(host, offset, syncTime));
	}

	IntPtr DAAttachToObjectWithZOffsetObserverClass::DAAttachToObjectWithZOffsetObserverClassPointer::get()
	{
		return IntPtr(InternalDAAttachToObjectWithZOffsetObserverClassPointer);
	}

	::DAGameObjObserverClass* DAAttachToObjectWithZOffsetObserverClass::InternalDAGameObjObserverClassPointer::get()
	{
		return InternalDAAttachToObjectWithZOffsetObserverClassPointer;
	}

	::DAAttachToObjectWithZOffsetObserverClass* DAAttachToObjectWithZOffsetObserverClass::InternalDAAttachToObjectWithZOffsetObserverClassPointer::get()
	{
		return reinterpret_cast<::DAAttachToObjectWithZOffsetObserverClass*>(Pointer.ToPointer());
	}

	DANoPointsUntilEnteredObserverClass::DANoPointsUntilEnteredObserverClass()
		: DAGameObjObserverClass(IntPtr(Imports::CreateDANoPointsUntilEnteredObserverClass()))
	{

	}

	DANoPointsUntilEnteredObserverClass::DANoPointsUntilEnteredObserverClass(IntPtr pointer)
		: DAGameObjObserverClass(pointer)
	{

	}

	IUnmanagedContainer<IDANoPointsUntilEnteredObserverClass^>^ DANoPointsUntilEnteredObserverClass::CreateDANoPointsUntilEnteredObserverClass()
	{
		return gcnew UnmanagedContainer<IDANoPointsUntilEnteredObserverClass^>(gcnew DANoPointsUntilEnteredObserverClass());
	}

	IntPtr DANoPointsUntilEnteredObserverClass::DANoPointsUntilEnteredObserverClassPointer::get()
	{
		return IntPtr(InternalDANoPointsUntilEnteredObserverClassPointer);
	}

	::DAGameObjObserverClass* DANoPointsUntilEnteredObserverClass::InternalDAGameObjObserverClassPointer::get()
	{
		return InternalDANoPointsUntilEnteredObserverClassPointer;
	}

	::DANoPointsUntilEnteredObserverClass* DANoPointsUntilEnteredObserverClass::InternalDANoPointsUntilEnteredObserverClassPointer::get()
	{
		return reinterpret_cast<::DANoPointsUntilEnteredObserverClass*>(Pointer.ToPointer());
	}
}