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

#include "MSaveLoadSubSystemClass.h"
#include "Mengine_vector.h"
#include "MHashTemplateClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <TranslateDBClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
#pragma managed(push, off)

	class TranslateDBClassHelper : public ::TranslateDBClass
	{
		public:
			static constexpr int IDMin = ::TranslateDBClass::ID_MIN;
			static constexpr int IDMax = ::TranslateDBClass::ID_MAX;

		private:
			TranslateDBClassHelper() = default;
	};

#pragma managed(pop)

	interface class ITDBObjClass;

	public interface class ITranslateDBClass : public ISaveLoadSubSystemClass
	{
		enum class LangID : uint32
		{
			LangIDEnglish = ::TranslateDBClass::LANGID_ENGLISH,
			LangIDFrench = ::TranslateDBClass::LANGID_FRENCH,
			LangIDGerman = ::TranslateDBClass::LANGID_GERMAN,
			LangIDSpanish = ::TranslateDBClass::LANGID_SPANISH,
			LangIDChinese = ::TranslateDBClass::LANGID_CHINESE,
			LangIDJapanese = ::TranslateDBClass::LANGID_JAPANESE,
			LangIDKorean = ::TranslateDBClass::LANGID_KOREAN
		};

		enum class FilterOpt : int
		{
			FilterDisabled = ::TranslateDBClass::FILTER_DISABLED,
			FilterIfEqual = ::TranslateDBClass::FILTER_IF_EQUAL,
			FilterIfNotEqual = ::TranslateDBClass::FILTER_IF_NOT_EQUAL,
		};

		property IntPtr TranslateDBClassPointer
		{
			IntPtr get();
		}
	};

	public ref class TranslateDBClass : public SaveLoadSubSystemClass, public ITranslateDBClass
	{
		public:
			TranslateDBClass(IntPtr pointer);

			static void Initialize();
			static void Shutdown();
			static void RemoveAll();
			static String^ GetString(uint32 id);
			static String^ GetString(String^ id);
			static String^ GetEnglishString(uint32 id);
			static ITDBObjClass^ FindObject(String^ id);
			static ITDBObjClass^ FindObject(uint32 id);

			static property String^ StringNotFound
			{
				String^ get();
			}

			static property String^ EnglishStringNotFound
			{
				String^ get();
			}

			static property uint32 VersionNumber
			{
				uint32 get();
			}

			static property bool IsLoaded
			{
				bool get();
			}

			static property int ObjectCount
			{
				int get();
			}

			static property uint32 CurrentLanguage
			{
				uint32 get();
				void set(uint32 value);
			}

			property IntPtr TranslateDBClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			literal int IDMin = TranslateDBClassHelper::IDMin;
			literal int IDMax = TranslateDBClassHelper::IDMax;

			property ::SaveLoadSubSystemClass* InternalSaveLoadSubSystemClassPointer
			{
				::SaveLoadSubSystemClass* get() override;
			}

			property ::TranslateDBClass* InternalTranslateDBClassPointer
			{
				virtual ::TranslateDBClass* get();
			}
	};
}