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

#include "AbstractUnmanagedObject.h"

namespace RenSharp
{
	interface class IChunkSaveClass;
	interface class IChunkLoadClass;
	interface class IReferencerClass;

	generic<typename T>
	public interface class IReferenceableClass : public IUnmanagedObject
	{
		literal int ChunkIDRefVariables = CHUNKID_REF_VARIABLES;

		literal int XXXXMicroChunkIDListHead = XXXX_MICROCHUNKID_LIST_HEAD;

		literal int MicroChunkIDXXXXXXXXX = MICROCHUNKID_XXXXXXXXX;

		literal int MicroChunkIDPtr = MICROCHUNKID_PTR;

		literal int MicroChunkIDTarget = MICROCHUNKID_TARGET;

		literal int XXXXMicroChunkIDNext = XXXX_MICROCHUNKID_NEXT;

		bool Save(IChunkSaveClass ^csave);
	};

	generic<typename T>
	public ref class ReferenceableClass abstract: public AbstractUnmanagedObject, public IReferenceableClass<T>
	{
		protected:
			ReferenceableClass()
				: AbstractUnmanagedObject()
			{

			}

		public:
			ReferenceableClass(IntPtr pointer)
				: AbstractUnmanagedObject(pointer)
			{

			}

			virtual bool Save(IChunkSaveClass ^csave) = 0;

		protected:
			property IReferencerClass ^ReferencerListHead
			{
				virtual IReferencerClass ^get() = 0;
				virtual void set(IReferencerClass ^value) = 0;
			}

			property T Data
			{
				virtual T get() = 0;
			}
	};
}