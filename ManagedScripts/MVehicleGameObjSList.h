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

#include "MSList.h"

#pragma managed(push, off)

class VehicleGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class IVehicleGameObj;

	public ref class VehicleGameObjSLNode : public SLNode<IVehicleGameObj ^>
	{
		public:
			VehicleGameObjSLNode(IntPtr pointer);

			void SetNext(ISLNode<IVehicleGameObj ^> ^next) override sealed;

			property IntPtr VehicleGameObjSLNodePointer
			{
				IntPtr get();
			}

			property ISLNode<IVehicleGameObj ^> ^Next
			{
				ISLNode<IVehicleGameObj ^> ^get() override sealed;
			}

			property IVehicleGameObj ^Data
			{
				IVehicleGameObj ^get() override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::AutoPoolClass<::GenericSLNode, 256> *InternalAutoPoolClassPointer
			{
				::AutoPoolClass<::GenericSLNode, 256> *get() override;
			}

			property ::GenericSLNode *InternalGenericSLNodePointer
			{
				::GenericSLNode *get() override;
			}

			property ::SLNode<::VehicleGameObj> *InternalVehicleGameObjSLNodePointer
			{
				virtual ::SLNode<::VehicleGameObj> *get();
			}
	};

	public ref class VehicleGameObjSList : public SList<IVehicleGameObj ^>
	{
		private:
			VehicleGameObjSList();

		public:
			VehicleGameObjSList(IntPtr pointer);

			static IUnmanagedContainer<ISList<IVehicleGameObj ^> ^> ^CreateVehicleGameObjSList();

			bool AddHead(IVehicleGameObj ^data) override sealed;
			bool AddHead(ISList<IVehicleGameObj ^> ^list) override sealed;
			bool AddTail(IVehicleGameObj ^data) override sealed;
			bool AddTail(ISList<IVehicleGameObj ^> ^list) override sealed;
			IVehicleGameObj ^RemoveHead() override sealed;
			IVehicleGameObj ^RemoveTail() override sealed;
			bool Remove(IVehicleGameObj ^data) override;
			void RemoveAll() override sealed;
			bool InsertBefore(IVehicleGameObj ^newNode, IVehicleGameObj ^oldNode) override sealed;
			bool InsertAfter(IVehicleGameObj ^newNode, IVehicleGameObj ^oldNode) override sealed;
			ISLNode<IVehicleGameObj ^> ^FindNode(IVehicleGameObj ^data) override sealed;
			void InsertBefore(IVehicleGameObj ^data, ISLNode<IVehicleGameObj ^> ^node) override sealed;
			void InsertAfter(IVehicleGameObj ^data, ISLNode<IVehicleGameObj ^> ^node) override sealed;

			property IntPtr VehicleGameObjSListPointer
			{
				IntPtr get();
			}

			property bool IsEmpty
			{
				bool get() override sealed;
			}

			property ISLNode<IVehicleGameObj ^> ^Head
			{
				ISLNode<IVehicleGameObj ^> ^get() override sealed;
			}

			property ISLNode<IVehicleGameObj ^> ^Tail
			{
				ISLNode<IVehicleGameObj ^> ^get() override sealed;
			}

			property int Count
			{
				int get() override;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::SList<::VehicleGameObj> *InternalVehicleGameObjSListPointer
			{
				virtual ::SList<::VehicleGameObj> *get();
			}
	};
}