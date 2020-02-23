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

#include "MCullSystemClass.h"
#include "Mengine_vector.h"
#include "MCullableClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <AABTreeCull.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	value class SphereClass;
	interface class IAABTreeNodeClass;
	interface class IChunkLoadClass;
	interface class IChunkSaveClass;
	value class AABoxClass;
	value class MinMaxAABoxClass;
	value class AAPlaneClass;

	public interface class IAABTreeCullSystemClass : public ICullSystemClass
	{
		void CollectObjects(SphereClass sphere);

		property IntPtr AABTreeCullSystemClassPointer
		{
			IntPtr get();
		}
	};

	public ref class AABTreeCullSystemClass : public CullSystemClass, public IAABTreeCullSystemClass
	{
		public:
			interface class IStatsStruct : public IUnmanagedObject
			{
				property IntPtr StatsStructPointer
				{
					IntPtr get();
				}

				property int NodeCount
				{
					int get();
					void set(int value);
				}

				property int NodesAccepted
				{
					int get();
					void set(int value);
				}

				property int NodesTriviallyAccepted
				{
					int get();
					void set(int value);
				}

				property int NodesRejected
				{
					int get();
					void set(int value);
				}
			};

			ref class StatsStruct : public AbstractUnmanagedObject, public IStatsStruct
			{
				private:
					StatsStruct();

				public:
					StatsStruct(IntPtr pointer);

					bool Equals(Object^ other) override;

					static IUnmanagedContainer<IStatsStruct^>^ CreateStatsStruct();

					property IntPtr StatsStructPointer
					{
						virtual IntPtr get() sealed;
					}

					property int NodeCount
					{
						virtual int get() sealed;
						virtual void set(int value) sealed;
					}

					property int NodesAccepted
					{
						virtual int get() sealed;
						virtual void set(int value) sealed;
					}

					property int NodesTriviallyAccepted
					{
						virtual int get() sealed;
						virtual void set(int value) sealed;
					}

					property int NodesRejected
					{
						virtual int get() sealed;
						virtual void set(int value) sealed;
					}

				protected:
					bool InternalDestroyPointer() override;

					property ::AABTreeCullSystemClass::StatsStruct* InternalStatsStructPointer
					{
						virtual ::AABTreeCullSystemClass::StatsStruct* get();
					}
			};

			AABTreeCullSystemClass(IntPtr pointer);

			virtual void CollectObjects(SphereClass sphere) sealed;

			property IntPtr AABTreeCullSystemClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			void NodeAccepted();
			void NodeTriviallyAccepted();
			void NodeRejected();
			void LoadNodeContents(IAABTreeNodeClass^ node, IChunkLoadClass^ cLoad);
			void SaveNodeContents(IAABTreeNodeClass^ node, IChunkSaveClass^ cSave);

			property ::CullSystemClass* InternalCullSystemClassPointer
			{
				::CullSystemClass* get() override;
			}

			property ::AABTreeCullSystemClass* InternalAABTreeCullSystemClassPointer
			{
				virtual ::AABTreeCullSystemClass* get();
			}

			property IAABTreeNodeClass^ RootNode
			{
				IAABTreeNodeClass^ get();
				void set(IAABTreeNodeClass^ value);
			}

			property int ObjectCount
			{
				int get();
				void set(int value);
			}

			property int NodeCount
			{
				int get();
				void set(int value);
			}

			property array<IAABTreeNodeClass^>^ IndexedNodes
			{
				array<IAABTreeNodeClass^>^ get();
				void set(array<IAABTreeNodeClass^>^ value);
			}

			property IStatsStruct^ Stats
			{
				IStatsStruct^ get();
				void set(IStatsStruct^ value);
			}
	};

	public interface class IAABTreeIterator : public IUnmanagedObject
	{
		property IntPtr AABTreeIteratorPointer
		{
			IntPtr get();
		}
	};

	public ref class AABTreeIterator : public AbstractUnmanagedObject, public IAABTreeIterator
	{
		public:
			AABTreeIterator(IntPtr pointer);

			property IntPtr AABTreeIteratorPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::AABTreeIterator* InternalAABTreeIteratorPointer
			{
				virtual ::AABTreeIterator* get();
			}
	};

	generic<typename T>
	public interface class ITypedAABTreeCullSystemClass : public IAABTreeCullSystemClass
	{
		 
	};

	generic<typename T>
	public ref class TypedAABTreeCullSystemClass abstract : public AABTreeCullSystemClass, public ITypedAABTreeCullSystemClass<T>
	{
		public:
			TypedAABTreeCullSystemClass(IntPtr pointer)
				: AABTreeCullSystemClass(pointer)
			{

			}
	};

	public interface class IAABTreeNodeClass : public IAutoPoolClass<IAABTreeNodeClass^>
	{
		property IntPtr AABTreeNodeClassPointer
		{
			IntPtr get();
		}

		property uint32 Index
		{
			uint32 get();
			void set(uint32 value);
		}

		property AABoxClass Box
		{
			AABoxClass get();
			void set(AABoxClass value);
		}

		property IAABTreeNodeClass^ Parent
		{
			IAABTreeNodeClass^ get();
			void set(IAABTreeNodeClass^ value);
		}

		property IAABTreeNodeClass^ Front
		{
			IAABTreeNodeClass^ get();
			void set(IAABTreeNodeClass^ value);
		}

		property IAABTreeNodeClass^ Back
		{
			IAABTreeNodeClass^ get();
			void set(IAABTreeNodeClass^ value);
		}

		property ICullableClass^ Object
		{
			ICullableClass^ get();
			void set(ICullableClass^ value);
		}

		property uint32 UserData
		{
			uint32 get();
			void set(uint32 value);
		}
	};

	public ref class AABTreeNodeClass : public AutoPoolClass<IAABTreeNodeClass^>, public IAABTreeNodeClass
	{
		public:
			interface class ISplitChoiceStruct : public IUnmanagedObject
			{
				property IntPtr SplitChoiceStructPointer
				{
					IntPtr get();
				}

				property float Cost
				{
					float get();
					void set(float value);
				}

				property int FrontCount
				{
					int get();
					void set(int value);
				}

				property int BackCount
				{
					int get();
					void set(int value);
				}

				property MinMaxAABoxClass FrontBox
				{
					MinMaxAABoxClass get();
					void set(MinMaxAABoxClass value);
				}

				property MinMaxAABoxClass BackBox
				{
					MinMaxAABoxClass get();
					void set(MinMaxAABoxClass value);
				}

				property AAPlaneClass Plane
				{
					AAPlaneClass get();
					void set(AAPlaneClass value);
				}
			};

			ref class SplitChoiceStruct : public AbstractUnmanagedObject, public ISplitChoiceStruct
			{
				private:
					SplitChoiceStruct();

				public:
					SplitChoiceStruct(IntPtr pointer);

					static IUnmanagedContainer<ISplitChoiceStruct^>^ CreateSplitChoiceStruct();

					bool Equals(Object^ other) override;

					property IntPtr SplitChoiceStructPointer
					{
						virtual IntPtr get() sealed;
					}

					property float Cost
					{
						virtual float get() sealed;
						virtual void set(float value) sealed;
					}

					property int FrontCount
					{
						virtual int get() sealed;
						virtual void set(int value) sealed;
					}

					property int BackCount
					{
						virtual int get() sealed;
						virtual void set(int value) sealed;
					}

					property MinMaxAABoxClass FrontBox
					{
						virtual MinMaxAABoxClass get() sealed;
						virtual void set(MinMaxAABoxClass value) sealed;
					}

					property MinMaxAABoxClass BackBox
					{
						virtual MinMaxAABoxClass get() sealed;
						virtual void set(MinMaxAABoxClass value) sealed;
					}

					property AAPlaneClass Plane
					{
						virtual AAPlaneClass get() sealed;
						virtual void set(AAPlaneClass value) sealed;
					}

				protected:
					bool InternalDestroyPointer() override;

					property ::AABTreeNodeClass::SplitChoiceStruct* InternalSplitChoiceStructPointer
					{
						virtual ::AABTreeNodeClass::SplitChoiceStruct* get();
					}
			};

			AABTreeNodeClass(IntPtr pointer);

			bool Equals(System::Object^ other) override;

			property IntPtr AABTreeNodeClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr AABTreeNodeClassAutoPoolClassPointer
			{
				IntPtr get();
			}

			property uint32 Index
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

			property AABoxClass Box
			{
				virtual AABoxClass get() sealed;
				virtual void set(AABoxClass value) sealed;
			}

			property IAABTreeNodeClass^ Parent
			{
				virtual IAABTreeNodeClass^ get() sealed;
				virtual void set(IAABTreeNodeClass^ value) sealed;
			}

			property IAABTreeNodeClass^ Front
			{
				virtual IAABTreeNodeClass^ get() sealed;
				virtual void set(IAABTreeNodeClass^ value) sealed;
			}

			property IAABTreeNodeClass^ Back
			{
				virtual IAABTreeNodeClass^ get() sealed;
				virtual void set(IAABTreeNodeClass^ value) sealed;
			}

			property ICullableClass^ Object
			{
				virtual ICullableClass^ get() sealed;
				virtual void set(ICullableClass^ value) sealed;
			}

			property uint32 UserData
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

		protected:
			property ::AutoPoolClass<::AABTreeNodeClass, 256>* InternalAABTreeNodeClassAutoPoolClassPointer
			{
				virtual ::AutoPoolClass<::AABTreeNodeClass, 256>* get();
			}

			property ::AABTreeNodeClass* InternalAABTreeNodeClassPointer
			{
				virtual ::AABTreeNodeClass* get();
			}
	};

	public interface class IAABTreeLinkClass : public ICullLinkClass, public IAutoPoolClass<IAABTreeLinkClass^>
	{
		property IntPtr AABTreeLinkClassPointer
		{
			IntPtr get();
		}

		property IAABTreeNodeClass^ Node
		{
			IAABTreeNodeClass^ get();
			void set(IAABTreeNodeClass^ value);
		}

		property ICullableClass^ NextObject
		{
			ICullableClass^ get();
			void set(ICullableClass^ value);
		}
	};

	public ref class AABTreeLinkClass : public CullLinkClass, public IAABTreeLinkClass
	{
		private:
			AABTreeLinkClass(IAABTreeCullSystemClass^ system);

		public:
			AABTreeLinkClass(IntPtr pointer);

			static IUnmanagedContainer<IAABTreeLinkClass^>^ CreateAABTreeLinkClass(IAABTreeCullSystemClass^ system);

			property IntPtr AABTreeLinkClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr AABTreeLinkClassAutoPoolClassPointer
			{
				IntPtr get();
			}

			property IAABTreeNodeClass^ Node
			{
				virtual IAABTreeNodeClass^ get() sealed;
				virtual void set(IAABTreeNodeClass^ value) sealed;
			}

			property ICullableClass^ NextObject
			{
				virtual ICullableClass^ get() sealed;
				virtual void set(ICullableClass^ value) sealed;
			}

		protected:
			property ::CullLinkClass* InternalCullLinkClassPointer
			{
				::CullLinkClass* get() override;
			}

			property ::AutoPoolClass<::AABTreeLinkClass, 256>* InternalAABTreeLinkClassAutoPoolClassPointer
			{
				virtual ::AutoPoolClass<::AABTreeLinkClass, 256>* get();
			}

			property ::AABTreeLinkClass* InternalAABTreeLinkClassPointer
			{
				virtual ::AABTreeLinkClass* get();
			}
	};
}