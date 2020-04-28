#include "LinkedList.h"
#include<iostream>
#include<vector>


LinkedList::Iterator LinkedList::Begin() const
{
	return LinkedList::Iterator(this->head);
}

LinkedList::Iterator LinkedList::End() const
{
	return LinkedList::Iterator(nullptr);
}

LinkedList::LinkedList()
{
	this->tail = nullptr;
	this->head = nullptr;
	this->length = 0;
}

LinkedList::LinkedList(const LinkedList& other)
{
	for (auto it = other.Begin(); it != other.End(); it++)
	{
		this->Append(*it);
	}
}

LinkedList::LinkedList(LinkedList&& other)
{
	this->head = other.head;
	this->tail = other.tail;
	this->length = other.length;

	other.head = nullptr;
	other.tail = nullptr;
	other.length = 0;
}



void LinkedList::Copy(const LinkedList& other)
{
	*this = other;
}

void LinkedList::Append(double value)
{
	Node* end = new Node;

	end->data = value;
	end->next = nullptr;

	if (this->length == 0)
		this->head = end,
		this->tail = end;
		
	else 
		this->tail->next = end,
	    this->tail = end;
	this->length++;
}

void LinkedList::Prepend(double value)
{
	Node* start = new Node;
	start->data = value;

	if (length == 0)
		this->head = start,
		this->tail = start,
		start->next = nullptr;
	else
		start->next = head,
		head = start;

	length++;

}

void LinkedList::Move(LinkedList&& other)
{
	*this = other;
}

void LinkedList::Delete()
{
	for (auto it = this->Begin(); it != this->End(); )
	{
		auto temp = it;
		it++;
		temp.Delete();
	}
	this->head = nullptr;
	this->tail = nullptr;
	this->length = 0;
}		

void LinkedList::Print()
{
	for (auto it = this->Begin(); it != this->End(); it++)
		std::cout << *it  << '\t';
	std::cout << std::endl;
}

size_t LinkedList::GetLength()
{
	return this->length;
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
	if (this == &other)
		return *this;

	this->Delete();

	for (auto it = other.Begin(); it != other.End(); it++)
	{
		this->Append(*it);
	}
	return *this;
}

LinkedList& LinkedList::operator=(LinkedList&& other)
{
	if (this == &other)
		return *this;
	this->Delete();

	this->head = other.head;
	this->tail = other.tail;
	this->length = other.length;

	other.head = nullptr;
	other.tail = nullptr;
	other.length = 0;

	return *this;
}

LinkedList::~LinkedList()
{
	this->Delete();
}









