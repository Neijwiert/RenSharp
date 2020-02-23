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
#include "MSceneClass.h"

#include "MRenderObjClass.h"
#include "Imports.h"
#include "MVector3.h"
#include "MChunkClass.h"

namespace RenSharp
{
	ref class SceneIteratorContainer : public IUnmanagedContainer<ISceneIterator ^>
	{
		private:
			bool disposedResources;
			ISceneIterator ^unmanagedObject;
			ISceneClass ^scene;

		public:
			SceneIteratorContainer(ISceneIterator ^unmanagedObject, ISceneClass ^scene)
				: disposedResources(false), unmanagedObject(unmanagedObject), scene(scene)
			{
				if (unmanagedObject == nullptr || unmanagedObject->SceneIteratorPointer.ToPointer() == nullptr)
				{
					throw gcnew ArgumentNullException("unmanagedObject");
				}
				else if (scene == nullptr || scene->SceneClassPointer.ToPointer() == nullptr)
				{
					throw gcnew ArgumentNullException("scene");
				}
			}

			~SceneIteratorContainer()
			{
				this->!SceneIteratorContainer();
			}

			bool Equals(Object ^other) override
			{
				if (other == nullptr)
				{
					return false;
				}
				else if (other == this)
				{
					return true;
				}

				IUnmanagedContainer<ISceneIterator ^> ^otherContainer = dynamic_cast<IUnmanagedContainer<ISceneIterator ^> ^>(other);
				if (otherContainer == nullptr)
				{
					return false;
				}

				if (unmanagedObject == nullptr)
				{
					return (otherContainer->UnmanagedObject == nullptr);
				}

				return unmanagedObject->Equals(otherContainer->UnmanagedObject);
			}

			int GetHashCode() override
			{
				if (UnmanagedObject == nullptr)
				{
					IntPtr zero = IntPtr::Zero;

					return zero.GetHashCode();
				}
				else
				{
					return unmanagedObject->GetHashCode();
				}
			}

			virtual void ReleaseObject() sealed
			{
				unmanagedObject = nullptr;
			}

			property ISceneIterator ^UnmanagedObject
			{
				virtual ISceneIterator ^get() sealed
				{
					return unmanagedObject;
				}

				protected:
					virtual void set(ISceneIterator ^value) sealed
					{
						unmanagedObject = value;
					}
			}

		protected:
			!SceneIteratorContainer()
			{
				if (!disposedResources)
				{
					if (unmanagedObject != nullptr && unmanagedObject->SceneIteratorPointer.ToPointer() != nullptr)
					{
						scene->DestroyIterator(unmanagedObject);
						unmanagedObject->ReleasePointer();
					}

					disposedResources = true;
				}
			}
	};

	ref class SceneClassEnumerator sealed : Generic::IEnumerator<IRenderObjClass ^>
	{
		private:
			IUnmanagedContainer<ISceneIterator ^> ^iterator;
			bool reset;
			bool disposedResources;

		public:
			SceneClassEnumerator(IUnmanagedContainer<ISceneIterator ^> ^iterator)
				: iterator(iterator), reset(true), disposedResources(false)
			{
						
			}

			~SceneClassEnumerator()
			{
				if (!disposedResources)
				{
#pragma push_macro("delete")
#undef delete
					delete iterator;
					iterator = nullptr;
#pragma pop_macro("delete")

					disposedResources = true;
				}
			}

			virtual bool MoveNext() = Generic::IEnumerator<IGenericNode ^>::MoveNext
			{
				if (reset)
				{
					iterator->UnmanagedObject->First();

					return (!iterator->UnmanagedObject->IsDone);
				}

				if (iterator->UnmanagedObject->IsDone)
				{
					return false;
				}

				iterator->UnmanagedObject->Next();

				return !iterator->UnmanagedObject->IsDone;
			}

			virtual void Reset() = Generic::IEnumerator<IGenericNode ^>::Reset
			{
				iterator->UnmanagedObject->First();
				reset = true;
			}

			property IRenderObjClass ^Current
			{
				virtual IRenderObjClass ^get() = Generic::IEnumerator<IRenderObjClass ^>::Current::get
				{
					return iterator->UnmanagedObject->CurrentItem;
				}
			}

			property Object ^Current2
			{
				virtual Object ^get() = Collections::IEnumerator::Current::get
				{
					return Current;
				}
			}
	};

