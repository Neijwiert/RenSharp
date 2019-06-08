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
#include "MProjectorManagerClass.h"

using namespace System::Runtime::InteropServices;

namespace RenSharp
{

#pragma managed(push, off)

	class ProjectorManagerClassHelper : public ::ProjectorManagerClass
	{
		private:
			ProjectorManagerClassHelper() = default;

		public:
			uint16 &GetFlags()
			{
				return Flags;
			}

			uint16 &GetProjectorBoneIndex()
			{
				return ProjectorBoneIndex;
			}

			::TexProjectClass *&GetProjector()
			{
				return Projector;
			}
	};

#pragma managed(pop)

	ProjectorManagerClass::ProjectorManagerClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool ProjectorManagerClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IProjectorManagerClass ^otherThis = dynamic_cast<IProjectorManagerClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return ProjectorManagerClassPointer.Equals(otherThis->ProjectorManagerClassPointer);
	}

	void ProjectorManagerClass::SetFlag(int flag, bool onoff)
	{
		InternalProjectorManagerClassPointer->Set_Flag(flag, onoff);
	}

	bool ProjectorManagerClass::GetFlag(int flag)
	{
		return InternalProjectorManagerClassPointer->Get_Flag(flag);
	}

	IntPtr ProjectorManagerClass::ProjectorManagerClassPointer::get()
	{
		return IntPtr(InternalProjectorManagerClassPointer);
	}

	::ProjectorManagerClass *ProjectorManagerClass::InternalProjectorManagerClassPointer::get()
	{
		return reinterpret_cast<::ProjectorManagerClass *>(Pointer.ToPointer());
	}

	uint16 ProjectorManagerClass::Flags::get()
	{
		auto helper = reinterpret_cast<ProjectorManagerClassHelper *>(InternalProjectorManagerClassPointer);

		auto &flags = helper->GetFlags();

		return flags;
	}

	void ProjectorManagerClass::Flags::set(uint16 value)
	{
		auto helper = reinterpret_cast<ProjectorManagerClassHelper *>(InternalProjectorManagerClassPointer);

		auto &flags = helper->GetFlags();

		flags = value;
	}

	uint16 ProjectorManagerClass::ProjectorBoneIndex::get()
	{
		auto helper = reinterpret_cast<ProjectorManagerClassHelper *>(InternalProjectorManagerClassPointer);

		auto &projectorBoneIndex = helper->GetProjectorBoneIndex();

		return projectorBoneIndex;
	}

	void ProjectorManagerClass::ProjectorBoneIndex::set(uint16 value)
	{
		auto helper = reinterpret_cast<ProjectorManagerClassHelper *>(InternalProjectorManagerClassPointer);

		auto &projectorBoneIndex = helper->GetProjectorBoneIndex();

		projectorBoneIndex = value;
	}

	IntPtr ProjectorManagerClass::Projector::get()
	{
		auto helper = reinterpret_cast<ProjectorManagerClassHelper *>(InternalProjectorManagerClassPointer);

		auto &projector = helper->GetProjector();

		return IntPtr(projector);
	}

	void ProjectorManagerClass::Projector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<ProjectorManagerClassHelper *>(InternalProjectorManagerClassPointer);

		auto &projector = helper->GetProjector();

		projector = reinterpret_cast<::TexProjectClass *>(value.ToPointer());
	}

	ProjectorManagerDefClass::ProjectorManagerDefClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IntPtr ProjectorManagerDefClass::ProjectorManagerDefClassPointer::get()
	{
		return IntPtr(InternalProjectorManagerDefClassPointer);
	}

	bool ProjectorManagerDefClass::IsEnabled::get()
	{
		return InternalProjectorManagerDefClassPointer->IsEnabled;
	}

	void ProjectorManagerDefClass::IsEnabled::set(bool value)
	{
		InternalProjectorManagerDefClassPointer->IsEnabled = value;
	}

	bool ProjectorManagerDefClass::IsPerspective::get()
	{
		return InternalProjectorManagerDefClassPointer->IsPerspective;
	}

	void ProjectorManagerDefClass::IsPerspective::set(bool value)
	{
		InternalProjectorManagerDefClassPointer->IsPerspective = value;
	}

	bool ProjectorManagerDefClass::IsAdditive::get()
	{
		return InternalProjectorManagerDefClassPointer->IsAdditive;
	}

	void ProjectorManagerDefClass::IsAdditive::set(bool value)
	{
		InternalProjectorManagerDefClassPointer->IsAdditive = value;
	}

	bool ProjectorManagerDefClass::IsAnimated::get()
	{
		return InternalProjectorManagerDefClassPointer->IsAnimated;
	}

	void ProjectorManagerDefClass::IsAnimated::set(bool value)
	{
		InternalProjectorManagerDefClassPointer->IsAnimated = value;
	}

	float ProjectorManagerDefClass::OrthoWidth::get()
	{
		return InternalProjectorManagerDefClassPointer->OrthoWidth;
	}

	void ProjectorManagerDefClass::OrthoWidth::set(float value)
	{
		InternalProjectorManagerDefClassPointer->OrthoWidth = value;
	}

	float ProjectorManagerDefClass::OrthoHeight::get()
	{
		return InternalProjectorManagerDefClassPointer->OrthoHeight;
	}

	void ProjectorManagerDefClass::OrthoHeight::set(float value)
	{
		InternalProjectorManagerDefClassPointer->OrthoHeight = value;
	}

	float ProjectorManagerDefClass::HorizontalFOV::get()
	{
		return InternalProjectorManagerDefClassPointer->HorizontalFOV;
	}

	void ProjectorManagerDefClass::HorizontalFOV::set(float value)
	{
		InternalProjectorManagerDefClassPointer->HorizontalFOV = value;
	}

	float ProjectorManagerDefClass::VerticalFOV::get()
	{
		return InternalProjectorManagerDefClassPointer->VerticalFOV;
	}

	void ProjectorManagerDefClass::VerticalFOV::set(float value)
	{
		InternalProjectorManagerDefClassPointer->VerticalFOV = value;
	}

	float ProjectorManagerDefClass::NearZ::get()
	{
		return InternalProjectorManagerDefClassPointer->NearZ;
	}

	void ProjectorManagerDefClass::NearZ::set(float value)
	{
		InternalProjectorManagerDefClassPointer->NearZ = value;
	}

	float ProjectorManagerDefClass::FarZ::get()
	{
		return InternalProjectorManagerDefClassPointer->FarZ;
	}

	void ProjectorManagerDefClass::FarZ::set(float value)
	{
		InternalProjectorManagerDefClassPointer->FarZ = value;
	}

	float ProjectorManagerDefClass::Intensity::get()
	{
		return InternalProjectorManagerDefClassPointer->Intensity;
	}

	void ProjectorManagerDefClass::Intensity::set(float value)
	{
		InternalProjectorManagerDefClassPointer->Intensity = value;
	}

	String ^ProjectorManagerDefClass::TextureName::get()
	{
		return gcnew String(InternalProjectorManagerDefClassPointer->TextureName.Peek_Buffer());
	}

	void ProjectorManagerDefClass::TextureName::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalProjectorManagerDefClassPointer->TextureName = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String ^ProjectorManagerDefClass::BoneName::get()
	{
		return gcnew String(InternalProjectorManagerDefClassPointer->BoneName.Peek_Buffer());
	}

	void ProjectorManagerDefClass::BoneName::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalProjectorManagerDefClassPointer->BoneName = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	::ProjectorManagerDefClass *ProjectorManagerDefClass::InternalProjectorManagerDefClassPointer::get()
	{
		return reinterpret_cast<::ProjectorManagerDefClass *>(Pointer.ToPointer());
	}
}