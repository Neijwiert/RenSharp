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
#include "MCollideableObjClassDynamicVectorClass.h"

#include "Imports.h"
#include "MAnimCollisionManagerClass.h"

namespace RenSharp
{

#pragma managed(push, off)

	class AnimCollisionManagerHelper : public ::AnimCollisionManagerClass
	{
		public:
			class CollideableObjClassDynamicVectorClassHelper : public ::DynamicVectorClass<::AnimCollisionManagerClass::CollideableObjClass>
			{
				private:
					CollideableObjClassDynamicVectorClassHelper() = default;

				public:
					void *GetVector()
					{
						return Vector;
					}

					void SetVector(void *value)
					{
						Vector = reinterpret_cast<::AnimCollisionManagerClass::CollideableObjClass *>(value);
					}

					int &GetVectorMax()
					{
						return VectorMax;
					}

					bool &GetIsValid()
					{
						return IsValid;
					}

					bool &GetIsAllocated()
					{
						return IsAllocated;
					}

					int &GetActiveCount()
					{
						return ActiveCount;
					}
			};

		private:
			AnimCollisionManagerHelper(::PhysClass &parent)
				: ::AnimCollisionManagerClass(parent)
			{

			}

		public:
			static void CollisionMeshesClear(void *ptr)
			{
				auto castPtr = reinterpret_cast<::DynamicVectorClass<::AnimCollisionManagerClass::CollideableObjClass> *>(ptr);

				castPtr->Clear();
			}

			static void CollisionMeshesResetActive(void *ptr)
			{
				auto castPtr = reinterpret_cast<::DynamicVectorClass<::AnimCollisionManagerClass::CollideableObjClass> *>(ptr);

				castPtr->Reset_Active();
			}

			static void *CollisionMeshesIndexOperator(void *ptr, int index)
			{
				auto castPtr = reinterpret_cast<::DynamicVectorClass<::AnimCollisionManagerClass::CollideableObjClass> *>(ptr);

				return &castPtr->operator[](index);
			}

			static int CollisionMeshesGetLength(void *ptr)
			{
				auto castPtr = reinterpret_cast<::DynamicVectorClass<::AnimCollisionManagerClass::CollideableObjClass> *>(ptr);

				return castPtr->Length();
			}

			static int CollisionMeshesGetCount(void *ptr)
			{
				auto castPtr = reinterpret_cast<::DynamicVectorClass<::AnimCollisionManagerClass::CollideableObjClass> *>(ptr);

				return castPtr->Count();
			}

			static void CollisionMeshesSetCount(void *ptr, int value)
			{
				auto castPtr = reinterpret_cast<::DynamicVectorClass<::AnimCollisionManagerClass::CollideableObjClass> *>(ptr);

				castPtr->Set_Active(value);
			}

			static int CollisionMeshesGetGrowthStep(void *ptr)
			{
				auto castPtr = reinterpret_cast<::DynamicVectorClass<::AnimCollisionManagerClass::CollideableObjClass> *>(ptr);

				return castPtr->Growth_Step();
			}

			static void CollisionMeshesSetGrowthStep(void *ptr, int value)
			{
				auto castPtr = reinterpret_cast<::DynamicVectorClass<::AnimCollisionManagerClass::CollideableObjClass> *>(ptr);

				castPtr->Set_Growth_Step(value);
			}
	};

#pragma managed(pop)

	CollideableObjClassDynamicVectorClass::CollideableObjClassDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<ICollideableObjClass ^>(pointer)
	{

	}

	bool CollideableObjClassDynamicVectorClass::Resize(int newSize)
	{
		throw gcnew NotSupportedException();
	}

	void CollideableObjClassDynamicVectorClass::Clear()
	{
		AnimCollisionManagerHelper::CollisionMeshesClear(InternalCollideableObjClassDynamicVectorClassPointer);
	}

	int CollideableObjClassDynamicVectorClass::ID(ICollideableObjClass ^object)
	{
		throw gcnew NotSupportedException();
	}

	void CollideableObjClassDynamicVectorClass::Insert(int index, ICollideableObjClass ^object)
	{
		throw gcnew NotSupportedException();
	}

	bool CollideableObjClassDynamicVectorClass::Add(ICollideableObjClass ^object)
	{
		throw gcnew NotSupportedException();
	}

	void CollideableObjClassDynamicVectorClass::ResetActive()
	{
		AnimCollisionManagerHelper::CollisionMeshesResetActive(InternalCollideableObjClassDynamicVectorClassPointer);
	}

	bool CollideableObjClassDynamicVectorClass::AddHead(ICollideableObjClass ^object)
	{
		throw gcnew NotSupportedException();
	}

	bool CollideableObjClassDynamicVectorClass::DeleteObj(ICollideableObjClass ^object)
	{
		throw gcnew NotSupportedException();
	}

