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
#include "PriorityQueueNode.h"

using namespace System;

namespace RenSharp
{
	generic<typename T>
	public ref class PriorityQueue : public IPriorityQueue<T>
	{
		private:
			ref class Enumerator sealed : public IEnumerator<T>
			{
				private:
					PriorityQueue<T>^ queue;
					std::int32_t index;

				public:
					Enumerator(PriorityQueue<T>^ queue)
						: queue(queue), index(-1)
					{

					}

					~Enumerator()
					{

					}

					virtual bool MoveNext() = Collections::Generic::IEnumerator<T>::MoveNext
					{
						index++;

						return (index < queue->nodeCount);
					}

					virtual void Reset() = Collections::Generic::IEnumerator<T>::Reset
					{
						index = -1;
					}

					property T Current
					{
						virtual T get() = Collections::Generic::IEnumerator<T>::Current::get
						{
							return queue->nodes[index]->Item;
						}
					}

					property Object^ Current2
					{
						virtual Object^ get() = Collections::IEnumerator::Current::get
						{
							return Current;
						}
					}
			};

			array<PriorityQueueNode<T>^>^ nodes;
			std::int32_t nodeCount;
			IEqualityComparer<T>^ comparer; 

		public:
			PriorityQueue(std::int32_t initialSize, IEqualityComparer<T>^ comparer)
			{
				if (initialSize <= 0)
				{
					throw gcnew ArgumentOutOfRangeException("initialSize");
				}
				else if (comparer == nullptr)
				{
					throw gcnew ArgumentNullException("comparer");
				}

				nodes = gcnew array<PriorityQueueNode<T>^>(initialSize);
				nodeCount = 0;
				this->comparer = comparer;
			}

			PriorityQueue(std::int32_t initialSize)
				: PriorityQueue<T>(initialSize, EqualityComparer<T>::Default)
			{

			}

			virtual Collections::Generic::IEnumerator<T>^ GetEnumerator()
			{
				return gcnew Enumerator(this);
			}

			virtual Collections::IEnumerator^ GetEnumerator2() = Collections::IEnumerable::GetEnumerator
			{
				return PriorityQueue<T>::GetEnumerator();
			}

			virtual bool Remove(T item)
			{
				for (std::int32_t nodeIndex = 0; nodeIndex < nodeCount; nodeIndex++)
				{
					PriorityQueueNode<T>^ currentNode = nodes[nodeIndex];
					if (comparer->Equals(item, currentNode->Item))
					{
						InternalRemove(nodeIndex);

						return true;
					}
				}

				return false;
			}

			virtual bool ChangePriority(T item, std::uint32_t priority)
			{
				if (Remove(item))
				{
					EnqueueItem(item, priority);

					return true;
				}

				return false;
			}

			virtual void Clear()
			{
				for (std::int32_t nodeIndex = 0; nodeIndex < nodeCount; nodeIndex++)
				{
					nodes[nodeIndex] = nullptr;
				}

				nodeCount = 0;
			}

			virtual void Resize(std::int32_t newSize)
			{
				if (newSize <= 0 || newSize < nodes->LongLength)
				{
					throw gcnew ArgumentOutOfRangeException("newSize");
				}

				array<PriorityQueueNode<T>^>^ newNodes = gcnew array<PriorityQueueNode<T>^>(newSize);
				for (std::int32_t nodeIndex = 0; nodeIndex < nodeCount; nodeIndex++)
				{
					newNodes[nodeIndex] = nodes[nodeIndex];
				}

				nodes = newNodes;
			}

			virtual bool TryPeekFirstItem([Out] T% result)
			{
				if (nodeCount <= 0)
				{
					result = T();

					return false;
				}

				result = nodes[0]->Item;

				return true;
			}

			virtual bool TryTakeFirstItem([Out] T% result)
			{
				if (nodeCount <= 0)
				{
					result = T();

					return false;
				}

				result = InternalRemove(0)->Item;

				return true;
			}

			virtual bool EnqueueItem(T item, std::uint32_t priority)
			{
				if (nodeCount == nodes->Length)
				{
					auto newSize = (nodes->LongLength * 2);
					if (newSize > int::MaxValue)
					{
						return false;
					}

					Resize(static_cast<int>(newSize));
				}

				std::int32_t insertionIndex = 0;
				for (std::int32_t nodeIndex = nodeCount - 1; nodeIndex >= 0 && nodeIndex < nodeCount; nodeIndex--)
				{
					PriorityQueueNode<T>^ currentNode = nodes[nodeIndex];
					if (currentNode->Priority >= priority)
					{
						insertionIndex = nodeIndex + 1;

						break;
					}
				}

				PriorityQueueNode<T>^ previousNode = nodes[insertionIndex];
				for (std::int32_t currentNodeIndex = insertionIndex + 1, previousNodeIndex = insertionIndex; currentNodeIndex <= nodeCount; currentNodeIndex++, previousNodeIndex++)
				{
					PriorityQueueNode<T>^ currentNode = nodes[currentNodeIndex];
					nodes[currentNodeIndex] = previousNode;
					previousNode = currentNode;
				}

				nodes[insertionIndex] = gcnew PriorityQueueNode<T>(item, priority);
				nodeCount++;

				return true;
			}

			property std::int32_t Count
			{
				virtual std::int32_t get()
				{
					return nodeCount;
				}
			}

		private:
			PriorityQueueNode<T>^ InternalRemove(std::int32_t index)
			{
				PriorityQueueNode<T>^ result = nodes[index];
				nodes[index] = nullptr;

				for (std::int32_t currentNodeIndex = index, nextNodeIndex = index + 1; nextNodeIndex < nodeCount; currentNodeIndex++, nextNodeIndex++)
				{
					nodes[currentNodeIndex] = nodes[nextNodeIndex];
				}

				nodeCount--;

				return result;
			}
	};
}