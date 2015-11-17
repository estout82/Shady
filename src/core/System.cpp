/*
 * System.cpp
 *
 *  Created on: Nov 2, 2015
 *      Author: Eric-PC
 *
 *  Copyright 2015, Eric Stoutenburg, All rights reserved.
 */

#include "System.h"

System::System() :
	m_gameObjects(),
	m_componentRequirements() {

}

System::~System() {
	m_gameObjects.clear();
	m_componentRequirements.clear();
}

void System::addComponentRequirement(component_type type) {
	m_componentRequirements.push_back(type);
}

const std::list<component_type>& System::getRequiredComponents() {
	return m_componentRequirements;
}
