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

#include "ITimerInterface.h"
#include "IUnmanagedAttachable.h"
#include "Mengine_tt.h"

#pragma managed(push, off)

class ConsoleFunctionClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IDATokenClass;

	public interface class IRenSharpConsoleFunctionClass : public ITimerInterface, public IUnmanagedAttachable<IConsoleFunctionClass^>
	{
		void Activate(String^ pArgs);

		void Activate(IDATokenClass^ args);

		property IntPtr ConsoleFunctionClassPointer
		{
			IntPtr get();
		}

		property String^ Name
		{
			String^ get();
		}

		property String^ Alias
		{
			String^ get();
		}

		property String^ Help
		{
			String^ get();
		}
	};

	public ref class RenSharpConsoleFunctionClass abstract : public IRenSharpConsoleFunctionClass
	{
		private:
			bool disposedResources;
			bool destroyPointer;
			IntPtr consoleFunctionClassPointer;
			IConsoleFunctionClass^ consoleFunctionClass;
			String ^name;
			String ^alias;
			String ^help;

		public:
			RenSharpConsoleFunctionClass(String ^name, String ^alias, String ^help);
			RenSharpConsoleFunctionClass(String ^name, String ^help);
			~RenSharpConsoleFunctionClass();
			!RenSharpConsoleFunctionClass();

			String ^ToString() override;
			bool Equals(Object ^other) override;
			int GetHashCode() override sealed;

			virtual void TimerExpired(int number, Object^ data);
			virtual void StartTimer(int number, TimeSpan duration, bool repeat, Object^ data) sealed;
			virtual void StartTimer(int number, TimeSpan duration, bool repeat) sealed;
			virtual void StartTimer(int number, TimeSpan duration) sealed;
			virtual void StartTimer(TimeSpan duration, bool repeat, System::Action<RenSharpTimerStruct^>^ action) sealed;
			virtual void StartTimer(TimeSpan duration, System::Action<RenSharpTimerStruct^>^ action) sealed;
			virtual void StopTimer(int number, Object^ data) sealed;
			virtual void StopTimer(int number) sealed;
			virtual void StopTimer(System::Action<RenSharpTimerStruct^>^ action) sealed;
			virtual bool IsTimer(int number, Object^ data) sealed;
			virtual bool IsTimer(int number) sealed;
			virtual bool IsTimer(System::Action<RenSharpTimerStruct^>^ action) sealed;
			virtual void ClearTimers() sealed;

			virtual void InitUnmanagedAttachable() sealed;
			virtual void AttachToUnmanagedObject() sealed;
			virtual void RegisterManagedObject() sealed;
			virtual void ReleasePointer() sealed;
			virtual void UnmanagedAttach();
			virtual void ManagedRegistered();
			virtual void Activate(String ^pArgs);
			virtual void Activate(IDATokenClass^ args);
			virtual IConsoleFunctionClass ^ AsUnmanagedObject() sealed;

			property Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ Timers
			{
				virtual Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ get() sealed;
			}

			property IntPtr ConsoleFunctionClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr Pointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsAttached
			{
				virtual bool get() sealed;
			}

			property bool IsRegistered
			{
				virtual bool get() sealed;
			}

			property bool DestroyPointer
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property String ^Name
			{
				virtual String ^get() sealed;

				protected:
					virtual void set(String^ value) sealed;
			}

			property String ^Alias
			{
				virtual String ^get() sealed;

				protected:
					virtual void set(String^ value) sealed;
			}

			property String ^Help
			{
				virtual String ^get() sealed;

				protected:
					virtual void set(String^ value) sealed;
			}

		protected:
			property ::ConsoleFunctionClass *InternalConsoleFunctionClassPointer
			{
				virtual ::ConsoleFunctionClass *get();
			}
	};
}