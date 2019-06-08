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

using namespace System;
using namespace System::Runtime::Serialization;
using namespace System::Security::Permissions;

namespace RenSharp
{
	[Serializable]
	public ref class FatalRenSharpException : public Exception
	{
		public:
			FatalRenSharpException();
			FatalRenSharpException(String ^message);
			FatalRenSharpException(String ^message, Exception ^inner);

			[SecurityPermission(SecurityAction::Demand, SerializationFormatter = true)]
			void GetObjectData(SerializationInfo ^info, StreamingContext context) override;

		protected:
			FatalRenSharpException(SerializationInfo ^info, StreamingContext context);
	};
}