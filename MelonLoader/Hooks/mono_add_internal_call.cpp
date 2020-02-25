#include "Hooks.h"
#include "../MelonLoader.h"
#include "../detours/detours.h"
#include "../Console.h"
#include "../PointerUtils.h"

mono_add_internal_call_t Hook_mono_add_internal_call::Original_mono_add_internal_call = NULL;

void Hook_mono_add_internal_call::Hook()
{
	if (Original_mono_add_internal_call == NULL)
	{
		Original_mono_add_internal_call = Mono::mono_add_internal_call;
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(&(LPVOID&)Original_mono_add_internal_call, Hooked_mono_add_internal_call);
		DetourTransactionCommit();
	}
}

void Hook_mono_add_internal_call::Unhook()
{
	if (Original_mono_add_internal_call != NULL)
	{
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourDetach(&(LPVOID&)Original_mono_add_internal_call, Hooked_mono_add_internal_call);
		DetourTransactionCommit();
		Original_mono_add_internal_call = NULL;
	}
}

void Hook_mono_add_internal_call::Hooked_mono_add_internal_call(const char* name, void* method)
{
	if (MelonLoader::MupotMode)
	{
		Original_mono_add_internal_call(name, method);
		Hook_il2cpp_add_internal_call::Original_il2cpp_add_internal_call(name, method);
	}
}