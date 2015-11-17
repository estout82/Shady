/*
 * Event.h
 *
 *  Created on: Nov 2, 2015
 *      Author: Eric-PC
 *
 *  Copyright 2015, Eric Stoutenburg, All rights reserved.
 */

#ifndef EVENT_H
#define EVENT_H

class Event {
public:
	virtual ~Event() {}

	virtual int getType() = 0;
};

#endif /* EVENT_H */
