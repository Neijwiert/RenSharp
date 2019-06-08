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

class MuzzleRecoilClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IMuzzleRecoilClass : IUnmanagedObject
	{
		property IntPtr MuzzleRecoilClassPointer
		{
			IntPtr get();
		}

		property bool IsRecoiling
		{
			bool get();
		}
	};

	public ref class MuzzleRecoilClass : public AbstractUnmanagedObject, public IMuzzleRecoilClass
	{
		public:
			MuzzleRecoilClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			property IntPtr MuzzleRecoilClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsRecoiling
			{
				virtual bool get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::MuzzleRecoilClass *InternalMuzzleRecoilClassPointer
			{
				virtual ::MuzzleRecoilClass *get();
			}
	};
}