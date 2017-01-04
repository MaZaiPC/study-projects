#pragma once
#include "Node.h"

class Stack
{
	Node   *head;   // ��������� �� ������ ������� ����� - �� ������� �����
	size_t size;    // ������� ���������� ��������� � �����

public:
	Stack() : head(), size() {}
	Stack(int payload) : head(new Node(payload)), size(1) {}
	Stack(const Stack &Stack);
	~Stack();

	size_t getSize() { return size; }

	Stack &operator=(const Stack &Stack);

	// �������� �� ������
	// ���������� ��������
	void push(int payload);

	// �������� ��������
	void pop();

	// �������� �������� ����� �� �������
	bool isEmpty() { return size == 0; }

	friend ostream &operator <<(ostream &os, const Stack &Stack);
};

