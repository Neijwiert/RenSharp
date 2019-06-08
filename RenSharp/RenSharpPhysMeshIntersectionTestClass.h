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

#include <MeshClass.h>
#include <PhysClass.h>
#include <physinttest.h>

class RenSharpPhysMeshIntersectionTestClass : public PhysMeshIntersectionTestClass
{
	private:
		bool resultListEnabled;
		MultiListClass<PhysClass> resultList;

	public:
		RenSharpPhysMeshIntersectionTestClass(MeshClass *mesh, int colGroup, int colType, bool enableResultList);

		MultiListClass<PhysClass> *getResultList();
};