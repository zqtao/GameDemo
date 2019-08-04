#ifndef GAMEDEMO_DATAOBJECT_H
#define GAMEDEMO_DATAOBJECT_H

#include "Vertex.h"
#include "Matrix.h"
#include <string>

using namespace std;

class DataObject {
public:
    DataObject();
    DataObject(const string& filename, const string& vertex, const string& fragment, const string& texture);
    virtual ~DataObject();

    void SetMeshAsset(const string& filename);
    void SetShader(const string& vertex, const string& fragment);
    void SetTexture(const string& texture);
    const string& GetVertexShader();
    const string& GetFragmentShader();
    const string& GetTexture();
    const Mesh* GetMesh();
    const vector<unsigned short>& GetIndices();

    void Scale(float x, float y, float z);
    void Rotate(float angle, float x, float y, float z);
    void Translate(float x, float y, float z);

private:
    void LoadAsset();

private:
    string m_strAsset;
    string m_strVertex;
    string m_strFragment;
    string m_strTexture;

    Mesh m_oMesh;
    vector<unsigned short> m_oIndices;

    Matrix m_oModel;
};

#endif //GAMEDEMO_DATAOBJECT_H
