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

#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"

#pragma managed(push, off)

struct PivotClass;
class HTreeClass;

#pragma managed(pop)

namespace RenSharp
{
	value class Matrix3D;

	public interface class IPivotClass : public IUnmanagedObject
	{
		void CaptureUpdate();

		property IntPtr PivotClassPointer
		{
			IntPtr get();
		}

		property String ^Name
		{
			String ^get();
			void set(String ^value);
		}

		property int Index
		{
			int get();
			void set(int value);
		}

		property IPivotClass ^Parent
		{
			IPivotClass ^get();
			void set(IPivotClass ^value);
		}

		property Matrix3D BaseTransform
		{
			Matrix3D get();
			void set(Matrix3D value);
		}

		property Matrix3D Transform
		{
			Matrix3D get();
			void set(Matrix3D value);
		}

		property bool IsVisible
		{
			bool get();
			void set(bool value);
		}

		property bool IsCaptured
		{
			bool get();
			void set(bool value);
		}

		property Matrix3D CapTransform
		{
			Matrix3D get();
			void set(Matrix3D value);
		}

		property bool WorldSpaceTranslation
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class PivotClass : public AbstractUnmanagedObject, public IPivotClass
	{
		private:
			PivotClass();

		public:
			PivotClass(IntPtr pointer);

			String ^ToString() override;
			bool Equals(Object ^other) override;

			static IUnmanagedContainer<IPivotClass ^> ^CreatePivotClass();

			virtual void CaptureUpdate() sealed;

			property IntPtr PivotClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String ^Name
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property int Index
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property IPivotClass ^Parent
			{
				virtual IPivotClass ^get() sealed;
				virtual void set(IPivotClass ^value) sealed;
			}

			property Matrix3D BaseTransform
			{
				virtual Matrix3D get() sealed;
				virtual void set(Matrix3D value) sealed;
			}

			property Matrix3D Transform
			{
				virtual Matrix3D get() sealed;
				virtual void set(Matrix3D value) sealed;
			}

			property bool IsVisible
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsCaptured
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property Matrix3D CapTransform
			{
				virtual Matrix3D get() sealed;
				virtual void set(Matrix3D value) sealed;
			}

			property bool WorldSpaceTranslation
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::PivotClass *InternalPivotClassPointer
			{
				virtual ::PivotClass *get();
			}
	};

	public interface class IHTreeClass : public IUnmanagedObject
	{
		Matrix3D GetTransform(int pivot);

		bool GetVisibility(int pivot);

		property IntPtr HTreeClassPointer
		{
			IntPtr get();
		}

		property String ^Name
		{
			String ^get();
		}

		property int NumPivots
		{
			int get();
		}

		property Matrix3D RootTransform
		{
			Matrix3D get();
		}
	};

	public ref class HTreeClass : public AbstractUnmanagedObject, public IHTreeClass
	{
		public:
			HTreeClass(IntPtr pointer);

			String ^ToString() override;
			bool Equals(Object ^other) override;

			virtual Matrix3D GetTransform(int pivot) sealed;
			virtual bool GetVisibility(int pivot) sealed;

			property IntPtr HTreeClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String ^Name
			{
				virtual String ^get() sealed;
			}

			property int NumPivots
			{
				virtual int get() sealed;
			}

			property Matrix3D RootTransform
			{
				virtual Matrix3D get() sealed;
			}

		protected:
			property ::HTreeClass *InternalHTreeClassPointer
			{
				virtual ::HTreeClass *get();
			}
	};
}