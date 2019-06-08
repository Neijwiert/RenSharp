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
#include "IUnmanagedContainer.h"
#include "Mengine_vector.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_crate.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	interface class IDACrateModifierClass;
	interface class IcPlayer;
	interface class IDACrateClass;
	interface class IRenSharpCrateModifierClass;
	interface class IRenSharpCrateModifierFactoryClass;
	interface class IRenSharpCrateFactoryClass;
	interface class IRenSharpCrateClass;

#pragma managed(push, off)

	class DACrateModifierClassHelper : public ::DACrateModifierClass
	{
		private:
			DACrateModifierClassHelper() = default;

		public:
			float& GetValue()
			{
				return Value;
			}

			::DACrateModifierOperator::Operator& GetOperator()
			{
				return Operator;
			}
	};

	class DACrateFactoryClassHelper : public ::DACrateFactoryClass
	{
		private:
			DACrateFactoryClassHelper(const char* name, ::DACrateType::Type type)
				: ::DACrateFactoryClass(name, type)
			{

			}

		public:
			::StringClass& GetSection()
			{
				return Section;
			}

			::DACrateType::Type& GetType()
			{
				return Type;
			}

			::DACrateClass*& GetInstance()
			{
				return Instance;
			}
	};

	class DACrateClassHelper : public ::DACrateClass
	{
		private:
			DACrateClassHelper() = default;

		public:
			bool& GetCapOdds()
			{
				return CapOdds;
			}

			float& GetBaseOdds()
			{
				return BaseOdds;
			}

			float& GetModifiedOdds()
			{
				return ModifiedOdds;
			}

			float& GetFinalOdds()
			{
				return FinalOdds;
			}

			::DACrateType::Type& GetType()
			{
				return Type;
			}

			::DynamicVectorClass<::DACrateModifierClass*>& GetModifiers()
			{
				return Modifiers;
			}
	};

