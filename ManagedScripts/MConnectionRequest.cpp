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
#include "MConnectionRequest.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <ConnectionRequest.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "UnmanagedContainer.h"
#include "Imports.h"

using namespace System::Net::Sockets;

namespace RenSharp
{
	ConnectionRequest::ConnectionRequest()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateConnectionRequest()))
	{

	}

	ConnectionRequest::ConnectionRequest(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool ConnectionRequest::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IConnectionRequest ^otherThis = dynamic_cast<IConnectionRequest ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return ConnectionRequestPointer.Equals(otherThis->ConnectionRequestPointer);
	}

	IUnmanagedContainer<IConnectionRequest ^> ^ConnectionRequest::CreateConnectionRequest()
	{
		return gcnew UnmanagedContainer<IConnectionRequest ^>(gcnew ConnectionRequest());
	}

	IntPtr ConnectionRequest::ConnectionRequestPointer::get()
	{
		return IntPtr(InternalConnectionRequestPointer);
	}

	int ConnectionRequest::ClientID::get()
	{
		return InternalConnectionRequestPointer->clientId;
	}

	void ConnectionRequest::ClientID::set(int value)
	{
		InternalConnectionRequestPointer->clientId = value;
	}

	IPEndPoint ^ConnectionRequest::ClientAddress::get()
	{
		return gcnew IPEndPoint(InternalConnectionRequestPointer->clientAddress.sin_addr.S_un.S_addr, InternalConnectionRequestPointer->clientAddress.sin_port);
	}

	void ConnectionRequest::ClientAddress::set(IPEndPoint ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (value->AddressFamily != AddressFamily::InterNetwork)
		{
			throw gcnew ArgumentException("IPEndPoint 'value' must be of the address family InterNetwork");
		}

		InternalConnectionRequestPointer->clientAddress.sin_family = static_cast<ADDRESS_FAMILY>(AddressFamily::InterNetwork);
		InternalConnectionRequestPointer->clientAddress.sin_port = static_cast<USHORT>(value->Port);
		InternalConnectionRequestPointer->clientAddress.sin_addr.S_un.S_addr = static_cast<ULONG>(value->Address->Address);
	}

	String ^ConnectionRequest::ClientName::get()
	{
		return gcnew String(InternalConnectionRequestPointer->clientName.Peek_Buffer());
	}

	void ConnectionRequest::ClientName::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalUni(value);
		try
		{
			InternalConnectionRequestPointer->clientName = reinterpret_cast<wchar_t *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	int ConnectionRequest::ClientExeKey::get()
	{
		return InternalConnectionRequestPointer->clientExeKey;
	}

	void ConnectionRequest::ClientExeKey::set(int value)
	{
		InternalConnectionRequestPointer->clientExeKey = value;
	}

	String ^ConnectionRequest::ClientSerialHash::get()
	{
		return gcnew String(InternalConnectionRequestPointer->clientSerialHash.Peek_Buffer());
	}

	void ConnectionRequest::ClientSerialHash::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalConnectionRequestPointer->clientSerialHash = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	float ConnectionRequest::ClientVersion::get()
	{
		return InternalConnectionRequestPointer->clientVersion;
	}

	void ConnectionRequest::ClientVersion::set(float value)
	{
		InternalConnectionRequestPointer->clientVersion = value;
	}

	uint ConnectionRequest::ClientRevisionNumber::get()
	{
		return InternalConnectionRequestPointer->clientRevisionNumber;
	}

	void ConnectionRequest::ClientRevisionNumber::set(uint value)
	{
		InternalConnectionRequestPointer->clientRevisionNumber = value;
	}

	String ^ConnectionRequest::Password::get()
	{
		return gcnew String(InternalConnectionRequestPointer->password.Peek_Buffer());
	}

	void ConnectionRequest::Password::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalUni(value);
		try
		{
			InternalConnectionRequestPointer->password = reinterpret_cast<wchar_t *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	bool ConnectionRequest::InternalDestroyPointer()
	{
		Imports::DestroyConnectionRequest(InternalConnectionRequestPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::ConnectionRequest *ConnectionRequest::InternalConnectionRequestPointer::get()
	{
		return reinterpret_cast<::ConnectionRequest *>(Pointer.ToPointer());
	}
}