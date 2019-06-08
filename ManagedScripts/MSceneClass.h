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

#include "Mengine_vector.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <SceneClass.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Runtime::InteropServices;

namespace RenSharp
{
	interface class IRenderObjClass;
	value class Vector3;
	interface class IChunkSaveClass;
	interface class IChunkLoadClass;

	public interface class ISceneIterator : public IUnmanagedObject
	{
		void First();

		void Next();

		property IntPtr SceneIteratorPointer
		{
			IntPtr get();
		}

		property bool IsDone
		{
			bool get();
		}

		property IRenderObjClass ^CurrentItem
		{
			IRenderObjClass ^get();
		}
	};

	public ref class SceneIterator : public AbstractUnmanagedObject, public ISceneIterator
	{
		public:
			SceneIterator(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual void First() sealed;
			virtual void Next() sealed;

			property IntPtr SceneIteratorPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsDone
			{
				virtual bool get() sealed;
			}

			property IRenderObjClass ^CurrentItem
			{
				virtual IRenderObjClass ^get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::SceneIterator *InternalSceneIteratorPointer
			{
				virtual ::SceneIterator *get();
			}
	};

	public interface class ISceneClass 
		: 
		public IRefCountClass,
		public Collections::IEnumerable,
		public Generic::IEnumerable<IRenderObjClass ^>
	{
		enum class RegType : int
		{
			OnFrameUpdate = ::SceneClass::RegType::ON_FRAME_UPDATE,
			Light = ::SceneClass::RegType::LIGHT,
			Release = ::SceneClass::RegType::RELEASE
		};

		enum class PolyRenderType : int
		{
			Point = ::SceneClass::PolyRenderType::POINT,
			Line = ::SceneClass::PolyRenderType::LINE,
			Fill = ::SceneClass::PolyRenderType::FILL
		};

		enum class ExtraPassPolyRenderType : int
		{
			ExtraPassDisable = ::SceneClass::ExtraPassPolyRenderType::EXTRA_PASS_DISABLE,
			ExtraPassLine = ::SceneClass::ExtraPassPolyRenderType::EXTRA_PASS_LINE,
			ExtraPassClearLine = ::SceneClass::ExtraPassPolyRenderType::EXTRA_PASS_CLEAR_LINE
		};

		void AddRenderObject(IRenderObjClass ^obj);

		void RemoveRenderObject(IRenderObjClass ^obj);

		IUnmanagedContainer<ISceneIterator ^> ^CreateIterator(bool onlyVisible);

		void DestroyIterator(ISceneIterator ^it);

		void GetFogRange([Out] float %start, [Out] float %end);

		void SetFogRange(float start, float end);

		void Register(IRenderObjClass ^obj, RegType forWhat);

		void Unregister(IRenderObjClass ^obj, RegType forWhat);

		float ComputePointVisibility(IntPtr rInfo, Vector3 point);

		void Save(IChunkSaveClass ^cSave);

		void Load(IChunkLoadClass ^cLoad);

		void CustomizedRender(IntPtr rInfo);

		void PreRenderProcessing(IntPtr rInfo);

		void PostRenderProcessing(IntPtr rInfo);

		property IntPtr SceneClassPointer
		{
			IntPtr get();
		}

		property Vector3 AmbientLight
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property bool FogEnabled
		{
			bool get();
			void set(bool value);
		}

		property Vector3 FogColor
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property PolyRenderType PolygonModel
		{
			PolyRenderType get();
		}
	};

	public ref class SceneClass : public RefCountClass, public ISceneClass
	{
		public:
			SceneClass(IntPtr pointer);

			virtual void AddRenderObject(IRenderObjClass ^obj) sealed;
			virtual void RemoveRenderObject(IRenderObjClass ^obj) sealed;
			virtual IUnmanagedContainer<ISceneIterator ^> ^CreateIterator(bool onlyVisible) sealed;
			virtual void DestroyIterator(ISceneIterator ^it) sealed;
			virtual void GetFogRange([Out] float %start, [Out] float %end) sealed;
			virtual void SetFogRange(float start, float end) sealed;
			virtual void Register(IRenderObjClass ^obj, ISceneClass::RegType forWhat) sealed;
			virtual void Unregister(IRenderObjClass ^obj, ISceneClass::RegType forWhat) sealed;
			virtual float ComputePointVisibility(IntPtr rInfo, Vector3 point) sealed;
			virtual void Save(IChunkSaveClass ^cSave) sealed;
			virtual void Load(IChunkLoadClass ^cLoad) sealed;
			virtual void CustomizedRender(IntPtr rInfo) sealed;
			virtual void PreRenderProcessing(IntPtr rInfo) sealed;
			virtual void PostRenderProcessing(IntPtr rInfo) sealed;

			virtual Generic::IEnumerator<IRenderObjClass ^> ^GetEnumerator() = Generic::IEnumerable<IRenderObjClass ^>::GetEnumerator;
			virtual Collections::IEnumerator^ GetEnumerator2() = Collections::IEnumerable::GetEnumerator;

			property IntPtr SceneClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property Vector3 AmbientLight
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property bool FogEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property Vector3 FogColor
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property ISceneClass::PolyRenderType PolygonModel
			{
				virtual ISceneClass::PolyRenderType get() sealed;
			}

		protected:
			property ::RefCountClass *InternalRefCountClassPointer
			{
				::RefCountClass *get() override;
			}

			property ::SceneClass *InternalSceneClassPointer
			{
				virtual ::SceneClass *get();
			}
	};
}