#pragma once
#include <iostream>
#include <set>
/* Copyright: 151220023 */

template<class T>
class LinkedList
{
private:
	/* Node should be a private member. */
	template<class T>
	struct Node {
		T data;
		Node<T> * next;
		Node<T>(const T& d) : data(d), next() {}
		Node<T>() : data(), next() {}
		Node<T>(const Node* node) : data(node->data), next(node->next) {}
	};

public:
	Node<T> * head;
	Node<T> * tail;

	LinkedList() : head(NULL), tail(NULL) {}
	~LinkedList() {
		Node<T> * curr = head;
		while (head)
		{
			head = head->next;
			delete curr;
			curr = head;
		}
	}

	void insertToTail(T val);
	void insertToHead(T val);
	T deleteFromTail();
	T deleteFromHead();
	void print();
};

template<class T>
void LinkedList<T>::insertToTail(T val)
{
	Node<T> * newNode = new Node<T>(val);
	if (tail == NULL)
	{
		newNode->next = tail;
		tail = newNode;
		head = newNode;
		return;
	}
	tail->next = newNode;
	tail = tail->next;
}

template<class T>
void LinkedList<T>::insertToHead(T val)
{
	Node<T> * newNode = new Node<T>(val);
	newNode->next = head;
	head = newNode;
	if (head->next == NULL)
		tail = newNode;
}

template<class T>
T LinkedList<T>::deleteFromHead() {
	Node<T> * ans = new Node<T>(head);
	head = head->next;
	ans->next = NULL;
	return ans->data;
}

template<class T>
T LinkedList<T>::deleteFromTail() {
	Node<T> * ans = new Node<T>(head);
	while (ans->next != tail)
		ans = ans->next;
	tail = ans;
	ans = ans->next;
	tail->next = NULL;

	return ans->data;
}

template<class T>
void LinkedList<T>::print()
{
	Node<T> * curr = head;
	while (curr)
	{
		cout << curr->data << " -> ";
		curr = curr->next;
	}
	cout << "NULL" << endl;
}
