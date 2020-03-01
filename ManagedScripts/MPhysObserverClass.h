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

#include "IUnmanagedObject.h"
#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <PhysObserverClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	interface class IPhysClass;
	interface class IDamageableGameObj;
	interface class IPhysicalGameObj;
	interface class IBuildingGameObj;

	public enum class CollisionReactionType : int
	{
		CollisionReactionDefault = ::COLLISION_REACTION_DEFAULT,
		CollisionReactionStopMotion = ::COLLISION_REACTION_STOP_MOTION,
		CollisionReactionNoBounce = ::COLLISION_REACTION_NO_BOUNCE
	};

	public enum class ExpirationReactionType : int
	{
		ExpirationDenied = ::EXPIRATION_DENIED,
		ExpirationApproved = ::EXPIRATION_APPROVED
	};

	public interface class IPhysObserverClass : public IUnmanagedObject
	{
		int CollisionOccurred(IntPtr event);

		int ObjectExpired(IPhysClass ^observedObj);

		void ObjectRemovedFromScene(IPhysClass ^observedObj);

		void ObjectShatteredSomething(IPhysClass ^observedObj, IPhysClass ^shatteredObj, int surfaceType);

		property IntPtr PhysObserverClassPointer
		{
			IntPtr get();
		}
	};

	public ref class PhysObserverClass : public AbstractUnmanagedObject, public IPhysObserverClass
	{
		private:
			PhysObserverClass();

		public:
			PhysObserverClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			static IUnmanagedContainer<IPhysObserverClass ^> ^CreatePhysObserverClass();

			virtual int CollisionOccurred(IntPtr event) sealed;
			virtual int ObjectExpired(IPhysClass ^observedObj) sealed;
			virtual void ObjectRemovedFromScene(IPhysClass ^observedObj) sealed;
			virtual void ObjectShatteredSomething(IPhysClass ^observedObj, IPhysClass ^shatteredObj, int surfaceType) sealed;

			property IntPtr PhysObserverClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::PhysObserverClass *InternalPhysObserverClassPointer
			{
				virtual ::PhysObserverClass *get();
			}
	};

	public interface class ICombatPhysObserverClass : public IPhysObserverClass
	{
		property IntPtr CombatPhysObserverClassPointer
		{
			IntPtr get();
		}
	};

	public ref class CombatPhysObserverClass : public PhysObserverClass, public ICombatPhysObserverClass
	{
		private:
			CombatPhysObserverClass();

		public:
			CombatPhysObserverClass(IntPtr pointer);
			
			static ICombatPhysObserverClass^ CreateCombatPhysObserverClassWrapper(IntPtr combatPhysObserverClassPtr);
			static IUnmanagedContainer<ICombatPhysObserverClass ^> ^CreateCombatPhysObserverClass();

			property IntPtr CombatPhysObserverClassPointer
			{
				virtual IntPtr get() sealed;
			}

		internal:
			static ICombatPhysObserverClass^ CreateCombatPhysObserverClassWrapper(::CombatPhysObserverClass* combatPhysObserverClassPtr);

		protected:
			bool InternalDestroyPointer() override;

			property ::PhysObserverClass *InternalPhysObserverClassPointer
			{
				::PhysObserverClass *get() override;
			}

			property ::CombatPhysObserverClass *InternalCombatPhysObserverClassPointer
			{
				virtual ::CombatPhysObserverClass *get();
			}
	};
}