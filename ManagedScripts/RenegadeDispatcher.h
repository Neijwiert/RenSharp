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

#include "BaseRenegadeDispatcherOperation.h"
#include "RenegadeDispatcherTaskOperation.h"

namespace RenSharp
{
	public ref class RenegadeDispatcher sealed
	{
		private:
			IPriorityQueue<BaseRenegadeDispatcherOperation^>^ queue;
			std::int64_t currentOperationId;
			Threading::Thread^ renegadeThread;
			Threading::Thread^ owner;
			std::int32_t maxQueueSize;

		public:
			RenegadeDispatcher(Threading::Thread^ renegadeThread, Threading::Thread^ owner, std::int32_t queueInitialSize);

			void ProcessOperation();
			bool CheckAccess();

			RenegadeDispatcherTaskOperation<Task^>^ InvokeAsync(Action^ action, std::uint32_t priority, Nullable<CancellationToken> cancellationToken);
			RenegadeDispatcherTaskOperation<Task^>^ InvokeAsync(Action^ action, std::uint32_t priority);
			RenegadeDispatcherTaskOperation<Task^>^ InvokeAsync(Action^ action);

			generic<typename TResult>
			RenegadeDispatcherTaskOperation<Task<TResult>^>^ InvokeAsync(Func<TResult>^ callback, std::uint32_t priority, Nullable<CancellationToken> cancellationToken)
			{
				Task<TResult>^ task;
				if (cancellationToken.HasValue)
				{
					task = gcnew Task<TResult>(callback, cancellationToken.Value);
				}
				else
				{
					task = gcnew Task<TResult>(callback);
				}

				RenegadeDispatcherTaskOperation<Task<TResult>^>^ newOperation = gcnew RenegadeDispatcherTaskOperation<Task<TResult>^>(
					this,
					Interlocked::Increment(currentOperationId),
					queue,
					priority,
					task);

				Monitor::Enter(this);
				try
				{
					Monitor::Enter(queue);
					try
					{
						if (
							(maxQueueSize > 0 && queue->Count >= maxQueueSize) ||
							!queue->EnqueueItem(newOperation, priority))
						{
							return nullptr;
						}
					}
					finally
					{
						Monitor::Exit(queue);
					}
				}
				finally
				{
					Monitor::Exit(this);
				}

				return newOperation;
			}

			generic<typename TResult>
			RenegadeDispatcherTaskOperation<Task<TResult>^>^ InvokeAsync(Func<TResult>^ callback, std::uint32_t priority)
			{
				return InvokeAsync<TResult>(callback, priority, Nullable<CancellationToken>());
			}

			generic<typename TResult>
			RenegadeDispatcherTaskOperation<Task<TResult>^>^ InvokeAsync(Func<TResult>^ callback)
			{
				return InvokeAsync<TResult>(callback, 0, Nullable<CancellationToken>());
			}

			RenegadeDispatcherTaskOperation<Task^>^ Invoke(Action^ action, std::uint32_t priority, Nullable<CancellationToken> cancellationToken);
			RenegadeDispatcherTaskOperation<Task^>^ Invoke(Action^ action, std::uint32_t priority);
			RenegadeDispatcherTaskOperation<Task^>^ Invoke(Action^ action);

			RenegadeDispatcherTaskOperation<Task^>^ Invoke(Action^ action, TimeSpan timeout, std::uint32_t priority, Nullable<CancellationToken> cancellationToken);
			RenegadeDispatcherTaskOperation<Task^>^ Invoke(Action^ action, TimeSpan timeout, std::uint32_t priority);
			RenegadeDispatcherTaskOperation<Task^>^ Invoke(Action^ action, TimeSpan timeout);

			generic<typename TResult>
			RenegadeDispatcherTaskOperation<Task<TResult>^>^ Invoke(Func<TResult>^ callback, std::uint32_t priority, Nullable<CancellationToken> cancellationToken)
			{
				if (CheckAccess())
				{
					throw gcnew InvalidOperationException("On the Renegade thread");
				}

				RenegadeDispatcherTaskOperation<Task<TResult>^>^ newOperation = InvokeAsync<TResult>(callback, priority, cancellationToken);
				if (newOperation == nullptr)
				{
					return nullptr;
				}

				newOperation->Wait();

				return newOperation;
			}

			generic<typename TResult>
			RenegadeDispatcherTaskOperation<Task<TResult>^>^ Invoke(Func<TResult>^ callback, std::uint32_t priority)
			{
				return Invoke<TResult>(callback, priority, Nullable<CancellationToken>());
			}

			generic<typename TResult>
			RenegadeDispatcherTaskOperation<Task<TResult>^>^ Invoke(Func<TResult>^ callback)
			{
				return Invoke<TResult>(callback, 0, Nullable<CancellationToken>());
			}

			generic<typename TResult>
			RenegadeDispatcherTaskOperation<Task<TResult>^>^ Invoke(Func<TResult>^ callback, TimeSpan timeout, std::uint32_t priority, Nullable<CancellationToken> cancellationToken)
			{
				if (CheckAccess())
				{
					throw gcnew InvalidOperationException("On the Renegade thread");
				}

				RenegadeDispatcherTaskOperation<Task<TResult>^>^ newOperation = InvokeAsync<TResult>(callback, priority, cancellationToken);
				if (newOperation == nullptr)
				{
					return nullptr;
				}

				newOperation->Wait(timeout);

				return newOperation;
			}

			generic<typename TResult>
			RenegadeDispatcherTaskOperation<Task<TResult>^>^ Invoke(Func<TResult>^ callback, TimeSpan timeout, std::uint32_t priority)
			{
				return Invoke<TResult>(callback, timeout, priority, Nullable<CancellationToken>());
			}

			generic<typename TResult>
			RenegadeDispatcherTaskOperation<Task<TResult>^>^ Invoke(Func<TResult>^ callback, TimeSpan timeout)
			{
				return Invoke<TResult>(callback, timeout, 0, Nullable<CancellationToken>());
			}

			property Threading::Thread^ RenegadeThread
			{
				Threading::Thread^ get();
			}

			property Threading::Thread^ Owner
			{
				Threading::Thread^ get();
			}

			property int MaxQueueSize
			{
				int get();
				void set(int value);
			}

			property int CurrentQueueCount
			{
				int get();
			}
	};
}