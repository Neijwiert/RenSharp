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

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <scripts.h>

class SafeActionParamsStruct;

#pragma warning(pop) 
#pragma managed(pop)

#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"
#include "MVector3.h"
#include "MScriptableGameObj.h"
#include "Imports.h"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;
using namespace System::Drawing;

namespace RenSharp
{

#pragma warning(push)
#pragma warning(disable : 4099 4251 4244 26495 26454)

	interface class IRenSharpGameObjObserverClass;
	interface class IScriptFactory;
	ref class ActionParamsStruct;

#pragma warning(pop) 

	public enum class CombatSoundType : int
	{
		SoundTypeNone = ::SOUND_TYPE_NONE,
		SoundTypeOldWeapon = ::SOUND_TYPE_OLD_WEAPON,
		SoundTypeFootsteps = ::SOUND_TYPE_FOOTSTEPS,
		SoundTypeVehicle = ::SOUND_TYPE_VEHICLE,
		SoundTypeGunshot = ::SOUND_TYPE_GUNSHOT,
		SoundTypeBulletHit = ::SOUND_TYPE_BULLET_HIT,
		NumDefinedSoundTypes = ::NUM_DEFINED_SOUND_TYPES,
		SoundTypeDesigner01 = ::SOUND_TYPE_DESIGNER01,
		SoundTypeDesigner02 = ::SOUND_TYPE_DESIGNER02,
		SoundTypeDesigner03 = ::SOUND_TYPE_DESIGNER03,
		SoundTypeDesigner04 = ::SOUND_TYPE_DESIGNER04,
		SoundTypeDesigner05 = ::SOUND_TYPE_DESIGNER05,
		SoundTypeDesigner06 = ::SOUND_TYPE_DESIGNER06,
		SoundTypeDesigner07 = ::SOUND_TYPE_DESIGNER07,
		SoundTypeDesigner08 = ::SOUND_TYPE_DESIGNER08,
		SoundTypeDesigner09 = ::SOUND_TYPE_DESIGNER09
	};

	public enum class ActionCompleteReason : int
	{
		ActionCompleteNormal = ::ACTION_COMPLETE_NORMAL,
		ActionCompleteLowPriority = ::ACTION_COMPLETE_LOW_PRIORITY,
		ActionCompletePathBadStart = ::ACTION_COMPLETE_PATH_BAD_START,
		ActionCompletePathBadDest = ::ACTION_COMPLETE_PATH_BAD_DEST,
		ActionCompleteMoveNoProgressMade = ::ACTION_COMPLETE_MOVE_NO_PROGRESS_MADE,
		ActionCompleteAttackOutOfRange = ::ACTION_COMPLETE_ATTACK_OUT_OF_RANGE,
		ActionCompleteConversationEnded = ::ACTION_COMPLETE_CONVERSATION_ENDED,
		ActionCompleteConversationInterrupted = ::ACTION_COMPLETE_CONVERSATION_INTERRUPTED,
		ActionCompleteConversationUnableToInit = ::ACTION_COMPLETE_CONVERSATION_UNABLE_TO_INIT,
		MovementCompleteArrived = ::MOVEMENT_COMPLETE_ARRIVED
	};

	public enum class SoldierAIState : int
	{
		NoAIStateChange = ::NO_AI_STATE_CHANGE,
		AIStateIdle = ::AI_STATE_IDLE,
		AIStateSecondaryIdle = ::AI_STATE_SECONDARY_IDLE,
		AIStateSearch = ::AI_STATE_SEARCH,
		AIStateCombat = ::AI_STATE_COMBAT
	};

	public enum class CustomEventType : int
	{
		CustomEventSystemFirst = ::CUSTOM_EVENT_SYSTEM_FIRST,
		CustomEventSoundEnded = ::CUSTOM_EVENT_SOUND_ENDED,
		CustomEventBuildingPowerChanged = ::CUSTOM_EVENT_BUILDING_POWER_CHANGED,
		CustomEventDockBackingIn = ::CUSTOM_EVENT_DOCK_BACKING_IN,
		CustomEventCinematicSetFirstSlot = ::CUSTOM_EVENT_CINEMATIC_SET_FIRST_SLOT,
		CustomEventCinematicSetLastSlot = ::CUSTOM_EVENT_CINEMATIC_SET_LAST_SLOT,
		CustomEventPowerUpGranted = ::CUSTOM_EVENT_POWERUP_GRANTED,
		CustomEventBuildingDamaged = ::CUSTOM_EVENT_BUILDING_DAMAGED,
		CustomEventBuildingRepaired = ::CUSTOM_EVENT_BUILDING_REPAIRED,
		CustomEventVehicleEntered = ::CUSTOM_EVENT_VEHICLE_ENTERED,
		CustomEventVehicleExited = ::CUSTOM_EVENT_VEHICLE_EXITED,
		CustomEventAttackArrived = ::CUSTOM_EVENT_ATTACK_ARRIVED,
		CustomEventConversationBegan = ::CUSTOM_EVENT_CONVERSATION_BEGAN,
		CustomEventConversationRemarkStarted = ::CUSTOM_EVENT_CONVERSATION_REMARK_STARTED,
		CustomEventConversationRemarkEnded = ::CUSTOM_EVENT_CONVERSATION_REMARK_ENDED,
		CustomEventLaddedOccupied = ::CUSTOM_EVENT_LADDER_OCCUPIED,
		CustomEventFallingDamage = ::CUSTOM_EVENT_FALLING_DAMAGE,
		CustomEventVehicleOwner = ::CUSTOM_EVENT_VEHICLE_OWNER,
		CustomEventVehicleDriver = ::CUSTOM_EVENT_VEHICLE_DRIVER,
		CustomEventVehicleDriverId = ::CUSTOM_EVENT_VHEICLE_DRIVER_ID,
		CustomEventBeaconDeployed = ::CUSTOM_EVENT_BEACON_DEPLOYED,
		CustomEventRefill = ::CUSTOM_EVENT_REFILL,
		CustomEventBuildingRevived = ::CUSTOM_EVENT_BUILDING_REVIVED
	};

	public enum class ObjectiveType : int
	{
		ObjectiveTypePrimary = ::OBJECTIVE_TYPE_PRIMARY,
		ObjectiveTypeSecondary = ::OBJECTIVE_TYPE_SECONDARY,
		ObjectiveTypeTertiary = ::OBJECTIVE_TYPE_TERTIARY
	};

	public enum class ObjectiveStatus : int
	{
		ObjectiveStatusPending = ::OBJECTIVE_STATUS_PENDING,
		ObjectiveStatusAccomplished = ::OBJECTIVE_STATUS_ACCOMPLISHED,
		ObjectiveStatusFailed = ::OBJECTIVE_STATUS_FAILED,
		ObjectiveStatusHidden = ::OBJECTIVE_STATUS_HIDDEN
	};

	public enum class RadarBlipShape : int
	{
		RadarBlipShapeNone = ::RADAR_BLIP_SHAPE_NONE,
		RadarBlipShapeHuman = ::RADAR_BLIP_SHAPE_HUMAN,
		RadarBlipShapeVehicle = ::RADAR_BLIP_SHAPE_VEHICLE,
		RadarBlipShapeStationary = ::RADAR_BLIP_SHAPE_STATIONARY,
		RadarBlipShapeObjective = ::RADAR_BLIP_SHAPE_OBJECTIVE,
		RadarBlipShapeExtra1 = ::RADAR_BLIP_SHAPE_EXTRA_1,
		RadarBlipShapeExtra2 = ::RADAR_BLIP_SHAPE_EXTRA_2,
		RadarBlipShapeExtra3 = ::RADAR_BLIP_SHAPE_EXTRA_3,
		RadarBlipShapeExtra4 = ::RADAR_BLIP_SHAPE_EXTRA_4,
		RadarBlipShapeExtraDistant1 = ::RADAR_BLIP_SHAPE_EXTRA_DISTANT_1,
		RadarBlipShapeExtraDistant2 = ::RADAR_BLIP_SHAPE_EXTRA_DISTANT_2,
		RadarBlipShapeExtraDistant3 = ::RADAR_BLIP_SHAPE_EXTRA_DISTANT_3,
		RadarBlipShapeExtraDistant4 = ::RADAR_BLIP_SHAPE_EXTRA_DISTANT_4
	};

	public enum class RadarBlipColor : int
	{
		RadarBlipColorNod = ::RADAR_BLIP_COLOR_NOD,
		RadarBlipColorGDI = ::RADAR_BLIP_COLOR_GDI,
		RadarBlipColorNeutral = ::RADAR_BLIP_COLOR_NEUTRAL,
		RadarBlipColorMutant = ::RADAR_BLIP_COLOR_MUTANT,
		RadarBlipColorRenegade = ::RADAR_BLIP_COLOR_RENEGADE,
		RadarBlipColorPrimaryObjective = ::RADAR_BLIP_COLOR_PRIMARY_OBJECTIVE,
		RadarBlipColorSecondaryObjective = ::RADAR_BLIP_COLOR_SECONDARY_OBJECTIVE,
		RadarBlipColorTertiaryObjective = ::RADAR_BLIP_COLOR_TERTIARY_OBJECTIVE
	};

	public enum class ScriptPlayerType : int
	{
		ScriptPlayerTypeSpectator = ::SCRIPT_PLAYERTYPE_SPECTATOR,
		ScriptPlayerTypeMutant = ::SCRIPT_PLAYERTYPE_MUTANT,
		ScriptPlayerTypeNeutral = ::SCRIPT_PLAYERTYPE_NEUTRAL,
		ScriptPlayerTypeRenegade = ::SCRIPT_PLAYERTYPE_RENEGADE,
		ScriptPlayerTypeNod = ::SCRIPT_PLAYERTYPE_NOD,
		ScriptPlayerTypeGDI = ::SCRIPT_PLAYERTYPE_GDI
	};

	public interface class ICombatSound : public IUnmanagedObject
	{
		property IntPtr CombatSoundPointer
		{
			IntPtr get();
		}

		property Vector3 Position
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property int Sound
		{
			int get();
			void set(int value);
		}

		property IScriptableGameObj ^Creator
		{
			IScriptableGameObj ^get();
			void set(IScriptableGameObj ^value);
		}
	};

