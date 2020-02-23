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

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <NetworkObjectClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "IUnmanagedObject.h"
#include "AbstractUnmanagedObject.h"
#include "MVector3.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace RenSharp
{
	[Flags]
	public enum class DirtyBit : BYTE
	{
		BitMaskFrequent = ::NetworkObjectClass::BIT_MASK_FREQUENT,
		BitMaskOccasional = ::NetworkObjectClass::BIT_MASK_OCCASIONAL,
		BitMaskRare = ::NetworkObjectClass::BIT_MASK_RARE,
		BitMaskCreation = ::NetworkObjectClass::BIT_MASK_CREATION,
		BitFrequent = ::NetworkObjectClass::BIT_FREQUENT,
		BitOccasional = ::NetworkObjectClass::BIT_OCCASIONAL,
		BitRare = ::NetworkObjectClass::BIT_RARE,
		BitCreation = ::NetworkObjectClass::BIT_CREATION,
		BitSuppressUpdates = ::NetworkObjectClass::BIT_SUPPRESS_UPDATES
	};

	public interface class INetworkObjectClass : public IUnmanagedObject
	{
		literal int MaxClientCount = 128;

		void ImportCreation(IntPtr packet);

		void ImportRare(IntPtr packet);

		void ImportOccasional(IntPtr packet);

		void ImportFrequent(IntPtr packet);

		void ExportCreation(IntPtr packet);

		void ExportRare(IntPtr packet);

		void ExportOccasional(IntPtr packet);

		void ExportFrequent(IntPtr packet);

		void NetworkThink();

		void SetDeletePending();

		void Delete();

		void SetObjectDirtyBit(DirtyBit dirtyBit, bool onOff);

		void SetObjectDirtyBit(int clientId, DirtyBit dirtyBit, bool onOff);

		void ClearObjectDirtyBits();

		bool GetObjectDirtyBit(int clientId, DirtyBit dirtyBit);

		BYTE GetObjectDirtyBits(int clientId);

		void SetObjectDirtyBits(int clientId, BYTE bits);

		bool IsClientDirty(int clientId);

		bool GetObjectDirtyBit2(int clientId, DirtyBit dirtyBit);

		BYTE GetObjectDirtyBits2(int clientId);

		bool GetWorldPosition([Out] Vector3 %pos);

		BYTE GetClientHintCount2(int clientId);

		void ResetImportStateCount();

		void IncrementImportStateCount();

		void SetCachedPriority2(int clientId, float priority);

		float GetCachedPriority2(int clientId);

		property IntPtr NetworkObjectClassPointer
		{
			IntPtr get();
		}

		property int NetworkId
		{
			int get();
		}

		property uint32 NetworkClassId
		{
			uint32 get();
		}

		property bool IsDeletePending
		{
			bool get();
			void set(bool value);
		}

		property BYTE AppPacketType
		{
			BYTE get();
			void set(BYTE value);
		}

		property int VisId
		{
			int get();
		}

		property float FilterDistance
		{
			float get();
		}

		property int ImportStateCount
		{
			int get();
		}

		property ULONG LastClientsideUpdateTime
		{
			ULONG get();
		}

		property unsigned char FrequentUpdateExportSize
		{
			unsigned char get();
			void set(unsigned char value);
		}

		property bool IsTagged
		{
			bool get();
		}

		property String ^Description
		{
			String ^get();
		}

		property bool UnreliableOverride
		{
			bool get();
			void set(bool value);
		}

		property float CachedPriority
		{
			float get();
		}

		property int LastObjectIdIDamaged
		{
			int get();
			void set(int value);
		}

		property int LastObjectIdIGotDamagedBy
		{
			int get();
			void set(int value);
		}

		property ULONG LastHintRequestTime
		{
			ULONG get();
			void set(ULONG value);
		}
	};

	public ref class NetworkObjectClass : public AbstractUnmanagedObject, public INetworkObjectClass
	{
		public:
			NetworkObjectClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual void ImportCreation(IntPtr packet) sealed;
			virtual void ImportRare(IntPtr packet) sealed;
			virtual void ImportOccasional(IntPtr packet) sealed;
			virtual void ImportFrequent(IntPtr packet) sealed;
			virtual void ExportCreation(IntPtr packet) sealed;
			virtual void ExportRare(IntPtr packet) sealed;
			virtual void ExportOccasional(IntPtr packet) sealed;
			virtual void ExportFrequent(IntPtr packet) sealed;
			virtual void NetworkThink() sealed;
			virtual void SetDeletePending() sealed;
			virtual void Delete() sealed;
			virtual void SetObjectDirtyBit(DirtyBit dirtyBit, bool onOff) sealed;
			virtual void SetObjectDirtyBit(int clientId, DirtyBit dirtyBit, bool onOff) sealed;
			virtual void ClearObjectDirtyBits() sealed;
			virtual bool GetObjectDirtyBit(int clientId, DirtyBit dirtyBit) sealed;
			virtual BYTE GetObjectDirtyBits(int clientId) sealed;
			virtual void SetObjectDirtyBits(int clientId, BYTE bits) sealed;
			virtual bool IsClientDirty(int clientId) sealed;
			virtual bool GetObjectDirtyBit2(int clientId, DirtyBit dirtyBit) sealed;
			virtual BYTE GetObjectDirtyBits2(int clientId) sealed;
			virtual bool GetWorldPosition([Out] Vector3 %pos) sealed;
			virtual BYTE GetClientHintCount2(int clientId) sealed;
			virtual void ResetImportStateCount() sealed;
			virtual void IncrementImportStateCount() sealed;
			virtual void SetCachedPriority2(int clientId, float priority) sealed;
			virtual float GetCachedPriority2(int clientId) sealed;

			property IntPtr NetworkObjectClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int NetworkId
			{
				virtual int get() sealed;
			}

			property uint32 NetworkClassId
			{
				virtual uint32 get() sealed;
			}

			property bool IsDeletePending
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property BYTE AppPacketType
			{
				virtual BYTE get() sealed;
				virtual void set(BYTE value) sealed;
			}

			property int VisId
			{
				virtual int get() sealed;
			}

			property float FilterDistance
			{
				virtual float get() sealed;
			}

			property int ImportStateCount
			{
				virtual int get() sealed;
			}

			property ULONG LastClientsideUpdateTime
			{
				virtual ULONG get() sealed;
			}

			property unsigned char FrequentUpdateExportSize
			{
				virtual unsigned char get() sealed;
				virtual void set(unsigned char value) sealed;
			}

			property bool IsTagged
			{
				virtual bool get() sealed;
			}

			property String ^Description
			{
				virtual String ^get() sealed;
			}

			property bool UnreliableOverride
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property float CachedPriority
			{
				virtual float get() sealed;
			}

			property int LastObjectIdIDamaged
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int LastObjectIdIGotDamagedBy
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property ULONG LastHintRequestTime
			{
				virtual ULONG get() sealed;
				virtual void set(ULONG value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::NetworkObjectClass *InternalNetworkObjectClassPointer
			{
				virtual ::NetworkObjectClass *get();
			}
	};
}