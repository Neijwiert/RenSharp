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

#include "IUnmanagedAttachable.h"
#include "Mda_crate.h"

#pragma managed(push, off)

class DACrateModifierClass;

#pragma managed(pop)

using namespace System;

namespace RenSharp
{
	interface class IcPlayer;
	interface class IDATokenClass;

	public interface class IRenSharpCrateModifierClass : public IUnmanagedAttachable<IDACrateModifierClass^>
	{
		void Init(String^ parameters);

		void Init(IDATokenClass^ parameters);

		void CalculateOdds(float% odds, IcPlayer^ player);

		void ApplyModifier(float% odds);

		property IntPtr DACrateModifierClassPointer
		{
			IntPtr get();
		}

		property bool IsMultiplicative
		{
			bool get();
		}

		property bool IsPositive
		{
			bool get();
		}

		property IDACrateModifierFactoryClass^ Factory
		{
			IDACrateModifierFactoryClass^ get();
			void set(IDACrateModifierFactoryClass^ value);
		}

		property String^ Name
		{
			String^ get();
		}
	};

	public ref class RenSharpCrateModifierClass abstract : public IRenSharpCrateModifierClass
	{
		private:
			bool disposedResources;
			bool destroyPointer;
			IntPtr daCrateModifierClassPointer;
			IDACrateModifierClass^ daCrateModifierClass;

		public:
			RenSharpCrateModifierClass();
			~RenSharpCrateModifierClass();
			!RenSharpCrateModifierClass();

			String^ ToString() override;
			bool Equals(Object^ other) override;
			int GetHashCode() override sealed;

			virtual void AttachToUnmanagedObject() sealed;
			virtual void RegisterManagedObject() sealed;
			virtual void ReleasePointer() sealed;
			virtual void UnmanagedAttach();
			virtual void ManagedRegistered();
			virtual IDACrateModifierClass^ AsUnmanagedObject() sealed;

			virtual void Init(String^ parameters);
			virtual void Init(IDATokenClass^ parameters);
			virtual void CalculateOdds(float% odds, IcPlayer^ player) = 0;
			virtual void ApplyModifier(float% odds) sealed;

			property IntPtr DACrateModifierClassPointer
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

			property bool DestroyPointer
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsMultiplicative
			{
				virtual bool get() sealed;
			}

			property bool IsPositive
			{
				virtual bool get() sealed;
			}

			property IDACrateModifierFactoryClass^ Factory
			{
				virtual IDACrateModifierFactoryClass^ get() sealed;
				virtual void set(IDACrateModifierFactoryClass^ value) sealed;
			}

			property String^ Name
			{
				virtual String^ get() sealed;
			}

		protected:
			property ::DACrateModifierClass* InternalDACrateModifierClassPointer
			{
				virtual ::DACrateModifierClass* get();
			}

			property DACrateModifierOperator Operator
			{
				DACrateModifierOperator get();
				void set(DACrateModifierOperator value);
			}

			property float Value
			{
				float get();
				void set(float value);
			}
	};
}