#include "Log.h"
#include "Shader.h"
#include "File.h"


static GLuint CompileShader(GLuint type, const char* code)
{
    GLuint shaderId = glCreateShader(type);
    glShaderSource(shaderId, 1, &code, nullptr);
    glCompileShader(shaderId);

    GLint compiled;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compiled);

    if (compiled == 0)
	{
        GLint infoLen = 0;
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLen);
        if (infoLen > 0)
		{
            char* infoLog = (char*)malloc(sizeof(char) * infoLen);
            glGetShaderInfoLog(shaderId, infoLen, nullptr, infoLog);
            LOGE("CompileShader: %s", infoLog);
            free(infoLog);
        }

        glDeleteShader(shaderId);
        return 0;
    }

    return shaderId;
}

GLuint CompileProgram(const string& vertexFile, const string& fragmentFile)
{
    char* code = File::GetFileContent(vertexFile);
    GLuint vertexId = CompileShader(GL_VERTEX_SHADER, code);
    free(code);

    code = File::GetFileContent(fragmentFile);
    GLuint fragmentId = CompileShader(GL_FRAGMENT_SHADER, code);
    free(code);

    GLuint programId = glCreateProgram();
    glAttachShader(programId, vertexId);
    glAttachShader(programId, fragmentId);
    glLinkProgram(programId);

    GLint linked;
    glGetProgramiv(programId, GL_LINK_STATUS, &linked);
    if (linked  == 0)
	{
        GLint infoLen = 0;
        glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &infoLen);
        if (infoLen > 0)
		{
            char* infoLog = (char*)malloc(sizeof(char)*infoLen);
            glGetProgramInfoLog(programId, infoLen, nullptr, infoLog);
            LOGE("CompileProgram: %s", infoLog);
            free(infoLog);
        }
    }

    glDeleteShader(vertexId);
    glDeleteShader(fragmentId);

    return programId;
}
