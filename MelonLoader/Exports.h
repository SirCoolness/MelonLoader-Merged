#pragma once
#include "Il2Cpp.h"

extern "C"
{
	__declspec(dllexport) Il2CppDomain* __stdcall melonloader_get_il2cpp_domain();
	__declspec(dllexport) bool __stdcall melonloader_is_il2cpp_game();
	__declspec(dllexport) bool __stdcall melonloader_is_debug_mode();
	__declspec(dllexport) const char* __stdcall melonloader_get_game_directory();
	__declspec(dllexport) void __stdcall melonloader_console_writeline(const char* txt);
}