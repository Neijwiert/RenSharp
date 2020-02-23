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

#include "stdafx.h"
#include "MMeshClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <MeshClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "Imports.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{

#pragma managed(push, off)

	class MeshClassHelper : public ::MeshClass
	{
		private:
			MeshClassHelper() = default;

		public:
			::MeshModelClass *&GetModel()
			{
				return Model;
			}

			::DecalMeshClass *&GetDecalMesh()
			{
				return DecalMesh;
			}

			unsigned int &GetMeshDebugId()
			{
				return MeshDebugId;
			}

			unsigned int *&GetUserLighting()
			{
				return UserLighting;
			}

			::MultiListClass<::DX8PolygonRendererClass> &GetPolygonRendererList()
			{
				return PolygonRendererList;
			}
	};

#pragma managed(pop)

	MeshClass::MeshClass(IntPtr pointer)
		: RenderObjClass(pointer)
	{

	}

	IntPtr MeshClass::PeekModel()
	{
		return IntPtr(InternalMeshClassPointer->Peek_Model());
	}

	IntPtr MeshClass::MeshClassPointer::get()
	{
		return IntPtr(InternalMeshClassPointer);
	}

	IntPtr MeshClass::LightEnvironment::get()
	{
		return IntPtr(InternalMeshClassPointer->Get_Lighting_Environment());
	}

	void MeshClass::LightEnvironment::set(IntPtr value)
	{
		InternalMeshClassPointer->Set_Lighting_Environment(reinterpret_cast<::LightEnvironmentClass *>(value.ToPointer()));
	}

	IMeshClass ^MeshClass::NextVisibleSkin::get()
	{
		auto result = InternalMeshClassPointer->Peek_Next_Visible_Skin();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew MeshClass(IntPtr(result));
		}
	}

	void MeshClass::NextVisibleSkin::set(IMeshClass ^value)
	{
		if (value == nullptr || value->MeshClassPointer.ToPointer() == nullptr)
		{
			InternalMeshClassPointer->Set_Next_Visible_Skin(nullptr);
		}
		else
		{
			InternalMeshClassPointer->Set_Next_Visible_Skin(
				reinterpret_cast<::MeshClass *>(value->MeshClassPointer.ToPointer()));
		}
	}

	int MeshClass::BaseVertexOffset::get()
	{
		return InternalMeshClassPointer->Get_Base_Vertex_Offset();
	}

	void MeshClass::BaseVertexOffset::set(int value)
	{
		InternalMeshClassPointer->Set_Base_Vertex_Offset(value);
	}

	unsigned int MeshClass::MeshDebugId::get()
	{
		return InternalMeshClassPointer->Get_Debug_Id();
	}

	void MeshClass::MeshDebugId::set(unsigned int value)
	{
		auto helper = reinterpret_cast<MeshClassHelper *>(InternalMeshClassPointer);

		auto &meshDebugId = helper->GetMeshDebugId();

		meshDebugId = value;
	}

	bool MeshClass::IsDisabledByDebugger::get()
	{
		return InternalMeshClassPointer->Is_Disabled_By_Debugger();
	}

	void MeshClass::IsDisabledByDebugger::set(bool value)
	{
		InternalMeshClassPointer->Set_Debugger_Disable(value);
	}

	::PostLoadableClass *MeshClass::InternalPostLoadableClassPointer::get()
	{
		return InternalMeshClassPointer;
	}

	::PersistClass *MeshClass::InternalPersistClassPointer::get()
	{
		return InternalMeshClassPointer;
	}

	::MultiListObjectClass *MeshClass::InternalMultiListObjectClassPointer::get()
	{
		return InternalMeshClassPointer;
	}

	::RenderObjClass *MeshClass::InternalRenderObjClassPointer::get()
	{
		return InternalMeshClassPointer;
	}

	::MeshClass *MeshClass::InternalMeshClassPointer::get()
	{
		return reinterpret_cast<::MeshClass *>(Pointer.ToPointer());
	}

	IntPtr MeshClass::Model::get()
	{
		auto helper = reinterpret_cast<MeshClassHelper *>(InternalMeshClassPointer);

		auto &model = helper->GetModel();

		return IntPtr(model);
	}

	void MeshClass::Model::set(IntPtr value)
	{
		auto helper = reinterpret_cast<MeshClassHelper *>(InternalMeshClassPointer);

		auto &model = helper->GetModel();

		model = reinterpret_cast<::MeshModelClass *>(value.ToPointer());
	}

	IntPtr MeshClass::DecalMesh::get()
	{
		auto helper = reinterpret_cast<MeshClassHelper *>(InternalMeshClassPointer);

		auto &decalMesh = helper->GetDecalMesh();

		return IntPtr(decalMesh);
	}

	void MeshClass::DecalMesh::set(IntPtr value)
	{
		auto helper = reinterpret_cast<MeshClassHelper *>(InternalMeshClassPointer);

		auto &decalMesh = helper->GetDecalMesh();

		decalMesh = reinterpret_cast<::DecalMeshClass *>(value.ToPointer());
	}

	IntPtr MeshClass::PolygonRendererList::get()
	{
		auto helper = reinterpret_cast<MeshClassHelper *>(InternalMeshClassPointer);

		auto &polygonRenderList = helper->GetPolygonRendererList();

		return IntPtr(&polygonRenderList);
	}

	PrimitivePrototypeClass::PrimitivePrototypeClass(IRenderObjClass ^proto)
	{
		if (proto == nullptr || proto->RenderObjClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("proto");
		}

		Pointer = IntPtr(Imports::CreatePrimitivePrototypeClass(reinterpret_cast<::RenderObjClass *>(proto->RenderObjClassPointer.ToPointer())));
	}

	PrimitivePrototypeClass::PrimitivePrototypeClass(IntPtr pointer)
		: PrototypeClass(pointer)
	{

	}

	IUnmanagedContainer<IPrimitivePrototypeClass ^> ^PrimitivePrototypeClass::CreatePrimitivePrototypeClass(IRenderObjClass ^proto)
	{
		return gcnew UnmanagedContainer<IPrimitivePrototypeClass ^>(gcnew PrimitivePrototypeClass(proto));
	}

	IntPtr PrimitivePrototypeClass::PrimitivePrototypeClassPointer::get()
	{
		return IntPtr(InternalPrimitivePrototypeClassPointer);
	}

	::PrototypeClass *PrimitivePrototypeClass::InternalPrototypeClassPointer::get()
	{
		return InternalPrimitivePrototypeClassPointer;
	}

	::PrimitivePrototypeClass *PrimitivePrototypeClass::InternalPrimitivePrototypeClassPointer::get()
	{
		return reinterpret_cast<::PrimitivePrototypeClass *>(Pointer.ToPointer());
	}

	MeshLoaderClass::MeshLoaderClass(IntPtr pointer)
		: PrototypeLoaderClass(pointer)
	{

	}

	IntPtr MeshLoaderClass::MeshLoaderClassPointer::get()
	{
		return IntPtr(InternalMeshLoaderClassPointer);
	}

	bool MeshLoaderClass::InternalDestroyPointer()
	{
		return false;
	}

	::PrototypeLoaderClass *MeshLoaderClass::InternalPrototypeLoaderClassPointer::get()
	{
		return InternalMeshLoaderClassPointer;
	}

	::MeshLoaderClass *MeshLoaderClass::InternalMeshLoaderClassPointer::get()
	{
		return reinterpret_cast<::MeshLoaderClass *>(Pointer.ToPointer());
	}
}