#pragma once
#include "Node.h"

class Stack
{
	Node   *head;   // указатель на первый элемент стека - на вершину стека
	size_t size;    // текущее количество элементов в стеке

public:
	Stack() : head(), size() {}
	Stack(int payload) : head(new Node(payload)), size(1) {}
	Stack(const Stack &Stack);
	~Stack();

	size_t getSize() { return size; }

	Stack &operator=(const Stack &Stack);

	// Операции со стеком
	// добавление элемента
	void push(int payload);

	// удаление элемента
	void pop();

	// операция проверки стека на пустоту
	bool isEmpty() { return size == 0; }

	friend ostream &operator <<(ostream &os, const Stack &Stack);
};

