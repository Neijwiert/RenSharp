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
#include "RenegadeDispatcher.h"
#include "PriorityQueue.h"

namespace RenSharp
{
	RenegadeDispatcher::RenegadeDispatcher(Threading::Thread^ renegadeThread, std::int32_t queueInitialSize)
		: queue(gcnew PriorityQueue<BaseRenegadeDispatcherOperation^>(queueInitialSize)), currentOperationId(1), renegadeThread(renegadeThread)
	{
		if (renegadeThread == nullptr)
		{
			throw gcnew ArgumentNullException("renegadeThread");
		}
	}

	void RenegadeDispatcher::ProcessOperation()
	{
		if (!CheckAccess())
		{
			throw gcnew InvalidOperationException("Not on the Renegade thread");
		}

		BaseRenegadeDispatcherOperation^ operation;
		Monitor::Enter(queue);
		try
		{
			if (!queue->TryTakeFirstItem(operation))
			{
				return;
			}
		}
		finally
		{
			Monitor::Exit(queue);
		}

		if (operation->Status != RenegadeDispatcherOperationStatus::Executing)
		{
			operation->Invoke();
		}
	}

	bool RenegadeDispatcher::CheckAccess()
	{
		return (Thread::CurrentThread->Equals(renegadeThread));
	}

	RenegadeDispatcherTaskOperation<Task^>^ RenegadeDispatcher::InvokeAsync(Action^ action, std::uint32_t priority, Nullable<CancellationToken>^ cancellationToken)
	{
		Task^ task;
		if (cancellationToken->HasValue)
		{
			task = gcnew Task(action, cancellationToken->Value);
		}
		else
		{
			task = gcnew Task(action);
		}

		RenegadeDispatcherTaskOperation<Task^>^ newOperation = gcnew RenegadeDispatcherTaskOperation<Task^>(
			this,
			Interlocked::Increment(currentOperationId),
			queue,
			priority, 
			task);

		Monitor::Enter(queue);
		try
		{
			queue->EnqueueItem(newOperation, priority);
		}
		finally
		{
			Monitor::Exit(queue);
		}

		return newOperation;
	}

	RenegadeDispatcherTaskOperation<Task^>^ RenegadeDispatcher::InvokeAsync(Action^ action, std::uint32_t priority)
	{
		return InvokeAsync(action, priority, nullptr);
	}

	RenegadeDispatcherTaskOperation<Task^>^ RenegadeDispatcher::InvokeAsync(Action^ action)
	{
		return InvokeAsync(action, 0, nullptr);
	}

	RenegadeDispatcherTaskOperation<Task^>^ RenegadeDispatcher::Invoke(Action^ action, std::uint32_t priority, Nullable<CancellationToken>^ cancellationToken)
	{
		RenegadeDispatcherTaskOperation<Task^>^ newOperation;
		if (CheckAccess())
		{
			Task^ task;
			if (cancellationToken->HasValue)
			{
				task = gcnew Task(action, cancellationToken->Value);
			}
			else
			{
				task = gcnew Task(action);
			}

			newOperation = gcnew RenegadeDispatcherTaskOperation<Task^>(this, Interlocked::Increment(currentOperationId), queue, priority, task);

			newOperation->Invoke();
		}
		else
		{
			newOperation = InvokeAsync(action, priority, cancellationToken);
			newOperation->Wait();
		}

		return newOperation;
	}

	RenegadeDispatcherTaskOperation<Task^>^ RenegadeDispatcher::Invoke(Action^ action, std::uint32_t priority)
	{
		return Invoke(action, priority, nullptr);
	}

	RenegadeDispatcherTaskOperation<Task^>^ RenegadeDispatcher::Invoke(Action^ action)
	{
		return Invoke(action, 0, nullptr);
	}

	RenegadeDispatcherTaskOperation<Task^>^ RenegadeDispatcher::Invoke(Action^ action, TimeSpan timeout, std::uint32_t priority, Nullable<CancellationToken>^ cancellationToken)
	{
		RenegadeDispatcherTaskOperation<Task^>^ newOperation;
		if (CheckAccess())
		{
			Task^ task;
			if (cancellationToken->HasValue)
			{
				task = gcnew Task(action, cancellationToken->Value);
			}
			else
			{
				task = gcnew Task(action);
			}

			newOperation = gcnew RenegadeDispatcherTaskOperation<Task^>(this, Interlocked::Increment(currentOperationId), queue, priority, task);

			newOperation->Invoke();
		}
		else
		{
			newOperation = InvokeAsync(action, priority, cancellationToken);
			newOperation->Wait(timeout);
		}

		return newOperation;
	}

	RenegadeDispatcherTaskOperation<Task^>^ RenegadeDispatcher::Invoke(Action^ action, TimeSpan timeout, std::uint32_t priority)
	{
		return Invoke(action, timeout, priority, nullptr);
	}

	RenegadeDispatcherTaskOperation<Task^>^ RenegadeDispatcher::Invoke(Action^ action, TimeSpan timeout)
	{
		return Invoke(action, timeout, 0, nullptr);
	}

	Threading::Thread^ RenegadeDispatcher::RenegadeThread::get()
	{
		return renegadeThread;
	}
}