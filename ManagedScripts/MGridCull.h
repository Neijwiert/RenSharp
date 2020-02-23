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
#include "IUnmanagedContainer.h"
#include "Mengine_vector.h"
#include "MCullableClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <GridCull.h>
#include <type_traits>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{

#pragma managed(push, off)

	class GridCullSystemClassHelper : public ::GridCullSystemClass
	{
		public:
			static constexpr int TerminationCellCount = ::GridCullSystemClass::TERMINATION_CELL_COUNT;
			static constexpr int UngriddedAddress = ::GridCullSystemClass::UNGRIDDED_ADDRESS;
			static constexpr std::size_t MinSizeCount = (sizeof(::GridCullSystemClass::VolumeStruct::Min) / sizeof(std::remove_all_extents<decltype(::GridCullSystemClass::VolumeStruct::Min)>::type));
			static constexpr std::size_t MaxSizeCount = (sizeof(::GridCullSystemClass::VolumeStruct::Max) / sizeof(std::remove_all_extents<decltype(::GridCullSystemClass::VolumeStruct::Max)>::type));
			static constexpr std::size_t CellCountSizeCount = (sizeof(::GridCullSystemClass::CellCount) / sizeof(std::remove_all_extents<decltype(::GridCullSystemClass::CellCount)>::type));

		private:
			static constexpr std::size_t MinSize = sizeof(::GridCullSystemClass::VolumeStruct::Min);
			static constexpr std::size_t MaxSize = sizeof(::GridCullSystemClass::VolumeStruct::Max);

			GridCullSystemClassHelper() = default;

		public:
			static bool IsLeaf(void* volumeStructPtr)
			{
				::GridCullSystemClass::VolumeStruct* volumeStruct = reinterpret_cast<::GridCullSystemClass::VolumeStruct*>(volumeStructPtr);

				return volumeStruct->Is_Leaf();
			}

			static bool IsEmpty(void* volumeStructPtr)
			{
				::GridCullSystemClass::VolumeStruct* volumeStruct = reinterpret_cast<::GridCullSystemClass::VolumeStruct*>(volumeStructPtr);

				return volumeStruct->Is_Empty();
			}

			static void Split(void* volumeStructPtr, void* v0Ptr, void* v1Ptr)
			{
				::GridCullSystemClass::VolumeStruct* volumeStruct = reinterpret_cast<::GridCullSystemClass::VolumeStruct*>(volumeStructPtr);
				::GridCullSystemClass::VolumeStruct* v0 = reinterpret_cast<::GridCullSystemClass::VolumeStruct*>(v0Ptr);
				::GridCullSystemClass::VolumeStruct* v1 = reinterpret_cast<::GridCullSystemClass::VolumeStruct*>(v1Ptr);

				volumeStruct->Split(*v0, *v1);
			}

			static void GetMin(void* volumeStructPtr, int* result)
			{
				::GridCullSystemClass::VolumeStruct* volumeStruct = reinterpret_cast<::GridCullSystemClass::VolumeStruct*>(volumeStructPtr);

				std::memcpy(result, volumeStruct->Min, MinSize);
			}

			static void SetMin(void* volumeStructPtr, int* value)
			{
				::GridCullSystemClass::VolumeStruct* volumeStruct = reinterpret_cast<::GridCullSystemClass::VolumeStruct*>(volumeStructPtr);

				std::memcpy(volumeStruct->Min, value, MinSize);
			}

			static void GetMax(void* volumeStructPtr, int* result)
			{
				::GridCullSystemClass::VolumeStruct* volumeStruct = reinterpret_cast<::GridCullSystemClass::VolumeStruct*>(volumeStructPtr);

				std::memcpy(result, volumeStruct->Max, MaxSize);
			}

			static void SetMax(void* volumeStructPtr, int* value)
			{
				::GridCullSystemClass::VolumeStruct* volumeStruct = reinterpret_cast<::GridCullSystemClass::VolumeStruct*>(volumeStructPtr);

				std::memcpy(volumeStruct->Max, value, MaxSize);
			}

			float& GetMaxObjExtent()
			{
				return MaxObjExtent;
			}

			::Vector3& GetOrigin()
			{
				return Origin;
			}

			::Vector3& GetCellDim()
			{
				return CellDim;
			}

			::Vector3& GetOOCellDim()
			{
				return OOCellDim;
			}

			void GetCellCount(int* result)
			{
				std::memcpy(result, CellCount, sizeof(CellCount));
			}

			void SetCellCount(int* value)
			{
				std::memcpy(CellCount, value, sizeof(CellCount));
			}

			::CullableClass** GetCells()
			{
				return Cells;
			}

			void SetCell(std::size_t index, ::CullableClass* cullObj)
			{
				Cells[index] = cullObj;
			}

			::CullableClass*& GetNoGridList()
			{
				return NoGridList;
			}

			int& GetObjCount()
			{
				return ObjCount;
			}

			::GridCullSystemClass::StatsStruct& GetStats()
			{
				return Stats;
			}

			bool MapPointToCell(const ::Vector3& pt, int& setI, int& setJ, int& setK)
			{
				return map_point_to_cell(pt, setI, setJ, setK);
			}

			bool MapPointToAddress(const ::Vector3 pt, int& setAddress)
			{
				return map_point_to_address(pt, setAddress);
			}

			int MapIndicesToAddress(int i, int j, int k)
			{
				return map_indices_to_address(i, j, k);
			}

			void ClampIndicesToGrid(int* i, int* j, int* k)
			{
				clamp_indices_to_grid(i, j, k);
			}

			int TotalCellCount()
			{
				return total_cell_count();
			}

			void ComputeBox(int i, int j, int k, ::AABoxClass* setBox)
			{
				compute_box(i, j, k, setBox);
			}

			void ComputeBox(void* volumeStructPtr, ::AABoxClass* setBox)
			{
				::GridCullSystemClass::VolumeStruct* volumeStruct = reinterpret_cast<::GridCullSystemClass::VolumeStruct*>(volumeStructPtr);

				compute_box(*volumeStruct, setBox);
			}

			void InitVolume(const ::Vector3& boundMin, const ::Vector3& boundMax, void* volumeStructPtr)
			{
				::GridCullSystemClass::VolumeStruct* volumeStruct = reinterpret_cast<::GridCullSystemClass::VolumeStruct*>(volumeStructPtr);

				init_volume(boundMin, boundMax, volumeStruct);
			}

			void InitVolume(const ::LineSegClass& line, void* volumeStructPtr)
			{
				::GridCullSystemClass::VolumeStruct* volumeStruct = reinterpret_cast<::GridCullSystemClass::VolumeStruct*>(volumeStructPtr);

				init_volume(line, volumeStruct);
			}

			void InitVolume(const ::AABoxClass& box, void* volumeStructPtr)
			{
				::GridCullSystemClass::VolumeStruct* volumeStruct = reinterpret_cast<::GridCullSystemClass::VolumeStruct*>(volumeStructPtr);

				init_volume(box, volumeStruct);
			}

			void InitVolume(const ::OBBoxClass& box, void* volumeStructPtr)
			{
				::GridCullSystemClass::VolumeStruct* volumeStruct = reinterpret_cast<::GridCullSystemClass::VolumeStruct*>(volumeStructPtr);

				init_volume(box, volumeStruct);
			}

			void InitVolume(const ::FrustumClass& frustum, void* volumeStructPtr)
			{
				::GridCullSystemClass::VolumeStruct* volumeStruct = reinterpret_cast<::GridCullSystemClass::VolumeStruct*>(volumeStructPtr);

				init_volume(frustum, volumeStruct);
			}
	};

