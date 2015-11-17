/*
 * EventBroadcaster.h
 *
 *  Created on: Nov 2, 2015
 *      Author: Eric-PC
 *
 *  Copyright 2015, Eric Stoutenburg, All rights reserved.
 */

#ifndef EVENT_BROADCASTER_H
#define EVENT_BROADCASTER_H

#include <map>
#include <vector>

#include "util/Types.h"

class Event;
class EventHandler;

class EventBroadcaster {
public:
	EventBroadcaster();

	~EventBroadcaster();

	void reset();

	void broadcast(Event* event);

	void add(EventHandler* handler);

	bool remove(EventHandler* handler);

private:
	std::map<event_type, std::vector<EventHandler*> > m_handlers;
};

#endif /* EVENT_BROADCASTER_H */
