/*
 * Allocators.h
 *
 *  Created on: Nov 16, 2015
 *      Author: Eric-PC
 *
 *   Copyright 2015, Eric Stoutenburg, All rights reserved.
 */

#ifndef ALLOCATORS_H
#define ALLOCATORS_H

#include <cassert>
#include <memory>
#include <queue>

#include "util/Types.h"

template<typename T>
class Allocator {
public:
	Allocator() {}

	virtual ~Allocator() {}

	virtual T* get() = 0;

	virtual void release(T* t) = 0;

private:
};

template<typename T>
class FixedSizeAllocator : public Allocator<T> {
public:
	FixedSizeAllocator() :
		m_capacity(100),
		m_front(nullptr),
		m_array(nullptr),
		m_removedPtrs() {
		m_array = new T[m_capacity];
		m_front = m_array;
	}

	virtual ~FixedSizeAllocator() {
		delete[] m_array;
	}

	virtual T* get() override {
		if (m_front > m_array + m_capacity) {
			if (!m_removedPtrs.empty()) {
				T *_object = m_removedPtrs.front();
				m_removedPtrs.pop();
				return _object;
			}

			// else
			growArray();
		}

		return m_front++;
	}

	virtual void release(T* t) override {
		// check bounds
		assert(t >= m_array &&
			   t <= m_array + m_capacity);

		m_removedPtrs.push(t);
	}

private:
	uint32 m_capacity;

	T* m_front;

	T* m_array;

	std::queue<T*> m_removedPtrs;

	void growArray() {
		uint32 _newCapacity = m_capacity * 1.4;
		T* _newArray = new T[_newCapacity];
		memcpy(_newArray, m_array, sizeof(T) * m_capacity);
		m_capacity = _newCapacity;
		m_array = _newArray;
	}
};

#endif /* ALLOCATORS_H */
