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
#include "MScriptableGameObj.h"
#include "Mda_gameobj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <ScriptableGameObj.h>
#include <ScriptableGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "MChunkClass.h"
#include "MReferencerClass.h"
#include "MScriptableGameObjDef.h"
#include "Mscripts.h"
#include "MGameObjObserverClassPtrSimpleDynVecClass.h"
#include "MGameObjObserverTimerClassPtrDynamicVectorClass.h"
#include "MGameObjCustomTimerClassPtrDynamicVectorClass.h"
#include "MVector3.h"
#include "RenSharpGameObjObserverClass.h"

namespace RenSharp
{
#pragma managed(push, off)

	class ReferenceableGameObjHelper : public ::ReferenceableClass<::ScriptableGameObj>
	{
		private:
			ReferenceableGameObjHelper()
				: ::ReferenceableClass<::ScriptableGameObj>(nullptr)
			{
			}

		public:
			::ReferencerClass *GetReferencerListHead() const
			{
				return ReferencerListHead;
			}

			void SetReferencerListHead(::ReferencerClass *value)
			{
				ReferencerListHead = value;
			}

			::ScriptableGameObj *GetData() const
			{
				return Get_Data();
			}
	};

	class ScriptableGameObjHelper : public ::ScriptableGameObj
	{
		private:
			ScriptableGameObjHelper() = default;

		public:
			bool &GetObserverCreatedPending()
			{
				return ObserverCreatedPending;
			}

			bool &GetObserversStarted()
			{
				return ObserversStarted;
			}

			::SimpleDynVecClass<::GameObjObserverClass *> &GetObservers()
			{
				return Observers;
			}

			::DynamicVectorClass<::GameObjObserverTimerClass *> &GetObserverTimerList()
			{
				return ObserverTimerList;
			}

			::DynamicVectorClass<::GameObjCustomTimerClass *> &GetCustomTimerList()
			{
				return CustomTimerList;
			}
	};

#pragma managed(pop)

	ReferenceableGameObj::ReferenceableGameObj(IScriptableGameObj ^referenceData)
		: ReferenceableClass<IScriptableGameObj ^>()
	{
		if (referenceData == nullptr || referenceData->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			Pointer = IntPtr(Imports::CreateReferenceableGameObj(nullptr));
		}
		else
		{
			Pointer = IntPtr(Imports::CreateReferenceableGameObj(reinterpret_cast<::ScriptableGameObj *>(referenceData->ScriptableGameObjPointer.ToPointer())));
		}
	}

	ReferenceableGameObj::ReferenceableGameObj(IntPtr pointer)
		: ReferenceableClass<IScriptableGameObj ^>(pointer)
	{

	}

	IUnmanagedContainer<IReferenceableClass<IScriptableGameObj ^> ^> ^ReferenceableGameObj::CreateReferenceableGameObj(IScriptableGameObj ^referenceData)
	{
		return gcnew UnmanagedContainer<IReferenceableClass<IScriptableGameObj ^> ^>(gcnew ReferenceableGameObj(referenceData));
	}

	bool ReferenceableGameObj::Save(IChunkSaveClass ^csave)
	{
		if (csave == nullptr || csave->ChunkSaveClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("csave");
		}

		return InternalReferenceableGameObjPointer->Save(*reinterpret_cast<::ChunkSaveClass *>(csave->ChunkSaveClassPointer.ToPointer()));
	}

	IntPtr ReferenceableGameObj::ReferenceableGameObjPointer::get()
	{
		return IntPtr(InternalReferenceableGameObjPointer);
	}

