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

class CommandLineParser;

#pragma managed(pop)

namespace RenSharp
{
	public interface class ICommandLineParser : public IUnmanagedObject
	{
		void Skip();

		String^ GetString();

		String^ GetRemainingString();

		int GetInt();

		double GetDouble();

		property IntPtr CommandLineParserPointer
		{
			IntPtr get();
		}
	};

	public ref class CommandLineParser : public AbstractUnmanagedObject, public ICommandLineParser
	{
		private:
			CommandLineParser(String^ command);

		public:
			CommandLineParser(IntPtr pointer);

			static IUnmanagedContainer<ICommandLineParser^>^ CreateCommandLineParser(String^ command);

			bool Equals(Object^ other) override;

			virtual void Skip() sealed;
			virtual String^ GetString() sealed;
			virtual String^ GetRemainingString() sealed;
			virtual int GetInt() sealed;
			virtual double GetDouble() sealed;

			property IntPtr CommandLineParserPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::CommandLineParser* InternalCommandLineParserPointer
			{
				virtual ::CommandLineParser* get();
			}
	};
}