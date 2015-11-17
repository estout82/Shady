/*
 * GameObject.cpp
 *
 *  Created on: Nov 2, 2015
 *      Author: Eric-PC
 *
 *  Copyright 2015, Eric Stoutenburg, All rights reserved.
 */

#include "GameObject.h"

#include <cstdlib>

#include "core/Component.h"

void GameObject::initalize() {
	/* NOTE: handle is set when the object is created in the Space class
	 * NOTE: event broadcaster and component map default constructors called
	 *       during allocation
	 */
}

void GameObject::dispose() {
	m_handle = 0;
	m_eventBroadcaster.reset();
	m_components.clear();
}

void GameObject::add(Component* component) {
	m_components.insert(std::pair<component_type, Component*>(component->getType(),
			                                                  component));
}

void GameObject::remove(Component* component) {
	for (auto itr = m_components.begin();
			itr != m_components.end();
			itr++) {
		if (itr->second == component) {
			m_components.erase(itr);
			return;
		}
	}
}

void GameObject::remove(component_type type) {
	m_components.erase(type);
}

Component* GameObject::getComponent(component_type type) {
	auto _elem = m_components.find(type);

	if (_elem != m_components.end())
		return _elem->second;

	return NULL;
}

// TODO: possibly find a better way to query all components
std::list<Component*> GameObject::getComponents() {
	std::list<Component*> _list;

	for (auto itr = m_components.begin();
			itr != m_components.end();
			itr++) {
		_list.push_back(itr->second);
	}

	return _list;
}

// TODO: possibly find a better way to query all component types
std::list<component_type> GameObject::getComponentTypes() {
	std::list<component_type> _list;

	for (auto itr = m_components.begin();
			itr != m_components.end();
			itr++) {
		_list.push_back(itr->first);
	}

	return _list;
}

EventBroadcaster* GameObject::getEventBroadcaster() {
	return &m_eventBroadcaster;
}

handle GameObject::getHandle() {
	return m_handle;
}
