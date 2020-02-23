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

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4561 4251 4244 26495 26454)
#include <ConnectionAcceptanceFilter.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	interface class IConnectionRequest;

	public enum class ConnectionAcceptanceFilterStatus : int
	{
		StatusIndeterminate = ::ConnectionAcceptanceFilter::STATUS_INDETERMINATE,
		StatusRefusing = ::ConnectionAcceptanceFilter::STATUS_REFUSING,
		StatusAccepting = ::ConnectionAcceptanceFilter::STATUS_ACCEPTING
	};

	public interface class IConnectionAcceptanceFilter : public IUnmanagedObject
	{
		void HandleInitiation(IConnectionRequest^ connectionRequest);

		void HandleTermination(IConnectionRequest^ connectionRequest);

		void HandleCancellation(IConnectionRequest^ connectionRequest);

		ConnectionAcceptanceFilterStatus GetStatus(IConnectionRequest^ connectionRequest, String^% refusalMessage);

		property IntPtr ConnectionAcceptanceFilterPointer
		{
			IntPtr get();
		}
	};

	public ref class ConnectionAcceptanceFilter : public AbstractUnmanagedObject, public IConnectionAcceptanceFilter
	{
		public:
			ConnectionAcceptanceFilter(IntPtr pointer);

			bool Equals(Object^ other) override;

			virtual void HandleInitiation(IConnectionRequest^ connectionRequest) sealed;
			virtual void HandleTermination(IConnectionRequest^ connectionRequest) sealed;
			virtual void HandleCancellation(IConnectionRequest^ connectionRequest) sealed;
			virtual ConnectionAcceptanceFilterStatus GetStatus(IConnectionRequest^ connectionRequest, String^% refusalMessage) sealed;

			property IntPtr ConnectionAcceptanceFilterPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::ConnectionAcceptanceFilter* InternalConnectionAcceptanceFilterPointer
			{
				virtual ::ConnectionAcceptanceFilter* get();
			}
	};
}