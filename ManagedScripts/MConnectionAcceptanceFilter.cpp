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
#include "MConnectionAcceptanceFilter.h"

#include "MConnectionRequest.h"

#include "Imports.h"

using namespace System::Runtime::InteropServices;

namespace RenSharp
{
	ConnectionAcceptanceFilter::ConnectionAcceptanceFilter(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool ConnectionAcceptanceFilter::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IConnectionAcceptanceFilter^ otherThis = dynamic_cast<IConnectionAcceptanceFilter^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return ConnectionAcceptanceFilterPointer.Equals(otherThis->ConnectionAcceptanceFilterPointer);
	}

	void ConnectionAcceptanceFilter::HandleInitiation(IConnectionRequest^ connectionRequest)
	{
		if (connectionRequest == nullptr || connectionRequest->ConnectionRequestPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("connectionRequest");
		}

		InternalConnectionAcceptanceFilterPointer->handleInitiation(
			*reinterpret_cast<::ConnectionRequest*>(connectionRequest->ConnectionRequestPointer.ToPointer()));
	}

	void ConnectionAcceptanceFilter::HandleTermination(IConnectionRequest^ connectionRequest)
	{
		if (connectionRequest == nullptr || connectionRequest->ConnectionRequestPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("connectionRequest");
		}

		InternalConnectionAcceptanceFilterPointer->handleTermination(
			*reinterpret_cast<::ConnectionRequest*>(connectionRequest->ConnectionRequestPointer.ToPointer()));
	}

	void ConnectionAcceptanceFilter::HandleCancellation(IConnectionRequest^ connectionRequest)
	{
		if (connectionRequest == nullptr || connectionRequest->ConnectionRequestPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("connectionRequest");
		}

		InternalConnectionAcceptanceFilterPointer->handleCancellation(
			*reinterpret_cast<::ConnectionRequest*>(connectionRequest->ConnectionRequestPointer.ToPointer()));
	}

	ConnectionAcceptanceFilterStatus ConnectionAcceptanceFilter::GetStatus(IConnectionRequest^ connectionRequest, String^% refusalMessage)
	{
		if (connectionRequest == nullptr || connectionRequest->ConnectionRequestPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("connectionRequest");
		}
		else if (refusalMessage == nullptr)
		{
			throw gcnew ArgumentNullException("refusalMessage");
		}

		IntPtr refusalMessageHandle = Marshal::StringToHGlobalUni(refusalMessage);
		try
		{
			::WideStringClass tmp(reinterpret_cast<wchar_t*>(refusalMessageHandle.ToPointer()));

			auto result = InternalConnectionAcceptanceFilterPointer->getStatus(
				*reinterpret_cast<::ConnectionRequest*>(connectionRequest->ConnectionRequestPointer.ToPointer()),
				tmp);

			refusalMessage = gcnew String(tmp.Peek_Buffer());

			return static_cast<ConnectionAcceptanceFilterStatus>(result);
		}
		finally
		{
			Marshal::FreeHGlobal(refusalMessageHandle);
		}
	}

	IntPtr ConnectionAcceptanceFilter::ConnectionAcceptanceFilterPointer::get()
	{
		return IntPtr(InternalConnectionAcceptanceFilterPointer);
	}

	bool ConnectionAcceptanceFilter::InternalDestroyPointer()
	{
		Imports::DestroyConnectionAcceptanceFilter(InternalConnectionAcceptanceFilterPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::ConnectionAcceptanceFilter* ConnectionAcceptanceFilter::InternalConnectionAcceptanceFilterPointer::get()
	{
		return reinterpret_cast<::ConnectionAcceptanceFilter*>(Pointer.ToPointer());
	}
}