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

#include "MPersist.h"
#include "Mengine_vector.h"

#pragma managed(push, off)

class TDBObjClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class ITDBObjClass : public IPersistClass
	{
		String^ GetString(uint32 langId);

		String^ GetString();

		void SetString(uint32 langId, String^ str);

		void SetEnglishString(String^ str);

		void SetID(uint32 id);

		void SetIDDesc(String^ desc);

		bool ContainsTranslation(uint32 langId);

		property IntPtr TDBObjClassPointer
		{
			IntPtr get();
		}

		property String^ EnglishString
		{
			String^ get();
		}

		property uint32 ID
		{
			uint32 get();
		}

		property String^ IDDesc
		{
			String^ get();
		}

		property uint32 SoundID
		{
			uint32 get();
			void set(uint32 value);
		}

		property String^ AnimationName
		{
			String^ get();
			void set(String^ value);
		}

		property uint32 CategoryID
		{
			uint32 get();
			void set(uint32 value);
		}
	};

	public ref class TDBObjClass : public PersistClass, public ITDBObjClass
	{
		public:
			TDBObjClass(IntPtr pointer);

			String^ ToString() override;

			virtual String^ GetString(uint32 langId) sealed;
			virtual String^ GetString() sealed;
			virtual void SetString(uint32 langId, String^ str) sealed;
			virtual void SetEnglishString(String^ str) sealed;
			virtual void SetID(uint32 id) sealed;
			virtual void SetIDDesc(String^ desc) sealed;
			virtual bool ContainsTranslation(uint32 langId) sealed;

			property IntPtr TDBObjClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String^ EnglishString
			{
				virtual String^ get() sealed;

				protected:
					void set(String^ value);
			}

			property uint32 ID
			{
				virtual uint32 get() sealed;

				protected:
					void set(uint32 value);
			}

			property String^ IDDesc
			{
				virtual String^ get() sealed;

				protected:
					void set(String^ value);
			}

			property uint32 SoundID
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

			property String^ AnimationName
			{
				virtual String^ get() sealed;
				virtual void set(String^ value) sealed;
			}

			property uint32 CategoryID
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

		protected:
			property ::PersistClass* InternalPersistClassPointer
			{
				::PersistClass* get() override;
			}

			property ::TDBObjClass* InternalTDBObjClassPointer
			{
				virtual ::TDBObjClass* get();
			}

			property IDynamicVectorClass<String^>^ TranslatedStrings
			{
				IDynamicVectorClass<String^>^ get();
				void set(IDynamicVectorClass<String^>^ value);
			}
	};
}