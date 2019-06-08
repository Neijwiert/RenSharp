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

#include "MBaseGameObj.h"
#include "MReferenceableClass.h"
#include "Maudiocallback.h"
#include "IUnmanagedContainer.h"
#include "Mengine_vector.h"

#pragma managed(push, off)

class ScriptableGameObj;

#pragma managed(pop)

namespace RenSharp
{

#pragma warning(push)
#pragma warning(disable : 4099 4251 4244 26495 26454)

	interface class IScriptableGameObjDef;
	interface class IScriptZoneGameObj;
	interface class IGameObjObserverClass;
	value class Vector3;
	interface class IDamageableGameObj;
	interface class IBuildingGameObj;
	interface class ISoldierGameObj;
	interface class IRenSharpGameObjObserverClass;

#pragma warning(pop) 

	public interface class IScriptableGameObj : public IBaseGameObj, public IReferenceableClass<IScriptableGameObj ^>, public IAudioCallbackClass
	{
		void PostReInit();
		
		void AddObserver(IGameObjObserverClass ^observer);

		void AddObserver(IRenSharpGameObjObserverClass^ observer);

		void AddObserver(IUnmanagedContainer<IGameObjObserverClass^>^ observer);

		void RemoveObserver(IGameObjObserverClass ^observer);

		void RemoveObserver(IRenSharpGameObjObserverClass^ observer);

		void RemoveObserver(String ^name);

		IGameObjObserverClass ^FindObserver(String ^name);

		void InsertObserver(IGameObjObserverClass ^observer);

		void InsertObserver(IRenSharpGameObjObserverClass^ observer);

		void InsertObserver(IUnmanagedContainer<IGameObjObserverClass^>^ observer);

		IScriptableGameObj ^AsScriptableGameObj();

		IDamageableGameObj ^AsDamageableGameObj();

		IBuildingGameObj ^AsBuildingGameObj();

		ISoldierGameObj ^AsSoldierGameObj();

		IScriptZoneGameObj ^AsScriptZoneGameObj();

		IReferenceableClass<IScriptableGameObj ^> ^AsReferenceableGameObj();

		property IntPtr ReferenceableGameObjPointer
		{
			IntPtr get();
		}

		property IntPtr ScriptableGameObjPointer
		{
			IntPtr get();
		}

		property IScriptableGameObjDef ^Definition
		{
			IScriptableGameObjDef ^get();
		}

		property Vector3 Position
		{
			Vector3 get();
		}

		property ISimpleDynVecClass<IGameObjObserverClass ^> ^Observers
		{
			ISimpleDynVecClass<IGameObjObserverClass ^> ^get();
		}

		property String ^Information
		{
			String ^get();
		}

		property bool IsAlwaysDirty
		{
			bool get();
		}

		property bool HasObservers
		{
			bool get();
		}
	};

