#ifndef GAMEDEMO_FILE_HANDLE_H
#define GAMEDEMO_FILE_HANDLE_H

#include <string>

using namespace std;

extern void* g_handle;
extern void SetSystemFileHandle(void *handle);

class FileHandle {
public:
	static FileHandle* OpenFile(string name);

    FileHandle(const string name) : m_strFilename(name)
		{ Open(); }
    virtual ~FileHandle() { Close(); }

    virtual int Read(char* buffer, unsigned int size) = 0;
    virtual int Write(const char* buffer, unsigned int size) = 0;
	virtual int GetSize() = 0;

protected:
	virtual void Open() {};
    virtual void Close() {};

protected:
	string m_strFilename;
};



#endif //GAMEDEMO_FILE_HANDLE_H
