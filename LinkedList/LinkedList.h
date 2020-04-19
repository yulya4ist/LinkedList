#pragma once
#include<iostream>
class LinkedList
{
private:
	struct Node
	{
		double data;
		Node* next;
	};

	Node* head;
	Node* tail;
	size_t length;
public:
	class Iterator
	{
	public:
		Iterator (Node* current) 
		{ 
			this->current = current; 
		}
		Iterator& operator++ (int)
		{ 
			if (this->current == nullptr)
			{
				std::cout << "Error : Iterator out of range" << std::endl;
				exit(1);
			}
			this->current = this->current->next; 
			return *this; 
		}
		Iterator& operator+=(int n)
		{
			for (size_t i = 0; i < n; i++)
			{
				if(this->current == nullptr)
				{
					std::cout << "Error : Iterator out of range" << std::endl;
					exit(1);
				}
				this->current = this->current->next;
			}
			return *this;
		}
		Iterator& operator+(int n)
		{
			return *this+=n;
		}
		double operator*()
		{
			if (this->current == nullptr)
			{
				std::cout << "Error : Null Iterator dereferencing" << std::endl;
				exit(1);
			}
			return this->current->data;
		}
		bool operator==(Iterator other)
		{
			if (other.current == this->current) return true;
			return false;
		}
		bool operator!=(Iterator other)
		{
			if (other.current != this->current) return true;
			return false;
		}
		void Delete()
		{
			if (this->current == nullptr)
			{
				std::cout << "Error : Delete Null iterator" << std::endl;
				exit(1);
			}
			delete this->current;
		}
	private:
		Node* current;
	};

	LinkedList::Iterator Begin() const;
	LinkedList::Iterator End() const;

	LinkedList();
	
	void Move(const LinkedList& other);
	void Append(double value);
	void Prepend(double value);
	void Delete();
	void Print();
	size_t GetLength();
	LinkedList& operator=(const LinkedList& other);

	~LinkedList();
};



