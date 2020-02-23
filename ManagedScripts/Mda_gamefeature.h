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
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_gamefeature.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	interface class IDAGameFeatureClass;
	interface class IRenSharpGameFeatureFactoryClass;
	interface class IRenSharpGameFeatureClass;

#pragma managed(push, off)

	class DAGameFeatureFactoryClassHelper : public ::DAGameFeatureFactoryClass
	{
		private:
			DAGameFeatureFactoryClassHelper(const char* name, const char* enableSetting)
				: ::DAGameFeatureFactoryClass(name, enableSetting)
			{

			}

		public:
			void AddGameFeature()
			{
#pragma warning(push)
#pragma warning(disable : 4996)
				Add_Game_Feature();
#pragma warning(pop) 
			}

			::DAGameFeatureClass*& GetInstance()
			{
				return Instance;
			}
	};

#pragma managed(pop)

	public interface class IDAGameFeatureFactoryClass : public IUnmanagedObject
	{
		IDAGameFeatureClass^ CreateInstance();

		IRenSharpGameFeatureFactoryClass^ AsManagedGameFeatureFactory();

		property IntPtr DAGameFeatureFactoryClassPointer
		{
			IntPtr get();
		}

		property String^ Name
		{
			String^ get();
		}

		property String^ EnableSetting
		{
			String^ get();
		}

		property String^ RequiredData
		{
			String^ get();
		}

		property IDAGameFeatureClass^ Instance
		{
			IDAGameFeatureClass^ get();
		}

		property bool IsManagedGameFeatureFactory
		{
			bool get();
		}
	};

	public ref class DAGameFeatureFactoryClass : public AbstractUnmanagedObject, public IDAGameFeatureFactoryClass
	{
		protected:
			DAGameFeatureFactoryClass();

		public:
			DAGameFeatureFactoryClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual IDAGameFeatureClass^ CreateInstance() sealed;
			virtual IRenSharpGameFeatureFactoryClass^ AsManagedGameFeatureFactory() sealed;

			property IntPtr DAGameFeatureFactoryClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String^ Name
			{
				virtual String^ get() sealed;
			}

			property String^ EnableSetting
			{
				virtual String^ get() sealed;
			}

			property String^ RequiredData
			{
				virtual String^ get() sealed;
			}

			property IDAGameFeatureClass^ Instance
			{
				virtual IDAGameFeatureClass^ get() sealed;

				protected:
					void set(IDAGameFeatureClass^ value);
			}

			property bool IsManagedGameFeatureFactory
			{
				virtual bool get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			[Obsolete("The constructor already does this", true)]
			void AddGameFeature();

			property ::DAGameFeatureFactoryClass* InternalDAGameFeatureFactoryClassPointer
			{
				virtual ::DAGameFeatureFactoryClass* get();
			}
	};

	public interface class IDAGameFeatureClass : public IUnmanagedObject
	{
		void Init();

		IRenSharpGameFeatureClass^ AsManagedGameFeature();

		property IntPtr DAGameFeatureClassPointer
		{
			IntPtr get();
		}

		property String^ Name
		{
			String^ get();
		}

		property IDAGameFeatureFactoryClass^ Factory
		{
			IDAGameFeatureFactoryClass^ get();
			void set(IDAGameFeatureFactoryClass^ value);
		}

		property bool IsManagedGameFeature
		{
			bool get();
		}
	};

	public ref class DAGameFeatureClass : public AbstractUnmanagedObject, public IDAGameFeatureClass
	{
		public:
			DAGameFeatureClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void Init() sealed;
			virtual IRenSharpGameFeatureClass^ AsManagedGameFeature() sealed;

			property IntPtr DAGameFeatureClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String^ Name
			{
				virtual String^ get() sealed;
			}

			property IDAGameFeatureFactoryClass^ Factory
			{
				virtual IDAGameFeatureFactoryClass^ get() sealed;
				virtual void set(IDAGameFeatureFactoryClass^ value) sealed;
			}

			property bool IsManagedGameFeature
			{
				virtual bool get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DAGameFeatureClass* InternalDAGameFeatureClassPointer
			{
				virtual ::DAGameFeatureClass* get();
			}
	};

	generic<typename T>
	public interface class IDAGameFeatureRegistrant : public IDAGameFeatureFactoryClass
	{

	};

	generic<typename T>
	public ref class DAGameFeatureRegistrant abstract : public DAGameFeatureFactoryClass, public IDAGameFeatureRegistrant<T>
	{
		protected:
			DAGameFeatureRegistrant()
				: DAGameFeatureFactoryClass()
			{

			}

		public:
			DAGameFeatureRegistrant(IntPtr pointer)
				: DAGameFeatureFactoryClass(pointer)
			{

			}
	};
}