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

#include "MVector3.h"
#include "IUnmanagedObject.h"
#include "IUnmanagedContainer.h"
#include "AbstractUnmanagedObject.h"

#pragma managed(push, off)

class DASettingsClass;

#pragma managed(pop)

using namespace System;

namespace RenSharp
{
	interface class IINISection;
	interface class IINIClass;

	public interface class IDASettingsClass : public IUnmanagedObject
	{
		void Reload();

		void ReloadSilent();

		int GetInt(String ^entry, int defaultValue);

		int GetInt(String ^section, String ^entry, int defaultValue);

		int GetInt(String ^section1, String ^section2, String ^entry, int defaultValue);

		float GetFloat(String ^entry, float defaultValue);

		float GetFloat(String ^section, String ^entry, float defaultValue);

		float GetFloat(String ^section1, String ^section2, String ^entry, float defaultValue);

		bool GetBool(String ^entry, bool defaultValue);

		bool GetBool(String ^section, String ^entry, bool defaultValue);

		bool GetBool(String ^section1, String ^section2, String ^entry, bool defaultValue);

		String ^GetString(String ^entry, String ^defaultValue);

		String ^GetString(String ^section, String ^entry, String ^defaultValue);

		String ^GetString(String ^section1, String ^section2, String ^entry, String ^defaultValue);

		Vector3 GetVector3(String ^entry, Vector3 defaultValue);

		Vector3 GetVector3(String ^section, String ^entry, Vector3 defaultValue);

		Vector3 GetVector3(String ^section1, String ^section2, String ^entry, Vector3 defaultValue);

		IINISection ^GetSection(String ^section);

		property IntPtr DASettingsClassPointer
		{
			IntPtr get();
		}

		property IINIClass ^INI
		{
			IINIClass ^get();
		}

		property String ^Filename
		{
			String ^get();
		}
	};

	public ref class DASettingsClass : public AbstractUnmanagedObject, public IDASettingsClass
	{
		private:
			DASettingsClass();
			DASettingsClass(String ^filename);
			DASettingsClass(IINIClass ^ini);

		public:
			DASettingsClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			String ^ToString() override;

			static IUnmanagedContainer<IDASettingsClass ^> ^CreateDASettingsClass();
			static IUnmanagedContainer<IDASettingsClass ^> ^CreateDASettingsClass(String ^filename);
			static IUnmanagedContainer<IDASettingsClass ^> ^CreateDASettingsClass(IINIClass ^ini);

			virtual void Reload() sealed;
			virtual void ReloadSilent() sealed;
			virtual int GetInt(String ^entry, int defaultValue) sealed;
			virtual int GetInt(String ^section, String ^entry, int defaultValue) sealed;
			virtual int GetInt(String ^section1, String ^section2, String ^entry, int defaultValue) sealed;
			virtual float GetFloat(String ^entry, float defaultValue) sealed;
			virtual float GetFloat(String ^section, String ^entry, float defaultValue) sealed;
			virtual float GetFloat(String ^section1, String ^section2, String ^entry, float defaultValue) sealed;
			virtual bool GetBool(String ^entry, bool defaultValue) sealed;
			virtual bool GetBool(String ^section, String ^entry, bool defaultValue) sealed;
			virtual bool GetBool(String ^section1, String ^section2, String ^entry, bool defaultValue) sealed;
			virtual String ^GetString(String ^entry, String ^defaultValue) sealed;
			virtual String ^GetString(String ^section, String ^entry, String ^defaultValue) sealed;
			virtual String ^GetString(String ^section1, String ^section2, String ^entry, String ^defaultValue) sealed;
			virtual Vector3 GetVector3(String ^entry, Vector3 defaultValue) sealed;
			virtual Vector3 GetVector3(String ^section, String ^entry, Vector3 defaultValue) sealed;
			virtual Vector3 GetVector3(String ^section1, String ^section2, String ^entry, Vector3 defaultValue) sealed;
			virtual IINISection ^GetSection(String ^section) sealed;

			property IntPtr DASettingsClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IINIClass ^INI
			{
				virtual IINIClass ^get() sealed;
			}

			property String ^Filename
			{
				virtual String ^get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DASettingsClass *InternalDASettingsClassPointer
			{
				virtual ::DASettingsClass *get();
			}
	};

	public ref class DASettingsManager abstract sealed
	{
		public:
			static void Shutdown();
			static void Reload();
			static void ReloadSilent();
			static void AddSettings(String ^filename);
			static void RemoveSettings(String ^filename);
			static void RemoveSettings(int position);
			static IDASettingsClass ^GetSettings(String ^filename);
			static IDASettingsClass ^GetSettings(int position);
			static int GetInt(String ^entry, int defaultValue);
			static int GetInt(String ^section, String ^entry, int defaultValue);
			static int GetInt(String ^section1, String ^section2, String ^entry, int defaultValue);
			static float GetFloat(String ^entry, float defaultValue);
			static float GetFloat(String ^section, String ^entry, float defaultValue);
			static float GetFloat(String ^section1, String ^section2, String ^entry, float defaultValue);
			static bool GetBool(String ^entry, bool defaultValue);
			static bool GetBool(String ^section, String ^entry, bool defaultValue);
			static bool GetBool(String ^section1, String ^section2, String ^entry, bool defaultValue);
			static String ^GetString(String ^entry, String ^defaultValue);
			static String ^GetString(String ^section, String ^entry, String ^defaultValue);
			static String ^GetString(String ^section1, String ^section2, String ^entry, String ^defaultValue);
			static Vector3 GetVector3(String ^entry, Vector3 defaultValue);
			static Vector3 GetVector3(String ^section, String ^entry, Vector3 defaultValue);
			static Vector3 GetVector3(String ^section1, String ^section2, String ^entry, Vector3 defaultValue);
			static IINISection ^GetSection(String ^section);

			static property int SettingsCount
			{
				int get();
			}
	};
}