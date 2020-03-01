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
#include "MSpawnerClass.h"

#include "MSpawnerDefClass.h"
#include "MMatrix3DDynamicVectorClass.h"
#include "MStringClassDynamicVectorClass.h"
#include "MReferencerClass.h"
#include "MMatrix3D.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <SpawnerClass.h>
#include <SpawnerDefClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	SpawnerClass::SpawnerClass(IntPtr pointer)
		: PersistClass(pointer)
	{

	}

	IntPtr SpawnerClass::SpawnerClassPointer::get()
	{
		return IntPtr(InternalSpawnerClassPointer);
	}

	sint32 SpawnerClass::Id::get()
	{
		return InternalSpawnerClassPointer->id;
	}

	void SpawnerClass::Id::set(sint32 value)
	{
		InternalSpawnerClassPointer->id = value;
	}

	Matrix3D SpawnerClass::Transform::get()
	{
		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(InternalSpawnerClassPointer->transform, result);

		return result;
	}

	void SpawnerClass::Transform::set(Matrix3D value)
	{
		Matrix3D::ManagedToUnmanagedMatrix3D(value, InternalSpawnerClassPointer->transform);
	}

	Matrix3D SpawnerClass::SpawnEffectTransform::get()
	{
		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(InternalSpawnerClassPointer->spawnEffectTransform, result);

		return result;
	}

	void SpawnerClass::SpawnEffectTransform::set(Matrix3D value)
	{
		Matrix3D::ManagedToUnmanagedMatrix3D(value, InternalSpawnerClassPointer->spawnEffectTransform);
	}

	ISpawnerDefClass^ SpawnerClass::Definition::get()
	{
		auto defPtr = InternalSpawnerClassPointer->definition;
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<ISpawnerDefClass^>(DefinitionClass::CreateDefinitionClassWrapper(defPtr));
		}
	}

	void SpawnerClass::Definition::set(ISpawnerDefClass^ value)
	{
		if (value == nullptr || value->SpawnerDefClassPointer.ToPointer() == nullptr)
		{
			InternalSpawnerClassPointer->definition = nullptr;
		}
		else
		{
			InternalSpawnerClassPointer->definition = reinterpret_cast<::SpawnerDefClass*>(value->SpawnerDefClassPointer.ToPointer());
		}
	}

	IReferencerClass^ SpawnerClass::CurrentObject::get()
	{
		return gcnew ReferencerClass(IntPtr(&InternalSpawnerClassPointer->currentObject));
	}

	void SpawnerClass::CurrentObject::set(IReferencerClass^ value)
	{
		if (value == nullptr || value->ReferencerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		
		InternalSpawnerClassPointer->currentObject = *reinterpret_cast<::ReferencerClass*>(value->ReferencerClassPointer.ToPointer());
	}

	bool SpawnerClass::Enabled::get()
	{
		return InternalSpawnerClassPointer->enabled;
	}

	void SpawnerClass::Enabled::set(bool value)
	{
		InternalSpawnerClassPointer->enabled = value;
	}

	sint32 SpawnerClass::SpawnCount::get()
	{
		return InternalSpawnerClassPointer->spawnCount;
	}

	void SpawnerClass::SpawnCount::set(sint32 value)
	{
		InternalSpawnerClassPointer->spawnCount = value;
	}

	float SpawnerClass::SpawnTimeRemaining::get()
	{
		return InternalSpawnerClassPointer->spawnTimeRemaining;
	}

	void SpawnerClass::SpawnTimeRemaining::set(float value)
	{
		InternalSpawnerClassPointer->spawnTimeRemaining = value;
	}

	IDynamicVectorClass<Matrix3D>^ SpawnerClass::AlternateTransform::get()
	{
		return gcnew Matrix3DDynamicVectorClass(IntPtr(&InternalSpawnerClassPointer->alternateTransforms));
	}
	
	void SpawnerClass::AlternateTransform::set(IDynamicVectorClass<Matrix3D>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalSpawnerClassPointer->alternateTransforms = *reinterpret_cast<::DynamicVectorClass<::Matrix3D>*>(value->Pointer.ToPointer());
	}

	IDynamicVectorClass<String^>^ SpawnerClass::ScriptNames::get()
	{
		return gcnew StringClassDynamicVectorClass(IntPtr(&InternalSpawnerClassPointer->scriptNames));
	}

	void SpawnerClass::ScriptNames::set(IDynamicVectorClass<String^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalSpawnerClassPointer->scriptNames = *reinterpret_cast<::DynamicVectorClass<::StringClass>*>(value->Pointer.ToPointer());
	}

	IDynamicVectorClass<String^>^ SpawnerClass::ScriptParameters::get()
	{
		return gcnew StringClassDynamicVectorClass(IntPtr(&InternalSpawnerClassPointer->scriptParameters));
	}

	void SpawnerClass::ScriptParameters::set(IDynamicVectorClass<String^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalSpawnerClassPointer->scriptParameters = *reinterpret_cast<::DynamicVectorClass<::StringClass>*>(value->Pointer.ToPointer());
	}

	::PersistClass* SpawnerClass::InternalPersistClassPointer::get()
	{
		return InternalSpawnerClassPointer;
	}

	::SpawnerClass* SpawnerClass::InternalSpawnerClassPointer::get()
	{
		return reinterpret_cast<::SpawnerClass*>(Pointer.ToPointer());
	}
}