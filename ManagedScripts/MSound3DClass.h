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

#include "MAudibleSoundClass.h"

#pragma managed(push, off)

class Sound3DClass;

#pragma managed(pop)

namespace RenSharp
{
	value class Vector3;

	public interface class ISound3DClass : public IAudibleSoundClass
	{
		property IntPtr Sound3DClassPointer
		{
			IntPtr get();
		}

		property bool IsTransformValid
		{
			bool get();
			void set(bool value);
		}

		property bool IsAutoCalcVelocity
		{
			bool get();
			void set(bool value);
		}

		property Vector3 Velocity
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property float MaxVolRadius
		{
			float get();
			void set(float value);
		}

		property bool IsStatic
		{
			bool get();
			void set(bool value);
		}

		property uint32 Time
		{
			uint32 get();
			void set(uint32 value);
		}
	};

	public ref class Sound3DClass : public AudibleSoundClass, public ISound3DClass
	{
		public:
			Sound3DClass(IntPtr pointer);

			ISound3DClass ^AsSound3DClass() override;

			property IntPtr Sound3DClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsTransformValid
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsAutoCalcVelocity
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property Vector3 Velocity
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property float MaxVolRadius
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool IsStatic
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property uint32 Time
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

		protected:
			property ::AudibleSoundClass *InternalAudibleSoundClassPointer
			{
				::AudibleSoundClass *get() override;
			}

			property ::Sound3DClass *InternalSound3DClassPointer
			{
				virtual ::Sound3DClass *get();
			}
	};
}