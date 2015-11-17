/*
 * Space.h
 *
 *  Created on: Nov 9, 2015
 *      Author: Eric-PC
 *
 *  Copyright 2015, Eric Stoutenburg, All rights reserved.
 */

#ifndef SPACE_H
#define SPACE_H

#include <queue>
#include <map>

#include "util/Types.h"
#include "util/Allocators.h"

class GameObject;

class Space {
public:
	Space();

	~Space();

	GameObject* createGameObject();

	void releaseGameObject(handle handle);

private:
	FixedSizeAllocator<GameObject> m_allocator;

	std::map<handle, GameObject*> m_gameObjects;
};

#endif /* SPACE_H */
