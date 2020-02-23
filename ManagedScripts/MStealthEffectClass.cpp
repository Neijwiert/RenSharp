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
#include "MStealthEffectClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <StealthEffectClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "Mvector2.h"

namespace RenSharp
{

#pragma managed(push, off)

	class StealthEffectClassHelper : public ::StealthEffectClass
	{
		private:
			StealthEffectClassHelper() = default;

		public:
			bool &GetIsStealthEnabled()
			{
				return IsStealthEnabled;
			}

			bool &GetIsFriendly()
			{
				return IsFriendly;
			}

			bool &GetIsBroken()
			{
				return IsBroken;
			}

			float &GetCurrentFraction()
			{
				return CurrentFraction;
			}

			float &GetTargetFraction()
			{
				return TargetFraction;
			}

			::Vector2 &GetUVRate()
			{
				return UVRate;
			}

			bool &GetRenderBaseMaterial()
			{
				return RenderBaseMaterial;
			}

			bool &GetRenderStealthMaterial()
			{
				return RenderStealthMaterial;
			}

			float &GetIntensityScale()
			{
				return IntensityScale;
			}

			::Vector2 &GetUVOffset()
			{
				return UVOffset;
			}

			::MatrixMapperClass *&GetMapper()
			{
				return Mapper;
			}

			::MaterialPassClass *&GetMaterialPass()
			{
				return MaterialPass;
			}
	};

#pragma managed(pop)

	StealthEffectClass::StealthEffectClass(IntPtr pointer)
		: MaterialEffectClass(pointer)
	{

	}

	void StealthEffectClass::SetCurrentState(float percent)
	{
		InternalStealthEffectClassPointer->Set_Current_State(percent);
	}

	void StealthEffectClass::SetTargetState(float percent)
	{
		InternalStealthEffectClassPointer->Set_Target_State(percent);
	}

	IntPtr StealthEffectClass::StealthEffectClassPointer::get()
	{
		return IntPtr(InternalStealthEffectClassPointer);
	}

	bool StealthEffectClass::IsStealthEnabled::get()
	{
		return InternalStealthEffectClassPointer->Is_Stealth_Enabled();
	}

	void StealthEffectClass::IsStealthEnabled::set(bool value)
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &isStealthEnabled = helper->GetIsStealthEnabled();

		isStealthEnabled = value;
	}

	bool StealthEffectClass::IsFriendly::get()
	{
		return InternalStealthEffectClassPointer->Is_Friendly();
	}

	void StealthEffectClass::IsFriendly::set(bool value)
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &isFriendly = helper->GetIsFriendly();

		isFriendly = value;
	}

	bool StealthEffectClass::IsBroken::get()
	{
		return InternalStealthEffectClassPointer->Is_Broken();
	}

	void StealthEffectClass::IsBroken::set(bool value)
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &isBroken = helper->GetIsBroken();

		isBroken = value;
	}

	bool StealthEffectClass::IsStealthed::get()
	{
		return InternalStealthEffectClassPointer->Is_Stealthed();
	}

	float StealthEffectClass::FadeDistance::get()
	{
		return InternalStealthEffectClassPointer->Get_Fade_Distance();
	}

	void StealthEffectClass::FadeDistance::set(float value)
	{
		InternalStealthEffectClassPointer->Set_Fade_Distance(value);
	}

	::MaterialEffectClass *StealthEffectClass::InternalMaterialEffectClassPointer::get()
	{
		return InternalStealthEffectClassPointer;
	}

	::StealthEffectClass *StealthEffectClass::InternalStealthEffectClassPointer::get()
	{
		return reinterpret_cast<::StealthEffectClass *>(Pointer.ToPointer());
	}

	float StealthEffectClass::CurrentFraction::get()
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &currentFraction = helper->GetCurrentFraction();

		return currentFraction;
	}

	void StealthEffectClass::CurrentFraction::set(float value)
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &currentFraction = helper->GetCurrentFraction();

		currentFraction = value;
	}

	float StealthEffectClass::TargetFraction::get()
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &targetFraction = helper->GetTargetFraction();

		return targetFraction;
	}

	void StealthEffectClass::TargetFraction::set(float value)
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &targetFraction = helper->GetTargetFraction();

		targetFraction = value;
	}

	Vector2 StealthEffectClass::UVRate::get()
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &uvRate = helper->GetUVRate();

		Vector2 result;
		Vector2::UnmanagedToManagedVector2(uvRate, result);

		return result;
	}

	void StealthEffectClass::UVRate::set(Vector2 value)
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &uvRate = helper->GetUVRate();

		Vector2::ManagedToUnmanagedVector2(value, uvRate);
	}

	bool StealthEffectClass::RenderBaseMaterial::get()
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &renderBaseMaterial = helper->GetRenderBaseMaterial();

		return renderBaseMaterial;
	}

	void StealthEffectClass::RenderBaseMaterial::set(bool value)
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &renderBaseMaterial = helper->GetRenderBaseMaterial();

		renderBaseMaterial = value;
	}

	bool StealthEffectClass::RenderStealthMaterial::get()
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &renderStealthMaterial = helper->GetRenderStealthMaterial();

		return renderStealthMaterial;
	}

	void StealthEffectClass::RenderStealthMaterial::set(bool value)
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &renderStealthMaterial = helper->GetRenderStealthMaterial();

		renderStealthMaterial = value;
	}

	float StealthEffectClass::IntensityScale::get()
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &intensityScale = helper->GetIntensityScale();

		return intensityScale;
	}

	void StealthEffectClass::IntensityScale::set(float value)
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &intensityScale = helper->GetIntensityScale();

		intensityScale = value;
	}

	Vector2 StealthEffectClass::UVOffset::get()
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &uvOffset = helper->GetUVOffset();

		Vector2 result;
		Vector2::UnmanagedToManagedVector2(uvOffset, result);

		return result;
	}

	void StealthEffectClass::UVOffset::set(Vector2 value)
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &uvOffset = helper->GetUVOffset();

		Vector2::ManagedToUnmanagedVector2(value, uvOffset);
	}

	IntPtr StealthEffectClass::Mapper::get()
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &mapper = helper->GetMapper();

		return IntPtr(mapper);
	}

	void StealthEffectClass::Mapper::set(IntPtr value)
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &mapper = helper->GetMapper();

		if (value.ToPointer() == nullptr)
		{
			mapper = nullptr;
		}
		else
		{
			mapper = reinterpret_cast<::MatrixMapperClass *>(value.ToPointer());
		}
	}

	IntPtr StealthEffectClass::MaterialPass::get()
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &materialPass = helper->GetMaterialPass();

		return IntPtr(materialPass);
	}

	void StealthEffectClass::MaterialPass::set(IntPtr value)
	{
		auto helper = reinterpret_cast<StealthEffectClassHelper *>(InternalStealthEffectClassPointer);

		auto &materialPass = helper->GetMaterialPass();

		if (value.ToPointer() == nullptr)
		{
			materialPass = nullptr;
		}
		else
		{
			materialPass = reinterpret_cast<::MaterialPassClass *>(value.ToPointer());
		}
	}
}