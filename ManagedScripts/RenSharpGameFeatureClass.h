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

#include "IUnmanagedAttachable.h"
#include "Mda_gamefeature.h"

#pragma managed(push, off)

class DAGameFeatureClass;

#pragma managed(pop)

using namespace System;

namespace RenSharp
{
	interface class IRenSharpGameFeatureFactoryClass;

	public interface class IRenSharpGameFeatureClass : public IUnmanagedAttachable<IDAGameFeatureClass^>
	{
		void Init();

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
	};

	public ref class RenSharpGameFeatureClass abstract : public IRenSharpGameFeatureClass
	{
		private:
			bool disposedResources;
			bool destroyPointer;
			IntPtr daGameFeatureClassPointer;
			IDAGameFeatureClass^ daGameFeatureClass;

		public:
			RenSharpGameFeatureClass();
			~RenSharpGameFeatureClass();
			!RenSharpGameFeatureClass();

			String^ ToString() override;
			bool Equals(Object^ other) override;
			int GetHashCode() override sealed;

			virtual void AttachToUnmanagedObject() sealed;
			virtual void RegisterManagedObject() sealed;
			virtual void ReleasePointer() sealed;
			virtual void UnmanagedAttach();
			virtual void ManagedRegistered();
			virtual IDAGameFeatureClass^ AsUnmanagedObject() sealed;

			virtual void Init();

			property IntPtr DAGameFeatureClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr Pointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsAttached
			{
				virtual bool get() sealed;
			}

			property bool DestroyPointer
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
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

		protected:
			property ::DAGameFeatureClass* InternalDAGameFeatureClassPointer
			{
				virtual ::DAGameFeatureClass* get();
			}
	};
}