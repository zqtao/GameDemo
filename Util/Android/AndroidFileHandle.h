#ifndef GAMEDEMO_ANDROID_FILE_HANDLE_H
#define GAMEDEMO_ANDROID_FILE_HANDLE_H

#include "FileHandle.h"

#include <string>
#include <android/asset_manager.h>

using namespace std;

class AndroidFileHandle : public FileHandle {
public:
    AndroidFileHandle(string name);
    virtual ~AndroidFileHandle();

    virtual int Read(char* buffer, unsigned int size);
    virtual int Write(const char* buffer, unsigned int size);
	virtual int GetSize();

protected:
	virtual void Open();
    virtual void Close();

private:
	AAsset* m_pAasset;
};

#endif //GAMEDEMO_ANDROID_FILE_HANDLE_H
