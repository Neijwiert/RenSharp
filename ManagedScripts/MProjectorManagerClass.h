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

#include "AbstractUnmanagedObject.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <ProjectorManagerClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public interface class IProjectorManagerClass : public IUnmanagedObject
	{
		void SetFlag(int flag, bool onoff);

		bool GetFlag(int flag);

		enum class ProjectorFlags : int
		{
			IsAnimated = ::ProjectorManagerClass::IS_ANIMATED
		};

		property IntPtr ProjectorManagerClassPointer
		{
			IntPtr get();
		}
	};

	public ref class ProjectorManagerClass : public AbstractUnmanagedObject, public IProjectorManagerClass
	{
		public:
			ProjectorManagerClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual void SetFlag(int flag, bool onoff) sealed;
			virtual bool GetFlag(int flag) sealed;

			property IntPtr ProjectorManagerClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::ProjectorManagerClass *InternalProjectorManagerClassPointer
			{
				virtual ::ProjectorManagerClass *get();
			}

			property uint16 Flags
			{
				uint16 get();
				void set(uint16 value);
			}

			property uint16 ProjectorBoneIndex
			{
				uint16 get();
				void set(uint16 value);
			}

			property IntPtr Projector
			{
				IntPtr get();
				void set(IntPtr value);
			}
	};

	public interface class IProjectorManagerDefClass : public IUnmanagedObject
	{
		property IntPtr ProjectorManagerDefClassPointer
		{
			IntPtr get();
		}

		property bool IsEnabled
		{
			bool get();
			void set(bool value);
		}

		property bool IsPerspective
		{
			bool get();
			void set(bool value);
		}

		property bool IsAdditive
		{
			bool get();
			void set(bool value);
		}

		property bool IsAnimated
		{
			bool get();
			void set(bool value);
		}

		property float OrthoWidth
		{
			float get();
			void set(float value);
		}

		property float OrthoHeight
		{
			float get();
			void set(float value);
		}

		property float HorizontalFOV
		{
			float get();
			void set(float value);
		}

		property float VerticalFOV
		{
			float get();
			void set(float value);
		}

		property float NearZ
		{
			float get();
			void set(float value);
		}

		property float FarZ
		{
			float get();
			void set(float value);
		}

		property float Intensity
		{
			float get();
			void set(float value);
		}

		property String ^TextureName
		{
			String ^get();
			void set(String ^value);
		}

		property String ^BoneName
		{
			String ^get();
			void set(String ^value);
		}
	};

	public ref class ProjectorManagerDefClass : public AbstractUnmanagedObject, public IProjectorManagerDefClass
	{
		public:
			ProjectorManagerDefClass(IntPtr pointer);

			property IntPtr ProjectorManagerDefClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsPerspective
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsAdditive
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsAnimated
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property float OrthoWidth
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float OrthoHeight
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float HorizontalFOV
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float VerticalFOV
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float NearZ
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float FarZ
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float Intensity
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property String ^TextureName
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property String ^BoneName
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

		protected:
			property ::ProjectorManagerDefClass *InternalProjectorManagerDefClassPointer
			{
				virtual ::ProjectorManagerDefClass *get();
			}
	};
}