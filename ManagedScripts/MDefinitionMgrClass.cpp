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

#include "stdafx.h"
#include "MDefinitionMgrClass.h"

#include "MDefinition.h"

using namespace System::Collections::Generic;

namespace RenSharp
{
	private ref class DefinitionEnumerable : IEnumerable<IDefinitionClass^>
	{
		private:
			ref class DefinitionEnumerator : IEnumerator<IDefinitionClass^>
			{
				private:
					IDefinitionClass^ current;
					bool reset;

				public:
					DefinitionEnumerator()
						: current(nullptr), reset(true)
					{

					}

					~DefinitionEnumerator()
					{

					}

					virtual bool MoveNext() = Collections::Generic::IEnumerator<IDefinitionClass^>::MoveNext
					{
						if (reset)
						{
							current = DefinitionMgrClass::GetFirst();

							reset = false;

							return (current != nullptr);
						}

						if (current == nullptr)
						{
							return false;
						}

						current = DefinitionMgrClass::GetNext(current);

						return (current != nullptr);
					}

					virtual void Reset() = Collections::Generic::IEnumerator<IDefinitionClass^>::Reset
					{
						current = nullptr;
						reset = true;
					}

					property IDefinitionClass^ Current
					{
						virtual IDefinitionClass^ get() = Collections::Generic::IEnumerator<IDefinitionClass^>::Current::get
						{
							return current;
						}
					}

					property Object^ Current2
					{
						virtual Object^ get() = Collections::IEnumerator::Current::get
						{
							return Current;
						}
					}
			};

		public:
			virtual IEnumerator<IDefinitionClass^>^ GetEnumerator() sealed
			{ 
				return gcnew DefinitionEnumerator();
			}

			virtual Collections::IEnumerator^ GetEnumerator2() sealed = Collections::IEnumerable::GetEnumerator
			{
				return GetEnumerator();
			}
	};

	DefinitionMgrClass::DefinitionMgrClass(IntPtr pointer)
		: SaveLoadSubSystemClass(pointer)
	{

	}

