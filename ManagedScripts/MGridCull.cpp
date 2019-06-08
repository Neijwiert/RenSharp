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
#include "MGridCull.h"

#include "Imports.h"
#include "MChunkClass.h"
#include "MVector3.h"
#include "MAABoxClass.h"
#include "Mobboxclass.h"
#include "MFrustumClass.h"
#include "MLineSegClass.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	GridCullSystemClass::StatsStruct::StatsStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateGridCullSystemClassStatsStruct()))
	{

	}

	GridCullSystemClass::StatsStruct::StatsStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<GridCullSystemClass::IStatsStruct^>^ GridCullSystemClass::StatsStruct::CreateStatsStruct()
	{
		return gcnew UnmanagedContainer<GridCullSystemClass::IStatsStruct^>(gcnew GridCullSystemClass::StatsStruct());
	}

	bool GridCullSystemClass::StatsStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		GridCullSystemClass::IStatsStruct^ otherThis = dynamic_cast<GridCullSystemClass::IStatsStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return StatsStructPointer.Equals(otherThis->StatsStructPointer);
	}

	IntPtr GridCullSystemClass::StatsStruct::StatsStructPointer::get()
	{
		return IntPtr(InternalStatsStructPointer);
	}

	int GridCullSystemClass::StatsStruct::NodeCount::get()
	{
		return InternalStatsStructPointer->NodeCount;
	}

	void GridCullSystemClass::StatsStruct::NodeCount::set(int value)
	{
		InternalStatsStructPointer->NodeCount = value;
	}

	int GridCullSystemClass::StatsStruct::NodesAccepted::get()
	{
		return InternalStatsStructPointer->NodesAccepted;
	}

	void GridCullSystemClass::StatsStruct::NodesAccepted::set(int value)
	{
		InternalStatsStructPointer->NodesAccepted = value;
	}

	int GridCullSystemClass::StatsStruct::NodesTriviallyAccepted::get()
	{
		return InternalStatsStructPointer->NodesTriviallyAccepted;
	}

	void GridCullSystemClass::StatsStruct::NodesTriviallyAccepted::set(int value)
	{
		InternalStatsStructPointer->NodesTriviallyAccepted = value;
	}

	int GridCullSystemClass::StatsStruct::NodesRejected::get()
	{
		return InternalStatsStructPointer->NodesRejected;
	}

	void GridCullSystemClass::StatsStruct::NodesRejected::set(int value)
	{
		InternalStatsStructPointer->NodesRejected = value;
	}

	bool GridCullSystemClass::StatsStruct::InternalDestroyPointer()
	{
		Imports::DestroyGridCullSystemClassStatsStruct(InternalStatsStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::GridCullSystemClass::StatsStruct* GridCullSystemClass::StatsStruct::InternalStatsStructPointer::get()
	{
		return reinterpret_cast<::GridCullSystemClass::StatsStruct*>(Pointer.ToPointer());
	}

	GridCullSystemClass::VolumeStruct::VolumeStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateGridCullSystemClassVolumeStruct1()))
	{

	}

	GridCullSystemClass::VolumeStruct::VolumeStruct(int i0, int j0, int k0, int i1, int j1, int k1)
		: AbstractUnmanagedObject(IntPtr(Imports::CreateGridCullSystemClassVolumeStruct2(i0, j0, k0, i1, j1, k1)))
	{

	}

	GridCullSystemClass::VolumeStruct::VolumeStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<GridCullSystemClass::IVolumeStruct^>^ GridCullSystemClass::VolumeStruct::CreateVolumeStruct()
	{
		return gcnew UnmanagedContainer<GridCullSystemClass::IVolumeStruct^>(gcnew GridCullSystemClass::VolumeStruct());
	}

	IUnmanagedContainer<GridCullSystemClass::IVolumeStruct^>^ GridCullSystemClass::VolumeStruct::CreateVolumeStruct(int i0, int j0, int k0, int i1, int j1, int k1)
	{
		return gcnew UnmanagedContainer<GridCullSystemClass::IVolumeStruct^>(gcnew GridCullSystemClass::VolumeStruct(i0, j0, k0, i1, j1, k1));
	}

	bool GridCullSystemClass::VolumeStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		GridCullSystemClass::IVolumeStruct^ otherThis = dynamic_cast<GridCullSystemClass::IVolumeStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return VolumeStructPointer.Equals(otherThis->VolumeStructPointer);
	}

	void GridCullSystemClass::VolumeStruct::Split(IVolumeStruct^ v0, IVolumeStruct^ v1)
	{
		if (v0 == nullptr || v0->VolumeStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("v0");
		}
		else if (v1 == nullptr || v1->VolumeStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("v1");
		}

		GridCullSystemClassHelper::Split(
			InternalVolumeStructPointer,
			v0->VolumeStructPointer.ToPointer(),
			v1->VolumeStructPointer.ToPointer());
	}

	IntPtr GridCullSystemClass::VolumeStruct::VolumeStructPointer::get()
	{
		return IntPtr(InternalVolumeStructPointer);
	}

	bool GridCullSystemClass::VolumeStruct::IsLeaf::get()
	{
		return GridCullSystemClassHelper::IsLeaf(InternalVolumeStructPointer);
	}

	bool GridCullSystemClass::VolumeStruct::IsEmpty::get()
	{
		return GridCullSystemClassHelper::IsEmpty(InternalVolumeStructPointer);
	}

	array<int>^ GridCullSystemClass::VolumeStruct::Min::get()
	{
		array<int>^ result = gcnew array<int>(GridCullSystemClassHelper::MinSizeCount);

		pin_ptr<int> pinnedResult = &result[0];
		int* resultPtr = pinnedResult;

		GridCullSystemClassHelper::GetMin(
			InternalVolumeStructPointer,
			resultPtr);

		return result;
	}

	void GridCullSystemClass::VolumeStruct::Min::set(array<int>^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (value->Length != static_cast<int>(GridCullSystemClassHelper::MinSizeCount))
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		pin_ptr<int> pinnedValue = &value[0];
		int* valuePtr = pinnedValue;

		GridCullSystemClassHelper::SetMin(
			InternalVolumeStructPointer,
			valuePtr);
	}

	array<int>^ GridCullSystemClass::VolumeStruct::Max::get()
	{
		array<int>^ result = gcnew array<int>(GridCullSystemClassHelper::MaxSizeCount);

		pin_ptr<int> pinnedResult = &result[0];
		int* resultPtr = pinnedResult;

		GridCullSystemClassHelper::GetMax(
			InternalVolumeStructPointer,
			resultPtr);

		return result;
	}

	void GridCullSystemClass::VolumeStruct::Max::set(array<int>^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (value->Length != static_cast<int>(GridCullSystemClassHelper::MaxSizeCount))
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		pin_ptr<int> pinnedValue = &value[0];
		int* valuePtr = pinnedValue;

		GridCullSystemClassHelper::SetMax(
			InternalVolumeStructPointer,
			valuePtr);
	}

	bool GridCullSystemClass::VolumeStruct::InternalDestroyPointer()
	{
		Imports::DestroyGridCullSystemClassVolumeStruct(InternalVolumeStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	void* GridCullSystemClass::VolumeStruct::InternalVolumeStructPointer::get()
	{
		return Pointer.ToPointer();
	}

	GridCullSystemClass::GridCullSystemClass(IntPtr pointer)
		: CullSystemClass(pointer)
	{

	}

	void GridCullSystemClass::RePartition(Vector3 min, Vector3 max, float objDim)
	{
		::Vector3 minVec;
		::Vector3 maxVec;

		Vector3::ManagedToUnmanagedVector3(min, minVec);
		Vector3::ManagedToUnmanagedVector3(max, maxVec);

		InternalGridCullSystemClassPointer->Re_Partition(minVec, maxVec, objDim);
	}

	void GridCullSystemClass::Load(IChunkLoadClass^ cLoad)
	{
		if (cLoad == nullptr || cLoad->ChunkLoadClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("cLoad");
		}

		InternalGridCullSystemClassPointer->Load(
			*reinterpret_cast<::ChunkLoadClass*>(cLoad->ChunkLoadClassPointer.ToPointer()));
	}

	void GridCullSystemClass::Save(IChunkSaveClass^ cSave)
	{
		if (cSave == nullptr || cSave->ChunkSaveClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("cSave");
		}

		InternalGridCullSystemClassPointer->Save(
			*reinterpret_cast<::ChunkSaveClass*>(cSave->ChunkSaveClassPointer.ToPointer()));
	}

	IntPtr GridCullSystemClass::GridCullSystemClassPointer::get()
	{
		return IntPtr(InternalGridCullSystemClassPointer);
	}

	int GridCullSystemClass::ObjectCount::get()
	{
		return InternalGridCullSystemClassPointer->Get_Object_Count();
	}

	void GridCullSystemClass::ObjectCount::set(int value)
	{
		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		auto& objectCount = helper->GetObjCount();

		objectCount = value;
	}

	Vector3 GridCullSystemClass::MinCellSize::get()
	{
		Vector3 result;
		::Vector3 tmp;

		InternalGridCullSystemClassPointer->Get_Min_Cell_Size(tmp);

		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	void GridCullSystemClass::MinCellSize::set(Vector3 value)
	{
		::Vector3 valueVec;

		Vector3::ManagedToUnmanagedVector3(value, valueVec);

		InternalGridCullSystemClassPointer->Set_Min_Cell_Size(valueVec);
	}

	int GridCullSystemClass::TerminationCellCount::get()
	{
		return InternalGridCullSystemClassPointer->Get_Termination_Count();
	}

	void GridCullSystemClass::TerminationCellCount::set(int value)
	{
		InternalGridCullSystemClassPointer->Set_Termination_Count(value);
	}

	bool GridCullSystemClass::MapPointToCell(Vector3 pt, [Out] int% setI, [Out] int% setJ, [Out] int% setK)
	{
		::Vector3 ptVec;

		Vector3::ManagedToUnmanagedVector3(pt, ptVec);

		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		int tmpSetI = setI;
		int tmpSetJ = setJ;
		int tmpSetK = setK;

		auto result = helper->MapPointToCell(ptVec, tmpSetI, tmpSetJ, tmpSetK);

		setI = tmpSetI;
		setJ = tmpSetJ;
		setK = tmpSetK;

		return result;
	}

	bool GridCullSystemClass::MapPointToAddress(Vector3 pt, [Out] int% setAddress)
	{
		::Vector3 ptVec;

		Vector3::ManagedToUnmanagedVector3(pt, ptVec);

		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		int tmpSetAddress = setAddress;

		auto result = helper->MapPointToAddress(ptVec, tmpSetAddress);

		setAddress = tmpSetAddress;

		return result;
	}

	int GridCullSystemClass::MapIndicesToAddress(int i, int j, int k)
	{
		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		return helper->MapIndicesToAddress(i, j, k);
	}

	void GridCullSystemClass::ClampIndicesToGrid(int% i, int% j, int% k)
	{
		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		int tmpI = i;
		int tmpJ = j;
		int tmpK = k;

		helper->ClampIndicesToGrid(&tmpI, &tmpJ, &tmpK);

		i = tmpI;
		j = tmpJ;
		k = tmpK;
	}

	AABoxClass GridCullSystemClass::ComputeBox(int i, int j, int k)
	{
		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		::AABoxClass tmp;

		helper->ComputeBox(i, j, k, &tmp);

		AABoxClass result;

		AABoxClass::UnmanagedToManagedAABoxClass(tmp, result);

		return result;
	}

	AABoxClass GridCullSystemClass::ComputeBox(GridCullSystemClass::IVolumeStruct^ vol)
	{
		if (vol == nullptr || vol->VolumeStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("vol");
		}

		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		::AABoxClass tmp;

		helper->ComputeBox(vol->VolumeStructPointer.ToPointer(), &tmp);

		AABoxClass result;

		AABoxClass::UnmanagedToManagedAABoxClass(tmp, result);

		return result;
	}

	void GridCullSystemClass::InitVolume(Vector3 boundMin, Vector3 boundMax, GridCullSystemClass::IVolumeStruct^ setVol)
	{
		if (setVol == nullptr || setVol->VolumeStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("setVol");
		}

		::Vector3 boundMinVec;
		::Vector3 boundMaxVec;

		Vector3::ManagedToUnmanagedVector3(boundMin, boundMinVec);
		Vector3::ManagedToUnmanagedVector3(boundMax, boundMaxVec);

		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		helper->InitVolume(boundMinVec, boundMaxVec, setVol->VolumeStructPointer.ToPointer());
	}

	void GridCullSystemClass::InitVolume(LineSegClass line, GridCullSystemClass::IVolumeStruct^ setVol)
	{
		if (setVol == nullptr || setVol->VolumeStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("setVol");
		}

		::LineSegClass tmp;

		LineSegClass::ManagedToUnmanagedLineSegClass(line, tmp);

		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		helper->InitVolume(tmp, setVol->VolumeStructPointer.ToPointer());
	}

	void GridCullSystemClass::InitVolume(AABoxClass box, GridCullSystemClass::IVolumeStruct^ setVol)
	{
		if (setVol == nullptr || setVol->VolumeStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("setVol");
		}

		::AABoxClass tmp;

		AABoxClass::ManagedToUnmanagedAABoxClass(box, tmp);

		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		helper->InitVolume(tmp, setVol->VolumeStructPointer.ToPointer());
	}

	void GridCullSystemClass::InitVolume(OBBoxClass box, GridCullSystemClass::IVolumeStruct^ setVol)
	{
		if (setVol == nullptr || setVol->VolumeStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("setVol");
		}

		::OBBoxClass tmp;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(box, tmp);

		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		helper->InitVolume(tmp, setVol->VolumeStructPointer.ToPointer());
	}

	void GridCullSystemClass::InitVolume(FrustumClass frustum, GridCullSystemClass::IVolumeStruct^ setVol)
	{
		if (setVol == nullptr || setVol->VolumeStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("setVol");
		}

		::FrustumClass tmp;

		FrustumClass::ManagedToUnmanagedFrustumClass(frustum, tmp);

		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		helper->InitVolume(tmp, setVol->VolumeStructPointer.ToPointer());
	}

	::CullSystemClass* GridCullSystemClass::InternalCullSystemClassPointer::get()
	{
		return InternalGridCullSystemClassPointer;
	}

	::GridCullSystemClass* GridCullSystemClass::InternalGridCullSystemClassPointer::get()
	{
		return reinterpret_cast<::GridCullSystemClass*>(Pointer.ToPointer());
	}

	float GridCullSystemClass::MaxObjExtent::get()
	{
		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		auto& maxObjExtent = helper->GetMaxObjExtent();

		return maxObjExtent;
	}

	void GridCullSystemClass::MaxObjExtent::set(float value)
	{
		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		auto& maxObjExtent = helper->GetMaxObjExtent();

		maxObjExtent = value;
	}

	Vector3 GridCullSystemClass::Origin::get()
	{
		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		auto& origin = helper->GetOrigin();

		Vector3 result;

		Vector3::UnmanagedToManagedVector3(origin, result);

		return result;
	}

	void GridCullSystemClass::Origin::set(Vector3 value)
	{
		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		auto& origin = helper->GetOrigin();

		Vector3::ManagedToUnmanagedVector3(value, origin);
	}

	Vector3 GridCullSystemClass::CellDim::get()
	{
		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		auto& cellDim = helper->GetCellDim();

		Vector3 result;

		Vector3::UnmanagedToManagedVector3(cellDim, result);

		return result;
	}

	void GridCullSystemClass::CellDim::set(Vector3 value)
	{
		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		auto& cellDim = helper->GetCellDim();

		Vector3::ManagedToUnmanagedVector3(value, cellDim);
	}

	Vector3 GridCullSystemClass::OOCellDim::get()
	{
		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		auto& ooCellDim = helper->GetOOCellDim();

		Vector3 result;

		Vector3::UnmanagedToManagedVector3(ooCellDim, result);

		return result;
	}

	void GridCullSystemClass::OOCellDim::set(Vector3 value)
	{
		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		auto& ooCellDim = helper->GetOOCellDim();

		Vector3::ManagedToUnmanagedVector3(value, ooCellDim);
	}

	array<int>^ GridCullSystemClass::CellCount::get()
	{
		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		array<int>^ result = gcnew array<int>(GridCullSystemClassHelper::CellCountSizeCount);

		pin_ptr<int> pinnedResult = &result[0];
		int* resultPtr = pinnedResult;

		helper->GetCellCount(resultPtr);

		return result;
	}

	void GridCullSystemClass::CellCount::set(array<int>^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (value->Length != static_cast<int>(GridCullSystemClassHelper::CellCountSizeCount))
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		pin_ptr<int> pinnedValue = &value[0];
		int* valuePtr = pinnedValue;

		helper->SetCellCount(valuePtr);
	}

	array<ICullableClass^>^ GridCullSystemClass::Cells::get()
	{
		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		auto cells = helper->GetCells();

		array<ICullableClass^>^ result = gcnew array<ICullableClass^>(TotalCellCount);
		for (int x = 0; x < result->Length; x++)
		{
			auto currentCell = cells[x];
			if (currentCell == nullptr)
			{
				result[x] = nullptr;
			}
			else
			{
				result[x] = gcnew CullableClass(IntPtr(currentCell));
			}
		}

		return result;
	}

	void GridCullSystemClass::Cells::set(array<ICullableClass^>^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (value->Length != TotalCellCount)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		for (int x = 0; x < value->Length; x++)
		{
			auto currentCell = value[x];
			if (currentCell == nullptr || currentCell->CullableClassPointer.ToPointer() == nullptr)
			{
				helper->SetCell(
					static_cast<std::size_t>(x),
					nullptr);
			}
			else
			{
				helper->SetCell(
					static_cast<std::size_t>(x),
					reinterpret_cast<::CullableClass*>(currentCell->CullableClassPointer.ToPointer()));
			}
		}
	}

	ICullableClass^ GridCullSystemClass::NoGridList::get()
	{
		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		auto& noGridList = helper->GetNoGridList();

		if (noGridList == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew CullableClass(IntPtr(noGridList));
		}
	}

	void GridCullSystemClass::NoGridList::set(ICullableClass^ value)
	{
		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		auto& noGridList = helper->GetNoGridList();

		if (value == nullptr || value->CullableClassPointer.ToPointer() == nullptr)
		{
			noGridList = nullptr;
		}
		else
		{
			noGridList = reinterpret_cast<::CullableClass*>(value->CullableClassPointer.ToPointer());
		}
	}

	GridCullSystemClass::IStatsStruct^ GridCullSystemClass::Stats::get()
	{
		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		auto& stats = helper->GetStats();

		return gcnew GridCullSystemClass::StatsStruct(IntPtr(&stats));
	}

	void GridCullSystemClass::Stats::set(GridCullSystemClass::IStatsStruct^ value)
	{
		if (value == nullptr || value->StatsStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		auto& stats = helper->GetStats();

		stats = *reinterpret_cast<::GridCullSystemClass::StatsStruct*>(value->StatsStructPointer.ToPointer());
	}

	int GridCullSystemClass::TotalCellCount::get()
	{
		auto helper = reinterpret_cast<GridCullSystemClassHelper*>(InternalGridCullSystemClassPointer);

		return helper->TotalCellCount();
	}

	GridLinkClass::GridLinkClass(IntPtr pointer)
		: CullLinkClass(pointer)
	{

	}

	IntPtr GridLinkClass::GridLinkClassPointer::get()
	{
		return IntPtr(InternalGridLinkClassPointer);
	}

	IntPtr GridLinkClass::GridLinkClassAutoPoolClassPointer::get()
	{
		return IntPtr(InternalGridLinkClassAutoPoolClassPointer);
	}

	int GridLinkClass::GridAddress::get()
	{
		return InternalGridLinkClassPointer->GridAddress;
	}

	void GridLinkClass::GridAddress::set(int value)
	{
		InternalGridLinkClassPointer->GridAddress = value;
	}

	ICullableClass^ GridLinkClass::Prev::get()
	{
		auto result = InternalGridLinkClassPointer->Prev;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew CullableClass(IntPtr(result));
		}
	}

	void GridLinkClass::Prev::set(ICullableClass^ value)
	{
		if (value == nullptr || value->CullableClassPointer.ToPointer() == nullptr)
		{
			InternalGridLinkClassPointer->Prev = nullptr;
		}
		else
		{
			InternalGridLinkClassPointer->Prev = reinterpret_cast<::CullableClass*>(value->CullableClassPointer.ToPointer());
		}
	}

	ICullableClass^ GridLinkClass::Next::get()
	{
		auto result = InternalGridLinkClassPointer->Next;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew CullableClass(IntPtr(result));
		}
	}

	void GridLinkClass::Next::set(ICullableClass^ value)
	{
		if (value == nullptr || value->CullableClassPointer.ToPointer() == nullptr)
		{
			InternalGridLinkClassPointer->Next = nullptr;
		}
		else
		{
			InternalGridLinkClassPointer->Next = reinterpret_cast<::CullableClass*>(value->CullableClassPointer.ToPointer());
		}
	}

	::CullLinkClass* GridLinkClass::InternalCullLinkClassPointer::get()
	{
		return InternalGridLinkClassPointer;
	}

	::AutoPoolClass<::GridLinkClass, 256>* GridLinkClass::InternalGridLinkClassAutoPoolClassPointer::get()
	{
		return InternalGridLinkClassPointer;
	}

	::GridLinkClass* GridLinkClass::InternalGridLinkClassPointer::get()
	{
		return reinterpret_cast<::GridLinkClass*>(Pointer.ToPointer());
	}

	GridListIterator::GridListIterator(ICullableClass^ head)
	{
		if (head == nullptr || head->CullableClassPointer.ToPointer() == nullptr)
		{
			Pointer = IntPtr(Imports::CreateGridListIterator(nullptr));
		}
		else
		{
			Pointer = IntPtr(Imports::CreateGridListIterator(
				reinterpret_cast<::CullableClass*>(head->CullableClassPointer.ToPointer())));
		}
	}

	GridListIterator::GridListIterator(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IGridListIterator^>^ GridListIterator::CreateGridListIterator(ICullableClass^ head)
	{
		return gcnew UnmanagedContainer<IGridListIterator^>(gcnew GridListIterator(head));
	}

	void GridListIterator::First(ICullableClass^ head)
	{
		if (head == nullptr || head->CullableClassPointer.ToPointer() == nullptr)
		{
			InternalGridListIteratorPointer->First(nullptr);
		}
		else
		{
			InternalGridListIteratorPointer->First(
				reinterpret_cast<::CullableClass*>(head->CullableClassPointer.ToPointer()));
		}
	}

	void GridListIterator::First()
	{
		InternalGridListIteratorPointer->First();
	}

	void GridListIterator::Next()
	{
		InternalGridListIteratorPointer->Next();
	}

	void GridListIterator::Prev()
	{
		InternalGridListIteratorPointer->Prev();
	}

	ICullableClass^ GridListIterator::GetObj()
	{
		auto result = InternalGridListIteratorPointer->Get_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew CullableClass(IntPtr(result));
		}
	}

	ICullableClass^ GridListIterator::PeekObj()
	{
		auto result = InternalGridListIteratorPointer->Peek_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew CullableClass(IntPtr(result));
		}
	}

	IntPtr GridListIterator::GridListIteratorPointer::get()
	{
		return IntPtr(InternalGridListIteratorPointer);
	}

	bool GridListIterator::IsDone::get()
	{
		return InternalGridListIteratorPointer->Is_Done();
	}

	bool GridListIterator::InternalDestroyPointer()
	{
		Imports::DestroyGridListIterator(InternalGridListIteratorPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::GridListIterator* GridListIterator::InternalGridListIteratorPointer::get()
	{
		return reinterpret_cast<::GridListIterator*>(Pointer.ToPointer());
	}
}