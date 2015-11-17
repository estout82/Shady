/*
 * System.h
 *
 *  Created on: Nov 2, 2015
 *      Author: Eric-PC
 *
 *  Copyright 2015, Eric Stoutenburg, All rights reserved.
 */

#ifndef SYSTEM_H
#define SYSTEM_H

#include <list>

#include "util/Types.h"

class GameObject;

class System {
public:
	virtual ~System();

	void addComponentRequirement(component_type type);

	const std::list<component_type>& getRequiredComponents();

	virtual void run() = 0;

	virtual int getType() = 0;

protected:
	System();

private:
	std::list<GameObject*> m_gameObjects;
	std::list<component_type> m_componentRequirements;
};

#endif /* SYSTEM_H */
