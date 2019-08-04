#include "Environment.h"

Environment::Environment() :
    m_oPrespective(),
    m_oCameraView(),
    m_vDataObjects(),
    m_vGameObjects()
{
}

Environment::~Environment()
{
    for (GameObject* gameObject : m_vGameObjects)
    {
        delete gameObject;
    }
    m_vGameObjects.clear();

    for (DataObject* dataObject : m_vDataObjects)
    {
        delete dataObject;
    }
    m_vDataObjects.clear();
}


void Environment::SetPerspective(Matrix& matrix)
{
    m_oPrespective = matrix;
}

void Environment::SetCameraView(Matrix& matrix)
{
    m_oCameraView = matrix;
}

void Environment::AddDataObject(const string& obj,
                       const string& vertexShader,
                       const string& fragmentSahder,
                       const string& texture)
{
    DataObject* dataObject = new DataObject("sphere.obj", "vertex.glsl", "fragment.glsl", "sky.tga");
    m_vDataObjects.push_back(dataObject);
    m_vGameObjects.push_back(GameObject::CreateGameObject(dataObject));
}


