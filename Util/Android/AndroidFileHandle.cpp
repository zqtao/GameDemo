#include "AndroidFileHandle.h"

AndroidFileHandle::AndroidFileHandle(string name) :
	FileHandle(name)
{
}

AndroidFileHandle::~AndroidFileHandle()
{
}

void AndroidFileHandle::Open()
{
	m_pAasset = AAssetManager_open(static_cast<AAssetManager*>(g_handle), m_strFilename.c_str(), AASSET_MODE_BUFFER);
}

void AndroidFileHandle::Close()
{
	AAsset_close(m_pAasset);
}

int AndroidFileHandle::GetSize()
{
	if (m_pAasset == nullptr)
		return 0;

	off64_t fileLength = AAsset_getLength64(m_pAasset);

	return fileLength;
}


int AndroidFileHandle::Read(char* buffer, unsigned int size)
{
    return AAsset_read(m_pAasset, buffer, (size_t)size);
}

int AndroidFileHandle::Write(const char* buffer, unsigned int size)
{
	//TODO: android aasset doesn't support wirte
    return 0;
}



