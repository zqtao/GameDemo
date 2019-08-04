#include "GameObject.h"

#ifdef ANDROID_OS
#include "GLObject.h"
#endif

GameObject* GameObject::CreateGameObject(DataObject* data)
{
#ifdef ANDROID_OS
	return new GLObject(data);
#endif
}

