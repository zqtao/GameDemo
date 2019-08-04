#include "File.h"
#include "FileHandle.h"
#include <sstream>

using namespace std;

const unsigned int LINE_SIZE = 1024;


void File::LoadOBJ(const string name, Mesh& mesh, vector<unsigned short>& indices)
{
    char* data = GetAssetData(name);
    LoadData(data, mesh, indices);
    free(data);
}

char* File::GetFileContent(const string name)
{
    return GetAssetData(name);
}

char* File::GetAssetData(const string name)
{
    FileHandle* handle = FileHandle::OpenFile(name);
    int fileLength = handle->GetSize();

    char* data = (char*)malloc((size_t)fileLength);
    memset(data, 0, (size_t)fileLength);

    handle->Read(data, (size_t)fileLength);

	delete handle;

    return data;
}

void File::LoadData(const char*data, Mesh& mesh, vector<unsigned short>& indices)
{
    istringstream stream;
    stream.str(data);

    char line[LINE_SIZE];
    vector<Vertex> tmpVertex;
    vector<UV> tmpUV;
    vector<Normal> tmpNormal;
    vector<unsigned int> vertexIndices;
    vector<unsigned int> uvIndices;
    vector<unsigned int> normalIndices;

    istringstream iss;

    while(stream.getline(line, LINE_SIZE))
	{
        string s;
        iss.str(line);
        iss >> s;
        if (s.compare("v") == 0)
		{
            Vertex vertex;
            iss >> vertex.x >> vertex.y >> vertex.z;
            tmpVertex.push_back(vertex);
        }
		else if (s.compare("vt") == 0)
		{
            UV uv;
            iss >> uv.x >> uv.y;
            tmpUV.push_back(uv);
        }
		else if (s.compare("vn") == 0)
		{
            Normal normal;
            iss >> normal.x >> normal.y >> normal.z;
            tmpNormal.push_back(normal);
        }
		else if (s.compare("f") == 0)
		{
            char c;
            unsigned int vertexIndex[3];
            unsigned int uvIndex[3];
            unsigned int normalIndex[3];
            iss >> vertexIndex[0] >> c >> uvIndex[0] >> c >> normalIndex[0]
                >> vertexIndex[1] >> c >> uvIndex[1] >> c >> normalIndex[1]
                >> vertexIndex[2] >> c >> uvIndex[2] >> c >> normalIndex[2];

            vertexIndices.push_back(vertexIndex[0]);
            vertexIndices.push_back(vertexIndex[1]);
            vertexIndices.push_back(vertexIndex[2]);

            uvIndices.push_back(uvIndex[0]);
            uvIndices.push_back(uvIndex[1]);
            uvIndices.push_back(uvIndex[2]);

            normalIndices.push_back(normalIndex[0]);
            normalIndices.push_back(normalIndex[1]);
            normalIndices.push_back(normalIndex[2]);
        }
    }

    map<Point, unsigned short> dataCache;
    Point point;
    unsigned short result;
    for (unsigned int i = 0; i < vertexIndices.size(); ++i)
	{
        unsigned int vertexIndex = vertexIndices[i];
        unsigned int uvIndex = uvIndices[i];
        unsigned int normalIndex = normalIndices[i];

        point.vertex = tmpVertex[vertexIndex];
        point.uv = tmpUV[uvIndex];
        point.normal = tmpNormal[normalIndex];
        if (FilterData(dataCache, point, result))
		{
            indices.push_back(result);
        }
		else
		{
            indices.push_back((unsigned short)mesh.vertex.size());
            dataCache[point] = mesh.vertex.size();
            mesh.vertex.push_back(tmpVertex[vertexIndex]);
            mesh.uv.push_back(tmpUV[uvIndex]);
            mesh.normal.push_back(tmpNormal[normalIndex]);
        }
    }
}

bool File::FilterData(map<Point, unsigned short>& dataCache, Point& point, unsigned short& result)
{
    auto it = dataCache.find(point);
    if (it == dataCache.end())
	{
        return false;
    }
	else
	{
        result = it->second;
        return true;
    }
}

char* File::GetTGAContent(const string name, int& width, int& height)
{
	char* buffer = nullptr;
	tga_header header;

    FileHandle* handle = FileHandle::OpenFile(name);
    handle->Read((char*)&header, sizeof(tga_header));
	width = header.Width;
	height = header.Height;

	if (header.ColorDepth == 8 || header.ColorDepth == 24 || header.ColorDepth == 32)
	{
		int bytesToRead = sizeof(char) * width * height * header.ColorDepth / 8;
		buffer = (char*)malloc(bytesToRead);
		if (buffer)
		{
			handle->Read(buffer, bytesToRead);
		}
	}
	delete handle;

	return buffer;
}

