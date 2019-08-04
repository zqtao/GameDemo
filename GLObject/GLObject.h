#ifndef GAMEDEMO_GLOBJECT_H
#define GAMEDEMO_GLOBJECT_H

#include <GLES3/gl3.h>
#include "GameObject.h"
#include "DataObject.h"

class GLObject : public GameObject {
public:
    GLObject(DataObject* dataObject);
    virtual ~GLObject();

	virtual void Init();
	virtual void Draw();
	virtual void SetProgram(GLuint program);

private:
	void LoadMesh();
	void GenerateTexture();
	void GenerateProgram();

private:
    GLuint m_uTextureId;
	GLuint m_pBufferId[4]; // 1)vertex 2)uv 3)normal 4)indices
	GLuint m_uProgramId;
	unsigned int m_uIndexSize;
};

#endif //GAMEDEMO_GLOBJECT_H