	SceneIterator::SceneIterator(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool SceneIterator::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		ISceneIterator ^otherThis = dynamic_cast<ISceneIterator ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return SceneIteratorPointer.Equals(otherThis->SceneIteratorPointer);
	}

	void SceneIterator::First()
	{
		InternalSceneIteratorPointer->First();
	}

	void SceneIterator::Next()
	{
		InternalSceneIteratorPointer->Next();
	}

	IntPtr SceneIterator::SceneIteratorPointer::get()
	{
		return IntPtr(InternalSceneIteratorPointer);
	}

	bool SceneIterator::IsDone::get()
	{
		return InternalSceneIteratorPointer->Is_Done();
	}

	IRenderObjClass ^SceneIterator::CurrentItem::get()
	{
		auto result = InternalSceneIteratorPointer->Current_Item();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(result));
		}
	}

	bool SceneIterator::InternalDestroyPointer()
	{
		Imports::DestroySceneIterator(InternalSceneIteratorPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::SceneIterator *SceneIterator::InternalSceneIteratorPointer::get()
	{
		return reinterpret_cast<::SceneIterator *>(Pointer.ToPointer());
	}

	SceneClass::SceneClass(IntPtr pointer)
		: RefCountClass(pointer)
	{

	}

	void SceneClass::AddRenderObject(IRenderObjClass ^obj)
	{
		if (obj == nullptr || obj->RenderObjClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalSceneClassPointer->Add_Render_Object(
			reinterpret_cast<::RenderObjClass *>(obj->RenderObjClassPointer.ToPointer()));
	}

	void SceneClass::RemoveRenderObject(IRenderObjClass ^obj)
	{
		if (obj == nullptr || obj->RenderObjClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalSceneClassPointer->Remove_Render_Object(
			reinterpret_cast<::RenderObjClass *>(obj->RenderObjClassPointer.ToPointer()));
	}

	IUnmanagedContainer<ISceneIterator ^> ^SceneClass::CreateIterator(bool onlyVisible)
	{
		auto result = InternalSceneClassPointer->Create_Iterator(onlyVisible);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SceneIteratorContainer(gcnew SceneIterator(IntPtr(result)), this);
		}
	}

	void SceneClass::DestroyIterator(ISceneIterator ^it)
	{
		if (it == nullptr || it->SceneIteratorPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("it");
		}

		InternalSceneClassPointer->Destroy_Iterator(
			reinterpret_cast<::SceneIterator *>(it->SceneIteratorPointer.ToPointer()));
	}

	void SceneClass::GetFogRange([Out] float %start, [Out] float %end)
	{
		float tmpStart;
		float tmpEnd;

		InternalSceneClassPointer->Get_Fog_Range(&tmpStart, &tmpEnd);

		start = tmpStart;
		end = tmpEnd;
	}

	void SceneClass::SetFogRange(float start, float end)
	{
		InternalSceneClassPointer->Set_Fog_Range(start, end);
	}

	void SceneClass::Register(IRenderObjClass ^obj, ISceneClass::RegType forWhat)
	{
		if (obj == nullptr || obj->RenderObjClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalSceneClassPointer->Register(
			reinterpret_cast<::RenderObjClass *>(obj->RenderObjClassPointer.ToPointer()),
			static_cast<::SceneClass::RegType>(forWhat));
	}

	void SceneClass::Unregister(IRenderObjClass ^obj, ISceneClass::RegType forWhat)
	{
		if (obj == nullptr || obj->RenderObjClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalSceneClassPointer->Unregister(
			reinterpret_cast<::RenderObjClass *>(obj->RenderObjClassPointer.ToPointer()),
			static_cast<::SceneClass::RegType>(forWhat));
	}

	float SceneClass::ComputePointVisibility(IntPtr rInfo, Vector3 point)
	{
		if (rInfo.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("rInfo");
		}

		::Vector3 pointVec;

		Vector3::ManagedToUnmanagedVector3(point, pointVec);

		return InternalSceneClassPointer->Compute_Point_Visibility(
			*reinterpret_cast<::RenderInfoClass *>(rInfo.ToPointer()),
			pointVec);
	}

	void SceneClass::Save(IChunkSaveClass ^cSave)
	{
		if (cSave == nullptr || cSave->ChunkSaveClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("cSave");
		}

		InternalSceneClassPointer->Save(
			*reinterpret_cast<::ChunkSaveClass *>(cSave->ChunkSaveClassPointer.ToPointer()));
	}

	void SceneClass::Load(IChunkLoadClass ^cLoad)
	{
		if (cLoad == nullptr || cLoad->ChunkLoadClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("cLoad");
		}

		InternalSceneClassPointer->Load(
			*reinterpret_cast<::ChunkLoadClass *>(cLoad->ChunkLoadClassPointer.ToPointer()));
	}

	void SceneClass::CustomizedRender(IntPtr rInfo)
	{
		if (rInfo.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("rInfo");
		}

		InternalSceneClassPointer->Customized_Render(
			*reinterpret_cast<::RenderInfoClass *>(rInfo.ToPointer()));
	}

	void SceneClass::PreRenderProcessing(IntPtr rInfo)
	{
		if (rInfo.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("rInfo");
		}

		InternalSceneClassPointer->Pre_Render_Processing(
			*reinterpret_cast<::RenderInfoClass *>(rInfo.ToPointer()));
	}

	void SceneClass::PostRenderProcessing(IntPtr rInfo)
	{
		if (rInfo.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("rInfo");
		}

		InternalSceneClassPointer->Post_Render_Processing(
			*reinterpret_cast<::RenderInfoClass *>(rInfo.ToPointer()));
	}

	Generic::IEnumerator<IRenderObjClass ^> ^SceneClass::GetEnumerator()
	{
		return gcnew SceneClassEnumerator(CreateIterator(false));
	}

	Collections::IEnumerator^ SceneClass::GetEnumerator2()
	{
		return GetEnumerator();
	}

	IntPtr SceneClass::SceneClassPointer::get()
	{
		return IntPtr(InternalSceneClassPointer);
	}

	Vector3 SceneClass::AmbientLight::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalSceneClassPointer->Get_Ambient_Light(), result);

		return result;
	}

	void SceneClass::AmbientLight::set(Vector3 value)
	{
		::Vector3 tmp;

		Vector3::ManagedToUnmanagedVector3(value, tmp);

		InternalSceneClassPointer->Set_Ambient_Light(tmp);
	}

	bool SceneClass::FogEnabled::get()
	{
		return InternalSceneClassPointer->Get_Fog_Enable();
	}

	void SceneClass::FogEnabled::set(bool value)
	{
		InternalSceneClassPointer->Set_Fog_Enable(value);
	}

	Vector3 SceneClass::FogColor::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalSceneClassPointer->Get_Fog_Color(), result);

		return result;
	}

	void SceneClass::FogColor::set(Vector3 value)
	{
		::Vector3 tmp;

		Vector3::ManagedToUnmanagedVector3(value, tmp);

		InternalSceneClassPointer->Set_Fog_Color(tmp);
	}

	ISceneClass::PolyRenderType SceneClass::PolygonModel::get()
	{
		return static_cast<ISceneClass::PolyRenderType>(InternalSceneClassPointer->Get_Polygon_Mode());
	}

	::RefCountClass *SceneClass::InternalRefCountClassPointer::get()
	{
		return InternalSceneClassPointer;
	}

	::SceneClass *SceneClass::InternalSceneClassPointer::get()
	{
		return reinterpret_cast<::SceneClass *>(Pointer.ToPointer());
	}
}