	public ref class ReferenceableGameObj : public ReferenceableClass<IScriptableGameObj ^>
	{
		private:
			ReferenceableGameObj(IScriptableGameObj ^referenceData);

		public:
			ReferenceableGameObj(IntPtr pointer);

			static IUnmanagedContainer<IReferenceableClass<IScriptableGameObj ^> ^> ^CreateReferenceableGameObj(IScriptableGameObj ^referenceData);

			bool Save(IChunkSaveClass ^csave) override sealed;

			property IntPtr ReferenceableGameObjPointer
			{
				IntPtr get();
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::ReferenceableGameObj *InternalReferenceableGameObjPointer
			{
				virtual ::ReferenceableGameObj *get();
			}

			property IReferencerClass ^ReferencerListHead
			{
				IReferencerClass ^get() override sealed;
				void set(IReferencerClass ^value) override sealed;
			}

			property IScriptableGameObj ^Data
			{
				IScriptableGameObj ^get() override sealed;
			}
	};

	public ref class ScriptableGameObj : public BaseGameObj, public IScriptableGameObj
	{
		private:
			static Generic::IDictionary<IntPtr, IRenSharpGameObjObserverClass^> ^managedObservers;

			IReferenceableClass<IScriptableGameObj ^> ^referenceableGameObj;
			IAudioCallbackClass ^audioCallbackClass;

		public:
			static ScriptableGameObj();
			ScriptableGameObj(IntPtr pointer);

			static void OnManagedObserverDestructed(IntPtr observer);
			static bool IsManagedObserver(IntPtr observer);
			static bool IsManagedObserver(IGameObjObserverClass ^observer);
			static IRenSharpGameObjObserverClass^ AsManagedObserver(IntPtr observerPtr);
			static IRenSharpGameObjObserverClass^ AsManagedObserver(IGameObjObserverClass ^observer);

			bool Equals(Object ^other) override;

			virtual void OnSoundStarted(ISoundSceneObjClass ^soundObj) sealed;
			virtual void OnSoundEnded(ISoundSceneObjClass ^soundObj) sealed;
			virtual void OnLogicalHeard(IntPtr listener, IntPtr soundObj) sealed;

			virtual void PostReInit() sealed;
			virtual void AddObserver(IGameObjObserverClass ^observer) sealed;
			virtual void AddObserver(IRenSharpGameObjObserverClass^ observer) sealed;
			virtual void AddObserver(IUnmanagedContainer<IGameObjObserverClass^>^ observer) sealed;
			virtual void RemoveObserver(IGameObjObserverClass ^observer) sealed;
			virtual void RemoveObserver(IRenSharpGameObjObserverClass^ observer) sealed;
			virtual void RemoveObserver(String ^name) sealed;
			virtual IGameObjObserverClass ^FindObserver(String ^name) sealed;
			virtual void InsertObserver(IGameObjObserverClass ^observer) sealed;
			virtual void InsertObserver(IRenSharpGameObjObserverClass^ observer) sealed;
			virtual void InsertObserver(IUnmanagedContainer<IGameObjObserverClass^>^ observer) sealed;
			virtual IDamageableGameObj ^AsDamageableGameObj();
			virtual IBuildingGameObj ^AsBuildingGameObj();
			virtual ISoldierGameObj ^AsSoldierGameObj();
			IScriptableGameObj ^AsScriptableGameObj() override;
			virtual IScriptZoneGameObj ^AsScriptZoneGameObj();
			virtual IReferenceableClass<IScriptableGameObj ^> ^AsReferenceableGameObj();

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr ReferenceableGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr ScriptableGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr AudioCallbackClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDynamicVectorClass<ISoundSceneObjClass ^> ^SoundList
			{
				virtual IDynamicVectorClass<ISoundSceneObjClass ^> ^get() sealed;
				virtual void set(IDynamicVectorClass<ISoundSceneObjClass ^> ^value) sealed;
			}

#pragma push_macro("new")
#undef new

			property IScriptableGameObjDef ^Definition
			{
				virtual IScriptableGameObjDef ^get() new sealed;
			}

#pragma pop_macro("new")

			property Vector3 Position
			{
				virtual Vector3 get();
			}

			property ISimpleDynVecClass<IGameObjObserverClass ^> ^Observers
			{
				virtual ISimpleDynVecClass<IGameObjObserverClass ^> ^get() sealed;

				protected:
					void set(ISimpleDynVecClass<IGameObjObserverClass ^> ^value);
			}

			property String ^Information
			{
				virtual String ^get() sealed;
			}

			property bool IsAlwaysDirty
			{
				virtual bool get() sealed;
			}

			property bool HasObservers
			{
				virtual bool get() sealed;
			}

		internal:
			static void Shutdown();

			static void RegisterManagedObserver(IRenSharpGameObjObserverClass^ observer);
			static void UnregisterManagedObserver(IRenSharpGameObjObserverClass^ observer);

		protected:
			property ::BaseGameObj *InternalBaseGameObjPointer
			{
				::BaseGameObj *get() override;
			}

			property ::ReferenceableGameObj *InternalReferenceableGameObjPointer
			{
				virtual ::ReferenceableGameObj *get();
			}

			property ::AudioCallbackClass *InternalAudioCallbackClassPointer
			{
				virtual ::AudioCallbackClass *get();
			}

			property ::ScriptableGameObj *InternalScriptableGameObjPointer
			{
				virtual ::ScriptableGameObj *get();
			}

			property bool ObserverCreatedPending
			{
				bool get();
				void set(bool value);
			}

			property bool ObserversStarted
			{
				bool get();
				void set(bool value);
			}

			property IDynamicVectorClass<IntPtr> ^ObserverTimerList
			{
				IDynamicVectorClass<IntPtr> ^get();
				void set(IDynamicVectorClass<IntPtr> ^value);
			}

			property IDynamicVectorClass<IntPtr> ^CustomTimerList
			{
				IDynamicVectorClass<IntPtr> ^get();
				void set(IDynamicVectorClass<IntPtr> ^value);
			}
	};
}