	IDefinitionClass ^DefinitionMgrClass::FindDefinition(uint32 id, bool twiddle)
	{
		auto defPtr = ::DefinitionMgrClass::Find_Definition(id, twiddle);
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			auto result = DefinitionClass::CreateDefinitionClassWrapper(defPtr);
			if (result == nullptr)
			{
				result = gcnew DefinitionClass(IntPtr(const_cast<::DefinitionClass*>(defPtr)));
			}

			return result;
		}
	}

	IDefinitionClass ^DefinitionMgrClass::FindNamedDefinition(String ^name, bool twiddle)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			auto defPtr = ::DefinitionMgrClass::Find_Named_Definition(
				reinterpret_cast<char *>(nameHandle.ToPointer()),
				twiddle);
			if (defPtr == nullptr)
			{
				return nullptr;
			}
			else
			{
				auto result = DefinitionClass::CreateDefinitionClassWrapper(defPtr);
				if (result == nullptr)
				{
					result = gcnew DefinitionClass(IntPtr(const_cast<::DefinitionClass*>(defPtr)));
				}

				return result;
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	IDefinitionClass ^DefinitionMgrClass::FindTypedDefinition(String ^name, uint32 classID, bool twiddle)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			auto defPtr = ::DefinitionMgrClass::Find_Typed_Definition(
				reinterpret_cast<char *>(nameHandle.ToPointer()),
				classID,
				twiddle);
			if (defPtr == nullptr)
			{
				return nullptr;
			}
			else
			{
				auto result = DefinitionClass::CreateDefinitionClassWrapper(defPtr);
				if (result == nullptr)
				{
					result = gcnew DefinitionClass(IntPtr(const_cast<::DefinitionClass*>(defPtr)));
				}

				return result;
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	void DefinitionMgrClass::RegisterDefinition(IDefinitionClass ^definition)
	{
		if (definition == nullptr || definition->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("definition");
		}

		::DefinitionMgrClass::Register_Definition(
			reinterpret_cast<::DefinitionClass *>(definition->DefinitionClassPointer.ToPointer()));
	}

	void DefinitionMgrClass::UnregisterDefinition(IDefinitionClass ^definition)
	{
		if (definition == nullptr || definition->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("definition");
		}

		::DefinitionMgrClass::Unregister_Definition(
			reinterpret_cast<::DefinitionClass *>(definition->DefinitionClassPointer.ToPointer()));
	}

	IDefinitionClass ^DefinitionMgrClass::GetFirst(uint32 id, IDefinitionMgrClass::IDType type)
	{
		auto defPtr = ::DefinitionMgrClass::Get_First(
			id,
			static_cast<::DefinitionMgrClass::ID_TYPE>(type));
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			auto result = DefinitionClass::CreateDefinitionClassWrapper(defPtr);
			if (result == nullptr)
			{
				result = gcnew DefinitionClass(IntPtr(const_cast<::DefinitionClass*>(defPtr)));
			}

			return result;
		}
	}

	IDefinitionClass ^DefinitionMgrClass::GetFirst(uint32 id)
	{
		auto defPtr = ::DefinitionMgrClass::Get_First(id);
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			auto result = DefinitionClass::CreateDefinitionClassWrapper(defPtr);
			if (result == nullptr)
			{
				result = gcnew DefinitionClass(IntPtr(const_cast<::DefinitionClass*>(defPtr)));
			}

			return result;
		}
	}

	IDefinitionClass ^DefinitionMgrClass::GetFirst()
	{
		auto defPtr = ::DefinitionMgrClass::Get_First();
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			auto result = DefinitionClass::CreateDefinitionClassWrapper(defPtr);
			if (result == nullptr)
			{
				result = gcnew DefinitionClass(IntPtr(const_cast<::DefinitionClass*>(defPtr)));
			}

			return result;
		}
	}

	IDefinitionClass ^DefinitionMgrClass::GetNext(IDefinitionClass ^currDef, uint32 id, IDefinitionMgrClass::IDType type)
	{
		if (currDef == nullptr || currDef->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("currDef");
		}

		auto defPtr = ::DefinitionMgrClass::Get_Next(
			reinterpret_cast<::DefinitionClass *>(currDef->DefinitionClassPointer.ToPointer()),
			id,
			static_cast<::DefinitionMgrClass::ID_TYPE>(type));
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			auto result = DefinitionClass::CreateDefinitionClassWrapper(defPtr);
			if (result == nullptr)
			{
				result = gcnew DefinitionClass(IntPtr(const_cast<::DefinitionClass*>(defPtr)));
			}

			return result;
		}
	}

	IDefinitionClass ^DefinitionMgrClass::GetNext(IDefinitionClass ^currDef, uint32 id)
	{
		if (currDef == nullptr || currDef->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("currDef");
		}

		auto defPtr = ::DefinitionMgrClass::Get_Next(
			reinterpret_cast<::DefinitionClass *>(currDef->DefinitionClassPointer.ToPointer()),
			id);
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			auto result = DefinitionClass::CreateDefinitionClassWrapper(defPtr);
			if (result == nullptr)
			{
				result = gcnew DefinitionClass(IntPtr(const_cast<::DefinitionClass*>(defPtr)));
			}

			return result;
		}
	}

	IDefinitionClass ^DefinitionMgrClass::GetNext(IDefinitionClass ^currDef)
	{
		if (currDef == nullptr || currDef->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("currDef");
		}

		auto defPtr = ::DefinitionMgrClass::Get_Next(
			reinterpret_cast<::DefinitionClass *>(currDef->DefinitionClassPointer.ToPointer()));
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			auto result = DefinitionClass::CreateDefinitionClassWrapper(defPtr);
			if (result == nullptr)
			{
				result = gcnew DefinitionClass(IntPtr(const_cast<::DefinitionClass*>(defPtr)));
			}

			return result;
		}
	}

	void DefinitionMgrClass::FreeDefinitions()
	{
		::DefinitionMgrClass::Free_Definitions();
	}

	IEnumerable<IDefinitionClass^>^ DefinitionMgrClass::GetDefinitions()
	{
		return gcnew DefinitionEnumerable();
	}

	IntPtr DefinitionMgrClass::DefinitionMgrClassPointer::get()
	{
		return IntPtr(InternalDefinitionMgrClassPointer);
	}

	::SaveLoadSubSystemClass *DefinitionMgrClass::InternalSaveLoadSubSystemClassPointer::get()
	{
		return InternalDefinitionMgrClassPointer;
	}

	::DefinitionMgrClass *DefinitionMgrClass::InternalDefinitionMgrClassPointer::get()
	{
		return reinterpret_cast<::DefinitionMgrClass *>(Pointer.ToPointer());
	}
}