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

#include <coltest.h>

class RenSharpOBBoxCollisionTestClass : public OBBoxCollisionTestClass
{
	private:
		CastResultStruct result;

	public:
		RenSharpOBBoxCollisionTestClass(const OBBoxClass &obbox, const Vector3 &move, Collision_Type collisionType);
		RenSharpOBBoxCollisionTestClass(const OBBoxClass &obbox, const Vector3 &move);
		RenSharpOBBoxCollisionTestClass(const OBBoxCollisionTestClass &that, const Matrix3D &tm);
		RenSharpOBBoxCollisionTestClass(const AABoxCollisionTestClass &that, const Matrix3D &tm);

		void setResult(const CastResultStruct &res);
};