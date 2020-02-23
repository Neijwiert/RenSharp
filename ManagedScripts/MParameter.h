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

#include "Mengine_vector.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <Parameter.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public interface class IParameterClass : public IUnmanagedObject
	{
		enum class ParameterType : int
		{
			TypeInt = ::ParameterClass::TYPE_INT,
			TypeFloat = ::ParameterClass::TYPE_FLOAT,
			TypeString = ::ParameterClass::TYPE_STRING,
			TypeVector3 = ::ParameterClass::TYPE_VECTOR3,
			TypeMatrix3D = ::ParameterClass::TYPE_MATRIX3D,
			TypeBool = ::ParameterClass::TYPE_BOOL,
			TypeTransition = ::ParameterClass::TYPE_TRANSITION,
			TypeModelDefinitionID = ::ParameterClass::TYPE_MODELDEFINITIONID,
			TypeFilename = ::ParameterClass::TYPE_FILENAME,
			TypeEnum = ::ParameterClass::TYPE_ENUM,
			TypeGameObjDefinitionID = ::ParameterClass::TYPE_GAMEOBJDEFINITIONID,
			TypeScript = ::ParameterClass::TYPE_SCRIPT,
			TypeSoundFilename = ::ParameterClass::TYPE_SOUND_FILENAME,
			TypeAngle = ::ParameterClass::TYPE_ANGLE,
			TypeWeaponObjDefinitionID = ::ParameterClass::TYPE_WEAPONOBJDEFINITIONID,
			TypeAmmoObjDefinitionID = ::ParameterClass::TYPE_AMMOOBJDEFINITIONID,
			TypeSoundDefinitionID = ::ParameterClass::TYPE_SOUNDDEFINITIONID,
			TypeColor = ::ParameterClass::TYPE_COLOR,
			TypePhysDefinitionID = ::ParameterClass::TYPE_PHYSDEFINITIONID,
			TypeExplosionDefinitionID = ::ParameterClass::TYPE_EXPLOSIONDEFINITIONID,
			TypeDefinitionIDList = ::ParameterClass::TYPE_DEFINITIONIDLIST,
			TypeZone = ::ParameterClass::TYPE_ZONE,
			TypeFilenameList = ::ParameterClass::TYPE_FILENAMELIST,
			TypeSeparator = ::ParameterClass::TYPE_SEPARATOR,
			TypeGenericDefinitionID = ::ParameterClass::TYPE_GENERICDEFINITIONID,
			TypeScriptList = ::ParameterClass::TYPE_SCRIPTLIST,
			TypeVector2 = ::ParameterClass::TYPE_VECTOR2,
			TypeRect = ::ParameterClass::TYPE_RECT,
			TypeStringsDBID = ::ParameterClass::TYPE_STRINGSDB_ID
		};

		IntPtr AsDefParameterClass();

		bool IsType(ParameterType type);

		void CopyValue(IParameterClass^ src);

		property IntPtr ParameterClassPointer
		{
			IntPtr get();
		}

		property ParameterType Type
		{
			ParameterType get();
		}

		property bool IsModified
		{
			bool get();
			void set(bool value);
		}

		property String^ Name
		{
			String^ get();
			void set(String^ value);
		}

		property String^ UnitsName
		{
			String^ get();
			void set(String^ value);
		}
	};

	public ref class ParameterClass : public AbstractUnmanagedObject, public IParameterClass
	{
		public:
			ParameterClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual IntPtr AsDefParameterClass() sealed;
			virtual bool IsType(IParameterClass::ParameterType type) sealed;
			virtual void CopyValue(IParameterClass^ src) sealed;

			property IntPtr ParameterClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IParameterClass::ParameterType Type
			{
				virtual IParameterClass::ParameterType get() sealed;
			}

			property bool IsModified
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property String^ Name
			{
				virtual String^ get() sealed;
				virtual void set(String^ value) sealed;
			}

			property String^ UnitsName
			{
				virtual String^ get() sealed;
				virtual void set(String^ value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::ParameterClass* InternalParameterClassPointer
			{
				virtual ::ParameterClass* get();
			}
	};

	public interface class IParameterListClass : public IDynamicVectorClass<IParameterClass^>
	{
		property IntPtr ParameterListClassPointer
		{
			IntPtr get();
		}
	};

	public ref class ParameterListClass : public DynamicVectorClass<IParameterClass^>, public IParameterListClass
	{
		private:
			ParameterListClass();

		public:
			ParameterListClass(IntPtr pointer);

			bool Equals(Object^ other) override;

			static IUnmanagedContainer<IParameterListClass^>^ CreateParameterListClass();

			bool Resize(int newSize) override sealed;
			void Clear() override;
			int ID(IParameterClass ^object) override sealed;
			void Insert(int index, IParameterClass ^object) override;
			bool Add(IParameterClass ^object) override;
			void ResetActive() override sealed;
			bool AddHead(IParameterClass ^object) override sealed;
			bool DeleteObj(IParameterClass ^object) override sealed;
			bool Delete(int index) override sealed;
			void DeleteAll() override sealed;
			int UninitializedAdd() override sealed;
			void AddMultiple(int numberToAdd) override sealed;

			property IntPtr ParameterListClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr ParameterClassPtrDynamicVectorClassPointer
			{
				IntPtr get();
			}

			property IParameterClass ^default[int]
			{
				IParameterClass ^get(int index) override;
				void set(int index, IParameterClass ^value) override;
			}

			property int Length
			{
				int get() override sealed;
			}

			property int Count
			{
				int get() override;
				void set(int value) override sealed;
			}

			property int GrowthStep
			{
				int get() override sealed;
				void set(int value) override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;
			void FreeParameters();

			property ::DynamicVectorClass<::ParameterClass *> *InternalParameterClassPtrDynamicVectorClassPointer
			{
				virtual ::DynamicVectorClass<::ParameterClass *> *get();
			}

			property ::ParameterListClass* InternalParameterListClassPointer
			{
				virtual ::ParameterListClass* get();
			}

			property IntPtr Vector
			{
				IntPtr get() override sealed;
				void set(IntPtr value) override sealed;
			}

			property int VectorMax
			{
				int get() override sealed;
				void set(int value) override sealed;
			}

			property bool IsValid
			{
				bool get() override sealed;
				void set(bool value) override sealed;
			}

			property bool IsAllocated
			{
				bool get() override sealed;
				void set(bool value) override sealed;
			}

			property int ActiveCount
			{
				int get() override sealed;
				void set(int value) override sealed;
			}
	};
}