	bool CollideableObjClassDynamicVectorClass::Delete(int index)
	{
		throw gcnew NotSupportedException();
	}

	void CollideableObjClassDynamicVectorClass::DeleteAll()
	{
		throw gcnew NotSupportedException();
	}

	int CollideableObjClassDynamicVectorClass::UninitializedAdd()
	{
		throw gcnew NotSupportedException();
	}

	void CollideableObjClassDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		throw gcnew NotSupportedException();
	}

	IntPtr CollideableObjClassDynamicVectorClass::CollideableObjClassDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalCollideableObjClassDynamicVectorClassPointer);
	}

	ICollideableObjClass ^CollideableObjClassDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = AnimCollisionManagerHelper::CollisionMeshesIndexOperator(InternalCollideableObjClassDynamicVectorClassPointer, index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew CollideableObjClass(IntPtr(result));
		}
	}

	void CollideableObjClassDynamicVectorClass::default::set(int index, ICollideableObjClass ^value)
	{
		throw gcnew NotSupportedException();
	}

	int CollideableObjClassDynamicVectorClass::Length::get()
	{
		return AnimCollisionManagerHelper::CollisionMeshesGetLength(InternalCollideableObjClassDynamicVectorClassPointer);
	}

	int CollideableObjClassDynamicVectorClass::Count::get()
	{
		return AnimCollisionManagerHelper::CollisionMeshesGetCount(InternalCollideableObjClassDynamicVectorClassPointer);
	}

	void CollideableObjClassDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		AnimCollisionManagerHelper::CollisionMeshesSetCount(InternalCollideableObjClassDynamicVectorClassPointer, value);
	}

	int CollideableObjClassDynamicVectorClass::GrowthStep::get()
	{
		return AnimCollisionManagerHelper::CollisionMeshesGetGrowthStep(InternalCollideableObjClassDynamicVectorClassPointer);
	}

	void CollideableObjClassDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		AnimCollisionManagerHelper::CollisionMeshesSetGrowthStep(InternalCollideableObjClassDynamicVectorClassPointer, value);
	}

	bool CollideableObjClassDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyCollideableObjClassDynamicVectorClass(InternalCollideableObjClassDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	void *CollideableObjClassDynamicVectorClass::InternalCollideableObjClassDynamicVectorClassPointer::get()
	{
		return Pointer.ToPointer();
	}

	IntPtr CollideableObjClassDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerHelper::CollideableObjClassDynamicVectorClassHelper *>(InternalCollideableObjClassDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void CollideableObjClassDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<AnimCollisionManagerHelper::CollideableObjClassDynamicVectorClassHelper *>(InternalCollideableObjClassDynamicVectorClassPointer);

		helper->SetVector(value.ToPointer());
	}

	int CollideableObjClassDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerHelper::CollideableObjClassDynamicVectorClassHelper *>(InternalCollideableObjClassDynamicVectorClassPointer);

		auto &vectorMax = helper->GetVectorMax();

		return vectorMax;
	}

	void CollideableObjClassDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<AnimCollisionManagerHelper::CollideableObjClassDynamicVectorClassHelper *>(InternalCollideableObjClassDynamicVectorClassPointer);

		auto &vectorMax = helper->GetVectorMax();

		vectorMax = value;
	}

	bool CollideableObjClassDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerHelper::CollideableObjClassDynamicVectorClassHelper *>(InternalCollideableObjClassDynamicVectorClassPointer);

		auto &isValid = helper->GetIsValid();

		return isValid;
	}

	void CollideableObjClassDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<AnimCollisionManagerHelper::CollideableObjClassDynamicVectorClassHelper *>(InternalCollideableObjClassDynamicVectorClassPointer);

		auto &isValid = helper->GetIsValid();

		isValid = value;
	}

	bool CollideableObjClassDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerHelper::CollideableObjClassDynamicVectorClassHelper *>(InternalCollideableObjClassDynamicVectorClassPointer);

		auto &isAllocated = helper->GetIsAllocated();

		return isAllocated;
	}

	void CollideableObjClassDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<AnimCollisionManagerHelper::CollideableObjClassDynamicVectorClassHelper *>(InternalCollideableObjClassDynamicVectorClassPointer);

		auto &isAllocated = helper->GetIsAllocated();

		isAllocated = value;
	}

	int CollideableObjClassDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerHelper::CollideableObjClassDynamicVectorClassHelper *>(InternalCollideableObjClassDynamicVectorClassPointer);

		auto &activeCount = helper->GetActiveCount();

		return activeCount;
	}

	void CollideableObjClassDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<AnimCollisionManagerHelper::CollideableObjClassDynamicVectorClassHelper *>(InternalCollideableObjClassDynamicVectorClassPointer);

		auto &activeCount = helper->GetActiveCount();

		activeCount = value;
	}
}