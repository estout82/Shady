/*
 * Core.cpp
 *
 *  Created on: Nov 7, 2015
 *      Author: Eric-PC
 *
 *  Copyright 2015, Eric Stoutenburg, All rights reserved.
 */

#include "Core.h"

#include <iostream>

#include "core/Space.h"
#include "core/GameObject.h"

int main(int argc, char* args[]) {

	Space s;

	GameObject* o = s.createGameObject();
	s.releaseGameObject(o->getHandle());
}