#pragma managed(pop)

	public enum class DACrateModifierOperator : int
	{
		None = ::DACrateModifierOperator::Operator::NONE,
		Add = ::DACrateModifierOperator::ADD,
		Substract = ::DACrateModifierOperator::SUBTRACT,
		Multiply = ::DACrateModifierOperator::MULTIPLY,
		Divide = ::DACrateModifierOperator::DIVIDE
	};

	public interface class IDACrateModifierFactoryClass : public IUnmanagedObject
	{
		IUnmanagedContainer<IDACrateModifierClass^>^ Create(String^ parameters);

		IRenSharpCrateModifierFactoryClass^ AsManagedCrateModifierFactory();

		property IntPtr DACrateModifierFactoryClassPointer
		{
			IntPtr get();
		}

		property String^ Name
		{
			String^ get();
		}

		property bool IsManagedCrateModifierFactory
		{
			bool get();
		}
	};

	public ref class DACrateModifierFactoryClass : public AbstractUnmanagedObject, public IDACrateModifierFactoryClass
	{
		public:
			DACrateModifierFactoryClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual IUnmanagedContainer<IDACrateModifierClass^>^ Create(String^ parameters) sealed;
			virtual IRenSharpCrateModifierFactoryClass^ AsManagedCrateModifierFactory() sealed;

			property IntPtr DACrateModifierFactoryClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String^ Name
			{
				virtual String^ get() sealed;
			}

			property bool IsManagedCrateModifierFactory
			{
				virtual bool get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DACrateModifierFactoryClass* InternalDACrateModifierFactoryClassPointer
			{
				virtual ::DACrateModifierFactoryClass* get();
			}
	};

	public interface class IDACrateModifierClass : public IUnmanagedObject
	{
		void Init(String^ parameters);

		void CalculateOdds(float %odds, IcPlayer^ player);

		void ApplyModifier(float %odds);

		IRenSharpCrateModifierClass^ AsManagedCrateModifier();

		property IntPtr DACrateModifierClassPointer
		{
			IntPtr get();
		}

		property bool IsMultiplicative
		{
			bool get();
		}

		property bool IsPositive
		{
			bool get();
		}

		property IDACrateModifierFactoryClass^ Factory
		{
			IDACrateModifierFactoryClass^ get();
			void set(IDACrateModifierFactoryClass^ value);
		}

		property String^ Name
		{
			String^ get();
		}

		property bool IsManagedCrateModifier
		{
			bool get();
		}
	};

	public ref class DACrateModifierClass : public AbstractUnmanagedObject, public IDACrateModifierClass
	{
		public:
			DACrateModifierClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void Init(String^ parameters) sealed;
			virtual void CalculateOdds(float% odds, IcPlayer^ player) sealed;
			virtual void ApplyModifier(float% odds) sealed;
			virtual IRenSharpCrateModifierClass^ AsManagedCrateModifier() sealed;

			property IntPtr DACrateModifierClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsMultiplicative
			{
				virtual bool get() sealed;
			}

			property bool IsPositive
			{
				virtual bool get() sealed;
			}

			property IDACrateModifierFactoryClass^ Factory
			{
				virtual IDACrateModifierFactoryClass^ get() sealed;
				virtual void set(IDACrateModifierFactoryClass^ value) sealed;
			}

			property String^ Name
			{
				virtual String^ get() sealed;
			}

			property bool IsManagedCrateModifier
			{
				virtual bool get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DACrateModifierClass* InternalDACrateModifierClassPointer
			{
				virtual ::DACrateModifierClass* get();
			}

			property float Value
			{
				float get();
				void set(float value);
			}

			property RenSharp::DACrateModifierOperator Operator
			{
				RenSharp::DACrateModifierOperator get();
				void set(RenSharp::DACrateModifierOperator value);
			}
	};

	[Flags]
	public enum class DACrateType : int
	{
		Infantry = ::DACrateType::INFANTRY,
		Vehicle = ::DACrateType::VEHICLE
	};

	public interface class IDACrateFactoryClass : public IUnmanagedObject
	{
		IDACrateClass^ CreateInstance();

		void DestroyInstance();

		bool CheckEnabled();

		bool CheckType(RenSharp::DACrateType type);

		bool CheckEnabledType(RenSharp::DACrateType type);

		IRenSharpCrateFactoryClass^ AsManagedCrateFactory();

		property IntPtr DACrateFactoryClassPointer
		{
			IntPtr get();
		}

		property String^ Name
		{
			String^ get();
		}

		property String^ Section
		{
			String^ get();
		}

		property RenSharp::DACrateType Type
		{
			RenSharp::DACrateType get();
		}

		property IDACrateClass^ Instance
		{
			IDACrateClass^ get();
		}

		property bool IsManagedCrateFactory
		{
			bool get();
		}
	};

	public ref class DACrateFactoryClass : public AbstractUnmanagedObject, public IDACrateFactoryClass
	{
		public:
			DACrateFactoryClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual IDACrateClass^ CreateInstance() sealed;
			virtual void DestroyInstance() sealed;
			virtual bool CheckEnabled() sealed;
			virtual bool CheckType(RenSharp::DACrateType type) sealed;
			virtual bool CheckEnabledType(RenSharp::DACrateType type) sealed;
			virtual IRenSharpCrateFactoryClass^ AsManagedCrateFactory() sealed;

			property IntPtr DACrateFactoryClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String^ Name
			{
				virtual String^ get() sealed;
			}

			property String^ Section
			{
				virtual String^ get() sealed;

				protected:
					void set(String^ value);
			}

			property RenSharp::DACrateType Type
			{
				virtual RenSharp::DACrateType get() sealed;

				protected:
					void set(RenSharp::DACrateType value);
			}

			property IDACrateClass^ Instance
			{
				virtual IDACrateClass^ get() sealed;

				protected:
					void set(IDACrateClass^ value);
			}

			property bool IsManagedCrateFactory
			{
				virtual bool get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DACrateFactoryClass* InternalDACrateFactoryClassPointer
			{
				virtual ::DACrateFactoryClass* get();
			}
	};

	public interface class IDACrateClass : public IUnmanagedObject
	{
		void Init();

		void SettingsLoaded();

		void CalculateOdds(IcPlayer^ player);

		bool CanActivate(IcPlayer^ player);

		void Activate(IcPlayer^ player);

		bool CheckType(IcPlayer^ player);

		bool CheckType(RenSharp::DACrateType type);

		void AdjustOdds(float odds);

		IRenSharpCrateClass^ AsManagedCrate();

		property IntPtr DACrateClassPointer
		{
			IntPtr get();
		}

		property bool CapOdds
		{
			bool get();
		}

		property float BaseOdds
		{
			float get();
		}

		property float ModifiedOdds
		{
			float get();
		}

		property float FinalOdds
		{
			float get();
		}

		property IDACrateFactoryClass^ Factory
		{
			IDACrateFactoryClass^ get();
			void set(IDACrateFactoryClass^ value);
		}

		property String^ Name
		{
			String^ get();
		}

		property String^ Section
		{
			String^ get();
		}

		property RenSharp::DACrateType Type
		{
			RenSharp::DACrateType get();
		}

		property bool IsManagedCrate
		{
			bool get();
		}
	};

	public ref class DACrateClass : public AbstractUnmanagedObject, public IDACrateClass
	{
		public:
			DACrateClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void Init() sealed;
			virtual void SettingsLoaded() sealed;
			virtual void CalculateOdds(IcPlayer^ player) sealed;
			virtual bool CanActivate(IcPlayer^ player) sealed;
			virtual void Activate(IcPlayer^ player) sealed;
			virtual bool CheckType(IcPlayer^ player) sealed;
			virtual bool CheckType(RenSharp::DACrateType type) sealed;
			virtual void AdjustOdds(float odds) sealed;
			virtual IRenSharpCrateClass^ AsManagedCrate() sealed;

			property IntPtr DACrateClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool CapOdds
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property float BaseOdds
			{
				virtual float get() sealed;

				protected:
					void set(float value);
			}

			property float ModifiedOdds
			{
				virtual float get() sealed;

				protected:
					void set(float value);
			}

			property float FinalOdds
			{
				virtual float get() sealed;

				protected:
					void set(float value);
			}

			property IDACrateFactoryClass^ Factory
			{
				virtual IDACrateFactoryClass^ get() sealed;
				virtual void set(IDACrateFactoryClass^ value) sealed;
			}

			property String^ Name
			{
				virtual String^ get() sealed;
			}

			property String^ Section
			{
				virtual String^ get() sealed;
			}

			property RenSharp::DACrateType Type
			{
				virtual RenSharp::DACrateType get() sealed;

				protected:
					void set(RenSharp::DACrateType value);
			}

			property bool IsManagedCrate
			{
				virtual bool get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DACrateClass* InternalDACrateClassPointer
			{
				virtual ::DACrateClass* get();
			}

			property IDynamicVectorClass<IDACrateModifierClass^>^ Modifiers
			{
				IDynamicVectorClass<IDACrateModifierClass^>^ get();
				void set(IDynamicVectorClass<IDACrateModifierClass^>^ value);
			}
	};
}