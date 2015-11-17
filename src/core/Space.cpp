/*
 * Space.cpp
 *
 *  Created on: Nov 9, 2015
 *      Author: Eric-PC
 *
 *  Copyright 2015, Eric Stoutenburg, All rights reserved.
 */

#include "core/Space.h"

#include <memory>
#include <cassert>

#include "core/GameObject.h"

// TODO: make a handle manager
uint32 g_handleGen = 1;

Space::Space() :
	m_allocator() {
}

Space::~Space() {

}

GameObject* Space::createGameObject() {
	GameObject* _object = m_allocator.get();
	_object->m_handle = g_handleGen++;
	_object->initalize();
	m_gameObjects.insert(std::pair<handle, GameObject*>(_object->m_handle, _object));
	return _object;
}

void Space::releaseGameObject(handle handle) {
	auto _mapElem = m_gameObjects.find(handle);

	if (_mapElem != m_gameObjects.end()) {
		m_allocator.release(_mapElem->second);
		m_gameObjects.erase(_mapElem);
	}
}
