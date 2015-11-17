/*
 * GameObject.h
 *
 *  Created on: Nov 2, 2015
 *      Author: Eric-PC
 *
 *  Copyright 2015, Eric Stoutenburg, All rights reserved.
 */

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <list>
#include <map>

#include "core/EventBroadcaster.h"

#include "util/Types.h"

class Component;
class GameObjectManager;

class GameObject {
public:
	friend class Space;

	void add(Component* component);

	void remove(Component* component);

	void remove(component_type type);

	Component* getComponent(component_type type);

	std::list<Component*> getComponents();

	std::list<component_type> getComponentTypes();

	EventBroadcaster* getEventBroadcaster();

	handle getHandle();

private:
	handle m_handle;

	EventBroadcaster m_eventBroadcaster;

	std::map<component_type, Component*> m_components;

	void initalize();

	void dispose();
};

#endif /* GAME_OBJECT_H */
