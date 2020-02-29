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

#include "MDefinition.h"
#include "IUnmanagedContainer.h"

#pragma managed(push, off)

class AudibleSoundDefinitionClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IAudibleSoundClass;
	value class Vector3;

	public interface class IAudibleSoundDefinitionClass : public IDefinitionClass
	{
		literal unsigned int AudibleSoundDefinitionClassClassID = 0x5000;

		IUnmanagedContainer<IAudibleSoundClass ^> ^CreateSound(int type);

		void InitializeFromSound(IAudibleSoundClass ^sound);

		IntPtr CreateLogical();
			 
		property IntPtr AudibleSoundDefinitionClassPointer
		{
			IntPtr get();
		}

		property String ^Filename
		{
			String ^get();
		}

		property String ^DisplayText
		{
			String ^get();
		}

		property float MaxVolRadius
		{
			float get();
			void set(float value);
		}

		property float DropOffRadius
		{
			float get();
			void set(float value);
		}

		property Vector3 SphereColor
		{
			Vector3 get();
		}

		property float Volume
		{
			float get();
			void set(float value);
		}

		property float VolumeRandomizer
		{
			float get();
			void set(float value);
		}

		property float StartOffset
		{
			float get();
			void set(float value);
		}

		property float PitchFactor
		{
			float get();
			void set(float value);
		}

		property float PitchFactorRandomizer
		{
			float get();
			void set(float value);
		}

		property int VirtualChannel
		{
			int get();
			void set(int value);
		}

		property float LogicalDropoffRadius
		{
			float get();
		}

		property int LogicalType
		{
			int get();
		}
	};

	public ref class AudibleSoundDefinitionClass : public DefinitionClass, public IAudibleSoundDefinitionClass
	{
		public:
			AudibleSoundDefinitionClass(IntPtr pointer);

			virtual IUnmanagedContainer<IAudibleSoundClass ^> ^CreateSound(int type) sealed;
			virtual void InitializeFromSound(IAudibleSoundClass ^sound) sealed;
			virtual IntPtr CreateLogical() sealed;

			property IntPtr AudibleSoundDefinitionClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String ^Filename
			{
				virtual String ^get() sealed;
			}

			property String ^DisplayText
			{
				virtual String ^get() sealed;
			}

			property float MaxVolRadius
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float DropOffRadius
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property Vector3 SphereColor
			{
				virtual Vector3 get() sealed;
			}

			property float Volume
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float VolumeRandomizer
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float StartOffset
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float PitchFactor
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float PitchFactorRandomizer
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int VirtualChannel
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float LogicalDropoffRadius
			{
				virtual float get() sealed;
			}

			property int LogicalType
			{
				virtual int get() sealed;
			}

		protected:
			property ::DefinitionClass *InternalDefinitionClassPointer
			{
				::DefinitionClass *get() override;
			}

			property ::AudibleSoundDefinitionClass *InternalAudibleSoundDefinitionClassPointer
			{
				virtual ::AudibleSoundDefinitionClass *get();
			}
	};
}