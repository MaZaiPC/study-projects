#include "stdafx.h"
#include "Node.h"


ostream &operator <<(ostream &os, const Node &item)
{
	os << "{ " << item.payload << "} " << (item.next?" --> ":" --X");
	return os;
} // operator <<


istream &operator >>(istream &is, Node &item)
{
	is >> item.payload;
	return is;
} // operator >>


