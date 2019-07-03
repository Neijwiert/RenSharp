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

#include "stdafx.h"
#include "BaseRenegadeDispatcherOperation.h"
#include "RenegadeDispatcher.h"

using namespace System::Threading;

namespace RenSharp
{
	BaseRenegadeDispatcherOperation::BaseRenegadeDispatcherOperation(RenegadeDispatcher^ dispatcher, std::int64_t id, IPriorityQueue<BaseRenegadeDispatcherOperation^>^ queue, std::uint32_t priority)
		: dispatcher(dispatcher), id(id), queue(queue), status(RenegadeDispatcherOperationStatus::Pending), priority(priority)
	{
		if (dispatcher == nullptr)
		{
			throw gcnew ArgumentNullException("dispatcher");
		}
		else if (queue == nullptr)
		{
			throw gcnew ArgumentNullException("queue");
		}
	}

	bool BaseRenegadeDispatcherOperation::Equals(Object^ obj)
	{
		BaseRenegadeDispatcherOperation^ otherOperation = dynamic_cast<BaseRenegadeDispatcherOperation^>(obj);
		if (otherOperation == nullptr)
		{
			return false;
		}

		return id.Equals(otherOperation->id);
	}

	int BaseRenegadeDispatcherOperation::GetHashCode()
	{
		return id.GetHashCode();
	}

	bool BaseRenegadeDispatcherOperation::Abort()
	{
		Monitor::Enter(this);
		try
		{
			if (
				status == RenegadeDispatcherOperationStatus::Executing ||
				status == RenegadeDispatcherOperationStatus::Completed ||
				status == RenegadeDispatcherOperationStatus::InvocationFailed)
			{
				return false;
			}

			status = RenegadeDispatcherOperationStatus::Aborted;

			Monitor::PulseAll(this);

			return true;
		}
		finally
		{
			Monitor::Exit(this);
		}
	}

	RenegadeDispatcherOperationStatus BaseRenegadeDispatcherOperation::Invoke()
	{
		if (!dispatcher->CheckAccess())
		{
			throw gcnew InvalidOperationException("Not on the Renegade thread");
		}

		Monitor::Enter(this);
		try
		{
			if (status == RenegadeDispatcherOperationStatus::Executing)
			{
				throw gcnew InvalidOperationException("Already executing");
			}
			else if (status != RenegadeDispatcherOperationStatus::Pending)
			{
				return status;
			}

			status = RenegadeDispatcherOperationStatus::Executing;
		}
		finally
		{
			Monitor::Exit(this);
		}

		bool invocationResult = InternalInvoke();

		Monitor::Enter(this);
		try
		{
			if (invocationResult)
			{
				status = RenegadeDispatcherOperationStatus::Completed;
			}
			else
			{
				status = RenegadeDispatcherOperationStatus::InvocationFailed;
			}

			Monitor::PulseAll(this);

			return status;
		}
		finally
		{
			Monitor::Exit(this);
		}
	}

	RenegadeDispatcherOperationStatus BaseRenegadeDispatcherOperation::Wait()
	{
		if (dispatcher->CheckAccess())
		{
			throw gcnew InvalidOperationException("Cannot wait on the Renegade thread");
		}

		Monitor::Enter(this);
		try
		{
			if (
				status != RenegadeDispatcherOperationStatus::Aborted &&
				status != RenegadeDispatcherOperationStatus::Completed &&
				status != RenegadeDispatcherOperationStatus::InvocationFailed)
			{
				Monitor::Wait(this);
			}

			return status;
		}
		finally
		{
			Monitor::Exit(this);
		}
	}

	RenegadeDispatcherOperationStatus BaseRenegadeDispatcherOperation::Wait(TimeSpan timeout)
	{
		if (dispatcher->CheckAccess())
		{
			throw gcnew InvalidOperationException("Cannot wait on the Renegade thread");
		}

		Monitor::Enter(this);
		try
		{
			if (
				status != RenegadeDispatcherOperationStatus::Aborted &&
				status != RenegadeDispatcherOperationStatus::Completed &&
				status != RenegadeDispatcherOperationStatus::InvocationFailed)
			{
				Monitor::Wait(this, timeout);
			}

			return status;
		}
		finally
		{
			Monitor::Exit(this);
		}
	}

	RenegadeDispatcher^ BaseRenegadeDispatcherOperation::Dispatcher::get()
	{
		return dispatcher;
	}

	std::int64_t BaseRenegadeDispatcherOperation::Id::get()
	{
		return id;
	}

	RenegadeDispatcherOperationStatus BaseRenegadeDispatcherOperation::Status::get()
	{
		Monitor::Enter(this);
		try
		{
			return status;
		}
		finally
		{
			Monitor::Exit(this);
		}
	}

	std::uint32_t BaseRenegadeDispatcherOperation::Priority::get()
	{
		Monitor::Enter(this);
		try
		{
			return priority;
		}
		finally
		{
			Monitor::Exit(this);
		}
	}

	void BaseRenegadeDispatcherOperation::Priority::set(std::uint32_t value)
	{
		Monitor::Enter(queue);
		try
		{
			Monitor::Enter(this);
			try
			{
				if (value != priority)
				{
					queue->ChangePriority(this, value);
					priority = value;
				}
			}
			finally
			{
				Monitor::Exit(this);
			}
		}
		finally
		{
			Monitor::Exit(queue);
		}
	}
}