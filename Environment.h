#ifndef GAMEDEMO_ENVIRONMENT_H
#define GAMEDEMO_ENVIRONMENT_H

#include <string>
#include "Matrix.h"
#include "DataObject.h"
#include "GameObject.h"

using namespace std;

class Environment {
public:
    Environment();
    virtual ~Environment();

    virtual void Init() = 0;

    void SetPerspective(Matrix& matrix);
    void SetCameraView(Matrix& matrix);

    void AddDataObject(const string& obj,
                       const string& vertexShader,
                       const string& fragmentSahder,
                       const string& texture);

protected:
    Matrix m_oPrespective;
    Matrix m_oCameraView;
    Vector3f m_vDirectLight;
    // vector<Vector3f> m_vPointLight; //数据点光源，需要定义点光源数据结构，定义位置/颜色/强度等信息
private:
    vector<DataObject*> m_vDataObjects;
    vector<GameObject*> m_vGameObjects;
};

#endif //GAMEDEMO_ENVIRONMENT_H


