#include "Assertion.h"
#include "../Core.h"
#include "Console/Debug.h"
#include "Console/Logger.h"
#include "Console/Console.h"
#include <string>
#include <iostream>

bool Assertion::ShouldContinue = true;
bool Assertion::DontDie = false;

bool Assertion::ThrowInternalFailure(const char* msg)
{
	return ThrowInternalFailuref("%s", msg);
}

bool Assertion::ThrowInternalFailuref(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vThrowInternalFailuref(fmt, args);
	va_end(args);

	return false;
}

bool Assertion::vThrowInternalFailuref(const char* fmt, va_list args)
{
	// TODO: implement JNI bindings to show message box and error
	if (!ShouldContinue)
		return false;
	
	ShouldContinue = false;

	std::string timestamp = Logger::GetTimestamp();
	
	const Logger::MessagePrefix prefixes[]{
#ifndef __ANDROID__
		Logger::MessagePrefix{
			Console::Green,
			timestamp.c_str()
		},
#endif
		Logger::MessagePrefix{
			Console::Red,
			"INTERNAL FAILURE"
		},
	};
	
#ifdef _WIN32
	bool should_print_debug_info = (!Logger::LogFile.coss.is_open() || Debug::Enabled);
	
	if (should_print_debug_info)
	{
		Logger::Internal_DirectWrite(Console::Color::Red, LogLevel::Error, prefixes, sizeof(prefixes) / sizeof(prefixes[0]), msg);

		MessageBoxA(NULL, msg, "MelonLoader - INTERNAL FAILURE", MB_OK | MB_ICONERROR);
	}
	else
	{
		Console::Close();
		MessageBoxA(NULL, "Please Post your latest.log File\nto #internal-failure in the MelonLoader Discord!", "MelonLoader - INTERNAL FAILURE!", MB_OK | MB_ICONERROR);
	}
#elif defined(__ANDROID__)
	Logger::Internal_vDirectWritef(Console::Color::Red, LogLevel::Error, prefixes, sizeof(prefixes) / sizeof(prefixes[0]), fmt, args);
#endif

	return false;
}

#ifdef __ANDROID__
#include <jni.h>
extern "C" {
	jboolean Java_com_melonloader_bridge_Assertion_getShouldContinue(JNIEnv* env, jclass type) {
		return (jboolean)Assertion::ShouldContinue;
	}

	jboolean Java_com_melonloader_bridge_Assertion_getDontDie(JNIEnv* env, jclass type) {
		return (jboolean)Assertion::DontDie;
	}

	void Java_com_melonloader_bridge_Assertion_ThrowInternalFailure(JNIEnv* env, jclass type, jstring msg)
	{
		const char* cMsg = env->GetStringUTFChars(msg, nullptr);

		Assertion::ThrowInternalFailure(cMsg);

		env->ReleaseStringUTFChars(msg, cMsg);
	}
}
#endif
