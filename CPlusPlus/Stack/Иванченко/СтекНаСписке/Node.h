#pragma once
//#include "List.h"

class Node
{
	int payload;  // "полезная нагрузка" - информация, для хранения
	Node *next;   // адрес следующего элемента списка

	friend class Stack;

public:
	Node() : payload(), next() {}
	Node(int payload) : payload(payload), next() {}
	~Node() {}

	int getPayload() { return payload; }
	Node *getNext() { return next;  }

	friend ostream &operator <<(ostream &os, const Node &item);
	friend istream &operator >>(istream &os, Node &item);
};

