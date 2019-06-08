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
#include "MFrustumClass.h"

#include "Mvector2.h"
#include "Imports.h"

namespace RenSharp
{
	void FrustumClass::Init(Matrix3D camera, Vector2 vpMin, Vector2 vpMax, float zNear, float zFar)
	{
		::Matrix3D cameraMat;
		::Vector2 vpMinVec;
		::Vector2 vpMaxVec;

		Matrix3D::ManagedToUnmanagedMatrix3D(camera, cameraMat);
		Vector2::ManagedToUnmanagedVector2(vpMin, vpMinVec);
		Vector2::ManagedToUnmanagedVector2(vpMax, vpMaxVec);

		::FrustumClass thisFrustum;
		ManagedToUnmanagedFrustumClass(thisFrustum);

		Imports::FrustumClassInit(&thisFrustum, &cameraMat, &vpMinVec, &vpMaxVec, zNear, zFar);

		UnmanagedToManagedFrustumClass(thisFrustum);
	}
}