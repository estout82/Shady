/*
 * EventBroadcaster.cpp
 *
 *  Created on: Nov 2, 2015
 *      Author: Eric-PC
 *
 *  Copyright 2015, Eric Stoutenburg, All rights reserved.
 */

#include "EventBroadcaster.h"

#include "core/Event.h"
#include "core/EventHandler.h"

EventBroadcaster::EventBroadcaster() :
	m_handlers() {

}

EventBroadcaster::~EventBroadcaster() {
	reset();
}

void EventBroadcaster::reset() {
	m_handlers.clear();
}

void EventBroadcaster::broadcast(Event* event) {
	std::map<event_type, std::vector<EventHandler*> >::iterator _mapItr(m_handlers.find(event->getType()));

	// is there any handlers for this event type
	if (_mapItr != m_handlers.end()) {
		// loop through all handlers and call their handler event function
		std::vector<EventHandler*>* _handlers = &_mapItr->second;

		for (std::vector<EventHandler*>::iterator _itr = _handlers->begin();
				_itr != _handlers->end();
				_itr++) {
			(*_itr)->handleEvent(event);
		}
	}
}

void EventBroadcaster::add(EventHandler* handler) {
	// get the iterator of this event type
	std::map<event_type, std::vector<EventHandler*> >::iterator _mapItr = m_handlers.find(handler->getHandledEvent());

	// does the mapped list exist?
	if (_mapItr == m_handlers.end()) {
		// no, create it
		std::vector<EventHandler*> _list;
		_list.push_back(handler);

		// insert new list into map
		std::pair<event_type, std::vector<EventHandler*> > _pair(handler->getHandledEvent(),
				                                                 _list);
		m_handlers.insert(_pair);
		return;
	}
}

bool EventBroadcaster::remove(EventHandler* handler) {
	// get the iterator of this event type
	std::map<event_type, std::vector<EventHandler*> >::iterator _mapItr = m_handlers.find(handler->getHandledEvent());

	// does the mapped list exist?
	if (_mapItr != m_handlers.end()) {
		// loop through all handlers of this event type and see if pointers are equal
		std::vector<EventHandler*>* _handlers = &_mapItr->second;

		for (std::vector<EventHandler*>::iterator _itr = _handlers->begin();
				_itr != _handlers->end();
				_itr++) {
			if ((*_itr) == handler) {
				// remove handler from vector
				_handlers->erase(_itr);

				// was that the last handler of this type?
				if (_handlers->empty())
					m_handlers.erase(handler->getHandledEvent()); // erase from map

				return true;
			}
		}
	}

	return false;
}
