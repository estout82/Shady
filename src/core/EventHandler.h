/*
 * EventHandler.h
 *
 *  Created on: Nov 2, 2015
 *      Author: Eric-PC
 *
 *  Copyright 2015, Eric Stoutenburg, All rights reserved.
 */

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "util/Types.h"

class EventHandler {
public:
	virtual ~EventHandler() {}

	virtual void handleEvent(Event* event) = 0;

	virtual event_type getHandledEvent() = 0;
};

#endif /* EVENTHANDLER_H */
