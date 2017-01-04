#include "stdafx.h"
#include "Stack.h"
#include "Node.h"


Stack::Stack(const Stack & Stack): size(Stack.size)
{
	Node *src;
	
	// �������� �� ������-��������� (Stack)
	for (src = Stack.head; src != 0; src = src->next) {
		push(src->payload);
	} // for 
} // Stack::Stack


Stack::~Stack()
{
	Node *node, *temp;

	// �������� �� ������-��������� (Stack)
	for (node = head; node != nullptr; node = temp) {
		temp = node->next;
		delete node;
	} // for 
} // Stack::~Stack


Stack & Stack::operator=(const Stack & Stack)
{
	return *this;
}


void Stack::pop()
{
	if (head == nullptr) return;
	Node *temp;
	temp = (Node*)malloc(sizeof(Node)); // ��������� ������ ��� ����
	temp = head;						// ������������ ������ ������ ��������� ����������
	head = temp->next;					// ������������ ���������� ������� � ������ ������
	free(temp);							// ������������ ������
	size--;								// ��������� �������� ������ � ������
} // Stack::remove


// ���������� �������� � ����
void Stack::push(int payload)
{
	Node *temp;
	temp = (Node*)malloc(sizeof(Node));			// ��������� ������ ��� ����
	temp->payload = payload;					// ������������ �������� �������� ������ ����
	temp->next = (size == 0 ? nullptr : head);	// ������������ ������ ���������� ������� � ������
	head = temp;								// ������������ ������� ������ �������� ������
	size++;										// ��������� �������� ������ � ������
} // Stack::insert


ostream &operator <<(ostream &os, const Stack &Stack)
{
	Node *skate = Stack.head;
	while (skate != nullptr) {
		os << *skate;
		skate = skate->getNext();
	} // while
	return os;
} // &operator <<


istream &operator >>(istream &is, Stack &Stack)
{
	return is;
} // &operator <<