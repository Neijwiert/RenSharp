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

#include "MStaticAnimPhysDefClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <BuildingAggregateDefClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{

#pragma managed(push, off)

	class BuildingAggregateDefClassHelper : public ::BuildingAggregateDefClass
	{
		public:
			static constexpr int AnimLogicLinear = ::BuildingAggregateDefClass::ANIM_LOGIC_LINEAR;
			static constexpr int AnimLogicLoop = ::BuildingAggregateDefClass::ANIM_LOGIC_LOOP;
			static constexpr int AnimLogicSequence = ::BuildingAggregateDefClass::ANIM_LOGIC_SEQUENCE;
			static constexpr std::size_t Frame0SizeCount = (sizeof(Frame0) / sizeof(std::remove_all_extents<decltype(Frame0)>::type));
			static constexpr std::size_t Frame1SizeCount = (sizeof(Frame1) / sizeof(std::remove_all_extents<decltype(Frame1)>::type));
			static constexpr std::size_t AnimationEnabledSizeCount = (sizeof(AnimationEnabled) / sizeof(std::remove_all_extents<decltype(AnimationEnabled)>::type));

		private:
			BuildingAggregateDefClassHelper() = default;

		public:
			int& GetAnimLogicMode()
			{
				return AnimLogicMode;
			}

			bool& GetIsMCT()
			{
				return IsMCT;
			}

			void GetFrame0(int* result)
			{
				std::memcpy(result, Frame0, sizeof(Frame0));
			}

			void SetFrame0(int* value)
			{
				std::memcpy(Frame0, value, sizeof(Frame0));
			}

			void GetFrame1(int* result)
			{
				std::memcpy(result, Frame1, sizeof(Frame1));
			}

			void SetFrame1(int* value)
			{
				std::memcpy(Frame1, value, sizeof(Frame1));
			}

			void GetAnimationEnabled(bool* result)
			{
				std::memcpy(result, AnimationEnabled, sizeof(AnimationEnabled));
			}

			void SetAnimationEnabled(bool* value)
			{
				std::memcpy(AnimationEnabled, value, sizeof(AnimationEnabled));
			}
	};

#pragma managed(pop)

	public interface class IBuildingAggregateDefClass : public IStaticAnimPhysDefClass
	{
		property IntPtr BuildingAggregateDefClassPointer
		{
			IntPtr get();
		}
	};

	public enum class AnimLogicEnum : int
	{
		AnimLogicLinear = BuildingAggregateDefClassHelper::AnimLogicLinear,
		AnimLogicLoop = BuildingAggregateDefClassHelper::AnimLogicLoop,
		AnimLogicSequence = BuildingAggregateDefClassHelper::AnimLogicSequence
	};

	public ref class BuildingAggregateDefClass : public StaticAnimPhysDefClass, public IBuildingAggregateDefClass
	{
		public:
			BuildingAggregateDefClass(IntPtr pointer);

			property IntPtr BuildingAggregateDefClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::StaticAnimPhysDefClass* InternalStaticAnimPhysDefClassPointer
			{
				::StaticAnimPhysDefClass* get() override;
			}

			property ::BuildingAggregateDefClass* InternalBuildingAggregateDefClassPointer
			{
				virtual ::BuildingAggregateDefClass* get();
			}

			property int AnimLogicMode
			{
				int get();
				void set(int value);
			}

			property bool IsMCT
			{
				bool get();
				void set(bool value);
			}

			property array<int>^ Frame0
			{
				array<int>^ get();
				void set(array<int>^ value);
			}

			property array<int>^ Frame1
			{
				array<int>^ get();
				void set(array<int>^ value);
			}

			property array<bool>^ AnimationEnabled
			{
				array<bool>^ get();
				void set(array<bool>^ value);
			}
	};
}