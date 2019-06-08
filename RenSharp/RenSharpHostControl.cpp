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

#include "General.h"
#include "RenSharpHostControl.h"

RenSharpHostControl::RenSharpHostControl()
	: refCount(0), defaultDomainManager(nullptr)
{
}

RenSharpHostControl::~RenSharpHostControl()
{
	if (defaultDomainManager != nullptr)
	{
		defaultDomainManager->Release();
		defaultDomainManager = nullptr;
	}
}

HRESULT RenSharpHostControl::GetHostManager(REFIID id, void **ppHostManager)
{
	*ppHostManager = nullptr;

	return E_NOINTERFACE;
}

HRESULT RenSharpHostControl::SetAppDomainManager(DWORD dwAppDomainID, IUnknown *pUnkAppDomainManager)
{
	HRESULT hr = pUnkAppDomainManager->QueryInterface(__uuidof(RenSharpInterface), reinterpret_cast<PVOID *>(&defaultDomainManager));

	return hr;
}

RenSharpInterface *RenSharpHostControl::GetRenSharpInterface()
{
	if (defaultDomainManager != nullptr)
	{
		defaultDomainManager->AddRef();
	}

	return defaultDomainManager;
}

HRESULT RenSharpHostControl::QueryInterface(const IID &iid, void **ppv)
{
	if (ppv == nullptr)
	{
		return E_POINTER;
	}

	*ppv = this;

	AddRef();

	return S_OK;
}

ULONG RenSharpHostControl::AddRef()
{
	return InterlockedIncrement(&refCount);
}

ULONG RenSharpHostControl::Release()
{
	if (InterlockedDecrement(&refCount) == 0)
	{
		delete this;

		return 0;
	}

	return refCount;
}