	public ref class CombatSound : public AbstractUnmanagedObject, public ICombatSound
	{
		private:
			CombatSound();

		public:
			CombatSound(IntPtr pointer);

			static IUnmanagedContainer<ICombatSound ^> ^CreateCombatSound();

			bool Equals(Object ^other) override;

			property IntPtr CombatSoundPointer
			{
				virtual IntPtr get() sealed;
			}

			property Vector3 Position
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property int Sound
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property IScriptableGameObj ^Creator
			{
				virtual IScriptableGameObj ^get() sealed;
				virtual void set(IScriptableGameObj ^value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::CombatSound *InternalCombatSoundPointer
			{
				virtual ::CombatSound *get();
			}
	};

	public interface class IGameObjObserverClass : public IUnmanagedObject
	{
		void Attach(IScriptableGameObj ^obj);

		void Detach(IScriptableGameObj ^obj);

		void Created(IScriptableGameObj ^obj);

		void Destroyed(IScriptableGameObj ^obj);

		void Killed(IScriptableGameObj ^obj, IScriptableGameObj ^killer);

		void Damaged(IScriptableGameObj ^obj, IScriptableGameObj ^damager, float amount);

		void Custom(IScriptableGameObj ^obj, int type, int param, IScriptableGameObj ^sender);

		void SoundHeard(IScriptableGameObj ^obj, ICombatSound ^sound);

		void EnemySeen(IScriptableGameObj ^obj, IScriptableGameObj ^enemy);

		void ActionComplete(IScriptableGameObj ^obj, int actionId, ActionCompleteReason completeReason);

		void TimerExpired(IScriptableGameObj ^obj, int number);

		void AnimationComplete(IScriptableGameObj ^obj, String ^animationName);

		void Poked(IScriptableGameObj ^obj, IScriptableGameObj ^poker);

		void Entered(IScriptableGameObj ^obj, IScriptableGameObj ^enterer);

		void Exited(IScriptableGameObj ^obj, IScriptableGameObj ^exiter);

		IRenSharpGameObjObserverClass^ AsManagedObserver();

		property IntPtr GameObjObserverClassPointer
		{
			IntPtr get();
		}

		property String ^Name
		{
			String ^get();
		}

		property int ID
		{
			int get();
			void set(int value);
		}

		property IScriptableGameObj ^Owner
		{
			IScriptableGameObj ^get();
		}

		property bool IsManagedObserver
		{
			bool get();
		}
	};

	public ref class GameObjObserverClass : public AbstractUnmanagedObject, public IGameObjObserverClass
	{
		protected:
			GameObjObserverClass();

		public:
			GameObjObserverClass(IntPtr pointer);

			static IGameObjObserverClass^ CreateGameObjObserverClassWrapper(IntPtr gameObjObserverClass);

			String ^ToString() override;
			bool Equals(Object ^other) override;

			virtual void Attach(IScriptableGameObj ^obj);
			virtual void Detach(IScriptableGameObj ^obj);
			virtual void Created(IScriptableGameObj ^obj);
			virtual void Destroyed(IScriptableGameObj ^obj) sealed;
			virtual void Killed(IScriptableGameObj ^obj, IScriptableGameObj ^killer);
			virtual void Damaged(IScriptableGameObj ^obj, IScriptableGameObj ^damager, float amount);
			virtual void Custom(IScriptableGameObj ^obj, int type, int param, IScriptableGameObj ^sender) sealed;
			virtual void SoundHeard(IScriptableGameObj ^obj, ICombatSound ^sound) sealed;
			virtual void EnemySeen(IScriptableGameObj ^obj, IScriptableGameObj ^enemy) sealed;
			virtual void ActionComplete(IScriptableGameObj ^obj, int actionId, ActionCompleteReason completeReason) sealed;
			virtual void TimerExpired(IScriptableGameObj ^obj, int number) sealed;
			virtual void AnimationComplete(IScriptableGameObj ^obj, String ^animationName) sealed;
			virtual void Poked(IScriptableGameObj ^obj, IScriptableGameObj ^poker) sealed;
			virtual void Entered(IScriptableGameObj ^obj, IScriptableGameObj ^enterer) sealed;
			virtual void Exited(IScriptableGameObj ^obj, IScriptableGameObj ^exiter) sealed;
			virtual IRenSharpGameObjObserverClass^ AsManagedObserver() sealed;

			property IntPtr GameObjObserverClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String ^Name
			{
				virtual String ^get() sealed;
			}

			property int ID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property IScriptableGameObj ^Owner
			{
				virtual IScriptableGameObj ^get();
			}

			property bool IsManagedObserver
			{
				virtual bool get() sealed;
			}

		internal:
			static IGameObjObserverClass^ CreateGameObjObserverClassWrapper(::GameObjObserverClass* gameObjObserverClassPtr);

		protected:
			bool InternalDestroyPointer() override;

			property ::GameObjObserverClass *InternalGameObjObserverClassPointer
			{
				virtual ::GameObjObserverClass *get();
			}
	};

	public interface class IScriptVariableClass : public IUnmanagedObject
	{
		property IntPtr ScriptVariableClassPointer
		{
			IntPtr get();
		}

		property IntPtr DataPtr
		{
			IntPtr get();
		}

		property int DataSize
		{
			int get();
		}

		property int ID
		{
			int get();
		}

		property IScriptVariableClass ^Next
		{
			IScriptVariableClass ^get();
		}
	};

	public ref class ScriptVariableClass : public AbstractUnmanagedObject, public IScriptVariableClass
	{
		private:
			ScriptVariableClass(IntPtr dataPtr, int dataSize, int id, IScriptVariableClass ^next);

		public:
			ScriptVariableClass(IntPtr pointer);

			static IUnmanagedContainer<IScriptVariableClass ^> ^CreateScriptVariableClass(IntPtr dataPtr, int dataSize, int id, IScriptVariableClass ^next);

			bool Equals(Object ^other) override;

			property IntPtr ScriptVariableClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr DataPtr
			{
				virtual IntPtr get() sealed;
			}

			property int DataSize
			{
				virtual int get() sealed;
			}

			property int ID
			{
				virtual int get() sealed;
			}

			property IScriptVariableClass ^Next
			{
				virtual IScriptVariableClass ^get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::ScriptVariableClass *InternalScriptVariableClassPointer
			{
				virtual ::ScriptVariableClass *get();
			}
	};

	public interface class IScriptClass : public IGameObjObserverClass
	{
		void Save(IntPtr saver);

		void Load(IntPtr loader);

		property IntPtr ScriptClassPointer
		{
			IntPtr get();
		}

		property IScriptableGameObj ^Owner
		{
			IScriptableGameObj ^get();
			void set(IScriptableGameObj ^value);
		}

		property String ^ParametersString
		{
			String ^get();
			void set(String ^value);
		}
	};

	public ref class ScriptClass : public GameObjObserverClass, public IScriptClass
	{
		public:
			ScriptClass(IntPtr pointer);

			virtual void Save(IntPtr saver) sealed;
			virtual void Load(IntPtr loader) sealed;

			property IntPtr ScriptClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IScriptableGameObj ^Owner
			{
				IScriptableGameObj ^get() override;
				virtual void set(IScriptableGameObj ^value) sealed;
			}

			property String ^ParametersString
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

		protected:
			property ::GameObjObserverClass *InternalGameObjObserverClassPointer
			{
				::GameObjObserverClass *get() override;
			}

			property ::ScriptClass *InternalScriptClassPointer
			{
				virtual ::ScriptClass *get();
			}
	};

	public interface class IScriptImpClass : public IScriptClass
	{
		void SetFactory(IScriptFactory ^factory);

		int CheckPlayerType(IScriptableGameObj ^obj, int type);

		void AutoSaveVariable(IntPtr dataPtr, int dataSize, int id);

		void RegisterAutoSaveVariables();

		String ^GetParameter(String ^name);

		String ^GetParameter(int index);

		int GetIntParameter(String ^parameterName);

		float GetFloatParameter(String ^parameterName);

		Vector3 GetVector3Parameter(int index);

		Vector3 GetVector3Parameter(String ^parameterName);

		int GetParameterIndex(String ^parameterName);

		int GetIntParameter(int index);

		float GetFloatParameter(int index);

		bool GetBoolParameter(String ^name);

		bool GetBoolParameter(int index);

		void DestroyScript();

		property IntPtr ScriptImpClassPointer
		{
			IntPtr get();
		}

		property int ParameterCount
		{
			int get();
		}
	};

	public ref class ScriptImpClass : public ScriptClass, public IScriptImpClass
	{
		private:
			ScriptImpClass();

		public:
			ScriptImpClass(IntPtr pointer);

			static IUnmanagedContainer<IScriptImpClass ^> ^CreateScriptImpClass();

			virtual void SetFactory(IScriptFactory ^factory) sealed;
			virtual int CheckPlayerType(IScriptableGameObj ^obj, int type) sealed;
			virtual void AutoSaveVariable(IntPtr dataPtr, int dataSize, int id) sealed;
			virtual void RegisterAutoSaveVariables() sealed;
			virtual String ^GetParameter(String ^name) sealed;
			virtual String ^GetParameter(int index) sealed;
			virtual int GetIntParameter(String ^parameterName) sealed;
			virtual float GetFloatParameter(String ^parameterName) sealed;
			virtual Vector3 GetVector3Parameter(int index) sealed;
			virtual Vector3 GetVector3Parameter(String ^parameterName) sealed;
			virtual int GetParameterIndex(String ^parameterName) sealed;
			virtual int GetIntParameter(int index) sealed;
			virtual float GetFloatParameter(int index) sealed;
			virtual bool GetBoolParameter(String ^name) sealed;
			virtual bool GetBoolParameter(int index) sealed;
			virtual void DestroyScript() sealed;

			property IntPtr ScriptImpClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int ParameterCount
			{
				virtual int get() sealed;
			}

		protected:
			property ::ScriptClass *InternalScriptClassPointer
			{
				::ScriptClass *get() override;
			}

			property ::ScriptImpClass *InternalScriptImpClassPointer
			{
				virtual ::ScriptImpClass *get();
			}
	};

	public interface class IActionParamsStruct : public IUnmanagedObject
	{
		ActionParamsStruct ^ToActionParamsStruct();

		void SetBasicOld(IScriptClass^ script, unsigned long priority, unsigned long id, SoldierAIState state);

		void SetAttackHold(IScriptableGameObj^ target, float range, float deviation, bool primary, bool hold);

		void SetAttackPosition(Vector3 position, float range, float deviation, bool primary);

		void SetGotoLocation(Vector3 position, float speed, float arriveDistance, bool crouch);

		void SetGotoFollowing(IScriptableGameObj^ target, float speed, float arriveDistance, bool following);

		void SetGotoCrouch(IScriptableGameObj^ target, float speed, float arriveDistance, bool crouch);

		void SetGotoCrouchFollowing(IScriptableGameObj^ target, float speed, float arriveDistance, bool crouch, bool following);

		void SetGoto(IScriptableGameObj^ target, float speed, float arriveDistance);

		void SetGotoWaypathStart(unsigned long waypathId, unsigned long waypathStartId, unsigned long waypathEndId, bool splined);

		void SetGotoWaypath(unsigned long waypathId, bool splined, bool attackActive, bool hold);

		void SetGotoWaypathId(unsigned long waypathId);

		void SetMoveArriveDistance(float distance);

		void SetBasic(IGameObjObserverClass ^script, float priority, int actionId, SoldierAIState aiState);

		void SetBasic(IGameObjObserverClass ^script, float priority, int actionId);

		void SetBasic(long observerId, float priority, int actionId, SoldierAIState aiState);

		void SetBasic(long observerId, float priority, int actionId);

		void SetLook(Vector3 location, float duration);

		void SetLook(IScriptableGameObj ^object, float duration);

		void SetLook(Vector3 objPos, float angle, float duration);

		void SetMovement(Vector3 location, float speed, float arrivedDistance, bool crouched);

		void SetMovement(Vector3 location, float speed, float arrivedDistance);

		void SetMovement(IScriptableGameObj ^object, float speed, float arrivedDistance, bool crouched);

		void SetMovement(IScriptableGameObj ^object, float speed, float arrivedDistance);

		void SetAttack(Vector3 location, float range, float error, bool primaryFire);

		void SetAttack(IScriptableGameObj ^object, float range, float error, bool primaryFire);

		//void SetAnimation(String ^name, bool looping);

		void SetFaceLocation(Vector3 location, float duration);

		void SetFaceLocation(Vector3 objPos, float angle, float duration);

		void JoinConversation(int activeConversationId);

		//void StartConversation(String ^name);

		void DockVehicle(Vector3 dockLocation, Vector3 dockEntrance);

		property IntPtr ActionParamsStructPointer
		{
			IntPtr get();
		}

		property int Priority
		{
			int get();
			void set(int value);
		}

		property int ActionID
		{
			int get();
			void set(int value);
		}

		property long ObserverID
		{
			long get();
			void set(long value);
		}

		property Vector3 LookLocation
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property IScriptableGameObj ^LookObject
		{
			IScriptableGameObj ^get();
			void set(IScriptableGameObj ^value);
		}

		property float LookDuration
		{
			float get();
			void set(float value);
		}

		property Vector3 MoveLocation
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property IScriptableGameObj ^MoveObject
		{
			IScriptableGameObj ^get();
			void set(IScriptableGameObj ^value);
		}

		property Vector3 MoveObjectOffset
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property float MoveSpeed
		{
			float get();
			void set(float value);
		}

		property float MoveArrivedDistance
		{
			float get();
			void set(float value);
		}

		property bool MoveBackup
		{
			bool get();
			void set(bool value);
		}

		property bool MoveFollow
		{
			bool get();
			void set(bool value);
		}

		property bool MoveCrouched
		{
			bool get();
			void set(bool value);
		}

		property bool MovePathfind
		{
			bool get();
			void set(bool value);
		}

		property bool ShutdownEngineOnArrival
		{
			bool get();
			void set(bool value);
		}

		property float AttackRange
		{
			float get();
			void set(float value);
		}

		property float AttackError
		{
			float get();
			void set(float value);
		}

		property bool AttackErrorOverride
		{
			bool get();
			void set(bool value);
		}

		property IScriptableGameObj ^AttackObject
		{
			IScriptableGameObj ^get();
			void set(IScriptableGameObj ^value);
		}

		property bool AttackPrimaryFire
		{
			bool get();
			void set(bool value);
		}

		property bool AttackCrouched
		{
			bool get();
			void set(bool value);
		}

		property Vector3 AttackLocation
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property bool AttackCheckBlocked
		{
			bool get();
			void set(bool value);
		}

		property bool AttackActive
		{
			bool get();
			void set(bool value);
		}

		property bool AttackWanderAllowed
		{
			bool get();
			void set(bool value);
		}

		property bool AttackFaceTarget
		{
			bool get();
			void set(bool value);
		}

		property bool AttackForceFire
		{
			bool get();
			void set(bool value);
		}

		property bool ForceFacing
		{
			bool get();
			void set(bool value);
		}

		property Vector3 FaceLocation
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property float FaceDuration
		{
			float get();
			void set(float value);
		}

		property bool IgnoreFacing
		{
			bool get();
			void set(bool value);
		}

		property int WaypathID
		{
			int get();
			void set(int value);
		}

		property int WaypointStartID
		{
			int get();
			void set(int value);
		}

		property int WaypointEndID
		{
			int get();
			void set(int value);
		}

		property bool WaypathSplined
		{
			bool get();
			void set(bool value);
		}

		property String ^AnimationName
		{
			String ^get();
			//void set(String ^value);
		}

		property bool AnimationLooping
		{
			bool get();
			void set(bool value);
		}

		property int ActiveConversationID
		{
			int get();
			void set(int value);
		}

		property String ^ConversationName
		{
			String ^get();
			//void set(String ^value);
		}

		property SoldierAIState AIState
		{
			SoldierAIState get();
			void set(SoldierAIState value);
		}

		property Vector3 DockLocation
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property Vector3 DockEntrance
		{
			Vector3 get();
			void set(Vector3 value);
		}
	};

	public ref class ActionParamsStructRef : public AbstractUnmanagedObject, public IActionParamsStruct
	{
		protected:
			ActionParamsStructRef(bool create);

		public:
			ActionParamsStructRef(IntPtr pointer);

			static IUnmanagedContainer<IActionParamsStruct ^> ^CreateActionParamsStructRef();

			bool Equals(Object ^other) override;

			virtual ActionParamsStruct ^ToActionParamsStruct() sealed;
			virtual void SetBasicOld(IScriptClass^ script, unsigned long priority, unsigned long id, SoldierAIState state) sealed;
			virtual void SetAttackHold(IScriptableGameObj^ target, float range, float deviation, bool primary, bool hold) sealed;
			virtual void SetAttackPosition(Vector3 position, float range, float deviation, bool primary) sealed;
			virtual void SetGotoLocation(Vector3 position, float speed, float arriveDistance, bool crouch) sealed;
			virtual void SetGotoFollowing(IScriptableGameObj^ target, float speed, float arriveDistance, bool following) sealed;
			virtual void SetGotoCrouch(IScriptableGameObj^ target, float speed, float arriveDistance, bool crouch) sealed;
			virtual void SetGotoCrouchFollowing(IScriptableGameObj^ target, float speed, float arriveDistance, bool crouch, bool following) sealed;
			virtual void SetGoto(IScriptableGameObj^ target, float speed, float arriveDistance) sealed;
			virtual void SetGotoWaypathStart(unsigned long waypathId, unsigned long waypathStartId, unsigned long waypathEndId, bool splined) sealed;
			virtual void SetGotoWaypath(unsigned long waypathId, bool splined, bool attackActive, bool hold) sealed;
			virtual void SetGotoWaypathId(unsigned long waypathId) sealed;
			virtual void SetMoveArriveDistance(float distance) sealed;
			virtual void SetBasic(IGameObjObserverClass ^script, float priority, int actionId, SoldierAIState aiState) sealed;
			virtual void SetBasic(IGameObjObserverClass ^script, float priority, int actionId) sealed;
			virtual void SetBasic(long observerId, float priority, int actionId, SoldierAIState aiState) sealed;
			virtual void SetBasic(long observerId, float priority, int actionId) sealed;
			virtual void SetLook(Vector3 location, float duration) sealed;
			virtual void SetLook(IScriptableGameObj ^object, float duration) sealed;
			virtual void SetLook(Vector3 objPos, float angle, float duration) sealed;
			virtual void SetMovement(Vector3 location, float speed, float arrivedDistance, bool crouched) sealed;
			virtual void SetMovement(Vector3 location, float speed, float arrivedDistance) sealed;
			virtual void SetMovement(IScriptableGameObj ^object, float speed, float arrivedDistance, bool crouched) sealed;
			virtual void SetMovement(IScriptableGameObj ^object, float speed, float arrivedDistance) sealed;
			virtual void SetAttack(Vector3 location, float range, float error, bool primaryFire) sealed;
			virtual void SetAttack(IScriptableGameObj ^object, float range, float error, bool primaryFire) sealed;
			//virtual void SetAnimation(String ^name, bool looping);
			virtual void SetFaceLocation(Vector3 location, float duration) sealed;
			virtual void SetFaceLocation(Vector3 objPos, float angle, float duration) sealed;
			virtual void JoinConversation(int activeConversationId) sealed;
			//virtual void StartConversation(String ^name);
			virtual void DockVehicle(Vector3 dockLocation, Vector3 dockEntrance) sealed;

			property IntPtr ActionParamsStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property int Priority
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int ActionID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property long ObserverID
			{
				virtual long get() sealed;
				virtual void set(long value) sealed;
			}

			property Vector3 LookLocation
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property IScriptableGameObj ^LookObject
			{
				virtual IScriptableGameObj ^get();
				virtual void set(IScriptableGameObj ^value);
			}

			property float LookDuration
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property Vector3 MoveLocation
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property IScriptableGameObj ^MoveObject
			{
				virtual IScriptableGameObj ^get();
				virtual void set(IScriptableGameObj ^value);
			}

			property Vector3 MoveObjectOffset
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property float MoveSpeed
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float MoveArrivedDistance
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool MoveBackup
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool MoveFollow
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool MoveCrouched
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool MovePathfind
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool ShutdownEngineOnArrival
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property float AttackRange
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float AttackError
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool AttackErrorOverride
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property IScriptableGameObj ^AttackObject
			{
				virtual IScriptableGameObj ^get();
				virtual void set(IScriptableGameObj ^value);
			}

			property bool AttackPrimaryFire
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool AttackCrouched
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property Vector3 AttackLocation
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property bool AttackCheckBlocked
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool AttackActive
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool AttackWanderAllowed
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool AttackFaceTarget
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool AttackForceFire
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool ForceFacing
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property Vector3 FaceLocation
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property float FaceDuration
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool IgnoreFacing
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int WaypathID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int WaypointStartID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int WaypointEndID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool WaypathSplined
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property String ^AnimationName
			{
				virtual String ^get();
				//virtual void set(String ^value);
			}

			property bool AnimationLooping
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int ActiveConversationID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property String ^ConversationName
			{
				virtual String ^get();
				//virtual void set(String ^value);
			}

			property SoldierAIState AIState
			{
				virtual SoldierAIState get() sealed;
				virtual void set(SoldierAIState value) sealed;
			}

			property Vector3 DockLocation
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property Vector3 DockEntrance
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}
		protected:
			bool InternalDestroyPointer() override;

			property ::ActionParamsStruct *InternalActionParamsStructPointer
			{
				virtual ::ActionParamsStruct *get();
			}
	};

	public ref class ActionParamsStruct
	{
		public:
			int Priority;
			int ActionID;           
			long ObserverID;            
			Vector3 LookLocation;
			IScriptableGameObj ^LookObject;
			float LookDuration;
			Vector3 MoveLocation;      
			IScriptableGameObj ^MoveObject;
			Vector3 MoveObjectOffset;
			float MoveSpeed;
			float MoveArrivedDistance;  
			bool MoveBackup;             
			bool MoveFollow;
			bool MoveCrouched;
			bool MovePathfind;
			bool ShutdownEngineOnArrival; 
			float AttackRange;            
			float AttackError;         
			bool AttackErrorOverride;
			IScriptableGameObj ^AttackObject;
			bool AttackPrimaryFire;
			bool AttackCrouched;
			Vector3 AttackLocation;      
			bool AttackCheckBlocked;
			bool AttackActive;
			bool AttackWanderAllowed;
			bool AttackFaceTarget;
			bool AttackForceFire;
			bool ForceFacing;
			Vector3 FaceLocation;
			float FaceDuration;
			bool IgnoreFacing;
			int	WaypathID;
			int WaypointStartID;
			int WaypointEndID;
			bool WaypathSplined;
			String ^AnimationName;
			bool AnimationLooping;
			int ActiveConversationID;
			String ^ConversationName;
			SoldierAIState AIState;
			Vector3 DockLocation;
			Vector3 DockEntrance;

			ActionParamsStruct();
			ActionParamsStruct(IActionParamsStruct ^params);
			ActionParamsStruct(ActionParamsStruct ^params);

			void CopyFrom(IActionParamsStruct ^params);
			void CopyFrom(ActionParamsStruct ^params);

			void SetBasicOld(IScriptClass^ script, unsigned long priority, unsigned long id, SoldierAIState state);
			void SetAttackHold(IScriptableGameObj^ target, float range, float deviation, bool primary, bool hold);
			void SetAttackPosition(Vector3 position, float range, float deviation, bool primary);
			void SetGotoLocation(Vector3 position, float speed, float arriveDistance, bool crouch);
			void SetGotoFollowing(IScriptableGameObj^ target, float speed, float arriveDistance, bool following);
			void SetGotoCrouch(IScriptableGameObj^ target, float speed, float arriveDistance, bool crouch);
			void SetGotoCrouchFollowing(IScriptableGameObj^ target, float speed, float arriveDistance, bool crouch, bool following);
			void SetGoto(IScriptableGameObj^ target, float speed, float arriveDistance);
			void SetGotoWaypathStart(unsigned long waypathId, unsigned long waypathStartId, unsigned long waypathEndId, bool splined);
			void SetGotoWaypath(unsigned long waypathId, bool splined, bool attackActive, bool hold);
			void SetGotoWaypathId(unsigned long waypathId);
			void SetMoveArriveDistance(float distance);
			void SetBasic(IGameObjObserverClass ^script, float priority, int actionId, SoldierAIState aiState);
			void SetBasic(IGameObjObserverClass ^script, float priority, int actionId);
			void SetBasic(long observerId, float priority, int actionId, SoldierAIState aiState);
			void SetBasic(long observerId, float priority, int actionId);
			void SetLook(Vector3 location, float duration);
			void SetLook(IScriptableGameObj ^object, float duration);
			void SetLook(Vector3 objPos, float angle, float duration);
			void SetMovement(Vector3 location, float speed, float arrivedDistance, bool crouched);
			void SetMovement(Vector3 location, float speed, float arrivedDistance);
			void SetMovement(IScriptableGameObj ^object, float speed, float arrivedDistance, bool crouched);
			void SetMovement(IScriptableGameObj ^object, float speed, float arrivedDistance);
			void SetAttack(Vector3 location, float range, float error, bool primaryFire);
			void SetAttack(IScriptableGameObj ^object, float range, float error, bool primaryFire);
			void SetAnimation(String ^name, bool looping);
			void SetFaceLocation(Vector3 location, float duration);
			void SetFaceLocation(Vector3 objPos, float angle, float duration);
			void JoinConversation(int activeConversationId);
			void StartConversation(String ^name);
			void DockVehicle(Vector3 dockLocation, Vector3 dockEntrance);
	};

	public interface class IScriptFactory : public IUnmanagedObject
	{
		IUnmanagedContainer<IScriptImpClass ^> ^Create();

		property IntPtr ScriptFactoryPointer
		{
			IntPtr get();
		}

		property String ^Name
		{
			String ^get();
		}

		property String ^ParamDescription
		{
			String ^get();
		}
	};

	public ref class ScriptFactory : public AbstractUnmanagedObject, public IScriptFactory
	{
		public:
			ScriptFactory(IntPtr pointer);

			String ^ToString() override;
			bool Equals(Object ^other) override;

			virtual IUnmanagedContainer<IScriptImpClass ^> ^Create() sealed;

			property IntPtr ScriptFactoryPointer
			{
				virtual IntPtr get() sealed;
			}

			property String ^Name
			{
				virtual String ^get() sealed;
			}

			property String ^ParamDescription
			{
				virtual String ^get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::ScriptFactory *InternalScriptFactoryPointer
			{
				virtual ::ScriptFactory *get();
			}

			property IScriptFactory ^Next
			{
				IScriptFactory ^get();
				void set(IScriptFactory ^value);
			}
	};

	public ref class ScriptRegistrar abstract sealed
	{
		public:
			static void RegisterScript(IScriptFactory ^factory);
			static void UnregisterScript(IScriptFactory ^factory);
			static IUnmanagedContainer<IScriptImpClass ^> ^CreateScript(String ^name);
			static IScriptFactory ^GetScriptFactory(String ^name);
			static IScriptFactory ^GetScriptFactory(int index);

			static property int Count
			{
				int get();
			}
	};

	generic<typename T>
	where T : IScriptImpClass
	public interface class IScriptRegistrant : public IScriptFactory
	{
		
	};

	generic<typename T>
	where T : IScriptImpClass
	public ref class ScriptRegistrant : public ScriptFactory
	{
		public:
			ScriptRegistrant(IntPtr pointer)
				: ScriptFactory(pointer)
			{

			}
	};

	public interface class IScriptCommands : public IUnmanagedObject
	{
		void DebugMessage(String ^format, ...array<Object ^> ^args);

		void ActionReset(IScriptableGameObj ^obj, float priority);

		void ActionGoto(IScriptableGameObj ^obj, ActionParamsStruct ^params);

		void ActionGoto(IScriptableGameObj ^obj, IActionParamsStruct ^params);

		void ActionAttack(IScriptableGameObj ^obj, ActionParamsStruct ^params);

		void ActionAttack(IScriptableGameObj ^obj, IActionParamsStruct ^params);

		void ActionPlayAnimation(IScriptableGameObj ^obj, ActionParamsStruct ^params);

		void ActionPlayAnimation(IScriptableGameObj ^obj, IActionParamsStruct ^params);

		void ActionEnterExit(IScriptableGameObj ^obj, ActionParamsStruct ^params);

		void ActionEnterExit(IScriptableGameObj ^obj, IActionParamsStruct ^params);

		void ActionFaceLocation(IScriptableGameObj ^obj, ActionParamsStruct ^params);

		void ActionFaceLocation(IScriptableGameObj ^obj, IActionParamsStruct ^params);

		void ActionDock(IScriptableGameObj ^obj, ActionParamsStruct ^params);

		void ActionDock(IScriptableGameObj ^obj, IActionParamsStruct ^params);

		void ActionFollowInput(IScriptableGameObj ^obj, ActionParamsStruct ^params);

		void ActionFollowInput(IScriptableGameObj ^obj, IActionParamsStruct ^params);

		void ModifyAction(IScriptableGameObj ^obj, int actionID, ActionParamsStruct ^params, bool modifyMove, bool modifyAttack);

		void ModifyAction(IScriptableGameObj ^obj, int actionID, IActionParamsStruct ^params, bool modifyMove, bool modifyAttack);

		int GetActionID(IScriptableGameObj ^obj);

		bool GetActionParams(IScriptableGameObj ^obj, [Out] ActionParamsStruct ^%params);

		bool GetActionParams(IScriptableGameObj ^obj, IActionParamsStruct ^params);

		bool IsPerformingPathfindAction(IScriptableGameObj ^obj);

		void SetPosition(IScriptableGameObj ^obj, Vector3 position);

		Vector3 GetPosition(IScriptableGameObj ^obj);

		Vector3 GetBonePosition(IScriptableGameObj ^obj, String ^boneName);

		float GetFacing(IScriptableGameObj ^obj);

		void SetFacing(IScriptableGameObj ^obj, float degrees);

		void DisableAllCollisions(IScriptableGameObj ^obj);

		void DisablePhysicalCollisions(IScriptableGameObj ^obj);

		void EnableCollisions(IScriptableGameObj ^obj);

		void DestroyObject(IScriptableGameObj ^obj);

		IScriptableGameObj ^FindObject(int objId);

		IScriptableGameObj ^CreateObject(String ^typeName, Vector3 position);

		IScriptableGameObj ^CreateObjectAtBone(IScriptableGameObj ^hostObj, String ^newObjTypeName, String ^boneName);

		int GetID(IScriptableGameObj ^obj);

		int GetPresetID(IScriptableGameObj ^obj);

		String ^GetPresetName(IScriptableGameObj ^obj);

		void AttachScript(IScriptableGameObj ^object, String ^scriptName, String ^scriptParams, ...array<Object^>^ args);

		void AddToDirtyCullList(IScriptableGameObj ^object);

		void StartTimer(IScriptableGameObj ^obj, IScriptClass ^script, float duration, int timerId);

		void TriggerWeapon(IScriptableGameObj ^obj, bool trigger, Vector3 target, bool primary);

		void SelectWeapon(IScriptableGameObj ^obj, String ^weaponName);

		void SendCustomEvent(IScriptableGameObj ^from, IScriptableGameObj ^to, int type, int param, float delay);

		void SendDamagedEvent(IScriptableGameObj ^object, IScriptableGameObj ^damager);

		float GetRandom(float min, float max);

		int GetRandomInt(int min, int max);

		IScriptableGameObj ^FindRandomSimpleObject(String ^presetName);

		void SetModel(IScriptableGameObj ^obj, String ^modelName);

		void SetAnimation(IScriptableGameObj ^obj, String ^animName, bool looping, String ^subObjName, float startFrame, float endFrame, bool isBlended);

		void SetAnimationFrame(IScriptableGameObj ^obj, String ^animName, int frame);

		int CreateSound(String ^soundPresetName, Vector3 position, IScriptableGameObj ^creator);

		int Create2DSound(String ^soundPresetName);

		int Create2DWAVSound(String ^wavFilename);

		int Create3DWAVSoundAtBone(String ^wavFilename, IScriptableGameObj ^obj, String ^boneName);

		int Create3DSoundAtBone(String ^soundPresetName, IScriptableGameObj ^obj, String ^boneName);

		int CreateLogicalSound(IScriptableGameObj ^creator, int type, Vector3 position, float radius);

		void StartSound(int soundId);

		void StopSound(int soundId, bool destroySound);

		void MonitorSound(IScriptableGameObj ^obj, int soundId);

		void SetBackgroundMusic(String ^wavFilename);

		void FadeBackgroundMusic(String ^wavFilename, int fadeOutTime, int fadeInTime);

		void StopBackgroundMusic();

		float GetHealth(IScriptableGameObj ^obj);

		float GetMaxHealth(IScriptableGameObj ^obj);

		void SetHealth(IScriptableGameObj ^obj, float health);

		float GetShieldStrength(IScriptableGameObj ^obj);

		float GetMaxShieldStrength(IScriptableGameObj ^obj);

		void SetShieldStrength(IScriptableGameObj ^obj, float strength);

		void SetShieldType(IScriptableGameObj ^obj, String ^name);

		int GetPlayerType(IScriptableGameObj ^obj);

		void SetPlayerType(IScriptableGameObj ^obj, int type);

		float GetDistance(Vector3 p1, Vector3 p2);

		void SetCameraHost(IScriptableGameObj ^obj);

		void ForceCameraLook(Vector3 target);

		IScriptableGameObj ^GetTheStar();

		IScriptableGameObj ^GetAStar(Vector3 pos);

		IScriptableGameObj ^FindClosestSoldier(Vector3 pos, float minDist, float maxDist, bool onlyHuman);

		bool IsAStar(IScriptableGameObj ^obj);

		void ControlEnable(IScriptableGameObj ^obj, bool enable);

		String ^GetDamageBoneName();

		bool GetDamageBoneDirection();

		bool IsObjectVisible(IScriptableGameObj ^looker, IScriptableGameObj ^obj);

		void EnableEnemySeen(IScriptableGameObj ^obj, bool enable);

		void SetDisplayColor(System::Drawing::Color color);

		void DisplayText(int stringId);

		void DisplayFloat(float value, String ^format);

		void DisplayInt(int value, String ^format);

		void SaveData(IntPtr saver, int id, array<std::uint8_t> ^data);

		void SavePointer(IntPtr saver, int id, IntPtr pointer);

		bool LoadBegin(IntPtr loader, [Out] int %id);

		void LoadData(IntPtr loader, array<std::uint8_t> ^data);

		void LoadPointer(IntPtr loader, [Out] IntPtr %pointer);

		void LoadEnd(IntPtr loader);

		void BeginChunk(IntPtr saver, unsigned int chunkID);

		void EndChunk(IntPtr saver);

		bool OpenChunk(IntPtr loader, [Out] unsigned int %chunkID);

		void CloseChunk(IntPtr loader);

		void ClearRadarMarkers();

		void ClearRadarMarker(int id);

		void AddRadarMarker(int id, Vector3 position, int shapeType, int colorType);

		void SetObjRadarBlipShape(IScriptableGameObj ^obj, int shapeType);

		void SetObjRadarBlipColor(IScriptableGameObj ^obj, int colorType);

		void EnableRadar(bool enable);

		void ClearMapCell(int cellX, int cellY);

		void ClearMapCellByPos(Vector3 worldSpacePos);

		void ClearMapCellByPixelPos(int pixelPosX, int pixelPosY);

		void ClearMapRegionByPos(Vector3 worldSpacePos, int pixelRadius);

		void RevealMap();

		void ShroudMap();

		void ShowPlayerMapMarker(bool onoff);

		float GetSafeFlightHeight(float xPos, float yPos);

		void CreateExplosion(String ^explosionDefName, Vector3 pos, IScriptableGameObj ^creator);

		void CreateExplosionAtBone(String ^explosionDefName, IScriptableGameObj ^object, String ^boneName, IScriptableGameObj ^creator);

		void EnableHUD(bool enable);

		void MissionComplete(bool success);

		void GivePowerUp(IScriptableGameObj ^obj, String ^presetName, bool displayOnHUD);

		void InnateDisable(IScriptableGameObj ^object);

		void InnateEnable(IScriptableGameObj ^object);

		bool InnateSoldierEnableEnemySeen(IScriptableGameObj ^obj, bool state);

		bool InnateSoldierEnableGunshotHeard(IScriptableGameObj ^obj, bool state);

		bool InnateSoldierEnableFootstepsHeard(IScriptableGameObj ^obj, bool state);

		bool InnateSoldierEnableBulletHeard(IScriptableGameObj ^obj, bool state);

		bool InnateSoldierEnableActions(IScriptableGameObj ^obj, bool state);

		void SetInnateSoldierHomeLocation(IScriptableGameObj ^obj, Vector3 homePos, float homeRadius);

		void SetInnateAggressiveness(IScriptableGameObj ^obj, float aggressiveness);

		void SetInnateTakeCoverProbability(IScriptableGameObj ^obj, float probability);

		void SetInnateIsStationary(IScriptableGameObj ^obj, bool stationary);

		void InnateForceStateBulletHeard(IScriptableGameObj ^obj, Vector3 pos);

		void InnateForceStateFootstepsHeard(IScriptableGameObj ^obj, Vector3 pos);

		void InnateForceStateGunshotsHeard(IScriptableGameObj ^obj, Vector3 pos);

		void InnateForceStateEnemySeen(IScriptableGameObj ^obj, IScriptableGameObj ^enemy);

		void StaticAnimPhysGotoFrame(int objId, float frame, String ^animName);

		void StaticAnimPhysGotoLastFrame(int objId, String ^animName);

		unsigned int GetSyncTime();

		void AddObjective(int id, int type, int status, int shortDescriptionId, String ^descriptionSoundFilename, int longDescriptionId);

		void RemoveObjective(int id);

		void SetObjectiveStatus(int id, int status);

		void ChangeObjectiveType(int id, int type);

		void SetObjectiveRadarBlip(int id, Vector3 position);

		void SetObjectiveRadarBlipObject(int id, IScriptableGameObj ^unit);

		void SetObjectiveHUDInfo(int id, float priority, String ^textureName, int messageId);

		void SetObjectiveHUDInfoPosition(int id, float priority, String ^textureName, int messageId, Vector3 position);

		void ShakeCamera(Vector3 pos, float radius, float intensity, float duration);

		void EnableSpawner(int id, bool enable);

		IScriptableGameObj ^TriggerSpawner(int id);

		void EnableEngine(IScriptableGameObj ^object, bool onoff);

		int GetDifficultyLevel();

		void GrantKey(IScriptableGameObj ^object, int key, bool grant);

		bool HasKey(IScriptableGameObj ^object, int key);

		void EnableHibernation(IScriptableGameObj ^object, bool enable);

		void AttachToObjectBone(IScriptableGameObj ^object, IScriptableGameObj ^hostObject, String ^boneName);

		int CreateConversation(String ^conversationName, int priority, float maxDist, bool isInterruptable);

		void JoinConversation(IScriptableGameObj ^object, int activeConversationId, bool allowMove, bool allowHeadTurn, bool allowFace);

		void JoinConversationFacing(IScriptableGameObj ^object, int activeConversationId, int objIdToFace);

		void StartConversation(int activeConversationId, int actionID);

		void MonitorConversation(IScriptableGameObj ^object, int activeConversationId);

		void StartRandomConversation(IScriptableGameObj ^object);

		void StopConversation(int activeConversationId);

		void StopAllConversations();

		void LockSoldierFacing(IScriptableGameObj ^object, IScriptableGameObj ^objectToFace, bool turnBody);

		void UnlockSoldierFacing(IScriptableGameObj ^object);

		void ApplyDamage(IScriptableGameObj ^object, float amount, String ^warheadName, IScriptableGameObj ^damager);

		void SetLoitersAllowed(IScriptableGameObj ^object, bool allowed);

		void SetIsVisible(IScriptableGameObj ^object, bool visible);

		void SetIsRendered(IScriptableGameObj ^object, bool rendered);

		float GetPoints(IScriptableGameObj ^object);

		void GivePoints(IScriptableGameObj ^object, float points, bool entireTeam);

		float GetMoney(IScriptableGameObj ^object);

		void GiveMoney(IScriptableGameObj ^object, float money, bool entireTeam);

		bool GetBuildingPower(IScriptableGameObj ^object);

		void SetBuildingPower(IScriptableGameObj ^object, bool onoff);

		void PlayBuildingAnnouncement(IScriptableGameObj ^object, int textId);

		IScriptableGameObj ^FindNearestBuildingToPos(Vector3 position, String ^meshPrefix);

		IScriptableGameObj ^FindNearestBuilding(IScriptableGameObj ^object, String ^meshPrefix);

		int TeamMembersInZone(IScriptableGameObj ^object, int playerType);

		void SetClouds(float cloudCover, float cloudGloominess, float ramptime);

		void SetLightning(float intensity, float startDistance, float endDistance, float heading, float distribution, float ramptime);

		void SetWarBlitz(float intensity, float startDistance, float endDistance, float heading, float distribution, float ramptime);

		void SetWind(float heading, float speed, float variability, float ramptime);

		void SetRain(float density, float ramptime, bool prime);

		void SetSnow(float density, float ramptime, bool prime);

		void SetAsh(float density, float ramptime, bool prime);

		void SetFogEnable(bool enabled);

		void SetFogRange(float startDistance, float endDistance, float ramptime);

		void EnableStealth(IScriptableGameObj ^object, bool onoff);

		void CinematicSniperControl(bool enabled, float zoom);

		int TextFileOpen(String ^filename);

		String ^TextFileGetString(int handle);

		void TextFileClose(int handle);

		void EnableVehicleTransitions(IScriptableGameObj ^object, bool enable);

		void DisplayGDIPlayerTerminal();

		void DisplayNodPlayerTerminal();

		void DisplayMutantPlayerTerminal();

		bool RevealEncyclopediaCharacter(int objectId);

		bool RevealEncyclopediaWeapon(int objectId);

		bool RevealEncyclopediaVehicle(int objectId);

		bool RevealEncyclopediaBuilding(int objectId);

		void DisplayEncyclopediaEventUI();

		void ScaleAIAwareness(float sightScale, float hearingScale);

		void EnableCinematicFreeze(IScriptableGameObj ^object, bool enable);

		void ExpirePowerup(IScriptableGameObj ^object);

		void SetHUDHelpText(int stringId, Color color);

		void EnableHUDPokableIndicator(IScriptableGameObj ^object, bool enable);

		void EnableInnateConversations(IScriptableGameObj ^object, bool enable);

		void DisplayHealthBar(IScriptableGameObj ^object, bool display);

		void EnableShadow(IScriptableGameObj ^object, bool enable);

		void ClearWeapons(IScriptableGameObj ^object);

		void SetNumTertiaryObjectives(int count);

		void EnableLetterbox(bool onoff, float seconds);

		void SetScreenFadeColor(Color color, float seconds);

		void SetScreenFadeOpacity(float opacity, float seconds);

		property IntPtr ScriptCommandsPointer
		{
			IntPtr get();
		}

		property int Size
		{
			int get();
			void set(int value);
		}

		property int Version
		{
			int get();
			void set(int value);
		}

		property IntPtr DebugMessagePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ActionResetPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ActionGotoPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ActionAttackPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ActionPlayAnimationPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ActionEnterExitPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ActionFaceLocationPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ActionDockPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ActionFollowInputPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ModifyActionPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetActionIDPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetActionParamsPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr IsPerformingPathfindActionPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetPositionPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetPositionPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetBonePositionPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetFacingPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetFacingPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr DisableAllCollisionsPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr DisablePhysicalCollisionsPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr EnableCollisionsPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr DestroyObjectPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr FindObjectPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr CreateObjectPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr CreateObjectAtBonePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetIDPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetPresetIDPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetPresetNamePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr AttachScriptPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr AddToDirtyCullListPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr StartTimerPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr TriggerWeaponPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SelectWeaponPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SendCustomEventPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SendDamagedEventPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetRandomPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetRandomIntPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr FindRandomSimpleObjectPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetModelPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetAnimationPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetAnimationFramePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr CreateSoundPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr Create2DSoundPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr Create2DWAVSoundPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr Create3DWAVSoundAtBonePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr Create3DSoundAtBonePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr CreateLogicalSoundPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr StartSoundPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr StopSoundPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr MonitorSoundPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetBackgroundMusicPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr FadeBackgroundMusicPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr StopBackgroundMusicPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetHealthPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetMaxHealthPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetHealthPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetShieldStrengthPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetMaxShieldStrengthPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetShieldStrengthPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetShieldTypePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetPlayerTypePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetPlayerTypePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetDistancePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetCameraHostPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ForceCameraLookPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetTheStarPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetAStarPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr FindClosestSoldierPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr IsAStarPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ControlEnablePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetDamageBoneNamePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetDamageBoneDirectionPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr IsObjectVisiblePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr EnableEnemySeenPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetDisplayColorPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr DisplayTextPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr DisplayFloatPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr DisplayIntPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SaveDataPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SavePointerPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr LoadBeginPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr LoadDataPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr LoadPointerPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr LoadEndPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr BeginChunkPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr EndChunkPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr OpenChunkPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr CloseChunkPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ClearRadarMarkersPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ClearRadarMarkerPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr AddRadarMarkerPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetObjRadarBlipShapePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetObjRadarBlipColorPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr EnableRadarPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ClearMapCellPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ClearMapCellByPosPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ClearMapCellByPixelPosPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ClearMapRegionByPosPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr RevealMapPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ShroudMapPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ShowPlayerMapMarkerPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetSafeFlightHeightPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr CreateExplosionPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr CreateExplosionAtBonePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr EnableHUDPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr MissionCompletePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GivePowerUpPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr InnateDisablePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr InnateEnablePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr InnateSoldierEnableEnemySeenPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr InnateSoldierEnableGunshotHeardPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr InnateSoldierEnableFootstepsHeardPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr InnateSoldierEnableBulletHeardPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr InnateSoldierEnableActionsPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetInnateSoldierHomeLocationPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetInnateAggressivenessPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetInnateTakeCoverProbabilityPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetInnateIsStationaryPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr InnateForceStateBulletHeardPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr InnateForceStateFootstepsHeardPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr InnateForceStateGunshotsHeardPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr InnateForceStateEnemySeenPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr StaticAnimPhysGotoFramePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr StaticAnimPhysGotoLastFramePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetSyncTimePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr AddObjectivePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr RemoveObjectivePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetObjectiveStatusPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ChangeObjectiveTypePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetObjectiveRadarBlipPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetObjectiveRadarBlipObjectPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetObjectiveHUDInfoPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetObjectiveHUDInfoPositionPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ShakeCameraPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr EnableSpawnerPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr TriggerSpawnerPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr EnableEnginePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetDifficultyLevelPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GrantKeyPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr HasKeyPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr EnableHibernationPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr AttachToObjectBonePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr CreateConversationPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr JoinConversationPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr JoinConversationFacingPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr StartConversationPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr MonitorConversationPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr StartRandomConversationPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr StopConversationPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr StopAllConversationsPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr LockSoldierFacingPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr UnlockSoldierFacingPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ApplyDamagePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetLoitersAllowedPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetIsVisiblePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetIsRenderedPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetPointsPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GivePointsPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetMoneyPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GiveMoneyPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr GetBuildingPowerPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetBuildingPowerPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr PlayBuildingAnnouncementPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr FindNearestBuildingToPosPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr FindNearestBuildingPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr TeamMembersInZonePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetCloudsPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetLightningPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetWarBlitzPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetWindPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetRainPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetSnowPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetAshPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetFogEnablePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetFogRangePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr EnableStealthPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr CinematicSniperControlPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr TextFileOpenPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr TextFileGetStringPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr TextFileClosePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr EnableVehicleTransitionsPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr DisplayGDIPlayerTerminalPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr DisplayNodPlayerTerminalPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr DisplayMutantPlayerTerminalPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr RevealEncyclopediaCharacterPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr RevealEncyclopediaWeaponPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr RevealEncyclopediaVehiclePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr RevealEncyclopediaBuildingPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr DisplayEncyclopediaEventUIPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ScaleAIAwarenessPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr EnableCinematicFreezePointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ExpirePowerupPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetHUDHelpTextPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr EnableHUDPokableIndicatorPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr EnableInnateConversationsPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr DisplayHealthBarPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr EnableShadowPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr ClearWeaponsPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetNumTertiaryObjectivesPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr EnableLetterboxPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetScreenFadeColorPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IntPtr SetScreenFadeOpacityPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}
	};

	public ref class ScriptCommands : public AbstractUnmanagedObject, public IScriptCommands
	{
		private:
			ScriptCommands();

		public:
			ScriptCommands(IntPtr pointer);

			static IUnmanagedContainer<IScriptCommands ^> ^CreateScriptCommands();

			bool Equals(Object ^other) override;

			virtual void DebugMessage(String ^format, ...array<Object ^> ^args) sealed;
			virtual void ActionReset(IScriptableGameObj ^obj, float priority) sealed;
			virtual void ActionGoto(IScriptableGameObj ^obj, ActionParamsStruct ^params) sealed;
			virtual void ActionGoto(IScriptableGameObj ^obj, IActionParamsStruct ^params) sealed;
			virtual void ActionAttack(IScriptableGameObj ^obj, ActionParamsStruct ^params) sealed;
			virtual void ActionAttack(IScriptableGameObj ^obj, IActionParamsStruct ^params) sealed;
			virtual void ActionPlayAnimation(IScriptableGameObj ^obj, ActionParamsStruct ^params) sealed;
			virtual void ActionPlayAnimation(IScriptableGameObj ^obj, IActionParamsStruct ^params) sealed;
			virtual void ActionEnterExit(IScriptableGameObj ^obj, ActionParamsStruct ^params) sealed;
			virtual void ActionEnterExit(IScriptableGameObj ^obj, IActionParamsStruct ^params) sealed;
			virtual void ActionFaceLocation(IScriptableGameObj ^obj, ActionParamsStruct ^params) sealed;
			virtual void ActionFaceLocation(IScriptableGameObj ^obj, IActionParamsStruct ^params) sealed;
			virtual void ActionDock(IScriptableGameObj ^obj, ActionParamsStruct ^params) sealed;
			virtual void ActionDock(IScriptableGameObj ^obj, IActionParamsStruct ^params) sealed;
			virtual void ActionFollowInput(IScriptableGameObj ^obj, ActionParamsStruct ^params) sealed;
			virtual void ActionFollowInput(IScriptableGameObj ^obj, IActionParamsStruct ^params) sealed;
			virtual void ModifyAction(IScriptableGameObj ^obj, int actionID, ActionParamsStruct ^params, bool modifyMove, bool modifyAttack) sealed;
			virtual void ModifyAction(IScriptableGameObj ^obj, int actionID, IActionParamsStruct ^params, bool modifyMove, bool modifyAttack) sealed;
			virtual int GetActionID(IScriptableGameObj ^obj) sealed;
			virtual bool GetActionParams(IScriptableGameObj ^obj, [Out] ActionParamsStruct ^%params) sealed;
			virtual bool GetActionParams(IScriptableGameObj ^obj, IActionParamsStruct ^params) sealed;
			virtual bool IsPerformingPathfindAction(IScriptableGameObj ^obj) sealed;
			virtual void SetPosition(IScriptableGameObj ^obj, Vector3 position) sealed;
			virtual Vector3 GetPosition(IScriptableGameObj ^obj) sealed;
			virtual Vector3 GetBonePosition(IScriptableGameObj ^obj, String ^boneName) sealed;
			virtual float GetFacing(IScriptableGameObj ^obj) sealed;
			virtual void SetFacing(IScriptableGameObj ^obj, float degrees) sealed;
			virtual void DisableAllCollisions(IScriptableGameObj ^obj) sealed;
			virtual void DisablePhysicalCollisions(IScriptableGameObj ^obj) sealed;
			virtual void EnableCollisions(IScriptableGameObj ^obj) sealed;
			virtual void DestroyObject(IScriptableGameObj ^obj) sealed;
			virtual IScriptableGameObj ^FindObject(int objId) sealed;
			virtual IScriptableGameObj ^CreateObject(String ^typeName, Vector3 position) sealed;
			virtual IScriptableGameObj ^CreateObjectAtBone(IScriptableGameObj ^hostObj, String ^newObjTypeName, String ^boneName) sealed;
			virtual int GetID(IScriptableGameObj ^obj) sealed;
			virtual int GetPresetID(IScriptableGameObj ^obj) sealed;
			virtual String ^GetPresetName(IScriptableGameObj ^obj) sealed;
			virtual void AttachScript(IScriptableGameObj ^object, String ^scriptName, String ^scriptParams, ...array<Object^>^ args) sealed;
			virtual void AddToDirtyCullList(IScriptableGameObj ^object) sealed;
			virtual void StartTimer(IScriptableGameObj ^obj, IScriptClass ^script, float duration, int timerId) sealed;
			virtual void TriggerWeapon(IScriptableGameObj ^obj, bool trigger, Vector3 target, bool primary) sealed;
			virtual void SelectWeapon(IScriptableGameObj ^obj, String ^weaponName) sealed;
			virtual void SendCustomEvent(IScriptableGameObj ^from, IScriptableGameObj ^to, int type, int param, float delay) sealed;
			virtual void SendDamagedEvent(IScriptableGameObj ^object, IScriptableGameObj ^damager) sealed;
			virtual float GetRandom(float min, float max) sealed;
			virtual int GetRandomInt(int min, int max) sealed;
			virtual IScriptableGameObj ^FindRandomSimpleObject(String ^presetName) sealed;
			virtual void SetModel(IScriptableGameObj ^obj, String ^modelName) sealed;
			virtual void SetAnimation(IScriptableGameObj ^obj, String ^animName, bool looping, String ^subObjName, float startFrame, float endFrame, bool isBlended) sealed;
			virtual void SetAnimationFrame(IScriptableGameObj ^obj, String ^animName, int frame) sealed;
			virtual int CreateSound(String ^soundPresetName, Vector3 position, IScriptableGameObj ^creator) sealed;
			virtual int Create2DSound(String ^soundPresetName) sealed;
			virtual int Create2DWAVSound(String ^wavFilename) sealed;
			virtual int Create3DWAVSoundAtBone(String ^wavFilename, IScriptableGameObj ^obj, String ^boneName) sealed;
			virtual int Create3DSoundAtBone(String ^soundPresetName, IScriptableGameObj ^obj, String ^boneName) sealed;
			virtual int CreateLogicalSound(IScriptableGameObj ^creator, int type, Vector3 position, float radius) sealed;
			virtual void StartSound(int soundId) sealed;
			virtual void StopSound(int soundId, bool destroySound) sealed;
			virtual void MonitorSound(IScriptableGameObj ^obj, int soundId) sealed;
			virtual void SetBackgroundMusic(String ^wavFilename) sealed;
			virtual void FadeBackgroundMusic(String ^wavFilename, int fadeOutTime, int fadeInTime) sealed;
			virtual void StopBackgroundMusic() sealed;
			virtual float GetHealth(IScriptableGameObj ^obj) sealed;
			virtual float GetMaxHealth(IScriptableGameObj ^obj) sealed;
			virtual void SetHealth(IScriptableGameObj ^obj, float health) sealed;
			virtual float GetShieldStrength(IScriptableGameObj ^obj) sealed;
			virtual float GetMaxShieldStrength(IScriptableGameObj ^obj) sealed;
			virtual void SetShieldStrength(IScriptableGameObj ^obj, float strength) sealed;
			virtual void SetShieldType(IScriptableGameObj ^obj, String ^name) sealed;
			virtual int GetPlayerType(IScriptableGameObj ^obj) sealed;
			virtual void SetPlayerType(IScriptableGameObj ^obj, int type) sealed;
			virtual float GetDistance(Vector3 p1, Vector3 p2) sealed;
			virtual void SetCameraHost(IScriptableGameObj ^obj) sealed;
			virtual void ForceCameraLook(Vector3 target) sealed;
			virtual IScriptableGameObj ^GetTheStar() sealed;
			virtual IScriptableGameObj ^GetAStar(Vector3 pos) sealed;
			virtual IScriptableGameObj ^FindClosestSoldier(Vector3 pos, float minDist, float maxDist, bool onlyHuman) sealed;
			virtual bool IsAStar(IScriptableGameObj ^obj) sealed;
			virtual void ControlEnable(IScriptableGameObj ^obj, bool enable) sealed;
			virtual String ^GetDamageBoneName() sealed;
			virtual bool GetDamageBoneDirection() sealed;
			virtual bool IsObjectVisible(IScriptableGameObj ^looker, IScriptableGameObj ^obj) sealed;
			virtual void EnableEnemySeen(IScriptableGameObj ^obj, bool enable) sealed;
			virtual void SetDisplayColor(System::Drawing::Color color) sealed;
			virtual void DisplayText(int stringId) sealed;
			virtual void DisplayFloat(float value, String ^format) sealed;
			virtual void DisplayInt(int value, String ^format) sealed;
			virtual void SaveData(IntPtr saver, int id, array<std::uint8_t> ^data) sealed;
			virtual void SavePointer(IntPtr saver, int id, IntPtr pointer) sealed;
			virtual bool LoadBegin(IntPtr loader, [Out] int %id) sealed;
			virtual void LoadData(IntPtr loader, array<std::uint8_t> ^data) sealed;
			virtual void LoadPointer(IntPtr loader, [Out] IntPtr %pointer) sealed;
			virtual void LoadEnd(IntPtr loader) sealed;
			virtual void BeginChunk(IntPtr saver, unsigned int chunkID) sealed;
			virtual void EndChunk(IntPtr saver) sealed;
			virtual bool OpenChunk(IntPtr loader, [Out] unsigned int %chunkID) sealed;
			virtual void CloseChunk(IntPtr loader) sealed;
			virtual void ClearRadarMarkers() sealed;
			virtual void ClearRadarMarker(int id) sealed;
			virtual void AddRadarMarker(int id, Vector3 position, int shapeType, int colorType) sealed;
			virtual void SetObjRadarBlipShape(IScriptableGameObj ^obj, int shapeType) sealed;
			virtual void SetObjRadarBlipColor(IScriptableGameObj ^obj, int colorType) sealed;
			virtual void EnableRadar(bool enable) sealed;
			virtual void ClearMapCell(int cellX, int cellY) sealed;
			virtual void ClearMapCellByPos(Vector3 worldSpacePos) sealed;
			virtual void ClearMapCellByPixelPos(int pixelPosX, int pixelPosY) sealed;
			virtual void ClearMapRegionByPos(Vector3 worldSpacePos, int pixelRadius) sealed;
			virtual void RevealMap() sealed;
			virtual void ShroudMap() sealed;
			virtual void ShowPlayerMapMarker(bool onoff) sealed;
			virtual float GetSafeFlightHeight(float xPos, float yPos) sealed;
			virtual void CreateExplosion(String ^explosionDefName, Vector3 pos, IScriptableGameObj ^creator) sealed;
			virtual void CreateExplosionAtBone(String ^explosionDefName, IScriptableGameObj ^object, String ^boneName, IScriptableGameObj ^creator) sealed;
			virtual void EnableHUD(bool enable) sealed;
			virtual void MissionComplete(bool success) sealed;
			virtual void GivePowerUp(IScriptableGameObj ^obj, String ^presetName, bool displayOnHUD) sealed;
			virtual void InnateDisable(IScriptableGameObj ^object) sealed;
			virtual void InnateEnable(IScriptableGameObj ^object) sealed;
			virtual bool InnateSoldierEnableEnemySeen(IScriptableGameObj ^obj, bool state) sealed;
			virtual bool InnateSoldierEnableGunshotHeard(IScriptableGameObj ^obj, bool state) sealed;
			virtual bool InnateSoldierEnableFootstepsHeard(IScriptableGameObj ^obj, bool state) sealed;
			virtual bool InnateSoldierEnableBulletHeard(IScriptableGameObj ^obj, bool state) sealed;
			virtual bool InnateSoldierEnableActions(IScriptableGameObj ^obj, bool state) sealed;
			virtual void SetInnateSoldierHomeLocation(IScriptableGameObj ^obj, Vector3 homePos, float homeRadius) sealed;
			virtual void SetInnateAggressiveness(IScriptableGameObj ^obj, float aggressiveness) sealed;
			virtual void SetInnateTakeCoverProbability(IScriptableGameObj ^obj, float probability) sealed;
			virtual void SetInnateIsStationary(IScriptableGameObj ^obj, bool stationary);
			virtual void InnateForceStateBulletHeard(IScriptableGameObj ^obj, Vector3 pos) sealed;
			virtual void InnateForceStateFootstepsHeard(IScriptableGameObj ^obj, Vector3 pos) sealed;
			virtual void InnateForceStateGunshotsHeard(IScriptableGameObj ^obj, Vector3 pos) sealed;
			virtual void InnateForceStateEnemySeen(IScriptableGameObj ^obj, IScriptableGameObj ^enemy) sealed;
			virtual void StaticAnimPhysGotoFrame(int objId, float frame, String ^animName) sealed;
			virtual void StaticAnimPhysGotoLastFrame(int objId, String ^animName) sealed;
			virtual unsigned int GetSyncTime() sealed;
			virtual void AddObjective(int id, int type, int status, int shortDescriptionId, String ^descriptionSoundFilename, int longDescriptionId) sealed;
			virtual void RemoveObjective(int id) sealed;
			virtual void SetObjectiveStatus(int id, int status) sealed;
			virtual void ChangeObjectiveType(int id, int type) sealed;
			virtual void SetObjectiveRadarBlip(int id, Vector3 position) sealed;
			virtual void SetObjectiveRadarBlipObject(int id, IScriptableGameObj ^unit) sealed;
			virtual void SetObjectiveHUDInfo(int id, float priority, String ^textureName, int messageId) sealed;
			virtual void SetObjectiveHUDInfoPosition(int id, float priority, String ^textureName, int messageId, Vector3 position) sealed;
			virtual void ShakeCamera(Vector3 pos, float radius, float intensity, float duration) sealed;
			virtual void EnableSpawner(int id, bool enable) sealed;
			virtual IScriptableGameObj ^TriggerSpawner(int id) sealed;
			virtual void EnableEngine(IScriptableGameObj ^object, bool onoff) sealed;
			virtual int GetDifficultyLevel() sealed;
			virtual void GrantKey(IScriptableGameObj ^object, int key, bool grant) sealed;
			virtual bool HasKey(IScriptableGameObj ^object, int key) sealed;
			virtual void EnableHibernation(IScriptableGameObj ^object, bool enable) sealed;
			virtual void AttachToObjectBone(IScriptableGameObj ^object, IScriptableGameObj ^hostObject, String ^boneName) sealed;
			virtual int CreateConversation(String ^conversationName, int priority, float maxDist, bool isInterruptable) sealed;
			virtual void JoinConversation(IScriptableGameObj ^object, int activeConversationId, bool allowMove, bool allowHeadTurn, bool allowFace) sealed;
			virtual void JoinConversationFacing(IScriptableGameObj ^object, int activeConversationId, int objIdToFace) sealed;
			virtual void StartConversation(int activeConversationId, int actionID) sealed;
			virtual void MonitorConversation(IScriptableGameObj ^object, int activeConversationId) sealed;
			virtual void StartRandomConversation(IScriptableGameObj ^object) sealed;
			virtual void StopConversation(int activeConversationId) sealed;
			virtual void StopAllConversations() sealed;
			virtual void LockSoldierFacing(IScriptableGameObj ^object, IScriptableGameObj ^objectToFace, bool turnBody) sealed;
			virtual void UnlockSoldierFacing(IScriptableGameObj ^object) sealed;
			virtual void ApplyDamage(IScriptableGameObj ^object, float amount, String ^warheadName, IScriptableGameObj ^damager) sealed;
			virtual void SetLoitersAllowed(IScriptableGameObj ^object, bool allowed) sealed;
			virtual void SetIsVisible(IScriptableGameObj ^object, bool visible) sealed;
			virtual void SetIsRendered(IScriptableGameObj ^object, bool rendered) sealed;
			virtual float GetPoints(IScriptableGameObj ^object) sealed;
			virtual void GivePoints(IScriptableGameObj ^object, float points, bool entireTeam) sealed;
			virtual float GetMoney(IScriptableGameObj ^object) sealed;
			virtual void GiveMoney(IScriptableGameObj ^object, float money, bool entireTeam) sealed;
			virtual bool GetBuildingPower(IScriptableGameObj ^object) sealed;
			virtual void SetBuildingPower(IScriptableGameObj ^object, bool onoff) sealed;
			virtual void PlayBuildingAnnouncement(IScriptableGameObj ^object, int textId) sealed;
			virtual IScriptableGameObj ^FindNearestBuildingToPos(Vector3 position, String ^meshPrefix) sealed;
			virtual IScriptableGameObj ^FindNearestBuilding(IScriptableGameObj ^object, String ^meshPrefix) sealed;
			virtual int TeamMembersInZone(IScriptableGameObj ^object, int playerType) sealed;
			virtual void SetClouds(float cloudCover, float cloudGloominess, float ramptime) sealed;
			virtual void SetLightning(float intensity, float startDistance, float endDistance, float heading, float distribution, float ramptime) sealed;
			virtual void SetWarBlitz(float intensity, float startDistance, float endDistance, float heading, float distribution, float ramptime) sealed;
			virtual void SetWind(float heading, float speed, float variability, float ramptime) sealed;
			virtual void SetRain(float density, float ramptime, bool prime) sealed;
			virtual void SetSnow(float density, float ramptime, bool prime) sealed;
			virtual void SetAsh(float density, float ramptime, bool prime) sealed;
			virtual void SetFogEnable(bool enabled) sealed;
			virtual void SetFogRange(float startDistance, float endDistance, float ramptime) sealed;
			virtual void EnableStealth(IScriptableGameObj ^object, bool onoff) sealed;
			virtual void CinematicSniperControl(bool enabled, float zoom) sealed;
			virtual int TextFileOpen(String ^filename) sealed;
			virtual String ^TextFileGetString(int handle) sealed;
			virtual void TextFileClose(int handle) sealed;
			virtual void EnableVehicleTransitions(IScriptableGameObj ^object, bool enable) sealed;
			virtual void DisplayGDIPlayerTerminal() sealed;
			virtual void DisplayNodPlayerTerminal() sealed;
			virtual void DisplayMutantPlayerTerminal() sealed;
			virtual bool RevealEncyclopediaCharacter(int objectId) sealed;
			virtual bool RevealEncyclopediaWeapon(int objectId) sealed;
			virtual bool RevealEncyclopediaVehicle(int objectId) sealed;
			virtual bool RevealEncyclopediaBuilding(int objectId) sealed;
			virtual void DisplayEncyclopediaEventUI() sealed;
			virtual void ScaleAIAwareness(float sightScale, float hearingScale) sealed;
			virtual void EnableCinematicFreeze(IScriptableGameObj ^object, bool enable) sealed;
			virtual void ExpirePowerup(IScriptableGameObj ^object) sealed;
			virtual void SetHUDHelpText(int stringId, Color color) sealed;
			virtual void EnableHUDPokableIndicator(IScriptableGameObj ^object, bool enable) sealed;
			virtual void EnableInnateConversations(IScriptableGameObj ^object, bool enable) sealed;
			virtual void DisplayHealthBar(IScriptableGameObj ^object, bool display) sealed;
			virtual void EnableShadow(IScriptableGameObj ^object, bool enable) sealed;
			virtual void ClearWeapons(IScriptableGameObj ^object) sealed;
			virtual void SetNumTertiaryObjectives(int count) sealed;
			virtual void EnableLetterbox(bool onoff, float seconds) sealed;
			virtual void SetScreenFadeColor(Color color, float seconds) sealed;
			virtual void SetScreenFadeOpacity(float opacity, float seconds) sealed;

			property IntPtr ScriptCommandsPointer
			{
				virtual IntPtr get() sealed;
			}

			property int Size
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int Version
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property IntPtr DebugMessagePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ActionResetPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ActionGotoPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ActionAttackPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ActionPlayAnimationPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ActionEnterExitPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ActionFaceLocationPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ActionDockPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ActionFollowInputPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ModifyActionPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetActionIDPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetActionParamsPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr IsPerformingPathfindActionPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetPositionPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetPositionPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetBonePositionPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetFacingPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetFacingPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr DisableAllCollisionsPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr DisablePhysicalCollisionsPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr EnableCollisionsPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr DestroyObjectPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr FindObjectPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr CreateObjectPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr CreateObjectAtBonePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetIDPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetPresetIDPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetPresetNamePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr AttachScriptPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr AddToDirtyCullListPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr StartTimerPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr TriggerWeaponPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SelectWeaponPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SendCustomEventPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SendDamagedEventPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetRandomPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetRandomIntPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr FindRandomSimpleObjectPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetModelPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetAnimationPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetAnimationFramePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr CreateSoundPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr Create2DSoundPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr Create2DWAVSoundPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr Create3DWAVSoundAtBonePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr Create3DSoundAtBonePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr CreateLogicalSoundPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr StartSoundPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr StopSoundPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr MonitorSoundPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetBackgroundMusicPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr FadeBackgroundMusicPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr StopBackgroundMusicPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetHealthPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetMaxHealthPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetHealthPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetShieldStrengthPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetMaxShieldStrengthPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetShieldStrengthPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetShieldTypePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetPlayerTypePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetPlayerTypePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetDistancePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetCameraHostPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ForceCameraLookPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetTheStarPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetAStarPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr FindClosestSoldierPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr IsAStarPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ControlEnablePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetDamageBoneNamePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetDamageBoneDirectionPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr IsObjectVisiblePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr EnableEnemySeenPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetDisplayColorPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr DisplayTextPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr DisplayFloatPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr DisplayIntPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SaveDataPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SavePointerPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr LoadBeginPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr LoadDataPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr LoadPointerPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr LoadEndPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr BeginChunkPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr EndChunkPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr OpenChunkPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr CloseChunkPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ClearRadarMarkersPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ClearRadarMarkerPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr AddRadarMarkerPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetObjRadarBlipShapePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetObjRadarBlipColorPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr EnableRadarPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ClearMapCellPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ClearMapCellByPosPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ClearMapCellByPixelPosPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ClearMapRegionByPosPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr RevealMapPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ShroudMapPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ShowPlayerMapMarkerPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetSafeFlightHeightPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr CreateExplosionPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr CreateExplosionAtBonePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr EnableHUDPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr MissionCompletePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GivePowerUpPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr InnateDisablePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr InnateEnablePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr InnateSoldierEnableEnemySeenPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr InnateSoldierEnableGunshotHeardPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr InnateSoldierEnableFootstepsHeardPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr InnateSoldierEnableBulletHeardPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr InnateSoldierEnableActionsPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetInnateSoldierHomeLocationPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetInnateAggressivenessPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetInnateTakeCoverProbabilityPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetInnateIsStationaryPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr InnateForceStateBulletHeardPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr InnateForceStateFootstepsHeardPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr InnateForceStateGunshotsHeardPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr InnateForceStateEnemySeenPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr StaticAnimPhysGotoFramePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr StaticAnimPhysGotoLastFramePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetSyncTimePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr AddObjectivePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr RemoveObjectivePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetObjectiveStatusPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ChangeObjectiveTypePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetObjectiveRadarBlipPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetObjectiveRadarBlipObjectPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetObjectiveHUDInfoPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetObjectiveHUDInfoPositionPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ShakeCameraPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr EnableSpawnerPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr TriggerSpawnerPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr EnableEnginePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetDifficultyLevelPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GrantKeyPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr HasKeyPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr EnableHibernationPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr AttachToObjectBonePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr CreateConversationPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr JoinConversationPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr JoinConversationFacingPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr StartConversationPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr MonitorConversationPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr StartRandomConversationPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr StopConversationPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr StopAllConversationsPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr LockSoldierFacingPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr UnlockSoldierFacingPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ApplyDamagePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetLoitersAllowedPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetIsVisiblePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetIsRenderedPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetPointsPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GivePointsPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetMoneyPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GiveMoneyPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr GetBuildingPowerPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetBuildingPowerPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr PlayBuildingAnnouncementPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr FindNearestBuildingToPosPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr FindNearestBuildingPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr TeamMembersInZonePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetCloudsPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetLightningPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetWarBlitzPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetWindPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetRainPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetSnowPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetAshPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetFogEnablePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetFogRangePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr EnableStealthPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr CinematicSniperControlPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr TextFileOpenPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr TextFileGetStringPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr TextFileClosePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr EnableVehicleTransitionsPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr DisplayGDIPlayerTerminalPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr DisplayNodPlayerTerminalPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr DisplayMutantPlayerTerminalPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr RevealEncyclopediaCharacterPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr RevealEncyclopediaWeaponPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr RevealEncyclopediaVehiclePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr RevealEncyclopediaBuildingPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr DisplayEncyclopediaEventUIPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ScaleAIAwarenessPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr EnableCinematicFreezePointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ExpirePowerupPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetHUDHelpTextPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr EnableHUDPokableIndicatorPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr EnableInnateConversationsPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr DisplayHealthBarPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr EnableShadowPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr ClearWeaponsPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetNumTertiaryObjectivesPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr EnableLetterboxPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetScreenFadeColorPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr SetScreenFadeOpacityPointer
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::ScriptCommands *InternalScriptCommandsPointer
			{
				virtual ::ScriptCommands *get();
			}
	};

	public ref class Commands abstract sealed
	{
		public:
			static void DebugMessage(String ^format, ...array<Object ^> ^args);
			static void ActionReset(IScriptableGameObj ^obj, float priority);
			static void ActionGoto(IScriptableGameObj ^obj, ActionParamsStruct ^params);
			static void ActionGoto(IScriptableGameObj ^obj, IActionParamsStruct ^params);
			static void ActionAttack(IScriptableGameObj ^obj, ActionParamsStruct ^params);
			static void ActionAttack(IScriptableGameObj ^obj, IActionParamsStruct ^params);
			static void ActionPlayAnimation(IScriptableGameObj ^obj, ActionParamsStruct ^params);
			static void ActionPlayAnimation(IScriptableGameObj ^obj, IActionParamsStruct ^params);
			static void ActionEnterExit(IScriptableGameObj ^obj, ActionParamsStruct ^params);
			static void ActionEnterExit(IScriptableGameObj ^obj, IActionParamsStruct ^params);
			static void ActionFaceLocation(IScriptableGameObj ^obj, ActionParamsStruct ^params);
			static void ActionFaceLocation(IScriptableGameObj ^obj, IActionParamsStruct ^params);
			static void ActionDock(IScriptableGameObj ^obj, ActionParamsStruct ^params);
			static void ActionDock(IScriptableGameObj ^obj, IActionParamsStruct ^params);
			static void ActionFollowInput(IScriptableGameObj ^obj, ActionParamsStruct ^params);
			static void ActionFollowInput(IScriptableGameObj ^obj, IActionParamsStruct ^params);
			static void ModifyAction(IScriptableGameObj ^obj, int actionID, ActionParamsStruct ^params, bool modifyMove, bool modifyAttack);
			static void ModifyAction(IScriptableGameObj ^obj, int actionID, IActionParamsStruct ^params, bool modifyMove, bool modifyAttack);
			static int GetActionID(IScriptableGameObj ^obj);
			static bool GetActionParams(IScriptableGameObj ^obj, [Out] ActionParamsStruct ^%params);
			static bool GetActionParams(IScriptableGameObj ^obj, IActionParamsStruct ^params);
			static bool IsPerformingPathfindAction(IScriptableGameObj ^obj);
			static void SetPosition(IScriptableGameObj ^obj, Vector3 position);
			static Vector3 GetPosition(IScriptableGameObj ^obj);
			static Vector3 GetBonePosition(IScriptableGameObj ^obj, String ^boneName);
			static float GetFacing(IScriptableGameObj ^obj);
			static void SetFacing(IScriptableGameObj ^obj, float degrees);
			static void DisableAllCollisions(IScriptableGameObj ^obj);
			static void DisablePhysicalCollisions(IScriptableGameObj ^obj);
			static void EnableCollisions(IScriptableGameObj ^obj);
			static void DestroyObject(IScriptableGameObj ^obj);
			static IScriptableGameObj ^FindObject(int objId);
			static IScriptableGameObj ^CreateObject(String ^typeName, Vector3 position);
			static IScriptableGameObj ^CreateObjectAtBone(IScriptableGameObj ^hostObj, String ^newObjTypeName, String ^boneName);
			static int GetID(IScriptableGameObj ^obj);
			static int GetPresetID(IScriptableGameObj ^obj);
			static String ^GetPresetName(IScriptableGameObj ^obj);
			static void AttachScript(IScriptableGameObj ^object, String ^scriptName, String ^scriptParams, ...array<Object^>^ args);
			static void AddToDirtyCullList(IScriptableGameObj ^object);
			static void StartTimer(IScriptableGameObj ^obj, IScriptClass ^script, float duration, int timerId);
			static void TriggerWeapon(IScriptableGameObj ^obj, bool trigger, Vector3 target, bool primary);
			static void SelectWeapon(IScriptableGameObj ^obj, String ^weaponName);
			static void SendCustomEvent(IScriptableGameObj ^from, IScriptableGameObj ^to, int type, int param, float delay);
			static void SendDamagedEvent(IScriptableGameObj ^object, IScriptableGameObj ^damager);
			static float GetRandom(float min, float max);
			static int GetRandomInt(int min, int max);
			static IScriptableGameObj ^FindRandomSimpleObject(String ^presetName);
			static void SetModel(IScriptableGameObj ^obj, String ^modelName);
			static void SetAnimation(IScriptableGameObj ^obj, String ^animName, bool looping, String ^subObjName, float startFrame, float endFrame, bool isBlended);
			static void SetAnimationFrame(IScriptableGameObj ^obj, String ^animName, int frame);
			static int CreateSound(String ^soundPresetName, Vector3 position, IScriptableGameObj ^creator);
			static int Create2DSound(String ^soundPresetName);
			static int Create2DWAVSound(String ^wavFilename);
			static int Create3DWAVSoundAtBone(String ^wavFilename, IScriptableGameObj ^obj, String ^boneName);
			static int Create3DSoundAtBone(String ^soundPresetName, IScriptableGameObj ^obj, String ^boneName);
			static int CreateLogicalSound(IScriptableGameObj ^creator, int type, Vector3 position, float radius);
			static void StartSound(int soundId);
			static void StopSound(int soundId, bool destroySound);
			static void MonitorSound(IScriptableGameObj ^obj, int soundId);
			static void SetBackgroundMusic(String ^wavFilename);
			static void FadeBackgroundMusic(String ^wavFilename, int fadeOutTime, int fadeInTime);
			static void StopBackgroundMusic();
			static float GetHealth(IScriptableGameObj ^obj);
			static float GetMaxHealth(IScriptableGameObj ^obj);
			static void SetHealth(IScriptableGameObj ^obj, float health);
			static float GetShieldStrength(IScriptableGameObj ^obj);
			static float GetMaxShieldStrength(IScriptableGameObj ^obj);
			static void SetShieldStrength(IScriptableGameObj ^obj, float strength);
			static void SetShieldType(IScriptableGameObj ^obj, String ^name);
			static int GetPlayerType(IScriptableGameObj ^obj);
			static void SetPlayerType(IScriptableGameObj ^obj, int type);
			static float GetDistance(Vector3 p1, Vector3 p2);
			static void SetCameraHost(IScriptableGameObj ^obj);
			static void ForceCameraLook(Vector3 target);
			static IScriptableGameObj ^GetTheStar();
			static IScriptableGameObj ^GetAStar(Vector3 pos);
			static IScriptableGameObj ^FindClosestSoldier(Vector3 pos, float minDist, float maxDist, bool onlyHuman);
			static bool IsAStar(IScriptableGameObj ^obj);
			static void ControlEnable(IScriptableGameObj ^obj, bool enable);
			static String ^GetDamageBoneName();
			static bool GetDamageBoneDirection();
			static bool IsObjectVisible(IScriptableGameObj ^looker, IScriptableGameObj ^obj);
			static void EnableEnemySeen(IScriptableGameObj ^obj, bool enable);
			static void SetDisplayColor(System::Drawing::Color color);
			static void DisplayText(int stringId);
			static void DisplayFloat(float value, String ^format);
			static void DisplayInt(int value, String ^format);
			static void SaveData(IntPtr saver, int id, array<std::uint8_t> ^data);
			static void SavePointer(IntPtr saver, int id, IntPtr pointer);
			static bool LoadBegin(IntPtr loader, [Out] int %id);
			static void LoadData(IntPtr loader, array<std::uint8_t> ^data);
			static void LoadPointer(IntPtr loader, [Out] IntPtr %pointer);
			static void LoadEnd(IntPtr loader);
			static void BeginChunk(IntPtr saver, unsigned int chunkID);
			static void EndChunk(IntPtr saver);
			static bool OpenChunk(IntPtr loader, [Out] unsigned int %chunkID);
			static void CloseChunk(IntPtr loader);
			static void ClearRadarMarkers();
			static void ClearRadarMarker(int id);
			static void AddRadarMarker(int id, Vector3 position, int shapeType, int colorType);
			static void SetObjRadarBlipShape(IScriptableGameObj ^obj, int shapeType);
			static void SetObjRadarBlipColor(IScriptableGameObj ^obj, int colorType);
			static void EnableRadar(bool enable);
			static void ClearMapCell(int cellX, int cellY);
			static void ClearMapCellByPos(Vector3 worldSpacePos);
			static void ClearMapCellByPixelPos(int pixelPosX, int pixelPosY);
			static void ClearMapRegionByPos(Vector3 worldSpacePos, int pixelRadius);
			static void RevealMap();
			static void ShroudMap();
			static void ShowPlayerMapMarker(bool onoff);
			static float GetSafeFlightHeight(float xPos, float yPos);
			static void CreateExplosion(String ^explosionDefName, Vector3 pos, IScriptableGameObj ^creator);
			static void CreateExplosionAtBone(String ^explosionDefName, IScriptableGameObj ^object, String ^boneName, IScriptableGameObj ^creator);
			static void EnableHUD(bool enable);
			static void MissionComplete(bool success);
			static void GivePowerUp(IScriptableGameObj ^obj, String ^presetName, bool displayOnHUD);
			static void InnateDisable(IScriptableGameObj ^object);
			static void InnateEnable(IScriptableGameObj ^object);
			static bool InnateSoldierEnableEnemySeen(IScriptableGameObj ^obj, bool state);
			static bool InnateSoldierEnableGunshotHeard(IScriptableGameObj ^obj, bool state);
			static bool InnateSoldierEnableFootstepsHeard(IScriptableGameObj ^obj, bool state);
			static bool InnateSoldierEnableBulletHeard(IScriptableGameObj ^obj, bool state);
			static bool InnateSoldierEnableActions(IScriptableGameObj ^obj, bool state);
			static void SetInnateSoldierHomeLocation(IScriptableGameObj ^obj, Vector3 homePos, float homeRadius);
			static void SetInnateAggressiveness(IScriptableGameObj ^obj, float aggressiveness);
			static void SetInnateTakeCoverProbability(IScriptableGameObj ^obj, float probability);
			static void SetInnateIsStationary(IScriptableGameObj ^obj, bool stationary);
			static void InnateForceStateBulletHeard(IScriptableGameObj ^obj, Vector3 pos);
			static void InnateForceStateFootstepsHeard(IScriptableGameObj ^obj, Vector3 pos);
			static void InnateForceStateGunshotsHeard(IScriptableGameObj ^obj, Vector3 pos);
			static void InnateForceStateEnemySeen(IScriptableGameObj ^obj, IScriptableGameObj ^enemy);
			static void StaticAnimPhysGotoFrame(int objId, float frame, String ^animName);
			static void StaticAnimPhysGotoLastFrame(int objId, String ^animName);
			static unsigned int GetSyncTime();
			static void AddObjective(int id, int type, int status, int shortDescriptionId, String ^descriptionSoundFilename, int longDescriptionId);
			static void RemoveObjective(int id);
			static void SetObjectiveStatus(int id, int status);
			static void ChangeObjectiveType(int id, int type);
			static void SetObjectiveRadarBlip(int id, Vector3 position);
			static void SetObjectiveRadarBlipObject(int id, IScriptableGameObj ^unit);
			static void SetObjectiveHUDInfo(int id, float priority, String ^textureName, int messageId);
			static void SetObjectiveHUDInfoPosition(int id, float priority, String ^textureName, int messageId, Vector3 position);
			static void ShakeCamera(Vector3 pos, float radius, float intensity, float duration);
			static void EnableSpawner(int id, bool enable);
			static IScriptableGameObj ^TriggerSpawner(int id);
			static void EnableEngine(IScriptableGameObj ^object, bool onoff);
			static int GetDifficultyLevel();
			static void GrantKey(IScriptableGameObj ^object, int key, bool grant);
			static bool HasKey(IScriptableGameObj ^object, int key);
			static void EnableHibernation(IScriptableGameObj ^object, bool enable);
			static void AttachToObjectBone(IScriptableGameObj ^object, IScriptableGameObj ^hostObject, String ^boneName);
			static int CreateConversation(String ^conversationName, int priority, float maxDist, bool isInterruptable);
			static void JoinConversation(IScriptableGameObj ^object, int activeConversationId, bool allowMove, bool allowHeadTurn, bool allowFace);
			static void JoinConversationFacing(IScriptableGameObj ^object, int activeConversationId, int objIdToFace);
			static void StartConversation(int activeConversationId, int actionID);
			static void MonitorConversation(IScriptableGameObj ^object, int activeConversationId);
			static void StartRandomConversation(IScriptableGameObj ^object);
			static void StopConversation(int activeConversationId);
			static void StopAllConversations();
			static void LockSoldierFacing(IScriptableGameObj ^object, IScriptableGameObj ^objectToFace, bool turnBody);
			static void UnlockSoldierFacing(IScriptableGameObj ^object);
			static void ApplyDamage(IScriptableGameObj ^object, float amount, String ^warheadName, IScriptableGameObj ^damager);
			static void SetLoitersAllowed(IScriptableGameObj ^object, bool allowed);
			static void SetIsVisible(IScriptableGameObj ^object, bool visible);
			static void SetIsRendered(IScriptableGameObj ^object, bool rendered);
			static float GetPoints(IScriptableGameObj ^object);
			static void GivePoints(IScriptableGameObj ^object, float points, bool entireTeam);
			static float GetMoney(IScriptableGameObj ^object);
			static void GiveMoney(IScriptableGameObj ^object, float money, bool entireTeam);
			static bool GetBuildingPower(IScriptableGameObj ^object);
			static void SetBuildingPower(IScriptableGameObj ^object, bool onoff);
			static void PlayBuildingAnnouncement(IScriptableGameObj ^object, int textId);
			static IScriptableGameObj ^FindNearestBuildingToPos(Vector3 position, String ^meshPrefix);
			static IScriptableGameObj ^FindNearestBuilding(IScriptableGameObj ^object, String ^meshPrefix);
			static int TeamMembersInZone(IScriptableGameObj ^object, int playerType);
			static void SetClouds(float cloudCover, float cloudGloominess, float ramptime);
			static void SetLightning(float intensity, float startDistance, float endDistance, float heading, float distribution, float ramptime);
			static void SetWarBlitz(float intensity, float startDistance, float endDistance, float heading, float distribution, float ramptime);
			static void SetWind(float heading, float speed, float variability, float ramptime);
			static void SetRain(float density, float ramptime, bool prime);
			static void SetSnow(float density, float ramptime, bool prime);
			static void SetAsh(float density, float ramptime, bool prime);
			static void SetFogEnable(bool enabled);
			static void SetFogRange(float startDistance, float endDistance, float ramptime);
			static void EnableStealth(IScriptableGameObj ^object, bool onoff);
			static void CinematicSniperControl(bool enabled, float zoom);
			static int TextFileOpen(String ^filename);
			static String ^TextFileGetString(int handle);
			static void TextFileClose(int handle);
			static void EnableVehicleTransitions(IScriptableGameObj ^object, bool enable);
			static void DisplayGDIPlayerTerminal();
			static void DisplayNodPlayerTerminal();
			static void DisplayMutantPlayerTerminal();
			static bool RevealEncyclopediaCharacter(int objectId);
			static bool RevealEncyclopediaWeapon(int objectId);
			static bool RevealEncyclopediaVehicle(int objectId);
			static bool RevealEncyclopediaBuilding(int objectId);
			static void DisplayEncyclopediaEventUI();
			static void ScaleAIAwareness(float sightScale, float hearingScale);
			static void EnableCinematicFreeze(IScriptableGameObj ^object, bool enable);
			static void ExpirePowerup(IScriptableGameObj ^object);
			static void SetHUDHelpText(int stringId, Color color);
			static void EnableHUDPokableIndicator(IScriptableGameObj ^object, bool enable);
			static void EnableInnateConversations(IScriptableGameObj ^object, bool enable);
			static void DisplayHealthBar(IScriptableGameObj ^object, bool display);
			static void EnableShadow(IScriptableGameObj ^object, bool enable);
			static void ClearWeapons(IScriptableGameObj ^object);
			static void SetNumTertiaryObjectives(int count);
			static void EnableLetterbox(bool onoff, float seconds);
			static void SetScreenFadeColor(Color color, float seconds);
			static void SetScreenFadeOpacity(float opacity, float seconds);

			static property int Size
			{
				int get();
				void set(int value);
			}

			static property int Version
			{
				int get();
				void set(int value);
			}

			static property IntPtr DebugMessagePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ActionResetPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ActionGotoPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ActionAttackPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ActionPlayAnimationPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ActionEnterExitPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ActionFaceLocationPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ActionDockPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ActionFollowInputPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ModifyActionPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetActionIDPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetActionParamsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr IsPerformingPathfindActionPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetPositionPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetPositionPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetBonePositionPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetFacingPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetFacingPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr DisableAllCollisionsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr DisablePhysicalCollisionsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr EnableCollisionsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr DestroyObjectPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr FindObjectPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr CreateObjectPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr CreateObjectAtBonePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetIDPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetPresetIDPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetPresetNamePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr AttachScriptPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr AddToDirtyCullListPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr StartTimerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr TriggerWeaponPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SelectWeaponPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SendCustomEventPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SendDamagedEventPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetRandomPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetRandomIntPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr FindRandomSimpleObjectPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetModelPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetAnimationPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetAnimationFramePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr CreateSoundPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr Create2DSoundPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr Create2DWAVSoundPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr Create3DWAVSoundAtBonePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr Create3DSoundAtBonePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr CreateLogicalSoundPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr StartSoundPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr StopSoundPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr MonitorSoundPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetBackgroundMusicPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr FadeBackgroundMusicPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr StopBackgroundMusicPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetHealthPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetMaxHealthPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetHealthPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetShieldStrengthPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetMaxShieldStrengthPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetShieldStrengthPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetShieldTypePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetPlayerTypePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetPlayerTypePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetDistancePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetCameraHostPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ForceCameraLookPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetTheStarPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetAStarPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr FindClosestSoldierPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr IsAStarPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ControlEnablePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetDamageBoneNamePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetDamageBoneDirectionPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr IsObjectVisiblePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr EnableEnemySeenPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetDisplayColorPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr DisplayTextPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr DisplayFloatPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr DisplayIntPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SaveDataPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SavePointerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr LoadBeginPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr LoadDataPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr LoadPointerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr LoadEndPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr BeginChunkPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr EndChunkPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr OpenChunkPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr CloseChunkPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ClearRadarMarkersPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ClearRadarMarkerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr AddRadarMarkerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetObjRadarBlipShapePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetObjRadarBlipColorPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr EnableRadarPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ClearMapCellPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ClearMapCellByPosPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ClearMapCellByPixelPosPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ClearMapRegionByPosPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr RevealMapPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ShroudMapPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ShowPlayerMapMarkerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetSafeFlightHeightPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr CreateExplosionPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr CreateExplosionAtBonePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr EnableHUDPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr MissionCompletePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GivePowerUpPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr InnateDisablePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr InnateEnablePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr InnateSoldierEnableEnemySeenPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr InnateSoldierEnableGunshotHeardPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr InnateSoldierEnableFootstepsHeardPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr InnateSoldierEnableBulletHeardPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr InnateSoldierEnableActionsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetInnateSoldierHomeLocationPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetInnateAggressivenessPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetInnateTakeCoverProbabilityPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetInnateIsStationaryPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr InnateForceStateBulletHeardPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr InnateForceStateFootstepsHeardPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr InnateForceStateGunshotsHeardPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr InnateForceStateEnemySeenPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr StaticAnimPhysGotoFramePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr StaticAnimPhysGotoLastFramePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetSyncTimePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr AddObjectivePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr RemoveObjectivePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetObjectiveStatusPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ChangeObjectiveTypePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetObjectiveRadarBlipPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetObjectiveRadarBlipObjectPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetObjectiveHUDInfoPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetObjectiveHUDInfoPositionPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ShakeCameraPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr EnableSpawnerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr TriggerSpawnerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr EnableEnginePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetDifficultyLevelPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GrantKeyPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr HasKeyPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr EnableHibernationPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr AttachToObjectBonePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr CreateConversationPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr JoinConversationPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr JoinConversationFacingPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr StartConversationPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr MonitorConversationPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr StartRandomConversationPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr StopConversationPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr StopAllConversationsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr LockSoldierFacingPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr UnlockSoldierFacingPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ApplyDamagePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetLoitersAllowedPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetIsVisiblePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetIsRenderedPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetPointsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GivePointsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetMoneyPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GiveMoneyPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetBuildingPowerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetBuildingPowerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr PlayBuildingAnnouncementPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr FindNearestBuildingToPosPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr FindNearestBuildingPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr TeamMembersInZonePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetCloudsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetLightningPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetWarBlitzPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetWindPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetRainPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetSnowPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetAshPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetFogEnablePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetFogRangePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr EnableStealthPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr CinematicSniperControlPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr TextFileOpenPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr TextFileGetStringPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr TextFileClosePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr EnableVehicleTransitionsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr DisplayGDIPlayerTerminalPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr DisplayNodPlayerTerminalPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr DisplayMutantPlayerTerminalPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr RevealEncyclopediaCharacterPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr RevealEncyclopediaWeaponPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr RevealEncyclopediaVehiclePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr RevealEncyclopediaBuildingPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr DisplayEncyclopediaEventUIPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ScaleAIAwarenessPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr EnableCinematicFreezePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ExpirePowerupPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetHUDHelpTextPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr EnableHUDPokableIndicatorPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr EnableInnateConversationsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr DisplayHealthBarPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr EnableShadowPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ClearWeaponsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetNumTertiaryObjectivesPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr EnableLetterboxPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetScreenFadeColorPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetScreenFadeOpacityPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}
	};

	public interface class IScriptCommandsClass : public IUnmanagedObject
	{
		property IntPtr ScriptCommandsClassPointer
		{
			IntPtr get();
		}

		property IScriptCommands ^Commands
		{
			IScriptCommands ^get();
			void set(IScriptCommands ^value);
		}
	};

	public ref class ScriptCommandsClass : public AbstractUnmanagedObject, public IScriptCommandsClass
	{
		private:
			ScriptCommandsClass();

		public:
			ScriptCommandsClass(IntPtr pointer);

			static IUnmanagedContainer<IScriptCommandsClass ^> ^CreateScriptCommandsClass();

			bool Equals(Object ^other) override;

			property IntPtr ScriptCommandsClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IScriptCommands ^Commands
			{
				virtual IScriptCommands ^get() sealed;
				virtual void set(IScriptCommands ^value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::ScriptCommandsClass *InternalScriptCommandsClassPointer
			{
				virtual ::ScriptCommandsClass *get();
			}
	};
}