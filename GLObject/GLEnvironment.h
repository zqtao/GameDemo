#ifndef GAMEDEMO_GL_ENVIRONMENT_H
#define GAMEDEMO_GL_ENVIRONMENT_H

#include "Environment.h"

class GLEnvironment : public Environment {
public:
    GLEnvironment() : Environment() {};
    virtual ~GLEnvironment() {};

	virtual void Init();
};

#endif //GAMEDEMO_GL_ENVIRONMENT_H



