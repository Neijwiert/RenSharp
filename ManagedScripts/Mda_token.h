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

#include "IUnmanagedObject.h"
#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"

#pragma managed(push, off)

class DATokenParserClass;
class DATokenClass;

#pragma managed(pop)

using namespace System::Runtime::InteropServices;

namespace RenSharp
{
	public interface class IDATokenParserClass : public IUnmanagedObject
	{
		void Set(String ^str, wchar_t delim);

		String ^GetString();

		String ^GetRemainingString();

		bool GetInt([Out] int %buffer);

		bool GetUInt([Out] unsigned int %buffer);

		bool GetFloat([Out] float %buffer);

		property IntPtr DATokenParserClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DATokenParserClass : public AbstractUnmanagedObject, public IDATokenParserClass
	{
		private:
			DATokenParserClass(String ^str, wchar_t delim);

		public:
			DATokenParserClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			static IUnmanagedContainer<IDATokenParserClass ^> ^CreateDATokenParserClass(String ^str, wchar_t delim);

			virtual void Set(String ^str, wchar_t delim) sealed;
			virtual String ^GetString() sealed;
			virtual String ^GetRemainingString() sealed;
			virtual bool GetInt([Out] int %buffer) sealed;
			virtual bool GetUInt([Out] unsigned int %buffer) sealed;
			virtual bool GetFloat([Out] float %buffer) sealed;

			property IntPtr DATokenParserClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DATokenParserClass *InternalDATokenParserClassPointer
			{
				virtual ::DATokenParserClass *get();
			}
	};

	public interface class IDATokenClass : public IUnmanagedObject
	{
		void Build(IDATokenParserClass ^parser);

		void Build(String ^str, int startPos, wchar_t delim);

		void ToLower();

		String ^GetPartialToken(int start, int end);

		String ^GetPartialToken(int start);

		void Erase(int pos);

		void Replace(int pos, String ^newText);

		void Add(String ^text, int pos);

		void Add(String ^text);

		bool IsInt(int pos);

		bool IsUInt(int pos);

		bool IsFloat(int pos);

		int Find(String ^text);

		int Find(uint hash);

		bool AsInt(int pos, [Out] int %buffer);

		bool AsUInt(int pos, [Out] unsigned int %buffer);

		bool AsFloat(int pos, [Out] float %buffer);

		String ^AsString(int pos);

		property IntPtr DATokenClassPointer
		{
			IntPtr get();
		}

		property String ^Delimiter
		{
			String ^get();
		}

		property String ^default[int]
		{
			String ^get(int index);
		}

		property int Size
		{
			int get();
		}
	};

	public ref class DATokenClass : public AbstractUnmanagedObject, public IDATokenClass
	{
		private:
			DATokenClass();
			DATokenClass(String ^str, int startPos, wchar_t delim);
			DATokenClass(String ^str, int startPos);
			DATokenClass(String ^str);
			DATokenClass(IDATokenParserClass^ parser);

		public:
			DATokenClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			static IUnmanagedContainer<IDATokenClass ^> ^CreateDATokenClass();
			static IUnmanagedContainer<IDATokenClass ^> ^CreateDATokenClass(String ^str, int startPos, wchar_t delim);
			static IUnmanagedContainer<IDATokenClass ^> ^CreateDATokenClass(String ^str, int startPos);
			static IUnmanagedContainer<IDATokenClass ^> ^CreateDATokenClass(String ^str);
			static IUnmanagedContainer<IDATokenClass^>^ CreateDATokenClass(IDATokenParserClass^ parser);

			virtual void Build(IDATokenParserClass ^parser) sealed;
			virtual void Build(String ^str, int startPos, wchar_t delim) sealed;
			virtual void ToLower() sealed;
			virtual String ^GetPartialToken(int start, int end) sealed;
			virtual String ^GetPartialToken(int start) sealed;
			virtual void Erase(int pos) sealed;
			virtual void Replace(int pos, String ^newText) sealed;
			virtual void Add(String ^text, int pos) sealed;
			virtual void Add(String ^text) sealed;
			virtual bool IsInt(int pos) sealed;
			virtual bool IsUInt(int pos) sealed;
			virtual bool IsFloat(int pos) sealed;
			virtual int Find(String ^text) sealed;
			virtual int Find(uint hash) sealed;
			virtual bool AsInt(int pos, [Out] int %buffer) sealed;
			virtual bool AsUInt(int pos, [Out] unsigned int %buffer) sealed;
			virtual bool AsFloat(int pos, [Out] float %buffer) sealed;
			virtual String ^AsString(int pos) sealed;

			property IntPtr DATokenClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String ^Delimiter
			{
				virtual String ^get() sealed;
			}

			property String ^default[int]
			{
				virtual String ^get(int index) sealed;
			}

			property int Size
			{
				virtual int get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DATokenClass *InternalDATokenClassPointer
			{
				virtual ::DATokenClass *get();
			}
	};
}