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
#include "RenSharpConsoleFunctionClass.h"

#include "Imports.h"
#include "MEngine.h"
#include "RenSharpTimerManager.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <engine_tt.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	RenSharpConsoleFunctionClass::RenSharpConsoleFunctionClass(String ^name, String ^alias, String ^help)
		: disposedResources(false), destroyPointer(true), consoleFunctionClassPointer(IntPtr::Zero), consoleFunctionClass(nullptr), name(name), alias(alias), help(help)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}
		else if (help == nullptr)
		{
			throw gcnew ArgumentNullException("help");
		}
	}

	RenSharpConsoleFunctionClass::RenSharpConsoleFunctionClass(String ^name, String ^help)
		: RenSharpConsoleFunctionClass(name, nullptr, help)
	{

	}

	RenSharpConsoleFunctionClass::~RenSharpConsoleFunctionClass()
	{
		if (disposedResources)
		{
			return;
		}

		Engine::UnregisterManagedConsoleFunction(this);

		ClearTimers();

		this->!RenSharpConsoleFunctionClass();

		disposedResources = true;
	}

	RenSharpConsoleFunctionClass::!RenSharpConsoleFunctionClass()
	{
		if (IsAttached)
		{
			::ConsoleFunctionList.DeleteObj(InternalConsoleFunctionClassPointer);

			if (destroyPointer)
			{
				IntPtr tmp = consoleFunctionClassPointer;
				consoleFunctionClassPointer = IntPtr::Zero;
				Imports::DestroyConsoleFunctionClass(reinterpret_cast<::ConsoleFunctionClass*>(tmp.ToPointer()));
			}
		}

		ReleasePointer();
	}

	String ^RenSharpConsoleFunctionClass::ToString()
	{
		return name;
	}

	bool RenSharpConsoleFunctionClass::Equals(Object ^other)
	{
		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		IConsoleFunctionClass^ otherThis1 = dynamic_cast<IConsoleFunctionClass^>(other);
		if (otherThis1 != nullptr && consoleFunctionClassPointer.Equals(otherThis1->ConsoleFunctionClassPointer))
		{
			return true;
		}

		IRenSharpConsoleFunctionClass ^otherThis2 = dynamic_cast<IRenSharpConsoleFunctionClass ^>(other);
		if (otherThis2 == nullptr)
		{
			return false;
		}

		return consoleFunctionClassPointer.Equals(otherThis2->ConsoleFunctionClassPointer);
	}

	int RenSharpConsoleFunctionClass::GetHashCode()
	{
		return consoleFunctionClassPointer.GetHashCode();
	}

	void RenSharpConsoleFunctionClass::TimerExpired(int number, Object^ data)
	{
		
	}

	void RenSharpConsoleFunctionClass::StartTimer(int number, TimeSpan duration, bool repeat, Object^ data)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat, data);
	}

	void RenSharpConsoleFunctionClass::StartTimer(int number, TimeSpan duration, bool repeat)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat);
	}

	void RenSharpConsoleFunctionClass::StartTimer(int number, TimeSpan duration)
	{
		RenSharpTimerManager::StartTimer(this, number, duration);
	}

	void RenSharpConsoleFunctionClass::StopTimer(int number, Object^ data)
	{
		RenSharpTimerManager::StopTimer(this, number, data);
	}

	void RenSharpConsoleFunctionClass::StopTimer(int number)
	{
		RenSharpTimerManager::StopTimer(this, number);
	}

	bool RenSharpConsoleFunctionClass::IsTimer(int number, Object^ data)
	{
		return RenSharpTimerManager::IsTimer(this, number, data);
	}

	bool RenSharpConsoleFunctionClass::IsTimer(int number)
	{
		return RenSharpTimerManager::IsTimer(this, number);
	}

	void RenSharpConsoleFunctionClass::ClearTimers()
	{
		RenSharpTimerManager::ClearTimers(this);
	}

	void RenSharpConsoleFunctionClass::InitUnmanagedAttachable()
	{
		AttachToUnmanagedObject();
		RegisterManagedObject();
	}

	void RenSharpConsoleFunctionClass::AttachToUnmanagedObject()
	{
		if (IsAttached)
		{
			throw gcnew NotSupportedException("Already attached.");
		}

		::RenSharpConsoleFunctionClass* newFunction = nullptr;
		try
		{
			IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
			try
			{
				IntPtr helpHandle = Marshal::StringToHGlobalAnsi(help);
				try
				{
					if (alias == nullptr)
					{
						newFunction = Imports::CreateRenSharpConsoleFunctionClass(
							reinterpret_cast<char*>(nameHandle.ToPointer()),
							nullptr,
							reinterpret_cast<char*>(helpHandle.ToPointer()));
					}
					else
					{
						IntPtr aliasHandle = Marshal::StringToHGlobalAnsi(alias);
						try
						{
							newFunction = Imports::CreateRenSharpConsoleFunctionClass(
								reinterpret_cast<char*>(nameHandle.ToPointer()),
								reinterpret_cast<char*>(aliasHandle.ToPointer()),
								reinterpret_cast<char*>(helpHandle.ToPointer()));
						}
						finally
						{
							Marshal::FreeHGlobal(aliasHandle);
						}
					}
				}
				finally
				{
					Marshal::FreeHGlobal(helpHandle);
				}
			}
			finally
			{
				Marshal::FreeHGlobal(nameHandle);
			}

			consoleFunctionClassPointer = IntPtr(newFunction);
		}
		catch (Exception^)
		{
			if (newFunction != nullptr)
			{
				Imports::DestroyConsoleFunctionClass(reinterpret_cast<::ConsoleFunctionClass*>(newFunction));
			}

			throw;
		}

		consoleFunctionClass = gcnew ConsoleFunctionClass(consoleFunctionClassPointer);

		UnmanagedAttach();
	}

	void RenSharpConsoleFunctionClass::RegisterManagedObject()
	{
		Engine::RegisterManagedConsoleFunction(this);

		ManagedRegistered();
	}

	void RenSharpConsoleFunctionClass::ReleasePointer()
	{
		consoleFunctionClassPointer = IntPtr::Zero;
		consoleFunctionClass = nullptr;
	}

	void RenSharpConsoleFunctionClass::UnmanagedAttach()
	{

	}

	void RenSharpConsoleFunctionClass::ManagedRegistered()
	{

	}

	void RenSharpConsoleFunctionClass::Activate(String^ pArgs)
	{

	}

	void RenSharpConsoleFunctionClass::Activate(IDATokenClass^ args)
	{

	}

	IConsoleFunctionClass ^RenSharpConsoleFunctionClass::AsUnmanagedObject()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return consoleFunctionClass;
	}

	Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ RenSharpConsoleFunctionClass::Timers::get()
	{
		return RenSharpTimerManager::GetTimers(this);
	}

	IntPtr RenSharpConsoleFunctionClass::ConsoleFunctionClassPointer::get()
	{
		return consoleFunctionClassPointer;
	}

	IntPtr RenSharpConsoleFunctionClass::Pointer::get()
	{
		return consoleFunctionClassPointer;
	}

	bool RenSharpConsoleFunctionClass::IsAttached::get()
	{
		return (consoleFunctionClassPointer != IntPtr::Zero);
	}

	bool RenSharpConsoleFunctionClass::IsRegistered::get()
	{
		return (IsAttached && Engine::IsManagedConsoleFunction(consoleFunctionClassPointer));
	}

	String ^RenSharpConsoleFunctionClass::Name::get()
	{
		return name;
	}

	String ^RenSharpConsoleFunctionClass::Alias::get()
	{
		return alias;
	}

	String ^RenSharpConsoleFunctionClass::Help::get()
	{
		return help;
	}

	bool RenSharpConsoleFunctionClass::DestroyPointer::get()
	{
		return destroyPointer;
	}

	void RenSharpConsoleFunctionClass::DestroyPointer::set(bool value)
	{
		destroyPointer = value;
	}

	::ConsoleFunctionClass *RenSharpConsoleFunctionClass::InternalConsoleFunctionClassPointer::get()
	{
		return reinterpret_cast<::ConsoleFunctionClass *>(consoleFunctionClassPointer.ToPointer());
	}
}