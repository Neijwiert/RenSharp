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

#include "IPriorityQueue.h"
#include "RenegadeDispatcherOperationStatus.h"

using namespace System;

namespace RenSharp
{
	ref class RenegadeDispatcher;

	public ref class BaseRenegadeDispatcherOperation abstract
	{
		private:
			RenegadeDispatcher^ dispatcher;
			std::int64_t id;
			IPriorityQueue<BaseRenegadeDispatcherOperation^>^ queue;
			RenegadeDispatcherOperationStatus status;
			std::uint32_t priority;

		public:
			BaseRenegadeDispatcherOperation(RenegadeDispatcher^ dispatcher, std::int64_t id, IPriorityQueue<BaseRenegadeDispatcherOperation^>^ queue, std::uint32_t priority);

			bool Equals(Object^ obj) override;
			int GetHashCode() override;

			bool Abort();
			RenegadeDispatcherOperationStatus Invoke();
			RenegadeDispatcherOperationStatus Wait();
			RenegadeDispatcherOperationStatus Wait(TimeSpan timeout);

			property RenegadeDispatcher^ Dispatcher
			{
				RenegadeDispatcher^ get();
			}

			property std::int64_t Id
			{
				std::int64_t get();
			}

			property RenegadeDispatcherOperationStatus Status
			{
				RenegadeDispatcherOperationStatus get();
			}

			property std::uint32_t Priority
			{
				std::uint32_t get();
				void set(std::uint32_t value);
			}

		protected:
			virtual bool InternalInvoke() = 0;
	};
}