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

#include "IUnmanagedAttachable.h"
#include "Mda_crate.h"
#include "ITimerInterface.h"

#pragma managed(push, off)

class DACrateClass;

#pragma managed(pop)

using namespace System;

namespace RenSharp
{
	interface class IcPlayer;

	public interface class IRenSharpCrateClass : public IUnmanagedAttachable<IDACrateClass^>, public ITimerInterface
	{
		void Init();

		void SettingsLoaded();

		void CalculateOdds(IcPlayer^ player);

		bool CanActivate(IcPlayer^ player);

		void Activate(IcPlayer^ player);

		bool CheckType(IcPlayer^ player);

		bool CheckType(DACrateType type);

		void AdjustOdds(float odds);

		property IntPtr DACrateClassPointer
		{
			IntPtr get();
		}

		property bool CapOdds
		{
			bool get();
		}

		property float BaseOdds
		{
			float get();
		}

		property float ModifiedOdds
		{
			float get();
		}

		property float FinalOdds
		{
			float get();
		}

		property IDACrateFactoryClass^ Factory
		{
			IDACrateFactoryClass^ get();
			void set(IDACrateFactoryClass^ value);
		}

		property String^ Name
		{
			String^ get();
		}

		property String^ Section
		{
			String^ get();
		}

		property DACrateType Type
		{
			DACrateType get();
		}
	};

	public ref class RenSharpCrateClass abstract : public IRenSharpCrateClass
	{
		private:
			bool disposedResources;
			bool destroyPointer;
			IntPtr daCrateClassPointer;
			IDACrateClass^ daCrateClass;

		public:
			RenSharpCrateClass();
			~RenSharpCrateClass();
			!RenSharpCrateClass();

			String^ ToString() override;
			bool Equals(Object^ other) override;
			int GetHashCode() override sealed;

			virtual void InitUnmanagedAttachable() sealed;
			virtual void AttachToUnmanagedObject() sealed;
			virtual void RegisterManagedObject() sealed;
			virtual void ReleasePointer() sealed;
			virtual void UnmanagedAttach();
			virtual void ManagedRegistered();
			virtual IDACrateClass^ AsUnmanagedObject() sealed;

			virtual void TimerExpired(int number, Object^ data);
			virtual void StartTimer(int number, TimeSpan duration, bool repeat, Object^ data) sealed;
			virtual void StartTimer(int number, TimeSpan duration, bool repeat) sealed;
			virtual void StartTimer(int number, TimeSpan duration) sealed;
			virtual void StartTimer(TimeSpan duration, bool repeat, System::Action<RenSharpTimerStruct^>^ action) sealed;
			virtual void StartTimer(TimeSpan duration, System::Action<RenSharpTimerStruct^>^ action) sealed;
			virtual void StopTimer(int number, Object^ data) sealed;
			virtual void StopTimer(int number) sealed;
			virtual void StopTimer(System::Action<RenSharpTimerStruct^>^ action) sealed;
			virtual bool IsTimer(int number, Object^ data) sealed;
			virtual bool IsTimer(int number) sealed;
			virtual bool IsTimer(System::Action<RenSharpTimerStruct^>^ action) sealed;
			virtual void ClearTimers() sealed;

			virtual void Init();
			virtual void SettingsLoaded();
			virtual void CalculateOdds(IcPlayer^ player);
			virtual bool CanActivate(IcPlayer^ player);
			virtual void Activate(IcPlayer^ player) = 0;
			virtual bool CheckType(IcPlayer^ player) sealed;
			virtual bool CheckType(DACrateType type) sealed;
			virtual void AdjustOdds(float odds) sealed;

			property IntPtr DACrateClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr Pointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsAttached
			{
				virtual bool get() sealed;
			}

			property bool IsRegistered
			{
				virtual bool get() sealed;
			}

			property bool DestroyPointer
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ Timers
			{
				virtual Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ get() sealed;
			}

			property bool CapOdds
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property float BaseOdds
			{
				virtual float get() sealed;

				protected:
					void set(float value);
			}

			property float ModifiedOdds
			{
				virtual float get() sealed;

				protected:
					void set(float value);
			}

			property float FinalOdds
			{
				virtual float get() sealed;

				protected:
					void set(float value);
			}

			property IDACrateFactoryClass^ Factory
			{
				virtual IDACrateFactoryClass^ get() sealed;
				virtual void set(IDACrateFactoryClass^ value) sealed;
			}

			property String^ Name
			{
				virtual String^ get() sealed;
			}

			property String^ Section
			{
				virtual String^ get() sealed;
			}

			property DACrateType Type
			{
				virtual DACrateType get() sealed;

				protected:
					void set(DACrateType value);
			}

		protected:
			property ::DACrateClass* InternalDACrateClassPointer
			{
				virtual ::DACrateClass* get();
			}

			property IDynamicVectorClass<IDACrateModifierClass^>^ Modifiers
			{
				IDynamicVectorClass<IDACrateModifierClass^>^ get();
				void set(IDynamicVectorClass<IDACrateModifierClass^>^ value);
			}
	};
}