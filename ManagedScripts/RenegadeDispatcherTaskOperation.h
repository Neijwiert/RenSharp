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

using namespace System::Threading;
using namespace System::Threading::Tasks;

namespace RenSharp
{
	generic<typename T>
	where T : Task
	public ref class RenegadeDispatcherTaskOperation sealed : public BaseRenegadeDispatcherOperation
	{
		private:
			T task;

		public:
			RenegadeDispatcherTaskOperation(RenegadeDispatcher^ dispatcher, std::int64_t id, IPriorityQueue<BaseRenegadeDispatcherOperation^>^ queue, std::uint32_t priority, T task)
				: BaseRenegadeDispatcherOperation(dispatcher, id, queue, priority), task(task)
			{
				if (task == nullptr)
				{
					throw gcnew ArgumentNullException("task");
				}
			}

			property T Task
			{
				T get()
				{
					Monitor::Enter(this);
					try
					{
						return task;
					}
					finally
					{
						Monitor::Exit(this);
					}
				}

				void set(T value)
				{
					if (value == nullptr)
					{
						throw gcnew ArgumentNullException("value");
					}

					Monitor::Enter(this);
					try
					{
						task = value;
					}
					finally
					{
						Monitor::Exit(this);
					}
				}
			}

		protected:
			bool InternalInvoke() override
			{
				T taskToRun;
				Monitor::Enter(this);
				try
				{
					taskToRun = task;
				}
				finally
				{
					Monitor::Exit(this);
				}

				if (taskToRun->Status == TaskStatus::Created)
				{
					try
					{
						taskToRun->RunSynchronously();
					}
					catch (InvalidOperationException^)
					{
						return false;
					}
				}

				return (taskToRun->Status == TaskStatus::RanToCompletion);
			}
	};
}