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

#include "Mengine_vector.h"

using namespace System;
using namespace System::Drawing;

namespace RenSharp
{
	interface class IcPlayer;
	interface class IConsoleFunctionClass;
	interface class IScriptableGameObj;

	public ref class DA abstract sealed
	{
		public:
			static void Init();
			static void Shutdown();
			static void HostMessage(String^ format, ...array<Object^>^ args);
			static void TeamHostMessage(int team, String^ format, ...array<Object^>^ args); 
			static void PrivateHostMessage(IcPlayer^ player, String^ format, ...array<Object^>^ args);
			static void PrivateHostMessage(int player, String^ format, ...array<Object^>^ args);
			static void PrivateHostMessage(IScriptableGameObj^ player, String^ format, ...array<Object^>^ args);
			static void AdminMessage(String^ format, ...array<Object^>^ args);
			static void TeamAdminMessage(int team, String^ format, ...array<Object^>^ args); 
			static void PrivateAdminMessage(IcPlayer^ player, String^ format, ...array<Object^>^ args);
			static void PrivateAdminMessage(int player, String^ format, ...array<Object^>^ args);
			static void PrivateAdminMessage(IScriptableGameObj^ player, String^ format, ...array<Object^>^ args);
			static void PlayerMessage(IcPlayer^ player, String^ format, ...array<Object^>^ args);
			static void PlayerMessage(int player, String^ format, ...array<Object^>^ args);
			static void PlayerMessage(IScriptableGameObj^ player, String^ format, ...array<Object^>^ args);
			static void TeamPlayerMessage(IcPlayer^ player, String^ format, ...array<Object^>^ args);
			static void TeamPlayerMessage(int player, String^ format, ...array<Object^>^ args);
			static void TeamPlayerMessage(IScriptableGameObj^ player, String^ format, ...array<Object^>^ args);
			static void PageTeam(int team, String^ format, ...array<Object^>^ args);
			static void PageTeamExcept(int team, IcPlayer^ except, String^ format, ...array<Object^>^ args);
			static void PagePlayer(IcPlayer^ player, String^ format, ...array<Object^>^ args);
			static void PagePlayer(int player, String^ format, ...array<Object^>^ args);
			static void PagePlayer(IScriptableGameObj^ player, String^ format, ...array<Object^>^ args);
			static void ColorMessage(Color color, String^ format, ...array<Object^>^ args);
			static void ColorMessageWithTeamColor(int team, String^ format, ...array<Object^>^ args);
			static void TeamColorMessage(int team, Color color, String^ format, ...array<Object^>^ args);
			static void TeamColorMessageWithTeamColor(int team, String^ format, ...array<Object^>^ args);
			static void PrivateColorMessage(IcPlayer^ player, Color color, String^ format, ...array<Object^>^ args);
			static void PrivateColorMessage(int player, Color color, String^ format, ...array<Object^>^ args);
			static void PrivateColorMessage(IScriptableGameObj^ player, Color color, String^ format, ...array<Object^>^ args);
			static void PrivateColorMessageWithTeamColor(IcPlayer^ player, int team, String^ format, ...array<Object^>^ args);
			static void PrivateColorMessageWithTeamColor(int player, int team, String^ format, ...array<Object^>^ args);
			static void PrivateColorMessageWithTeamColor(IScriptableGameObj^ player, int team, String^ format, ...array<Object^>^ args);
			static void Create2DSound(String^ sound);
			static void Create2DSoundTeam(int team, String^ sound); 
			static void Create2DSoundPlayer(IcPlayer^ player, String^ sound);
			static void Create2DSoundPlayer(int player, String^ sound);
			static void Create2DSoundPlayer(IScriptableGameObj^ player, String^ sound);
			static void HUDMessage(Color color, String^ format, ...array<Object^>^ args);
			static void TeamHUDMessage(int team, Color color, String^ format, ...array<Object^>^ args);
			static void PrivateHUDMessage(IcPlayer^ player, Color color, String^ format, ...array<Object^>^ args);
			static void PrivateHUDMessage(int player, Color color, String^ format, ...array<Object^>^ args);
			static void PrivateHUDMessage(IScriptableGameObj^ player, Color color, String^ format, ...array<Object^>^ args);

			static property String ^Version
			{
				String ^get();
			}

			static property String^ MessagePrefix
			{
				String^ get();
			}

			static property IDynamicVectorClass<IConsoleFunctionClass^>^ ConsoleFunctionList
			{
				IDynamicVectorClass<IConsoleFunctionClass^>^ get();
				void set(IDynamicVectorClass<IConsoleFunctionClass^>^ value);
			}
	};
}