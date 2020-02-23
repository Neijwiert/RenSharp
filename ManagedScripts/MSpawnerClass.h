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

#include "MPersist.h"
#include "Mengine_vector.h"

#pragma managed(push, off)

class SpawnerClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class ISpawnerDefClass;
	interface class IReferencerClass;
	value class Matrix3D;

	public interface class ISpawnerClass : public IPersistClass
	{
		property IntPtr SpawnerClassPointer
		{
			IntPtr get();
		}

		property sint32 Id
		{
			sint32 get();
			void set(sint32 value);
		}

		property Matrix3D Transform
		{
			Matrix3D get();
			void set(Matrix3D value);
		}

		property Matrix3D SpawnEffectTransform
		{
			Matrix3D get();
			void set(Matrix3D value);
		}

		property ISpawnerDefClass^ Definition
		{
			ISpawnerDefClass^ get();
			void set(ISpawnerDefClass^ value);
		}

		property IReferencerClass^ CurrentObject
		{
			IReferencerClass^ get();
			void set(IReferencerClass^ value);
		}

		property bool Enabled
		{
			bool get();
			void set(bool value);
		}

		property sint32 SpawnCount
		{
			sint32 get();
			void set(sint32 value);
		}

		property float SpawnTimeRemaining
		{
			float get();
			void set(float value);
		}

		property IDynamicVectorClass<Matrix3D>^ AlternateTransform
		{
			IDynamicVectorClass<Matrix3D>^ get();
			void set(IDynamicVectorClass<Matrix3D>^ value);
		}

		property IDynamicVectorClass<String^>^ ScriptNames
		{
			IDynamicVectorClass<String^>^ get();
			void set(IDynamicVectorClass<String^>^ value);
		}

		property IDynamicVectorClass<String^>^ ScriptParameters
		{
			IDynamicVectorClass<String^>^ get();
			void set(IDynamicVectorClass<String^>^ value);
		}
	};

	public ref class SpawnerClass : public PersistClass, public ISpawnerClass
	{
		public:
			SpawnerClass(IntPtr pointer);

			property IntPtr SpawnerClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property sint32 Id
			{
				virtual sint32 get() sealed;
				virtual void set(sint32 value) sealed;
			}

			property Matrix3D Transform
			{
				virtual Matrix3D get() sealed;
				virtual void set(Matrix3D value) sealed;
			}

			property Matrix3D SpawnEffectTransform
			{
				virtual Matrix3D get() sealed;
				virtual void set(Matrix3D value) sealed;
			}

			property ISpawnerDefClass^ Definition
			{
				virtual ISpawnerDefClass^ get() sealed;
				virtual void set(ISpawnerDefClass^ value) sealed;
			}

			property IReferencerClass^ CurrentObject
			{
				virtual IReferencerClass^ get() sealed;
				virtual void set(IReferencerClass^ value) sealed;
			}

			property bool Enabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property sint32 SpawnCount
			{
				virtual sint32 get() sealed;
				virtual void set(sint32 value) sealed;
			}

			property float SpawnTimeRemaining
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property IDynamicVectorClass<Matrix3D>^ AlternateTransform
			{
				virtual IDynamicVectorClass<Matrix3D>^ get() sealed;
				virtual void set(IDynamicVectorClass<Matrix3D>^ value) sealed;
			}

			property IDynamicVectorClass<String^>^ ScriptNames
			{
				virtual IDynamicVectorClass<String^>^ get() sealed;
				virtual void set(IDynamicVectorClass<String^>^ value) sealed;
			}

			property IDynamicVectorClass<String^>^ ScriptParameters
			{
				virtual IDynamicVectorClass<String^>^ get() sealed;
				virtual void set(IDynamicVectorClass<String^>^ value) sealed;
			}

		protected:
			property ::PersistClass* InternalPersistClassPointer
			{
				::PersistClass* get() override;
			}

			property ::SpawnerClass* InternalSpawnerClassPointer
			{
				virtual ::SpawnerClass* get();
			}
	};
}