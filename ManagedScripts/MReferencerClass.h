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

#include "MPostLoadableClass.h"
#include "IUnmanagedContainer.h"

#pragma managed(push, off)

class ReferencerClass;

#pragma managed(pop)

using namespace System;

namespace RenSharp
{
	interface class IScriptableGameObj;

	public interface class IReferencerClass : public IPostLoadableClass
	{
		void AssignScriptableGameObj(IScriptableGameObj^ obj);

		property IntPtr ReferencerClassPointer
		{
			IntPtr get();
		}

		property IScriptableGameObj ^Ptr
		{
			IScriptableGameObj ^get();
			void set(IScriptableGameObj ^value);
		}
	};

	public ref class ReferencerClass : public PostLoadableClass, public IReferencerClass
	{
		private:
			ReferencerClass();
			ReferencerClass(IScriptableGameObj ^object);

		public:
			ReferencerClass(IntPtr pointer);

			static IUnmanagedContainer<IReferencerClass ^> ^CreateReferencerClass();
			static IUnmanagedContainer<IReferencerClass ^> ^CreateReferencerClass(IScriptableGameObj ^object);

			virtual void AssignScriptableGameObj(IScriptableGameObj^ obj) sealed;

			property IntPtr ReferencerClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IScriptableGameObj ^Ptr
			{
				virtual IScriptableGameObj ^get() sealed;
				virtual void set(IScriptableGameObj ^value) sealed;
			}

		protected:
			property ::PostLoadableClass *InternalPostLoadableClassPointer
			{
				::PostLoadableClass *get() override;
			}

			property ::ReferencerClass *InternalReferencerClassPointer
			{
				virtual ::ReferencerClass *get();
			}
	};
}