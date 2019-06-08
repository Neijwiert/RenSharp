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

#include "IUnmanagedObject.h"
#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"

#pragma managed(push, off)

struct ConnectionRequest;

#pragma managed(pop)

using namespace System::Net;

namespace RenSharp
{
	public interface class IConnectionRequest : public IUnmanagedObject
	{
		property IntPtr ConnectionRequestPointer
		{
			IntPtr get();
		}

		property int ClientID
		{
			int get();
			void set(int value);
		}

		property IPEndPoint ^ClientAddress
		{
			IPEndPoint ^get();
			void set(IPEndPoint ^value);
		}

		property String ^ClientName
		{
			String ^get();
			void set(String ^value);
		}

		property int ClientExeKey
		{
			int get();
			void set(int value);
		}

		property String ^ClientSerialHash
		{
			String ^get();
			void set(String ^value);
		}

		property float ClientVersion
		{
			float get();
			void set(float value);
		}

		property uint ClientRevisionNumber
		{
			uint get();
			void set(uint value);
		}

		property String ^Password
		{
			String ^get();
			void set(String ^value);
		}
	};

	public ref class ConnectionRequest : public AbstractUnmanagedObject, public IConnectionRequest
	{
		private:
			ConnectionRequest();

		public:
			ConnectionRequest(IntPtr pointer);

			bool Equals(Object ^other) override;

			static IUnmanagedContainer<IConnectionRequest ^> ^CreateConnectionRequest();

			property IntPtr ConnectionRequestPointer
			{
				virtual IntPtr get() sealed;
			}

			property int ClientID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property IPEndPoint ^ClientAddress
			{
				virtual IPEndPoint ^get() sealed;
				virtual void set(IPEndPoint ^value) sealed;
			}

			property String ^ClientName
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property int ClientExeKey
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property String ^ClientSerialHash
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property float ClientVersion
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property uint ClientRevisionNumber
			{
				virtual uint get() sealed;
				virtual void set(uint value) sealed;
			}

			property String ^Password
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::ConnectionRequest *InternalConnectionRequestPointer
			{
				virtual ::ConnectionRequest *get();
			}
	};
}