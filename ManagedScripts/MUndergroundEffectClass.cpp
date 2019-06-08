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

#include "stdafx.h"
#include "MUndergroundEffectClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <UndergroundEffectClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MVector3.h"

namespace RenSharp
{

#pragma managed(push, off)

	class UndergroundEffectClassHelper : public ::UndergroundEffectClass
	{
		private:
			UndergroundEffectClassHelper() = default;

		public:
			bool &GetIsUnderground()
			{
				return IsUnderground;
			}

			bool &GetWasUnderground()
			{
				return WasUnderground;
			}

			bool &GetIsVisible()
			{
				return IsVisible;
			}

			float &GetFadeDistance()
			{
				return FadeDistance;
			}

			float &GetCurrentFraction()
			{
				return CurrentFraction;
			}

			bool &GetRenderStealthMaterial()
			{
				return RenderStealthMaterial;
			}

			float &GetIntensityScale()
			{
				return IntensityScale;
			}

			::MaterialPassClass *&GetMaterialPass()
			{
				return MaterialPass;
			}

			::MatrixMapperClass *&GetMapper()
			{
				return Mapper;
			}

			::Vector3 &GetColor()
			{
				return Color;
			}
	};

#pragma managed(pop)

	UndergroundEffectClass::UndergroundEffectClass(IntPtr pointer)
		: MaterialEffectClass(pointer)
	{

	}

	IntPtr UndergroundEffectClass::UndergroundEffectClassPointer::get()
	{
		return IntPtr(InternalUndergroundEffectClassPointer);
	}

	bool UndergroundEffectClass::IsUnderground::get()
	{
		return InternalUndergroundEffectClassPointer->Is_Underground();
	}

	void UndergroundEffectClass::IsUnderground::set(bool value)
	{
		auto helper = reinterpret_cast<UndergroundEffectClassHelper *>(InternalUndergroundEffectClassPointer);

		auto &isUnderground = helper->GetIsUnderground();

		isUnderground = value;
	}

	bool UndergroundEffectClass::IsVisible::get()
	{
		return InternalUndergroundEffectClassPointer->Is_Visible();
	}

	void UndergroundEffectClass::IsVisible::set(bool value)
	{
		auto helper = reinterpret_cast<UndergroundEffectClassHelper *>(InternalUndergroundEffectClassPointer);

		auto &isVisible = helper->GetIsVisible();

		isVisible = value;
	}

	float UndergroundEffectClass::FadeDistance::get()
	{
		return InternalUndergroundEffectClassPointer->Get_Fade_Distance();
	}

	void UndergroundEffectClass::FadeDistance::set(float value)
	{
		InternalUndergroundEffectClassPointer->Set_Fade_Distance(value);
	}

	Drawing::Color UndergroundEffectClass::Color::get()
	{
		auto &color = InternalUndergroundEffectClassPointer->Get_Color();

		return Drawing::Color::FromArgb(255, static_cast<int>(color.X * 255.0f), static_cast<int>(color.Y * 255.0f), static_cast<int>(color.Z * 255.0f));
	}

	void UndergroundEffectClass::Color::set(Drawing::Color value)
	{
		auto helper = reinterpret_cast<UndergroundEffectClassHelper *>(InternalUndergroundEffectClassPointer);

		auto &color = helper->GetColor();

		::Vector3 tmp(value.R / 255.0f, value.G / 255.0f, value.B / 255.0f);

		color = tmp;
	}

	::MultiListObjectClass *UndergroundEffectClass::InternalMultiListObjectClassPointer::get()
	{
		return InternalUndergroundEffectClassPointer;
	}

	::MaterialEffectClass *UndergroundEffectClass::InternalMaterialEffectClassPointer::get()
	{
		return InternalUndergroundEffectClassPointer;
	}

	::UndergroundEffectClass *UndergroundEffectClass::InternalUndergroundEffectClassPointer::get()
	{
		return reinterpret_cast<::UndergroundEffectClass *>(Pointer.ToPointer());
	}

	bool UndergroundEffectClass::WasUnderground::get()
	{
		auto helper = reinterpret_cast<UndergroundEffectClassHelper *>(InternalUndergroundEffectClassPointer);

		auto &wasUnderground = helper->GetWasUnderground();

		return wasUnderground;
	}

	void UndergroundEffectClass::WasUnderground::set(bool value)
	{
		auto helper = reinterpret_cast<UndergroundEffectClassHelper *>(InternalUndergroundEffectClassPointer);

		auto &wasUnderground = helper->GetWasUnderground();

		wasUnderground = value;
	}

	float UndergroundEffectClass::CurrentFraction::get()
	{
		auto helper = reinterpret_cast<UndergroundEffectClassHelper *>(InternalUndergroundEffectClassPointer);

		auto &currentFraction = helper->GetCurrentFraction();

		return currentFraction;
	}

	void UndergroundEffectClass::CurrentFraction::set(float value)
	{
		auto helper = reinterpret_cast<UndergroundEffectClassHelper *>(InternalUndergroundEffectClassPointer);

		auto &currentFraction = helper->GetCurrentFraction();

		currentFraction = value;
	}

	bool UndergroundEffectClass::RenderStealthMaterial::get()
	{
		auto helper = reinterpret_cast<UndergroundEffectClassHelper *>(InternalUndergroundEffectClassPointer);

		auto &renderStealthMaterial = helper->GetRenderStealthMaterial();

		return renderStealthMaterial;
	}

	void UndergroundEffectClass::RenderStealthMaterial::set(bool value)
	{
		auto helper = reinterpret_cast<UndergroundEffectClassHelper *>(InternalUndergroundEffectClassPointer);

		auto &renderStealthMaterial = helper->GetRenderStealthMaterial();

		renderStealthMaterial = value;
	}

	float UndergroundEffectClass::IntensityScale::get()
	{
		auto helper = reinterpret_cast<UndergroundEffectClassHelper *>(InternalUndergroundEffectClassPointer);

		auto &intensityScale = helper->GetIntensityScale();

		return intensityScale;
	}

	void UndergroundEffectClass::IntensityScale::set(float value)
	{
		auto helper = reinterpret_cast<UndergroundEffectClassHelper *>(InternalUndergroundEffectClassPointer);

		auto &intensityScale = helper->GetIntensityScale();

		intensityScale = value;
	}

	IntPtr UndergroundEffectClass::MaterialPass::get()
	{
		auto helper = reinterpret_cast<UndergroundEffectClassHelper *>(InternalUndergroundEffectClassPointer);

		auto &materialPass = helper->GetMaterialPass();

		return IntPtr(materialPass);
	}

	void UndergroundEffectClass::MaterialPass::set(IntPtr value)
	{
		auto helper = reinterpret_cast<UndergroundEffectClassHelper *>(InternalUndergroundEffectClassPointer);

		auto &materialPass = helper->GetMaterialPass();

		materialPass = reinterpret_cast<::MaterialPassClass *>(value.ToPointer());
	}

	IntPtr UndergroundEffectClass::Mapper::get()
	{
		auto helper = reinterpret_cast<UndergroundEffectClassHelper *>(InternalUndergroundEffectClassPointer);

		auto &mapper = helper->GetMapper();

		return IntPtr(mapper);
	}

	void UndergroundEffectClass::Mapper::set(IntPtr value)
	{
		auto helper = reinterpret_cast<UndergroundEffectClassHelper *>(InternalUndergroundEffectClassPointer);

		auto &mapper = helper->GetMapper();

		mapper = reinterpret_cast<::MatrixMapperClass *>(value.ToPointer());
	}
}