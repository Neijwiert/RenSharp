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

#include "Mengine_vector.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <AudioCallbackListClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	generic<typename T>
	public interface class IAudioCallbackStruct : public IUnmanagedObject
	{
		property T Callback
		{
			T get();
			void set(T value);
		}

		property uint32 UserData
		{
			uint32 get();
			void set(uint32 value);
		}
	};

	generic<typename T>
	public ref class AudioCallbackStruct abstract : public AbstractUnmanagedObject, public IAudioCallbackStruct<T>
	{
		public:
			AudioCallbackStruct(IntPtr pointer)
				: AbstractUnmanagedObject(pointer)
			{

			}

			property T Callback
			{
				virtual T get() = 0;
				virtual void set(T value) = 0;
			}

			property uint32 UserData
			{
				virtual uint32 get() = 0;
				virtual void set(uint32 value) = 0;
			}
	};

	generic<typename T>
	public interface class IAudioCallbackListClass : public ISimpleDynVecClass<IAudioCallbackStruct<T>^>
	{
		T GetCallback(int index, uint32% userData);

		T GetCallback(int index);

		void AddCallback(T callback, uint32 userData);

		void RemoveCallback(T callback);
	};

	generic<typename T>
	public ref class AudioCallbackListClass abstract : public SimpleDynVecClass<IAudioCallbackStruct<T>^>, public IAudioCallbackListClass<T>
	{
		public:
			AudioCallbackListClass(IntPtr pointer)
				: SimpleDynVecClass<IAudioCallbackStruct<T>^>(pointer)
			{

			}

			virtual T GetCallback(int index, uint32% userData) = 0;
			virtual T GetCallback(int index) = 0;
			virtual void AddCallback(T callback, uint32 userData) = 0;
			virtual void RemoveCallback(T callback) = 0;
	};
}