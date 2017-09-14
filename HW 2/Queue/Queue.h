#pragma once
#include "LinkedList.h"
/* Copyright: 151220023 */

template<class T>
class Queue {
private:
	LinkedList<T> *queue;
public:
	Queue() {
		queue = new LinkedList<T>();
	}
	Queue(T val) {
		queue = new LinkedList<T>(val);
	}
	/* Destructor function is in LinkedList.h. There is no need to release it again.*/

	bool isEmpty() {
		return queue->isEmpty();
	}
	void enqueue(T val) {
		queue->insertToTail(val);
	}

	T dequeue() {
		T ans = queue->deleteFromHead();
		return ans;
	}
};