	bool ReferenceableGameObj::InternalDestroyPointer()
	{
		Imports::DestroyReferenceableGameObj(InternalReferenceableGameObjPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::ReferenceableGameObj *ReferenceableGameObj::InternalReferenceableGameObjPointer::get()
	{
		return reinterpret_cast<::ReferenceableGameObj *>(Pointer.ToPointer());
	}

	IReferencerClass ^ReferenceableGameObj::ReferencerListHead::get()
	{
		auto helper = reinterpret_cast<ReferenceableGameObjHelper *>(InternalReferenceableGameObjPointer);
		auto result = helper->GetReferencerListHead();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ReferencerClass(IntPtr(result));
		}
	}

	void ReferenceableGameObj::ReferencerListHead::set(IReferencerClass ^value)
	{
		auto helper = reinterpret_cast<ReferenceableGameObjHelper *>(InternalReferenceableGameObjPointer);
		if (value == nullptr || value->ReferencerClassPointer.ToPointer() == nullptr)
		{
			helper->SetReferencerListHead(nullptr);
		}
		else
		{
			helper->SetReferencerListHead(reinterpret_cast<::ReferencerClass *>(value->ReferencerClassPointer.ToPointer()));
		}
	}

	IScriptableGameObj ^ReferenceableGameObj::Data::get()
	{
		auto helper = reinterpret_cast<ReferenceableGameObjHelper *>(InternalReferenceableGameObjPointer);
		auto result = helper->GetData();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	static ScriptableGameObj::ScriptableGameObj()
	{
		managedObservers = gcnew Generic::Dictionary<IntPtr, IRenSharpGameObjObserverClass^>();
	}

	ScriptableGameObj::ScriptableGameObj(IntPtr pointer)
		:  BaseGameObj(pointer)
		
	{
		referenceableGameObj = gcnew ReferenceableGameObj(IntPtr(InternalReferenceableGameObjPointer));
		audioCallbackClass = gcnew AudioCallbackClass(IntPtr(InternalAudioCallbackClassPointer));
	}

	void ScriptableGameObj::OnManagedObserverDestructed(IntPtr observer)
	{
		IRenSharpGameObjObserverClass^ managedObserver = AsManagedObserver(observer);
		if (managedObserver != nullptr && managedObserver->IsAttached)
		{
			managedObserver->DestroyPointer = false;

#pragma push_macro("delete")
#undef delete

			delete managedObserver;
			managedObserver = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool ScriptableGameObj::Equals(Object ^other)
	{
		if (BaseGameObj::Equals(other))
		{
			return true;
		}

		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		auto otherUnmanagedObj = dynamic_cast<IUnmanagedObject ^>(other);
		if (otherUnmanagedObj == nullptr || otherUnmanagedObj->Pointer.Equals(IntPtr::Zero))
		{
			return false;
		}

		auto otherReferenceableGameObj = dynamic_cast<IReferenceableClass<IScriptableGameObj ^> ^>(other);
		if (otherReferenceableGameObj != nullptr)
		{
			if (referenceableGameObj->Equals(otherReferenceableGameObj))
			{
				return true;
			}
		}

		auto otherAudioCallbackClass = dynamic_cast<IAudioCallbackClass ^>(other);
		if (otherAudioCallbackClass != nullptr)
		{
			if (audioCallbackClass->Equals(otherAudioCallbackClass))
			{
				return true;
			}
		}

		auto otherScriptableGameObj = dynamic_cast<IScriptableGameObj ^>(other);
		if (otherScriptableGameObj != nullptr)
		{
			if (ScriptableGameObjPointer.Equals(otherScriptableGameObj->ScriptableGameObjPointer))
			{
				return true;
			}
		}

		return false;
	}

	void ScriptableGameObj::OnSoundStarted(ISoundSceneObjClass ^soundObj)
	{
		audioCallbackClass->OnSoundStarted(soundObj);
	}

	void ScriptableGameObj::OnSoundEnded(ISoundSceneObjClass ^soundObj)
	{
		audioCallbackClass->OnSoundEnded(soundObj);
	}

	void ScriptableGameObj::OnLogicalHeard(IntPtr listener, IntPtr soundObj)
	{
		audioCallbackClass->OnLogicalHeard(listener, soundObj);
	}

	void ScriptableGameObj::PostReInit()
	{
		InternalScriptableGameObjPointer->Post_Re_Init();
	}

	void ScriptableGameObj::AddObserver(IGameObjObserverClass ^observer)
	{
		if (observer == nullptr || observer->GameObjObserverClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}
		
		if (observer->IsManagedObserver)
		{
			AddObserver(observer->AsManagedObserver());
		}
		else
		{
			InternalScriptableGameObjPointer->Add_Observer(reinterpret_cast<::GameObjObserverClass*>(observer->GameObjObserverClassPointer.ToPointer()));
		}
	}

	void ScriptableGameObj::AddObserver(IRenSharpGameObjObserverClass^ observer)
	{
		if (observer == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}
		
		if (!observer->IsAttached)
		{
			observer->AttachToUnmanagedObject();
		}

		if (!observer->IsRegistered)
		{
			observer->RegisterManagedObject();
		}

		InternalScriptableGameObjPointer->Add_Observer(
			reinterpret_cast<::GameObjObserverClass *>(observer->DAGameObjObserverClassPointer.ToPointer()));
	}

	void ScriptableGameObj::AddObserver(IUnmanagedContainer<IGameObjObserverClass^>^ observer)
	{
		if (observer == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}
		else if (observer->UnmanagedObject == nullptr || observer->UnmanagedObject->GameObjObserverClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentException("Unmanaged container is empty.");
		}

		AddObserver(observer->UnmanagedObject);
		observer->ReleaseObject();
	}
	
	void ScriptableGameObj::RemoveObserver(IGameObjObserverClass ^observer)
	{
		if (observer == nullptr || observer->GameObjObserverClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}

		InternalScriptableGameObjPointer->Remove_Observer(reinterpret_cast<::GameObjObserverClass *>(observer->GameObjObserverClassPointer.ToPointer()));
	}

	void ScriptableGameObj::RemoveObserver(IRenSharpGameObjObserverClass^ observer)
	{
		if (observer == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}
		
		if (!observer->IsAttached)
		{
			observer->AttachToUnmanagedObject();
		}

		if (!observer->IsRegistered)
		{
			observer->RegisterManagedObject();
		}

		InternalScriptableGameObjPointer->Remove_Observer(reinterpret_cast<::GameObjObserverClass *>(observer->DAGameObjObserverClassPointer.ToPointer()));
	}

	void ScriptableGameObj::RemoveObserver(String ^name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			InternalScriptableGameObjPointer->Remove_Observer(reinterpret_cast<char *>(nameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	IGameObjObserverClass ^ScriptableGameObj::FindObserver(String ^name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			auto result = InternalScriptableGameObjPointer->Find_Observer(reinterpret_cast<char *>(nameHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return GameObjObserverClass::CreateGameObjObserverClassWrapper(result);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	void ScriptableGameObj::InsertObserver(IGameObjObserverClass ^observer)
	{
		if (observer == nullptr || observer->GameObjObserverClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}
		
		if (observer->IsManagedObserver)
		{
			InsertObserver(observer->AsManagedObserver());
		}
		else
		{
			InternalScriptableGameObjPointer->Insert_Observer(reinterpret_cast<::GameObjObserverClass*>(observer->GameObjObserverClassPointer.ToPointer()));
		}
	}

	void ScriptableGameObj::InsertObserver(IRenSharpGameObjObserverClass^ observer)
	{
		if (observer == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}
		
		if (!observer->IsAttached)
		{
			observer->AttachToUnmanagedObject();
		}

		if (!observer->IsRegistered)
		{
			observer->RegisterManagedObject();
		}

		InternalScriptableGameObjPointer->Insert_Observer(
			reinterpret_cast<::GameObjObserverClass *>(observer->DAGameObjObserverClassPointer.ToPointer()));
	}

	void ScriptableGameObj::InsertObserver(IUnmanagedContainer<IGameObjObserverClass^>^ observer)
	{
		if (observer == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}
		else if (observer->UnmanagedObject == nullptr || observer->UnmanagedObject->GameObjObserverClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentException("Unmanaged container is empty.");
		}

		InsertObserver(observer->UnmanagedObject);
		observer->ReleaseObject();
	}

	IntPtr ScriptableGameObj::Pointer::get()
	{
		return BaseGameObj::Pointer::get();
	}

	void ScriptableGameObj::Pointer::set(IntPtr value)
	{
		BaseGameObj::Pointer::set(value);

		if (Pointer == IntPtr::Zero)
		{
			referenceableGameObj = nullptr;
			audioCallbackClass = nullptr;
		}
		else
		{
			referenceableGameObj = gcnew ReferenceableGameObj(IntPtr(InternalReferenceableGameObjPointer));
			audioCallbackClass = gcnew AudioCallbackClass(IntPtr(InternalAudioCallbackClassPointer));
		}
	}

	IntPtr ScriptableGameObj::ReferenceableGameObjPointer::get()
	{
		return IntPtr(InternalReferenceableGameObjPointer);
	}

	IntPtr ScriptableGameObj::ScriptableGameObjPointer::get()
	{
		return IntPtr(InternalScriptableGameObjPointer);
	}

	IntPtr ScriptableGameObj::AudioCallbackClassPointer::get()
	{
		return IntPtr(InternalAudioCallbackClassPointer);
	}
	
	IDynamicVectorClass<ISoundSceneObjClass ^> ^ScriptableGameObj::SoundList::get()
	{
		return audioCallbackClass->SoundList;
	}

	void ScriptableGameObj::SoundList::set(IDynamicVectorClass<ISoundSceneObjClass ^> ^value)
	{
		audioCallbackClass->SoundList = value;
	}

	IScriptableGameObjDef ^ScriptableGameObj::Definition::get()
	{
		return safe_cast<IScriptableGameObjDef^>(DefinitionClass::CreateDefinitionClassWrapper(&InternalScriptableGameObjPointer->Get_Definition()));
	}

	Vector3 ScriptableGameObj::Position::get()
	{
		::Vector3 tmp;
		InternalScriptableGameObjPointer->Get_Position(&tmp);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	ISimpleDynVecClass<IGameObjObserverClass ^> ^ScriptableGameObj::Observers::get()
	{
		auto result = const_cast<::SimpleDynVecClass<::GameObjObserverClass *> *>(&InternalScriptableGameObjPointer->Get_Observers());

		return gcnew GameObjObserverClassPtrSimpleDynVecClass(IntPtr(result));
	}

	void ScriptableGameObj::Observers::set(ISimpleDynVecClass<IGameObjObserverClass ^> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<ScriptableGameObjHelper *>(InternalScriptableGameObjPointer);

		auto &observers = helper->GetObservers();

		observers = *reinterpret_cast<::SimpleDynVecClass<::GameObjObserverClass *> *>(value->Pointer.ToPointer());
	}

	String ^ScriptableGameObj::Information::get()
	{
		::StringClass tmp;
		InternalScriptableGameObjPointer->Get_Information(tmp);

		return gcnew String(tmp.Peek_Buffer());
	}

	bool ScriptableGameObj::IsAlwaysDirty::get()
	{
		return InternalScriptableGameObjPointer->Is_Always_Dirty();
	}

	bool ScriptableGameObj::HasObservers::get()
	{
		return InternalScriptableGameObjPointer->hasObservers();
	}

	void ScriptableGameObj::Shutdown()
	{
		auto tmpManagedObservers = gcnew Generic::Dictionary<IntPtr, IRenSharpGameObjObserverClass^>(managedObservers);

		for each (auto observer in tmpManagedObservers->Values)
		{
#pragma push_macro("delete")
#undef delete

			delete observer;
			observer = nullptr;

#pragma pop_macro("delete")
		}

		tmpManagedObservers->Clear();
		managedObservers->Clear();
	}

	void ScriptableGameObj::RenSharpThink()
	{
		for each (auto observer in managedObservers->Values)
		{
			observer->Think(observer->Owner);
		}
	}

	void ScriptableGameObj::RegisterManagedObserver(IRenSharpGameObjObserverClass^ observer)
	{
		if (observer == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}
		else if (!observer->IsAttached)
		{
			throw gcnew ArgumentException("Observer is not attached");
		}
		else if (Imports::IsShuttingDown())
		{
			throw gcnew NotSupportedException("Engine is shutting down");
		}

		managedObservers->Add(observer->DAGameObjObserverClassPointer, observer);
	}

	void ScriptableGameObj::UnregisterManagedObserver(IRenSharpGameObjObserverClass^ observer)
	{
		if (observer == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}

		managedObservers->Remove(observer->DAGameObjObserverClassPointer);
	}

	bool ScriptableGameObj::IsManagedObserver(IntPtr observer)
	{
		return managedObservers->ContainsKey(observer);
	}

	bool ScriptableGameObj::IsManagedObserver(IGameObjObserverClass ^observer)
	{
		if (observer == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}

		return IsManagedObserver(observer->GameObjObserverClassPointer);
	}

	IRenSharpGameObjObserverClass^ ScriptableGameObj::AsManagedObserver(IntPtr observerPtr)
	{
		IRenSharpGameObjObserverClass^ result = nullptr;
		managedObservers->TryGetValue(observerPtr, result);

		return result;
	}

	IRenSharpGameObjObserverClass^ ScriptableGameObj::AsManagedObserver(IGameObjObserverClass ^observer)
	{
		if (observer == nullptr || observer->GameObjObserverClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}

		return AsManagedObserver(observer->GameObjObserverClassPointer);
	}

	::BaseGameObj *ScriptableGameObj::InternalBaseGameObjPointer::get()
	{
		return InternalScriptableGameObjPointer;
	}

	::ReferenceableGameObj *ScriptableGameObj::InternalReferenceableGameObjPointer::get()
	{
		return InternalScriptableGameObjPointer;
	}

	::AudioCallbackClass *ScriptableGameObj::InternalAudioCallbackClassPointer::get()
	{
		return InternalScriptableGameObjPointer;
	}

	::ScriptableGameObj *ScriptableGameObj::InternalScriptableGameObjPointer::get()
	{
		return reinterpret_cast<::ScriptableGameObj *>(Pointer.ToPointer());
	}

	bool ScriptableGameObj::ObserverCreatedPending::get()
	{
		auto helper = reinterpret_cast<ScriptableGameObjHelper *>(InternalScriptableGameObjPointer);

		auto &observerCreatedPending = helper->GetObserverCreatedPending();

		return observerCreatedPending;
	}

	void ScriptableGameObj::ObserverCreatedPending::set(bool value)
	{
		auto helper = reinterpret_cast<ScriptableGameObjHelper *>(InternalScriptableGameObjPointer);

		auto &observerCreatedPending = helper->GetObserverCreatedPending();

		observerCreatedPending = value;
	}

	bool ScriptableGameObj::ObserversStarted::get()
	{
		auto helper = reinterpret_cast<ScriptableGameObjHelper *>(InternalScriptableGameObjPointer);

		auto &observersStarted = helper->GetObserversStarted();

		return observersStarted;
	}

	void ScriptableGameObj::ObserversStarted::set(bool value)
	{
		auto helper = reinterpret_cast<ScriptableGameObjHelper *>(InternalScriptableGameObjPointer);

		auto &observersStarted = helper->GetObserversStarted();

		observersStarted = value;
	}

	IDynamicVectorClass<IntPtr> ^ScriptableGameObj::ObserverTimerList::get()
	{
		auto helper = reinterpret_cast<ScriptableGameObjHelper *>(InternalScriptableGameObjPointer);

		auto &observerTimerList = helper->GetObserverTimerList();

		return gcnew GameObjObserverTimerClassPtrDynamicVectorClass(IntPtr(&observerTimerList));
	}

	void ScriptableGameObj::ObserverTimerList::set(IDynamicVectorClass<IntPtr> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<ScriptableGameObjHelper *>(InternalScriptableGameObjPointer);

		auto &observerTimerList = helper->GetObserverTimerList();

		observerTimerList = *reinterpret_cast<::DynamicVectorClass<::GameObjObserverTimerClass *> *>(value->Pointer.ToPointer());
	}

	IDynamicVectorClass<IntPtr> ^ScriptableGameObj::CustomTimerList::get()
	{
		auto helper = reinterpret_cast<ScriptableGameObjHelper *>(InternalScriptableGameObjPointer);

		auto &customTimerList = helper->GetCustomTimerList();

		return gcnew GameObjCustomTimerClassPtrDynamicVectorClass(IntPtr(&customTimerList));
	}

	void ScriptableGameObj::CustomTimerList::set(IDynamicVectorClass<IntPtr> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<ScriptableGameObjHelper *>(InternalScriptableGameObjPointer);

		auto &customTimerList = helper->GetCustomTimerList();

		customTimerList = *reinterpret_cast<::DynamicVectorClass<::GameObjCustomTimerClass *> *>(value->Pointer.ToPointer());
	}
}