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
		Iterator(const Iterator& other) : Iterator(other.current) {}


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
		Iterator& operator=(const Iterator& other)
		{
			this->current = other.current;
		}
		
		double& operator*()
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
			return (other.current == this->current);
		}

		bool operator!=(Iterator other)
		{
			return !(*this==other);
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
	LinkedList(const LinkedList& other);
	LinkedList(LinkedList&& other);

	void Copy(const LinkedList& other);
	void Append(double value);
	void Prepend(double value);
	void Move(LinkedList&& other);

	void Delete();
	void Print();
	size_t GetLength();
	LinkedList& operator=(const LinkedList& other);

	LinkedList& operator=( LinkedList&& other);

	~LinkedList();
};