#pragma managed(pop)

	interface class IChunkLoadClass;
	interface class IChunkSaveClass;
	value class LineSegClass;

	public interface class IGridCullSystemClass : public ICullSystemClass
	{
		void RePartition(Vector3 min, Vector3 max, float objDim);

		void Load(IChunkLoadClass^ cLoad);

		void Save(IChunkSaveClass^ cSave);

		property IntPtr GridCullSystemClassPointer
		{
			IntPtr get();
		}

		property int ObjectCount
		{
			int get();
		}

		property Vector3 MinCellSize
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property int TerminationCellCount
		{
			int get();
			void set(int value);
		}
	};

	public ref class GridCullSystemClass : public CullSystemClass, public IGridCullSystemClass
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

					static IUnmanagedContainer<IStatsStruct^>^ CreateStatsStruct();

					bool Equals(Object^ other) override;

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

					property ::GridCullSystemClass::StatsStruct* InternalStatsStructPointer
					{
						virtual ::GridCullSystemClass::StatsStruct* get();
					}
			};

			GridCullSystemClass(IntPtr pointer);

			virtual void RePartition(Vector3 min, Vector3 max, float objDim) sealed;
			virtual void Load(IChunkLoadClass^ cLoad) sealed;
			virtual void Save(IChunkSaveClass^ cSave) sealed;

			property IntPtr GridCullSystemClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int ObjectCount
			{
				virtual int get() sealed;

				protected:
					void set(int value);
			}

			property Vector3 MinCellSize
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property int TerminationCellCount
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			literal int MaxTerminationCellCount = GridCullSystemClassHelper::TerminationCellCount;
			literal int UngriddedAddress = GridCullSystemClassHelper::UngriddedAddress;

			interface class IVolumeStruct : public IUnmanagedObject
			{
				void Split(IVolumeStruct^ v0, IVolumeStruct^ v1);

				property IntPtr VolumeStructPointer
				{
					IntPtr get();
				}

				property bool IsLeaf
				{
					bool get();
				}

				property bool IsEmpty
				{
					bool get();
				}

				property array<int>^ Min
				{
					array<int>^ get();
					void set(array<int>^ value);
				}

				property array<int>^ Max
				{
					array<int>^ get();
					void set(array<int>^ value);
				}
			};

			ref class VolumeStruct : public AbstractUnmanagedObject, public IVolumeStruct
			{
				private:
					VolumeStruct();
					VolumeStruct(int i0, int j0, int k0, int i1, int j1, int k1);

				public:
					VolumeStruct(IntPtr pointer);

					static IUnmanagedContainer<IVolumeStruct^>^ CreateVolumeStruct();
					static IUnmanagedContainer<IVolumeStruct^>^ CreateVolumeStruct(int i0, int j0, int k0, int i1, int j1, int k1);

					bool Equals(Object^ other) override;

					virtual void Split(IVolumeStruct^ v0, IVolumeStruct^ v1) sealed;

					property IntPtr VolumeStructPointer
					{
						virtual IntPtr get() sealed;
					}

					property bool IsLeaf
					{
						virtual bool get() sealed;
					}

					property bool IsEmpty
					{
						virtual bool get() sealed;
					}

					property array<int>^ Min
					{
						virtual array<int>^ get() sealed;
						virtual void set(array<int>^ value) sealed;
					}

					property array<int>^ Max
					{
						virtual array<int>^ get() sealed;
						virtual void set(array<int>^ value) sealed;
					}

				protected:
					bool InternalDestroyPointer() override;

					property void* InternalVolumeStructPointer
					{
						virtual void* get();
					}
			};

			bool MapPointToCell(Vector3 pt, [Out] int% setI, [Out] int% setJ, [Out] int% setK);
			bool MapPointToAddress(Vector3 pt, [Out] int% setAddress);
			int MapIndicesToAddress(int i, int j, int k);
			void ClampIndicesToGrid(int% i, int% j, int% k);
			AABoxClass ComputeBox(int i, int j, int k);
			AABoxClass ComputeBox(IVolumeStruct^ vol);
			void InitVolume(Vector3 boundMin, Vector3 boundMax, IVolumeStruct^ setVol);
			void InitVolume(LineSegClass line, IVolumeStruct^ setVol);
			void InitVolume(AABoxClass box, IVolumeStruct^ setVol);
			void InitVolume(OBBoxClass box, IVolumeStruct^ setVol);
			void InitVolume(FrustumClass frustum, IVolumeStruct^ setVol);

			property ::CullSystemClass* InternalCullSystemClassPointer
			{
				::CullSystemClass* get() override;
			}

			property ::GridCullSystemClass* InternalGridCullSystemClassPointer
			{
				virtual ::GridCullSystemClass* get();
			}

			property float MaxObjExtent
			{
				float get();
				void set(float value);
			}

			property Vector3 Origin
			{
				Vector3 get();
				void set(Vector3 value);
			}

			property Vector3 CellDim
			{
				Vector3 get();
				void set(Vector3 value);
			}

			property Vector3 OOCellDim
			{
				Vector3 get();
				void set(Vector3 value);
			}

			property array<int>^ CellCount
			{
				array<int>^ get();
				void set(array<int>^ value);
			}

			property array<ICullableClass^>^ Cells
			{
				array<ICullableClass^>^ get();
				void set(array<ICullableClass^>^ value);
			}

			property ICullableClass^ NoGridList
			{
				ICullableClass^ get();
				void set(ICullableClass^ value);
			}

			property IStatsStruct^ Stats
			{
				IStatsStruct^ get();
				void set(IStatsStruct^ value);
			}

			property int TotalCellCount
			{
				int get();
			}
	};

	generic<typename T>
	public interface class ITypedGridCullSystemClass : public IGridCullSystemClass
	{

	};

	generic<typename T>
	public ref class TypedGridCullSystemClass : public GridCullSystemClass, public ITypedGridCullSystemClass<T>
	{
		public:
			TypedGridCullSystemClass(IntPtr pointer)
				: GridCullSystemClass(pointer)
			{

			}
	};

	public interface class IGridLinkClass : public ICullLinkClass, public IAutoPoolClass<IGridLinkClass^>
	{
		property IntPtr GridLinkClassPointer
		{
			IntPtr get();
		}

		property int GridAddress
		{
			int get();
			void set(int value);
		}

		property ICullableClass^ Prev
		{
			ICullableClass^ get();
			void set(ICullableClass^ value);
		}

		property ICullableClass^ Next
		{
			ICullableClass^ get();
			void set(ICullableClass^ value);
		}
	};

	public ref class GridLinkClass : public CullLinkClass, public IGridLinkClass
	{
		public:
			GridLinkClass(IntPtr pointer);

			property IntPtr GridLinkClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr GridLinkClassAutoPoolClassPointer
			{
				IntPtr get();
			}

			property int GridAddress
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property ICullableClass^ Prev
			{
				virtual ICullableClass^ get() sealed;
				virtual void set(ICullableClass^ value) sealed;
			}

			property ICullableClass^ Next
			{
				virtual ICullableClass^ get() sealed;
				virtual void set(ICullableClass^ value) sealed;
			}

		protected:
			property ::CullLinkClass* InternalCullLinkClassPointer
			{
				::CullLinkClass* get() override;
			}

			property ::AutoPoolClass<::GridLinkClass, 256>* InternalGridLinkClassAutoPoolClassPointer
			{
				virtual ::AutoPoolClass<::GridLinkClass, 256>* get();
			}

			property ::GridLinkClass* InternalGridLinkClassPointer
			{
				virtual ::GridLinkClass* get();
			}
	};

	public interface class IGridListIterator : public IUnmanagedObject
	{
		void First(ICullableClass^ head);

		void First();

		void Next();

		void Prev();

		ICullableClass^ GetObj();

		ICullableClass^ PeekObj();

		property IntPtr GridListIteratorPointer
		{
			IntPtr get();
		}

		property bool IsDone
		{
			bool get();
		}
	};

	public ref class GridListIterator : public AbstractUnmanagedObject, public IGridListIterator
	{
		private:
			GridListIterator(ICullableClass^ head);

		public:
			GridListIterator(IntPtr pointer);

			static IUnmanagedContainer<IGridListIterator^>^ CreateGridListIterator(ICullableClass^ head);

			virtual void First(ICullableClass^ head) sealed;
			virtual void First() sealed;
			virtual void Next() sealed;
			virtual void Prev() sealed;
			virtual ICullableClass^ GetObj() sealed;
			virtual ICullableClass^ PeekObj() sealed;

			property IntPtr GridListIteratorPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsDone
			{
				virtual bool get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::GridListIterator* InternalGridListIteratorPointer
			{
				virtual ::GridListIterator* get();
			}
	};
}