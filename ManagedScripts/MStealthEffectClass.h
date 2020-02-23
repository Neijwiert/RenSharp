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

#include "MMaterialEffectClass.h"

#pragma managed(push, off)

class StealthEffectClass;

#pragma managed(pop)

namespace RenSharp
{
	value class Vector2;

	public interface class IStealthEffectClass : public IMaterialEffectClass
	{
		void SetCurrentState(float percent);

		void SetTargetState(float percent);

		property IntPtr StealthEffectClassPointer
		{
			IntPtr get();
		}

		property bool IsStealthEnabled
		{
			bool get();
		}

		property bool IsFriendly
		{
			bool get();
		}

		property bool IsBroken
		{
			bool get();
		}

		property bool IsStealthed
		{
			bool get();
		}

		property float FadeDistance
		{
			float get();
			void set(float value);
		}
	};

	public ref class StealthEffectClass : public MaterialEffectClass, public IStealthEffectClass
	{
		public:
			StealthEffectClass(IntPtr pointer);

			virtual void SetCurrentState(float percent) sealed;
			virtual void SetTargetState(float percent) sealed;

			property IntPtr StealthEffectClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsStealthEnabled
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property bool IsFriendly
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property bool IsBroken
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property bool IsStealthed
			{
				virtual bool get() sealed;
			}

			property float FadeDistance
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

		protected:
			property ::MaterialEffectClass *InternalMaterialEffectClassPointer
			{
				::MaterialEffectClass *get() override;
			}

			property ::StealthEffectClass *InternalStealthEffectClassPointer
			{
				virtual ::StealthEffectClass *get();
			}

			property float CurrentFraction
			{
				float get();
				void set(float value);
			}

			property float TargetFraction
			{
				float get();
				void set(float value);
			}

			property Vector2 UVRate
			{
				Vector2 get();
				void set(Vector2 value);
			}

			property bool RenderBaseMaterial
			{
				bool get();
				void set(bool value);
			}

			property bool RenderStealthMaterial
			{
				bool get();
				void set(bool value);
			}

			property float IntensityScale
			{
				float get();
				void set(float value);
			}

			property Vector2 UVOffset
			{
				Vector2 get();
				void set(Vector2 value);
			}

			property IntPtr Mapper
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IntPtr MaterialPass
			{
				IntPtr get();
				void set(IntPtr value);
			}
	};
}