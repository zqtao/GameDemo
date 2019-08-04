#include "GLObject.h"
#include "Shader.h"
#include "File.h"

GLObject::GLObject(DataObject* dataObject):
	GameObject(dataObject),
	m_uTextureId(0),
	m_pBufferId{0, 0, 0, 0},
	m_uProgramId(0),
	m_uIndexSize(0)
{
}

GLObject::~GLObject()
{
	glDeleteBuffers(4, m_pBufferId);

	if (m_uTextureId != 0)
	{
		glDeleteTextures(1, &m_uTextureId);
	}

	if (m_uProgramId != 0)
	{
		glDeleteProgram(m_uProgramId);
	}
}

void GLObject::Init()
{
	GenerateProgram();
	LoadMesh();
	GenerateTexture();
}

void GLObject::Draw()
{
	glUseProgram(m_uProgramId);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_pBufferId[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, m_pBufferId[1]);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, m_pBufferId[2]);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_pBufferId[3]);

	glDrawElements(GL_TRIANGLES, m_uIndexSize, GL_UNSIGNED_SHORT, nullptr);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}

void GLObject::SetProgram(GLuint program)
{
	m_uProgramId = program;
}


void GLObject::LoadMesh()
{
	const Mesh* mesh = m_pDataObject->GetMesh();

	glGenBuffers(4, m_pBufferId);

	//vertex
	const vector<Vertex>& vertex = mesh->vertex;
	glBindBuffer(GL_ARRAY_BUFFER, m_pBufferId[0]);
	glBufferData(GL_ARRAY_BUFFER, vertex.size() * sizeof(Vertex), vertex.data(), GL_STATIC_DRAW);

	//uv
	const vector<UV>& uv = mesh->uv;
	glBindBuffer(GL_ARRAY_BUFFER, m_pBufferId[1]);
	glBufferData(GL_ARRAY_BUFFER, uv.size() * sizeof(UV), uv.data(), GL_STATIC_DRAW);

	//normal
	const vector<Normal> normal = mesh->normal;
	glBindBuffer(GL_ARRAY_BUFFER, m_pBufferId[2]);
	glBufferData(GL_ARRAY_BUFFER, normal.size() * sizeof(Normal), normal.data(), GL_STATIC_DRAW);

	//indices
	const vector<unsigned short>& indices = m_pDataObject->GetIndices();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_pBufferId[3]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned short), indices.data(), GL_STATIC_DRAW);
	m_uIndexSize = indices.size();
}

void GLObject::GenerateTexture()
{
	int width;
	int height;

	char *buffer = File::GetTGAContent(m_pDataObject->GetTexture(), width, height);
	GLuint texId;

	glGenTextures(1, &m_uTextureId);
	glBindTexture(GL_TEXTURE_2D, m_uTextureId);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, buffer);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	free(buffer);
}

void GLObject::GenerateProgram()
{
	m_uProgramId = CompileProgram(m_pDataObject->GetVertexShader(), m_pDataObject->GetFragmentShader());
}



