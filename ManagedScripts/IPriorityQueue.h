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

using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

namespace RenSharp
{
	generic<typename T>
	public interface class IPriorityQueue : public System::Collections::Generic::IEnumerable<T>
	{
		bool Remove(T item);

		bool ChangePriority(T item, std::uint32_t priority);

		void Clear();

		void Resize(std::int32_t newSize);

		bool TryPeekFirstItem([Out] T% result);

		bool TryTakeFirstItem([Out] T% result);

		bool EnqueueItem(T item, std::uint32_t priority);

		property std::int32_t Count
		{
			std::int32_t get();
		}
	};
}