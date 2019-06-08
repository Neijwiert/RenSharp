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
#include "MNetworkObjectClass.h"

#include "Imports.h"

namespace RenSharp
{
	NetworkObjectClass::NetworkObjectClass(IntPtr pointer) 
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool NetworkObjectClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		INetworkObjectClass ^otherThis = dynamic_cast<INetworkObjectClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return NetworkObjectClassPointer.Equals(otherThis->NetworkObjectClassPointer);
	}

	void NetworkObjectClass::ImportCreation(IntPtr packet)
	{
		if (packet == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("packet");
		}

		InternalNetworkObjectClassPointer->Import_Creation(*reinterpret_cast<::BitStreamClass *>(packet.ToPointer()));
	}

	void NetworkObjectClass::ImportRare(IntPtr packet)
	{
		if (packet == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("packet");
		}

		InternalNetworkObjectClassPointer->Import_Rare(*reinterpret_cast<::BitStreamClass *>(packet.ToPointer()));
	}

	void NetworkObjectClass::ImportOccasional(IntPtr packet)
	{
		if (packet == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("packet");
		}

		InternalNetworkObjectClassPointer->Import_Occasional(*reinterpret_cast<::BitStreamClass *>(packet.ToPointer()));
	}

	void NetworkObjectClass::ImportFrequent(IntPtr packet)
	{
		if (packet == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("packet");
		}

		InternalNetworkObjectClassPointer->Import_Frequent(*reinterpret_cast<::BitStreamClass *>(packet.ToPointer()));
	}

	void NetworkObjectClass::ExportCreation(IntPtr packet)
	{
		if (packet == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("packet");
		}

		InternalNetworkObjectClassPointer->Export_Creation(*reinterpret_cast<::BitStreamClass *>(packet.ToPointer()));
	}

	void NetworkObjectClass::ExportRare(IntPtr packet)
	{
		if (packet == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("packet");
		}

		InternalNetworkObjectClassPointer->Export_Rare(*reinterpret_cast<::BitStreamClass *>(packet.ToPointer()));
	}

	void NetworkObjectClass::ExportOccasional(IntPtr packet)
	{
		if (packet == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("packet");
		}

		InternalNetworkObjectClassPointer->Export_Occasional(*reinterpret_cast<::BitStreamClass *>(packet.ToPointer()));
	}

	void NetworkObjectClass::ExportFrequent(IntPtr packet)
	{
		if (packet == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("packet");
		}

		InternalNetworkObjectClassPointer->Export_Frequent(*reinterpret_cast<::BitStreamClass *>(packet.ToPointer()));
	}

	void NetworkObjectClass::NetworkThink()
	{
		InternalNetworkObjectClassPointer->Network_Think();
	}

	void NetworkObjectClass::SetDeletePending()
	{
		InternalNetworkObjectClassPointer->Set_Delete_Pending();
	}

	void NetworkObjectClass::Delete()
	{
		InternalNetworkObjectClassPointer->Delete();
	}

	void NetworkObjectClass::SetObjectDirtyBit(DirtyBit dirtyBit, bool onOff)
	{
		InternalNetworkObjectClassPointer->Set_Object_Dirty_Bit(static_cast<::NetworkObjectClass::DIRTY_BIT>(dirtyBit), onOff);
	}

	void NetworkObjectClass::SetObjectDirtyBit(int clientId, DirtyBit dirtyBit, bool onOff)
	{
		if (clientId < 0 || clientId >= INetworkObjectClass::MaxClientCount)
		{
			throw gcnew ArgumentOutOfRangeException("clientId");
		}

		InternalNetworkObjectClassPointer->Set_Object_Dirty_Bit(clientId, static_cast<::NetworkObjectClass::DIRTY_BIT>(dirtyBit), onOff);
	}

	void NetworkObjectClass::ClearObjectDirtyBits()
	{
		InternalNetworkObjectClassPointer->Clear_Object_Dirty_Bits();
	}

	bool NetworkObjectClass::GetObjectDirtyBit(int clientId, DirtyBit dirtyBit)
	{
		if (clientId < 0 || clientId >= INetworkObjectClass::MaxClientCount)
		{
			throw gcnew ArgumentOutOfRangeException("clientId");
		}

		return InternalNetworkObjectClassPointer->Get_Object_Dirty_Bit(clientId, static_cast<::NetworkObjectClass::DIRTY_BIT>(dirtyBit));
	}

	BYTE NetworkObjectClass::GetObjectDirtyBits(int clientId)
	{
		if (clientId < 0 || clientId >= INetworkObjectClass::MaxClientCount)
		{
			throw gcnew ArgumentOutOfRangeException("clientId");
		}

		return InternalNetworkObjectClassPointer->Get_Object_Dirty_Bits(clientId);
	}

	void NetworkObjectClass::SetObjectDirtyBits(int clientId, BYTE bits)
	{
		if (clientId < 0 || clientId >= INetworkObjectClass::MaxClientCount)
		{
			throw gcnew ArgumentOutOfRangeException("clientId");
		}

		InternalNetworkObjectClassPointer->Set_Object_Dirty_Bits(clientId, bits);
	}

	bool NetworkObjectClass::IsClientDirty(int clientId)
	{
		if (clientId < 0 || clientId >= INetworkObjectClass::MaxClientCount)
		{
			throw gcnew ArgumentOutOfRangeException("clientId");
		}

		return InternalNetworkObjectClassPointer->Is_Client_Dirty(clientId);
	}

	bool NetworkObjectClass::GetObjectDirtyBit2(int clientId, DirtyBit dirtyBit)
	{
		if (clientId < 0 || clientId >= INetworkObjectClass::MaxClientCount)
		{
			throw gcnew ArgumentOutOfRangeException("clientId");
		}

		return InternalNetworkObjectClassPointer->Get_Object_Dirty_Bit_2(clientId, static_cast<::NetworkObjectClass::DIRTY_BIT>(dirtyBit));
	}

	BYTE NetworkObjectClass::GetObjectDirtyBits2(int clientId)
	{
		if (clientId < 0 || clientId >= INetworkObjectClass::MaxClientCount)
		{
			throw gcnew ArgumentOutOfRangeException("clientId");
		}

		return InternalNetworkObjectClassPointer->Get_Object_Dirty_Bits_2(clientId);
	}

	bool NetworkObjectClass::GetWorldPosition([Out] Vector3 %pos)
	{
		::Vector3 tmp;
		if (InternalNetworkObjectClassPointer->Get_World_Position(tmp))
		{
			pos = Vector3(IntPtr(&tmp));

			return true;
		}
		else
		{
			pos = Vector3();

			return false;
		}
	}

	BYTE NetworkObjectClass::GetClientHintCount2(int clientId)
	{
		if (clientId < 0 || clientId >= INetworkObjectClass::MaxClientCount)
		{
			throw gcnew ArgumentOutOfRangeException("clientId");
		}

		return InternalNetworkObjectClassPointer->Get_Client_Hint_Count_2(clientId);
	}

	void NetworkObjectClass::ResetImportStateCount()
	{
		InternalNetworkObjectClassPointer->Reset_Import_State_Count();
	}

	void NetworkObjectClass::IncrementImportStateCount()
	{
		InternalNetworkObjectClassPointer->Increment_Import_State_Count();
	}

	void NetworkObjectClass::SetCachedPriority2(int clientId, float priority)
	{
		if (clientId < 0 || clientId >= INetworkObjectClass::MaxClientCount)
		{
			throw gcnew ArgumentOutOfRangeException("clientId");
		}

		InternalNetworkObjectClassPointer->Set_Cached_Priority_2(clientId, priority);
	}

	float NetworkObjectClass::GetCachedPriority2(int clientId)
	{
		if (clientId < 0 || clientId >= INetworkObjectClass::MaxClientCount)
		{
			throw gcnew ArgumentOutOfRangeException("clientId");
		}

		return InternalNetworkObjectClassPointer->Get_Cached_Priority_2(clientId);
	}

	IntPtr NetworkObjectClass::NetworkObjectClassPointer::get()
	{
		return IntPtr(InternalNetworkObjectClassPointer);
	}

	int NetworkObjectClass::NetworkId::get()
	{
		return InternalNetworkObjectClassPointer->Get_Network_ID();
	}

	uint32 NetworkObjectClass::NetworkClassId::get()
	{
		return InternalNetworkObjectClassPointer->Get_Network_Class_ID();
	}

	bool NetworkObjectClass::IsDeletePending::get()
	{
		return InternalNetworkObjectClassPointer->Is_Delete_Pending();
	}

	void NetworkObjectClass::IsDeletePending::set(bool value)
	{
		InternalNetworkObjectClassPointer->Set_Is_Delete_Pending(value);
	}

	BYTE NetworkObjectClass::AppPacketType::get()
	{
		return InternalNetworkObjectClassPointer->Get_App_Packet_Type();
	}

	void NetworkObjectClass::AppPacketType::set(BYTE value)
	{
		InternalNetworkObjectClassPointer->Set_App_Packet_Type(value);
	}

	int NetworkObjectClass::VisId::get()
	{
		return InternalNetworkObjectClassPointer->Get_Vis_ID();
	}

	float NetworkObjectClass::FilterDistance::get()
	{
		return InternalNetworkObjectClassPointer->Get_Filter_Distance();
	}

	int NetworkObjectClass::ImportStateCount::get()
	{
		return InternalNetworkObjectClassPointer->Get_Import_State_Count();
	}

	ULONG NetworkObjectClass::LastClientsideUpdateTime::get()
	{
		return InternalNetworkObjectClassPointer->Get_Last_Clientside_Update_Time();
	}

	unsigned char NetworkObjectClass::FrequentUpdateExportSize::get()
	{
		return InternalNetworkObjectClassPointer->Get_Frequent_Update_Export_Size();
	}

	void NetworkObjectClass::FrequentUpdateExportSize::set(unsigned char value)
	{
		InternalNetworkObjectClassPointer->Set_Frequent_Update_Export_Size(value);
	}

	bool NetworkObjectClass::IsTagged::get()
	{
		return InternalNetworkObjectClassPointer->Is_Tagged();
	}

	String ^NetworkObjectClass::Description::get()
	{
		::StringClass tmp;
		InternalNetworkObjectClassPointer->Get_Description(tmp);

		return gcnew String(tmp.Peek_Buffer());
	}

	bool NetworkObjectClass::UnreliableOverride::get()
	{
		return InternalNetworkObjectClassPointer->Get_Unreliable_Override();
	}

	void NetworkObjectClass::UnreliableOverride::set(bool value)
	{
		InternalNetworkObjectClassPointer->Set_Unreliable_Override(value);
	}

	float NetworkObjectClass::CachedPriority::get()
	{
		return InternalNetworkObjectClassPointer->Get_Cached_Priority();
	}

	int NetworkObjectClass::LastObjectIdIDamaged::get()
	{
		return InternalNetworkObjectClassPointer->Get_Last_Object_Id_I_Damaged();
	}

	void NetworkObjectClass::LastObjectIdIDamaged::set(int value)
	{
		InternalNetworkObjectClassPointer->Set_Last_Object_Id_I_Damaged(value);
	}

	int NetworkObjectClass::LastObjectIdIGotDamagedBy::get()
	{
		return InternalNetworkObjectClassPointer->Get_Last_Object_Id_I_Got_Damaged_By();
	}

	void NetworkObjectClass::LastObjectIdIGotDamagedBy::set(int value)
	{
		InternalNetworkObjectClassPointer->Set_Last_Object_Id_I_Got_Damaged_By(value);
	}

	ULONG NetworkObjectClass::LastHintRequestTime::get()
	{
		return InternalNetworkObjectClassPointer->getLastHintRequestTime();
	}

	void NetworkObjectClass::LastHintRequestTime::set(ULONG value)
	{
		InternalNetworkObjectClassPointer->setLastHintRequestTime(value);
	}

	bool NetworkObjectClass::InternalDestroyPointer()
	{
		Imports::DestroyNetworkObjectClass(InternalNetworkObjectClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::NetworkObjectClass *NetworkObjectClass::InternalNetworkObjectClassPointer::get()
	{
		return reinterpret_cast<::NetworkObjectClass *>(Pointer.ToPointer());
	}
}