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

class UndergroundEffectClass;

#pragma managed(pop)

using namespace System::Drawing;

namespace RenSharp
{

#pragma warning(push)
#pragma warning(disable : 4099 4251 4244 26495 26454)

	value class Vector3;

#pragma warning(pop)

	public interface class IUndergroundEffectClass : public IMaterialEffectClass
	{
		property IntPtr UndergroundEffectClassPointer
		{
			IntPtr get();
		}

		property bool IsUnderground
		{
			bool get();
		}

		property bool IsVisible
		{
			bool get();
		}

		property float FadeDistance
		{
			float get();
			void set(float value);
		}

		property Drawing::Color Color
		{
			Drawing::Color get();
			void set(Drawing::Color value);
		}
	};

	public ref class UndergroundEffectClass : public MaterialEffectClass, public IUndergroundEffectClass
	{
		public:
			UndergroundEffectClass(IntPtr pointer);

			property IntPtr UndergroundEffectClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsUnderground
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property bool IsVisible
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property float FadeDistance
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property Drawing::Color Color
			{
				virtual Drawing::Color get() sealed;
				virtual void set(Drawing::Color value) sealed;
			}

		protected:
			property ::MultiListObjectClass *InternalMultiListObjectClassPointer
			{
				::MultiListObjectClass *get() override;
			}

			property ::MaterialEffectClass *InternalMaterialEffectClassPointer
			{
				::MaterialEffectClass *get() override;
			}

			property ::UndergroundEffectClass *InternalUndergroundEffectClassPointer
			{
				virtual ::UndergroundEffectClass *get();
			}

			property bool WasUnderground
			{
				bool get();
				void set(bool value);
			}

			property float CurrentFraction
			{
				float get();
				void set(float value);
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

			property IntPtr MaterialPass
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IntPtr Mapper
			{
				IntPtr get();
				void set(IntPtr value);
			}
	};
}