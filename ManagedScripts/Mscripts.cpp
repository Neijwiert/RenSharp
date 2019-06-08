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
#include "Mscripts.h"

#include "UnmanagedContainer.h"
#include "MEngine.h"
#include "Maction.h"
#include "Mda_player.h"
#include "Imports.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <action.h>
#include <da_gameobj.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Text;

namespace RenSharp
{

#pragma managed(push, off)

	class ScriptFactoryHelper : public ::ScriptFactory
	{
		private:
			ScriptFactoryHelper()
				: ScriptFactory(nullptr, nullptr)
			{

			}

		public:
			::ScriptFactory *GetNext() const
			{
				return ::ScriptFactory::GetNext();
			}

			void SetNext(::ScriptFactory *link)
			{
				::ScriptFactory::SetNext(link);
			}
	};

	class GameObjObserverClassHelper : public ::GameObjObserverClass
	{
		private:
			GameObjObserverClassHelper() = default;

		public:
			static bool IsDAGameObjObserverClass(::GameObjObserverClass *observer)
			{
				observer->Owner();
				_asm
				{
					cmp ecx, 1
					jnz False
				}

				return true;

			False:
				return false;
			}
	};

#pragma managed(pop)

	CombatSound::CombatSound()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateCombatSound()))
	{

	}

	CombatSound::CombatSound(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<ICombatSound ^> ^CombatSound::CreateCombatSound()
	{
		return gcnew UnmanagedContainer<ICombatSound ^>(gcnew CombatSound());
	}

	bool CombatSound::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		ICombatSound ^otherThis = dynamic_cast<ICombatSound ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return CombatSoundPointer.Equals(otherThis->CombatSoundPointer);
	}

	IntPtr CombatSound::CombatSoundPointer::get()
	{
		return IntPtr(InternalCombatSoundPointer);
	}

	Vector3 CombatSound::Position::get()
	{
		Vector3 result;
		Vector3::UnmanagedToManagedVector3(InternalCombatSoundPointer->Position, result);

		return result;
	}

	void CombatSound::Position::set(Vector3 value)
	{
		Vector3::ManagedToUnmanagedVector3(value, InternalCombatSoundPointer->Position);
	}

	int CombatSound::Sound::get()
	{
		return InternalCombatSoundPointer->sound;
	}

	void CombatSound::Sound::set(int value)
	{
		InternalCombatSoundPointer->sound = value;
	}

	IScriptableGameObj ^CombatSound::Creator::get()
	{
		auto result = InternalCombatSoundPointer->Creator;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptableGameObj(IntPtr(result));
		}
	}

	void CombatSound::Creator::set(IScriptableGameObj ^value)
	{
		if (value == nullptr || value->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalCombatSoundPointer->Creator = nullptr;
		}
		else
		{
			InternalCombatSoundPointer->Creator = reinterpret_cast<::ScriptableGameObj *>(value->ScriptableGameObjPointer.ToPointer());
		}
	}

	bool CombatSound::InternalDestroyPointer()
	{
		Imports::DestroyCombatSound(InternalCombatSoundPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::CombatSound *CombatSound::InternalCombatSoundPointer::get()
	{
		return reinterpret_cast<::CombatSound *>(Pointer.ToPointer());
	}

	GameObjObserverClass::GameObjObserverClass()
	{

	}

	GameObjObserverClass::GameObjObserverClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String ^GameObjObserverClass::ToString()
	{
		StringBuilder ^builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	bool GameObjObserverClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IGameObjObserverClass ^otherThis = dynamic_cast<IGameObjObserverClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return GameObjObserverClassPointer.Equals(otherThis->GameObjObserverClassPointer);
	}

	void GameObjObserverClass::Attach(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalGameObjObserverClassPointer->Attach(nullptr);
		}
		else
		{
			InternalGameObjObserverClassPointer->Attach(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		}
	}

	void GameObjObserverClass::Detach(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalGameObjObserverClassPointer->Detach(nullptr);
		}
		else
		{
			InternalGameObjObserverClassPointer->Detach(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		}
	}

	void GameObjObserverClass::Created(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalGameObjObserverClassPointer->Created(nullptr);
		}
		else
		{
			InternalGameObjObserverClassPointer->Created(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		}
	}

	void GameObjObserverClass::Destroyed(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalGameObjObserverClassPointer->Destroyed(nullptr);
		}
		else
		{
			InternalGameObjObserverClassPointer->Destroyed(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		}
	}

	void GameObjObserverClass::Killed(IScriptableGameObj ^obj, IScriptableGameObj ^killer)
	{
		::ScriptableGameObj *objPtr;
		::ScriptableGameObj *killerPtr;

		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			objPtr = nullptr;
		}
		else
		{
			objPtr = reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer());
		}

		if (killer == nullptr || killer->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			killerPtr = nullptr;
		}
		else
		{
			killerPtr = reinterpret_cast<::ScriptableGameObj *>(killer->ScriptableGameObjPointer.ToPointer());
		}

		InternalGameObjObserverClassPointer->Killed(objPtr, killerPtr);
	}

	void GameObjObserverClass::Damaged(IScriptableGameObj ^obj, IScriptableGameObj ^damager, float amount)
	{
		::ScriptableGameObj *objPtr;
		::ScriptableGameObj *damagerPtr;

		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			objPtr = nullptr;
		}
		else
		{
			objPtr = reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer());
		}

		if (damager == nullptr || damager->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			damagerPtr = nullptr;
		}
		else
		{
			damagerPtr = reinterpret_cast<::ScriptableGameObj *>(damager->ScriptableGameObjPointer.ToPointer());
		}

		InternalGameObjObserverClassPointer->Damaged(objPtr, damagerPtr, amount);
	}

	void GameObjObserverClass::Custom(IScriptableGameObj ^obj, int type, int param, IScriptableGameObj ^sender)
	{
		::ScriptableGameObj *objPtr;
		::ScriptableGameObj *senderPtr;

		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			objPtr = nullptr;
		}
		else
		{
			objPtr = reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer());
		}

		if (sender == nullptr || sender->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			senderPtr = nullptr;
		}
		else
		{
			senderPtr = reinterpret_cast<::ScriptableGameObj *>(sender->ScriptableGameObjPointer.ToPointer());
		}

		InternalGameObjObserverClassPointer->Custom(objPtr, type, param, senderPtr);
	}

	void GameObjObserverClass::SoundHeard(IScriptableGameObj ^obj, ICombatSound ^sound)
	{
		if (sound == nullptr || sound->CombatSoundPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("sound");
		}

		::ScriptableGameObj *objPtr;
		::CombatSound *soundPtr = reinterpret_cast<::CombatSound *>(sound->CombatSoundPointer.ToPointer());

		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			objPtr = nullptr;
		}
		else
		{
			objPtr = reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer());
		}

		InternalGameObjObserverClassPointer->Sound_Heard(objPtr, *soundPtr);
	}

	void GameObjObserverClass::EnemySeen(IScriptableGameObj ^obj, IScriptableGameObj ^enemy)
	{
		::ScriptableGameObj *objPtr;
		::ScriptableGameObj *enemyPtr;

		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			objPtr = nullptr;
		}
		else
		{
			objPtr = reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer());
		}

		if (enemy == nullptr || enemy->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			enemyPtr = nullptr;
		}
		else
		{
			enemyPtr = reinterpret_cast<::ScriptableGameObj *>(enemy->ScriptableGameObjPointer.ToPointer());
		}

		InternalGameObjObserverClassPointer->Enemy_Seen(objPtr, enemyPtr);
	}

	void GameObjObserverClass::ActionComplete(IScriptableGameObj ^obj, int actionId, ActionCompleteReason completeReason)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalGameObjObserverClassPointer->Action_Complete(nullptr, actionId, static_cast<::ActionCompleteReason>(completeReason));
		}
		else
		{
			InternalGameObjObserverClassPointer->Action_Complete(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()), actionId, static_cast<::ActionCompleteReason>(completeReason));
		}
	}

	void GameObjObserverClass::TimerExpired(IScriptableGameObj ^obj, int number)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalGameObjObserverClassPointer->Timer_Expired(nullptr, number);
		}
		else
		{
			InternalGameObjObserverClassPointer->Timer_Expired(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()), number);
		}
	}

	void GameObjObserverClass::AnimationComplete(IScriptableGameObj ^obj, String ^animationName)
	{
		::ScriptableGameObj *objPtr;

		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			objPtr = nullptr;
		}
		else
		{
			objPtr = reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer());
		}

		if (animationName == nullptr)
		{
			InternalGameObjObserverClassPointer->Animation_Complete(objPtr, nullptr);
		}
		else
		{
			IntPtr animationNameHandle = Marshal::StringToHGlobalAnsi(animationName);
			try
			{
				InternalGameObjObserverClassPointer->Animation_Complete(objPtr, reinterpret_cast<char *>(animationNameHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(animationNameHandle);
			}
		}
	}

	void GameObjObserverClass::Poked(IScriptableGameObj ^obj, IScriptableGameObj ^poker)
	{
		::ScriptableGameObj *objPtr;
		::ScriptableGameObj *pokerPtr;

		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			objPtr = nullptr;
		}
		else
		{
			objPtr = reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer());
		}

		if (poker == nullptr || poker->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			pokerPtr = nullptr;
		}
		else
		{
			pokerPtr = reinterpret_cast<::ScriptableGameObj *>(poker->ScriptableGameObjPointer.ToPointer());
		}

		InternalGameObjObserverClassPointer->Poked(objPtr, pokerPtr);
	}

	void GameObjObserverClass::Entered(IScriptableGameObj ^obj, IScriptableGameObj ^enterer)
	{
		::ScriptableGameObj *objPtr;
		::ScriptableGameObj *entererPtr;

		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			objPtr = nullptr;
		}
		else
		{
			objPtr = reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer());
		}

		if (enterer == nullptr || enterer->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			entererPtr = nullptr;
		}
		else
		{
			entererPtr = reinterpret_cast<::ScriptableGameObj *>(enterer->ScriptableGameObjPointer.ToPointer());
		}

		InternalGameObjObserverClassPointer->Entered(objPtr, entererPtr);
	}

	void GameObjObserverClass::Exited(IScriptableGameObj ^obj, IScriptableGameObj ^exiter)
	{
		::ScriptableGameObj *objPtr;
		::ScriptableGameObj *exiterPtr;

		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			objPtr = nullptr;
		}
		else
		{
			objPtr = reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer());
		}

		if (exiter == nullptr || exiter->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			exiterPtr = nullptr;
		}
		else
		{
			exiterPtr = reinterpret_cast<::ScriptableGameObj *>(exiter->ScriptableGameObjPointer.ToPointer());
		}

		InternalGameObjObserverClassPointer->Exited(objPtr, exiterPtr);
	}

	IRenSharpGameObjObserverClass ^GameObjObserverClass::AsManagedObserver()
	{
		return ScriptableGameObj::AsManagedObserver(this);
	}

	IntPtr GameObjObserverClass::GameObjObserverClassPointer::get()
	{
		return IntPtr(InternalGameObjObserverClassPointer);
	}

	String ^GameObjObserverClass::Name::get()
	{
		auto result = InternalGameObjObserverClassPointer->Get_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	int GameObjObserverClass::ID::get()
	{
		return InternalGameObjObserverClassPointer->Get_ID();
	}

	void GameObjObserverClass::ID::set(int value)
	{
		InternalGameObjObserverClassPointer->Set_ID(value);
	}

	IScriptableGameObj ^GameObjObserverClass::Owner::get()
	{
		auto result = InternalGameObjObserverClassPointer->Owner();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			// Owner() is hijacked by DA to identify DA observers
			if (GameObjObserverClassHelper::IsDAGameObjObserverClass(InternalGameObjObserverClassPointer))
			{
				auto daResult = static_cast<::DAGameObjObserverClass *>(InternalGameObjObserverClassPointer);

				result = daResult->Get_Owner();
				if (result == nullptr)
				{
					return nullptr;
				}
			}

			return gcnew ScriptableGameObj(IntPtr(result));
		}
	}

	bool GameObjObserverClass::IsManagedObserver::get()
	{
		return ScriptableGameObj::IsManagedObserver(this);
	}

	bool GameObjObserverClass::InternalDestroyPointer()
	{
		Imports::DestroyGameObjObserverClass(InternalGameObjObserverClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::GameObjObserverClass *GameObjObserverClass::InternalGameObjObserverClassPointer::get()
	{
		return reinterpret_cast<::GameObjObserverClass *>(Pointer.ToPointer());
	}

	ScriptVariableClass::ScriptVariableClass(IntPtr dataPtr, int dataSize, int id, IScriptVariableClass ^next)
		: AbstractUnmanagedObject(IntPtr(Imports::CreateScriptVariableClass(
			dataPtr.ToPointer(), 
			dataSize, 
			id, 
			(next == nullptr || next->ScriptVariableClassPointer.ToPointer() == nullptr ? nullptr : reinterpret_cast<::ScriptVariableClass *>(next->ScriptVariableClassPointer.ToPointer())))))
	{

	}

	ScriptVariableClass::ScriptVariableClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IScriptVariableClass ^> ^ScriptVariableClass::CreateScriptVariableClass(IntPtr dataPtr, int dataSize, int id, IScriptVariableClass ^next)
	{
		return gcnew UnmanagedContainer<IScriptVariableClass ^>(gcnew ScriptVariableClass(dataPtr, dataSize, id, next));
	}

	bool ScriptVariableClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IScriptVariableClass ^otherThis = dynamic_cast<IScriptVariableClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return ScriptVariableClassPointer.Equals(otherThis->ScriptVariableClassPointer);
	}

	IntPtr ScriptVariableClass::ScriptVariableClassPointer::get()
	{
		return IntPtr(InternalScriptVariableClassPointer);
	}

	IntPtr ScriptVariableClass::DataPtr::get()
	{
		return IntPtr(InternalScriptVariableClassPointer->Get_Data_Ptr());
	}

	int ScriptVariableClass::DataSize::get()
	{
		return InternalScriptVariableClassPointer->Get_Data_Size();
	}

	int ScriptVariableClass::ID::get()
	{
		return InternalScriptVariableClassPointer->Get_ID();
	}

	IScriptVariableClass ^ScriptVariableClass::Next::get()
	{
		auto result = InternalScriptVariableClassPointer->Get_Next();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptVariableClass(IntPtr(result));
		}
	}

	bool ScriptVariableClass::InternalDestroyPointer()
	{
		Imports::DestroyScriptVariableClass(InternalScriptVariableClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::ScriptVariableClass *ScriptVariableClass::InternalScriptVariableClassPointer::get()
	{
		return reinterpret_cast<::ScriptVariableClass *>(Pointer.ToPointer());
	}

	ScriptClass::ScriptClass(IntPtr pointer)
		: GameObjObserverClass(pointer)
	{

	}

	void ScriptClass::Save(IntPtr saver)
	{
		if (saver.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("saver");
		}

		InternalScriptClassPointer->Save(*reinterpret_cast<::ScriptSaver *>(saver.ToPointer()));
	}

	void ScriptClass::Load(IntPtr loader)
	{
		if (loader.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("loader");
		}

		InternalScriptClassPointer->Load(*reinterpret_cast<::ScriptLoader *>(loader.ToPointer()));
	}

	IntPtr ScriptClass::ScriptClassPointer::get()
	{
		return IntPtr(InternalScriptClassPointer);
	}

	IScriptableGameObj ^ScriptClass::Owner::get()
	{
		return GameObjObserverClass::Owner::get();
	}

	void ScriptClass::Owner::set(IScriptableGameObj ^value)
	{
		auto ownerPtr = InternalScriptClassPointer->Get_Owner_Ptr();
		if (value == nullptr || value->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			*ownerPtr = nullptr;
		}
		else
		{
			*ownerPtr = reinterpret_cast<::ScriptableGameObj *>(value->ScriptableGameObjPointer.ToPointer());
		}
	}

	String ^ScriptClass::ParametersString::get()
	{
		char buffer[2048]; // Very generous...

		InternalScriptClassPointer->Get_Parameters_String(buffer, sizeof(buffer) / sizeof(char));

		return gcnew String(buffer);
	}

	void ScriptClass::ParametersString::set(String ^value)
	{
		if (value == nullptr)
		{
			InternalScriptClassPointer->Set_Parameters_String(nullptr);
		}
		else
		{
			IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
			try
			{
				InternalScriptClassPointer->Set_Parameters_String(reinterpret_cast<char *>(valueHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(valueHandle);
			}
		}
	}

	::GameObjObserverClass *ScriptClass::InternalGameObjObserverClassPointer::get()
	{
		return InternalScriptClassPointer;
	}

	::ScriptClass *ScriptClass::InternalScriptClassPointer::get()
	{
		return reinterpret_cast<::ScriptClass *>(Pointer.ToPointer());
	}

	ScriptImpClass::ScriptImpClass()
		: ScriptClass(IntPtr(Imports::CreateScriptImpClass()))
	{

	}

	ScriptImpClass::ScriptImpClass(IntPtr pointer)
		: ScriptClass(pointer)
	{

	}

	IUnmanagedContainer<IScriptImpClass ^> ^ScriptImpClass::CreateScriptImpClass()
	{
		return gcnew UnmanagedContainer<IScriptImpClass ^>(gcnew ScriptImpClass());
	}

	void ScriptImpClass::SetFactory(IScriptFactory ^factory)
	{
		if (factory == nullptr || factory->ScriptFactoryPointer.ToPointer() == nullptr)
		{
			InternalScriptImpClassPointer->SetFactory(nullptr);
		}
		else
		{
			InternalScriptImpClassPointer->SetFactory(reinterpret_cast<::ScriptFactory *>(factory->ScriptFactoryPointer.ToPointer()));
		}
	}

	int ScriptImpClass::CheckPlayerType(IScriptableGameObj ^obj, int type)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalScriptImpClassPointer->CheckPlayerType(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()), type);
	}

	void ScriptImpClass::AutoSaveVariable(IntPtr dataPtr, int dataSize, int id)
	{
		InternalScriptImpClassPointer->Auto_Save_Variable(dataPtr.ToPointer(), dataSize, id);
	}

	void ScriptImpClass::RegisterAutoSaveVariables()
	{
		InternalScriptImpClassPointer->Register_Auto_Save_Variables();
	}

	String ^ScriptImpClass::GetParameter(String ^name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			auto result = InternalScriptImpClassPointer->Get_Parameter(reinterpret_cast<char *>(nameHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew String(result);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	String ^ScriptImpClass::GetParameter(int index)
	{
		auto result = InternalScriptImpClassPointer->Get_Parameter(index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	int ScriptImpClass::GetIntParameter(String ^parameterName)
	{
		if (parameterName == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(parameterName);
		try
		{
			return InternalScriptImpClassPointer->Get_Int_Parameter(reinterpret_cast<char *>(nameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	float ScriptImpClass::GetFloatParameter(String ^parameterName)
	{
		if (parameterName == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(parameterName);
		try
		{
			return InternalScriptImpClassPointer->Get_Float_Parameter(reinterpret_cast<char *>(nameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	Vector3 ScriptImpClass::GetVector3Parameter(int index)
	{
		::Vector3 tmp = InternalScriptImpClassPointer->Get_Vector3_Parameter(index);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	Vector3 ScriptImpClass::GetVector3Parameter(String ^parameterName)
	{
		if (parameterName == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(parameterName);
		try
		{
			::Vector3 tmp = InternalScriptImpClassPointer->Get_Vector3_Parameter(reinterpret_cast<char *>(nameHandle.ToPointer()));

			Vector3 result;
			Vector3::UnmanagedToManagedVector3(tmp, result);

			return result;
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	int ScriptImpClass::GetParameterIndex(String ^parameterName)
	{
		if (parameterName == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(parameterName);
		try
		{
			return InternalScriptImpClassPointer->Get_Parameter_Index(reinterpret_cast<char *>(nameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	int ScriptImpClass::GetIntParameter(int index)
	{
		return InternalScriptImpClassPointer->Get_Int_Parameter(index);
	}

	float ScriptImpClass::GetFloatParameter(int index)
	{
		return InternalScriptImpClassPointer->Get_Float_Parameter(index);
	}

	bool ScriptImpClass::GetBoolParameter(String ^name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			return InternalScriptImpClassPointer->Get_Bool_Parameter(reinterpret_cast<char *>(nameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	bool ScriptImpClass::GetBoolParameter(int index)
	{
		return InternalScriptImpClassPointer->Get_Bool_Parameter(index);
	}

	void ScriptImpClass::DestroyScript()
	{
		InternalScriptImpClassPointer->Destroy_Script();
	}

	IntPtr ScriptImpClass::ScriptImpClassPointer::get()
	{
		return IntPtr(InternalScriptImpClassPointer);
	}

	int ScriptImpClass::ParameterCount::get()
	{
		return InternalScriptImpClassPointer->Get_Parameter_Count();
	}

	::ScriptClass *ScriptImpClass::InternalScriptClassPointer::get()
	{
		return InternalScriptImpClassPointer;
	}

	::ScriptImpClass *ScriptImpClass::InternalScriptImpClassPointer::get()
	{
		return reinterpret_cast<::ScriptImpClass *>(Pointer.ToPointer());
	}

	ActionParamsStructRef::ActionParamsStructRef(bool create)
		: AbstractUnmanagedObject()
	{
		if (create)
		{
			Pointer = IntPtr(Imports::CreateActionParamsStruct());
		}
	}

	ActionParamsStructRef::ActionParamsStructRef(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{
		
	}

	IUnmanagedContainer<IActionParamsStruct ^> ^ActionParamsStructRef::CreateActionParamsStructRef()
	{
		return gcnew UnmanagedContainer<IActionParamsStruct ^>(gcnew ActionParamsStructRef(true));
	}

	bool ActionParamsStructRef::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IActionParamsStruct ^otherThis = dynamic_cast<IActionParamsStruct ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return ActionParamsStructPointer.Equals(otherThis->ActionParamsStructPointer);
	}

	ActionParamsStruct ^ActionParamsStructRef::ToActionParamsStruct()
	{
		return gcnew ActionParamsStruct(this);
	}

	void ActionParamsStructRef::SetBasic(IGameObjObserverClass ^script, float priority, int actionId, SoldierAIState aiState)
	{
		if (script == nullptr || script->GameObjObserverClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		InternalActionParamsStructPointer->Set_Basic(
			reinterpret_cast<::GameObjObserverClass *>(script->GameObjObserverClassPointer.ToPointer()), 
			priority, 
			actionId, 
			static_cast<::SoldierAIState>(aiState));
	}

	void ActionParamsStructRef::SetBasic(IGameObjObserverClass ^script, float priority, int actionId)
	{
		::GameObjObserverClass *scriptPtr;
		if (script == nullptr || script->GameObjObserverClassPointer.ToPointer() == nullptr)
		{
			scriptPtr = nullptr;
		}
		else
		{
			scriptPtr = reinterpret_cast<::GameObjObserverClass *>(script->GameObjObserverClassPointer.ToPointer());
		}

		InternalActionParamsStructPointer->Set_Basic(scriptPtr, priority, actionId);
	}

	void ActionParamsStructRef::SetBasic(long observerId, float priority, int actionId, SoldierAIState aiState)
	{
		InternalActionParamsStructPointer->Set_Basic(observerId, priority, actionId, static_cast<::SoldierAIState>(aiState));
	}

	void ActionParamsStructRef::SetBasic(long observerId, float priority, int actionId)
	{
		InternalActionParamsStructPointer->Set_Basic(observerId, priority, actionId);
	}

	void ActionParamsStructRef::SetLook(Vector3 location, float duration)
	{
		::Vector3 locationVec;

		Vector3::ManagedToUnmanagedVector3(location, locationVec);

		InternalActionParamsStructPointer->Set_Look(locationVec, duration);
	}

	void ActionParamsStructRef::SetLook(IScriptableGameObj ^object, float duration)
	{
		::ScriptableGameObj *objectPtr;
		if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			objectPtr = nullptr;
		}
		else
		{
			objectPtr = reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer());
		}

		InternalActionParamsStructPointer->Set_Look(objectPtr, duration);
	}

	void ActionParamsStructRef::SetLook(Vector3 objPos, float angle, float duration)
	{
		::Vector3 objPosVec;

		Vector3::ManagedToUnmanagedVector3(objPos, objPosVec);

		InternalActionParamsStructPointer->Set_Look(objPosVec, angle, duration);
	}

	void ActionParamsStructRef::SetMovement(Vector3 location, float speed, float arrivedDistance, bool crouched)
	{
		::Vector3 locationVec;

		Vector3::ManagedToUnmanagedVector3(location, locationVec);

		InternalActionParamsStructPointer->Set_Movement(locationVec, speed, arrivedDistance, crouched);
	}

	void ActionParamsStructRef::SetMovement(Vector3 location, float speed, float arrivedDistance)
	{
		::Vector3 locationVec;

		Vector3::ManagedToUnmanagedVector3(location, locationVec);

		InternalActionParamsStructPointer->Set_Movement(locationVec, speed, arrivedDistance);
	}

	void ActionParamsStructRef::SetMovement(IScriptableGameObj ^object, float speed, float arrivedDistance, bool crouched)
	{
		::ScriptableGameObj *objectPtr;
		if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			objectPtr = nullptr;
		}
		else
		{
			objectPtr = reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer());
		}

		InternalActionParamsStructPointer->Set_Movement(objectPtr, speed, arrivedDistance, crouched);
	}

	void ActionParamsStructRef::SetMovement(IScriptableGameObj ^object, float speed, float arrivedDistance)
	{
		::ScriptableGameObj *objectPtr;
		if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			objectPtr = nullptr;
		}
		else
		{
			objectPtr = reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer());
		}

		InternalActionParamsStructPointer->Set_Movement(objectPtr, speed, arrivedDistance);
	}

	void ActionParamsStructRef::SetAttack(Vector3 location, float range, float error, bool primaryFire)
	{
		::Vector3 locationVec;

		Vector3::ManagedToUnmanagedVector3(location, locationVec);

		InternalActionParamsStructPointer->Set_Attack(locationVec, range, error, primaryFire);
	}

	void ActionParamsStructRef::SetAttack(IScriptableGameObj ^object, float range, float error, bool primaryFire)
	{
		::ScriptableGameObj *objectPtr;
		if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			objectPtr = nullptr;
		}
		else
		{
			objectPtr = reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer());
		}

		InternalActionParamsStructPointer->Set_Attack(objectPtr, range, error, primaryFire);
	}

	void ActionParamsStructRef::SetFaceLocation(Vector3 location, float duration)
	{
		::Vector3 locationVec;

		Vector3::ManagedToUnmanagedVector3(location, locationVec);

		InternalActionParamsStructPointer->Set_Face_Location(locationVec, duration);
	}

	void ActionParamsStructRef::SetFaceLocation(Vector3 objPos, float angle, float duration)
	{
		::Vector3 objPosVec;

		Vector3::ManagedToUnmanagedVector3(objPos, objPosVec);

		InternalActionParamsStructPointer->Set_Face_Location(objPosVec, angle, duration);
	}

	void ActionParamsStructRef::JoinConversation(int activeConversationId)
	{
		InternalActionParamsStructPointer->Join_Conversation(activeConversationId);
	}

	void ActionParamsStructRef::DockVehicle(Vector3 dockLocation, Vector3 dockEntrance)
	{
		::Vector3 dockLocationVec;
		::Vector3 dockEntranceVec;

		Vector3::ManagedToUnmanagedVector3(dockLocation, dockLocationVec);
		Vector3::ManagedToUnmanagedVector3(dockEntrance, dockEntranceVec);

		InternalActionParamsStructPointer->Dock_Vehicle(dockLocationVec, dockEntranceVec);
	}

	IntPtr ActionParamsStructRef::ActionParamsStructPointer::get()
	{
		return IntPtr(InternalActionParamsStructPointer);
	}

	int ActionParamsStructRef::Priority::get()
	{
		return InternalActionParamsStructPointer->Priority;
	}

	void ActionParamsStructRef::Priority::set(int value)
	{
		InternalActionParamsStructPointer->Priority = value;
	}

	int ActionParamsStructRef::ActionID::get()
	{
		return InternalActionParamsStructPointer->ActionID;
	}

	void ActionParamsStructRef::ActionID::set(int value)
	{
		InternalActionParamsStructPointer->ActionID = value;
	}

	long ActionParamsStructRef::ObserverID::get()
	{
		return InternalActionParamsStructPointer->ObserverID;
	}

	void ActionParamsStructRef::ObserverID::set(long value)
	{
		InternalActionParamsStructPointer->ObserverID = value;
	}

	Vector3 ActionParamsStructRef::LookLocation::get()
	{
		Vector3 result;
		Vector3::UnmanagedToManagedVector3(InternalActionParamsStructPointer->LookLocation, result);

		return result;
	}

	void ActionParamsStructRef::LookLocation::set(Vector3 value)
	{
		Vector3::ManagedToUnmanagedVector3(value, InternalActionParamsStructPointer->LookLocation);
	}

	IScriptableGameObj ^ActionParamsStructRef::LookObject::get()
	{
		auto result = InternalActionParamsStructPointer->LookObject;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptableGameObj(IntPtr(result));
		}
	}

	void ActionParamsStructRef::LookObject::set(IScriptableGameObj ^value)
	{
		if (value == nullptr || value->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalActionParamsStructPointer->LookObject = nullptr;
		}
		else
		{
			InternalActionParamsStructPointer->LookObject = reinterpret_cast<::ScriptableGameObj *>(value->ScriptableGameObjPointer.ToPointer());
		}
	}

	float ActionParamsStructRef::LookDuration::get()
	{
		return InternalActionParamsStructPointer->LookDuration;
	}

	void ActionParamsStructRef::LookDuration::set(float value)
	{
		InternalActionParamsStructPointer->LookDuration = value;
	}

	Vector3 ActionParamsStructRef::MoveLocation::get()
	{
		Vector3 result;
		Vector3::UnmanagedToManagedVector3(InternalActionParamsStructPointer->MoveLocation, result);

		return result;
	}

	void ActionParamsStructRef::MoveLocation::set(Vector3 value)
	{
		Vector3::ManagedToUnmanagedVector3(value, InternalActionParamsStructPointer->MoveLocation);
	}

	IScriptableGameObj ^ActionParamsStructRef::MoveObject::get()
	{
		auto result = InternalActionParamsStructPointer->MoveObject;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptableGameObj(IntPtr(result));
		}
	}

	void ActionParamsStructRef::MoveObject::set(IScriptableGameObj ^value)
	{
		if (value == nullptr || value->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalActionParamsStructPointer->MoveObject = nullptr;
		}
		else
		{
			InternalActionParamsStructPointer->MoveObject = reinterpret_cast<::ScriptableGameObj *>(value->ScriptableGameObjPointer.ToPointer());
		}
	}

	Vector3 ActionParamsStructRef::MoveObjectOffset::get()
	{
		Vector3 result;
		Vector3::UnmanagedToManagedVector3(InternalActionParamsStructPointer->MoveObjectOffset, result);
		
		return result;
	}

	void ActionParamsStructRef::MoveObjectOffset::set(Vector3 value)
	{
		Vector3::ManagedToUnmanagedVector3(value, InternalActionParamsStructPointer->MoveObjectOffset);
	}

	float ActionParamsStructRef::MoveSpeed::get()
	{
		return InternalActionParamsStructPointer->MoveSpeed;
	}

	void ActionParamsStructRef::MoveSpeed::set(float value)
	{
		InternalActionParamsStructPointer->MoveSpeed = value;
	}

	float ActionParamsStructRef::MoveArrivedDistance::get()
	{
		return InternalActionParamsStructPointer->MoveArrivedDistance;
	}

	void ActionParamsStructRef::MoveArrivedDistance::set(float value)
	{
		InternalActionParamsStructPointer->MoveArrivedDistance = value;
	}

	bool ActionParamsStructRef::MoveBackup::get()
	{
		return InternalActionParamsStructPointer->MoveBackup;
	}

	void ActionParamsStructRef::MoveBackup::set(bool value)
	{
		InternalActionParamsStructPointer->MoveBackup = value;
	}

	bool ActionParamsStructRef::MoveFollow::get()
	{
		return InternalActionParamsStructPointer->MoveFollow;
	}

	void ActionParamsStructRef::MoveFollow::set(bool value)
	{
		InternalActionParamsStructPointer->MoveFollow = value;
	}

	bool ActionParamsStructRef::MoveCrouched::get()
	{
		return InternalActionParamsStructPointer->MoveCrouched;
	}

	void ActionParamsStructRef::MoveCrouched::set(bool value)
	{
		InternalActionParamsStructPointer->MoveCrouched = value;
	}

	bool ActionParamsStructRef::MovePathfind::get()
	{
		return InternalActionParamsStructPointer->MovePathfind;
	}

	void ActionParamsStructRef::MovePathfind::set(bool value)
	{
		InternalActionParamsStructPointer->MovePathfind = value;
	}

	bool ActionParamsStructRef::ShutdownEngineOnArrival::get()
	{
		return InternalActionParamsStructPointer->ShutdownEngineOnArrival;
	}

	void ActionParamsStructRef::ShutdownEngineOnArrival::set(bool value)
	{
		InternalActionParamsStructPointer->ShutdownEngineOnArrival = value;
	}

	float ActionParamsStructRef::AttackRange::get()
	{
		return InternalActionParamsStructPointer->AttackRange;
	}

	void ActionParamsStructRef::AttackRange::set(float value)
	{
		InternalActionParamsStructPointer->AttackRange = value;
	}

	float ActionParamsStructRef::AttackError::get()
	{
		return InternalActionParamsStructPointer->AttackError;
	}

	void ActionParamsStructRef::AttackError::set(float value)
	{
		InternalActionParamsStructPointer->AttackError = value;
	}

	bool ActionParamsStructRef::AttackErrorOverride::get()
	{
		return InternalActionParamsStructPointer->AttackErrorOverride;
	}

	void ActionParamsStructRef::AttackErrorOverride::set(bool value)
	{
		InternalActionParamsStructPointer->AttackErrorOverride = value;
	}

	IScriptableGameObj ^ActionParamsStructRef::AttackObject::get()
	{
		auto result = InternalActionParamsStructPointer->AttackObject;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptableGameObj(IntPtr(result));
		}
	}

	void ActionParamsStructRef::AttackObject::set(IScriptableGameObj ^value)
	{
		if (value == nullptr || value->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalActionParamsStructPointer->AttackObject = nullptr;
		}
		else
		{
			InternalActionParamsStructPointer->AttackObject = reinterpret_cast<::ScriptableGameObj *>(value->ScriptableGameObjPointer.ToPointer());
		}
	}

	bool ActionParamsStructRef::AttackPrimaryFire::get()
	{
		return InternalActionParamsStructPointer->AttackPrimaryFire;
	}

	void ActionParamsStructRef::AttackPrimaryFire::set(bool value)
	{
		InternalActionParamsStructPointer->AttackPrimaryFire = value;
	}

	bool ActionParamsStructRef::AttackCrouched::get()
	{
		return InternalActionParamsStructPointer->AttackCrouched;
	}

	void ActionParamsStructRef::AttackCrouched::set(bool value)
	{
		InternalActionParamsStructPointer->AttackCrouched = value;
	}

	Vector3 ActionParamsStructRef::AttackLocation::get()
	{
		Vector3 result;
		Vector3::UnmanagedToManagedVector3(InternalActionParamsStructPointer->AttackLocation, result);

		return result;
	}

	void ActionParamsStructRef::AttackLocation::set(Vector3 value)
	{
		Vector3::ManagedToUnmanagedVector3(value, InternalActionParamsStructPointer->AttackLocation);
	}

	bool ActionParamsStructRef::AttackCheckBlocked::get()
	{
		return InternalActionParamsStructPointer->AttackCheckBlocked;
	}

	void ActionParamsStructRef::AttackCheckBlocked::set(bool value)
	{
		InternalActionParamsStructPointer->AttackCheckBlocked = value;
	}

	bool ActionParamsStructRef::AttackActive::get()
	{
		return InternalActionParamsStructPointer->AttackActive;
	}

	void ActionParamsStructRef::AttackActive::set(bool value)
	{
		InternalActionParamsStructPointer->AttackActive = value;
	}

	bool ActionParamsStructRef::AttackWanderAllowed::get()
	{
		return InternalActionParamsStructPointer->AttackWanderAllowed;
	}

	void ActionParamsStructRef::AttackWanderAllowed::set(bool value)
	{
		InternalActionParamsStructPointer->AttackWanderAllowed = value;
	}

	bool ActionParamsStructRef::AttackFaceTarget::get()
	{
		return InternalActionParamsStructPointer->AttackFaceTarget;
	}

	void ActionParamsStructRef::AttackFaceTarget::set(bool value)
	{
		InternalActionParamsStructPointer->AttackFaceTarget = value;
	}

	bool ActionParamsStructRef::AttackForceFire::get()
	{
		return InternalActionParamsStructPointer->AttackForceFire;
	}

	void ActionParamsStructRef::AttackForceFire::set(bool value)
	{
		InternalActionParamsStructPointer->AttackForceFire = value;
	}

	bool ActionParamsStructRef::ForceFacing::get()
	{
		return InternalActionParamsStructPointer->ForceFacing;
	}

	void ActionParamsStructRef::ForceFacing::set(bool value)
	{
		InternalActionParamsStructPointer->ForceFacing = value;
	}

	Vector3 ActionParamsStructRef::FaceLocation::get()
	{
		Vector3 result;
		Vector3::UnmanagedToManagedVector3(InternalActionParamsStructPointer->FaceLocation, result);

		return result;
	}

	void ActionParamsStructRef::FaceLocation::set(Vector3 value)
	{
		Vector3::ManagedToUnmanagedVector3(value, InternalActionParamsStructPointer->FaceLocation);
	}

	float ActionParamsStructRef::FaceDuration::get()
	{
		return InternalActionParamsStructPointer->FaceDuration;
	}

	void ActionParamsStructRef::FaceDuration::set(float value)
	{
		InternalActionParamsStructPointer->FaceDuration = value;
	}

	bool ActionParamsStructRef::IgnoreFacing::get()
	{
		return InternalActionParamsStructPointer->IgnoreFacing;
	}

	void ActionParamsStructRef::IgnoreFacing::set(bool value)
	{
		InternalActionParamsStructPointer->IgnoreFacing = value;
	}

	int ActionParamsStructRef::WaypathID::get()
	{
		return InternalActionParamsStructPointer->WaypathID;
	}

	void ActionParamsStructRef::WaypathID::set(int value)
	{
		InternalActionParamsStructPointer->WaypathID = value;
	}

	int ActionParamsStructRef::WaypointStartID::get()
	{
		return InternalActionParamsStructPointer->WaypointStartID;
	}

	void ActionParamsStructRef::WaypointStartID::set(int value)
	{
		InternalActionParamsStructPointer->WaypointStartID = value;
	}

	int ActionParamsStructRef::WaypointEndID::get()
	{
		return InternalActionParamsStructPointer->WaypointEndID;
	}

	void ActionParamsStructRef::WaypointEndID::set(int value)
	{
		InternalActionParamsStructPointer->WaypointEndID = value;
	}

	bool ActionParamsStructRef::WaypathSplined::get()
	{
		return InternalActionParamsStructPointer->WaypathSplined;
	}

	void ActionParamsStructRef::WaypathSplined::set(bool value)
	{
		InternalActionParamsStructPointer->WaypathSplined = value;
	}

	String ^ActionParamsStructRef::AnimationName::get()
	{
		auto result = InternalActionParamsStructPointer->AnimationName;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	bool ActionParamsStructRef::AnimationLooping::get()
	{
		return InternalActionParamsStructPointer->AnimationLooping;
	}

	void ActionParamsStructRef::AnimationLooping::set(bool value)
	{
		InternalActionParamsStructPointer->AnimationLooping = value;
	}

	int ActionParamsStructRef::ActiveConversationID::get()
	{
		return InternalActionParamsStructPointer->ActiveConversationID;
	}

	void ActionParamsStructRef::ActiveConversationID::set(int value)
	{
		InternalActionParamsStructPointer->ActiveConversationID = value;
	}

	String ^ActionParamsStructRef::ConversationName::get()
	{
		auto result = InternalActionParamsStructPointer->ConversationName;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	SoldierAIState ActionParamsStructRef::AIState::get()
	{
		return static_cast<SoldierAIState>(InternalActionParamsStructPointer->AIState);
	}

	void ActionParamsStructRef::AIState::set(SoldierAIState value)
	{
		InternalActionParamsStructPointer->AIState = static_cast<::SoldierAIState>(value);
	}

	Vector3 ActionParamsStructRef::DockLocation::get()
	{
		Vector3 result;
		Vector3::UnmanagedToManagedVector3(InternalActionParamsStructPointer->DockLocation, result);

		return result;
	}

	void ActionParamsStructRef::DockLocation::set(Vector3 value)
	{
		Vector3::ManagedToUnmanagedVector3(value, InternalActionParamsStructPointer->DockLocation);
	}

	Vector3 ActionParamsStructRef::DockEntrance::get()
	{
		Vector3 result;
		Vector3::UnmanagedToManagedVector3(InternalActionParamsStructPointer->DockEntrance, result);

		return result;
	}

	void ActionParamsStructRef::DockEntrance::set(Vector3 value)
	{
		Vector3::ManagedToUnmanagedVector3(value, InternalActionParamsStructPointer->DockEntrance);
	}

	bool ActionParamsStructRef::InternalDestroyPointer()
	{
		Imports::DestroyActionParamsStruct(InternalActionParamsStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::ActionParamsStruct *ActionParamsStructRef::InternalActionParamsStructPointer::get()
	{
		return reinterpret_cast<::ActionParamsStruct *>(Pointer.ToPointer());
	}

	ActionParamsStruct::ActionParamsStruct()
	{
		Priority = 0;
		ActionID = 0;               
		ObserverID = 0;           
		LookLocation = Vector3(0, 0, 0);
		LookObject = nullptr;
		LookDuration = 0;
		MoveLocation = Vector3(0, 0, 0);     
		MoveObject = nullptr;
		MoveObjectOffset = Vector3(0, 0, 0);
		MoveSpeed = 1;
		MoveArrivedDistance = Engine::DontMoveArrivedDist; 
		MoveBackup = false;           
		MoveFollow = false;
		MoveCrouched = false;
		MovePathfind = true;
		ShutdownEngineOnArrival = false;
		AttackRange = 20;    
		AttackError = 0;        
		AttackErrorOverride = false;
		AttackObject = nullptr;     
		AttackPrimaryFire = true;
		AttackCrouched = false;
		AttackLocation = Vector3(0, 0, 0);     
		AttackCheckBlocked = true;
		AttackActive = true;
		AttackWanderAllowed = false;
		AttackFaceTarget = true;
		AttackForceFire = false;
		ForceFacing = false;
		FaceLocation = Vector3(0, 0, 0);
		FaceDuration = 2;
		IgnoreFacing = false;
		WaypathID = 0;
		WaypointStartID = 0;
		WaypointEndID = 0;
		WaypathSplined = false;
		AnimationName = nullptr;
		AnimationLooping = false;
		ActiveConversationID = 0;
		ConversationName = nullptr;
		AIState = SoldierAIState::NoAIStateChange;
		DockLocation = Vector3(0, 0, 0);
		DockEntrance = Vector3(0, 0, 0);
	}

	ActionParamsStruct::ActionParamsStruct(IActionParamsStruct ^params)
	{
		if (params == nullptr || params->ActionParamsStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		Priority = params->Priority;
		ActionID = params->ActionID;
		ObserverID = params->ObserverID;
		LookLocation = params->LookLocation;
		LookObject = params->LookObject;
		LookDuration = params->LookDuration;
		MoveLocation = params->MoveLocation;
		MoveObject = params->MoveObject;
		MoveObjectOffset = params->MoveObjectOffset;
		MoveSpeed = params->MoveSpeed;
		MoveArrivedDistance = params->MoveArrivedDistance;
		MoveBackup = params->MoveBackup;
		MoveFollow = params->MoveFollow;
		MoveCrouched = params->MoveCrouched;
		MovePathfind = params->MovePathfind;
		ShutdownEngineOnArrival = params->ShutdownEngineOnArrival;
		AttackRange = params->AttackRange;
		AttackError = params->AttackError;
		AttackErrorOverride = params->AttackErrorOverride;
		AttackObject = params->AttackObject;
		AttackPrimaryFire = params->AttackPrimaryFire;
		AttackCrouched = params->AttackCrouched;
		AttackLocation = params->AttackLocation;
		AttackCheckBlocked = params->AttackCheckBlocked;
		AttackActive = params->AttackActive;
		AttackWanderAllowed = params->AttackWanderAllowed;
		AttackFaceTarget = params->AttackFaceTarget;
		AttackForceFire = params->AttackForceFire;
		ForceFacing = params->ForceFacing;
		FaceLocation = params->FaceLocation;
		FaceDuration = params->FaceDuration;
		IgnoreFacing = params->IgnoreFacing;
		WaypathID = params->WaypathID;
		WaypointStartID = params->WaypointStartID;
		WaypointEndID = params->WaypointEndID;
		WaypathSplined = params->WaypathSplined;
		AnimationName = params->AnimationName;
		AnimationLooping = params->AnimationLooping;
		ActiveConversationID = params->ActiveConversationID;
		ConversationName = params->ConversationName;
		AIState = params->AIState;
		DockLocation = params->DockLocation;
		DockEntrance = params->DockEntrance;
	}

	ActionParamsStruct::ActionParamsStruct(ActionParamsStruct ^params)
	{
		if (params == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		Priority = params->Priority;
		ActionID = params->ActionID;
		ObserverID = params->ObserverID;
		LookLocation = params->LookLocation;
		LookObject = params->LookObject;
		LookDuration = params->LookDuration;
		MoveLocation = params->MoveLocation;
		MoveObject = params->MoveObject;
		MoveObjectOffset = params->MoveObjectOffset;
		MoveSpeed = params->MoveSpeed;
		MoveArrivedDistance = params->MoveArrivedDistance;
		MoveBackup = params->MoveBackup;
		MoveFollow = params->MoveFollow;
		MoveCrouched = params->MoveCrouched;
		MovePathfind = params->MovePathfind;
		ShutdownEngineOnArrival = params->ShutdownEngineOnArrival;
		AttackRange = params->AttackRange;
		AttackError = params->AttackError;
		AttackErrorOverride = params->AttackErrorOverride;
		AttackObject = params->AttackObject;
		AttackPrimaryFire = params->AttackPrimaryFire;
		AttackCrouched = params->AttackCrouched;
		AttackLocation = params->AttackLocation;
		AttackCheckBlocked = params->AttackCheckBlocked;
		AttackActive = params->AttackActive;
		AttackWanderAllowed = params->AttackWanderAllowed;
		AttackFaceTarget = params->AttackFaceTarget;
		AttackForceFire = params->AttackForceFire;
		ForceFacing = params->ForceFacing;
		FaceLocation = params->FaceLocation;
		FaceDuration = params->FaceDuration;
		IgnoreFacing = params->IgnoreFacing;
		WaypathID = params->WaypathID;
		WaypointStartID = params->WaypointStartID;
		WaypointEndID = params->WaypointEndID;
		WaypathSplined = params->WaypathSplined;
		AnimationName = params->AnimationName;
		AnimationLooping = params->AnimationLooping;
		ActiveConversationID = params->ActiveConversationID;
		ConversationName = params->ConversationName;
		AIState = params->AIState;
		DockLocation = params->DockLocation;
		DockEntrance = params->DockEntrance;
	}

	void ActionParamsStruct::CopyFrom(IActionParamsStruct ^params)
	{
		if (params == nullptr || params->ActionParamsStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		Priority = params->Priority;
		ActionID = params->ActionID;
		ObserverID = params->ObserverID;
		LookLocation = params->LookLocation;
		LookObject = params->LookObject;
		LookDuration = params->LookDuration;
		MoveLocation = params->MoveLocation;
		MoveObject = params->MoveObject;
		MoveObjectOffset = params->MoveObjectOffset;
		MoveSpeed = params->MoveSpeed;
		MoveArrivedDistance = params->MoveArrivedDistance;
		MoveBackup = params->MoveBackup;
		MoveFollow = params->MoveFollow;
		MoveCrouched = params->MoveCrouched;
		MovePathfind = params->MovePathfind;
		ShutdownEngineOnArrival = params->ShutdownEngineOnArrival;
		AttackRange = params->AttackRange;
		AttackError = params->AttackError;
		AttackErrorOverride = params->AttackErrorOverride;
		AttackObject = params->AttackObject;
		AttackPrimaryFire = params->AttackPrimaryFire;
		AttackCrouched = params->AttackCrouched;
		AttackLocation = params->AttackLocation;
		AttackCheckBlocked = params->AttackCheckBlocked;
		AttackActive = params->AttackActive;
		AttackWanderAllowed = params->AttackWanderAllowed;
		AttackFaceTarget = params->AttackFaceTarget;
		AttackForceFire = params->AttackForceFire;
		ForceFacing = params->ForceFacing;
		FaceLocation = params->FaceLocation;
		FaceDuration = params->FaceDuration;
		IgnoreFacing = params->IgnoreFacing;
		WaypathID = params->WaypathID;
		WaypointStartID = params->WaypointStartID;
		WaypointEndID = params->WaypointEndID;
		WaypathSplined = params->WaypathSplined;
		AnimationName = params->AnimationName;
		AnimationLooping = params->AnimationLooping;
		ActiveConversationID = params->ActiveConversationID;
		ConversationName = params->ConversationName;
		AIState = params->AIState;
		DockLocation = params->DockLocation;
		DockEntrance = params->DockEntrance;
	}

	void ActionParamsStruct::CopyFrom(ActionParamsStruct ^params)
	{
		if (params == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		Priority = params->Priority;
		ActionID = params->ActionID;
		ObserverID = params->ObserverID;
		LookLocation = params->LookLocation;
		LookObject = params->LookObject;
		LookDuration = params->LookDuration;
		MoveLocation = params->MoveLocation;
		MoveObject = params->MoveObject;
		MoveObjectOffset = params->MoveObjectOffset;
		MoveSpeed = params->MoveSpeed;
		MoveArrivedDistance = params->MoveArrivedDistance;
		MoveBackup = params->MoveBackup;
		MoveFollow = params->MoveFollow;
		MoveCrouched = params->MoveCrouched;
		MovePathfind = params->MovePathfind;
		ShutdownEngineOnArrival = params->ShutdownEngineOnArrival;
		AttackRange = params->AttackRange;
		AttackError = params->AttackError;
		AttackErrorOverride = params->AttackErrorOverride;
		AttackObject = params->AttackObject;
		AttackPrimaryFire = params->AttackPrimaryFire;
		AttackCrouched = params->AttackCrouched;
		AttackLocation = params->AttackLocation;
		AttackCheckBlocked = params->AttackCheckBlocked;
		AttackActive = params->AttackActive;
		AttackWanderAllowed = params->AttackWanderAllowed;
		AttackFaceTarget = params->AttackFaceTarget;
		AttackForceFire = params->AttackForceFire;
		ForceFacing = params->ForceFacing;
		FaceLocation = params->FaceLocation;
		FaceDuration = params->FaceDuration;
		IgnoreFacing = params->IgnoreFacing;
		WaypathID = params->WaypathID;
		WaypointStartID = params->WaypointStartID;
		WaypointEndID = params->WaypointEndID;
		WaypathSplined = params->WaypathSplined;
		AnimationName = params->AnimationName;
		AnimationLooping = params->AnimationLooping;
		ActiveConversationID = params->ActiveConversationID;
		ConversationName = params->ConversationName;
		AIState = params->AIState;
		DockLocation = params->DockLocation;
		DockEntrance = params->DockEntrance;
	}

	void ActionParamsStruct::SetBasic(IGameObjObserverClass ^script, float priority, int actionId, SoldierAIState aiState)
	{
		if (script == nullptr || script->GameObjObserverClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		ObserverID = script->ID; 
		Priority = static_cast<int>(priority);
		ActionID = actionId;
		AIState = aiState;
	}

	void ActionParamsStruct::SetBasic(IGameObjObserverClass ^script, float priority, int actionId)
	{
		::GameObjObserverClass *scriptPtr;
		if (script == nullptr || script->GameObjObserverClassPointer.ToPointer() == nullptr)
		{
			scriptPtr = nullptr;
		}
		else
		{
			scriptPtr = reinterpret_cast<::GameObjObserverClass *>(script->GameObjObserverClassPointer.ToPointer());
		}

		ObserverID = script->ID;
		Priority = static_cast<int>(priority);
		ActionID = actionId;
		AIState = SoldierAIState::NoAIStateChange;
	}

	void ActionParamsStruct::SetBasic(long observerId, float priority, int actionId, SoldierAIState aiState)
	{
		ObserverID = observerId;
		Priority = static_cast<int>(priority);
		ActionID = actionId;
		AIState = aiState;
	}

	void ActionParamsStruct::SetBasic(long observerId, float priority, int actionId)
	{
		ObserverID = observerId;
		Priority = static_cast<int>(priority);
		ActionID = actionId;
		AIState = SoldierAIState::NoAIStateChange;
	}

	void ActionParamsStruct::SetLook(Vector3 location, float duration)
	{
		LookLocation = location; 
		LookDuration = duration;
	}

	void ActionParamsStruct::SetLook(IScriptableGameObj ^object, float duration)
	{
		LookObject = object; 
		LookDuration = duration;
	}

	void ActionParamsStruct::SetLook(Vector3 objPos, float angle, float duration)
	{
		LookLocation = objPos;
		LookLocation.X += static_cast<float>(::cos(angle));
		LookLocation.Y += static_cast<float>(::sin(angle));
		LookDuration = duration;
	}

	void ActionParamsStruct::SetMovement(Vector3 location, float speed, float arrivedDistance, bool crouched)
	{
		MoveLocation = location; 
		MoveSpeed = speed; 
		MoveArrivedDistance = arrivedDistance; 
		MoveCrouched = crouched;
	}

	void ActionParamsStruct::SetMovement(Vector3 location, float speed, float arrivedDistance)
	{
		MoveLocation = location;
		MoveSpeed = speed; 
		MoveArrivedDistance = arrivedDistance; 
		MoveCrouched = false;
	}

	void ActionParamsStruct::SetMovement(IScriptableGameObj ^object, float speed, float arrivedDistance, bool crouched)
	{
		MoveObject = object;
		MoveSpeed = speed;
		MoveArrivedDistance = arrivedDistance;
		MoveCrouched = crouched;
	}

	void ActionParamsStruct::SetMovement(IScriptableGameObj ^object, float speed, float arrivedDistance)
	{
		MoveObject = object;
		MoveSpeed = speed;
		MoveArrivedDistance = arrivedDistance;
		MoveCrouched = false;
	}

	void ActionParamsStruct::SetAttack(Vector3 location, float range, float error, bool primaryFire)
	{
		AttackLocation = location; 
		AttackRange = range; 
		AttackError = error; 
		AttackPrimaryFire = primaryFire;
	}

	void ActionParamsStruct::SetAttack(IScriptableGameObj ^object, float range, float error, bool primaryFire)
	{
		AttackObject = object; 
		AttackRange = range; 
		AttackError = error; 
		AttackPrimaryFire = primaryFire;
	}

	void ActionParamsStruct::SetAnimation(String ^name, bool looping)
	{
		AnimationName = name; 
		AnimationLooping = looping;
	}

	void ActionParamsStruct::SetFaceLocation(Vector3 location, float duration)
	{
		FaceLocation = location; 
		FaceDuration = duration;
	}

	void ActionParamsStruct::SetFaceLocation(Vector3 objPos, float angle, float duration)
	{
		FaceLocation = objPos;
		FaceLocation.X += static_cast<float>(::cos(angle));
		FaceLocation.Y += static_cast<float>(::sin(angle));
		FaceDuration = duration;
	}

	void ActionParamsStruct::JoinConversation(int activeConversationId)
	{
		ActiveConversationID = activeConversationId;
	}

	void ActionParamsStruct::StartConversation(String ^name)
	{
		ConversationName = name;
	}

	void ActionParamsStruct::DockVehicle(Vector3 dockLocation, Vector3 dockEntrance)
	{
		DockLocation = dockLocation;
		DockEntrance = dockEntrance;
	}

	ScriptFactory::ScriptFactory(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String ^ScriptFactory::ToString()
	{
		StringBuilder ^builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	bool ScriptFactory::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IScriptFactory ^otherThis = dynamic_cast<IScriptFactory ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return ScriptFactoryPointer.Equals(otherThis->ScriptFactoryPointer);
	}

	IUnmanagedContainer<IScriptImpClass ^> ^ScriptFactory::Create()
	{
		auto result = InternalScriptFactoryPointer->Create();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew UnmanagedContainer<IScriptImpClass ^>(gcnew ScriptImpClass(IntPtr(result)));
		}
	}

	IntPtr ScriptFactory::ScriptFactoryPointer::get()
	{
		return IntPtr(InternalScriptFactoryPointer);
	}

	String ^ScriptFactory::Name::get()
	{
		auto result = InternalScriptFactoryPointer->GetName();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String ^ScriptFactory::ParamDescription::get()
	{
		auto result = InternalScriptFactoryPointer->GetParamDescription();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	bool ScriptFactory::InternalDestroyPointer()
	{
		Imports::DestroyScriptFactory(InternalScriptFactoryPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::ScriptFactory *ScriptFactory::InternalScriptFactoryPointer::get()
	{
		return reinterpret_cast<::ScriptFactory *>(Pointer.ToPointer());
	}

	IScriptFactory ^ScriptFactory::Next::get()
	{
		auto helper = reinterpret_cast<ScriptFactoryHelper *>(InternalScriptFactoryPointer);

		auto next = helper->GetNext();
		if (next == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptFactory(IntPtr(next));
		}
	}

	void ScriptFactory::Next::set(IScriptFactory ^value)
	{
		auto helper = reinterpret_cast<ScriptFactoryHelper *>(InternalScriptFactoryPointer);

		if (value == nullptr || value->ScriptFactoryPointer.ToPointer() == nullptr)
		{
			helper->SetNext(nullptr);
		}
		else
		{
			helper->SetNext(reinterpret_cast<::ScriptFactory *>(value->ScriptFactoryPointer.ToPointer()));
		}
	}

	void ScriptRegistrar::RegisterScript(IScriptFactory ^factory)
	{
		if (factory == nullptr || factory->ScriptFactoryPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		::ScriptRegistrar::RegisterScript(reinterpret_cast<::ScriptFactory *>(factory->ScriptFactoryPointer.ToPointer()));
	}

	void ScriptRegistrar::UnregisterScript(IScriptFactory ^factory)
	{
		if (factory == nullptr || factory->ScriptFactoryPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		::ScriptRegistrar::UnregisterScript(reinterpret_cast<::ScriptFactory *>(factory->ScriptFactoryPointer.ToPointer()));
	}

	IUnmanagedContainer<IScriptImpClass ^> ^ScriptRegistrar::CreateScript(String ^name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			auto result = ::ScriptRegistrar::CreateScript(reinterpret_cast<char *>(nameHandle.ToPointer()));

			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew UnmanagedContainer<IScriptImpClass ^>(gcnew ScriptImpClass(IntPtr(result)));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	IScriptFactory ^ScriptRegistrar::GetScriptFactory(String ^name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			auto result = ::ScriptRegistrar::GetScriptFactory(reinterpret_cast<char *>(nameHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew ScriptFactory(IntPtr(result));
			}

		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	IScriptFactory ^ScriptRegistrar::GetScriptFactory(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = ::ScriptRegistrar::GetScriptFactory(index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptFactory(IntPtr(result));
		}
	}

	int ScriptRegistrar::Count::get()
	{
		return ::ScriptRegistrar::Count();
	}

	ScriptCommands::ScriptCommands()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateScriptCommands()))
	{

	}

	ScriptCommands::ScriptCommands(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IScriptCommands ^> ^ScriptCommands::CreateScriptCommands()
	{
		return gcnew UnmanagedContainer<IScriptCommands ^>(gcnew ScriptCommands());
	}

	bool ScriptCommands::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IScriptCommands ^otherThis = dynamic_cast<IScriptCommands ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return ScriptCommandsPointer.Equals(otherThis->ScriptCommandsPointer);
	}

	void ScriptCommands::DebugMessage(String ^format, ...array<Object ^> ^args)
	{
		if (InternalScriptCommandsPointer->Debug_Message == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}
		else if (args == nullptr)
		{
			throw gcnew ArgumentNullException("args");
		}

		String ^message = String::Format(format, args);
		IntPtr messageHandle = Marshal::StringToHGlobalAnsi(message);
		try
		{
			InternalScriptCommandsPointer->Debug_Message(reinterpret_cast<char *>(messageHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(messageHandle);
		}
	}

	void ScriptCommands::ActionReset(IScriptableGameObj ^obj, float priority)
	{
		if (InternalScriptCommandsPointer->Action_Reset == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalScriptCommandsPointer->Action_Reset(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()), priority);
	}

	void ScriptCommands::ActionGoto(IScriptableGameObj ^obj, ActionParamsStruct ^params)
	{
		if (InternalScriptCommandsPointer->Action_Goto == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (params == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		auto unsafeParams = SafeActionParamsStruct::CreateSafeActionParamsStruct(params);
		try
		{
			InternalScriptCommandsPointer->Action_Goto(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				*reinterpret_cast<::ActionParamsStruct *>(unsafeParams->UnmanagedObject->ActionParamsStructPointer.ToPointer()));
		}
		finally
		{

#pragma push_macro("delete")
#undef delete

			delete unsafeParams;
			unsafeParams = nullptr;

#pragma pop_macro("delete")

		}
	}

	void ScriptCommands::ActionGoto(IScriptableGameObj ^obj, IActionParamsStruct ^params)
	{
		if (InternalScriptCommandsPointer->Action_Goto == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (params == nullptr || params->ActionParamsStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		InternalScriptCommandsPointer->Action_Goto(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			*reinterpret_cast<::ActionParamsStruct *>(params->ActionParamsStructPointer.ToPointer()));
	}

	void ScriptCommands::ActionAttack(IScriptableGameObj ^obj, ActionParamsStruct ^params)
	{
		if (InternalScriptCommandsPointer->Action_Attack == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (params == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		auto unsafeParams = SafeActionParamsStruct::CreateSafeActionParamsStruct(params);
		try
		{
			InternalScriptCommandsPointer->Action_Attack(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				*reinterpret_cast<::ActionParamsStruct *>(unsafeParams->UnmanagedObject->ActionParamsStructPointer.ToPointer()));
		}
		finally
		{

#pragma push_macro("delete")
#undef delete

			delete unsafeParams;
			unsafeParams = nullptr;

#pragma pop_macro("delete")

		}
	}

	void ScriptCommands::ActionAttack(IScriptableGameObj ^obj, IActionParamsStruct ^params)
	{
		if (InternalScriptCommandsPointer->Action_Attack == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (params == nullptr || params->ActionParamsStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		InternalScriptCommandsPointer->Action_Attack(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			*reinterpret_cast<::ActionParamsStruct *>(params->ActionParamsStructPointer.ToPointer()));
	}

	void ScriptCommands::ActionPlayAnimation(IScriptableGameObj ^obj, ActionParamsStruct ^params)
	{
		if (InternalScriptCommandsPointer->Action_Play_Animation == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (params == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		auto unsafeParams = SafeActionParamsStruct::CreateSafeActionParamsStruct(params);
		try
		{
			InternalScriptCommandsPointer->Action_Play_Animation(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				*reinterpret_cast<::ActionParamsStruct *>(unsafeParams->UnmanagedObject->ActionParamsStructPointer.ToPointer()));
		}
		finally
		{

#pragma push_macro("delete")
#undef delete

			delete unsafeParams;
			unsafeParams = nullptr;

#pragma pop_macro("delete")

		}
	}

	void ScriptCommands::ActionPlayAnimation(IScriptableGameObj ^obj, IActionParamsStruct ^params)
	{
		if (InternalScriptCommandsPointer->Action_Play_Animation == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (params == nullptr || params->ActionParamsStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		InternalScriptCommandsPointer->Action_Play_Animation(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			*reinterpret_cast<::ActionParamsStruct *>(params->ActionParamsStructPointer.ToPointer()));
	}

	void ScriptCommands::ActionEnterExit(IScriptableGameObj ^obj, ActionParamsStruct ^params)
	{
		if (InternalScriptCommandsPointer->Action_Enter_Exit == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (params == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		auto unsafeParams = SafeActionParamsStruct::CreateSafeActionParamsStruct(params);
		try
		{
			InternalScriptCommandsPointer->Action_Enter_Exit(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				*reinterpret_cast<::ActionParamsStruct *>(unsafeParams->UnmanagedObject->ActionParamsStructPointer.ToPointer()));
		}
		finally
		{

#pragma push_macro("delete")
#undef delete

			delete unsafeParams;
			unsafeParams = nullptr;

#pragma pop_macro("delete")

		}
	}

	void ScriptCommands::ActionEnterExit(IScriptableGameObj ^obj, IActionParamsStruct ^params)
	{
		if (InternalScriptCommandsPointer->Action_Enter_Exit == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (params == nullptr || params->ActionParamsStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		InternalScriptCommandsPointer->Action_Enter_Exit(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			*reinterpret_cast<::ActionParamsStruct *>(params->ActionParamsStructPointer.ToPointer()));
	}

	void ScriptCommands::ActionFaceLocation(IScriptableGameObj ^obj, ActionParamsStruct ^params)
	{
		if (InternalScriptCommandsPointer->Action_Face_Location == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (params == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		auto unsafeParams = SafeActionParamsStruct::CreateSafeActionParamsStruct(params);
		try
		{
			InternalScriptCommandsPointer->Action_Face_Location(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				*reinterpret_cast<::ActionParamsStruct *>(unsafeParams->UnmanagedObject->ActionParamsStructPointer.ToPointer()));
		}
		finally
		{

#pragma push_macro("delete")
#undef delete

			delete unsafeParams;
			unsafeParams = nullptr;

#pragma pop_macro("delete")

		}
	}

	void ScriptCommands::ActionFaceLocation(IScriptableGameObj ^obj, IActionParamsStruct ^params)
	{
		if (InternalScriptCommandsPointer->Action_Face_Location == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (params == nullptr || params->ActionParamsStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		InternalScriptCommandsPointer->Action_Face_Location(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			*reinterpret_cast<::ActionParamsStruct *>(params->ActionParamsStructPointer.ToPointer()));
	}

	void ScriptCommands::ActionDock(IScriptableGameObj ^obj, ActionParamsStruct ^params)
	{
		if (InternalScriptCommandsPointer->Action_Dock == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (params == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		auto unsafeParams = SafeActionParamsStruct::CreateSafeActionParamsStruct(params);
		try
		{
			InternalScriptCommandsPointer->Action_Dock(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				*reinterpret_cast<::ActionParamsStruct *>(unsafeParams->UnmanagedObject->ActionParamsStructPointer.ToPointer()));
		}
		finally
		{

#pragma push_macro("delete")
#undef delete

			delete unsafeParams;
			unsafeParams = nullptr;

#pragma pop_macro("delete")

		}
	}

	void ScriptCommands::ActionDock(IScriptableGameObj ^obj, IActionParamsStruct ^params)
	{
		if (InternalScriptCommandsPointer->Action_Dock == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (params == nullptr || params->ActionParamsStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		InternalScriptCommandsPointer->Action_Dock(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			*reinterpret_cast<::ActionParamsStruct *>(params->ActionParamsStructPointer.ToPointer()));
	}

	void ScriptCommands::ActionFollowInput(IScriptableGameObj ^obj, ActionParamsStruct ^params)
	{
		if (InternalScriptCommandsPointer->Action_Follow_Input == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (params == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		auto unsafeParams = SafeActionParamsStruct::CreateSafeActionParamsStruct(params);
		try
		{
			InternalScriptCommandsPointer->Action_Follow_Input(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				*reinterpret_cast<::ActionParamsStruct *>(unsafeParams->UnmanagedObject->ActionParamsStructPointer.ToPointer()));
		}
		finally
		{

#pragma push_macro("delete")
#undef delete

			delete unsafeParams;
			unsafeParams = nullptr;

#pragma pop_macro("delete")

		}
	}

	void ScriptCommands::ActionFollowInput(IScriptableGameObj ^obj, IActionParamsStruct ^params)
	{
		if (InternalScriptCommandsPointer->Action_Follow_Input == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (params == nullptr || params->ActionParamsStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		InternalScriptCommandsPointer->Action_Follow_Input(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			*reinterpret_cast<::ActionParamsStruct *>(params->ActionParamsStructPointer.ToPointer()));
	}

	void ScriptCommands::ModifyAction(IScriptableGameObj ^obj, int actionID, ActionParamsStruct ^params, bool modifyMove, bool modifyAttack)
	{
		if (InternalScriptCommandsPointer->Modify_Action == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (params == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		auto unsafeParams = SafeActionParamsStruct::CreateSafeActionParamsStruct(params);
		try
		{
			InternalScriptCommandsPointer->Modify_Action(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				actionID,
				*reinterpret_cast<::ActionParamsStruct *>(unsafeParams->UnmanagedObject->ActionParamsStructPointer.ToPointer()),
				modifyMove,
				modifyAttack);
		}
		finally
		{

#pragma push_macro("delete")
#undef delete

			delete unsafeParams;
			unsafeParams = nullptr;

#pragma pop_macro("delete")

		}
	}

	void ScriptCommands::ModifyAction(IScriptableGameObj ^obj, int actionID, IActionParamsStruct ^params, bool modifyMove, bool modifyAttack)
	{
		if (InternalScriptCommandsPointer->Modify_Action == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (params == nullptr || params->ActionParamsStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		InternalScriptCommandsPointer->Modify_Action(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			actionID,
			*reinterpret_cast<::ActionParamsStruct *>(params->ActionParamsStructPointer.ToPointer()),
			modifyMove,
			modifyAttack);
	}

	int ScriptCommands::GetActionID(IScriptableGameObj ^obj)
	{
		if (InternalScriptCommandsPointer->Get_Action_ID == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalScriptCommandsPointer->Get_Action_ID(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool ScriptCommands::GetActionParams(IScriptableGameObj ^obj, [Out] ActionParamsStruct ^%params)
	{
		if (InternalScriptCommandsPointer->Get_Action_Params == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::ActionParamsStruct pParams;

		if (InternalScriptCommandsPointer->Get_Action_Params(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()), pParams))
		{
			IActionParamsStruct ^safeParams = gcnew ActionParamsStructRef(IntPtr(&pParams));

			params = safeParams->ToActionParamsStruct();

			return true;
		}
		else
		{
			params = nullptr;

			return false;
		}
	}

	bool ScriptCommands::GetActionParams(IScriptableGameObj ^obj, IActionParamsStruct ^params)
	{
		if (InternalScriptCommandsPointer->Get_Action_Params == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (params == nullptr || params->ActionParamsStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		return InternalScriptCommandsPointer->Get_Action_Params(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			*reinterpret_cast<::ActionParamsStruct *>(params->ActionParamsStructPointer.ToPointer()));
	}

	bool ScriptCommands::IsPerformingPathfindAction(IScriptableGameObj ^obj)
	{
		if (InternalScriptCommandsPointer->Is_Performing_Pathfind_Action == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalScriptCommandsPointer->Is_Performing_Pathfind_Action(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::SetPosition(IScriptableGameObj ^obj, Vector3 position)
	{
		if (InternalScriptCommandsPointer->Set_Position == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		InternalScriptCommandsPointer->Set_Position(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()), positionVec);
	}

	Vector3 ScriptCommands::GetPosition(IScriptableGameObj ^obj)
	{
		if (InternalScriptCommandsPointer->Get_Position == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Vector3 tmp = InternalScriptCommandsPointer->Get_Position(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	Vector3 ScriptCommands::GetBonePosition(IScriptableGameObj ^obj, String ^boneName)
	{
		if (InternalScriptCommandsPointer->Get_Bone_Position == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (boneName == nullptr)
		{
			throw gcnew ArgumentNullException("boneName");
		}

		IntPtr boneNameHandle = Marshal::StringToHGlobalAnsi(boneName);
		try
		{
			::Vector3 tmp = InternalScriptCommandsPointer->Get_Bone_Position(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(boneNameHandle.ToPointer()));

			Vector3 result;
			Vector3::UnmanagedToManagedVector3(tmp, result);

			return result;
		}
		finally
		{
			Marshal::FreeHGlobal(boneNameHandle);
		}
	}

	float ScriptCommands::GetFacing(IScriptableGameObj ^obj)
	{
		if (InternalScriptCommandsPointer->Get_Facing == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalScriptCommandsPointer->Get_Facing(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::SetFacing(IScriptableGameObj ^obj, float degrees)
	{
		if (InternalScriptCommandsPointer->Set_Facing == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalScriptCommandsPointer->Set_Facing(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()), degrees);
	}

	void ScriptCommands::DisableAllCollisions(IScriptableGameObj ^obj)
	{
		if (InternalScriptCommandsPointer->Disable_All_Collisions == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalScriptCommandsPointer->Disable_All_Collisions(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::DisablePhysicalCollisions(IScriptableGameObj ^obj)
	{
		if (InternalScriptCommandsPointer->Disable_Physical_Collisions == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalScriptCommandsPointer->Disable_Physical_Collisions(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::EnableCollisions(IScriptableGameObj ^obj)
	{
		if (InternalScriptCommandsPointer->Enable_Collisions == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalScriptCommandsPointer->Enable_Collisions(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::DestroyObject(IScriptableGameObj ^obj)
	{
		if (InternalScriptCommandsPointer->Destroy_Object == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalScriptCommandsPointer->Destroy_Object(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	IScriptableGameObj ^ScriptCommands::FindObject(int objId)
	{
		if (InternalScriptCommandsPointer->Find_Object == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		auto result = InternalScriptCommandsPointer->Find_Object(objId);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptableGameObj(IntPtr(result));
		}
	}

	IScriptableGameObj ^ScriptCommands::CreateObject(String ^typeName, Vector3 position)
	{
		if (InternalScriptCommandsPointer->Create_Object == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (typeName == nullptr)
		{
			throw gcnew ArgumentNullException("typeName");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		IntPtr typeNameHandle = Marshal::StringToHGlobalAnsi(typeName);
		try
		{
			auto result = InternalScriptCommandsPointer->Create_Object(reinterpret_cast<char *>(typeNameHandle.ToPointer()), positionVec);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew ScriptableGameObj(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(typeNameHandle);
		}
	}

	IScriptableGameObj ^ScriptCommands::CreateObjectAtBone(IScriptableGameObj ^hostObj, String ^newObjTypeName, String ^boneName)
	{
		if (InternalScriptCommandsPointer->Create_Object_At_Bone == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (hostObj == nullptr || hostObj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("hostObj");
		}
		else if (newObjTypeName == nullptr)
		{
			throw gcnew ArgumentNullException("newObjTypeName");
		}
		else if (boneName == nullptr)
		{
			throw gcnew ArgumentNullException("boneName");
		}

		IntPtr newObjTypeNameHandle = Marshal::StringToHGlobalAnsi(newObjTypeName);
		try
		{
			IntPtr boneNameHandle = Marshal::StringToHGlobalAnsi(boneName);
			try
			{
				auto result = InternalScriptCommandsPointer->Create_Object_At_Bone(
					reinterpret_cast<::ScriptableGameObj *>(hostObj->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<char *>(newObjTypeNameHandle.ToPointer()),
					reinterpret_cast<char *>(boneNameHandle.ToPointer()));

				if (result == nullptr)
				{
					return nullptr;
				}
				else
				{
					return gcnew ScriptableGameObj(IntPtr(result));
				}
			}
			finally
			{
				Marshal::FreeHGlobal(boneNameHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(newObjTypeNameHandle);
		}
	}

	int ScriptCommands::GetID(IScriptableGameObj ^obj)
	{
		if (InternalScriptCommandsPointer->Get_ID == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalScriptCommandsPointer->Get_ID(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	int ScriptCommands::GetPresetID(IScriptableGameObj ^obj)
	{
		if (InternalScriptCommandsPointer->Get_Preset_ID == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalScriptCommandsPointer->Get_Preset_ID(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	String ^ScriptCommands::GetPresetName(IScriptableGameObj ^obj)
	{
		if (InternalScriptCommandsPointer->Get_Preset_Name == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = InternalScriptCommandsPointer->Get_Preset_Name(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	void ScriptCommands::AttachScript(IScriptableGameObj ^object, String ^scriptName, String ^scriptParams, ...array<Object^>^ args)
	{
		if (InternalScriptCommandsPointer->Attach_Script == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr scriptNameHandle = Marshal::StringToHGlobalAnsi(scriptName);
		try
		{
			if (scriptParams == nullptr)
			{
				InternalScriptCommandsPointer->Attach_Script(
					reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<char *>(scriptNameHandle.ToPointer()),
					nullptr);
			}
			else
			{
				IntPtr scriptParamsHandle = Marshal::StringToHGlobalAnsi(String::Format(scriptParams, args));
				try
				{
					InternalScriptCommandsPointer->Attach_Script(
						reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
						reinterpret_cast<char *>(scriptNameHandle.ToPointer()),
						reinterpret_cast<char *>(scriptParamsHandle.ToPointer()));
				}
				finally
				{
					Marshal::FreeHGlobal(scriptParamsHandle);
				}
			}
		}
		finally
		{
			Marshal::FreeHGlobal(scriptNameHandle);
		}
	}

	void ScriptCommands::AddToDirtyCullList(IScriptableGameObj ^object)
	{
		if (InternalScriptCommandsPointer->Add_To_Dirty_Cull_List == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Add_To_Dirty_Cull_List(reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::StartTimer(IScriptableGameObj ^obj, IScriptClass ^script, float duration, int timerId)
	{
		if (InternalScriptCommandsPointer->Start_Timer == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (script == nullptr || script->ScriptClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		InternalScriptCommandsPointer->Start_Timer(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			reinterpret_cast<::ScriptClass *>(script->ScriptClassPointer.ToPointer()),
			duration,
			timerId);
	}

	void ScriptCommands::TriggerWeapon(IScriptableGameObj ^obj, bool trigger, Vector3 target, bool primary)
	{
		if (InternalScriptCommandsPointer->Trigger_Weapon == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Vector3 targetVec;

		Vector3::ManagedToUnmanagedVector3(target, targetVec);

		InternalScriptCommandsPointer->Trigger_Weapon(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			trigger,
			targetVec,
			primary);
	}

	void ScriptCommands::SelectWeapon(IScriptableGameObj ^obj, String ^weaponName)
	{
		if (InternalScriptCommandsPointer->Select_Weapon == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		if (weaponName == nullptr)
		{
			InternalScriptCommandsPointer->Select_Weapon(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				nullptr);
		}
		else
		{
			IntPtr weaponNameHandle = Marshal::StringToHGlobalAnsi(weaponName);
			try
			{
				InternalScriptCommandsPointer->Select_Weapon(
					reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<char *>(weaponNameHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(weaponNameHandle);
			}
		}
	}

	void ScriptCommands::SendCustomEvent(IScriptableGameObj ^from, IScriptableGameObj ^to, int type, int param, float delay)
	{
		if (InternalScriptCommandsPointer->Send_Custom_Event == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (from == nullptr || from->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("from");
		}
		else if (to == nullptr || to->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("to");
		}

		InternalScriptCommandsPointer->Send_Custom_Event(
			reinterpret_cast<::ScriptableGameObj *>(from->ScriptableGameObjPointer.ToPointer()),
			reinterpret_cast<::ScriptableGameObj *>(to->ScriptableGameObjPointer.ToPointer()),
			type,
			param,
			delay);
	}

	void ScriptCommands::SendDamagedEvent(IScriptableGameObj ^object, IScriptableGameObj ^damager)
	{
		if (InternalScriptCommandsPointer->Send_Damaged_Event == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		if (damager == nullptr || damager->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalScriptCommandsPointer->Send_Damaged_Event(
				reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
				nullptr);
		}
		else
		{
			InternalScriptCommandsPointer->Send_Damaged_Event(
				reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<::ScriptableGameObj *>(damager->ScriptableGameObjPointer.ToPointer()));
		}
	}

	float ScriptCommands::GetRandom(float min, float max)
	{
		if (InternalScriptCommandsPointer->Get_Random == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return InternalScriptCommandsPointer->Get_Random(min, max);
	}

	int ScriptCommands::GetRandomInt(int min, int max)
	{
		if (InternalScriptCommandsPointer->Get_Random_Int == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return InternalScriptCommandsPointer->Get_Random_Int(min, max);
	}

	IScriptableGameObj ^ScriptCommands::FindRandomSimpleObject(String ^presetName)
	{
		if (InternalScriptCommandsPointer->Find_Random_Simple_Object == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (presetName == nullptr)
		{
			throw gcnew ArgumentNullException("presetName");
		}

		IntPtr presetNameHandle = Marshal::StringToHGlobalAnsi(presetName);
		try
		{
			auto result = InternalScriptCommandsPointer->Find_Random_Simple_Object(reinterpret_cast<char *>(presetNameHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew ScriptableGameObj(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(presetNameHandle);
		}
	}

	void ScriptCommands::SetModel(IScriptableGameObj ^obj, String ^modelName)
	{
		if (InternalScriptCommandsPointer->Set_Model == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		IntPtr modelNameHandle = Marshal::StringToHGlobalAnsi(modelName);
		try
		{
			InternalScriptCommandsPointer->Set_Model(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(modelNameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(modelNameHandle);
		}
	}

	void ScriptCommands::SetAnimation(IScriptableGameObj ^obj, String ^animName, bool looping, String ^subObjName, float startFrame, float endFrame, bool isBlended)
	{
		if (InternalScriptCommandsPointer->Set_Animation == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		if (animName == nullptr)
		{
			if (subObjName == nullptr)
			{
				InternalScriptCommandsPointer->Set_Animation(
					reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
					nullptr,
					looping,
					nullptr,
					startFrame,
					endFrame,
					isBlended);
			}
			else
			{
				IntPtr subObjNameHandle = Marshal::StringToHGlobalAnsi(subObjName);
				try
				{
					InternalScriptCommandsPointer->Set_Animation(
						reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
						nullptr,
						looping,
						reinterpret_cast<char *>(subObjNameHandle.ToPointer()),
						startFrame,
						endFrame,
						isBlended);
				}
				finally
				{
					Marshal::FreeHGlobal(subObjNameHandle);
				}
			}
		}
		else
		{
			IntPtr animNameHandle = Marshal::StringToHGlobalAnsi(animName);
			try
			{
				if (subObjName == nullptr)
				{
					InternalScriptCommandsPointer->Set_Animation(
						reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
						reinterpret_cast<char *>(animNameHandle.ToPointer()),
						looping,
						nullptr,
						startFrame,
						endFrame,
						isBlended);
				}
				else
				{
					IntPtr subObjNameHandle = Marshal::StringToHGlobalAnsi(subObjName);
					try
					{
						InternalScriptCommandsPointer->Set_Animation(
							reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
							reinterpret_cast<char *>(animNameHandle.ToPointer()),
							looping,
							reinterpret_cast<char *>(subObjNameHandle.ToPointer()),
							startFrame,
							endFrame,
							isBlended);
					}
					finally
					{
						Marshal::FreeHGlobal(subObjNameHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(animNameHandle);
			}
		}
	}

	void ScriptCommands::SetAnimationFrame(IScriptableGameObj ^obj, String ^animName, int frame)
	{
		if (InternalScriptCommandsPointer->Set_Animation_Frame == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		if (animName == nullptr)
		{
			InternalScriptCommandsPointer->Set_Animation_Frame(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				nullptr,
				frame);
		}
		else
		{
			IntPtr animNameHandle = Marshal::StringToHGlobalAnsi(animName);
			try
			{
				InternalScriptCommandsPointer->Set_Animation_Frame(
					reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<char *>(animNameHandle.ToPointer()),
					frame);
			}
			finally
			{
				Marshal::FreeHGlobal(animNameHandle);
			}
		}
	}

	int ScriptCommands::CreateSound(String ^soundPresetName, Vector3 position, IScriptableGameObj ^creator)
	{
		if (InternalScriptCommandsPointer->Create_Sound == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (soundPresetName == nullptr)
		{
			throw gcnew ArgumentNullException("soundPresetName");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		IntPtr soundPresetNameHandle = Marshal::StringToHGlobalAnsi(soundPresetName);
		try
		{
			if (creator == nullptr || creator->ScriptableGameObjPointer.ToPointer() == nullptr)
			{
				return InternalScriptCommandsPointer->Create_Sound(
					reinterpret_cast<char *>(soundPresetNameHandle.ToPointer()),
					positionVec,
					nullptr);
			}
			else
			{
				return InternalScriptCommandsPointer->Create_Sound(
					reinterpret_cast<char *>(soundPresetNameHandle.ToPointer()),
					positionVec,
					reinterpret_cast<::ScriptableGameObj *>(creator->ScriptableGameObjPointer.ToPointer()));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(soundPresetNameHandle);
		}
	}

	int ScriptCommands::Create2DSound(String ^soundPresetName)
	{
		if (InternalScriptCommandsPointer->Create_2D_Sound == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (soundPresetName == nullptr)
		{
			throw gcnew ArgumentNullException("soundPresetName");
		}

		IntPtr soundPresetNameHandle = Marshal::StringToHGlobalAnsi(soundPresetName);
		try
		{
			return InternalScriptCommandsPointer->Create_2D_Sound(reinterpret_cast<char *>(soundPresetNameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(soundPresetNameHandle);
		}
	}

	int ScriptCommands::Create2DWAVSound(String ^wavFilename)
	{
		if (InternalScriptCommandsPointer->Create_2D_WAV_Sound == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (wavFilename == nullptr)
		{
			throw gcnew ArgumentNullException("wavFilename");
		}

		IntPtr wavFilenameHandle = Marshal::StringToHGlobalAnsi(wavFilename);
		try
		{
			return InternalScriptCommandsPointer->Create_2D_WAV_Sound(reinterpret_cast<char *>(wavFilenameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(wavFilenameHandle);
		}
	}

	int ScriptCommands::Create3DWAVSoundAtBone(String ^wavFilename, IScriptableGameObj ^obj, String ^boneName)
	{
		if (InternalScriptCommandsPointer->Create_3D_WAV_Sound_At_Bone == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (wavFilename == nullptr)
		{
			throw gcnew ArgumentNullException("wavFilename");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		IntPtr wavFilenameHandle = Marshal::StringToHGlobalAnsi(wavFilename);
		try
		{
			if (boneName == nullptr)
			{
				return InternalScriptCommandsPointer->Create_3D_WAV_Sound_At_Bone(
					reinterpret_cast<char *>(wavFilenameHandle.ToPointer()),
					reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
					nullptr);
			}
			else
			{
				IntPtr boneNameHandle = Marshal::StringToHGlobalAnsi(boneName);
				try
				{
					return InternalScriptCommandsPointer->Create_3D_WAV_Sound_At_Bone(
						reinterpret_cast<char *>(wavFilenameHandle.ToPointer()),
						reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
						reinterpret_cast<char *>(boneNameHandle.ToPointer()));
				}
				finally
				{
					Marshal::FreeHGlobal(boneNameHandle);
				}
			}
		}
		finally
		{
			Marshal::FreeHGlobal(wavFilenameHandle);
		}
	}

	int ScriptCommands::Create3DSoundAtBone(String ^soundPresetName, IScriptableGameObj ^obj, String ^boneName)
	{
		if (InternalScriptCommandsPointer->Create_3D_Sound_At_Bone == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (soundPresetName == nullptr)
		{
			throw gcnew ArgumentNullException("soundPresetName");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		IntPtr soundPresetNameHandle = Marshal::StringToHGlobalAnsi(soundPresetName);
		try
		{
			if (boneName == nullptr)
			{
				return InternalScriptCommandsPointer->Create_3D_Sound_At_Bone(
					reinterpret_cast<char *>(soundPresetNameHandle.ToPointer()),
					reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
					nullptr);
			}
			else
			{
				IntPtr boneNameHandle = Marshal::StringToHGlobalAnsi(boneName);
				try
				{
					return InternalScriptCommandsPointer->Create_3D_Sound_At_Bone(
						reinterpret_cast<char *>(soundPresetNameHandle.ToPointer()),
						reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
						reinterpret_cast<char *>(boneNameHandle.ToPointer()));
				}
				finally
				{
					Marshal::FreeHGlobal(boneNameHandle);
				}
			}
		}
		finally
		{
			Marshal::FreeHGlobal(soundPresetNameHandle);
		}
	}

	int ScriptCommands::CreateLogicalSound(IScriptableGameObj ^creator, int type, Vector3 position, float radius)
	{
		if (InternalScriptCommandsPointer->Create_Logical_Sound == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		if (creator == nullptr || creator->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			return InternalScriptCommandsPointer->Create_Logical_Sound(
				nullptr,
				type,
				positionVec,
				radius);
		}
		else
		{
			return InternalScriptCommandsPointer->Create_Logical_Sound(
				reinterpret_cast<::ScriptableGameObj *>(creator->ScriptableGameObjPointer.ToPointer()),
				type,
				positionVec,
				radius);
		}
	}

	void ScriptCommands::StartSound(int soundId)
	{
		if (InternalScriptCommandsPointer->Start_Sound == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Start_Sound(soundId);
	}

	void ScriptCommands::StopSound(int soundId, bool destroySound)
	{
		if (InternalScriptCommandsPointer->Stop_Sound == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Stop_Sound(soundId, destroySound);
	}

	void ScriptCommands::MonitorSound(IScriptableGameObj ^obj, int soundId)
	{
		if (InternalScriptCommandsPointer->Monitor_Sound == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalScriptCommandsPointer->Monitor_Sound(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			soundId);
	}

	void ScriptCommands::SetBackgroundMusic(String ^wavFilename)
	{
		if (InternalScriptCommandsPointer->Set_Background_Music == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (wavFilename == nullptr)
		{
			throw gcnew ArgumentNullException("wavFilename");
		}

		IntPtr wavFilenameHandle = Marshal::StringToHGlobalAnsi(wavFilename);
		try
		{
			InternalScriptCommandsPointer->Set_Background_Music(reinterpret_cast<char *>(wavFilenameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(wavFilenameHandle);
		}
	}

	void ScriptCommands::FadeBackgroundMusic(String ^wavFilename, int fadeOutTime, int fadeInTime)
	{
		if (InternalScriptCommandsPointer->Fade_Background_Music == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (wavFilename == nullptr)
		{
			throw gcnew ArgumentNullException("wavFilename");
		}

		IntPtr wavFilenameHandle = Marshal::StringToHGlobalAnsi(wavFilename);
		try
		{
			InternalScriptCommandsPointer->Fade_Background_Music(
				reinterpret_cast<char *>(wavFilenameHandle.ToPointer()),
				fadeOutTime,
				fadeInTime);
		}
		finally
		{
			Marshal::FreeHGlobal(wavFilenameHandle);
		}
	}

	void ScriptCommands::StopBackgroundMusic()
	{
		if (InternalScriptCommandsPointer->Stop_Background_Music == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Stop_Background_Music();
	}

	float ScriptCommands::GetHealth(IScriptableGameObj ^obj)
	{
		if (InternalScriptCommandsPointer->Get_Health == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalScriptCommandsPointer->Get_Health(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	float ScriptCommands::GetMaxHealth(IScriptableGameObj ^obj)
	{
		if (InternalScriptCommandsPointer->Get_Max_Health == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalScriptCommandsPointer->Get_Max_Health(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::SetHealth(IScriptableGameObj ^obj, float health)
	{
		if (InternalScriptCommandsPointer->Set_Health == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalScriptCommandsPointer->Set_Health(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			health);
	}

	float ScriptCommands::GetShieldStrength(IScriptableGameObj ^obj)
	{
		if (InternalScriptCommandsPointer->Get_Shield_Strength == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalScriptCommandsPointer->Get_Shield_Strength(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	float ScriptCommands::GetMaxShieldStrength(IScriptableGameObj ^obj)
	{
		if (InternalScriptCommandsPointer->Get_Max_Shield_Strength == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalScriptCommandsPointer->Get_Max_Shield_Strength(reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::SetShieldStrength(IScriptableGameObj ^obj, float strength)
	{
		if (InternalScriptCommandsPointer->Set_Shield_Strength == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalScriptCommandsPointer->Set_Shield_Strength(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			strength);
	}

	void ScriptCommands::SetShieldType(IScriptableGameObj ^obj, String ^name)
	{
		if (InternalScriptCommandsPointer->Set_Shield_Type == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			InternalScriptCommandsPointer->Set_Shield_Type(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(nameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	int ScriptCommands::GetPlayerType(IScriptableGameObj ^obj)
	{
		if (InternalScriptCommandsPointer->Get_Player_Type == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalScriptCommandsPointer->Get_Player_Type(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::SetPlayerType(IScriptableGameObj ^obj, int type)
	{
		if (InternalScriptCommandsPointer->Set_Player_Type == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalScriptCommandsPointer->Set_Player_Type(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			type);
	}

	float ScriptCommands::GetDistance(Vector3 p1, Vector3 p2)
	{
		if (InternalScriptCommandsPointer->Get_Distance == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Vector3 p1Vec;
		::Vector3 p2Vec;

		Vector3::ManagedToUnmanagedVector3(p1, p1Vec);
		Vector3::ManagedToUnmanagedVector3(p2, p2Vec);

		return InternalScriptCommandsPointer->Get_Distance(p1Vec, p2Vec);
	}

	void ScriptCommands::SetCameraHost(IScriptableGameObj ^obj)
	{
		if (InternalScriptCommandsPointer->Set_Camera_Host == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalScriptCommandsPointer->Set_Camera_Host(nullptr);
		}
		else
		{
			InternalScriptCommandsPointer->Set_Camera_Host(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		}
	}

	void ScriptCommands::ForceCameraLook(Vector3 target)
	{
		if (InternalScriptCommandsPointer->Force_Camera_Look == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Vector3 targetVec;

		Vector3::ManagedToUnmanagedVector3(target, targetVec);

		InternalScriptCommandsPointer->Force_Camera_Look(targetVec);
	}

	IScriptableGameObj ^ScriptCommands::GetTheStar()
	{
		if (InternalScriptCommandsPointer->Get_The_Star == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		auto result = InternalScriptCommandsPointer->Get_The_Star();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptableGameObj(IntPtr(result));
		}
	}

	IScriptableGameObj ^ScriptCommands::GetAStar(Vector3 pos)
	{
		if (InternalScriptCommandsPointer->Get_A_Star == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		auto result = InternalScriptCommandsPointer->Get_A_Star(posVec);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptableGameObj(IntPtr(result));
		}
	}

	IScriptableGameObj ^ScriptCommands::FindClosestSoldier(Vector3 pos, float minDist, float maxDist, bool onlyHuman)
	{
		if (InternalScriptCommandsPointer->Find_Closest_Soldier == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		auto result = InternalScriptCommandsPointer->Find_Closest_Soldier(posVec, minDist, maxDist, onlyHuman);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptableGameObj(IntPtr(result));
		}
	}

	bool ScriptCommands::IsAStar(IScriptableGameObj ^obj)
	{
		if (InternalScriptCommandsPointer->Is_A_Star == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalScriptCommandsPointer->Is_A_Star(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::ControlEnable(IScriptableGameObj ^obj, bool enable)
	{
		if (InternalScriptCommandsPointer->Control_Enable == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalScriptCommandsPointer->Control_Enable(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			enable);
	}

	String ^ScriptCommands::GetDamageBoneName()
	{
		if (InternalScriptCommandsPointer->Get_Damage_Bone_Name == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		auto result = InternalScriptCommandsPointer->Get_Damage_Bone_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	bool ScriptCommands::GetDamageBoneDirection()
	{
		if (InternalScriptCommandsPointer->Get_Damage_Bone_Direction == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return InternalScriptCommandsPointer->Get_Damage_Bone_Direction();
	}

	bool ScriptCommands::IsObjectVisible(IScriptableGameObj ^looker, IScriptableGameObj ^obj)
	{
		if (InternalScriptCommandsPointer->Is_Object_Visible == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (looker == nullptr || looker->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("looker");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalScriptCommandsPointer->Is_Object_Visible(
			reinterpret_cast<::ScriptableGameObj *>(looker->ScriptableGameObjPointer.ToPointer()),
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::EnableEnemySeen(IScriptableGameObj ^obj, bool enable)
	{
		if (InternalScriptCommandsPointer->Enable_Enemy_Seen == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalScriptCommandsPointer->Enable_Enemy_Seen(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			enable);
	}

	void ScriptCommands::SetDisplayColor(System::Drawing::Color color)
	{
		if (InternalScriptCommandsPointer->Set_Display_Color == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Set_Display_Color(color.R, color.G, color.B);
	}

	void ScriptCommands::DisplayText(int stringId)
	{
		if (InternalScriptCommandsPointer->Display_Text == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Display_Text(stringId);
	}

	void ScriptCommands::DisplayFloat(float value, String ^format)
	{
		if (InternalScriptCommandsPointer->Display_Float == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(format);
		try
		{
			InternalScriptCommandsPointer->Display_Float(
				value,
				reinterpret_cast<char *>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void ScriptCommands::DisplayInt(int value, String ^format)
	{
		if (InternalScriptCommandsPointer->Display_Int == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(format);
		try
		{
			InternalScriptCommandsPointer->Display_Int(
				value,
				reinterpret_cast<char *>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void ScriptCommands::SaveData(IntPtr saver, int id, array<std::uint8_t> ^data)
	{
		if (InternalScriptCommandsPointer->Save_Data == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (saver.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("saver");
		}
		else if (data == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		pin_ptr<std::uint8_t> pinnedData = &data[0];
		std::uint8_t *dataPtr = pinnedData;

		InternalScriptCommandsPointer->Save_Data(
			*reinterpret_cast<::ScriptSaver *>(saver.ToPointer()),
			id,
			data->Length,
			dataPtr);
	}

	void ScriptCommands::SavePointer(IntPtr saver, int id, IntPtr pointer)
	{
		if (InternalScriptCommandsPointer->Save_Pointer == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (saver.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("saver");
		}

		InternalScriptCommandsPointer->Save_Pointer(
			*reinterpret_cast<::ScriptSaver *>(saver.ToPointer()),
			id,
			pointer.ToPointer());
	}

	bool ScriptCommands::LoadBegin(IntPtr loader, int %id)
	{
		if (InternalScriptCommandsPointer->Load_Begin == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (loader.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("loader");
		}

		int tmpId = id;

		bool result = InternalScriptCommandsPointer->Load_Begin(
			*reinterpret_cast<::ScriptLoader *>(loader.ToPointer()),
			&tmpId);

		id = tmpId;

		return result;
	}

	void ScriptCommands::LoadData(IntPtr loader, array<std::uint8_t> ^data)
	{
		if (InternalScriptCommandsPointer->Load_Data == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (loader.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("loader");
		}
		else if (data == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		pin_ptr<std::uint8_t> pinnedData = &data[0];
		std::uint8_t *dataPtr = pinnedData;

		InternalScriptCommandsPointer->Load_Data(
			*reinterpret_cast<::ScriptLoader *>(loader.ToPointer()),
			data->Length,
			dataPtr);
	}

	void ScriptCommands::LoadPointer(IntPtr loader, IntPtr %pointer)
	{
		if (InternalScriptCommandsPointer->Load_Pointer == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (loader.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("loader");
		}

		void *tmpPointer = pointer.ToPointer();

		InternalScriptCommandsPointer->Load_Pointer(
			*reinterpret_cast<::ScriptLoader *>(loader.ToPointer()),
			&tmpPointer);

		pointer = IntPtr(tmpPointer);
	}

	void ScriptCommands::LoadEnd(IntPtr loader)
	{
		if (InternalScriptCommandsPointer->Load_End == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (loader.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("loader");
		}

		InternalScriptCommandsPointer->Load_End(
			*reinterpret_cast<::ScriptLoader *>(loader.ToPointer()));
	}

	void ScriptCommands::BeginChunk(IntPtr saver, unsigned int chunkID)
	{
		if (InternalScriptCommandsPointer->Begin_Chunk == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (saver.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("saver");
		}

		InternalScriptCommandsPointer->Begin_Chunk(
			*reinterpret_cast<::ScriptSaver *>(saver.ToPointer()),
			chunkID);
	}

	void ScriptCommands::EndChunk(IntPtr saver)
	{
		if (InternalScriptCommandsPointer->End_Chunk == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (saver.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("saver");
		}

		InternalScriptCommandsPointer->End_Chunk(
			*reinterpret_cast<::ScriptSaver *>(saver.ToPointer()));
	}

	bool ScriptCommands::OpenChunk(IntPtr loader, unsigned int %chunkID)
	{
		if (InternalScriptCommandsPointer->Open_Chunk == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (loader.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("loader");
		}

		unsigned int tmpChunkID = chunkID;

		bool result = InternalScriptCommandsPointer->Open_Chunk(
			*reinterpret_cast<::ScriptLoader *>(loader.ToPointer()),
			&tmpChunkID);

		chunkID = tmpChunkID;

		return result;
	}

	void ScriptCommands::CloseChunk(IntPtr loader)
	{
		if (InternalScriptCommandsPointer->Close_Chunk == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (loader.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("loader");
		}

		InternalScriptCommandsPointer->Close_Chunk(
			*reinterpret_cast<::ScriptLoader *>(loader.ToPointer()));
	}

	void ScriptCommands::ClearRadarMarkers()
	{
		if (InternalScriptCommandsPointer->Clear_Radar_Markers == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Clear_Radar_Markers();
	}

	void ScriptCommands::ClearRadarMarker(int id)
	{
		if (InternalScriptCommandsPointer->Clear_Radar_Marker == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Clear_Radar_Marker(id);
	}

	void ScriptCommands::AddRadarMarker(int id, Vector3 position, int shapeType, int colorType)
	{
		if (InternalScriptCommandsPointer->Add_Radar_Marker == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Vector3 positionVec;
		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		InternalScriptCommandsPointer->Add_Radar_Marker(
			id,
			positionVec,
			shapeType,
			colorType);
	}

	void ScriptCommands::SetObjRadarBlipShape(IScriptableGameObj ^obj, int shapeType)
	{
		if (InternalScriptCommandsPointer->Set_Obj_Radar_Blip_Shape == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalScriptCommandsPointer->Set_Obj_Radar_Blip_Shape(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			shapeType);
	}

	void ScriptCommands::SetObjRadarBlipColor(IScriptableGameObj ^obj, int colorType)
	{
		if (InternalScriptCommandsPointer->Set_Obj_Radar_Blip_Color == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalScriptCommandsPointer->Set_Obj_Radar_Blip_Color(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			colorType);
	}

	void ScriptCommands::EnableRadar(bool enable)
	{
		if (InternalScriptCommandsPointer->Enable_Radar == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Enable_Radar(enable);
	}

	void ScriptCommands::ClearMapCell(int cellX, int cellY)
	{
		if (InternalScriptCommandsPointer->Clear_Map_Cell == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Clear_Map_Cell(cellX, cellY);
	}

	void ScriptCommands::ClearMapCellByPos(Vector3 worldSpacePos)
	{
		if (InternalScriptCommandsPointer->Clear_Map_Cell_By_Pos == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Vector3 worldSpacePosVec;
		Vector3::ManagedToUnmanagedVector3(worldSpacePos, worldSpacePosVec);

		InternalScriptCommandsPointer->Clear_Map_Cell_By_Pos(worldSpacePosVec);
	}

	void ScriptCommands::ClearMapCellByPixelPos(int pixelPosX, int pixelPosY)
	{
		if (InternalScriptCommandsPointer->Clear_Map_Cell_By_Pixel_Pos == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Clear_Map_Cell_By_Pixel_Pos(pixelPosX, pixelPosY);
	}

	void ScriptCommands::ClearMapRegionByPos(Vector3 worldSpacePos, int pixelRadius)
	{
		if (InternalScriptCommandsPointer->Clear_Map_Region_By_Pos == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Vector3 worldSpacePosVec;
		Vector3::ManagedToUnmanagedVector3(worldSpacePos, worldSpacePosVec);

		InternalScriptCommandsPointer->Clear_Map_Region_By_Pos(worldSpacePosVec, pixelRadius);
	}

	void ScriptCommands::RevealMap()
	{
		if (InternalScriptCommandsPointer->Reveal_Map == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Reveal_Map();
	}

	void ScriptCommands::ShroudMap()
	{
		if (InternalScriptCommandsPointer->Shroud_Map == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Shroud_Map();
	}

	void ScriptCommands::ShowPlayerMapMarker(bool onoff)
	{
		if (InternalScriptCommandsPointer->Show_Player_Map_Marker == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Show_Player_Map_Marker(onoff);
	}

	float ScriptCommands::GetSafeFlightHeight(float xPos, float yPos)
	{
		if (InternalScriptCommandsPointer->Get_Safe_Flight_Height == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return InternalScriptCommandsPointer->Get_Safe_Flight_Height(xPos, yPos);
	}

	void ScriptCommands::CreateExplosion(String ^explosionDefName, Vector3 pos, IScriptableGameObj ^creator)
	{
		if (InternalScriptCommandsPointer->Create_Explosion == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (explosionDefName == nullptr)
		{
			throw gcnew ArgumentNullException("explosionDefName");
		}

		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		IntPtr explosionDefNameHandle = Marshal::StringToHGlobalAnsi(explosionDefName);
		try
		{
			if (creator == nullptr || creator->ScriptableGameObjPointer.ToPointer() == nullptr)
			{
				InternalScriptCommandsPointer->Create_Explosion(
					reinterpret_cast<char *>(explosionDefNameHandle.ToPointer()),
					posVec,
					nullptr);
			}
			else
			{
				InternalScriptCommandsPointer->Create_Explosion(
					reinterpret_cast<char *>(explosionDefNameHandle.ToPointer()),
					posVec,
					reinterpret_cast<::ScriptableGameObj *>(creator->ScriptableGameObjPointer.ToPointer()));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(explosionDefNameHandle);
		}
	}

	void ScriptCommands::CreateExplosionAtBone(String ^explosionDefName, IScriptableGameObj ^object, String ^boneName, IScriptableGameObj ^creator)
	{
		if (InternalScriptCommandsPointer->Create_Explosion_At_Bone == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (explosionDefName == nullptr)
		{
			throw gcnew ArgumentNullException("explosionDefName");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}
		else if (boneName == nullptr)
		{
			throw gcnew ArgumentNullException("boneName");
		}

		IntPtr explosionDefNameHandle = Marshal::StringToHGlobalAnsi(explosionDefName);
		try
		{
			IntPtr boneNameHandle = Marshal::StringToHGlobalAnsi(boneName);
			try
			{
				if (creator == nullptr || creator->ScriptableGameObjPointer.ToPointer() == nullptr)
				{
					InternalScriptCommandsPointer->Create_Explosion_At_Bone(
						reinterpret_cast<char *>(explosionDefNameHandle.ToPointer()),
						reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
						reinterpret_cast<char *>(boneNameHandle.ToPointer()),
						nullptr);
				}
				else
				{
					InternalScriptCommandsPointer->Create_Explosion_At_Bone(
						reinterpret_cast<char *>(explosionDefNameHandle.ToPointer()),
						reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
						reinterpret_cast<char *>(boneNameHandle.ToPointer()),
						reinterpret_cast<::ScriptableGameObj *>(creator->ScriptableGameObjPointer.ToPointer()));
				}
			}
			finally
			{
				Marshal::FreeHGlobal(boneNameHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(explosionDefNameHandle);
		}
	}

	void ScriptCommands::EnableHUD(bool enable)
	{
		if (InternalScriptCommandsPointer->Enable_HUD == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Enable_HUD(enable);
	}

	void ScriptCommands::MissionComplete(bool success)
	{
		if (InternalScriptCommandsPointer->Mission_Complete == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Mission_Complete(success);
	}

	void ScriptCommands::GivePowerUp(IScriptableGameObj ^obj, String ^presetName, bool displayOnHUD)
	{
		if (InternalScriptCommandsPointer->Give_PowerUp == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (presetName == nullptr)
		{
			throw gcnew ArgumentNullException("presetName");
		}

		IntPtr presetNameHandle = Marshal::StringToHGlobalAnsi(presetName);
		try
		{
			InternalScriptCommandsPointer->Give_PowerUp(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(presetNameHandle.ToPointer()),
				displayOnHUD);
		}
		finally
		{
			Marshal::FreeHGlobal(presetNameHandle);
		}
	}

	void ScriptCommands::InnateDisable(IScriptableGameObj ^object)
	{
		if (InternalScriptCommandsPointer->Innate_Disable == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Innate_Disable(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::InnateEnable(IScriptableGameObj ^object)
	{
		if (InternalScriptCommandsPointer->Innate_Enable == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Innate_Enable(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
	}

	bool ScriptCommands::InnateSoldierEnableEnemySeen(IScriptableGameObj ^obj, bool state)
	{
		if (InternalScriptCommandsPointer->Innate_Soldier_Enable_Enemy_Seen == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalScriptCommandsPointer->Innate_Soldier_Enable_Enemy_Seen(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			state);
	}

	bool ScriptCommands::InnateSoldierEnableGunshotHeard(IScriptableGameObj ^obj, bool state)
	{
		if (InternalScriptCommandsPointer->Innate_Soldier_Enable_Gunshot_Heard == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalScriptCommandsPointer->Innate_Soldier_Enable_Gunshot_Heard(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			state);
	}

	bool ScriptCommands::InnateSoldierEnableFootstepsHeard(IScriptableGameObj ^obj, bool state)
	{
		if (InternalScriptCommandsPointer->Innate_Soldier_Enable_Footsteps_Heard == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalScriptCommandsPointer->Innate_Soldier_Enable_Footsteps_Heard(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			state);
	}

	bool ScriptCommands::InnateSoldierEnableBulletHeard(IScriptableGameObj ^obj, bool state)
	{
		if (InternalScriptCommandsPointer->Innate_Soldier_Enable_Bullet_Heard == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalScriptCommandsPointer->Innate_Soldier_Enable_Bullet_Heard(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			state);
	}

	bool ScriptCommands::InnateSoldierEnableActions(IScriptableGameObj ^obj, bool state)
	{
		if (InternalScriptCommandsPointer->Innate_Soldier_Enable_Actions == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalScriptCommandsPointer->Innate_Soldier_Enable_Actions(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			state);
	}

	void ScriptCommands::SetInnateSoldierHomeLocation(IScriptableGameObj ^obj, Vector3 homePos, float homeRadius)
	{
		if (InternalScriptCommandsPointer->Set_Innate_Soldier_Home_Location == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Vector3 homePosVec;

		Vector3::ManagedToUnmanagedVector3(homePos, homePosVec);

		InternalScriptCommandsPointer->Set_Innate_Soldier_Home_Location(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			homePosVec,
			homeRadius);
	}

	void ScriptCommands::SetInnateAggressiveness(IScriptableGameObj ^obj, float aggressiveness)
	{
		if (InternalScriptCommandsPointer->Set_Innate_Aggressiveness == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalScriptCommandsPointer->Set_Innate_Aggressiveness(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			aggressiveness);
	}

	void ScriptCommands::SetInnateTakeCoverProbability(IScriptableGameObj ^obj, float probability)
	{
		if (InternalScriptCommandsPointer->Set_Innate_Take_Cover_Probability == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalScriptCommandsPointer->Set_Innate_Take_Cover_Probability(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			probability);
	}

	void ScriptCommands::SetInnateIsStationary(IScriptableGameObj ^obj, bool stationary)
	{
		if (InternalScriptCommandsPointer->Set_Innate_Is_Stationary == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalScriptCommandsPointer->Set_Innate_Is_Stationary(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			stationary);
	}

	void ScriptCommands::InnateForceStateBulletHeard(IScriptableGameObj ^obj, Vector3 pos)
	{
		if (InternalScriptCommandsPointer->Innate_Force_State_Bullet_Heard == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		InternalScriptCommandsPointer->Innate_Force_State_Bullet_Heard(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			posVec);
	}

	void ScriptCommands::InnateForceStateFootstepsHeard(IScriptableGameObj ^obj, Vector3 pos)
	{
		if (InternalScriptCommandsPointer->Innate_Force_State_Footsteps_Heard == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		InternalScriptCommandsPointer->Innate_Force_State_Footsteps_Heard(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			posVec);
	}

	void ScriptCommands::InnateForceStateGunshotsHeard(IScriptableGameObj ^obj, Vector3 pos)
	{
		if (InternalScriptCommandsPointer->Innate_Force_State_Gunshots_Heard == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		InternalScriptCommandsPointer->Innate_Force_State_Gunshots_Heard(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			posVec);
	}

	void ScriptCommands::InnateForceStateEnemySeen(IScriptableGameObj ^obj, IScriptableGameObj ^enemy)
	{
		if (InternalScriptCommandsPointer->Innate_Force_State_Enemy_Seen == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (enemy == nullptr || enemy->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("enemy");
		}

		InternalScriptCommandsPointer->Innate_Force_State_Enemy_Seen(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			reinterpret_cast<::ScriptableGameObj *>(enemy->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::StaticAnimPhysGotoFrame(int objId, float frame, String ^animName)
	{
		if (InternalScriptCommandsPointer->Static_Anim_Phys_Goto_Frame == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		if (animName == nullptr)
		{
			InternalScriptCommandsPointer->Static_Anim_Phys_Goto_Frame(objId, frame, nullptr);
		}
		else
		{
			IntPtr animNameHandle = Marshal::StringToHGlobalAnsi(animName);
			try
			{
				InternalScriptCommandsPointer->Static_Anim_Phys_Goto_Frame(
					objId,
					frame,
					reinterpret_cast<char *>(animNameHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(animNameHandle);
			}
		}
	}

	void ScriptCommands::StaticAnimPhysGotoLastFrame(int objId, String ^animName)
	{
		if (InternalScriptCommandsPointer->Static_Anim_Phys_Goto_Last_Frame == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		if (animName == nullptr)
		{
			InternalScriptCommandsPointer->Static_Anim_Phys_Goto_Last_Frame(objId, nullptr);
		}
		else
		{
			IntPtr animNameHandle = Marshal::StringToHGlobalAnsi(animName);
			try
			{
				InternalScriptCommandsPointer->Static_Anim_Phys_Goto_Last_Frame(
					objId,
					reinterpret_cast<char *>(animNameHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(animNameHandle);
			}
		}
	}

	unsigned int ScriptCommands::GetSyncTime()
	{
		if (InternalScriptCommandsPointer->Get_Sync_Time == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return InternalScriptCommandsPointer->Get_Sync_Time();
	}

	void ScriptCommands::AddObjective(int id, int type, int status, int shortDescriptionId, String ^descriptionSoundFilename, int longDescriptionId)
	{
		if (InternalScriptCommandsPointer->Add_Objective == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (descriptionSoundFilename == nullptr)
		{
			throw gcnew ArgumentNullException("descriptionSoundFilename");
		}

		IntPtr descriptionSoundFilenameHandle = Marshal::StringToHGlobalAnsi(descriptionSoundFilename);
		try
		{
			InternalScriptCommandsPointer->Add_Objective(
				id,
				type,
				status,
				shortDescriptionId,
				reinterpret_cast<char *>(descriptionSoundFilenameHandle.ToPointer()),
				longDescriptionId);
		}
		finally
		{
			Marshal::FreeHGlobal(descriptionSoundFilenameHandle);
		}
	}

	void ScriptCommands::RemoveObjective(int id)
	{
		if (InternalScriptCommandsPointer->Remove_Objective == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Remove_Objective(id);
	}

	void ScriptCommands::SetObjectiveStatus(int id, int status)
	{
		if (InternalScriptCommandsPointer->Set_Objective_Status == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Set_Objective_Status(id, status);
	}

	void ScriptCommands::ChangeObjectiveType(int id, int type)
	{
		if (InternalScriptCommandsPointer->Change_Objective_Type == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Change_Objective_Type(id, type);
	}

	void ScriptCommands::SetObjectiveRadarBlip(int id, Vector3 position)
	{
		if (InternalScriptCommandsPointer->Set_Objective_Radar_Blip == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		InternalScriptCommandsPointer->Set_Objective_Radar_Blip(id, positionVec);
	}

	void ScriptCommands::SetObjectiveRadarBlipObject(int id, IScriptableGameObj ^unit)
	{
		if (InternalScriptCommandsPointer->Set_Objective_Radar_Blip_Object == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (unit == nullptr || unit->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("unit");
		}

		InternalScriptCommandsPointer->Set_Objective_Radar_Blip_Object(
			id,
			reinterpret_cast<::ScriptableGameObj *>(unit->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::SetObjectiveHUDInfo(int id, float priority, String ^textureName, int messageId)
	{
		if (InternalScriptCommandsPointer->Set_Objective_HUD_Info == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (textureName == nullptr)
		{
			throw gcnew ArgumentNullException("textureName");
		}

		IntPtr textureNameHandle = Marshal::StringToHGlobalAnsi(textureName);
		try
		{
			InternalScriptCommandsPointer->Set_Objective_HUD_Info(
				id,
				priority,
				reinterpret_cast<char *>(textureNameHandle.ToPointer()),
				messageId);
		}
		finally
		{
			Marshal::FreeHGlobal(textureNameHandle);
		}
	}

	void ScriptCommands::SetObjectiveHUDInfoPosition(int id, float priority, String ^textureName, int messageId, Vector3 position)
	{
		if (InternalScriptCommandsPointer->Set_Objective_HUD_Info_Position == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (textureName == nullptr)
		{
			throw gcnew ArgumentNullException("textureName");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		IntPtr textureNameHandle = Marshal::StringToHGlobalAnsi(textureName);
		try
		{
			InternalScriptCommandsPointer->Set_Objective_HUD_Info_Position(
				id,
				priority,
				reinterpret_cast<char *>(textureNameHandle.ToPointer()),
				messageId,
				positionVec);
		}
		finally
		{
			Marshal::FreeHGlobal(textureNameHandle);
		}
	}

	void ScriptCommands::ShakeCamera(Vector3 pos, float radius, float intensity, float duration)
	{
		if (InternalScriptCommandsPointer->Shake_Camera == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		InternalScriptCommandsPointer->Shake_Camera(posVec, radius, intensity, duration);
	}

	void ScriptCommands::EnableSpawner(int id, bool enable)
	{
		if (InternalScriptCommandsPointer->Enable_Spawner == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Enable_Spawner(id, enable);
	}

	IScriptableGameObj ^ScriptCommands::TriggerSpawner(int id)
	{
		if (InternalScriptCommandsPointer->Trigger_Spawner == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		auto result = InternalScriptCommandsPointer->Trigger_Spawner(id);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptableGameObj(IntPtr(result));
		}
	}

	void ScriptCommands::EnableEngine(IScriptableGameObj ^object, bool onoff)
	{
		if (InternalScriptCommandsPointer->Enable_Engine == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Enable_Engine(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			onoff);
	}

	int ScriptCommands::GetDifficultyLevel()
	{
		if (InternalScriptCommandsPointer->Get_Difficulty_Level == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return InternalScriptCommandsPointer->Get_Difficulty_Level();
	}

	void ScriptCommands::GrantKey(IScriptableGameObj ^object, int key, bool grant)
	{
		if (InternalScriptCommandsPointer->Grant_Key == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Grant_Key(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			key,
			grant);
	}

	bool ScriptCommands::HasKey(IScriptableGameObj ^object, int key)
	{
		if (InternalScriptCommandsPointer->Has_Key == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalScriptCommandsPointer->Has_Key(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			key);
	}

	void ScriptCommands::EnableHibernation(IScriptableGameObj ^object, bool enable)
	{
		if (InternalScriptCommandsPointer->Enable_Hibernation == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Enable_Hibernation(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			enable);
	}

	void ScriptCommands::AttachToObjectBone(IScriptableGameObj ^object, IScriptableGameObj ^hostObject, String ^boneName)
	{
		if (InternalScriptCommandsPointer->Attach_To_Object_Bone == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		::ScriptableGameObj *hostObjectPtr;

		if (hostObject == nullptr || hostObject->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			hostObjectPtr = nullptr;
		}
		else
		{
			hostObjectPtr = reinterpret_cast<::ScriptableGameObj *>(hostObject->ScriptableGameObjPointer.ToPointer());
		}

		if (boneName == nullptr)
		{
			InternalScriptCommandsPointer->Attach_To_Object_Bone(
				reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
				hostObjectPtr,
				nullptr);
		}
		else
		{
			IntPtr boneNameHandle = Marshal::StringToHGlobalAnsi(boneName);
			try
			{
				InternalScriptCommandsPointer->Attach_To_Object_Bone(
					reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
					hostObjectPtr,
					reinterpret_cast<char *>(boneNameHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(boneNameHandle);
			}
		}
	}

	int ScriptCommands::CreateConversation(String ^conversationName, int priority, float maxDist, bool isInterruptable)
	{
		if (InternalScriptCommandsPointer->Create_Conversation == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (conversationName == nullptr)
		{
			throw gcnew ArgumentNullException("conversationName");
		}

		IntPtr conversationNameHandle = Marshal::StringToHGlobalAnsi(conversationName);
		try
		{
			return InternalScriptCommandsPointer->Create_Conversation(
				reinterpret_cast<char *>(conversationNameHandle.ToPointer()),
				priority,
				maxDist,
				isInterruptable);
		}
		finally
		{
			Marshal::FreeHGlobal(conversationNameHandle);
		}
	}

	void ScriptCommands::JoinConversation(IScriptableGameObj ^object, int activeConversationId, bool allowMove, bool allowHeadTurn, bool allowFace)
	{
		if (InternalScriptCommandsPointer->Join_Conversation == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalScriptCommandsPointer->Join_Conversation(
				nullptr,
				activeConversationId,
				allowMove,
				allowHeadTurn,
				allowFace);
		}
		else
		{
			InternalScriptCommandsPointer->Join_Conversation(
				reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
				activeConversationId,
				allowMove,
				allowHeadTurn,
				allowFace);
		}
	}

	void ScriptCommands::JoinConversationFacing(IScriptableGameObj ^object, int activeConversationId, int objIdToFace)
	{
		if (InternalScriptCommandsPointer->Join_Conversation_Facing == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Join_Conversation_Facing(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			activeConversationId,
			objIdToFace);
	}

	void ScriptCommands::StartConversation(int activeConversationId, int actionID)
	{
		if (InternalScriptCommandsPointer->Start_Conversation == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Start_Conversation(activeConversationId, actionID);
	}

	void ScriptCommands::MonitorConversation(IScriptableGameObj ^object, int activeConversationId)
	{
		if (InternalScriptCommandsPointer->Monitor_Conversation == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Monitor_Conversation(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			activeConversationId);
	}

	void ScriptCommands::StartRandomConversation(IScriptableGameObj ^object)
	{
		if (InternalScriptCommandsPointer->Start_Random_Conversation == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Start_Random_Conversation(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::StopConversation(int activeConversationId)
	{
		if (InternalScriptCommandsPointer->Stop_Conversation == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Stop_Conversation(activeConversationId);
	}

	void ScriptCommands::StopAllConversations()
	{
		if (InternalScriptCommandsPointer->Stop_All_Conversations == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Stop_All_Conversations();
	}

	void ScriptCommands::LockSoldierFacing(IScriptableGameObj ^object, IScriptableGameObj ^objectToFace, bool turnBody)
	{
		if (InternalScriptCommandsPointer->Lock_Soldier_Facing == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		if (objectToFace == nullptr || objectToFace->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalScriptCommandsPointer->Lock_Soldier_Facing(
				reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
				nullptr,
				turnBody);
		}
		else
		{
			InternalScriptCommandsPointer->Lock_Soldier_Facing(
				reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<::ScriptableGameObj *>(objectToFace->ScriptableGameObjPointer.ToPointer()),
				turnBody);
		}
	}

	void ScriptCommands::UnlockSoldierFacing(IScriptableGameObj ^object)
	{
		if (InternalScriptCommandsPointer->Unlock_Soldier_Facing == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Unlock_Soldier_Facing(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::ApplyDamage(IScriptableGameObj ^object, float amount, String ^warheadName, IScriptableGameObj ^damager)
	{
		if (InternalScriptCommandsPointer->Apply_Damage == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}
		else if (warheadName == nullptr)
		{
			throw gcnew ArgumentNullException("warheadName");
		}

		IntPtr warheadNameHandle = Marshal::StringToHGlobalAnsi(warheadName);
		try
		{
			if (damager == nullptr || damager->ScriptableGameObjPointer.ToPointer() == nullptr)
			{
				InternalScriptCommandsPointer->Apply_Damage(
					reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
					amount,
					reinterpret_cast<char *>(warheadNameHandle.ToPointer()),
					nullptr);
			}
			else
			{
				InternalScriptCommandsPointer->Apply_Damage(
					reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
					amount,
					reinterpret_cast<char *>(warheadNameHandle.ToPointer()),
					reinterpret_cast<::ScriptableGameObj *>(damager->ScriptableGameObjPointer.ToPointer()));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(warheadNameHandle);
		}
	}

	void ScriptCommands::SetLoitersAllowed(IScriptableGameObj ^object, bool allowed)
	{
		if (InternalScriptCommandsPointer->Set_Loiters_Allowed == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Set_Loiters_Allowed(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			allowed);
	}

	void ScriptCommands::SetIsVisible(IScriptableGameObj ^object, bool visible)
	{
		if (InternalScriptCommandsPointer->Set_Is_Visible == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Set_Is_Visible(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			visible);
	}

	void ScriptCommands::SetIsRendered(IScriptableGameObj ^object, bool rendered)
	{
		if (InternalScriptCommandsPointer->Set_Is_Rendered == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Set_Is_Rendered(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			rendered);
	}

	float ScriptCommands::GetPoints(IScriptableGameObj ^object)
	{
		if (InternalScriptCommandsPointer->Get_Points == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalScriptCommandsPointer->Get_Points(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::GivePoints(IScriptableGameObj ^object, float points, bool entireTeam)
	{
		if (InternalScriptCommandsPointer->Give_Points == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Give_Points(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			points,
			entireTeam);
	}

	float ScriptCommands::GetMoney(IScriptableGameObj ^object)
	{
		if (InternalScriptCommandsPointer->Get_Money == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalScriptCommandsPointer->Get_Money(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::GiveMoney(IScriptableGameObj ^object, float money, bool entireTeam)
	{
		if (InternalScriptCommandsPointer->Give_Money == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Give_Money(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			money,
			entireTeam);
	}

	bool ScriptCommands::GetBuildingPower(IScriptableGameObj ^object)
	{
		if (InternalScriptCommandsPointer->Get_Building_Power == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalScriptCommandsPointer->Get_Building_Power(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::SetBuildingPower(IScriptableGameObj ^object, bool onoff)
	{
		if (InternalScriptCommandsPointer->Set_Building_Power == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Set_Building_Power(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			onoff);
	}

	void ScriptCommands::PlayBuildingAnnouncement(IScriptableGameObj ^object, int textId)
	{
		if (InternalScriptCommandsPointer->Play_Building_Announcement == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Play_Building_Announcement(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			textId);
	}

	IScriptableGameObj ^ScriptCommands::FindNearestBuildingToPos(Vector3 position, String ^meshPrefix)
	{
		if (InternalScriptCommandsPointer->Find_Nearest_Building_To_Pos == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (meshPrefix == nullptr)
		{
			throw gcnew ArgumentNullException("meshPrefix");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		IntPtr meshPrefixHandle = Marshal::StringToHGlobalAnsi(meshPrefix);
		try
		{
			auto result = InternalScriptCommandsPointer->Find_Nearest_Building_To_Pos(
				positionVec,
				reinterpret_cast<char *>(meshPrefixHandle.ToPointer()));

			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew ScriptableGameObj(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(meshPrefixHandle);
		}
	}

	IScriptableGameObj ^ScriptCommands::FindNearestBuilding(IScriptableGameObj ^object, String ^meshPrefix)
	{
		if (InternalScriptCommandsPointer->Find_Nearest_Building == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}
		else if (meshPrefix == nullptr)
		{
			throw gcnew ArgumentNullException("meshPrefix");
		}

		IntPtr meshPrefixHandle = Marshal::StringToHGlobalAnsi(meshPrefix);
		try
		{
			auto result = InternalScriptCommandsPointer->Find_Nearest_Building(
				reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(meshPrefixHandle.ToPointer()));

			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew ScriptableGameObj(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(meshPrefixHandle);
		}
	}

	int ScriptCommands::TeamMembersInZone(IScriptableGameObj ^object, int playerType)
	{
		if (InternalScriptCommandsPointer->Team_Members_In_Zone == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalScriptCommandsPointer->Team_Members_In_Zone(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			playerType);
	}

	void ScriptCommands::SetClouds(float cloudCover, float cloudGloominess, float ramptime)
	{
		if (InternalScriptCommandsPointer->Set_Clouds == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Set_Clouds(cloudCover, cloudGloominess, ramptime);
	}

	void ScriptCommands::SetLightning(float intensity, float startDistance, float endDistance, float heading, float distribution, float ramptime)
	{
		if (InternalScriptCommandsPointer->Set_Lightning == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Set_Lightning(
			intensity,
			startDistance,
			endDistance,
			heading,
			distribution,
			ramptime);
	}

	void ScriptCommands::SetWarBlitz(float intensity, float startDistance, float endDistance, float heading, float distribution, float ramptime)
	{
		if (InternalScriptCommandsPointer->Set_War_Blitz == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Set_War_Blitz(
			intensity,
			startDistance,
			endDistance,
			heading,
			distribution,
			ramptime);
	}

	void ScriptCommands::SetWind(float heading, float speed, float variability, float ramptime)
	{
		if (InternalScriptCommandsPointer->Set_Wind == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Set_Wind(heading, speed, variability, ramptime);
	}

	void ScriptCommands::SetRain(float density, float ramptime, bool prime)
	{
		if (InternalScriptCommandsPointer->Set_Rain == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Set_Rain(density, ramptime, prime);
	}

	void ScriptCommands::SetSnow(float density, float ramptime, bool prime)
	{
		if (InternalScriptCommandsPointer->Set_Snow == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Set_Snow(density, ramptime, prime);
	}

	void ScriptCommands::SetAsh(float density, float ramptime, bool prime)
	{
		if (InternalScriptCommandsPointer->Set_Ash == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Set_Ash(density, ramptime, prime);
	}

	void ScriptCommands::SetFogEnable(bool enabled)
	{
		if (InternalScriptCommandsPointer->Set_Fog_Enable == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Set_Fog_Enable(enabled);
	}

	void ScriptCommands::SetFogRange(float startDistance, float endDistance, float ramptime)
	{
		if (InternalScriptCommandsPointer->Set_Fog_Range == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Set_Fog_Range(startDistance, endDistance, ramptime);
	}

	void ScriptCommands::EnableStealth(IScriptableGameObj ^object, bool onoff)
	{
		if (InternalScriptCommandsPointer->Enable_Stealth == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Enable_Stealth(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			onoff);
	}

	void ScriptCommands::CinematicSniperControl(bool enabled, float zoom)
	{
		if (InternalScriptCommandsPointer->Cinematic_Sniper_Control == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Cinematic_Sniper_Control(enabled, zoom);
	}

	int ScriptCommands::TextFileOpen(String ^filename)
	{
		if (InternalScriptCommandsPointer->Text_File_Open == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (filename == nullptr)
		{
			throw gcnew ArgumentNullException("filename");
		}

		IntPtr filenameHandle = Marshal::StringToHGlobalAnsi(filename);
		try
		{
			return InternalScriptCommandsPointer->Text_File_Open(
				reinterpret_cast<char *>(filenameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(filenameHandle);
		}
	}

	String ^ScriptCommands::TextFileGetString(int handle)
	{
		if (InternalScriptCommandsPointer->Text_File_Get_String == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (handle == 0)
		{
			throw gcnew ArgumentNullException("handle");
		}

		char buffer[2048] = { '\0' };
		if (InternalScriptCommandsPointer->Text_File_Get_String(handle, buffer, sizeof(buffer) / sizeof(char)))
		{
			return gcnew String(buffer);
		}
		else
		{
			return nullptr;
		}
	}

	void ScriptCommands::TextFileClose(int handle)
	{
		if (InternalScriptCommandsPointer->Text_File_Close == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Text_File_Close(handle);
	}

	void ScriptCommands::EnableVehicleTransitions(IScriptableGameObj ^object, bool enable)
	{
		if (InternalScriptCommandsPointer->Enable_Vehicle_Transitions == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Enable_Vehicle_Transitions(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			enable);
	}

	void ScriptCommands::DisplayGDIPlayerTerminal()
	{
		if (InternalScriptCommandsPointer->Display_GDI_Player_Terminal == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Display_GDI_Player_Terminal();
	}

	void ScriptCommands::DisplayNodPlayerTerminal()
	{
		if (InternalScriptCommandsPointer->Display_NOD_Player_Terminal == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Display_NOD_Player_Terminal();
	}

	void ScriptCommands::DisplayMutantPlayerTerminal()
	{
		if (InternalScriptCommandsPointer->Display_Mutant_Player_Terminal == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Display_Mutant_Player_Terminal();
	}

	bool ScriptCommands::RevealEncyclopediaCharacter(int objectId)
	{
		if (InternalScriptCommandsPointer->Reveal_Encyclopedia_Character == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return InternalScriptCommandsPointer->Reveal_Encyclopedia_Character(objectId);
	}

	bool ScriptCommands::RevealEncyclopediaWeapon(int objectId)
	{
		if (InternalScriptCommandsPointer->Reveal_Encyclopedia_Weapon == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return InternalScriptCommandsPointer->Reveal_Encyclopedia_Weapon(objectId);
	}

	bool ScriptCommands::RevealEncyclopediaVehicle(int objectId)
	{
		if (InternalScriptCommandsPointer->Reveal_Encyclopedia_Vehicle == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return InternalScriptCommandsPointer->Reveal_Encyclopedia_Vehicle(objectId);
	}

	bool ScriptCommands::RevealEncyclopediaBuilding(int objectId)
	{
		if (InternalScriptCommandsPointer->Reveal_Encyclopedia_Building == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return InternalScriptCommandsPointer->Reveal_Encyclopedia_Building(objectId);
	}

	void ScriptCommands::DisplayEncyclopediaEventUI()
	{
		if (InternalScriptCommandsPointer->Display_Encyclopedia_Event_UI == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Display_Encyclopedia_Event_UI();
	}

	void ScriptCommands::ScaleAIAwareness(float sightScale, float hearingScale)
	{
		if (InternalScriptCommandsPointer->Scale_AI_Awareness == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Scale_AI_Awareness(sightScale, hearingScale);
	}

	void ScriptCommands::EnableCinematicFreeze(IScriptableGameObj ^object, bool enable)
	{
		if (InternalScriptCommandsPointer->Enable_Cinematic_Freeze == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Enable_Cinematic_Freeze(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			enable);
	}

	void ScriptCommands::ExpirePowerup(IScriptableGameObj ^object)
	{
		if (InternalScriptCommandsPointer->Expire_Powerup == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Expire_Powerup(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::SetHUDHelpText(int stringId, Color color)
	{
		if (InternalScriptCommandsPointer->Set_HUD_Help_Text == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Vector3 colorVec(color.R / 255.0f, color.G / 255.0f, color.B / 255.0f);

		InternalScriptCommandsPointer->Set_HUD_Help_Text(stringId, colorVec);
	}

	void ScriptCommands::EnableHUDPokableIndicator(IScriptableGameObj ^object, bool enable)
	{
		if (InternalScriptCommandsPointer->Enable_HUD_Pokable_Indicator == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Enable_HUD_Pokable_Indicator(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			enable);
	}

	void ScriptCommands::EnableInnateConversations(IScriptableGameObj ^object, bool enable)
	{
		if (InternalScriptCommandsPointer->Enable_Innate_Conversations == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Enable_Innate_Conversations(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			enable);
	}

	void ScriptCommands::DisplayHealthBar(IScriptableGameObj ^object, bool display)
	{
		if (InternalScriptCommandsPointer->Display_Health_Bar == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Display_Health_Bar(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			display);
	}

	void ScriptCommands::EnableShadow(IScriptableGameObj ^object, bool enable)
	{
		if (InternalScriptCommandsPointer->Enable_Shadow == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Enable_Shadow(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
			enable);
	}

	void ScriptCommands::ClearWeapons(IScriptableGameObj ^object)
	{
		if (InternalScriptCommandsPointer->Clear_Weapons == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalScriptCommandsPointer->Clear_Weapons(
			reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
	}

	void ScriptCommands::SetNumTertiaryObjectives(int count)
	{
		if (InternalScriptCommandsPointer->Set_Num_Tertiary_Objectives == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Set_Num_Tertiary_Objectives(count);
	}

	void ScriptCommands::EnableLetterbox(bool onoff, float seconds)
	{
		if (InternalScriptCommandsPointer->Enable_Letterbox == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Enable_Letterbox(onoff, seconds);
	}

	void ScriptCommands::SetScreenFadeColor(Color color, float seconds)
	{
		if (InternalScriptCommandsPointer->Set_Screen_Fade_Color == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Set_Screen_Fade_Color(color.R / 255.0f, color.G / 255.0f, color.B / 255.0f, seconds);
	}

	void ScriptCommands::SetScreenFadeOpacity(float opacity, float seconds)
	{
		if (InternalScriptCommandsPointer->Set_Screen_Fade_Opacity == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		InternalScriptCommandsPointer->Set_Screen_Fade_Opacity(opacity, seconds);
	}

	IntPtr ScriptCommands::ScriptCommandsPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer);
	}

	int ScriptCommands::Size::get()
	{
		return InternalScriptCommandsPointer->Size;
	}

	void ScriptCommands::Size::set(int value)
	{
		InternalScriptCommandsPointer->Size = value;
	}

	int ScriptCommands::Version::get()
	{
		return InternalScriptCommandsPointer->Version;
	}

	void ScriptCommands::Version::set(int value)
	{
		InternalScriptCommandsPointer->Version = value;
	}

	IntPtr ScriptCommands::DebugMessagePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Debug_Message);
	}

	void ScriptCommands::DebugMessagePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Debug_Message = reinterpret_cast<void(*)(char *format, ...)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ActionResetPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Action_Reset);
	}

	void ScriptCommands::ActionResetPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Action_Reset = reinterpret_cast<void(*)(::ScriptableGameObj *, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ActionGotoPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Action_Goto);
	}

	void ScriptCommands::ActionGotoPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Action_Goto = reinterpret_cast<void(*)(::ScriptableGameObj *, const ::ActionParamsStruct &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ActionAttackPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Action_Attack);
	}

	void ScriptCommands::ActionAttackPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Action_Attack = reinterpret_cast<void(*)(::ScriptableGameObj *, const ::ActionParamsStruct &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ActionPlayAnimationPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Action_Play_Animation);
	}

	void ScriptCommands::ActionPlayAnimationPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Action_Play_Animation = reinterpret_cast<void(*)(::ScriptableGameObj *, const ::ActionParamsStruct &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ActionEnterExitPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Action_Enter_Exit);
	}

	void ScriptCommands::ActionEnterExitPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Action_Enter_Exit = reinterpret_cast<void(*)(::ScriptableGameObj *, const ::ActionParamsStruct &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ActionFaceLocationPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Action_Face_Location);
	}

	void ScriptCommands::ActionFaceLocationPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Action_Face_Location = reinterpret_cast<void(*)(::ScriptableGameObj *, const ::ActionParamsStruct &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ActionDockPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Action_Dock);
	}

	void ScriptCommands::ActionDockPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Action_Dock = reinterpret_cast<void(*)(::ScriptableGameObj *, const ::ActionParamsStruct &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ActionFollowInputPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Action_Follow_Input);
	}

	void ScriptCommands::ActionFollowInputPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Action_Follow_Input = reinterpret_cast<void(*)(::ScriptableGameObj *, const ::ActionParamsStruct &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ModifyActionPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Modify_Action);
	}

	void ScriptCommands::ModifyActionPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Modify_Action = reinterpret_cast<void(*)(::ScriptableGameObj *, int, const ::ActionParamsStruct &, bool, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetActionIDPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Action_ID);
	}

	void ScriptCommands::GetActionIDPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Action_ID = reinterpret_cast<int(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetActionParamsPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Action_Params);
	}

	void ScriptCommands::GetActionParamsPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Action_Params = reinterpret_cast<bool(*)(::ScriptableGameObj *, ::ActionParamsStruct &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::IsPerformingPathfindActionPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Is_Performing_Pathfind_Action);
	}

	void ScriptCommands::IsPerformingPathfindActionPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Is_Performing_Pathfind_Action = reinterpret_cast<bool(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetPositionPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Position);
	}

	void ScriptCommands::SetPositionPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Position = reinterpret_cast<void(*)(::ScriptableGameObj *, const ::Vector3 &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetPositionPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Position);
	}

	void ScriptCommands::GetPositionPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Position = reinterpret_cast<::Vector3(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetBonePositionPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Bone_Position);
	}

	void ScriptCommands::GetBonePositionPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Bone_Position = reinterpret_cast<::Vector3(*)(::ScriptableGameObj *, const char *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetFacingPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Facing);
	}

	void ScriptCommands::GetFacingPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Facing = reinterpret_cast<float(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetFacingPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Facing);
	}

	void ScriptCommands::SetFacingPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Facing = reinterpret_cast<void(*)(::ScriptableGameObj *, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::DisableAllCollisionsPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Disable_All_Collisions);
	}

	void ScriptCommands::DisableAllCollisionsPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Disable_All_Collisions = reinterpret_cast<void(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::DisablePhysicalCollisionsPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Disable_Physical_Collisions);
	}

	void ScriptCommands::DisablePhysicalCollisionsPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Disable_Physical_Collisions = reinterpret_cast<void(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::EnableCollisionsPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Enable_Collisions);
	}

	void ScriptCommands::EnableCollisionsPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Enable_Collisions = reinterpret_cast<void(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::DestroyObjectPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Destroy_Object);
	}

	void ScriptCommands::DestroyObjectPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Destroy_Object = reinterpret_cast<void(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::FindObjectPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Find_Object);
	}

	void ScriptCommands::FindObjectPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Find_Object = reinterpret_cast<::ScriptableGameObj * (*)(int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::CreateObjectPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Create_Object);
	}

	void ScriptCommands::CreateObjectPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Create_Object = reinterpret_cast<::ScriptableGameObj * (*)(const char *, const ::Vector3 &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::CreateObjectAtBonePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Create_Object_At_Bone);
	}

	void ScriptCommands::CreateObjectAtBonePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Create_Object_At_Bone = reinterpret_cast<::ScriptableGameObj *(*)(::ScriptableGameObj *, const char *, const char *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetIDPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_ID);
	}

	void ScriptCommands::GetIDPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_ID = reinterpret_cast<int(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetPresetIDPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Preset_ID);
	}

	void ScriptCommands::GetPresetIDPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Preset_ID = reinterpret_cast<int(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetPresetNamePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Preset_Name);
	}

	void ScriptCommands::GetPresetNamePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Preset_Name = reinterpret_cast<const char *(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::AttachScriptPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Attach_Script);
	}

	void ScriptCommands::AttachScriptPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Attach_Script = reinterpret_cast<void(*)(::ScriptableGameObj *, const char*, const char*)>(value.ToPointer());
	}

	IntPtr ScriptCommands::AddToDirtyCullListPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Add_To_Dirty_Cull_List);
	}

	void ScriptCommands::AddToDirtyCullListPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Add_To_Dirty_Cull_List = reinterpret_cast<void(*)(::ScriptableGameObj*)>(value.ToPointer());
	}

	IntPtr ScriptCommands::StartTimerPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Start_Timer);
	}

	void ScriptCommands::StartTimerPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Start_Timer = reinterpret_cast<void(*)(::ScriptableGameObj *, ::ScriptClass *, float, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::TriggerWeaponPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Trigger_Weapon);
	}

	void ScriptCommands::TriggerWeaponPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Trigger_Weapon = reinterpret_cast<void(*)(::ScriptableGameObj *, bool, const ::Vector3 &, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SelectWeaponPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Select_Weapon);
	}

	void ScriptCommands::SelectWeaponPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Select_Weapon = reinterpret_cast<void(*)(::ScriptableGameObj *, const char *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SendCustomEventPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Send_Custom_Event);
	}

	void ScriptCommands::SendCustomEventPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Send_Custom_Event = reinterpret_cast<void(*)(::ScriptableGameObj *, ::ScriptableGameObj *, int, int, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SendDamagedEventPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Send_Damaged_Event);
	}

	void ScriptCommands::SendDamagedEventPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Send_Damaged_Event = reinterpret_cast<void(*)(::ScriptableGameObj *, ::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetRandomPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Random);
	}

	void ScriptCommands::GetRandomPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Random = reinterpret_cast<float(*)(float, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetRandomIntPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Random_Int);
	}

	void ScriptCommands::GetRandomIntPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Random_Int = reinterpret_cast<int(*)(int, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::FindRandomSimpleObjectPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Find_Random_Simple_Object);
	}

	void ScriptCommands::FindRandomSimpleObjectPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Find_Random_Simple_Object = reinterpret_cast<::ScriptableGameObj *(*)(const char *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetModelPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Model);
	}

	void ScriptCommands::SetModelPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Model = reinterpret_cast<void(*)(::ScriptableGameObj *, const char *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetAnimationPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Animation);
	}

	void ScriptCommands::SetAnimationPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Animation = reinterpret_cast<void(*)(::ScriptableGameObj *, const char *, bool, const char *, float, float, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetAnimationFramePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Animation_Frame);
	}

	void ScriptCommands::SetAnimationFramePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Animation_Frame = reinterpret_cast<void(*)(::ScriptableGameObj *, const char *, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::CreateSoundPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Create_Sound);
	}

	void ScriptCommands::CreateSoundPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Create_Sound = reinterpret_cast<int(*)(const char *, const ::Vector3 &, ::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::Create2DSoundPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Create_2D_Sound);
	}

	void ScriptCommands::Create2DSoundPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Create_2D_Sound = reinterpret_cast<int(*)(const char *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::Create2DWAVSoundPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Create_2D_WAV_Sound);
	}

	void ScriptCommands::Create2DWAVSoundPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Create_2D_WAV_Sound = reinterpret_cast<int(*)(const char *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::Create3DWAVSoundAtBonePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Create_3D_WAV_Sound_At_Bone);
	}

	void ScriptCommands::Create3DWAVSoundAtBonePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Create_3D_WAV_Sound_At_Bone = reinterpret_cast<int(*)(const char *, ::ScriptableGameObj *, const char *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::Create3DSoundAtBonePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Create_3D_Sound_At_Bone);
	}

	void ScriptCommands::Create3DSoundAtBonePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Create_3D_Sound_At_Bone = reinterpret_cast<int(*)(const char *, ::ScriptableGameObj *, const char *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::CreateLogicalSoundPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Create_Logical_Sound);
	}

	void ScriptCommands::CreateLogicalSoundPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Create_Logical_Sound = reinterpret_cast<int(*)(::ScriptableGameObj *, int, const ::Vector3 &, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::StartSoundPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Start_Sound);
	}

	void ScriptCommands::StartSoundPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Start_Sound = reinterpret_cast<void(*)(int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::StopSoundPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Stop_Sound);
	}

	void ScriptCommands::StopSoundPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Stop_Sound = reinterpret_cast<void(*)(int, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::MonitorSoundPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Monitor_Sound);
	}

	void ScriptCommands::MonitorSoundPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Monitor_Sound = reinterpret_cast<void(*)(::ScriptableGameObj *, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetBackgroundMusicPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Background_Music);
	}

	void ScriptCommands::SetBackgroundMusicPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Background_Music = reinterpret_cast<void(*)(const char *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::FadeBackgroundMusicPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Fade_Background_Music);
	}

	void ScriptCommands::FadeBackgroundMusicPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Fade_Background_Music = reinterpret_cast<void(*)(const char *, int, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::StopBackgroundMusicPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Stop_Background_Music);
	}

	void ScriptCommands::StopBackgroundMusicPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Stop_Background_Music = reinterpret_cast<void(*)(void)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetHealthPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Health);
	}

	void ScriptCommands::GetHealthPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Health = reinterpret_cast<float(*)(::ScriptableGameObj *)>(value.ToPointer());
	}
	
	IntPtr ScriptCommands::GetMaxHealthPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Max_Health);
	}

	void ScriptCommands::GetMaxHealthPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Max_Health = reinterpret_cast<float(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetHealthPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Health);
	}

	void ScriptCommands::SetHealthPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Health = reinterpret_cast<void(*)(::ScriptableGameObj *, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetShieldStrengthPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Shield_Strength);
	}

	void ScriptCommands::GetShieldStrengthPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Shield_Strength = reinterpret_cast<float(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetMaxShieldStrengthPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Max_Shield_Strength);
	}

	void ScriptCommands::GetMaxShieldStrengthPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Max_Shield_Strength = reinterpret_cast<float(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetShieldStrengthPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Shield_Strength);
	}

	void ScriptCommands::SetShieldStrengthPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Shield_Strength = reinterpret_cast<void(*)(::ScriptableGameObj *, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetShieldTypePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Shield_Type);
	}

	void ScriptCommands::SetShieldTypePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Shield_Type = reinterpret_cast<void(*)(::ScriptableGameObj *, const char *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetPlayerTypePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Player_Type);
	}

	void ScriptCommands::GetPlayerTypePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Player_Type = reinterpret_cast<int(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetPlayerTypePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Player_Type);
	}

	void ScriptCommands::SetPlayerTypePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Player_Type = reinterpret_cast<void(*)(::ScriptableGameObj *, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetDistancePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Distance);
	}

	void ScriptCommands::GetDistancePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Distance = reinterpret_cast<float(*)(const ::Vector3 &, const ::Vector3 &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetCameraHostPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Camera_Host);
	}

	void ScriptCommands::SetCameraHostPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Camera_Host = reinterpret_cast<void(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ForceCameraLookPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Force_Camera_Look);
	}

	void ScriptCommands::ForceCameraLookPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Force_Camera_Look = reinterpret_cast<void(*)(const ::Vector3 &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetTheStarPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_The_Star);
	}

	void ScriptCommands::GetTheStarPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_The_Star = reinterpret_cast<::ScriptableGameObj *(*)()>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetAStarPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_A_Star);
	}

	void ScriptCommands::GetAStarPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_A_Star = reinterpret_cast<::ScriptableGameObj *(*)(const ::Vector3 &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::FindClosestSoldierPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Find_Closest_Soldier);
	}

	void ScriptCommands::FindClosestSoldierPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Find_Closest_Soldier = reinterpret_cast<::ScriptableGameObj *(*)(const ::Vector3 &, float, float, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::IsAStarPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Is_A_Star);
	}

	void ScriptCommands::IsAStarPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Is_A_Star = reinterpret_cast<bool(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ControlEnablePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Control_Enable);
	}

	void ScriptCommands::ControlEnablePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Control_Enable = reinterpret_cast<void(*)(::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetDamageBoneNamePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Damage_Bone_Name);
	}

	void ScriptCommands::GetDamageBoneNamePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Damage_Bone_Name = reinterpret_cast<const char *(*)()>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetDamageBoneDirectionPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Damage_Bone_Direction);
	}

	void ScriptCommands::GetDamageBoneDirectionPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Damage_Bone_Direction = reinterpret_cast<bool(*)()>(value.ToPointer());
	}

	IntPtr ScriptCommands::IsObjectVisiblePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Is_Object_Visible);
	}

	void ScriptCommands::IsObjectVisiblePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Is_Object_Visible = reinterpret_cast<bool(*)(::ScriptableGameObj *, ::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::EnableEnemySeenPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Enable_Enemy_Seen);
	}

	void ScriptCommands::EnableEnemySeenPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Enable_Enemy_Seen = reinterpret_cast<void(*)(::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetDisplayColorPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Display_Color);
	}

	void ScriptCommands::SetDisplayColorPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Display_Color = reinterpret_cast<void(*)(unsigned char, unsigned char, unsigned char)>(value.ToPointer());
	}

	IntPtr ScriptCommands::DisplayTextPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Display_Text);
	}

	void ScriptCommands::DisplayTextPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Display_Text = reinterpret_cast<void(*)(int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::DisplayFloatPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Display_Float);
	}

	void ScriptCommands::DisplayFloatPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Display_Float = reinterpret_cast<void(*)(float, const char *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::DisplayIntPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Display_Int);
	}

	void ScriptCommands::DisplayIntPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Display_Int = reinterpret_cast<void(*)(int, const char *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SaveDataPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Save_Data);
	}

	void ScriptCommands::SaveDataPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Save_Data = reinterpret_cast<void(*)(::ScriptSaver &, int, int, void *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SavePointerPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Save_Pointer);
	}

	void ScriptCommands::SavePointerPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Save_Pointer = reinterpret_cast<void(*)(::ScriptSaver &, int, void *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::LoadBeginPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Load_Begin);
	}

	void ScriptCommands::LoadBeginPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Load_Begin = reinterpret_cast<bool(*)(::ScriptLoader &, int *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::LoadDataPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Load_Data);
	}

	void ScriptCommands::LoadDataPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Load_Data = reinterpret_cast<void(*)(::ScriptLoader &, int, void *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::LoadPointerPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Load_Pointer);
	}

	void ScriptCommands::LoadPointerPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Load_Pointer = reinterpret_cast<void(*)(::ScriptLoader &, void **)>(value.ToPointer());
	}

	IntPtr ScriptCommands::LoadEndPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Load_End);
	}

	void ScriptCommands::LoadEndPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Load_End = reinterpret_cast<void(*)(::ScriptLoader &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::BeginChunkPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Begin_Chunk);
	}

	void ScriptCommands::BeginChunkPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Begin_Chunk = reinterpret_cast<void(*)(::ScriptSaver&, unsigned int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::EndChunkPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->End_Chunk);
	}

	void ScriptCommands::EndChunkPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->End_Chunk = reinterpret_cast<void(*)(::ScriptSaver&)>(value.ToPointer());
	}

	IntPtr ScriptCommands::OpenChunkPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Open_Chunk);
	}

	void ScriptCommands::OpenChunkPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Open_Chunk = reinterpret_cast<bool(*)(::ScriptLoader&, unsigned int*)>(value.ToPointer());
	}

	IntPtr ScriptCommands::CloseChunkPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Close_Chunk);
	}

	void ScriptCommands::CloseChunkPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Close_Chunk = reinterpret_cast<void(*)(::ScriptLoader&)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ClearRadarMarkersPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Clear_Radar_Markers);
	}

	void ScriptCommands::ClearRadarMarkersPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Clear_Radar_Markers = reinterpret_cast<void(*)()>(value.ToPointer());
	}

	IntPtr ScriptCommands::ClearRadarMarkerPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Clear_Radar_Marker);
	}

	void ScriptCommands::ClearRadarMarkerPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Clear_Radar_Marker = reinterpret_cast<void(*)(int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::AddRadarMarkerPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Add_Radar_Marker);
	}

	void ScriptCommands::AddRadarMarkerPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Add_Radar_Marker = reinterpret_cast<void(*)(int, const ::Vector3&, int, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetObjRadarBlipShapePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Obj_Radar_Blip_Shape);
	}

	void ScriptCommands::SetObjRadarBlipShapePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Obj_Radar_Blip_Shape = reinterpret_cast<void(*)(::ScriptableGameObj *, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetObjRadarBlipColorPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Obj_Radar_Blip_Color);
	}

	void ScriptCommands::SetObjRadarBlipColorPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Obj_Radar_Blip_Color = reinterpret_cast<void(*)(::ScriptableGameObj *, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::EnableRadarPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Enable_Radar);
	}

	void ScriptCommands::EnableRadarPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Enable_Radar = reinterpret_cast<void(*)(bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ClearMapCellPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Clear_Map_Cell);
	}

	void ScriptCommands::ClearMapCellPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Clear_Map_Cell = reinterpret_cast<void(*)(int, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ClearMapCellByPosPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Clear_Map_Cell_By_Pos);
	}

	void ScriptCommands::ClearMapCellByPosPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Clear_Map_Cell_By_Pos = reinterpret_cast<void(*)(const ::Vector3 &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ClearMapCellByPixelPosPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Clear_Map_Cell_By_Pixel_Pos);
	}

	void ScriptCommands::ClearMapCellByPixelPosPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Clear_Map_Cell_By_Pixel_Pos = reinterpret_cast<void(*)(int, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ClearMapRegionByPosPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Clear_Map_Region_By_Pos);
	}

	void ScriptCommands::ClearMapRegionByPosPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Clear_Map_Region_By_Pos = reinterpret_cast<void(*)(const ::Vector3 &, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::RevealMapPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Reveal_Map);
	}

	void ScriptCommands::RevealMapPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Reveal_Map = reinterpret_cast<void(*)()>(value.ToPointer());
	}

	IntPtr ScriptCommands::ShroudMapPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Shroud_Map);
	}

	void ScriptCommands::ShroudMapPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Shroud_Map = reinterpret_cast<void(*)()>(value.ToPointer());
	}

	IntPtr ScriptCommands::ShowPlayerMapMarkerPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Show_Player_Map_Marker);
	}

	void ScriptCommands::ShowPlayerMapMarkerPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Show_Player_Map_Marker = reinterpret_cast<void(*)(bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetSafeFlightHeightPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Safe_Flight_Height);
	}

	void ScriptCommands::GetSafeFlightHeightPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Safe_Flight_Height = reinterpret_cast<float(*)(float, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::CreateExplosionPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Create_Explosion);
	}

	void ScriptCommands::CreateExplosionPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Create_Explosion = reinterpret_cast<void(*)(const char *, const ::Vector3 &, ::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::CreateExplosionAtBonePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Create_Explosion_At_Bone);
	}

	void ScriptCommands::CreateExplosionAtBonePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Create_Explosion_At_Bone = reinterpret_cast<void(*)(const char *, ::ScriptableGameObj *, const char *, ::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::EnableHUDPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Enable_HUD);
	}

	void ScriptCommands::EnableHUDPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Enable_HUD = reinterpret_cast<void(*)(bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::MissionCompletePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Mission_Complete);
	}

	void ScriptCommands::MissionCompletePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Mission_Complete = reinterpret_cast<void(*)(bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GivePowerUpPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Give_PowerUp);
	}

	void ScriptCommands::GivePowerUpPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Give_PowerUp = reinterpret_cast<void(*)(::ScriptableGameObj *, const char *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::InnateDisablePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Innate_Disable);
	}

	void ScriptCommands::InnateDisablePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Innate_Disable = reinterpret_cast<void(*)(::ScriptableGameObj*)>(value.ToPointer());
	}

	IntPtr ScriptCommands::InnateEnablePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Innate_Enable);
	}

	void ScriptCommands::InnateEnablePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Innate_Enable = reinterpret_cast<void(*)(::ScriptableGameObj*)>(value.ToPointer());
	}

	IntPtr ScriptCommands::InnateSoldierEnableEnemySeenPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Innate_Soldier_Enable_Enemy_Seen);
	}

	void ScriptCommands::InnateSoldierEnableEnemySeenPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Innate_Soldier_Enable_Enemy_Seen = reinterpret_cast<bool(*)(::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::InnateSoldierEnableGunshotHeardPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Innate_Soldier_Enable_Gunshot_Heard);
	}

	void ScriptCommands::InnateSoldierEnableGunshotHeardPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Innate_Soldier_Enable_Gunshot_Heard = reinterpret_cast<bool(*)(::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::InnateSoldierEnableFootstepsHeardPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Innate_Soldier_Enable_Footsteps_Heard);
	}

	void ScriptCommands::InnateSoldierEnableFootstepsHeardPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Innate_Soldier_Enable_Footsteps_Heard = reinterpret_cast<bool(*)(::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::InnateSoldierEnableBulletHeardPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Innate_Soldier_Enable_Bullet_Heard);
	}

	void ScriptCommands::InnateSoldierEnableBulletHeardPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Innate_Soldier_Enable_Bullet_Heard = reinterpret_cast<bool(*)(::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::InnateSoldierEnableActionsPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Innate_Soldier_Enable_Actions);
	}

	void ScriptCommands::InnateSoldierEnableActionsPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Innate_Soldier_Enable_Actions = reinterpret_cast<bool(*)(::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetInnateSoldierHomeLocationPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Innate_Soldier_Home_Location);
	}

	void ScriptCommands::SetInnateSoldierHomeLocationPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Innate_Soldier_Home_Location = reinterpret_cast<void(*)(::ScriptableGameObj *, const ::Vector3&, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetInnateAggressivenessPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Innate_Aggressiveness);
	}

	void ScriptCommands::SetInnateAggressivenessPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Innate_Aggressiveness = reinterpret_cast<void(*)(::ScriptableGameObj *, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetInnateTakeCoverProbabilityPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Innate_Take_Cover_Probability);
	}

	void ScriptCommands::SetInnateTakeCoverProbabilityPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Innate_Take_Cover_Probability = reinterpret_cast<void(*)(::ScriptableGameObj *, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetInnateIsStationaryPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Innate_Is_Stationary);
	}

	void ScriptCommands::SetInnateIsStationaryPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Innate_Is_Stationary = reinterpret_cast<void(*)(::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::InnateForceStateBulletHeardPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Innate_Force_State_Bullet_Heard);
	}

	void ScriptCommands::InnateForceStateBulletHeardPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Innate_Force_State_Bullet_Heard = reinterpret_cast<void(*)(::ScriptableGameObj *, const ::Vector3 &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::InnateForceStateFootstepsHeardPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Innate_Force_State_Footsteps_Heard);
	}

	void ScriptCommands::InnateForceStateFootstepsHeardPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Innate_Force_State_Footsteps_Heard = reinterpret_cast<void(*)(::ScriptableGameObj *, const ::Vector3 &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::InnateForceStateGunshotsHeardPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Innate_Force_State_Gunshots_Heard);
	}

	void ScriptCommands::InnateForceStateGunshotsHeardPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Innate_Force_State_Gunshots_Heard = reinterpret_cast<void(*)(::ScriptableGameObj *, const ::Vector3 &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::InnateForceStateEnemySeenPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Innate_Force_State_Enemy_Seen);
	}

	void ScriptCommands::InnateForceStateEnemySeenPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Innate_Force_State_Enemy_Seen = reinterpret_cast<void(*)(::ScriptableGameObj *, ::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::StaticAnimPhysGotoFramePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Static_Anim_Phys_Goto_Frame);
	}

	void ScriptCommands::StaticAnimPhysGotoFramePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Static_Anim_Phys_Goto_Frame = reinterpret_cast<void(*)(int, float, const char *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::StaticAnimPhysGotoLastFramePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Static_Anim_Phys_Goto_Last_Frame);
	}

	void ScriptCommands::StaticAnimPhysGotoLastFramePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Static_Anim_Phys_Goto_Last_Frame = reinterpret_cast<void(*)(int, const char *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetSyncTimePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Sync_Time);
	}

	void ScriptCommands::GetSyncTimePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Sync_Time = reinterpret_cast<unsigned int(*)()>(value.ToPointer());
	}

	IntPtr ScriptCommands::AddObjectivePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Add_Objective);
	}

	void ScriptCommands::AddObjectivePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Add_Objective = reinterpret_cast<void(*)(int, int, int, int, char *, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::RemoveObjectivePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Remove_Objective);
	}

	void ScriptCommands::RemoveObjectivePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Remove_Objective = reinterpret_cast<void(*)(int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetObjectiveStatusPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Objective_Status);
	}

	void ScriptCommands::SetObjectiveStatusPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Objective_Status = reinterpret_cast<void(*)(int, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ChangeObjectiveTypePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Change_Objective_Type);
	}

	void ScriptCommands::ChangeObjectiveTypePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Change_Objective_Type = reinterpret_cast<void(*)(int, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetObjectiveRadarBlipPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Objective_Radar_Blip);
	}

	void ScriptCommands::SetObjectiveRadarBlipPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Objective_Radar_Blip = reinterpret_cast<void(*)(int, const ::Vector3 &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetObjectiveRadarBlipObjectPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Objective_Radar_Blip_Object);
	}

	void ScriptCommands::SetObjectiveRadarBlipObjectPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Objective_Radar_Blip_Object = reinterpret_cast<void(*)(int, ::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetObjectiveHUDInfoPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Objective_HUD_Info);
	}

	void ScriptCommands::SetObjectiveHUDInfoPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Objective_HUD_Info = reinterpret_cast<void(*)(int, float, const char *, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetObjectiveHUDInfoPositionPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Objective_HUD_Info_Position);
	}

	void ScriptCommands::SetObjectiveHUDInfoPositionPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Objective_HUD_Info_Position = reinterpret_cast<void(*)(int, float, const char *, int, const ::Vector3 &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ShakeCameraPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Shake_Camera);
	}

	void ScriptCommands::ShakeCameraPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Shake_Camera = reinterpret_cast<void(*)(const ::Vector3 &, float, float, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::EnableSpawnerPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Enable_Spawner);
	}

	void ScriptCommands::EnableSpawnerPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Enable_Spawner = reinterpret_cast<void(*)(int, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::TriggerSpawnerPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Trigger_Spawner);
	}

	void ScriptCommands::TriggerSpawnerPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Trigger_Spawner = reinterpret_cast<::ScriptableGameObj * (*)(int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::EnableEnginePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Enable_Engine);
	}

	void ScriptCommands::EnableEnginePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Enable_Engine = reinterpret_cast<void(*)(::ScriptableGameObj*, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetDifficultyLevelPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Difficulty_Level);
	}

	void ScriptCommands::GetDifficultyLevelPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Difficulty_Level = reinterpret_cast<int(*)()>(value.ToPointer());
	}

	IntPtr ScriptCommands::GrantKeyPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Grant_Key);
	}

	void ScriptCommands::GrantKeyPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Grant_Key = reinterpret_cast<void(*)(::ScriptableGameObj*, int, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::HasKeyPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Has_Key);
	}

	void ScriptCommands::HasKeyPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Has_Key = reinterpret_cast<bool(*)(::ScriptableGameObj*, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::EnableHibernationPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Enable_Hibernation);
	}

	void ScriptCommands::EnableHibernationPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Enable_Hibernation = reinterpret_cast<void(*)(::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::AttachToObjectBonePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Attach_To_Object_Bone);
	}

	void ScriptCommands::AttachToObjectBonePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Attach_To_Object_Bone = reinterpret_cast<void(*)(::ScriptableGameObj *, ::ScriptableGameObj *, const char *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::CreateConversationPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Create_Conversation);
	}

	void ScriptCommands::CreateConversationPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Create_Conversation = reinterpret_cast<int(*)(const char *, int, float, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::JoinConversationPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Join_Conversation);
	}

	void ScriptCommands::JoinConversationPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Join_Conversation = reinterpret_cast<void(*)(::ScriptableGameObj *, int, bool, bool, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::JoinConversationFacingPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Join_Conversation_Facing);
	}

	void ScriptCommands::JoinConversationFacingPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Join_Conversation_Facing = reinterpret_cast<void(*)(::ScriptableGameObj *, int, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::StartConversationPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Start_Conversation);
	}

	void ScriptCommands::StartConversationPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Start_Conversation = reinterpret_cast<void(*)(int, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::MonitorConversationPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Monitor_Conversation);
	}

	void ScriptCommands::MonitorConversationPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Monitor_Conversation = reinterpret_cast<void(*)(::ScriptableGameObj *, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::StartRandomConversationPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Start_Random_Conversation);
	}

	void ScriptCommands::StartRandomConversationPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Start_Random_Conversation = reinterpret_cast<void(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::StopConversationPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Stop_Conversation);
	}

	void ScriptCommands::StopConversationPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Stop_Conversation = reinterpret_cast<void(*)(int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::StopAllConversationsPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Stop_All_Conversations);
	}

	void ScriptCommands::StopAllConversationsPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Stop_All_Conversations = reinterpret_cast<void(*)()>(value.ToPointer());
	}

	IntPtr ScriptCommands::LockSoldierFacingPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Lock_Soldier_Facing);
	}

	void ScriptCommands::LockSoldierFacingPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Lock_Soldier_Facing = reinterpret_cast<void(*)(::ScriptableGameObj *, ::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::UnlockSoldierFacingPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Unlock_Soldier_Facing);
	}

	void ScriptCommands::UnlockSoldierFacingPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Unlock_Soldier_Facing = reinterpret_cast<void(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ApplyDamagePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Apply_Damage);
	}

	void ScriptCommands::ApplyDamagePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Apply_Damage = reinterpret_cast<void(*)(::ScriptableGameObj *, float, const char *, ::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetLoitersAllowedPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Loiters_Allowed);
	}

	void ScriptCommands::SetLoitersAllowedPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Loiters_Allowed = reinterpret_cast<void(*)(::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetIsVisiblePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Is_Visible);
	}

	void ScriptCommands::SetIsVisiblePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Is_Visible = reinterpret_cast<void(*)(::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetIsRenderedPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Is_Rendered);
	}

	void ScriptCommands::SetIsRenderedPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Is_Rendered = reinterpret_cast<void(*)(::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetPointsPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Points);
	}

	void ScriptCommands::GetPointsPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Points = reinterpret_cast<float(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GivePointsPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Give_Points);
	}

	void ScriptCommands::GivePointsPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Give_Points = reinterpret_cast<void(*)(::ScriptableGameObj *, float, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetMoneyPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Money);
	}

	void ScriptCommands::GetMoneyPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Money = reinterpret_cast<float(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GiveMoneyPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Give_Money);
	}

	void ScriptCommands::GiveMoneyPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Give_Money = reinterpret_cast<void(*)(::ScriptableGameObj *, float, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::GetBuildingPowerPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Get_Building_Power);
	}

	void ScriptCommands::GetBuildingPowerPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Get_Building_Power = reinterpret_cast<bool(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetBuildingPowerPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Building_Power);
	}

	void ScriptCommands::SetBuildingPowerPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Building_Power = reinterpret_cast<void(*)(::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::PlayBuildingAnnouncementPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Play_Building_Announcement);
	}

	void ScriptCommands::PlayBuildingAnnouncementPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Play_Building_Announcement = reinterpret_cast<void(*)(::ScriptableGameObj *, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::FindNearestBuildingToPosPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Find_Nearest_Building_To_Pos);
	}

	void ScriptCommands::FindNearestBuildingToPosPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Find_Nearest_Building_To_Pos = reinterpret_cast<::ScriptableGameObj * (*)(const ::Vector3 &, const char *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::FindNearestBuildingPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Find_Nearest_Building);
	}

	void ScriptCommands::FindNearestBuildingPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Find_Nearest_Building = reinterpret_cast<::ScriptableGameObj * (*)(::ScriptableGameObj *, const char *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::TeamMembersInZonePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Team_Members_In_Zone);
	}

	void ScriptCommands::TeamMembersInZonePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Team_Members_In_Zone = reinterpret_cast<int(*)(::ScriptableGameObj *, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetCloudsPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Clouds);
	}

	void ScriptCommands::SetCloudsPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Clouds = reinterpret_cast<void(*) (float, float, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetLightningPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Lightning);
	}

	void ScriptCommands::SetLightningPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Lightning = reinterpret_cast<void(*) (float, float, float, float, float, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetWarBlitzPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_War_Blitz);
	}

	void ScriptCommands::SetWarBlitzPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_War_Blitz = reinterpret_cast<void(*) (float, float, float, float, float, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetWindPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Wind);
	}

	void ScriptCommands::SetWindPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Wind = reinterpret_cast<void(*)(float, float, float, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetRainPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Rain);
	}

	void ScriptCommands::SetRainPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Rain = reinterpret_cast<void(*)(float, float, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetSnowPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Snow);
	}

	void ScriptCommands::SetSnowPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Snow = reinterpret_cast<void(*)(float, float, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetAshPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Ash);
	}

	void ScriptCommands::SetAshPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Ash = reinterpret_cast<void(*)(float, float, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetFogEnablePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Fog_Enable);
	}

	void ScriptCommands::SetFogEnablePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Fog_Enable = reinterpret_cast<void(*)(bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetFogRangePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Fog_Range);
	}

	void ScriptCommands::SetFogRangePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Fog_Range = reinterpret_cast<void(*)(float, float, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::EnableStealthPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Enable_Stealth);
	}

	void ScriptCommands::EnableStealthPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Enable_Stealth = reinterpret_cast<void(*)(::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::CinematicSniperControlPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Cinematic_Sniper_Control);
	}

	void ScriptCommands::CinematicSniperControlPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Cinematic_Sniper_Control = reinterpret_cast<void(*)(bool, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::TextFileOpenPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Text_File_Open);
	}

	void ScriptCommands::TextFileOpenPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Text_File_Open = reinterpret_cast<int(*)(const char *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::TextFileGetStringPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Text_File_Get_String);
	}

	void ScriptCommands::TextFileGetStringPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Text_File_Get_String = reinterpret_cast<bool(*)(int, char *, int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::TextFileClosePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Text_File_Close);
	}

	void ScriptCommands::TextFileClosePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Text_File_Close = reinterpret_cast<void(*)(int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::EnableVehicleTransitionsPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Enable_Vehicle_Transitions);
	}

	void ScriptCommands::EnableVehicleTransitionsPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Enable_Vehicle_Transitions = reinterpret_cast<void(*)(::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::DisplayGDIPlayerTerminalPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Display_GDI_Player_Terminal);
	}

	void ScriptCommands::DisplayGDIPlayerTerminalPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Display_GDI_Player_Terminal = reinterpret_cast<void(*)()>(value.ToPointer());
	}

	IntPtr ScriptCommands::DisplayNodPlayerTerminalPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Display_NOD_Player_Terminal);
	}

	void ScriptCommands::DisplayNodPlayerTerminalPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Display_NOD_Player_Terminal = reinterpret_cast<void(*)()>(value.ToPointer());
	}

	IntPtr ScriptCommands::DisplayMutantPlayerTerminalPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Display_Mutant_Player_Terminal);
	}

	void ScriptCommands::DisplayMutantPlayerTerminalPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Display_Mutant_Player_Terminal = reinterpret_cast<void(*)()>(value.ToPointer());
	}

	IntPtr ScriptCommands::RevealEncyclopediaCharacterPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Reveal_Encyclopedia_Character);
	}

	void ScriptCommands::RevealEncyclopediaCharacterPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Reveal_Encyclopedia_Character = reinterpret_cast<bool(*)(int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::RevealEncyclopediaWeaponPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Reveal_Encyclopedia_Weapon);
	}

	void ScriptCommands::RevealEncyclopediaWeaponPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Reveal_Encyclopedia_Weapon = reinterpret_cast<bool(*)(int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::RevealEncyclopediaVehiclePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Reveal_Encyclopedia_Vehicle);
	}

	void ScriptCommands::RevealEncyclopediaVehiclePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Reveal_Encyclopedia_Vehicle = reinterpret_cast<bool(*)(int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::RevealEncyclopediaBuildingPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Reveal_Encyclopedia_Building);
	}

	void ScriptCommands::RevealEncyclopediaBuildingPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Reveal_Encyclopedia_Building = reinterpret_cast<bool(*)(int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::DisplayEncyclopediaEventUIPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Display_Encyclopedia_Event_UI);
	}

	void ScriptCommands::DisplayEncyclopediaEventUIPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Display_Encyclopedia_Event_UI = reinterpret_cast<void(*)()>(value.ToPointer());
	}

	IntPtr ScriptCommands::ScaleAIAwarenessPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Scale_AI_Awareness);
	}

	void ScriptCommands::ScaleAIAwarenessPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Scale_AI_Awareness = reinterpret_cast<void(*)(float, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::EnableCinematicFreezePointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Enable_Cinematic_Freeze);
	}

	void ScriptCommands::EnableCinematicFreezePointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Enable_Cinematic_Freeze = reinterpret_cast<void(*)(::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ExpirePowerupPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Expire_Powerup);
	}

	void ScriptCommands::ExpirePowerupPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Expire_Powerup = reinterpret_cast<void(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetHUDHelpTextPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_HUD_Help_Text);
	}

	void ScriptCommands::SetHUDHelpTextPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_HUD_Help_Text = reinterpret_cast<void(*)(int, const ::Vector3 &)>(value.ToPointer());
	}

	IntPtr ScriptCommands::EnableHUDPokableIndicatorPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Enable_HUD_Pokable_Indicator);
	}

	void ScriptCommands::EnableHUDPokableIndicatorPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Enable_HUD_Pokable_Indicator = reinterpret_cast<void(*)(::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::EnableInnateConversationsPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Enable_Innate_Conversations);
	}

	void ScriptCommands::EnableInnateConversationsPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Enable_Innate_Conversations = reinterpret_cast<void(*)(::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::DisplayHealthBarPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Display_Health_Bar);
	}

	void ScriptCommands::DisplayHealthBarPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Display_Health_Bar = reinterpret_cast<void(*)(::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::EnableShadowPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Enable_Shadow);
	}

	void ScriptCommands::EnableShadowPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Enable_Shadow = reinterpret_cast<void(*)(::ScriptableGameObj *, bool)>(value.ToPointer());
	}

	IntPtr ScriptCommands::ClearWeaponsPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Clear_Weapons);
	}

	void ScriptCommands::ClearWeaponsPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Clear_Weapons = reinterpret_cast<void(*)(::ScriptableGameObj *)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetNumTertiaryObjectivesPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Num_Tertiary_Objectives);
	}

	void ScriptCommands::SetNumTertiaryObjectivesPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Num_Tertiary_Objectives = reinterpret_cast<void(*)(int)>(value.ToPointer());
	}

	IntPtr ScriptCommands::EnableLetterboxPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Enable_Letterbox);
	}

	void ScriptCommands::EnableLetterboxPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Enable_Letterbox = reinterpret_cast<void(*)(bool, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetScreenFadeColorPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Screen_Fade_Color);
	}

	void ScriptCommands::SetScreenFadeColorPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Screen_Fade_Color = reinterpret_cast<void(*)(float, float, float, float)>(value.ToPointer());
	}

	IntPtr ScriptCommands::SetScreenFadeOpacityPointer::get()
	{
		return IntPtr(InternalScriptCommandsPointer->Set_Screen_Fade_Opacity);
	}

	void ScriptCommands::SetScreenFadeOpacityPointer::set(IntPtr value)
	{
		InternalScriptCommandsPointer->Set_Screen_Fade_Opacity = reinterpret_cast<void(*)(float, float)>(value.ToPointer());
	}

	bool ScriptCommands::InternalDestroyPointer()
	{
		Imports::DestroyScriptCommands(InternalScriptCommandsPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::ScriptCommands *ScriptCommands::InternalScriptCommandsPointer::get()
	{
		return reinterpret_cast<::ScriptCommands *>(Pointer.ToPointer());
	}

	void Commands::DebugMessage(String ^format, ...array<Object ^> ^args)
	{
		Engine::Commands->DebugMessage(format, args);
	}

	void Commands::ActionReset(IScriptableGameObj ^obj, float priority)
	{
		Engine::Commands->ActionReset(obj, priority);
	}

	void Commands::ActionGoto(IScriptableGameObj ^obj, ActionParamsStruct ^params)
	{
		Engine::Commands->ActionGoto(obj, params);
	}

	void Commands::ActionGoto(IScriptableGameObj ^obj, IActionParamsStruct ^params)
	{
		Engine::Commands->ActionGoto(obj, params);
	}

	void Commands::ActionAttack(IScriptableGameObj ^obj, ActionParamsStruct ^params)
	{
		Engine::Commands->ActionAttack(obj, params);
	}

	void Commands::ActionAttack(IScriptableGameObj ^obj, IActionParamsStruct ^params)
	{
		Engine::Commands->ActionAttack(obj, params);
	}

	void Commands::ActionPlayAnimation(IScriptableGameObj ^obj, ActionParamsStruct ^params)
	{
		Engine::Commands->ActionPlayAnimation(obj, params);
	}

	void Commands::ActionPlayAnimation(IScriptableGameObj ^obj, IActionParamsStruct ^params)
	{
		Engine::Commands->ActionPlayAnimation(obj, params);
	}

	void Commands::ActionEnterExit(IScriptableGameObj ^obj, ActionParamsStruct ^params)
	{
		Engine::Commands->ActionEnterExit(obj, params);
	}

	void Commands::ActionEnterExit(IScriptableGameObj ^obj, IActionParamsStruct ^params)
	{
		Engine::Commands->ActionEnterExit(obj, params);
	}

	void Commands::ActionFaceLocation(IScriptableGameObj ^obj, ActionParamsStruct ^params)
	{
		Engine::Commands->ActionFaceLocation(obj, params);
	}

	void Commands::ActionFaceLocation(IScriptableGameObj ^obj, IActionParamsStruct ^params)
	{
		Engine::Commands->ActionFaceLocation(obj, params);
	}

	void Commands::ActionDock(IScriptableGameObj ^obj, ActionParamsStruct ^params)
	{
		Engine::Commands->ActionDock(obj, params);
	}

	void Commands::ActionDock(IScriptableGameObj ^obj, IActionParamsStruct ^params)
	{
		Engine::Commands->ActionDock(obj, params);
	}

	void Commands::ActionFollowInput(IScriptableGameObj ^obj, ActionParamsStruct ^params)
	{
		Engine::Commands->ActionFollowInput(obj, params);
	}

	void Commands::ActionFollowInput(IScriptableGameObj ^obj, IActionParamsStruct ^params)
	{
		Engine::Commands->ActionFollowInput(obj, params);
	}

	void Commands::ModifyAction(IScriptableGameObj ^obj, int actionID, ActionParamsStruct ^params, bool modifyMove, bool modifyAttack)
	{
		Engine::Commands->ModifyAction(obj, actionID, params, modifyMove, modifyAttack);
	}

	void Commands::ModifyAction(IScriptableGameObj ^obj, int actionID, IActionParamsStruct ^params, bool modifyMove, bool modifyAttack)
	{
		Engine::Commands->ModifyAction(obj, actionID, params, modifyMove, modifyAttack);
	}

	int Commands::GetActionID(IScriptableGameObj ^obj)
	{
		return Engine::Commands->GetActionID(obj);
	}

	bool Commands::GetActionParams(IScriptableGameObj ^obj, [Out] ActionParamsStruct ^%params)
	{
		return Engine::Commands->GetActionParams(obj, params);
	}

	bool Commands::GetActionParams(IScriptableGameObj ^obj, IActionParamsStruct ^params)
	{
		return Engine::Commands->GetActionParams(obj, params);
	}

	bool Commands::IsPerformingPathfindAction(IScriptableGameObj ^obj)
	{
		return Engine::Commands->IsPerformingPathfindAction(obj);
	}

	void Commands::SetPosition(IScriptableGameObj ^obj, Vector3 position)
	{
		Engine::Commands->SetPosition(obj, position);
	}

	Vector3 Commands::GetPosition(IScriptableGameObj ^obj)
	{
		return Engine::Commands->GetPosition(obj);
	}

	Vector3 Commands::GetBonePosition(IScriptableGameObj ^obj, String ^boneName)
	{
		return Engine::Commands->GetBonePosition(obj, boneName);
	}

	float Commands::GetFacing(IScriptableGameObj ^obj)
	{
		return Engine::Commands->GetFacing(obj);
	}

	void Commands::SetFacing(IScriptableGameObj ^obj, float degrees)
	{
		Engine::Commands->SetFacing(obj, degrees);
	}

	void Commands::DisableAllCollisions(IScriptableGameObj ^obj)
	{
		Engine::Commands->DisableAllCollisions(obj);
	}

	void Commands::DisablePhysicalCollisions(IScriptableGameObj ^obj)
	{
		Engine::Commands->DisablePhysicalCollisions(obj);
	}

	void Commands::EnableCollisions(IScriptableGameObj ^obj)
	{
		Engine::Commands->EnableCollisions(obj);
	}

	void Commands::DestroyObject(IScriptableGameObj ^obj)
	{
		Engine::Commands->DestroyObject(obj);
	}

	IScriptableGameObj ^Commands::FindObject(int objId)
	{
		return Engine::Commands->FindObject(objId);
	}

	IScriptableGameObj ^Commands::CreateObject(String ^typeName, Vector3 position)
	{
		return Engine::Commands->CreateObject(typeName, position);
	}

	IScriptableGameObj ^Commands::CreateObjectAtBone(IScriptableGameObj ^hostObj, String ^newObjTypeName, String ^boneName)
	{
		return Engine::Commands->CreateObjectAtBone(hostObj, newObjTypeName, boneName);
	}

	int Commands::GetID(IScriptableGameObj ^obj)
	{
		return Engine::Commands->GetID(obj);
	}

	int Commands::GetPresetID(IScriptableGameObj ^obj)
	{
		return Engine::Commands->GetPresetID(obj);
	}

	String ^Commands::GetPresetName(IScriptableGameObj ^obj)
	{
		return Engine::Commands->GetPresetName(obj);
	}

	void Commands::AttachScript(IScriptableGameObj ^object, String ^scriptName, String ^scriptParams, ...array<Object^>^ args)
	{
		Engine::Commands->AttachScript(object, scriptName, scriptParams, args);
	}

	void Commands::AddToDirtyCullList(IScriptableGameObj ^object)
	{
		Engine::Commands->AddToDirtyCullList(object);
	}

	void Commands::StartTimer(IScriptableGameObj ^obj, IScriptClass ^script, float duration, int timerId)
	{
		Engine::Commands->StartTimer(obj, script, duration, timerId);
	}

	void Commands::TriggerWeapon(IScriptableGameObj ^obj, bool trigger, Vector3 target, bool primary)
	{
		Engine::Commands->TriggerWeapon(obj, trigger, target, primary);
	}

	void Commands::SelectWeapon(IScriptableGameObj ^obj, String ^weaponName)
	{
		Engine::Commands->SelectWeapon(obj, weaponName);
	}

	void Commands::SendCustomEvent(IScriptableGameObj ^from, IScriptableGameObj ^to, int type, int param, float delay)
	{
		Engine::Commands->SendCustomEvent(from, to, type, param, delay);
	}

	void Commands::SendDamagedEvent(IScriptableGameObj ^object, IScriptableGameObj ^damager)
	{
		Engine::Commands->SendDamagedEvent(object, damager);
	}

	float Commands::GetRandom(float min, float max)
	{
		return Engine::Commands->GetRandom(min, max);
	}

	int Commands::GetRandomInt(int min, int max)
	{
		return Engine::Commands->GetRandomInt(min, max);
	}

	IScriptableGameObj ^Commands::FindRandomSimpleObject(String ^presetName)
	{
		return Engine::Commands->FindRandomSimpleObject(presetName);
	}

	void Commands::SetModel(IScriptableGameObj ^obj, String ^modelName)
	{
		Engine::Commands->SetModel(obj, modelName);
	}

	void Commands::SetAnimation(IScriptableGameObj ^obj, String ^animName, bool looping, String ^subObjName, float startFrame, float endFrame, bool isBlended)
	{
		Engine::Commands->SetAnimation(obj, animName, looping, subObjName, startFrame, endFrame, isBlended);
	}

	void Commands::SetAnimationFrame(IScriptableGameObj ^obj, String ^animName, int frame)
	{
		Engine::Commands->SetAnimationFrame(obj, animName, frame);
	}

	int Commands::CreateSound(String ^soundPresetName, Vector3 position, IScriptableGameObj ^creator)
	{
		return Engine::Commands->CreateSound(soundPresetName, position, creator);
	}

	int Commands::Create2DSound(String ^soundPresetName)
	{
		return Engine::Commands->Create2DSound(soundPresetName);
	}

	int Commands::Create2DWAVSound(String ^wavFilename)
	{
		return Engine::Commands->Create2DWAVSound(wavFilename);
	}

	int Commands::Create3DWAVSoundAtBone(String ^wavFilename, IScriptableGameObj ^obj, String ^boneName)
	{
		return Engine::Commands->Create3DWAVSoundAtBone(wavFilename, obj, boneName);
	}

	int Commands::Create3DSoundAtBone(String ^soundPresetName, IScriptableGameObj ^obj, String ^boneName)
	{
		return Engine::Commands->Create3DSoundAtBone(soundPresetName, obj, boneName);
	}

	int Commands::CreateLogicalSound(IScriptableGameObj ^creator, int type, Vector3 position, float radius)
	{
		return Engine::Commands->CreateLogicalSound(creator, type, position, radius);
	}

	void Commands::StartSound(int soundId)
	{
		Engine::Commands->StartSound(soundId);
	}

	void Commands::StopSound(int soundId, bool destroySound)
	{
		Engine::Commands->StopSound(soundId, destroySound);
	}

	void Commands::MonitorSound(IScriptableGameObj ^obj, int soundId)
	{
		Engine::Commands->MonitorSound(obj, soundId);
	}

	void Commands::SetBackgroundMusic(String ^wavFilename)
	{
		Engine::Commands->SetBackgroundMusic(wavFilename);
	}

	void Commands::FadeBackgroundMusic(String ^wavFilename, int fadeOutTime, int fadeInTime)
	{
		Engine::Commands->FadeBackgroundMusic(wavFilename, fadeOutTime, fadeInTime);
	}

	void Commands::StopBackgroundMusic()
	{
		Engine::Commands->StopBackgroundMusic();
	}

	float Commands::GetHealth(IScriptableGameObj ^obj)
	{
		return Engine::Commands->GetHealth(obj);
	}

	float Commands::GetMaxHealth(IScriptableGameObj ^obj)
	{
		return Engine::Commands->GetMaxHealth(obj);
	}

	void Commands::SetHealth(IScriptableGameObj ^obj, float health)
	{
		Engine::Commands->SetHealth(obj, health);
	}

	float Commands::GetShieldStrength(IScriptableGameObj ^obj)
	{
		return Engine::Commands->GetShieldStrength(obj);
	}

	float Commands::GetMaxShieldStrength(IScriptableGameObj ^obj)
	{
		return Engine::Commands->GetMaxShieldStrength(obj);
	}

	void Commands::SetShieldStrength(IScriptableGameObj ^obj, float strength)
	{
		Engine::Commands->SetShieldStrength(obj, strength);
	}

	void Commands::SetShieldType(IScriptableGameObj ^obj, String ^name)
	{
		Engine::Commands->SetShieldType(obj, name);
	}

	int Commands::GetPlayerType(IScriptableGameObj ^obj)
	{
		return Engine::Commands->GetPlayerType(obj);
	}

	void Commands::SetPlayerType(IScriptableGameObj ^obj, int type)
	{
		Engine::Commands->SetPlayerType(obj, type);
	}

	float Commands::GetDistance(Vector3 p1, Vector3 p2)
	{
		return Engine::Commands->GetDistance(p1, p2);
	}

	void Commands::SetCameraHost(IScriptableGameObj ^obj)
	{
		Engine::Commands->SetCameraHost(obj);
	}

	void Commands::ForceCameraLook(Vector3 target)
	{
		Engine::Commands->ForceCameraLook(target);
	}

	IScriptableGameObj ^Commands::GetTheStar()
	{
		return Engine::Commands->GetTheStar();
	}

	IScriptableGameObj ^Commands::GetAStar(Vector3 pos)
	{
		return Engine::Commands->GetAStar(pos);
	}

	IScriptableGameObj ^Commands::FindClosestSoldier(Vector3 pos, float minDist, float maxDist, bool onlyHuman)
	{
		return Engine::Commands->FindClosestSoldier(pos, minDist, maxDist, onlyHuman);
	}

	bool Commands::IsAStar(IScriptableGameObj ^obj)
	{
		return Engine::Commands->IsAStar(obj);
	}

	void Commands::ControlEnable(IScriptableGameObj ^obj, bool enable)
	{
		Engine::Commands->ControlEnable(obj, enable);
	}

	String ^Commands::GetDamageBoneName()
	{
		return Engine::Commands->GetDamageBoneName();
	}

	bool Commands::GetDamageBoneDirection()
	{
		return Engine::Commands->GetDamageBoneDirection();
	}

	bool Commands::IsObjectVisible(IScriptableGameObj ^looker, IScriptableGameObj ^obj)
	{
		return Engine::Commands->IsObjectVisible(looker, obj);
	}

	void Commands::EnableEnemySeen(IScriptableGameObj ^obj, bool enable)
	{
		Engine::Commands->EnableEnemySeen(obj, enable);
	}

	void Commands::SetDisplayColor(System::Drawing::Color color)
	{
		Engine::Commands->SetDisplayColor(color);
	}

	void Commands::DisplayText(int stringId)
	{
		Engine::Commands->DisplayText(stringId);
	}

	void Commands::DisplayFloat(float value, String ^format)
	{
		Engine::Commands->DisplayFloat(value, format);
	}

	void Commands::DisplayInt(int value, String ^format)
	{
		Engine::Commands->DisplayInt(value, format);
	}

	void Commands::SaveData(IntPtr saver, int id, array<std::uint8_t> ^data)
	{
		Engine::Commands->SaveData(saver, id, data);
	}

	void Commands::SavePointer(IntPtr saver, int id, IntPtr pointer)
	{
		Engine::Commands->SavePointer(saver, id, pointer);
	}

	bool Commands::LoadBegin(IntPtr loader, int %id)
	{
		return Engine::Commands->LoadBegin(loader, id);
	}

	void Commands::LoadData(IntPtr loader, array<std::uint8_t> ^data)
	{
		Engine::Commands->LoadData(loader, data);
	}

	void Commands::LoadPointer(IntPtr loader, IntPtr %pointer)
	{
		Engine::Commands->LoadPointer(loader, pointer);
	}

	void Commands::LoadEnd(IntPtr loader)
	{
		Engine::Commands->LoadEnd(loader);
	}

	void Commands::BeginChunk(IntPtr saver, unsigned int chunkID)
	{
		Engine::Commands->BeginChunk(saver, chunkID);
	}

	void Commands::EndChunk(IntPtr saver)
	{
		Engine::Commands->EndChunk(saver);
	}

	bool Commands::OpenChunk(IntPtr loader, unsigned int %chunkID)
	{
		return Engine::Commands->OpenChunk(loader, chunkID);
	}

	void Commands::CloseChunk(IntPtr loader)
	{
		Engine::Commands->CloseChunk(loader);
	}

	void Commands::ClearRadarMarkers()
	{
		Engine::Commands->ClearRadarMarkers();
	}

	void Commands::ClearRadarMarker(int id)
	{
		Engine::Commands->ClearRadarMarker(id);
	}

	void Commands::AddRadarMarker(int id, Vector3 position, int shapeType, int colorType)
	{
		Engine::Commands->AddRadarMarker(id, position, shapeType, colorType);
	}

	void Commands::SetObjRadarBlipShape(IScriptableGameObj ^obj, int shapeType)
	{
		Engine::Commands->SetObjRadarBlipShape(obj, shapeType);
	}

	void Commands::SetObjRadarBlipColor(IScriptableGameObj ^obj, int colorType)
	{
		Engine::Commands->SetObjRadarBlipColor(obj, colorType);
	}

	void Commands::EnableRadar(bool enable)
	{
		Engine::Commands->EnableRadar(enable);
	}

	void Commands::ClearMapCell(int cellX, int cellY)
	{
		Engine::Commands->ClearMapCell(cellX, cellY);
	}

	void Commands::ClearMapCellByPos(Vector3 worldSpacePos)
	{
		Engine::Commands->ClearMapCellByPos(worldSpacePos);
	}

	void Commands::ClearMapCellByPixelPos(int pixelPosX, int pixelPosY)
	{
		Engine::Commands->ClearMapCellByPixelPos(pixelPosX, pixelPosY);
	}

	void Commands::ClearMapRegionByPos(Vector3 worldSpacePos, int pixelRadius)
	{
		Engine::Commands->ClearMapRegionByPos(worldSpacePos, pixelRadius);
	}

	void Commands::RevealMap()
	{
		Engine::Commands->RevealMap();
	}

	void Commands::ShroudMap()
	{
		Engine::Commands->ShroudMap();
	}

	void Commands::ShowPlayerMapMarker(bool onoff)
	{
		Engine::Commands->ShowPlayerMapMarker(onoff);
	}

	float Commands::GetSafeFlightHeight(float xPos, float yPos)
	{
		return Engine::Commands->GetSafeFlightHeight(xPos, yPos);
	}

	void Commands::CreateExplosion(String ^explosionDefName, Vector3 pos, IScriptableGameObj ^creator)
	{
		Engine::Commands->CreateExplosion(explosionDefName, pos, creator);
	}

	void Commands::CreateExplosionAtBone(String ^explosionDefName, IScriptableGameObj ^object, String ^boneName, IScriptableGameObj ^creator)
	{
		Engine::Commands->CreateExplosionAtBone(explosionDefName, object, boneName, creator);
	}

	void Commands::EnableHUD(bool enable)
	{
		Engine::Commands->EnableHUD(enable);
	}

	void Commands::MissionComplete(bool success)
	{
		Engine::Commands->MissionComplete(success);
	}

	void Commands::GivePowerUp(IScriptableGameObj ^obj, String ^presetName, bool displayOnHUD)
	{
		Engine::Commands->GivePowerUp(obj, presetName, displayOnHUD);
	}

	void Commands::InnateDisable(IScriptableGameObj ^object)
	{
		Engine::Commands->InnateDisable(object);
	}

	void Commands::InnateEnable(IScriptableGameObj ^object)
	{
		Engine::Commands->InnateEnable(object);
	}

	bool Commands::InnateSoldierEnableEnemySeen(IScriptableGameObj ^obj, bool state)
	{
		return Engine::Commands->InnateSoldierEnableEnemySeen(obj, state);
	}

	bool Commands::InnateSoldierEnableGunshotHeard(IScriptableGameObj ^obj, bool state)
	{
		return Engine::Commands->InnateSoldierEnableGunshotHeard(obj, state);
	}

	bool Commands::InnateSoldierEnableFootstepsHeard(IScriptableGameObj ^obj, bool state)
	{
		return Engine::Commands->InnateSoldierEnableFootstepsHeard(obj, state);
	}

	bool Commands::InnateSoldierEnableBulletHeard(IScriptableGameObj ^obj, bool state)
	{
		return Engine::Commands->InnateSoldierEnableBulletHeard(obj, state);
	}

	bool Commands::InnateSoldierEnableActions(IScriptableGameObj ^obj, bool state)
	{
		return Engine::Commands->InnateSoldierEnableActions(obj, state);
	}

	void Commands::SetInnateSoldierHomeLocation(IScriptableGameObj ^obj, Vector3 homePos, float homeRadius)
	{
		Engine::Commands->SetInnateSoldierHomeLocation(obj, homePos, homeRadius);
	}

	void Commands::SetInnateAggressiveness(IScriptableGameObj ^obj, float aggressiveness)
	{
		Engine::Commands->SetInnateAggressiveness(obj, aggressiveness);
	}

	void Commands::SetInnateTakeCoverProbability(IScriptableGameObj ^obj, float probability)
	{
		Engine::Commands->SetInnateTakeCoverProbability(obj, probability);
	}

	void Commands::SetInnateIsStationary(IScriptableGameObj ^obj, bool stationary)
	{
		Engine::Commands->SetInnateIsStationary(obj, stationary);
	}

	void Commands::InnateForceStateBulletHeard(IScriptableGameObj ^obj, Vector3 pos)
	{
		Engine::Commands->InnateForceStateBulletHeard(obj, pos);
	}

	void Commands::InnateForceStateFootstepsHeard(IScriptableGameObj ^obj, Vector3 pos)
	{
		Engine::Commands->InnateForceStateFootstepsHeard(obj, pos);
	}

	void Commands::InnateForceStateGunshotsHeard(IScriptableGameObj ^obj, Vector3 pos)
	{
		Engine::Commands->InnateForceStateGunshotsHeard(obj, pos);
	}

	void Commands::InnateForceStateEnemySeen(IScriptableGameObj ^obj, IScriptableGameObj ^enemy)
	{
		Engine::Commands->InnateForceStateEnemySeen(obj, enemy);
	}

	void Commands::StaticAnimPhysGotoFrame(int objId, float frame, String ^animName)
	{
		Engine::Commands->StaticAnimPhysGotoFrame(objId, frame, animName);
	}

	void Commands::StaticAnimPhysGotoLastFrame(int objId, String ^animName)
	{
		Engine::Commands->StaticAnimPhysGotoLastFrame(objId, animName);
	}

	unsigned int Commands::GetSyncTime()
	{
		return Engine::Commands->GetSyncTime();
	}

	void Commands::AddObjective(int id, int type, int status, int shortDescriptionId, String ^descriptionSoundFilename, int longDescriptionId)
	{
		Engine::Commands->AddObjective(id, type, status, shortDescriptionId, descriptionSoundFilename, longDescriptionId);
	}

	void Commands::RemoveObjective(int id)
	{
		Engine::Commands->RemoveObjective(id);
	}

	void Commands::SetObjectiveStatus(int id, int status)
	{
		Engine::Commands->SetObjectiveStatus(id, status);
	}

	void Commands::ChangeObjectiveType(int id, int type)
	{
		Engine::Commands->ChangeObjectiveType(id, type);
	}

	void Commands::SetObjectiveRadarBlip(int id, Vector3 position)
	{
		Engine::Commands->SetObjectiveRadarBlip(id, position);
	}

	void Commands::SetObjectiveRadarBlipObject(int id, IScriptableGameObj ^unit)
	{
		Engine::Commands->SetObjectiveRadarBlipObject(id, unit);
	}

	void Commands::SetObjectiveHUDInfo(int id, float priority, String ^textureName, int messageId)
	{
		Engine::Commands->SetObjectiveHUDInfo(id, priority, textureName, messageId);
	}

	void Commands::SetObjectiveHUDInfoPosition(int id, float priority, String ^textureName, int messageId, Vector3 position)
	{
		Engine::Commands->SetObjectiveHUDInfoPosition(id, priority, textureName, messageId, position);
	}

	void Commands::ShakeCamera(Vector3 pos, float radius, float intensity, float duration)
	{
		Engine::Commands->ShakeCamera(pos, radius, intensity, duration);
	}

	void Commands::EnableSpawner(int id, bool enable)
	{
		Engine::Commands->EnableSpawner(id, enable);
	}

	IScriptableGameObj ^Commands::TriggerSpawner(int id)
	{
		return Engine::Commands->TriggerSpawner(id);
	}

	void Commands::EnableEngine(IScriptableGameObj ^object, bool onoff)
	{
		Engine::Commands->EnableEngine(object, onoff);
	}

	int Commands::GetDifficultyLevel()
	{
		return Engine::Commands->GetDifficultyLevel();
	}

	void Commands::GrantKey(IScriptableGameObj ^object, int key, bool grant)
	{
		Engine::Commands->GrantKey(object, key, grant);
	}

	bool Commands::HasKey(IScriptableGameObj ^object, int key)
	{
		return Engine::Commands->HasKey(object, key);
	}

	void Commands::EnableHibernation(IScriptableGameObj ^object, bool enable)
	{
		Engine::Commands->EnableHibernation(object, enable);
	}

	void Commands::AttachToObjectBone(IScriptableGameObj ^object, IScriptableGameObj ^hostObject, String ^boneName)
	{
		Engine::Commands->AttachToObjectBone(object, hostObject, boneName);
	}

	int Commands::CreateConversation(String ^conversationName, int priority, float maxDist, bool isInterruptable)
	{
		return Engine::Commands->CreateConversation(conversationName, priority, maxDist, isInterruptable);
	}

	void Commands::JoinConversation(IScriptableGameObj ^object, int activeConversationId, bool allowMove, bool allowHeadTurn, bool allowFace)
	{
		Engine::Commands->JoinConversation(object, activeConversationId, allowMove, allowHeadTurn, allowFace);
	}

	void Commands::JoinConversationFacing(IScriptableGameObj ^object, int activeConversationId, int objIdToFace)
	{
		Engine::Commands->JoinConversationFacing(object, activeConversationId, objIdToFace);
	}

	void Commands::StartConversation(int activeConversationId, int actionID)
	{
		Engine::Commands->StartConversation(activeConversationId, actionID);
	}

	void Commands::MonitorConversation(IScriptableGameObj ^object, int activeConversationId)
	{
		Engine::Commands->MonitorConversation(object, activeConversationId);
	}

	void Commands::StartRandomConversation(IScriptableGameObj ^object)
	{
		Engine::Commands->StartRandomConversation(object);
	}

	void Commands::StopConversation(int activeConversationId)
	{
		Engine::Commands->StopConversation(activeConversationId);
	}

	void Commands::StopAllConversations()
	{
		Engine::Commands->StopAllConversations();
	}

	void Commands::LockSoldierFacing(IScriptableGameObj ^object, IScriptableGameObj ^objectToFace, bool turnBody)
	{
		Engine::Commands->LockSoldierFacing(object, objectToFace, turnBody);
	}

	void Commands::UnlockSoldierFacing(IScriptableGameObj ^object)
	{
		Engine::Commands->UnlockSoldierFacing(object);
	}

	void Commands::ApplyDamage(IScriptableGameObj ^object, float amount, String ^warheadName, IScriptableGameObj ^damager)
	{
		Engine::Commands->ApplyDamage(object, amount, warheadName, damager);
	}

	void Commands::SetLoitersAllowed(IScriptableGameObj ^object, bool allowed)
	{
		Engine::Commands->SetLoitersAllowed(object, allowed);
	}

	void Commands::SetIsVisible(IScriptableGameObj ^object, bool visible)
	{
		Engine::Commands->SetIsVisible(object, visible);
	}

	void Commands::SetIsRendered(IScriptableGameObj ^object, bool rendered)
	{
		Engine::Commands->SetIsRendered(object, rendered);
	}

	float Commands::GetPoints(IScriptableGameObj ^object)
	{
		return Engine::Commands->GetPoints(object);
	}

	void Commands::GivePoints(IScriptableGameObj ^object, float points, bool entireTeam)
	{
		Engine::Commands->GivePoints(object, points, entireTeam);
	}

	float Commands::GetMoney(IScriptableGameObj ^object)
	{
		return Engine::Commands->GetMoney(object);
	}

	void Commands::GiveMoney(IScriptableGameObj ^object, float money, bool entireTeam)
	{
		Engine::Commands->GiveMoney(object, money, entireTeam);
	}

	bool Commands::GetBuildingPower(IScriptableGameObj ^object)
	{
		return Engine::Commands->GetBuildingPower(object);
	}

	void Commands::SetBuildingPower(IScriptableGameObj ^object, bool onoff)
	{
		Engine::Commands->SetBuildingPower(object, onoff);
	}

	void Commands::PlayBuildingAnnouncement(IScriptableGameObj ^object, int textId)
	{
		Engine::Commands->PlayBuildingAnnouncement(object, textId);
	}

	IScriptableGameObj ^Commands::FindNearestBuildingToPos(Vector3 position, String ^meshPrefix)
	{
		return Engine::Commands->FindNearestBuildingToPos(position, meshPrefix);
	}

	IScriptableGameObj ^Commands::FindNearestBuilding(IScriptableGameObj ^object, String ^meshPrefix)
	{
		return Engine::Commands->FindNearestBuilding(object, meshPrefix);
	}

	int Commands::TeamMembersInZone(IScriptableGameObj ^object, int playerType)
	{
		return Engine::Commands->TeamMembersInZone(object, playerType);
	}

	void Commands::SetClouds(float cloudCover, float cloudGloominess, float ramptime)
	{
		Engine::Commands->SetClouds(cloudCover, cloudGloominess, ramptime);
	}

	void Commands::SetLightning(float intensity, float startDistance, float endDistance, float heading, float distribution, float ramptime)
	{
		Engine::Commands->SetLightning(intensity, startDistance, endDistance, heading, distribution, ramptime);
	}

	void Commands::SetWarBlitz(float intensity, float startDistance, float endDistance, float heading, float distribution, float ramptime)
	{
		Engine::Commands->SetWarBlitz(intensity, startDistance, endDistance, heading, distribution, ramptime);
	}

	void Commands::SetWind(float heading, float speed, float variability, float ramptime)
	{
		Engine::Commands->SetWind(heading, speed, variability, ramptime);
	}

	void Commands::SetRain(float density, float ramptime, bool prime)
	{
		Engine::Commands->SetRain(density, ramptime, prime);
	}

	void Commands::SetSnow(float density, float ramptime, bool prime)
	{
		Engine::Commands->SetSnow(density, ramptime, prime);
	}

	void Commands::SetAsh(float density, float ramptime, bool prime)
	{
		Engine::Commands->SetAsh(density, ramptime, prime);
	}

	void Commands::SetFogEnable(bool enabled)
	{
		Engine::Commands->SetFogEnable(enabled);
	}

	void Commands::SetFogRange(float startDistance, float endDistance, float ramptime)
	{
		Engine::Commands->SetFogRange(startDistance, endDistance, ramptime);
	}

	void Commands::EnableStealth(IScriptableGameObj ^object, bool onoff)
	{
		Engine::Commands->EnableStealth(object, onoff);
	}

	void Commands::CinematicSniperControl(bool enabled, float zoom)
	{
		Engine::Commands->CinematicSniperControl(enabled, zoom);
	}

	int Commands::TextFileOpen(String ^filename)
	{
		return Engine::Commands->TextFileOpen(filename);
	}

	String ^Commands::TextFileGetString(int handle)
	{
		return Engine::Commands->TextFileGetString(handle);
	}

	void Commands::TextFileClose(int handle)
	{
		Engine::Commands->TextFileClose(handle);
	}

	void Commands::EnableVehicleTransitions(IScriptableGameObj ^object, bool enable)
	{
		Engine::Commands->EnableVehicleTransitions(object, enable);
	}

	void Commands::DisplayGDIPlayerTerminal()
	{
		Engine::Commands->DisplayGDIPlayerTerminal();
	}

	void Commands::DisplayNodPlayerTerminal()
	{
		Engine::Commands->DisplayNodPlayerTerminal();
	}

	void Commands::DisplayMutantPlayerTerminal()
	{
		Engine::Commands->DisplayMutantPlayerTerminal();
	}

	bool Commands::RevealEncyclopediaCharacter(int objectId)
	{
		return Engine::Commands->RevealEncyclopediaCharacter(objectId);
	}

	bool Commands::RevealEncyclopediaWeapon(int objectId)
	{
		return Engine::Commands->RevealEncyclopediaWeapon(objectId);
	}

	bool Commands::RevealEncyclopediaVehicle(int objectId)
	{
		return Engine::Commands->RevealEncyclopediaVehicle(objectId);
	}

	bool Commands::RevealEncyclopediaBuilding(int objectId)
	{
		return Engine::Commands->RevealEncyclopediaBuilding(objectId);
	}

	void Commands::DisplayEncyclopediaEventUI()
	{
		Engine::Commands->DisplayEncyclopediaEventUI();
	}

	void Commands::ScaleAIAwareness(float sightScale, float hearingScale)
	{
		Engine::Commands->ScaleAIAwareness(sightScale, hearingScale);
	}

	void Commands::EnableCinematicFreeze(IScriptableGameObj ^object, bool enable)
	{
		Engine::Commands->EnableCinematicFreeze(object, enable);
	}

	void Commands::ExpirePowerup(IScriptableGameObj ^object)
	{
		Engine::Commands->ExpirePowerup(object);
	}

	void Commands::SetHUDHelpText(int stringId, Color color)
	{
		Engine::Commands->SetHUDHelpText(stringId, color);
	}

	void Commands::EnableHUDPokableIndicator(IScriptableGameObj ^object, bool enable)
	{
		Engine::Commands->EnableHUDPokableIndicator(object, enable);
	}

	void Commands::EnableInnateConversations(IScriptableGameObj ^object, bool enable)
	{
		Engine::Commands->EnableInnateConversations(object, enable);
	}

	void Commands::DisplayHealthBar(IScriptableGameObj ^object, bool display)
	{
		Engine::Commands->DisplayHealthBar(object, display);
	}

	void Commands::EnableShadow(IScriptableGameObj ^object, bool enable)
	{
		Engine::Commands->EnableShadow(object, enable);
	}

	void Commands::ClearWeapons(IScriptableGameObj ^object)
	{
		Engine::Commands->ClearWeapons(object);
	}

	void Commands::SetNumTertiaryObjectives(int count)
	{
		Engine::Commands->SetNumTertiaryObjectives(count);
	}

	void Commands::EnableLetterbox(bool onoff, float seconds)
	{
		Engine::Commands->EnableLetterbox(onoff, seconds);
	}

	void Commands::SetScreenFadeColor(Color color, float seconds)
	{
		Engine::Commands->SetScreenFadeColor(color, seconds);
	}

	void Commands::SetScreenFadeOpacity(float opacity, float seconds)
	{
		Engine::Commands->SetScreenFadeOpacity(opacity, seconds);
	}

	int Commands::Size::get()
	{
		return Engine::Commands->Size;
	}

	void Commands::Size::set(int value)
	{
		Engine::Commands->Size = value;
	}

	int Commands::Version::get()
	{
		return Engine::Commands->Version;
	}

	void Commands::Version::set(int value)
	{
		Engine::Commands->Version = value;
	}

	IntPtr Commands::DebugMessagePointer::get()
	{
		return Engine::Commands->DebugMessagePointer;
	}

	void Commands::DebugMessagePointer::set(IntPtr value)
	{
		Engine::Commands->DebugMessagePointer = value;
	}

	IntPtr Commands::ActionResetPointer::get()
	{
		return Engine::Commands->ActionResetPointer;
	}

	void Commands::ActionResetPointer::set(IntPtr value)
	{
		Engine::Commands->ActionResetPointer = value;
	}

	IntPtr Commands::ActionGotoPointer::get()
	{
		return Engine::Commands->ActionGotoPointer;
	}

	void Commands::ActionGotoPointer::set(IntPtr value)
	{
		Engine::Commands->ActionGotoPointer = value;
	}

	IntPtr Commands::ActionAttackPointer::get()
	{
		return Engine::Commands->ActionAttackPointer;
	}

	void Commands::ActionAttackPointer::set(IntPtr value)
	{
		Engine::Commands->ActionAttackPointer = value;
	}

	IntPtr Commands::ActionPlayAnimationPointer::get()
	{
		return Engine::Commands->ActionPlayAnimationPointer;
	}

	void Commands::ActionPlayAnimationPointer::set(IntPtr value)
	{
		Engine::Commands->ActionPlayAnimationPointer = value;
	}

	IntPtr Commands::ActionEnterExitPointer::get()
	{
		return Engine::Commands->ActionEnterExitPointer;
	}

	void Commands::ActionEnterExitPointer::set(IntPtr value)
	{
		Engine::Commands->ActionEnterExitPointer = value;
	}

	IntPtr Commands::ActionFaceLocationPointer::get()
	{
		return Engine::Commands->ActionFaceLocationPointer;
	}

	void Commands::ActionFaceLocationPointer::set(IntPtr value)
	{
		Engine::Commands->ActionFaceLocationPointer = value;
	}

	IntPtr Commands::ActionDockPointer::get()
	{
		return Engine::Commands->ActionDockPointer;
	}

	void Commands::ActionDockPointer::set(IntPtr value)
	{
		Engine::Commands->ActionDockPointer = value;
	}

	IntPtr Commands::ActionFollowInputPointer::get()
	{
		return Engine::Commands->ActionFollowInputPointer;
	}

	void Commands::ActionFollowInputPointer::set(IntPtr value)
	{
		Engine::Commands->ActionFollowInputPointer = value;
	}

	IntPtr Commands::ModifyActionPointer::get()
	{
		return Engine::Commands->ModifyActionPointer;
	}

	void Commands::ModifyActionPointer::set(IntPtr value)
	{
		Engine::Commands->ModifyActionPointer = value;
	}

	IntPtr Commands::GetActionIDPointer::get()
	{
		return Engine::Commands->GetActionIDPointer;
	}

	void Commands::GetActionIDPointer::set(IntPtr value)
	{
		Engine::Commands->GetActionIDPointer = value;
	}

	IntPtr Commands::GetActionParamsPointer::get()
	{
		return Engine::Commands->GetActionParamsPointer;
	}

	void Commands::GetActionParamsPointer::set(IntPtr value)
	{
		Engine::Commands->GetActionParamsPointer = value;
	}

	IntPtr Commands::IsPerformingPathfindActionPointer::get()
	{
		return Engine::Commands->IsPerformingPathfindActionPointer;
	}

	void Commands::IsPerformingPathfindActionPointer::set(IntPtr value)
	{
		Engine::Commands->IsPerformingPathfindActionPointer = value;
	}

	IntPtr Commands::SetPositionPointer::get()
	{
		return Engine::Commands->SetPositionPointer;
	}

	void Commands::SetPositionPointer::set(IntPtr value)
	{
		Engine::Commands->SetPositionPointer = value;
	}

	IntPtr Commands::GetPositionPointer::get()
	{
		return Engine::Commands->GetPositionPointer;
	}

	void Commands::GetPositionPointer::set(IntPtr value)
	{
		Engine::Commands->GetPositionPointer = value;
	}

	IntPtr Commands::GetBonePositionPointer::get()
	{
		return Engine::Commands->GetBonePositionPointer;
	}

	void Commands::GetBonePositionPointer::set(IntPtr value)
	{
		Engine::Commands->GetBonePositionPointer = value;
	}

	IntPtr Commands::GetFacingPointer::get()
	{
		return Engine::Commands->GetFacingPointer;
	}

	void Commands::GetFacingPointer::set(IntPtr value)
	{
		Engine::Commands->GetFacingPointer = value;
	}

	IntPtr Commands::SetFacingPointer::get()
	{
		return Engine::Commands->SetFacingPointer;
	}

	void Commands::SetFacingPointer::set(IntPtr value)
	{
		Engine::Commands->SetFacingPointer = value;
	}

	IntPtr Commands::DisableAllCollisionsPointer::get()
	{
		return Engine::Commands->DisableAllCollisionsPointer;
	}

	void Commands::DisableAllCollisionsPointer::set(IntPtr value)
	{
		Engine::Commands->DisableAllCollisionsPointer = value;
	}

	IntPtr Commands::DisablePhysicalCollisionsPointer::get()
	{
		return Engine::Commands->DisablePhysicalCollisionsPointer;
	}

	void Commands::DisablePhysicalCollisionsPointer::set(IntPtr value)
	{
		Engine::Commands->DisablePhysicalCollisionsPointer = value;
	}

	IntPtr Commands::EnableCollisionsPointer::get()
	{
		return Engine::Commands->EnableCollisionsPointer;
	}

	void Commands::EnableCollisionsPointer::set(IntPtr value)
	{
		Engine::Commands->EnableCollisionsPointer = value;
	}

	IntPtr Commands::DestroyObjectPointer::get()
	{
		return Engine::Commands->DestroyObjectPointer;
	}

	void Commands::DestroyObjectPointer::set(IntPtr value)
	{
		Engine::Commands->DestroyObjectPointer = value;
	}

	IntPtr Commands::FindObjectPointer::get()
	{
		return Engine::Commands->FindObjectPointer;
	}

	void Commands::FindObjectPointer::set(IntPtr value)
	{
		Engine::Commands->FindObjectPointer = value;
	}

	IntPtr Commands::CreateObjectPointer::get()
	{
		return Engine::Commands->CreateObjectPointer;
	}

	void Commands::CreateObjectPointer::set(IntPtr value)
	{
		Engine::Commands->CreateObjectPointer = value;
	}

	IntPtr Commands::CreateObjectAtBonePointer::get()
	{
		return Engine::Commands->CreateObjectAtBonePointer;
	}

	void Commands::CreateObjectAtBonePointer::set(IntPtr value)
	{
		Engine::Commands->CreateObjectAtBonePointer = value;
	}

	IntPtr Commands::GetIDPointer::get()
	{
		return Engine::Commands->GetIDPointer;
	}

	void Commands::GetIDPointer::set(IntPtr value)
	{
		Engine::Commands->GetIDPointer = value;
	}

	IntPtr Commands::GetPresetIDPointer::get()
	{
		return Engine::Commands->GetPresetIDPointer;
	}

	void Commands::GetPresetIDPointer::set(IntPtr value)
	{
		Engine::Commands->GetPresetIDPointer = value;
	}

	IntPtr Commands::GetPresetNamePointer::get()
	{
		return Engine::Commands->GetPresetNamePointer;
	}

	void Commands::GetPresetNamePointer::set(IntPtr value)
	{
		Engine::Commands->GetPresetNamePointer = value;
	}

	IntPtr Commands::AttachScriptPointer::get()
	{
		return Engine::Commands->AttachScriptPointer;
	}

	void Commands::AttachScriptPointer::set(IntPtr value)
	{
		Engine::Commands->AttachScriptPointer = value;
	}

	IntPtr Commands::AddToDirtyCullListPointer::get()
	{
		return Engine::Commands->AddToDirtyCullListPointer;
	}

	void Commands::AddToDirtyCullListPointer::set(IntPtr value)
	{
		Engine::Commands->AddToDirtyCullListPointer = value;
	}

	IntPtr Commands::StartTimerPointer::get()
	{
		return Engine::Commands->StartTimerPointer;
	}

	void Commands::StartTimerPointer::set(IntPtr value)
	{
		Engine::Commands->StartTimerPointer = value;
	}

	IntPtr Commands::TriggerWeaponPointer::get()
	{
		return Engine::Commands->TriggerWeaponPointer;
	}

	void Commands::TriggerWeaponPointer::set(IntPtr value)
	{
		Engine::Commands->TriggerWeaponPointer = value;
	}

	IntPtr Commands::SelectWeaponPointer::get()
	{
		return Engine::Commands->SelectWeaponPointer;
	}

	void Commands::SelectWeaponPointer::set(IntPtr value)
	{
		Engine::Commands->SelectWeaponPointer = value;
	}

	IntPtr Commands::SendCustomEventPointer::get()
	{
		return Engine::Commands->SendCustomEventPointer;
	}

	void Commands::SendCustomEventPointer::set(IntPtr value)
	{
		Engine::Commands->SendCustomEventPointer = value;
	}

	IntPtr Commands::SendDamagedEventPointer::get()
	{
		return Engine::Commands->SendDamagedEventPointer;
	}

	void Commands::SendDamagedEventPointer::set(IntPtr value)
	{
		Engine::Commands->SendDamagedEventPointer = value;
	}

	IntPtr Commands::GetRandomPointer::get()
	{
		return Engine::Commands->GetRandomPointer;
	}

	void Commands::GetRandomPointer::set(IntPtr value)
	{
		Engine::Commands->GetRandomPointer = value;
	}

	IntPtr Commands::GetRandomIntPointer::get()
	{
		return Engine::Commands->GetRandomIntPointer;
	}

	void Commands::GetRandomIntPointer::set(IntPtr value)
	{
		Engine::Commands->GetRandomIntPointer = value;
	}

	IntPtr Commands::FindRandomSimpleObjectPointer::get()
	{
		return Engine::Commands->FindRandomSimpleObjectPointer;
	}

	void Commands::FindRandomSimpleObjectPointer::set(IntPtr value)
	{
		Engine::Commands->FindRandomSimpleObjectPointer = value;
	}

	IntPtr Commands::SetModelPointer::get()
	{
		return Engine::Commands->SetModelPointer;
	}

	void Commands::SetModelPointer::set(IntPtr value)
	{
		Engine::Commands->SetModelPointer = value;
	}

	IntPtr Commands::SetAnimationPointer::get()
	{
		return Engine::Commands->SetAnimationPointer;
	}

	void Commands::SetAnimationPointer::set(IntPtr value)
	{
		Engine::Commands->SetAnimationPointer = value;
	}

	IntPtr Commands::SetAnimationFramePointer::get()
	{
		return Engine::Commands->SetAnimationFramePointer;
	}

	void Commands::SetAnimationFramePointer::set(IntPtr value)
	{
		Engine::Commands->SetAnimationFramePointer = value;
	}

	IntPtr Commands::CreateSoundPointer::get()
	{
		return Engine::Commands->CreateSoundPointer;
	}

	void Commands::CreateSoundPointer::set(IntPtr value)
	{
		Engine::Commands->CreateSoundPointer = value;
	}

	IntPtr Commands::Create2DSoundPointer::get()
	{
		return Engine::Commands->Create2DSoundPointer;
	}

	void Commands::Create2DSoundPointer::set(IntPtr value)
	{
		Engine::Commands->Create2DSoundPointer = value;
	}

	IntPtr Commands::Create2DWAVSoundPointer::get()
	{
		return Engine::Commands->Create2DWAVSoundPointer;
	}

	void Commands::Create2DWAVSoundPointer::set(IntPtr value)
	{
		Engine::Commands->Create2DWAVSoundPointer = value;
	}

	IntPtr Commands::Create3DWAVSoundAtBonePointer::get()
	{
		return Engine::Commands->Create3DWAVSoundAtBonePointer;
	}

	void Commands::Create3DWAVSoundAtBonePointer::set(IntPtr value)
	{
		Engine::Commands->Create3DWAVSoundAtBonePointer = value;
	}

	IntPtr Commands::Create3DSoundAtBonePointer::get()
	{
		return Engine::Commands->Create3DSoundAtBonePointer;
	}

	void Commands::Create3DSoundAtBonePointer::set(IntPtr value)
	{
		Engine::Commands->Create3DSoundAtBonePointer = value;
	}

	IntPtr Commands::CreateLogicalSoundPointer::get()
	{
		return Engine::Commands->CreateLogicalSoundPointer;
	}

	void Commands::CreateLogicalSoundPointer::set(IntPtr value)
	{
		Engine::Commands->CreateLogicalSoundPointer = value;
	}

	IntPtr Commands::StartSoundPointer::get()
	{
		return Engine::Commands->StartSoundPointer;
	}

	void Commands::StartSoundPointer::set(IntPtr value)
	{
		Engine::Commands->StartSoundPointer = value;
	}

	IntPtr Commands::StopSoundPointer::get()
	{
		return Engine::Commands->StopSoundPointer;
	}

	void Commands::StopSoundPointer::set(IntPtr value)
	{
		Engine::Commands->StopSoundPointer = value;
	}

	IntPtr Commands::MonitorSoundPointer::get()
	{
		return Engine::Commands->MonitorSoundPointer;
	}

	void Commands::MonitorSoundPointer::set(IntPtr value)
	{
		Engine::Commands->MonitorSoundPointer = value;
	}

	IntPtr Commands::SetBackgroundMusicPointer::get()
	{
		return Engine::Commands->SetBackgroundMusicPointer;
	}

	void Commands::SetBackgroundMusicPointer::set(IntPtr value)
	{
		Engine::Commands->SetBackgroundMusicPointer = value;
	}

	IntPtr Commands::FadeBackgroundMusicPointer::get()
	{
		return Engine::Commands->FadeBackgroundMusicPointer;
	}

	void Commands::FadeBackgroundMusicPointer::set(IntPtr value)
	{
		Engine::Commands->FadeBackgroundMusicPointer = value;
	}

	IntPtr Commands::StopBackgroundMusicPointer::get()
	{
		return Engine::Commands->StopBackgroundMusicPointer;
	}

	void Commands::StopBackgroundMusicPointer::set(IntPtr value)
	{
		Engine::Commands->StopBackgroundMusicPointer = value;
	}

	IntPtr Commands::GetHealthPointer::get()
	{
		return Engine::Commands->GetHealthPointer;
	}

	void Commands::GetHealthPointer::set(IntPtr value)
	{
		Engine::Commands->GetHealthPointer = value;
	}

	IntPtr Commands::GetMaxHealthPointer::get()
	{
		return Engine::Commands->GetMaxHealthPointer;
	}

	void Commands::GetMaxHealthPointer::set(IntPtr value)
	{
		Engine::Commands->GetMaxHealthPointer = value;
	}

	IntPtr Commands::SetHealthPointer::get()
	{
		return Engine::Commands->SetHealthPointer;
	}

	void Commands::SetHealthPointer::set(IntPtr value)
	{
		Engine::Commands->SetHealthPointer = value;
	}

	IntPtr Commands::GetShieldStrengthPointer::get()
	{
		return Engine::Commands->GetShieldStrengthPointer;
	}

	void Commands::GetShieldStrengthPointer::set(IntPtr value)
	{
		Engine::Commands->GetShieldStrengthPointer = value;
	}

	IntPtr Commands::GetMaxShieldStrengthPointer::get()
	{
		return Engine::Commands->GetMaxShieldStrengthPointer;
	}

	void Commands::GetMaxShieldStrengthPointer::set(IntPtr value)
	{
		Engine::Commands->GetMaxShieldStrengthPointer = value;
	}

	IntPtr Commands::SetShieldStrengthPointer::get()
	{
		return Engine::Commands->SetShieldStrengthPointer;
	}

	void Commands::SetShieldStrengthPointer::set(IntPtr value)
	{
		Engine::Commands->SetShieldStrengthPointer = value;
	}

	IntPtr Commands::SetShieldTypePointer::get()
	{
		return Engine::Commands->SetShieldTypePointer;
	}

	void Commands::SetShieldTypePointer::set(IntPtr value)
	{
		Engine::Commands->SetShieldTypePointer = value;
	}

	IntPtr Commands::GetPlayerTypePointer::get()
	{
		return Engine::Commands->GetPlayerTypePointer;
	}

	void Commands::GetPlayerTypePointer::set(IntPtr value)
	{
		Engine::Commands->GetPlayerTypePointer = value;
	}

	IntPtr Commands::SetPlayerTypePointer::get()
	{
		return Engine::Commands->SetPlayerTypePointer;
	}

	void Commands::SetPlayerTypePointer::set(IntPtr value)
	{
		Engine::Commands->SetPlayerTypePointer = value;
	}

	IntPtr Commands::GetDistancePointer::get()
	{
		return Engine::Commands->GetDistancePointer;
	}

	void Commands::GetDistancePointer::set(IntPtr value)
	{
		Engine::Commands->GetDistancePointer = value;
	}

	IntPtr Commands::SetCameraHostPointer::get()
	{
		return Engine::Commands->SetCameraHostPointer;
	}

	void Commands::SetCameraHostPointer::set(IntPtr value)
	{
		Engine::Commands->SetCameraHostPointer = value;
	}

	IntPtr Commands::ForceCameraLookPointer::get()
	{
		return Engine::Commands->ForceCameraLookPointer;
	}

	void Commands::ForceCameraLookPointer::set(IntPtr value)
	{
		Engine::Commands->ForceCameraLookPointer = value;
	}

	IntPtr Commands::GetTheStarPointer::get()
	{
		return Engine::Commands->GetTheStarPointer;
	}

	void Commands::GetTheStarPointer::set(IntPtr value)
	{
		Engine::Commands->GetTheStarPointer = value;
	}

	IntPtr Commands::GetAStarPointer::get()
	{
		return Engine::Commands->GetAStarPointer;
	}

	void Commands::GetAStarPointer::set(IntPtr value)
	{
		Engine::Commands->GetAStarPointer = value;
	}

	IntPtr Commands::FindClosestSoldierPointer::get()
	{
		return Engine::Commands->FindClosestSoldierPointer;
	}

	void Commands::FindClosestSoldierPointer::set(IntPtr value)
	{
		Engine::Commands->FindClosestSoldierPointer = value;
	}

	IntPtr Commands::IsAStarPointer::get()
	{
		return Engine::Commands->IsAStarPointer;
	}

	void Commands::IsAStarPointer::set(IntPtr value)
	{
		Engine::Commands->IsAStarPointer = value;
	}


	IntPtr Commands::ControlEnablePointer::get()
	{
		return Engine::Commands->ControlEnablePointer;
	}

	void Commands::ControlEnablePointer::set(IntPtr value)
	{
		Engine::Commands->ControlEnablePointer = value;
	}

	IntPtr Commands::GetDamageBoneNamePointer::get()
	{
		return Engine::Commands->GetDamageBoneNamePointer;
	}

	void Commands::GetDamageBoneNamePointer::set(IntPtr value)
	{
		Engine::Commands->GetDamageBoneNamePointer = value;
	}

	IntPtr Commands::GetDamageBoneDirectionPointer::get()
	{
		return Engine::Commands->GetDamageBoneDirectionPointer;
	}

	void Commands::GetDamageBoneDirectionPointer::set(IntPtr value)
	{
		Engine::Commands->GetDamageBoneDirectionPointer = value;
	}

	IntPtr Commands::IsObjectVisiblePointer::get()
	{
		return Engine::Commands->IsObjectVisiblePointer;
	}

	void Commands::IsObjectVisiblePointer::set(IntPtr value)
	{
		Engine::Commands->IsObjectVisiblePointer = value;
	}

	IntPtr Commands::EnableEnemySeenPointer::get()
	{
		return Engine::Commands->EnableEnemySeenPointer;
	}

	void Commands::EnableEnemySeenPointer::set(IntPtr value)
	{
		Engine::Commands->EnableEnemySeenPointer = value;
	}

	IntPtr Commands::SetDisplayColorPointer::get()
	{
		return Engine::Commands->SetDisplayColorPointer;
	}

	void Commands::SetDisplayColorPointer::set(IntPtr value)
	{
		Engine::Commands->SetDisplayColorPointer = value;
	}

	IntPtr Commands::DisplayTextPointer::get()
	{
		return Engine::Commands->DisplayTextPointer;
	}

	void Commands::DisplayTextPointer::set(IntPtr value)
	{
		Engine::Commands->DisplayTextPointer = value;
	}

	IntPtr Commands::DisplayFloatPointer::get()
	{
		return Engine::Commands->DisplayFloatPointer;
	}

	void Commands::DisplayFloatPointer::set(IntPtr value)
	{
		Engine::Commands->DisplayFloatPointer = value;
	}

	IntPtr Commands::DisplayIntPointer::get()
	{
		return Engine::Commands->DisplayIntPointer;
	}

	void Commands::DisplayIntPointer::set(IntPtr value)
	{
		Engine::Commands->DisplayIntPointer = value;
	}

	IntPtr Commands::SaveDataPointer::get()
	{
		return Engine::Commands->SaveDataPointer;
	}

	void Commands::SaveDataPointer::set(IntPtr value)
	{
		Engine::Commands->SaveDataPointer = value;
	}

	IntPtr Commands::SavePointerPointer::get()
	{
		return Engine::Commands->SavePointerPointer;
	}

	void Commands::SavePointerPointer::set(IntPtr value)
	{
		Engine::Commands->SavePointerPointer = value;
	}

	IntPtr Commands::LoadBeginPointer::get()
	{
		return Engine::Commands->LoadBeginPointer;
	}

	void Commands::LoadBeginPointer::set(IntPtr value)
	{
		Engine::Commands->LoadBeginPointer = value;
	}

	IntPtr Commands::LoadDataPointer::get()
	{
		return Engine::Commands->LoadDataPointer;
	}

	void Commands::LoadDataPointer::set(IntPtr value)
	{
		Engine::Commands->LoadDataPointer = value;
	}

	IntPtr Commands::LoadPointerPointer::get()
	{
		return Engine::Commands->LoadPointerPointer;
	}

	void Commands::LoadPointerPointer::set(IntPtr value)
	{
		Engine::Commands->LoadPointerPointer = value;
	}

	IntPtr Commands::LoadEndPointer::get()
	{
		return Engine::Commands->LoadEndPointer;
	}

	void Commands::LoadEndPointer::set(IntPtr value)
	{
		Engine::Commands->LoadEndPointer = value;
	}

	IntPtr Commands::BeginChunkPointer::get()
	{
		return Engine::Commands->BeginChunkPointer;
	}

	void Commands::BeginChunkPointer::set(IntPtr value)
	{
		Engine::Commands->BeginChunkPointer = value;
	}

	IntPtr Commands::EndChunkPointer::get()
	{
		return Engine::Commands->EndChunkPointer;
	}

	void Commands::EndChunkPointer::set(IntPtr value)
	{
		Engine::Commands->EndChunkPointer = value;
	}

	IntPtr Commands::OpenChunkPointer::get()
	{
		return Engine::Commands->OpenChunkPointer;
	}

	void Commands::OpenChunkPointer::set(IntPtr value)
	{
		Engine::Commands->OpenChunkPointer = value;
	}

	IntPtr Commands::CloseChunkPointer::get()
	{
		return Engine::Commands->CloseChunkPointer;
	}

	void Commands::CloseChunkPointer::set(IntPtr value)
	{
		Engine::Commands->CloseChunkPointer = value;
	}

	IntPtr Commands::ClearRadarMarkersPointer::get()
	{
		return Engine::Commands->ClearRadarMarkersPointer;
	}

	void Commands::ClearRadarMarkersPointer::set(IntPtr value)
	{
		Engine::Commands->ClearRadarMarkersPointer = value;
	}

	IntPtr Commands::ClearRadarMarkerPointer::get()
	{
		return Engine::Commands->ClearRadarMarkerPointer;
	}

	void Commands::ClearRadarMarkerPointer::set(IntPtr value)
	{
		Engine::Commands->ClearRadarMarkerPointer = value;
	}

	IntPtr Commands::AddRadarMarkerPointer::get()
	{
		return Engine::Commands->AddRadarMarkerPointer;
	}

	void Commands::AddRadarMarkerPointer::set(IntPtr value)
	{
		Engine::Commands->AddRadarMarkerPointer = value;
	}

	IntPtr Commands::SetObjRadarBlipShapePointer::get()
	{
		return Engine::Commands->SetObjRadarBlipShapePointer;
	}

	void Commands::SetObjRadarBlipShapePointer::set(IntPtr value)
	{
		Engine::Commands->SetObjRadarBlipShapePointer = value;
	}

	IntPtr Commands::SetObjRadarBlipColorPointer::get()
	{
		return Engine::Commands->SetObjRadarBlipColorPointer;
	}

	void Commands::SetObjRadarBlipColorPointer::set(IntPtr value)
	{
		Engine::Commands->SetObjRadarBlipColorPointer = value;
	}

	IntPtr Commands::EnableRadarPointer::get()
	{
		return Engine::Commands->EnableRadarPointer;
	}

	void Commands::EnableRadarPointer::set(IntPtr value)
	{
		Engine::Commands->EnableRadarPointer = value;
	}

	IntPtr Commands::ClearMapCellPointer::get()
	{
		return Engine::Commands->ClearMapCellPointer;
	}

	void Commands::ClearMapCellPointer::set(IntPtr value)
	{
		Engine::Commands->ClearMapCellPointer = value;
	}

	IntPtr Commands::ClearMapCellByPosPointer::get()
	{
		return Engine::Commands->ClearMapCellByPosPointer;
	}

	void Commands::ClearMapCellByPosPointer::set(IntPtr value)
	{
		Engine::Commands->ClearMapCellByPosPointer = value;
	}

	IntPtr Commands::ClearMapCellByPixelPosPointer::get()
	{
		return Engine::Commands->ClearMapCellByPixelPosPointer;
	}

	void Commands::ClearMapCellByPixelPosPointer::set(IntPtr value)
	{
		Engine::Commands->ClearMapCellByPixelPosPointer = value;
	}

	IntPtr Commands::ClearMapRegionByPosPointer::get()
	{
		return Engine::Commands->ClearMapRegionByPosPointer;
	}

	void Commands::ClearMapRegionByPosPointer::set(IntPtr value)
	{
		Engine::Commands->ClearMapRegionByPosPointer = value;
	}

	IntPtr Commands::RevealMapPointer::get()
	{
		return Engine::Commands->RevealMapPointer;
	}

	void Commands::RevealMapPointer::set(IntPtr value)
	{
		Engine::Commands->RevealMapPointer = value;
	}

	IntPtr Commands::ShroudMapPointer::get()
	{
		return Engine::Commands->ShroudMapPointer;
	}

	void Commands::ShroudMapPointer::set(IntPtr value)
	{
		Engine::Commands->ShroudMapPointer = value;
	}

	IntPtr Commands::ShowPlayerMapMarkerPointer::get()
	{
		return Engine::Commands->ShowPlayerMapMarkerPointer;
	}

	void Commands::ShowPlayerMapMarkerPointer::set(IntPtr value)
	{
		Engine::Commands->ShowPlayerMapMarkerPointer = value;
	}

	IntPtr Commands::GetSafeFlightHeightPointer::get()
	{
		return Engine::Commands->GetSafeFlightHeightPointer;
	}

	void Commands::GetSafeFlightHeightPointer::set(IntPtr value)
	{
		Engine::Commands->GetSafeFlightHeightPointer = value;
	}

	IntPtr Commands::CreateExplosionPointer::get()
	{
		return Engine::Commands->CreateExplosionPointer;
	}

	void Commands::CreateExplosionPointer::set(IntPtr value)
	{
		Engine::Commands->CreateExplosionPointer = value;
	}

	IntPtr Commands::CreateExplosionAtBonePointer::get()
	{
		return Engine::Commands->CreateExplosionAtBonePointer;
	}

	void Commands::CreateExplosionAtBonePointer::set(IntPtr value)
	{
		Engine::Commands->CreateExplosionAtBonePointer = value;
	}

	IntPtr Commands::EnableHUDPointer::get()
	{
		return Engine::Commands->EnableHUDPointer;
	}

	void Commands::EnableHUDPointer::set(IntPtr value)
	{
		Engine::Commands->EnableHUDPointer = value;
	}

	IntPtr Commands::MissionCompletePointer::get()
	{
		return Engine::Commands->MissionCompletePointer;
	}

	void Commands::MissionCompletePointer::set(IntPtr value)
	{
		Engine::Commands->MissionCompletePointer = value;
	}

	IntPtr Commands::GivePowerUpPointer::get()
	{
		return Engine::Commands->GivePowerUpPointer;
	}

	void Commands::GivePowerUpPointer::set(IntPtr value)
	{
		Engine::Commands->GivePowerUpPointer = value;
	}

	IntPtr Commands::InnateDisablePointer::get()
	{
		return Engine::Commands->InnateDisablePointer;
	}

	void Commands::InnateDisablePointer::set(IntPtr value)
	{
		Engine::Commands->InnateDisablePointer = value;
	}

	IntPtr Commands::InnateEnablePointer::get()
	{
		return Engine::Commands->InnateEnablePointer;
	}

	void Commands::InnateEnablePointer::set(IntPtr value)
	{
		Engine::Commands->InnateEnablePointer = value;
	}

	IntPtr Commands::InnateSoldierEnableEnemySeenPointer::get()
	{
		return Engine::Commands->InnateSoldierEnableEnemySeenPointer;
	}

	void Commands::InnateSoldierEnableEnemySeenPointer::set(IntPtr value)
	{
		Engine::Commands->InnateSoldierEnableEnemySeenPointer = value;
	}

	IntPtr Commands::InnateSoldierEnableGunshotHeardPointer::get()
	{
		return Engine::Commands->InnateSoldierEnableGunshotHeardPointer;
	}

	void Commands::InnateSoldierEnableGunshotHeardPointer::set(IntPtr value)
	{
		Engine::Commands->InnateSoldierEnableGunshotHeardPointer = value;
	}

	IntPtr Commands::InnateSoldierEnableFootstepsHeardPointer::get()
	{
		return Engine::Commands->InnateSoldierEnableFootstepsHeardPointer;
	}

	void Commands::InnateSoldierEnableFootstepsHeardPointer::set(IntPtr value)
	{
		Engine::Commands->InnateSoldierEnableFootstepsHeardPointer = value;
	}

	IntPtr Commands::InnateSoldierEnableBulletHeardPointer::get()
	{
		return Engine::Commands->InnateSoldierEnableBulletHeardPointer;
	}

	void Commands::InnateSoldierEnableBulletHeardPointer::set(IntPtr value)
	{
		Engine::Commands->InnateSoldierEnableBulletHeardPointer = value;
	}

	IntPtr Commands::InnateSoldierEnableActionsPointer::get()
	{
		return Engine::Commands->InnateSoldierEnableActionsPointer;
	}

	void Commands::InnateSoldierEnableActionsPointer::set(IntPtr value)
	{
		Engine::Commands->InnateSoldierEnableActionsPointer = value;
	}

	IntPtr Commands::SetInnateSoldierHomeLocationPointer::get()
	{
		return Engine::Commands->SetInnateSoldierHomeLocationPointer;
	}

	void Commands::SetInnateSoldierHomeLocationPointer::set(IntPtr value)
	{
		Engine::Commands->SetInnateSoldierHomeLocationPointer = value;
	}

	IntPtr Commands::SetInnateAggressivenessPointer::get()
	{
		return Engine::Commands->SetInnateAggressivenessPointer;
	}

	void Commands::SetInnateAggressivenessPointer::set(IntPtr value)
	{
		Engine::Commands->SetInnateAggressivenessPointer = value;
	}

	IntPtr Commands::SetInnateTakeCoverProbabilityPointer::get()
	{
		return Engine::Commands->SetInnateTakeCoverProbabilityPointer;
	}

	void Commands::SetInnateTakeCoverProbabilityPointer::set(IntPtr value)
	{
		Engine::Commands->SetInnateTakeCoverProbabilityPointer = value;
	}

	IntPtr Commands::SetInnateIsStationaryPointer::get()
	{
		return Engine::Commands->SetInnateIsStationaryPointer;
	}

	void Commands::SetInnateIsStationaryPointer::set(IntPtr value)
	{
		Engine::Commands->SetInnateIsStationaryPointer = value;
	}

	IntPtr Commands::InnateForceStateBulletHeardPointer::get()
	{
		return Engine::Commands->InnateForceStateBulletHeardPointer;
	}

	void Commands::InnateForceStateBulletHeardPointer::set(IntPtr value)
	{
		Engine::Commands->InnateForceStateBulletHeardPointer = value;
	}

	IntPtr Commands::InnateForceStateFootstepsHeardPointer::get()
	{
		return Engine::Commands->InnateForceStateFootstepsHeardPointer;
	}

	void Commands::InnateForceStateFootstepsHeardPointer::set(IntPtr value)
	{
		Engine::Commands->InnateForceStateFootstepsHeardPointer = value;
	}

	IntPtr Commands::InnateForceStateGunshotsHeardPointer::get()
	{
		return Engine::Commands->InnateForceStateGunshotsHeardPointer;
	}

	void Commands::InnateForceStateGunshotsHeardPointer::set(IntPtr value)
	{
		Engine::Commands->InnateForceStateGunshotsHeardPointer = value;
	}

	IntPtr Commands::InnateForceStateEnemySeenPointer::get()
	{
		return Engine::Commands->InnateForceStateEnemySeenPointer;
	}

	void Commands::InnateForceStateEnemySeenPointer::set(IntPtr value)
	{
		Engine::Commands->InnateForceStateEnemySeenPointer = value;
	}

	IntPtr Commands::StaticAnimPhysGotoFramePointer::get()
	{
		return Engine::Commands->StaticAnimPhysGotoFramePointer;
	}

	void Commands::StaticAnimPhysGotoFramePointer::set(IntPtr value)
	{
		Engine::Commands->StaticAnimPhysGotoFramePointer = value;
	}

	IntPtr Commands::StaticAnimPhysGotoLastFramePointer::get()
	{
		return Engine::Commands->StaticAnimPhysGotoLastFramePointer;
	}

	void Commands::StaticAnimPhysGotoLastFramePointer::set(IntPtr value)
	{
		Engine::Commands->StaticAnimPhysGotoLastFramePointer = value;
	}

	IntPtr Commands::GetSyncTimePointer::get()
	{
		return Engine::Commands->GetSyncTimePointer;
	}

	void Commands::GetSyncTimePointer::set(IntPtr value)
	{
		Engine::Commands->GetSyncTimePointer = value;
	}

	IntPtr Commands::AddObjectivePointer::get()
	{
		return Engine::Commands->AddObjectivePointer;
	}

	void Commands::AddObjectivePointer::set(IntPtr value)
	{
		Engine::Commands->AddObjectivePointer = value;
	}

	IntPtr Commands::RemoveObjectivePointer::get()
	{
		return Engine::Commands->RemoveObjectivePointer;
	}

	void Commands::RemoveObjectivePointer::set(IntPtr value)
	{
		Engine::Commands->RemoveObjectivePointer = value;
	}

	IntPtr Commands::SetObjectiveStatusPointer::get()
	{
		return Engine::Commands->SetObjectiveStatusPointer;
	}

	void Commands::SetObjectiveStatusPointer::set(IntPtr value)
	{
		Engine::Commands->SetObjectiveStatusPointer = value;
	}

	IntPtr Commands::ChangeObjectiveTypePointer::get()
	{
		return Engine::Commands->ChangeObjectiveTypePointer;
	}

	void Commands::ChangeObjectiveTypePointer::set(IntPtr value)
	{
		Engine::Commands->ChangeObjectiveTypePointer = value;
	}

	IntPtr Commands::SetObjectiveRadarBlipPointer::get()
	{
		return Engine::Commands->SetObjectiveRadarBlipPointer;
	}

	void Commands::SetObjectiveRadarBlipPointer::set(IntPtr value)
	{
		Engine::Commands->SetObjectiveRadarBlipPointer = value;
	}

	IntPtr Commands::SetObjectiveRadarBlipObjectPointer::get()
	{
		return Engine::Commands->SetObjectiveRadarBlipObjectPointer;
	}

	void Commands::SetObjectiveRadarBlipObjectPointer::set(IntPtr value)
	{
		Engine::Commands->SetObjectiveRadarBlipObjectPointer = value;
	}

	IntPtr Commands::SetObjectiveHUDInfoPointer::get()
	{
		return Engine::Commands->SetObjectiveHUDInfoPointer;
	}

	void Commands::SetObjectiveHUDInfoPointer::set(IntPtr value)
	{
		Engine::Commands->SetObjectiveHUDInfoPointer = value;
	}

	IntPtr Commands::SetObjectiveHUDInfoPositionPointer::get()
	{
		return Engine::Commands->SetObjectiveHUDInfoPositionPointer;
	}

	void Commands::SetObjectiveHUDInfoPositionPointer::set(IntPtr value)
	{
		Engine::Commands->SetObjectiveHUDInfoPositionPointer = value;
	}

	IntPtr Commands::ShakeCameraPointer::get()
	{
		return Engine::Commands->ShakeCameraPointer;
	}

	void Commands::ShakeCameraPointer::set(IntPtr value)
	{
		Engine::Commands->ShakeCameraPointer = value;
	}

	IntPtr Commands::EnableSpawnerPointer::get()
	{
		return Engine::Commands->EnableSpawnerPointer;
	}

	void Commands::EnableSpawnerPointer::set(IntPtr value)
	{
		Engine::Commands->EnableSpawnerPointer = value;
	}

	IntPtr Commands::TriggerSpawnerPointer::get()
	{
		return Engine::Commands->TriggerSpawnerPointer;
	}

	void Commands::TriggerSpawnerPointer::set(IntPtr value)
	{
		Engine::Commands->TriggerSpawnerPointer = value;
	}

	IntPtr Commands::EnableEnginePointer::get()
	{
		return Engine::Commands->EnableEnginePointer;
	}

	void Commands::EnableEnginePointer::set(IntPtr value)
	{
		Engine::Commands->EnableEnginePointer = value;
	}

	IntPtr Commands::GetDifficultyLevelPointer::get()
	{
		return Engine::Commands->GetDifficultyLevelPointer;
	}

	void Commands::GetDifficultyLevelPointer::set(IntPtr value)
	{
		Engine::Commands->GetDifficultyLevelPointer = value;
	}

	IntPtr Commands::GrantKeyPointer::get()
	{
		return Engine::Commands->GrantKeyPointer;
	}

	void Commands::GrantKeyPointer::set(IntPtr value)
	{
		Engine::Commands->GrantKeyPointer = value;
	}

	IntPtr Commands::HasKeyPointer::get()
	{
		return Engine::Commands->HasKeyPointer;
	}

	void Commands::HasKeyPointer::set(IntPtr value)
	{
		Engine::Commands->HasKeyPointer = value;
	}

	IntPtr Commands::EnableHibernationPointer::get()
	{
		return Engine::Commands->EnableHibernationPointer;
	}

	void Commands::EnableHibernationPointer::set(IntPtr value)
	{
		Engine::Commands->EnableHibernationPointer = value;
	}

	IntPtr Commands::AttachToObjectBonePointer::get()
	{
		return Engine::Commands->AttachToObjectBonePointer;
	}

	void Commands::AttachToObjectBonePointer::set(IntPtr value)
	{
		Engine::Commands->AttachToObjectBonePointer = value;
	}

	IntPtr Commands::CreateConversationPointer::get()
	{
		return Engine::Commands->CreateConversationPointer;
	}

	void Commands::CreateConversationPointer::set(IntPtr value)
	{
		Engine::Commands->CreateConversationPointer = value;
	}

	IntPtr Commands::JoinConversationPointer::get()
	{
		return Engine::Commands->JoinConversationPointer;
	}

	void Commands::JoinConversationPointer::set(IntPtr value)
	{
		Engine::Commands->JoinConversationPointer = value;
	}

	IntPtr Commands::JoinConversationFacingPointer::get()
	{
		return Engine::Commands->JoinConversationFacingPointer;
	}

	void Commands::JoinConversationFacingPointer::set(IntPtr value)
	{
		Engine::Commands->JoinConversationFacingPointer = value;
	}

	IntPtr Commands::StartConversationPointer::get()
	{
		return Engine::Commands->StartConversationPointer;
	}

	void Commands::StartConversationPointer::set(IntPtr value)
	{
		Engine::Commands->StartConversationPointer = value;
	}

	IntPtr Commands::MonitorConversationPointer::get()
	{
		return Engine::Commands->MonitorConversationPointer;
	}

	void Commands::MonitorConversationPointer::set(IntPtr value)
	{
		Engine::Commands->MonitorConversationPointer = value;
	}

	IntPtr Commands::StartRandomConversationPointer::get()
	{
		return Engine::Commands->StartRandomConversationPointer;
	}

	void Commands::StartRandomConversationPointer::set(IntPtr value)
	{
		Engine::Commands->StartRandomConversationPointer = value;
	}

	IntPtr Commands::StopConversationPointer::get()
	{
		return Engine::Commands->StopConversationPointer;
	}

	void Commands::StopConversationPointer::set(IntPtr value)
	{
		Engine::Commands->StopConversationPointer = value;
	}

	IntPtr Commands::StopAllConversationsPointer::get()
	{
		return Engine::Commands->StopAllConversationsPointer;
	}

	void Commands::StopAllConversationsPointer::set(IntPtr value)
	{
		Engine::Commands->StopAllConversationsPointer = value;
	}

	IntPtr Commands::LockSoldierFacingPointer::get()
	{
		return Engine::Commands->LockSoldierFacingPointer;
	}

	void Commands::LockSoldierFacingPointer::set(IntPtr value)
	{
		Engine::Commands->LockSoldierFacingPointer = value;
	}

	IntPtr Commands::UnlockSoldierFacingPointer::get()
	{
		return Engine::Commands->UnlockSoldierFacingPointer;
	}

	void Commands::UnlockSoldierFacingPointer::set(IntPtr value)
	{
		Engine::Commands->UnlockSoldierFacingPointer = value;
	}

	IntPtr Commands::ApplyDamagePointer::get()
	{
		return Engine::Commands->ApplyDamagePointer;
	}

	void Commands::ApplyDamagePointer::set(IntPtr value)
	{
		Engine::Commands->ApplyDamagePointer = value;
	}

	IntPtr Commands::SetLoitersAllowedPointer::get()
	{
		return Engine::Commands->SetLoitersAllowedPointer;
	}

	void Commands::SetLoitersAllowedPointer::set(IntPtr value)
	{
		Engine::Commands->SetLoitersAllowedPointer = value;
	}

	IntPtr Commands::SetIsVisiblePointer::get()
	{
		return Engine::Commands->SetIsVisiblePointer;
	}

	void Commands::SetIsVisiblePointer::set(IntPtr value)
	{
		Engine::Commands->SetIsVisiblePointer = value;
	}

	IntPtr Commands::SetIsRenderedPointer::get()
	{
		return Engine::Commands->SetIsRenderedPointer;
	}

	void Commands::SetIsRenderedPointer::set(IntPtr value)
	{
		Engine::Commands->SetIsRenderedPointer = value;
	}

	IntPtr Commands::GetPointsPointer::get()
	{
		return Engine::Commands->GetPointsPointer;
	}

	void Commands::GetPointsPointer::set(IntPtr value)
	{
		Engine::Commands->GetPointsPointer = value;
	}

	IntPtr Commands::GivePointsPointer::get()
	{
		return Engine::Commands->GivePointsPointer;
	}

	void Commands::GivePointsPointer::set(IntPtr value)
	{
		Engine::Commands->GivePointsPointer = value;
	}

	IntPtr Commands::GetMoneyPointer::get()
	{
		return Engine::Commands->GetMoneyPointer;
	}

	void Commands::GetMoneyPointer::set(IntPtr value)
	{
		Engine::Commands->GetMoneyPointer = value;
	}

	IntPtr Commands::GiveMoneyPointer::get()
	{
		return Engine::Commands->GiveMoneyPointer;
	}

	void Commands::GiveMoneyPointer::set(IntPtr value)
	{
		Engine::Commands->GiveMoneyPointer = value;
	}

	IntPtr Commands::GetBuildingPowerPointer::get()
	{
		return Engine::Commands->GetBuildingPowerPointer;
	}

	void Commands::GetBuildingPowerPointer::set(IntPtr value)
	{
		Engine::Commands->GetBuildingPowerPointer = value;
	}

	IntPtr Commands::SetBuildingPowerPointer::get()
	{
		return Engine::Commands->SetBuildingPowerPointer;
	}

	void Commands::SetBuildingPowerPointer::set(IntPtr value)
	{
		Engine::Commands->SetBuildingPowerPointer = value;
	}

	IntPtr Commands::PlayBuildingAnnouncementPointer::get()
	{
		return Engine::Commands->PlayBuildingAnnouncementPointer;
	}

	void Commands::PlayBuildingAnnouncementPointer::set(IntPtr value)
	{
		Engine::Commands->PlayBuildingAnnouncementPointer = value;
	}

	IntPtr Commands::FindNearestBuildingToPosPointer::get()
	{
		return Engine::Commands->FindNearestBuildingToPosPointer;
	}

	void Commands::FindNearestBuildingToPosPointer::set(IntPtr value)
	{
		Engine::Commands->FindNearestBuildingToPosPointer = value;
	}

	IntPtr Commands::FindNearestBuildingPointer::get()
	{
		return Engine::Commands->FindNearestBuildingPointer;
	}

	void Commands::FindNearestBuildingPointer::set(IntPtr value)
	{
		Engine::Commands->FindNearestBuildingPointer = value;
	}

	IntPtr Commands::TeamMembersInZonePointer::get()
	{
		return Engine::Commands->TeamMembersInZonePointer;
	}

	void Commands::TeamMembersInZonePointer::set(IntPtr value)
	{
		Engine::Commands->TeamMembersInZonePointer = value;
	}

	IntPtr Commands::SetCloudsPointer::get()
	{
		return Engine::Commands->SetCloudsPointer;
	}

	void Commands::SetCloudsPointer::set(IntPtr value)
	{
		Engine::Commands->SetCloudsPointer = value;
	}

	IntPtr Commands::SetLightningPointer::get()
	{
		return Engine::Commands->SetLightningPointer;
	}

	void Commands::SetLightningPointer::set(IntPtr value)
	{
		Engine::Commands->SetLightningPointer = value;
	}

	IntPtr Commands::SetWarBlitzPointer::get()
	{
		return Engine::Commands->SetWarBlitzPointer;
	}

	void Commands::SetWarBlitzPointer::set(IntPtr value)
	{
		Engine::Commands->SetWarBlitzPointer = value;
	}

	IntPtr Commands::SetWindPointer::get()
	{
		return Engine::Commands->SetWindPointer;
	}

	void Commands::SetWindPointer::set(IntPtr value)
	{
		Engine::Commands->SetWindPointer = value;
	}

	IntPtr Commands::SetRainPointer::get()
	{
		return Engine::Commands->SetRainPointer;
	}

	void Commands::SetRainPointer::set(IntPtr value)
	{
		Engine::Commands->SetRainPointer = value;
	}

	IntPtr Commands::SetSnowPointer::get()
	{
		return Engine::Commands->SetSnowPointer;
	}

	void Commands::SetSnowPointer::set(IntPtr value)
	{
		Engine::Commands->SetSnowPointer = value;
	}

	IntPtr Commands::SetAshPointer::get()
	{
		return Engine::Commands->SetAshPointer;
	}

	void Commands::SetAshPointer::set(IntPtr value)
	{
		Engine::Commands->SetAshPointer = value;
	}

	IntPtr Commands::SetFogEnablePointer::get()
	{
		return Engine::Commands->SetFogEnablePointer;
	}

	void Commands::SetFogEnablePointer::set(IntPtr value)
	{
		Engine::Commands->SetFogEnablePointer = value;
	}

	IntPtr Commands::SetFogRangePointer::get()
	{
		return Engine::Commands->SetFogRangePointer;
	}

	void Commands::SetFogRangePointer::set(IntPtr value)
	{
		Engine::Commands->SetFogRangePointer = value;
	}

	IntPtr Commands::EnableStealthPointer::get()
	{
		return Engine::Commands->EnableStealthPointer;
	}

	void Commands::EnableStealthPointer::set(IntPtr value)
	{
		Engine::Commands->EnableStealthPointer = value;
	}

	IntPtr Commands::CinematicSniperControlPointer::get()
	{
		return Engine::Commands->CinematicSniperControlPointer;
	}

	void Commands::CinematicSniperControlPointer::set(IntPtr value)
	{
		Engine::Commands->CinematicSniperControlPointer = value;
	}

	IntPtr Commands::TextFileOpenPointer::get()
	{
		return Engine::Commands->TextFileOpenPointer;
	}

	void Commands::TextFileOpenPointer::set(IntPtr value)
	{
		Engine::Commands->TextFileOpenPointer = value;
	}

	IntPtr Commands::TextFileGetStringPointer::get()
	{
		return Engine::Commands->TextFileGetStringPointer;
	}

	void Commands::TextFileGetStringPointer::set(IntPtr value)
	{
		Engine::Commands->TextFileGetStringPointer = value;
	}

	IntPtr Commands::TextFileClosePointer::get()
	{
		return Engine::Commands->TextFileClosePointer;
	}

	void Commands::TextFileClosePointer::set(IntPtr value)
	{
		Engine::Commands->TextFileClosePointer = value;
	}

	IntPtr Commands::EnableVehicleTransitionsPointer::get()
	{
		return Engine::Commands->EnableVehicleTransitionsPointer;
	}

	void Commands::EnableVehicleTransitionsPointer::set(IntPtr value)
	{
		Engine::Commands->EnableVehicleTransitionsPointer = value;
	}

	IntPtr Commands::DisplayGDIPlayerTerminalPointer::get()
	{
		return Engine::Commands->DisplayGDIPlayerTerminalPointer;
	}

	void Commands::DisplayGDIPlayerTerminalPointer::set(IntPtr value)
	{
		Engine::Commands->DisplayGDIPlayerTerminalPointer = value;
	}

	IntPtr Commands::DisplayNodPlayerTerminalPointer::get()
	{
		return Engine::Commands->DisplayNodPlayerTerminalPointer;
	}

	void Commands::DisplayNodPlayerTerminalPointer::set(IntPtr value)
	{
		Engine::Commands->DisplayNodPlayerTerminalPointer = value;
	}

	IntPtr Commands::DisplayMutantPlayerTerminalPointer::get()
	{
		return Engine::Commands->DisplayMutantPlayerTerminalPointer;
	}

	void Commands::DisplayMutantPlayerTerminalPointer::set(IntPtr value)
	{
		Engine::Commands->DisplayMutantPlayerTerminalPointer = value;
	}

	IntPtr Commands::RevealEncyclopediaCharacterPointer::get()
	{
		return Engine::Commands->RevealEncyclopediaCharacterPointer;
	}

	void Commands::RevealEncyclopediaCharacterPointer::set(IntPtr value)
	{
		Engine::Commands->RevealEncyclopediaCharacterPointer = value;
	}

	IntPtr Commands::RevealEncyclopediaWeaponPointer::get()
	{
		return Engine::Commands->RevealEncyclopediaWeaponPointer;
	}

	void Commands::RevealEncyclopediaWeaponPointer::set(IntPtr value)
	{
		Engine::Commands->RevealEncyclopediaWeaponPointer = value;
	}

	IntPtr Commands::RevealEncyclopediaVehiclePointer::get()
	{
		return Engine::Commands->RevealEncyclopediaVehiclePointer;
	}

	void Commands::RevealEncyclopediaVehiclePointer::set(IntPtr value)
	{
		Engine::Commands->RevealEncyclopediaVehiclePointer = value;
	}

	IntPtr Commands::RevealEncyclopediaBuildingPointer::get()
	{
		return Engine::Commands->RevealEncyclopediaBuildingPointer;
	}

	void Commands::RevealEncyclopediaBuildingPointer::set(IntPtr value)
	{
		Engine::Commands->RevealEncyclopediaBuildingPointer = value;
	}

	IntPtr Commands::DisplayEncyclopediaEventUIPointer::get()
	{
		return Engine::Commands->DisplayEncyclopediaEventUIPointer;
	}

	void Commands::DisplayEncyclopediaEventUIPointer::set(IntPtr value)
	{
		Engine::Commands->DisplayEncyclopediaEventUIPointer = value;
	}

	IntPtr Commands::ScaleAIAwarenessPointer::get()
	{
		return Engine::Commands->ScaleAIAwarenessPointer;
	}

	void Commands::ScaleAIAwarenessPointer::set(IntPtr value)
	{
		Engine::Commands->ScaleAIAwarenessPointer = value;
	}

	IntPtr Commands::EnableCinematicFreezePointer::get()
	{
		return Engine::Commands->EnableCinematicFreezePointer;
	}

	void Commands::EnableCinematicFreezePointer::set(IntPtr value)
	{
		Engine::Commands->EnableCinematicFreezePointer = value;
	}

	IntPtr Commands::ExpirePowerupPointer::get()
	{
		return Engine::Commands->ExpirePowerupPointer;
	}

	void Commands::ExpirePowerupPointer::set(IntPtr value)
	{
		Engine::Commands->ExpirePowerupPointer = value;
	}

	IntPtr Commands::SetHUDHelpTextPointer::get()
	{
		return Engine::Commands->SetHUDHelpTextPointer;
	}

	void Commands::SetHUDHelpTextPointer::set(IntPtr value)
	{
		Engine::Commands->SetHUDHelpTextPointer = value;
	}

	IntPtr Commands::EnableHUDPokableIndicatorPointer::get()
	{
		return Engine::Commands->EnableHUDPokableIndicatorPointer;
	}

	void Commands::EnableHUDPokableIndicatorPointer::set(IntPtr value)
	{
		Engine::Commands->EnableHUDPokableIndicatorPointer = value;
	}

	IntPtr Commands::EnableInnateConversationsPointer::get()
	{
		return Engine::Commands->EnableInnateConversationsPointer;
	}

	void Commands::EnableInnateConversationsPointer::set(IntPtr value)
	{
		Engine::Commands->EnableInnateConversationsPointer = value;
	}

	IntPtr Commands::DisplayHealthBarPointer::get()
	{
		return Engine::Commands->DisplayHealthBarPointer;
	}

	void Commands::DisplayHealthBarPointer::set(IntPtr value)
	{
		Engine::Commands->DisplayHealthBarPointer = value;
	}

	IntPtr Commands::EnableShadowPointer::get()
	{
		return Engine::Commands->EnableShadowPointer;
	}

	void Commands::EnableShadowPointer::set(IntPtr value)
	{
		Engine::Commands->EnableShadowPointer = value;
	}

	IntPtr Commands::ClearWeaponsPointer::get()
	{
		return Engine::Commands->ClearWeaponsPointer;
	}

	void Commands::ClearWeaponsPointer::set(IntPtr value)
	{
		Engine::Commands->ClearWeaponsPointer = value;
	}

	IntPtr Commands::SetNumTertiaryObjectivesPointer::get()
	{
		return Engine::Commands->SetNumTertiaryObjectivesPointer;
	}

	void Commands::SetNumTertiaryObjectivesPointer::set(IntPtr value)
	{
		Engine::Commands->SetNumTertiaryObjectivesPointer = value;
	}

	IntPtr Commands::EnableLetterboxPointer::get()
	{
		return Engine::Commands->EnableLetterboxPointer;
	}

	void Commands::EnableLetterboxPointer::set(IntPtr value)
	{
		Engine::Commands->EnableLetterboxPointer = value;
	}

	IntPtr Commands::SetScreenFadeColorPointer::get()
	{
		return Engine::Commands->SetScreenFadeColorPointer;
	}

	void Commands::SetScreenFadeColorPointer::set(IntPtr value)
	{
		Engine::Commands->SetScreenFadeColorPointer = value;
	}

	IntPtr Commands::SetScreenFadeOpacityPointer::get()
	{
		return Engine::Commands->SetScreenFadeOpacityPointer;
	}

	void Commands::SetScreenFadeOpacityPointer::set(IntPtr value)
	{
		Engine::Commands->SetScreenFadeOpacityPointer = value;
	}

	ScriptCommandsClass::ScriptCommandsClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateScriptCommandsClass()))
	{

	}

	ScriptCommandsClass::ScriptCommandsClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IScriptCommandsClass ^> ^ScriptCommandsClass::CreateScriptCommandsClass()
	{
		return gcnew UnmanagedContainer<IScriptCommandsClass ^>(gcnew ScriptCommandsClass());
	}

	bool ScriptCommandsClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IScriptCommandsClass ^otherThis = dynamic_cast<IScriptCommandsClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return ScriptCommandsClassPointer.Equals(otherThis->ScriptCommandsClassPointer);
	}

	IntPtr ScriptCommandsClass::ScriptCommandsClassPointer::get()
	{
		return IntPtr(InternalScriptCommandsClassPointer);
	}

	IScriptCommands ^ScriptCommandsClass::Commands::get()
	{
		auto result = InternalScriptCommandsClassPointer->Commands;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptCommands(IntPtr(result));
		}
	}

	void ScriptCommandsClass::Commands::set(IScriptCommands ^value)
	{
		if (value == nullptr || value->ScriptCommandsPointer.ToPointer() == nullptr)
		{
			InternalScriptCommandsClassPointer->Commands = nullptr;
		}
		else
		{
			InternalScriptCommandsClassPointer->Commands = reinterpret_cast<::ScriptCommands *>(value->ScriptCommandsPointer.ToPointer());
		}
	}

	bool ScriptCommandsClass::InternalDestroyPointer()
	{
		Imports::DestroyScriptCommandsClass(InternalScriptCommandsClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::ScriptCommandsClass *ScriptCommandsClass::InternalScriptCommandsClassPointer::get()
	{
		return reinterpret_cast<::ScriptCommandsClass *>(Pointer.ToPointer());
	}
}