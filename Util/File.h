#ifndef GAMEDEMO_FILE_H
#define GAMEDEMO_FILE_H

#include "Vertex.h"
#include <string>
#include <map>

using namespace std;

typedef struct tga_header {
   unsigned char IdSize;
   unsigned char MapType;
   unsigned char ImageType;
   unsigned short PaletteStart;
   unsigned short PaletteSize;
   unsigned char PaletteEntryDepth;
   unsigned short X;
   unsigned short Y;
   unsigned short Width;
   unsigned short Height;
   unsigned char ColorDepth;
   unsigned char Descriptor;
} TGA_HEADER;


class File {
public:
    static void LoadOBJ(const string name, Mesh& mesh, vector<unsigned short>& indices);
    static char* GetFileContent(const string name);
	static char* GetTGAContent(const string name, int& width, int& height);

private:
	File() = delete;
    virtual ~File() {};

	static char* GetAssetData(const string name);
    static void LoadData(const char*data, Mesh& mesh, vector<unsigned short>& indices);
    static bool FilterData(map<Point, unsigned short>& dataCache, Point& point, unsigned short& result);
};


#endif //GAMEDEMO_FILE_H
