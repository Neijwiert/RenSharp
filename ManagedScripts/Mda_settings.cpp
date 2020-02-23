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
#include "Mda_settings.h"

#include "Mengine_io.h"
#include "UnmanagedContainer.h"
#include "Imports.h"

using namespace System::Runtime::InteropServices;
using namespace System::Text;

namespace RenSharp
{
	DASettingsClass::DASettingsClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateDASettingsClass1()))
	{

	}

	DASettingsClass::DASettingsClass(String ^filename)
		: AbstractUnmanagedObject()
	{
		if (filename == nullptr)
		{
			throw gcnew ArgumentNullException("filename");
		}

		Pointer = IntPtr(Imports::CreateDASettingsClass2(filename));
	}

	DASettingsClass::DASettingsClass(IINIClass ^ini)
		: AbstractUnmanagedObject()
	{
		if (ini == nullptr || ini->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("ini");
		}

		Pointer = IntPtr(Imports::CreateDASettingsClass3(reinterpret_cast<::INIClass *>(ini->INIClassPointer.ToPointer())));
	}

	DASettingsClass::DASettingsClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool DASettingsClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDASettingsClass ^otherThis = dynamic_cast<IDASettingsClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DASettingsClassPointer.Equals(otherThis->DASettingsClassPointer);
	}

	String ^DASettingsClass::ToString()
	{
		StringBuilder ^builder = gcnew StringBuilder();
		builder->Append(Filename);

		return builder->ToString();
	}

	IUnmanagedContainer<IDASettingsClass ^> ^DASettingsClass::CreateDASettingsClass()
	{
		return gcnew UnmanagedContainer<IDASettingsClass ^>(gcnew DASettingsClass());
	}

	IUnmanagedContainer<IDASettingsClass ^> ^DASettingsClass::CreateDASettingsClass(String ^filename)
	{
		return gcnew UnmanagedContainer<IDASettingsClass ^>(gcnew DASettingsClass(filename));
	}

	IUnmanagedContainer<IDASettingsClass ^> ^DASettingsClass::CreateDASettingsClass(IINIClass ^ini)
	{
		return gcnew UnmanagedContainer<IDASettingsClass ^>(gcnew DASettingsClass(ini));
	}

	void DASettingsClass::Reload()
	{
		InternalDASettingsClassPointer->Reload();
	}

	void DASettingsClass::ReloadSilent()
	{
		InternalDASettingsClassPointer->Reload_Silent();
	}

	int DASettingsClass::GetInt(String ^entry, int defaultValue)
	{
		if (entry == nullptr)
		{
			return InternalDASettingsClassPointer->Get_Int(
				nullptr,
				defaultValue);
		}
		else
		{
			IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
			try
			{
				return InternalDASettingsClassPointer->Get_Int(
					reinterpret_cast<char *>(entryHandle.ToPointer()), 
					defaultValue);
			}
			finally
			{
				Marshal::FreeHGlobal(entryHandle);
			}
		}
	}

	int DASettingsClass::GetInt(String ^section, String ^entry, int defaultValue)
	{
		if (section == nullptr)
		{
			if (entry == nullptr)
			{
				return InternalDASettingsClassPointer->Get_Int(
					nullptr, 
					nullptr, 
					defaultValue);
			}
			else
			{
				IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					return InternalDASettingsClassPointer->Get_Int(
						nullptr, 
						reinterpret_cast<char *>(entryHandle.ToPointer()), 
						defaultValue);
				}
				finally
				{
					Marshal::FreeHGlobal(entryHandle);
				}
			}
		}
		else
		{
			IntPtr sectionHandle = Marshal::StringToHGlobalAnsi(section);
			try
			{
				if (entry == nullptr)
				{
					return InternalDASettingsClassPointer->Get_Int(
						reinterpret_cast<char *>(sectionHandle.ToPointer()), 
						nullptr, 
						defaultValue);
				}
				else
				{
					IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
					try
					{
						return InternalDASettingsClassPointer->Get_Int(
							reinterpret_cast<char *>(sectionHandle.ToPointer()), 
							reinterpret_cast<char *>(entryHandle.ToPointer()), 
							defaultValue);
					}
					finally
					{
						Marshal::FreeHGlobal(entryHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(sectionHandle);
			}
		}
	}

	int DASettingsClass::GetInt(String ^section1, String ^section2, String ^entry, int defaultValue)
	{
		if (section1 == nullptr)
		{
			if (section2 == nullptr)
			{
				if (entry == nullptr)
				{
					return InternalDASettingsClassPointer->Get_Int(
						nullptr,
						nullptr,
						nullptr,
						defaultValue);
				}
				else
				{
					IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
					try
					{
						return InternalDASettingsClassPointer->Get_Int(
							nullptr,
							nullptr,
							reinterpret_cast<char *>(entryHandle.ToPointer()),
							defaultValue);
					}
					finally
					{
						Marshal::FreeHGlobal(entryHandle);
					}
				}
			}
			else
			{
				IntPtr section2Handle = Marshal::StringToHGlobalAnsi(section2);
				try
				{
					if (entry == nullptr)
					{
						return InternalDASettingsClassPointer->Get_Int(
							nullptr,
							reinterpret_cast<char *>(section2Handle.ToPointer()),
							nullptr,
							defaultValue);
					}
					else
					{
						IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
						try
						{
							return InternalDASettingsClassPointer->Get_Int(
								nullptr,
								reinterpret_cast<char *>(section2Handle.ToPointer()),
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								defaultValue);
						}
						finally
						{
							Marshal::FreeHGlobal(entryHandle);
						}
					}
				}
				finally
				{
					Marshal::FreeHGlobal(section2Handle);
				}
			}
		}
		else
		{
			IntPtr section1Handle = Marshal::StringToHGlobalAnsi(section1);
			try
			{
				if (section2 == nullptr)
				{
					if (entry == nullptr)
					{
						return InternalDASettingsClassPointer->Get_Int(
							reinterpret_cast<char *>(section1Handle.ToPointer()),
							nullptr,
							nullptr,
							defaultValue);
					}
					else
					{
						IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
						try
						{
							return InternalDASettingsClassPointer->Get_Int(
								reinterpret_cast<char *>(section1Handle.ToPointer()),
								nullptr,
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								defaultValue);
						}
						finally
						{
							Marshal::FreeHGlobal(entryHandle);
						}
					}
				}
				else
				{
					IntPtr section2Handle = Marshal::StringToHGlobalAnsi(section2);
					try
					{
						if (entry == nullptr)
						{
							return InternalDASettingsClassPointer->Get_Int(
								reinterpret_cast<char *>(section1Handle.ToPointer()),
								reinterpret_cast<char *>(section2Handle.ToPointer()),
								nullptr,
								defaultValue);
						}
						else
						{
							IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
							try
							{
								return InternalDASettingsClassPointer->Get_Int(
									reinterpret_cast<char *>(section1Handle.ToPointer()),
									reinterpret_cast<char *>(section2Handle.ToPointer()),
									reinterpret_cast<char *>(entryHandle.ToPointer()),
									defaultValue);
							}
							finally
							{
								Marshal::FreeHGlobal(entryHandle);
							}
						}
					}
					finally
					{
						Marshal::FreeHGlobal(section2Handle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(section1Handle);
			}
		}
	}

	float DASettingsClass::GetFloat(String ^entry, float defaultValue)
	{
		if (entry == nullptr)
		{
			return InternalDASettingsClassPointer->Get_Float(
				nullptr,
				defaultValue);
		}
		else
		{
			IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
			try
			{
				return InternalDASettingsClassPointer->Get_Float(
					reinterpret_cast<char *>(entryHandle.ToPointer()),
					defaultValue);
			}
			finally
			{
				Marshal::FreeHGlobal(entryHandle);
			}
		}
	}

	float DASettingsClass::GetFloat(String ^section, String ^entry, float defaultValue)
	{
		if (section == nullptr)
		{
			if (entry == nullptr)
			{
				return InternalDASettingsClassPointer->Get_Float(
					nullptr,
					nullptr,
					defaultValue);
			}
			else
			{
				IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					return InternalDASettingsClassPointer->Get_Float(
						nullptr,
						reinterpret_cast<char *>(entryHandle.ToPointer()),
						defaultValue);
				}
				finally
				{
					Marshal::FreeHGlobal(entryHandle);
				}
			}
		}
		else
		{
			IntPtr sectionHandle = Marshal::StringToHGlobalAnsi(section);
			try
			{
				if (entry == nullptr)
				{
					return InternalDASettingsClassPointer->Get_Float(
						reinterpret_cast<char *>(sectionHandle.ToPointer()),
						nullptr,
						defaultValue);
				}
				else
				{
					IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
					try
					{
						return InternalDASettingsClassPointer->Get_Float(
							reinterpret_cast<char *>(sectionHandle.ToPointer()),
							reinterpret_cast<char *>(entryHandle.ToPointer()),
							defaultValue);
					}
					finally
					{
						Marshal::FreeHGlobal(entryHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(sectionHandle);
			}
		}
	}

	float DASettingsClass::GetFloat(String ^section1, String ^section2, String ^entry, float defaultValue)
	{
		if (section1 == nullptr)
		{
			if (section2 == nullptr)
			{
				if (entry == nullptr)
				{
					return InternalDASettingsClassPointer->Get_Float(
						nullptr,
						nullptr,
						nullptr,
						defaultValue);
				}
				else
				{
					IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
					try
					{
						return InternalDASettingsClassPointer->Get_Float(
							nullptr,
							nullptr,
							reinterpret_cast<char *>(entryHandle.ToPointer()),
							defaultValue);
					}
					finally
					{
						Marshal::FreeHGlobal(entryHandle);
					}
				}
			}
			else
			{
				IntPtr section2Handle = Marshal::StringToHGlobalAnsi(section2);
				try
				{
					if (entry == nullptr)
					{
						return InternalDASettingsClassPointer->Get_Float(
							nullptr,
							reinterpret_cast<char *>(section2Handle.ToPointer()),
							nullptr,
							defaultValue);
					}
					else
					{
						IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
						try
						{
							return InternalDASettingsClassPointer->Get_Float(
								nullptr,
								reinterpret_cast<char *>(section2Handle.ToPointer()),
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								defaultValue);
						}
						finally
						{
							Marshal::FreeHGlobal(entryHandle);
						}
					}
				}
				finally
				{
					Marshal::FreeHGlobal(section2Handle);
				}
			}
		}
		else
		{
			IntPtr section1Handle = Marshal::StringToHGlobalAnsi(section1);
			try
			{
				if (section2 == nullptr)
				{
					if (entry == nullptr)
					{
						return InternalDASettingsClassPointer->Get_Float(
							reinterpret_cast<char *>(section1Handle.ToPointer()),
							nullptr,
							nullptr,
							defaultValue);
					}
					else
					{
						IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
						try
						{
							return InternalDASettingsClassPointer->Get_Float(
								reinterpret_cast<char *>(section1Handle.ToPointer()),
								nullptr,
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								defaultValue);
						}
						finally
						{
							Marshal::FreeHGlobal(entryHandle);
						}
					}
				}
				else
				{
					IntPtr section2Handle = Marshal::StringToHGlobalAnsi(section2);
					try
					{
						if (entry == nullptr)
						{
							return InternalDASettingsClassPointer->Get_Float(
								reinterpret_cast<char *>(section1Handle.ToPointer()),
								reinterpret_cast<char *>(section2Handle.ToPointer()),
								nullptr,
								defaultValue);
						}
						else
						{
							IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
							try
							{
								return InternalDASettingsClassPointer->Get_Float(
									reinterpret_cast<char *>(section1Handle.ToPointer()),
									reinterpret_cast<char *>(section2Handle.ToPointer()),
									reinterpret_cast<char *>(entryHandle.ToPointer()),
									defaultValue);
							}
							finally
							{
								Marshal::FreeHGlobal(entryHandle);
							}
						}
					}
					finally
					{
						Marshal::FreeHGlobal(section2Handle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(section1Handle);
			}
		}
	}

	bool DASettingsClass::GetBool(String ^entry, bool defaultValue)
	{
		if (entry == nullptr)
		{
			return InternalDASettingsClassPointer->Get_Bool(
				nullptr,
				defaultValue);
		}
		else
		{
			IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
			try
			{
				return InternalDASettingsClassPointer->Get_Bool(
					reinterpret_cast<char *>(entryHandle.ToPointer()),
					defaultValue);
			}
			finally
			{
				Marshal::FreeHGlobal(entryHandle);
			}
		}
	}

	bool DASettingsClass::GetBool(String ^section, String ^entry, bool defaultValue)
	{
		if (section == nullptr)
		{
			if (entry == nullptr)
			{
				return InternalDASettingsClassPointer->Get_Bool(
					nullptr,
					nullptr,
					defaultValue);
			}
			else
			{
				IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					return InternalDASettingsClassPointer->Get_Bool(
						nullptr,
						reinterpret_cast<char *>(entryHandle.ToPointer()),
						defaultValue);
				}
				finally
				{
					Marshal::FreeHGlobal(entryHandle);
				}
			}
		}
		else
		{
			IntPtr sectionHandle = Marshal::StringToHGlobalAnsi(section);
			try
			{
				if (entry == nullptr)
				{
					return InternalDASettingsClassPointer->Get_Bool(
						reinterpret_cast<char *>(sectionHandle.ToPointer()),
						nullptr,
						defaultValue);
				}
				else
				{
					IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
					try
					{
						return InternalDASettingsClassPointer->Get_Bool(
							reinterpret_cast<char *>(sectionHandle.ToPointer()),
							reinterpret_cast<char *>(entryHandle.ToPointer()),
							defaultValue);
					}
					finally
					{
						Marshal::FreeHGlobal(entryHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(sectionHandle);
			}
		}
	}

	bool DASettingsClass::GetBool(String ^section1, String ^section2, String ^entry, bool defaultValue)
	{
		if (section1 == nullptr)
		{
			if (section2 == nullptr)
			{
				if (entry == nullptr)
				{
					return InternalDASettingsClassPointer->Get_Bool(
						nullptr,
						nullptr,
						nullptr,
						defaultValue);
				}
				else
				{
					IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
					try
					{
						return InternalDASettingsClassPointer->Get_Bool(
							nullptr,
							nullptr,
							reinterpret_cast<char *>(entryHandle.ToPointer()),
							defaultValue);
					}
					finally
					{
						Marshal::FreeHGlobal(entryHandle);
					}
				}
			}
			else
			{
				IntPtr section2Handle = Marshal::StringToHGlobalAnsi(section2);
				try
				{
					if (entry == nullptr)
					{
						return InternalDASettingsClassPointer->Get_Bool(
							nullptr,
							reinterpret_cast<char *>(section2Handle.ToPointer()),
							nullptr,
							defaultValue);
					}
					else
					{
						IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
						try
						{
							return InternalDASettingsClassPointer->Get_Bool(
								nullptr,
								reinterpret_cast<char *>(section2Handle.ToPointer()),
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								defaultValue);
						}
						finally
						{
							Marshal::FreeHGlobal(entryHandle);
						}
					}
				}
				finally
				{
					Marshal::FreeHGlobal(section2Handle);
				}
			}
		}
		else
		{
			IntPtr section1Handle = Marshal::StringToHGlobalAnsi(section1);
			try
			{
				if (section2 == nullptr)
				{
					if (entry == nullptr)
					{
						return InternalDASettingsClassPointer->Get_Bool(
							reinterpret_cast<char *>(section1Handle.ToPointer()),
							nullptr,
							nullptr,
							defaultValue);
					}
					else
					{
						IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
						try
						{
							return InternalDASettingsClassPointer->Get_Bool(
								reinterpret_cast<char *>(section1Handle.ToPointer()),
								nullptr,
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								defaultValue);
						}
						finally
						{
							Marshal::FreeHGlobal(entryHandle);
						}
					}
				}
				else
				{
					IntPtr section2Handle = Marshal::StringToHGlobalAnsi(section2);
					try
					{
						if (entry == nullptr)
						{
							return InternalDASettingsClassPointer->Get_Bool(
								reinterpret_cast<char *>(section1Handle.ToPointer()),
								reinterpret_cast<char *>(section2Handle.ToPointer()),
								nullptr,
								defaultValue);
						}
						else
						{
							IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
							try
							{
								return InternalDASettingsClassPointer->Get_Bool(
									reinterpret_cast<char *>(section1Handle.ToPointer()),
									reinterpret_cast<char *>(section2Handle.ToPointer()),
									reinterpret_cast<char *>(entryHandle.ToPointer()),
									defaultValue);
							}
							finally
							{
								Marshal::FreeHGlobal(entryHandle);
							}
						}
					}
					finally
					{
						Marshal::FreeHGlobal(section2Handle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(section1Handle);
			}
		}
	}

	String ^DASettingsClass::GetString(String ^entry, String ^defaultValue)
	{
		::StringClass result;

		if (entry == nullptr)
		{
			if (defaultValue == nullptr)
			{
				InternalDASettingsClassPointer->Get_String(
					result,
					nullptr,
					nullptr);
			}
			else
			{
				IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
				try
				{
					InternalDASettingsClassPointer->Get_String(
						result,
						nullptr,
						reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
				}
				finally
				{
					Marshal::FreeHGlobal(defaultValueHandle);
				}
			}
		}
		else
		{
			IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
			try
			{
				if (defaultValue == nullptr)
				{
					InternalDASettingsClassPointer->Get_String(
						result,
						reinterpret_cast<char *>(entryHandle.ToPointer()),
						nullptr);
				}
				else
				{
					IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
					try
					{
						InternalDASettingsClassPointer->Get_String(
							result,
							reinterpret_cast<char *>(entryHandle.ToPointer()),
							reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
					}
					finally
					{
						Marshal::FreeHGlobal(defaultValueHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(entryHandle);
			}
		}

		return gcnew String(result.Peek_Buffer());
	}

	String ^DASettingsClass::GetString(String ^section, String ^entry, String ^defaultValue)
	{
		::StringClass result;

		if (section == nullptr)
		{
			if (entry == nullptr)
			{
				if (defaultValue == nullptr)
				{
					InternalDASettingsClassPointer->Get_String(
						result,
						nullptr,
						nullptr,
						nullptr);
				}
				else
				{
					IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
					try
					{
						InternalDASettingsClassPointer->Get_String(
							result,
							nullptr,
							nullptr,
							reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
					}
					finally
					{
						Marshal::FreeHGlobal(defaultValueHandle);
					}
				}
			}
			else
			{
				IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					if (defaultValue == nullptr)
					{
						InternalDASettingsClassPointer->Get_String(
							result,
							nullptr,
							reinterpret_cast<char *>(entryHandle.ToPointer()),
							nullptr);
					}
					else
					{
						IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
						try
						{
							InternalDASettingsClassPointer->Get_String(
								result,
								nullptr,
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
						}
						finally
						{
							Marshal::FreeHGlobal(defaultValueHandle);
						}
					}
				}
				finally
				{
					Marshal::FreeHGlobal(entryHandle);
				}
			}
		}
		else
		{
			IntPtr sectionHandle = Marshal::StringToHGlobalAnsi(section);
			try
			{
				if (entry == nullptr)
				{
					if (defaultValue == nullptr)
					{
						InternalDASettingsClassPointer->Get_String(
							result,
							reinterpret_cast<char *>(sectionHandle.ToPointer()),
							nullptr,
							nullptr);
					}
					else
					{
						IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
						try
						{
							InternalDASettingsClassPointer->Get_String(
								result,
								reinterpret_cast<char *>(sectionHandle.ToPointer()),
								nullptr,
								reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
						}
						finally
						{
							Marshal::FreeHGlobal(defaultValueHandle);
						}
					}
				}
				else
				{
					IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
					try
					{
						if (defaultValue == nullptr)
						{
							InternalDASettingsClassPointer->Get_String(
								result,
								reinterpret_cast<char *>(sectionHandle.ToPointer()),
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								nullptr);
						}
						else
						{
							IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
							try
							{
								InternalDASettingsClassPointer->Get_String(
									result,
									reinterpret_cast<char *>(sectionHandle.ToPointer()),
									reinterpret_cast<char *>(entryHandle.ToPointer()),
									reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
							}
							finally
							{
								Marshal::FreeHGlobal(defaultValueHandle);
							}
						}
					}
					finally
					{
						Marshal::FreeHGlobal(entryHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(sectionHandle);
			}
		}

		return gcnew String(result.Peek_Buffer());
	}

	String ^DASettingsClass::GetString(String ^section1, String ^section2, String ^entry, String ^defaultValue)
	{
		::StringClass result;

		if (section1 == nullptr)
		{
			if (section2 == nullptr)
			{
				if (entry == nullptr)
				{
					if (defaultValue == nullptr)
					{
						InternalDASettingsClassPointer->Get_String(
							result,
							nullptr,
							nullptr,
							nullptr,
							nullptr);
					}
					else
					{
						IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
						try
						{
							InternalDASettingsClassPointer->Get_String(
								result,
								nullptr,
								nullptr,
								nullptr,
								reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
						}
						finally
						{
							Marshal::FreeHGlobal(defaultValueHandle);
						}
					}
				}
				else
				{
					IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
					try
					{
						if (defaultValue == nullptr)
						{
							InternalDASettingsClassPointer->Get_String(
								result,
								nullptr,
								nullptr,
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								nullptr);
						}
						else
						{
							IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
							try
							{
								InternalDASettingsClassPointer->Get_String(
									result,
									nullptr,
									nullptr,
									reinterpret_cast<char *>(entryHandle.ToPointer()),
									reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
							}
							finally
							{
								Marshal::FreeHGlobal(defaultValueHandle);
							}
						}
					}
					finally
					{
						Marshal::FreeHGlobal(entryHandle);
					}
				}
			}
			else
			{
				IntPtr section2Handle = Marshal::StringToHGlobalAnsi(section2);
				try
				{
					if (entry == nullptr)
					{
						if (defaultValue == nullptr)
						{
							InternalDASettingsClassPointer->Get_String(
								result,
								nullptr,
								reinterpret_cast<char *>(section2Handle.ToPointer()),
								nullptr,
								nullptr);
						}
						else
						{
							IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
							try
							{
								InternalDASettingsClassPointer->Get_String(
									result,
									nullptr,
									reinterpret_cast<char *>(section2Handle.ToPointer()),
									nullptr,
									reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
							}
							finally
							{
								Marshal::FreeHGlobal(defaultValueHandle);
							}
						}
					}
					else
					{
						IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
						try
						{
							if (defaultValue == nullptr)
							{
								InternalDASettingsClassPointer->Get_String(
									result,
									nullptr,
									reinterpret_cast<char *>(section2Handle.ToPointer()),
									reinterpret_cast<char *>(entryHandle.ToPointer()),
									nullptr);
							}
							else
							{
								IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
								try
								{
									InternalDASettingsClassPointer->Get_String(
										result,
										nullptr,
										reinterpret_cast<char *>(section2Handle.ToPointer()),
										reinterpret_cast<char *>(entryHandle.ToPointer()),
										reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
								}
								finally
								{
									Marshal::FreeHGlobal(defaultValueHandle);
								}
							}
						}
						finally
						{
							Marshal::FreeHGlobal(entryHandle);
						}
					}
				}
				finally
				{
					Marshal::FreeHGlobal(section2Handle);
				}
			}
		}
		else
		{
			IntPtr section1Handle = Marshal::StringToHGlobalAnsi(section1);
			try
			{
				if (section2 == nullptr)
				{
					if (entry == nullptr)
					{
						if (defaultValue == nullptr)
						{
							InternalDASettingsClassPointer->Get_String(
								result,
								reinterpret_cast<char *>(section1Handle.ToPointer()),
								nullptr,
								nullptr,
								nullptr);
						}
						else
						{
							IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
							try
							{
								InternalDASettingsClassPointer->Get_String(
									result,
									reinterpret_cast<char *>(section1Handle.ToPointer()),
									nullptr,
									nullptr,
									reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
							}
							finally
							{
								Marshal::FreeHGlobal(defaultValueHandle);
							}
						}
					}
					else
					{
						IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
						try
						{
							if (defaultValue == nullptr)
							{
								InternalDASettingsClassPointer->Get_String(
									result,
									reinterpret_cast<char *>(section1Handle.ToPointer()),
									nullptr,
									reinterpret_cast<char *>(entryHandle.ToPointer()),
									nullptr);
							}
							else
							{
								IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
								try
								{
									InternalDASettingsClassPointer->Get_String(
										result,
										reinterpret_cast<char *>(section1Handle.ToPointer()),
										nullptr,
										reinterpret_cast<char *>(entryHandle.ToPointer()),
										reinterpret_cast<char *>(defaultValueHandle.ToPointer()));

								}
								finally
								{
									Marshal::FreeHGlobal(defaultValueHandle);
								}
							}
						}
						finally
						{
							Marshal::FreeHGlobal(entryHandle);
						}
					}
				}
				else
				{
					IntPtr section2Handle = Marshal::StringToHGlobalAnsi(section2);
					try
					{
						if (entry == nullptr)
						{
							if (defaultValue == nullptr)
							{
								InternalDASettingsClassPointer->Get_String(
									result,
									reinterpret_cast<char *>(section1Handle.ToPointer()),
									reinterpret_cast<char *>(section2Handle.ToPointer()),
									nullptr,
									nullptr);
							}
							else
							{
								IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
								try
								{
									InternalDASettingsClassPointer->Get_String(
										result,
										reinterpret_cast<char *>(section1Handle.ToPointer()),
										reinterpret_cast<char *>(section2Handle.ToPointer()),
										nullptr,
										reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
								}
								finally
								{
									Marshal::FreeHGlobal(defaultValueHandle);
								}
							}
						}
						else
						{
							IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
							try
							{
								if (defaultValue == nullptr)
								{
									InternalDASettingsClassPointer->Get_String(
										result,
										reinterpret_cast<char *>(section1Handle.ToPointer()),
										reinterpret_cast<char *>(section2Handle.ToPointer()),
										reinterpret_cast<char *>(entryHandle.ToPointer()),
										nullptr);
								}
								else
								{
									IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
									try
									{
										InternalDASettingsClassPointer->Get_String(
											result,
											reinterpret_cast<char *>(section1Handle.ToPointer()),
											reinterpret_cast<char *>(section2Handle.ToPointer()),
											reinterpret_cast<char *>(entryHandle.ToPointer()),
											reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
									}
									finally
									{
										Marshal::FreeHGlobal(defaultValueHandle);
									}
								}
							}
							finally
							{
								Marshal::FreeHGlobal(entryHandle);
							}
						}
					}
					finally
					{
						Marshal::FreeHGlobal(section2Handle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(section1Handle);
			}
		}

		return gcnew String(result.Peek_Buffer());
	}

	Vector3 DASettingsClass::GetVector3(String ^entry, Vector3 defaultValue)
	{
		::Vector3 result;

		IntPtr defaultValueHandle = Marshal::AllocHGlobal(Marshal::SizeOf(Vector3::typeid));
		try
		{
			Marshal::StructureToPtr(defaultValue, defaultValueHandle, false);

			if (entry == nullptr)
			{
				InternalDASettingsClassPointer->Get_Vector3(
					result,
					nullptr,
					*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
			}
			else
			{
				IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					InternalDASettingsClassPointer->Get_Vector3(
						result,
						reinterpret_cast<char *>(entryHandle.ToPointer()),
						*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
				}
				finally
				{
					Marshal::FreeHGlobal(entryHandle);
				}
			}
		}
		finally
		{
			Marshal::FreeHGlobal(defaultValueHandle);
		}

		return Marshal::PtrToStructure<Vector3>(IntPtr(&result));
	}

	Vector3 DASettingsClass::GetVector3(String ^section, String ^entry, Vector3 defaultValue)
	{
		::Vector3 result;

		IntPtr defaultValueHandle = Marshal::AllocHGlobal(Marshal::SizeOf(Vector3::typeid));
		try
		{
			Marshal::StructureToPtr(defaultValue, defaultValueHandle, false);

			if (section == nullptr)
			{
				if (entry == nullptr)
				{
					InternalDASettingsClassPointer->Get_Vector3(
						result,
						nullptr,
						nullptr,
						*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
				}
				else
				{
					IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
					try
					{
						InternalDASettingsClassPointer->Get_Vector3(
							result,
							nullptr,
							reinterpret_cast<char *>(entryHandle.ToPointer()),
							*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
					}
					finally
					{
						Marshal::FreeHGlobal(entryHandle);
					}
				}
			}
			else
			{
				IntPtr sectionHandle = Marshal::StringToHGlobalAnsi(section);
				try
				{
					if (entry == nullptr)
					{
						InternalDASettingsClassPointer->Get_Vector3(
							result,
							reinterpret_cast<char *>(sectionHandle.ToPointer()),
							nullptr,
							*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
					}
					else
					{
						IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
						try
						{
							InternalDASettingsClassPointer->Get_Vector3(
								result,
								reinterpret_cast<char *>(sectionHandle.ToPointer()),
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
						}
						finally
						{
							Marshal::FreeHGlobal(entryHandle);
						}
					}
				}
				finally
				{
					Marshal::FreeHGlobal(sectionHandle);
				}
			}
		}
		finally
		{
			Marshal::FreeHGlobal(defaultValueHandle);
		}

		return Marshal::PtrToStructure<Vector3>(IntPtr(&result));
	}

	Vector3 DASettingsClass::GetVector3(String ^section1, String ^section2, String ^entry, Vector3 defaultValue)
	{
		::Vector3 result;

		IntPtr defaultValueHandle = Marshal::AllocHGlobal(Marshal::SizeOf(Vector3::typeid));
		try
		{
			Marshal::StructureToPtr(defaultValue, defaultValueHandle, false);

			if (section1 == nullptr)
			{
				if (section2 == nullptr)
				{
					if (entry == nullptr)
					{
						InternalDASettingsClassPointer->Get_Vector3(
							result,
							nullptr,
							nullptr,
							nullptr,
							*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
					}
					else
					{
						IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
						try
						{
							InternalDASettingsClassPointer->Get_Vector3(
								result,
								nullptr,
								nullptr,
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
						}
						finally
						{
							Marshal::FreeHGlobal(entryHandle);
						}
					}
				}
				else
				{
					IntPtr section2Handle = Marshal::StringToHGlobalAnsi(section2);
					try
					{
						if (entry == nullptr)
						{
							InternalDASettingsClassPointer->Get_Vector3(
								result,
								nullptr,
								reinterpret_cast<char *>(section2Handle.ToPointer()),
								nullptr,
								*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
						}
						else
						{
							IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
							try
							{
								InternalDASettingsClassPointer->Get_Vector3(
									result,
									nullptr,
									reinterpret_cast<char *>(section2Handle.ToPointer()),
									reinterpret_cast<char *>(entryHandle.ToPointer()),
									*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
							}
							finally
							{
								Marshal::FreeHGlobal(entryHandle);
							}
						}
					}
					finally
					{
						Marshal::FreeHGlobal(section2Handle);
					}
				}
			}
			else
			{
				IntPtr section1Handle = Marshal::StringToHGlobalAnsi(section1);
				try
				{
					if (section2 == nullptr)
					{
						if (entry == nullptr)
						{
							InternalDASettingsClassPointer->Get_Vector3(
								result,
								reinterpret_cast<char *>(section1Handle.ToPointer()),
								nullptr,
								nullptr,
								*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
						}
						else
						{
							IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
							try
							{
								InternalDASettingsClassPointer->Get_Vector3(
									result,
									reinterpret_cast<char *>(section1Handle.ToPointer()),
									nullptr,
									reinterpret_cast<char *>(entryHandle.ToPointer()),
									*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
							}
							finally
							{
								Marshal::FreeHGlobal(entryHandle);
							}
						}
					}
					else
					{
						IntPtr section2Handle = Marshal::StringToHGlobalAnsi(section2);
						try
						{
							if (entry == nullptr)
							{
								InternalDASettingsClassPointer->Get_Vector3(
									result,
									reinterpret_cast<char *>(section1Handle.ToPointer()),
									reinterpret_cast<char *>(section2Handle.ToPointer()),
									nullptr,
									*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
							}
							else
							{
								IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
								try
								{
									InternalDASettingsClassPointer->Get_Vector3(
										result,
										reinterpret_cast<char *>(section1Handle.ToPointer()),
										reinterpret_cast<char *>(section2Handle.ToPointer()),
										reinterpret_cast<char *>(entryHandle.ToPointer()),
										*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
								}
								finally
								{
									Marshal::FreeHGlobal(entryHandle);
								}
							}
						}
						finally
						{
							Marshal::FreeHGlobal(section2Handle);
						}
					}
				}
				finally
				{
					Marshal::FreeHGlobal(section1Handle);
				}
			}
		}
		finally
		{
			Marshal::FreeHGlobal(defaultValueHandle);
		}

		return Marshal::PtrToStructure<Vector3>(IntPtr(&result));
	}

	IINISection ^DASettingsClass::GetSection(String ^section)
	{
		::INISection *result;
		if (section == nullptr)
		{
			result = InternalDASettingsClassPointer->Get_Section(nullptr);
		}
		else
		{
			IntPtr sectionHandle = Marshal::StringToHGlobalAnsi(section);
			try
			{
				result = InternalDASettingsClassPointer->Get_Section(reinterpret_cast<char *>(sectionHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(sectionHandle);
			}
		}

		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INISection(IntPtr(result));
		}
	}

	IntPtr DASettingsClass::DASettingsClassPointer::get()
	{
		return IntPtr(InternalDASettingsClassPointer);
	}

	IINIClass ^DASettingsClass::INI::get()
	{
		auto ini = const_cast<::INIClass *>(InternalDASettingsClassPointer->Get_INI());
		if (ini == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INIClass(IntPtr(ini));
		}
	}

	String ^DASettingsClass::Filename::get()
	{
		auto filename = InternalDASettingsClassPointer->Get_File_Name();
		if (filename == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(filename);
		}
	}

	bool DASettingsClass::InternalDestroyPointer()
	{
		Imports::DestroyDASettingsClass(InternalDASettingsClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DASettingsClass *DASettingsClass::InternalDASettingsClassPointer::get()
	{
		return reinterpret_cast<::DASettingsClass *>(Pointer.ToPointer());
	}

	IINISection ^DASettingsManager::GetSection(String ^section)
	{
		::INISection *sectionPtr;

		if (section == nullptr)
		{
			sectionPtr = ::DASettingsManager::Get_Section(nullptr);
		}
		else
		{
			IntPtr sectionHandle = Marshal::StringToHGlobalAnsi(section);
			try
			{
				sectionPtr = ::DASettingsManager::Get_Section(reinterpret_cast<char *>(sectionHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(sectionHandle);
			}
		}

		if (sectionPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INISection(IntPtr(sectionPtr));
		}
	}

	void DASettingsManager::Shutdown()
	{
		::DASettingsManager::Shutdown();
	}

	void DASettingsManager::Reload()
	{
		::DASettingsManager::Reload();
	}

	void DASettingsManager::ReloadSilent()
	{
		::DASettingsManager::Reload_Silent();
	}

	void DASettingsManager::AddSettings(String ^filename)
	{
		if (filename == nullptr)
		{
			throw gcnew ArgumentNullException("filename");
		}

		IntPtr filenameHandle = Marshal::StringToHGlobalAnsi(filename);
		try
		{
			::DASettingsManager::Add_Settings(reinterpret_cast<char *>(filenameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(filenameHandle);
		}
	}

	void DASettingsManager::RemoveSettings(String ^filename)
	{
		if (filename == nullptr)
		{
			throw gcnew ArgumentNullException("filename");
		}

		IntPtr filenameHandle = Marshal::StringToHGlobalAnsi(filename);
		try
		{
			::DASettingsManager::Remove_Settings(reinterpret_cast<char *>(filenameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(filenameHandle);
		}
	}

	void DASettingsManager::RemoveSettings(int position)
	{
		if (position < 0 || position >= ::DASettingsManager::Get_Settings_Count())
		{
			throw gcnew ArgumentOutOfRangeException("position");
		}

		::DASettingsManager::Remove_Settings(position);
	}

	IDASettingsClass ^DASettingsManager::GetSettings(String ^filename)
	{
		if (filename == nullptr)
		{
			throw gcnew ArgumentNullException("filename");
		}

		// The actual DASettingsManager::Get_Settings(const char *) implementation uses literal pointer comparison on the strings
		// Which is dumb and we cant really use that
		IntPtr filenameHandle = Marshal::StringToHGlobalAnsi(filename);
		try
		{
			char *filenamePtr = reinterpret_cast<char *>(filenameHandle.ToPointer());

			int settingsCount = ::DASettingsManager::Get_Settings_Count();
			for (int x = 0; x < settingsCount; x++)
			{
				auto currentSettings = const_cast<::DASettingsClass *>(::DASettingsManager::Get_Settings(x));
				if (currentSettings != nullptr && !_stricmp(currentSettings->Get_File_Name(), filenamePtr))
				{
					return gcnew DASettingsClass(IntPtr(currentSettings));
				}
			}
		}
		finally
		{
			Marshal::FreeHGlobal(filenameHandle);
		}

		return nullptr;
	}

	IDASettingsClass ^DASettingsManager::GetSettings(int position)
	{
		if (position < 0 || position >= ::DASettingsManager::Get_Settings_Count())
		{
			throw gcnew ArgumentOutOfRangeException("position");
		}

		auto result = const_cast<::DASettingsClass *>(::DASettingsManager::Get_Settings(position));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DASettingsClass(IntPtr(result));
		}
	}

	int DASettingsManager::GetInt(String ^entry, int defaultValue)
	{
		if (entry == nullptr)
		{
			return ::DASettingsManager::Get_Int(
				nullptr,
				defaultValue);
		}
		else
		{
			IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
			try
			{
				return ::DASettingsManager::Get_Int(
					reinterpret_cast<char *>(entryHandle.ToPointer()),
					defaultValue);
			}
			finally
			{
				Marshal::FreeHGlobal(entryHandle);
			}
		}
	}

	int DASettingsManager::GetInt(String ^section, String ^entry, int defaultValue)
	{
		if (section == nullptr)
		{
			if (entry == nullptr)
			{
				return ::DASettingsManager::Get_Int(
					nullptr,
					nullptr,
					defaultValue);
			}
			else
			{
				IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					return ::DASettingsManager::Get_Int(
						nullptr,
						reinterpret_cast<char *>(entryHandle.ToPointer()),
						defaultValue);
				}
				finally
				{
					Marshal::FreeHGlobal(entryHandle);
				}
			}
		}
		else
		{
			IntPtr sectionHandle = Marshal::StringToHGlobalAnsi(section);
			try
			{
				if (entry == nullptr)
				{
					return ::DASettingsManager::Get_Int(
						reinterpret_cast<char *>(sectionHandle.ToPointer()),
						nullptr,
						defaultValue);
				}
				else
				{
					IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
					try
					{
						return ::DASettingsManager::Get_Int(
							reinterpret_cast<char *>(sectionHandle.ToPointer()),
							reinterpret_cast<char *>(entryHandle.ToPointer()),
							defaultValue);
					}
					finally
					{
						Marshal::FreeHGlobal(entryHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(sectionHandle);
			}
		}
	}

	int DASettingsManager::GetInt(String ^section1, String ^section2, String ^entry, int defaultValue)
	{
		if (section1 == nullptr)
		{
			if (section2 == nullptr)
			{
				if (entry == nullptr)
				{
					return ::DASettingsManager::Get_Int(
						nullptr,
						nullptr,
						nullptr,
						defaultValue);
				}
				else
				{
					IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
					try
					{
						return ::DASettingsManager::Get_Int(
							nullptr,
							nullptr,
							reinterpret_cast<char *>(entryHandle.ToPointer()),
							defaultValue);
					}
					finally
					{
						Marshal::FreeHGlobal(entryHandle);
					}
				}
			}
			else
			{
				IntPtr section2Handle = Marshal::StringToHGlobalAnsi(section2);
				try
				{
					if (entry == nullptr)
					{
						return ::DASettingsManager::Get_Int(
							nullptr,
							reinterpret_cast<char *>(section2Handle.ToPointer()),
							nullptr,
							defaultValue);
					}
					else
					{
						IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
						try
						{
							return ::DASettingsManager::Get_Int(
								nullptr,
								reinterpret_cast<char *>(section2Handle.ToPointer()),
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								defaultValue);
						}
						finally
						{
							Marshal::FreeHGlobal(entryHandle);
						}
					}
				}
				finally
				{
					Marshal::FreeHGlobal(section2Handle);
				}
			}
		}
		else
		{
			IntPtr section1Handle = Marshal::StringToHGlobalAnsi(section1);
			try
			{
				if (section2 == nullptr)
				{
					if (entry == nullptr)
					{
						return ::DASettingsManager::Get_Int(
							reinterpret_cast<char *>(section1Handle.ToPointer()),
							nullptr,
							nullptr,
							defaultValue);
					}
					else
					{
						IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
						try
						{
							return ::DASettingsManager::Get_Int(
								reinterpret_cast<char *>(section1Handle.ToPointer()),
								nullptr,
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								defaultValue);
						}
						finally
						{
							Marshal::FreeHGlobal(entryHandle);
						}
					}
				}
				else
				{
					IntPtr section2Handle = Marshal::StringToHGlobalAnsi(section2);
					try
					{
						if (entry == nullptr)
						{
							return ::DASettingsManager::Get_Int(
								reinterpret_cast<char *>(section1Handle.ToPointer()),
								reinterpret_cast<char *>(section2Handle.ToPointer()),
								nullptr,
								defaultValue);
						}
						else
						{
							IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
							try
							{
								return ::DASettingsManager::Get_Int(
									reinterpret_cast<char *>(section1Handle.ToPointer()),
									reinterpret_cast<char *>(section2Handle.ToPointer()),
									reinterpret_cast<char *>(entryHandle.ToPointer()),
									defaultValue);
							}
							finally
							{
								Marshal::FreeHGlobal(entryHandle);
							}
						}
					}
					finally
					{
						Marshal::FreeHGlobal(section2Handle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(section1Handle);
			}
		}
	}

	float DASettingsManager::GetFloat(String ^entry, float defaultValue)
	{
		if (entry == nullptr)
		{
			return ::DASettingsManager::Get_Float(
				nullptr,
				defaultValue);
		}
		else
		{
			IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
			try
			{
				return ::DASettingsManager::Get_Float(
					reinterpret_cast<char *>(entryHandle.ToPointer()),
					defaultValue);
			}
			finally
			{
				Marshal::FreeHGlobal(entryHandle);
			}
		}
	}

	float DASettingsManager::GetFloat(String ^section, String ^entry, float defaultValue)
	{
		if (section == nullptr)
		{
			if (entry == nullptr)
			{
				return ::DASettingsManager::Get_Float(
					nullptr,
					nullptr,
					defaultValue);
			}
			else
			{
				IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					return ::DASettingsManager::Get_Float(
						nullptr,
						reinterpret_cast<char *>(entryHandle.ToPointer()),
						defaultValue);
				}
				finally
				{
					Marshal::FreeHGlobal(entryHandle);
				}
			}
		}
		else
		{
			IntPtr sectionHandle = Marshal::StringToHGlobalAnsi(section);
			try
			{
				if (entry == nullptr)
				{
					return ::DASettingsManager::Get_Float(
						reinterpret_cast<char *>(sectionHandle.ToPointer()),
						nullptr,
						defaultValue);
				}
				else
				{
					IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
					try
					{
						return ::DASettingsManager::Get_Float(
							reinterpret_cast<char *>(sectionHandle.ToPointer()),
							reinterpret_cast<char *>(entryHandle.ToPointer()),
							defaultValue);
					}
					finally
					{
						Marshal::FreeHGlobal(entryHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(sectionHandle);
			}
		}
	}

	float DASettingsManager::GetFloat(String ^section1, String ^section2, String ^entry, float defaultValue)
	{
		if (section1 == nullptr)
		{
			if (section2 == nullptr)
			{
				if (entry == nullptr)
				{
					return ::DASettingsManager::Get_Float(
						nullptr,
						nullptr,
						nullptr,
						defaultValue);
				}
				else
				{
					IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
					try
					{
						return ::DASettingsManager::Get_Float(
							nullptr,
							nullptr,
							reinterpret_cast<char *>(entryHandle.ToPointer()),
							defaultValue);
					}
					finally
					{
						Marshal::FreeHGlobal(entryHandle);
					}
				}
			}
			else
			{
				IntPtr section2Handle = Marshal::StringToHGlobalAnsi(section2);
				try
				{
					if (entry == nullptr)
					{
						return ::DASettingsManager::Get_Float(
							nullptr,
							reinterpret_cast<char *>(section2Handle.ToPointer()),
							nullptr,
							defaultValue);
					}
					else
					{
						IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
						try
						{
							return ::DASettingsManager::Get_Float(
								nullptr,
								reinterpret_cast<char *>(section2Handle.ToPointer()),
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								defaultValue);
						}
						finally
						{
							Marshal::FreeHGlobal(entryHandle);
						}
					}
				}
				finally
				{
					Marshal::FreeHGlobal(section2Handle);
				}
			}
		}
		else
		{
			IntPtr section1Handle = Marshal::StringToHGlobalAnsi(section1);
			try
			{
				if (section2 == nullptr)
				{
					if (entry == nullptr)
					{
						return ::DASettingsManager::Get_Float(
							reinterpret_cast<char *>(section1Handle.ToPointer()),
							nullptr,
							nullptr,
							defaultValue);
					}
					else
					{
						IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
						try
						{
							return ::DASettingsManager::Get_Float(
								reinterpret_cast<char *>(section1Handle.ToPointer()),
								nullptr,
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								defaultValue);
						}
						finally
						{
							Marshal::FreeHGlobal(entryHandle);
						}
					}
				}
				else
				{
					IntPtr section2Handle = Marshal::StringToHGlobalAnsi(section2);
					try
					{
						if (entry == nullptr)
						{
							return ::DASettingsManager::Get_Float(
								reinterpret_cast<char *>(section1Handle.ToPointer()),
								reinterpret_cast<char *>(section2Handle.ToPointer()),
								nullptr,
								defaultValue);
						}
						else
						{
							IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
							try
							{
								return ::DASettingsManager::Get_Float(
									reinterpret_cast<char *>(section1Handle.ToPointer()),
									reinterpret_cast<char *>(section2Handle.ToPointer()),
									reinterpret_cast<char *>(entryHandle.ToPointer()),
									defaultValue);
							}
							finally
							{
								Marshal::FreeHGlobal(entryHandle);
							}
						}
					}
					finally
					{
						Marshal::FreeHGlobal(section2Handle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(section1Handle);
			}
		}
	}

	bool DASettingsManager::GetBool(String ^entry, bool defaultValue)
	{
		if (entry == nullptr)
		{
			return ::DASettingsManager::Get_Bool(
				nullptr,
				defaultValue);
		}
		else
		{
			IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
			try
			{
				return ::DASettingsManager::Get_Bool(
					reinterpret_cast<char *>(entryHandle.ToPointer()),
					defaultValue);
			}
			finally
			{
				Marshal::FreeHGlobal(entryHandle);
			}
		}
	}

	bool DASettingsManager::GetBool(String ^section, String ^entry, bool defaultValue)
	{
		if (section == nullptr)
		{
			if (entry == nullptr)
			{
				return ::DASettingsManager::Get_Bool(
					nullptr,
					nullptr,
					defaultValue);
			}
			else
			{
				IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					return ::DASettingsManager::Get_Bool(
						nullptr,
						reinterpret_cast<char *>(entryHandle.ToPointer()),
						defaultValue);
				}
				finally
				{
					Marshal::FreeHGlobal(entryHandle);
				}
			}
		}
		else
		{
			IntPtr sectionHandle = Marshal::StringToHGlobalAnsi(section);
			try
			{
				if (entry == nullptr)
				{
					return ::DASettingsManager::Get_Bool(
						reinterpret_cast<char *>(sectionHandle.ToPointer()),
						nullptr,
						defaultValue);
				}
				else
				{
					IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
					try
					{
						return ::DASettingsManager::Get_Bool(
							reinterpret_cast<char *>(sectionHandle.ToPointer()),
							reinterpret_cast<char *>(entryHandle.ToPointer()),
							defaultValue);
					}
					finally
					{
						Marshal::FreeHGlobal(entryHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(sectionHandle);
			}
		}
	}

	bool DASettingsManager::GetBool(String ^section1, String ^section2, String ^entry, bool defaultValue)
	{
		if (section1 == nullptr)
		{
			if (section2 == nullptr)
			{
				if (entry == nullptr)
				{
					return ::DASettingsManager::Get_Bool(
						nullptr,
						nullptr,
						nullptr,
						defaultValue);
				}
				else
				{
					IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
					try
					{
						return ::DASettingsManager::Get_Bool(
							nullptr,
							nullptr,
							reinterpret_cast<char *>(entryHandle.ToPointer()),
							defaultValue);
					}
					finally
					{
						Marshal::FreeHGlobal(entryHandle);
					}
				}
			}
			else
			{
				IntPtr section2Handle = Marshal::StringToHGlobalAnsi(section2);
				try
				{
					if (entry == nullptr)
					{
						return ::DASettingsManager::Get_Bool(
							nullptr,
							reinterpret_cast<char *>(section2Handle.ToPointer()),
							nullptr,
							defaultValue);
					}
					else
					{
						IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
						try
						{
							return ::DASettingsManager::Get_Bool(
								nullptr,
								reinterpret_cast<char *>(section2Handle.ToPointer()),
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								defaultValue);
						}
						finally
						{
							Marshal::FreeHGlobal(entryHandle);
						}
					}
				}
				finally
				{
					Marshal::FreeHGlobal(section2Handle);
				}
			}
		}
		else
		{
			IntPtr section1Handle = Marshal::StringToHGlobalAnsi(section1);
			try
			{
				if (section2 == nullptr)
				{
					if (entry == nullptr)
					{
						return ::DASettingsManager::Get_Bool(
							reinterpret_cast<char *>(section1Handle.ToPointer()),
							nullptr,
							nullptr,
							defaultValue);
					}
					else
					{
						IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
						try
						{
							return ::DASettingsManager::Get_Bool(
								reinterpret_cast<char *>(section1Handle.ToPointer()),
								nullptr,
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								defaultValue);
						}
						finally
						{
							Marshal::FreeHGlobal(entryHandle);
						}
					}
				}
				else
				{
					IntPtr section2Handle = Marshal::StringToHGlobalAnsi(section2);
					try
					{
						if (entry == nullptr)
						{
							return ::DASettingsManager::Get_Bool(
								reinterpret_cast<char *>(section1Handle.ToPointer()),
								reinterpret_cast<char *>(section2Handle.ToPointer()),
								nullptr,
								defaultValue);
						}
						else
						{
							IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
							try
							{
								return ::DASettingsManager::Get_Bool(
									reinterpret_cast<char *>(section1Handle.ToPointer()),
									reinterpret_cast<char *>(section2Handle.ToPointer()),
									reinterpret_cast<char *>(entryHandle.ToPointer()),
									defaultValue);
							}
							finally
							{
								Marshal::FreeHGlobal(entryHandle);
							}
						}
					}
					finally
					{
						Marshal::FreeHGlobal(section2Handle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(section1Handle);
			}
		}
	}

	String ^DASettingsManager::GetString(String ^entry, String ^defaultValue)
	{
		::StringClass result;

		if (entry == nullptr)
		{
			if (defaultValue == nullptr)
			{
				::DASettingsManager::Get_String(
					result,
					nullptr,
					nullptr);
			}
			else
			{
				IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
				try
				{
					::DASettingsManager::Get_String(
						result,
						nullptr,
						reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
				}
				finally
				{
					Marshal::FreeHGlobal(defaultValueHandle);
				}
			}
		}
		else
		{
			IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
			try
			{
				if (defaultValue == nullptr)
				{
					::DASettingsManager::Get_String(
						result,
						reinterpret_cast<char *>(entryHandle.ToPointer()),
						nullptr);
				}
				else
				{
					IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
					try
					{
						::DASettingsManager::Get_String(
							result,
							reinterpret_cast<char *>(entryHandle.ToPointer()),
							reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
					}
					finally
					{
						Marshal::FreeHGlobal(defaultValueHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(entryHandle);
			}
		}

		return gcnew String(result.Peek_Buffer());
	}

	String ^DASettingsManager::GetString(String ^section, String ^entry, String ^defaultValue)
	{
		::StringClass result;

		if (section == nullptr)
		{
			if (entry == nullptr)
			{
				if (defaultValue == nullptr)
				{
					::DASettingsManager::Get_String(
						result,
						nullptr,
						nullptr,
						nullptr);
				}
				else
				{
					IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
					try
					{
						::DASettingsManager::Get_String(
							result,
							nullptr,
							nullptr,
							reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
					}
					finally
					{
						Marshal::FreeHGlobal(defaultValueHandle);
					}
				}
			}
			else
			{
				IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					if (defaultValue == nullptr)
					{
						::DASettingsManager::Get_String(
							result,
							nullptr,
							reinterpret_cast<char *>(entryHandle.ToPointer()),
							nullptr);
					}
					else
					{
						IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
						try
						{
							::DASettingsManager::Get_String(
								result,
								nullptr,
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
						}
						finally
						{
							Marshal::FreeHGlobal(defaultValueHandle);
						}
					}
				}
				finally
				{
					Marshal::FreeHGlobal(entryHandle);
				}
			}
		}
		else
		{
			IntPtr sectionHandle = Marshal::StringToHGlobalAnsi(section);
			try
			{
				if (entry == nullptr)
				{
					if (defaultValue == nullptr)
					{
						::DASettingsManager::Get_String(
							result,
							reinterpret_cast<char *>(sectionHandle.ToPointer()),
							nullptr,
							nullptr);
					}
					else
					{
						IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
						try
						{
							::DASettingsManager::Get_String(
								result,
								reinterpret_cast<char *>(sectionHandle.ToPointer()),
								nullptr,
								reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
						}
						finally
						{
							Marshal::FreeHGlobal(defaultValueHandle);
						}
					}
				}
				else
				{
					IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
					try
					{
						if (defaultValue == nullptr)
						{
							::DASettingsManager::Get_String(
								result,
								reinterpret_cast<char *>(sectionHandle.ToPointer()),
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								nullptr);
						}
						else
						{
							IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
							try
							{
								::DASettingsManager::Get_String(
									result,
									reinterpret_cast<char *>(sectionHandle.ToPointer()),
									reinterpret_cast<char *>(entryHandle.ToPointer()),
									reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
							}
							finally
							{
								Marshal::FreeHGlobal(defaultValueHandle);
							}
						}
					}
					finally
					{
						Marshal::FreeHGlobal(entryHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(sectionHandle);
			}
		}

		return gcnew String(result.Peek_Buffer());
	}

	String ^DASettingsManager::GetString(String ^section1, String ^section2, String ^entry, String ^defaultValue)
	{
		::StringClass result;

		if (section1 == nullptr)
		{
			if (section2 == nullptr)
			{
				if (entry == nullptr)
				{
					if (defaultValue == nullptr)
					{
						::DASettingsManager::Get_String(
							result,
							nullptr,
							nullptr,
							nullptr,
							nullptr);
					}
					else
					{
						IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
						try
						{
							::DASettingsManager::Get_String(
								result,
								nullptr,
								nullptr,
								nullptr,
								reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
						}
						finally
						{
							Marshal::FreeHGlobal(defaultValueHandle);
						}
					}
				}
				else
				{
					IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
					try
					{
						if (defaultValue == nullptr)
						{
							::DASettingsManager::Get_String(
								result,
								nullptr,
								nullptr,
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								nullptr);
						}
						else
						{
							IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
							try
							{
								::DASettingsManager::Get_String(
									result,
									nullptr,
									nullptr,
									reinterpret_cast<char *>(entryHandle.ToPointer()),
									reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
							}
							finally
							{
								Marshal::FreeHGlobal(defaultValueHandle);
							}
						}
					}
					finally
					{
						Marshal::FreeHGlobal(entryHandle);
					}
				}
			}
			else
			{
				IntPtr section2Handle = Marshal::StringToHGlobalAnsi(section2);
				try
				{
					if (entry == nullptr)
					{
						if (defaultValue == nullptr)
						{
							::DASettingsManager::Get_String(
								result,
								nullptr,
								reinterpret_cast<char *>(section2Handle.ToPointer()),
								nullptr,
								nullptr);
						}
						else
						{
							IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
							try
							{
								::DASettingsManager::Get_String(
									result,
									nullptr,
									reinterpret_cast<char *>(section2Handle.ToPointer()),
									nullptr,
									reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
							}
							finally
							{
								Marshal::FreeHGlobal(defaultValueHandle);
							}
						}
					}
					else
					{
						IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
						try
						{
							if (defaultValue == nullptr)
							{
								::DASettingsManager::Get_String(
									result,
									nullptr,
									reinterpret_cast<char *>(section2Handle.ToPointer()),
									reinterpret_cast<char *>(entryHandle.ToPointer()),
									nullptr);
							}
							else
							{
								IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
								try
								{
									::DASettingsManager::Get_String(
										result,
										nullptr,
										reinterpret_cast<char *>(section2Handle.ToPointer()),
										reinterpret_cast<char *>(entryHandle.ToPointer()),
										reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
								}
								finally
								{
									Marshal::FreeHGlobal(defaultValueHandle);
								}
							}
						}
						finally
						{
							Marshal::FreeHGlobal(entryHandle);
						}
					}
				}
				finally
				{
					Marshal::FreeHGlobal(section2Handle);
				}
			}
		}
		else
		{
			IntPtr section1Handle = Marshal::StringToHGlobalAnsi(section1);
			try
			{
				if (section2 == nullptr)
				{
					if (entry == nullptr)
					{
						if (defaultValue == nullptr)
						{
							::DASettingsManager::Get_String(
								result,
								reinterpret_cast<char *>(section1Handle.ToPointer()),
								nullptr,
								nullptr,
								nullptr);
						}
						else
						{
							IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
							try
							{
								::DASettingsManager::Get_String(
									result,
									reinterpret_cast<char *>(section1Handle.ToPointer()),
									nullptr,
									nullptr,
									reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
							}
							finally
							{
								Marshal::FreeHGlobal(defaultValueHandle);
							}
						}
					}
					else
					{
						IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
						try
						{
							if (defaultValue == nullptr)
							{
								::DASettingsManager::Get_String(
									result,
									reinterpret_cast<char *>(section1Handle.ToPointer()),
									nullptr,
									reinterpret_cast<char *>(entryHandle.ToPointer()),
									nullptr);
							}
							else
							{
								IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
								try
								{
									::DASettingsManager::Get_String(
										result,
										reinterpret_cast<char *>(section1Handle.ToPointer()),
										nullptr,
										reinterpret_cast<char *>(entryHandle.ToPointer()),
										reinterpret_cast<char *>(defaultValueHandle.ToPointer()));

								}
								finally
								{
									Marshal::FreeHGlobal(defaultValueHandle);
								}
							}
						}
						finally
						{
							Marshal::FreeHGlobal(entryHandle);
						}
					}
				}
				else
				{
					IntPtr section2Handle = Marshal::StringToHGlobalAnsi(section2);
					try
					{
						if (entry == nullptr)
						{
							if (defaultValue == nullptr)
							{
								::DASettingsManager::Get_String(
									result,
									reinterpret_cast<char *>(section1Handle.ToPointer()),
									reinterpret_cast<char *>(section2Handle.ToPointer()),
									nullptr,
									nullptr);
							}
							else
							{
								IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
								try
								{
									::DASettingsManager::Get_String(
										result,
										reinterpret_cast<char *>(section1Handle.ToPointer()),
										reinterpret_cast<char *>(section2Handle.ToPointer()),
										nullptr,
										reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
								}
								finally
								{
									Marshal::FreeHGlobal(defaultValueHandle);
								}
							}
						}
						else
						{
							IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
							try
							{
								if (defaultValue == nullptr)
								{
									::DASettingsManager::Get_String(
										result,
										reinterpret_cast<char *>(section1Handle.ToPointer()),
										reinterpret_cast<char *>(section2Handle.ToPointer()),
										reinterpret_cast<char *>(entryHandle.ToPointer()),
										nullptr);
								}
								else
								{
									IntPtr defaultValueHandle = Marshal::StringToHGlobalAnsi(defaultValue);
									try
									{
										::DASettingsManager::Get_String(
											result,
											reinterpret_cast<char *>(section1Handle.ToPointer()),
											reinterpret_cast<char *>(section2Handle.ToPointer()),
											reinterpret_cast<char *>(entryHandle.ToPointer()),
											reinterpret_cast<char *>(defaultValueHandle.ToPointer()));
									}
									finally
									{
										Marshal::FreeHGlobal(defaultValueHandle);
									}
								}
							}
							finally
							{
								Marshal::FreeHGlobal(entryHandle);
							}
						}
					}
					finally
					{
						Marshal::FreeHGlobal(section2Handle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(section1Handle);
			}
		}

		return gcnew String(result.Peek_Buffer());
	}

	Vector3 DASettingsManager::GetVector3(String ^entry, Vector3 defaultValue)
	{
		::Vector3 result;

		IntPtr defaultValueHandle = Marshal::AllocHGlobal(Marshal::SizeOf(Vector3::typeid));
		try
		{
			Marshal::StructureToPtr(defaultValue, defaultValueHandle, false);

			if (entry == nullptr)
			{
				::DASettingsManager::Get_Vector3(
					result,
					nullptr,
					*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
			}
			else
			{
				IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					::DASettingsManager::Get_Vector3(
						result,
						reinterpret_cast<char *>(entryHandle.ToPointer()),
						*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
				}
				finally
				{
					Marshal::FreeHGlobal(entryHandle);
				}
			}
		}
		finally
		{
			Marshal::FreeHGlobal(defaultValueHandle);
		}

		return Marshal::PtrToStructure<Vector3>(IntPtr(&result));
	}

	Vector3 DASettingsManager::GetVector3(String ^section, String ^entry, Vector3 defaultValue)
	{
		::Vector3 result;

		IntPtr defaultValueHandle = Marshal::AllocHGlobal(Marshal::SizeOf(Vector3::typeid));
		try
		{
			Marshal::StructureToPtr(defaultValue, defaultValueHandle, false);

			if (section == nullptr)
			{
				if (entry == nullptr)
				{
					::DASettingsManager::Get_Vector3(
						result,
						nullptr,
						nullptr,
						*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
				}
				else
				{
					IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
					try
					{
						::DASettingsManager::Get_Vector3(
							result,
							nullptr,
							reinterpret_cast<char *>(entryHandle.ToPointer()),
							*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
					}
					finally
					{
						Marshal::FreeHGlobal(entryHandle);
					}
				}
			}
			else
			{
				IntPtr sectionHandle = Marshal::StringToHGlobalAnsi(section);
				try
				{
					if (entry == nullptr)
					{
						::DASettingsManager::Get_Vector3(
							result,
							reinterpret_cast<char *>(sectionHandle.ToPointer()),
							nullptr,
							*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
					}
					else
					{
						IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
						try
						{
							::DASettingsManager::Get_Vector3(
								result,
								reinterpret_cast<char *>(sectionHandle.ToPointer()),
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
						}
						finally
						{
							Marshal::FreeHGlobal(entryHandle);
						}
					}
				}
				finally
				{
					Marshal::FreeHGlobal(sectionHandle);
				}
			}
		}
		finally
		{
			Marshal::FreeHGlobal(defaultValueHandle);
		}

		return Marshal::PtrToStructure<Vector3>(IntPtr(&result));
	}

	Vector3 DASettingsManager::GetVector3(String ^section1, String ^section2, String ^entry, Vector3 defaultValue)
	{
		::Vector3 result;

		IntPtr defaultValueHandle = Marshal::AllocHGlobal(Marshal::SizeOf(Vector3::typeid));
		try
		{
			Marshal::StructureToPtr(defaultValue, defaultValueHandle, false);

			if (section1 == nullptr)
			{
				if (section2 == nullptr)
				{
					if (entry == nullptr)
					{
						::DASettingsManager::Get_Vector3(
							result,
							nullptr,
							nullptr,
							nullptr,
							*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
					}
					else
					{
						IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
						try
						{
							::DASettingsManager::Get_Vector3(
								result,
								nullptr,
								nullptr,
								reinterpret_cast<char *>(entryHandle.ToPointer()),
								*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
						}
						finally
						{
							Marshal::FreeHGlobal(entryHandle);
						}
					}
				}
				else
				{
					IntPtr section2Handle = Marshal::StringToHGlobalAnsi(section2);
					try
					{
						if (entry == nullptr)
						{
							::DASettingsManager::Get_Vector3(
								result,
								nullptr,
								reinterpret_cast<char *>(section2Handle.ToPointer()),
								nullptr,
								*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
						}
						else
						{
							IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
							try
							{
								::DASettingsManager::Get_Vector3(
									result,
									nullptr,
									reinterpret_cast<char *>(section2Handle.ToPointer()),
									reinterpret_cast<char *>(entryHandle.ToPointer()),
									*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
							}
							finally
							{
								Marshal::FreeHGlobal(entryHandle);
							}
						}
					}
					finally
					{
						Marshal::FreeHGlobal(section2Handle);
					}
				}
			}
			else
			{
				IntPtr section1Handle = Marshal::StringToHGlobalAnsi(section1);
				try
				{
					if (section2 == nullptr)
					{
						if (entry == nullptr)
						{
							::DASettingsManager::Get_Vector3(
								result,
								reinterpret_cast<char *>(section1Handle.ToPointer()),
								nullptr,
								nullptr,
								*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
						}
						else
						{
							IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
							try
							{
								::DASettingsManager::Get_Vector3(
									result,
									reinterpret_cast<char *>(section1Handle.ToPointer()),
									nullptr,
									reinterpret_cast<char *>(entryHandle.ToPointer()),
									*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
							}
							finally
							{
								Marshal::FreeHGlobal(entryHandle);
							}
						}
					}
					else
					{
						IntPtr section2Handle = Marshal::StringToHGlobalAnsi(section2);
						try
						{
							if (entry == nullptr)
							{
								::DASettingsManager::Get_Vector3(
									result,
									reinterpret_cast<char *>(section1Handle.ToPointer()),
									reinterpret_cast<char *>(section2Handle.ToPointer()),
									nullptr,
									*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
							}
							else
							{
								IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
								try
								{
									::DASettingsManager::Get_Vector3(
										result,
										reinterpret_cast<char *>(section1Handle.ToPointer()),
										reinterpret_cast<char *>(section2Handle.ToPointer()),
										reinterpret_cast<char *>(entryHandle.ToPointer()),
										*reinterpret_cast<::Vector3 *>(defaultValueHandle.ToPointer()));
								}
								finally
								{
									Marshal::FreeHGlobal(entryHandle);
								}
							}
						}
						finally
						{
							Marshal::FreeHGlobal(section2Handle);
						}
					}
				}
				finally
				{
					Marshal::FreeHGlobal(section1Handle);
				}
			}
		}
		finally
		{
			Marshal::FreeHGlobal(defaultValueHandle);
		}

		return Marshal::PtrToStructure<Vector3>(IntPtr(&result));
	}

	int DASettingsManager::SettingsCount::get()
	{
		return ::DASettingsManager::Get_Settings_Count();
	}
}