#pragma once

#ifdef TESTDLLMAIN_EXPORTS
#define TestDLLMainAPI  __declspec(dllexport)
#else
#define TestDLLMainAPI __declspec(dllimport)
#endif // TESTDLLMAIN_EXPORTS

TestDLLMainAPI void SayHello();
