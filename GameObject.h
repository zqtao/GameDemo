#ifndef GAMEDEMO_GAME_OBJECT_H
#define GAMEDEMO_GAME_OBJECT_H

#include "DataObject.h"

class GameObject {
public:
    GameObject(DataObject* dataObject) : m_pDataObject(dataObject) {};
    virtual ~GameObject() {};

	virtual void Init() = 0;
	virtual void Draw() = 0;
	void SetProgram(unsigned int program);

	static GameObject* CreateGameObject(DataObject* data);

protected:
	DataObject* m_pDataObject;
};

#endif //GAMEDEMO_GAME_OBJECT_H

