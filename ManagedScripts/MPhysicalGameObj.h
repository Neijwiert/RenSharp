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

#include "MDamageableGameObj.h"
#include "MPhysObserverClass.h"
#include "MPhysDefClass.h"
#include "MPhysicalGameObjDef.h"

#pragma managed(push, off)

class PhysicalGameObj;

#pragma managed(pop)

namespace RenSharp
{

#pragma warning(push)
#pragma warning(disable : 4099 4251 4244 26495 26454)

	interface class IPhysClass;
	value class Matrix3D;
	interface class IRenderObjClass;
	value class Vector3;
	interface class IOffenseObjectClass;
	interface class IPowerUpGameObj;
	interface class IC4GameObj;
	interface class IBeaconGameObj;
	interface class ISimpleGameObj;
	interface class ICinematicGameObj;
	interface class IAnimControlClass;
	interface class IArmedGameObj;

#pragma warning(pop) 

	public interface class IPhysicalGameObj : public IDamageableGameObj, public ICombatPhysObserverClass
	{
		void Startup();

		IPhysClass ^PeekPhysicalObject();

		IRenderObjClass ^PeekModel();

		void SetAnimation(String ^animationName, bool looping, float frameOffset);

		void SetAnimation(String ^animationName, bool looping);

		void SetAnimation(String ^animationName);

		void SetAnimationFrame(String ^animationName, int frame);

		void ApplyDamageExtended(IOffenseObjectClass ^offense, float scale, Vector3 direction, String ^collisionBoxName);

		void ApplyDamageExtended(IOffenseObjectClass ^offense, float scale, Vector3 direction);

		void ApplyDamageExtended(IOffenseObjectClass ^offense, float scale);

		void ApplyDamageExtended(IOffenseObjectClass ^offense);

		void EnableHibernation(bool enable);

		void DoNotHibernate();

		void BeginHibernation();

		void EndHibernation();

		void ResetRadarBlipShapeType();

		void ClearAnimation();

		void SetTeamVisibility(TeamVisibilitySetting setting);

		void SetPlayerVisible(bool visible);

		property IntPtr PhysicalGameObjPointer
		{
			IntPtr get();
		}

		property IPhysicalGameObjDef ^Definition
		{
			IPhysicalGameObjDef ^get();
		}

		property bool IsAttachedToAnObject
		{
			bool get();
		}

		property Matrix3D Transform
		{
			Matrix3D get();
			void set(Matrix3D value);
		}

		property float Facing
		{
			float get();
		}

		property IAnimControlClass ^AnimControl
		{
			IAnimControlClass ^get();
		}

		property float BullseyeOffsetZ
		{
			float get();
		}

		property Vector3 BullseyePosition
		{
			Vector3 get();
		}

		property bool TakesExplosionDamage
		{
			bool get();
		}

		property int Type
		{
			int get();
		}

		property CollisionGroupType CollisionGroup
		{
			CollisionGroupType get();
			void set(CollisionGroupType value);
		}

		property BYTE ServerSkips
		{
			BYTE get();
		}

		property int RadarBlipShapeType
		{
			int get();
			void set(int value);
		}

		property int RadarBlipColorType
		{
			int get();
			void set(int value);
		}

		property float RadarBlipIntensity
		{
			float get();
			void set(float value);
		}

		property bool IsInnateConversationsEnabled
		{
			bool get();
			void set(bool value);
		}

		property bool IsInConversation
		{
			bool get();
		}

		property bool HUDPokableIndicatorEnabled
		{
			bool get();
		}

		property IScriptableGameObj^ ParentObject
		{
			IScriptableGameObj^ get();
		}
	};

