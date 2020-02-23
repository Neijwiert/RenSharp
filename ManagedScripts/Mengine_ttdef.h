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

#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4561 4251 4244 26495 26454)
#include <engine_ttdef.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Runtime::InteropServices;

namespace RenSharp
{
	public enum class TextMessageEnum : int
	{
		TextMessagePublic = ::TEXT_MESSAGE_PUBLIC,
		TextMessageTeam = ::TEXT_MESSAGE_TEAM,
		TextMessagePrivate = ::TEXT_MESSAGE_PRIVATE,
		TextMessageTMSG = ::TEXT_MESSAGE_TMSG,
		TextMessageKeyHook = ::TEXT_MESSAGE_KEYHOOK
	};

	public enum class AnnouncementEnum : int
	{
		AnnouncePublic = ::ANNOUNCE_PUBLIC,
		AnnounceTeam = ::ANNOUNCE_TEAM,
		AnnouncePrivate = ::ANNOUNCE_PRIVATE
	};

	public enum class PathfindDistanceResult : int
	{
		PathfindDistanceInvalidResult = ::PATHFIND_DISTANCE_INVALID_RESULT,
		PathfindDistanceResultOk = ::PATHFIND_DISTANCE_RESULT_OK,
		PathfindDistanceResultCanceled = ::PATHFIND_DISTANCE_RESULT_CANCELED,
		PathfindDistanceResultInvalidStartPos = ::PATHFIND_DISTANCE_RESULT_INVALID_START_POS,
		PathfindDistanceResultInvalidDestPos = ::PATHFIND_DISTANCE_RESULT_INVALID_DEST_POS,
		PathfindDistanceResultNoPath = ::PATHFIND_DISTANCE_RESULT_NO_PATH
	};
}