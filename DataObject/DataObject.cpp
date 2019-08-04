#include "DataObject.h"
#include "File.h"

DataObject::DataObject(const string& asset, const string& vertex, const string& fragment, const string& texture) :
	m_strAsset(asset),
	m_strVertex(vertex),
	m_strFragment(fragment),
	m_strTexture(texture),
	m_oMesh(),
	m_oIndices()
{
    MatrixLoadIdentity(&m_oModel);
}

DataObject::DataObject() :
	m_strAsset(),
	m_strVertex(),
	m_strFragment(),
	m_strTexture(),
	m_oMesh(),
	m_oIndices()
{

}

DataObject::~DataObject()
{

}

void DataObject::SetMeshAsset(const string& asset)
{
    m_strAsset = asset;
}

void DataObject::SetShader(const string& vertex, const string& fragment)
{
    m_strVertex = vertex;
    m_strFragment = fragment;
}

const string& DataObject::GetVertexShader()
{
	return m_strVertex;
}

const string& DataObject::GetFragmentShader()
{
	return m_strFragment;
}

const string& DataObject::GetTexture()
{
	return m_strTexture;
}

const Mesh* DataObject::GetMesh()
{
	return &m_oMesh;
}

const vector<unsigned short>& DataObject::GetIndices()
{
	return m_oIndices;
}

void DataObject::SetTexture(const string& texture)
{
    m_strTexture = texture;
}

void DataObject::LoadAsset()
{
    File::LoadOBJ(m_strAsset, m_oMesh, m_oIndices);
}

void DataObject::Scale(float x, float y, float z)
{
    MatrixScale(&m_oModel, x, y, z);
}

void DataObject::Rotate(float angle, float x, float y, float z)
{
    MatrixRotate(&m_oModel, angle, x, y, z);
}

void DataObject::Translate(float x, float y, float z)
{
    MatrixTranslate(&m_oModel, x, y, z);
}