	public ref class PhysicalGameObj : public DamageableGameObj, public IPhysicalGameObj
	{
		private:
			ICombatPhysObserverClass ^combatPhysObserverClass;

		public:
			PhysicalGameObj(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual int CollisionOccurred(IntPtr event) sealed;
			virtual int ObjectExpired(IPhysClass ^observedObj) sealed;
			virtual void ObjectRemovedFromScene(IPhysClass ^observedObj) sealed;
			virtual void ObjectShatteredSomething(IPhysClass ^observedObj, IPhysClass ^shatteredObj, int surfaceType) sealed;

			virtual void Startup() sealed;
			virtual IPhysClass ^PeekPhysicalObject() sealed;
			virtual IRenderObjClass ^PeekModel() sealed;
			virtual void SetAnimation(String ^animationName, bool looping, float frameOffset) sealed;
			virtual void SetAnimation(String ^animationName, bool looping) sealed;
			virtual void SetAnimation(String ^animationName) sealed;
			virtual void SetAnimationFrame(String ^animationName, int frame) sealed;
			virtual void ApplyDamageExtended(IOffenseObjectClass ^offense, float scale, Vector3 direction, String ^collisionBoxName) sealed;
			virtual void ApplyDamageExtended(IOffenseObjectClass ^offense, float scale, Vector3 direction) sealed;
			virtual void ApplyDamageExtended(IOffenseObjectClass ^offense, float scale) sealed;
			virtual void ApplyDamageExtended(IOffenseObjectClass ^offense) sealed;
			virtual void EnableHibernation(bool enable) sealed;
			virtual void DoNotHibernate() sealed;
			virtual void BeginHibernation() sealed;
			virtual void EndHibernation() sealed;
			virtual void ResetRadarBlipShapeType() sealed;
			virtual void ClearAnimation() sealed;
			virtual void SetTeamVisibility(TeamVisibilitySetting setting) sealed;
			virtual void SetPlayerVisible(bool visible) sealed;

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property Vector3 Position
			{
				Vector3 get() override;
				void set(Vector3 value);
			}

			property IntPtr PhysObserverClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr CombatPhysObserverClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr PhysicalGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

#pragma push_macro("new")
#undef new

			property IPhysicalGameObjDef ^Definition
			{
				virtual IPhysicalGameObjDef ^get() new sealed;
			}

#pragma pop_macro("new")

			property bool IsAttachedToAnObject
			{
				virtual bool get() sealed;
			}

			property Matrix3D Transform
			{
				virtual Matrix3D get() sealed;
				virtual void set(Matrix3D value) sealed;
			}

			property float Facing
			{
				virtual float get() sealed;
			}

			property IAnimControlClass ^AnimControl
			{
				virtual IAnimControlClass ^get() sealed;
			}

			property float BullseyeOffsetZ
			{
				virtual float get() sealed;
			}

			property Vector3 BullseyePosition
			{
				virtual Vector3 get() sealed;
			}

			property bool TakesExplosionDamage
			{
				virtual bool get() sealed;
			}

			property int Type
			{
				virtual int get() sealed;
			}

			property CollisionGroupType CollisionGroup
			{
				virtual CollisionGroupType get() sealed;
				virtual void set(CollisionGroupType value) sealed;
			}

			property BYTE ServerSkips
			{
				virtual BYTE get() sealed;
			}

			property int RadarBlipShapeType
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int RadarBlipColorType
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float RadarBlipIntensity
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool IsInnateConversationsEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsInConversation
			{
				virtual bool get() sealed;
			}

			property bool HUDPokableIndicatorEnabled
			{
				virtual bool get() sealed;
			}

			property IScriptableGameObj^ ParentObject
			{
				virtual IScriptableGameObj^ get() sealed;
			}

		protected:
			property ::DamageableGameObj *InternalDamageableGameObjPointer
			{
				::DamageableGameObj *get() override;
			}

			property ::PhysObserverClass *InternalPhysObserverClassPointer
			{
				virtual ::PhysObserverClass *get();
			}

			property ::CombatPhysObserverClass *InternalCombatPhysObserverClassPointer
			{
				virtual ::CombatPhysObserverClass *get();
			}

			property ::PhysicalGameObj *InternalPhysicalGameObjPointer
			{
				virtual ::PhysicalGameObj *get();
			}

			property IntPtr ActiveConversation
			{
				IntPtr get();
				void set(IntPtr value);
			}
	};
}