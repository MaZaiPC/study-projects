#include "stdafx.h"
#include "Stack.h"
#include "Node.h"


Stack::Stack(const Stack & Stack): size(Stack.size)
{
	Node *src;
	
	// Движение по списку-источнику (Stack)
	for (src = Stack.head; src != 0; src = src->next) {
		push(src->payload);
	} // for 
} // Stack::Stack


Stack::~Stack()
{
	Node *node, *temp;

	// Движение по списку-источнику (Stack)
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
	temp = (Node*)malloc(sizeof(Node)); // Выделение памяти для узла
	temp = head;						// Присваивание адреса головы временной переменной
	head = temp->next;					// Присваивание следующего адресса в списке голове
	free(temp);							// Освобождение памяти
	size--;								// Декремент счетчика данных в списке
} // Stack::remove


// добавление элемента в стек
void Stack::push(int payload)
{
	Node *temp;
	temp = (Node*)malloc(sizeof(Node));			// Выделение памяти для узла
	temp->payload = payload;					// Присваивание полезной нагрузки новому узлу
	temp->next = (size == 0 ? nullptr : head);	// Присваивание головы следующему адрессу в списке
	head = temp;								// Присваивание адресса нового элемента голове
	size++;										// Инкремент счетчика данных в списке
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