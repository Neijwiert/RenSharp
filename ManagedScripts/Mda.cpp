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
#include "Mda.h"

#include "McPlayer.h"
#include "MConsoleFunctionClassPtrDynamicVectorClass.h"
#include "MScriptableGameObj.h"

namespace RenSharp
{
	void DA::Init()
	{
		::DA::Init();
	}

	void DA::Shutdown()
	{
		::DA::Shutdown();
	}

	void DA::HostMessage(String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Host_Message(
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::TeamHostMessage(int team, String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Team_Host_Message(
				team,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::PrivateHostMessage(IcPlayer^ player, String^ format, ...array<Object^>^ args)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Private_Host_Message(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::PrivateHostMessage(int player, String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Private_Host_Message(
				player,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::PrivateHostMessage(IScriptableGameObj^ player, String^ format, ...array<Object^>^ args)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Private_Host_Message(
				reinterpret_cast<::ScriptableGameObj*>(player->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::AdminMessage(String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Admin_Message(
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::TeamAdminMessage(int team, String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Team_Admin_Message(
				team,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::PrivateAdminMessage(IcPlayer^ player, String^ format, ...array<Object^>^ args)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Private_Admin_Message(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::PrivateAdminMessage(int player, String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Private_Admin_Message(
				player,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::PrivateAdminMessage(IScriptableGameObj^ player, String^ format, ...array<Object^>^ args)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Private_Admin_Message(
				reinterpret_cast<::ScriptableGameObj*>(player->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::PlayerMessage(IcPlayer^ player, String^ format, ...array<Object^>^ args)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Player_Message(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::PlayerMessage(int player, String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Player_Message(
				player,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::PlayerMessage(IScriptableGameObj^ player, String^ format, ...array<Object^>^ args)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Player_Message(
				reinterpret_cast<::ScriptableGameObj*>(player->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::TeamPlayerMessage(IcPlayer^ player, String^ format, ...array<Object^>^ args)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Team_Player_Message(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::TeamPlayerMessage(int player, String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Team_Player_Message(
				player,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::TeamPlayerMessage(IScriptableGameObj^ player, String^ format, ...array<Object^>^ args)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Team_Player_Message(
				reinterpret_cast<::ScriptableGameObj*>(player->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::PageTeam(int team, String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Page_Team(
				team,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::PageTeamExcept(int team, IcPlayer^ except, String^ format, ...array<Object^>^ args)
	{
		if (except == nullptr || except->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("except");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Page_Team_Except(
				team,
				reinterpret_cast<::cPlayer*>(except->cPlayerPointer.ToPointer()),
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::PagePlayer(IcPlayer ^player, String ^format, ...array<Object ^> ^args)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException(L"player");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException(L"format");
		}

		String ^result = String::Format(format, args);

		IntPtr resultHandle = Marshal::StringToHGlobalAnsi(result);
		try
		{
			::DA::Page_Player(
				reinterpret_cast<::cPlayer *>(player->cPlayerPointer.ToPointer()),
				reinterpret_cast<char *>(resultHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(resultHandle);
		}
	}

	void DA::PagePlayer(int player, String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Page_Player(
				player,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::PagePlayer(IScriptableGameObj^ player, String^ format, ...array<Object^>^ args)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Page_Player(
				reinterpret_cast<::ScriptableGameObj*>(player->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::ColorMessage(Color color, String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Color_Message(
				color.R,
				color.G,
				color.B,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::ColorMessageWithTeamColor(int team, String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Color_Message_With_Team_Color(
				team,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::TeamColorMessage(int team, Color color, String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Team_Color_Message(
				team,
				color.R,
				color.G,
				color.B,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::TeamColorMessageWithTeamColor(int team, String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Team_Color_Message_With_Team_Color(
				team,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::PrivateColorMessage(IcPlayer^ player, Color color, String^ format, ...array<Object^>^ args)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException(L"player");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException(L"format");
		}

		String^ result = String::Format(format, args);

		IntPtr resultHandle = Marshal::StringToHGlobalAnsi(result);
		try
		{
			::DA::Private_Color_Message(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				color.R,
				color.G,
				color.B,
				reinterpret_cast<char*>(resultHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(resultHandle);
		}
	}

	void DA::PrivateColorMessage(int player, Color color, String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Private_Color_Message(
				player,
				color.R,
				color.G,
				color.B,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::PrivateColorMessage(IScriptableGameObj^ player, Color color, String^ format, ...array<Object^>^ args)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Private_Color_Message(
				reinterpret_cast<::ScriptableGameObj*>(player->ScriptableGameObjPointer.ToPointer()),
				color.R,
				color.G,
				color.B,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::PrivateColorMessageWithTeamColor(IcPlayer^ player, int team, String^ format, ...array<Object^>^ args)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException(L"player");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException(L"format");
		}

		String^ result = String::Format(format, args);

		IntPtr resultHandle = Marshal::StringToHGlobalAnsi(result);
		try
		{
			::DA::Private_Color_Message_With_Team_Color(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				team,
				reinterpret_cast<char*>(resultHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(resultHandle);
		}
	}

	void DA::PrivateColorMessageWithTeamColor(int player, int team, String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Private_Color_Message_With_Team_Color(
				player,
				team,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::PrivateColorMessageWithTeamColor(IScriptableGameObj^ player, int team, String^ format, ...array<Object^>^ args)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Private_Color_Message_With_Team_Color(
				reinterpret_cast<::ScriptableGameObj*>(player->ScriptableGameObjPointer.ToPointer()),
				team,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::Create2DSound(String^ sound)
	{
		if (sound == nullptr)
		{
			throw gcnew ArgumentNullException("sound");
		}

		IntPtr soundHandle = Marshal::StringToHGlobalAnsi(sound);
		try
		{
			::DA::Create_2D_Sound(
				reinterpret_cast<char*>(soundHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(soundHandle);
		}
	}

	void DA::Create2DSoundTeam(int team, String^ sound)
	{
		if (sound == nullptr)
		{
			throw gcnew ArgumentNullException("sound");
		}

		IntPtr soundHandle = Marshal::StringToHGlobalAnsi(sound);
		try
		{
			::DA::Create_2D_Sound_Team(
				team,
				reinterpret_cast<char*>(soundHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(soundHandle);
		}
	}

	void DA::Create2DSoundPlayer(IcPlayer^ player, String^ sound)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException(L"player");
		}
		else if (sound == nullptr)
		{
			throw gcnew ArgumentNullException("sound");
		}

		IntPtr soundHandle = Marshal::StringToHGlobalAnsi(sound);
		try
		{
			::DA::Create_2D_Sound_Player(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				reinterpret_cast<char*>(soundHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(soundHandle);
		}
	}

	void DA::Create2DSoundPlayer(int player, String^ sound)
	{
		if (sound == nullptr)
		{
			throw gcnew ArgumentNullException("sound");
		}

		IntPtr soundHandle = Marshal::StringToHGlobalAnsi(sound);
		try
		{
			::DA::Create_2D_Sound_Player(
				player,
				reinterpret_cast<char*>(soundHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(soundHandle);
		}
	}

	void DA::Create2DSoundPlayer(IScriptableGameObj^ player, String^ sound)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (sound == nullptr)
		{
			throw gcnew ArgumentNullException("sound");
		}

		IntPtr soundHandle = Marshal::StringToHGlobalAnsi(sound);
		try
		{
			::DA::Create_2D_Sound_Player(
				reinterpret_cast<::ScriptableGameObj*>(player->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char*>(soundHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(soundHandle);
		}
	}

	void DA::HUDMessage(Color color, String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::HUD_Message(
				color.R,
				color.G,
				color.B,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::TeamHUDMessage(int team, Color color, String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Team_HUD_Message(
				team,
				color.R,
				color.G,
				color.B,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::PrivateHUDMessage(IcPlayer^ player, Color color, String^ format, ...array<Object^>^ args)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException(L"player");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Private_HUD_Message(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				color.R,
				color.G,
				color.B,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::PrivateHUDMessage(int player, Color color, String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Private_HUD_Message(
				player,
				color.R,
				color.G,
				color.B,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DA::PrivateHUDMessage(IScriptableGameObj^ player, Color color, String^ format, ...array<Object^>^ args)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DA::Private_HUD_Message(
				reinterpret_cast<::ScriptableGameObj*>(player->ScriptableGameObjPointer.ToPointer()),
				color.R,
				color.G,
				color.B,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	String ^DA::Version::get()
	{
		return gcnew String(::DA::Get_Version());
	}

	String^ DA::MessagePrefix::get()
	{
		return gcnew String(::DA::Get_Message_Prefix().Peek_Buffer());
	}

	IDynamicVectorClass<IConsoleFunctionClass^>^ DA::ConsoleFunctionList::get()
	{
		return gcnew ConsoleFunctionClassPtrDynamicVectorClass(IntPtr(&::DA::Get_Console_Function_List()));
	}

	void DA::ConsoleFunctionList::set(IDynamicVectorClass<IConsoleFunctionClass^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto& consoleFunctionList = ::DA::Get_Console_Function_List();

		consoleFunctionList = *reinterpret_cast<::DynamicVectorClass<::ConsoleFunctionClass*>*>(value->Pointer.ToPointer());
	}
}