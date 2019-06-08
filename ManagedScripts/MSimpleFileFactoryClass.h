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

#include "Mengine_io.h"

#pragma managed(push, off)

class SimpleFileFactoryClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class ICriticalSectionClass;
	
	public interface class ISimpleFileFactoryClass : public IFileFactoryClass
	{
		property IntPtr SimpleFileFactoryClassPointer
		{
			IntPtr get();
		}

		property String^ SubDirectories
		{
			String^ get();
			void set(String^ value);
		}

		property bool IsStripPath
		{
			bool get();
			void set(bool value);
		}

		property ICriticalSectionClass^ Mutex
		{
			ICriticalSectionClass^ get();
		}
	};

	public ref class SimpleFileFactoryClass : public FileFactoryClass, public ISimpleFileFactoryClass
	{
		public:
			SimpleFileFactoryClass(IntPtr pointer);

			property IntPtr SimpleFileFactoryClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String^ SubDirectories
			{
				virtual String^ get() sealed;
				virtual void set(String^ value) sealed;
			}

			property bool IsStripPath
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property ICriticalSectionClass^ Mutex
			{
				virtual ICriticalSectionClass^ get() sealed;
			}

		protected:
			property ::FileFactoryClass* InternalFileFactoryClassPointer
			{
				::FileFactoryClass* get() override;
			}

			property ::SimpleFileFactoryClass* InternalSimpleFileFactoryClassPointer
			{
				virtual ::SimpleFileFactoryClass* get();
			}
	};
}