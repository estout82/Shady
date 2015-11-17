/*
 * Component.h
 *
 *  Created on: Nov 2, 2015
 *      Author: Eric-PC
 *
 *  Copyright 2015, Eric Stoutenburg, All rights reserved.
 */

#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
public:
	virtual ~Component() {}

	virtual int getType() = 0;
};

#endif /* COMPONENT_H */
