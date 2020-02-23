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

#include "Mengine_io.h"

#pragma managed(push, off)

class RawFileClass;
class TextFileClass;

#pragma managed(pop)

using namespace System::Runtime::InteropServices;

namespace RenSharp
{
	public interface class IRawFileClass : public IFileClass
	{
		void Reset();

		int RawSeek(int pos, int dir);

		void Attach(IntPtr handle, int rights);

		void Detach();

		property IntPtr RawFileClassPointer
		{
			IntPtr get();
		}

		property bool IsBiased
		{
			bool get();
		}

		property int TransferBlockSize
		{
			int get();
		}
	};

	public ref class RawFileClass : public FileClass, public IRawFileClass
	{
		protected:
			RawFileClass(bool create);

		private:
			RawFileClass(String^ filename);

		public:
			RawFileClass(IntPtr pointer);

			static IUnmanagedContainer<IRawFileClass^>^ CreateRawFileClass();
			static IUnmanagedContainer<IRawFileClass^>^ CreateRawFileClass(String^ filename);

			virtual void Reset() sealed;
			virtual int RawSeek(int pos, int dir) sealed;
			virtual void Attach(IntPtr handle, int rights) sealed;
			virtual void Detach() sealed;

			property IntPtr RawFileClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsBiased
			{
				virtual bool get() sealed;
			}

			property int TransferBlockSize
			{
				virtual int get() sealed;
			}

		protected:
			property ::FileClass* InternalFileClassPointer
			{
				::FileClass* get() override;
			}

			property ::RawFileClass* InternalRawFileClassPointer
			{
				virtual ::RawFileClass* get();
			}
	};

	public interface class ITextFileClass : public IRawFileClass
	{
		bool ReadLine([Out] String^% line);

		bool WriteLine(String^ str);

		property IntPtr TextFileClassPointer
		{
			IntPtr get();
		}
	};

	public ref class TextFileClass : public RawFileClass, public ITextFileClass
	{
		protected:
			TextFileClass(bool create);

		public:
			TextFileClass(IntPtr pointer);

			static IUnmanagedContainer<ITextFileClass^>^ CreateTextFileClass();

			virtual bool ReadLine([Out] String^% line) sealed;
			virtual bool WriteLine(String^ str) sealed;

			property IntPtr TextFileClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::RawFileClass* InternalRawFileClassPointer
			{
				::RawFileClass* get() override;
			}

			property ::TextFileClass* InternalTextFileClassPointer
			{
				virtual ::TextFileClass* get();
			}
	};
}