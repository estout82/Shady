/*
 * SimpleAllocator.h
 *
 *  Created on: Nov 7, 2015
 *      Author: Eric-PC
 */

#ifndef SIMPLE_ALLOCATOR_H
#define SIMPLE_ALLOCATOR_H

#include <queue>
#include <memory>
#include <cassert>

#include "util/Types.h"

template<typename T>
class SimpleAllocator {
public:
	SimpleAllocator() :
		capacity(100),
		front(0),
		array(NULL),
		removedHandles() {
		array = new T[capacity];
	}

	~SimpleAllocator() {
		delete[] array;
	}

	T* get(handle handle) {
		assert(handle > 0 && handle < capacity);
		return &(array[handle]);
	}

	handle allocate() {
		if (!removedHandles.empty()) {
			handle _r = removedHandles.front();
			removedHandles.pop();
			return _r;
		}

		if (front >= capacity)
			grow();

		return front++;
	}

	handle deallocate(handle handle) {
		assert(handle > 0 && handle < capacity);
		removedHandles.push(handle);
		return handle;
	}

private:
	uint32 capacity;
	handle front;

	T* array;

	std::queue<handle> removedHandles;

	void grow() {
		uint32 _newCapacity = capacity * 1.4;
		T* _newArray = new T[_newCapacity];
		memcpy(_newArray, array, sizeof(T) * capacity);
		capacity = _newCapacity;
	}
};

#endif /* SIMPLE_ALLOCATOR_H */
