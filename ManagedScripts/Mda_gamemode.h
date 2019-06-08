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
#include "IUnmanagedContainer.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_gamemode.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	interface class IDAGameModeClass;
	interface class IRenSharpGameModeClass;
	interface class IRenSharpGameModeFactoryClass;

#pragma managed(push, off)

	class DAGameModeFactoryClassHelper : public ::DAGameModeFactoryClass 
	{
		private:
			DAGameModeFactoryClassHelper(const char* shortName, const char* longName)
				: ::DAGameModeFactoryClass(shortName, longName)
			{

			}

		public:
			void AddGameMode()
			{
#pragma warning(push)
#pragma warning(disable : 4996)
				Add_Game_Mode();
#pragma warning(pop) 
			}

			::DAGameModeClass*& GetInstance()
			{
				return Instance;
			}
	};

#pragma managed(pop)

	public interface class IDAGameModeFactoryClass : public IUnmanagedObject
	{
		IDAGameModeClass^ CreateInstance();

		IRenSharpGameModeFactoryClass^ AsManagedGameModeFactory();

		property IntPtr DAGameModeFactoryClassPointer
		{
			IntPtr get();
		}

		property String^ LongName
		{
			String^ get();
		}

		property String^ ShortName
		{
			String^ get();
		}

		property IDAGameModeClass^ Instance
		{
			IDAGameModeClass^ get();
		}

		property bool IsManagedGameModeFactory
		{
			bool get();
		}
	};

	public ref class DAGameModeFactoryClass : public AbstractUnmanagedObject, public IDAGameModeFactoryClass
	{
		public:
			DAGameModeFactoryClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual IDAGameModeClass^ CreateInstance() sealed;
			virtual IRenSharpGameModeFactoryClass^ AsManagedGameModeFactory() sealed;

			property IntPtr DAGameModeFactoryClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String^ LongName
			{
				virtual String^ get() sealed;
			}

			property String^ ShortName
			{
				virtual String^ get() sealed;
			}

			property IDAGameModeClass^ Instance
			{
				virtual IDAGameModeClass^ get() sealed;

				protected:
					void set(IDAGameModeClass^ value);
			}

			property bool IsManagedGameModeFactory
			{
				virtual bool get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			[Obsolete("The constructor already does this", true)]
			void AddGameMode();

			property ::DAGameModeFactoryClass* InternalDAGameModeFactoryClassPointer
			{
				virtual ::DAGameModeFactoryClass* get();
			}
	};

	public interface class IDAGameModeClass : public IUnmanagedObject
	{
		void Init();

		IRenSharpGameModeClass^ AsManagedGameMode();

		property IntPtr DAGameModeClassPointer
		{
			IntPtr get();
		}

		property String^ LongName
		{
			String^ get();
		}

		property String^ ShortName
		{
			String^ get();
		}

		property IDAGameModeFactoryClass^ Factory
		{
			IDAGameModeFactoryClass^ get();
			void set(IDAGameModeFactoryClass^ value);
		}

		property bool IsManagedGameMode
		{
			bool get();
		}
	};

	public ref class DAGameModeClass : public AbstractUnmanagedObject, public IDAGameModeClass
	{
		public:
			DAGameModeClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void Init() sealed;
			virtual IRenSharpGameModeClass^ AsManagedGameMode() sealed;

			property IntPtr DAGameModeClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String^ LongName
			{
				virtual String^ get() sealed;
			}

			property String^ ShortName
			{
				virtual String^ get() sealed;
			}

			property IDAGameModeFactoryClass^ Factory
			{
				virtual IDAGameModeFactoryClass^ get() sealed;
				virtual void set(IDAGameModeFactoryClass^ value) sealed;
			}

			property bool IsManagedGameMode
			{
				virtual bool get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DAGameModeClass* InternalDAGameModeClassPointer
			{
				virtual ::DAGameModeClass* get();
			}
	};

	generic<typename T>
	public interface class IDAGameModeRegistrant : public IDAGameModeFactoryClass
	{

	};

	generic<typename T>
	public ref class DAGameModeRegistrant abstract : public DAGameModeFactoryClass, public IDAGameModeRegistrant<T>
	{
		public:
			DAGameModeRegistrant(IntPtr pointer)
				: DAGameModeFactoryClass(pointer)
			{

			}
	};
}