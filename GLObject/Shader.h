#ifndef GAMEDEMO_SHADER_H
#define GAMEDEMO_SHADER_H

#include <GLES3/gl3.h>
#include <string>

using namespace std;

GLuint CompileProgram(const string& vertexFile, const string& fragmentFile);

#endif //GAMEDEMO_SHADER_H
