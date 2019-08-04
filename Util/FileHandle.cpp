#include "FileHandle.h"
#ifdef ANDROID_OS
#include "AndroidFileHandle.h"
#endif

void* g_handle = nullptr;
void SetSystemFileHandle(void *handle)
{
	g_handle = handle;
}


FileHandle* FileHandle::OpenFile(string name)
{
#ifdef ANDROID_OS
	return new AndroidFileHandle(name);
#elif LINUX_OS

#endif
}


