// ListTwo.h
#pragma once
#include <iostream>
#include <string>
using namespace std;

struct listPeaple {
	string pasport;
	string nomerSim;
	string vipusk;
	string endSrok;

	listPeaple(string pasport = "", 
		string nomerSim = "", 
		string vipusk = "", 
		string endSrok = "")
	{
		this->pasport = pasport;
		this->nomerSim = nomerSim;
		this->vipusk = vipusk;
		this->endSrok = endSrok;
	}
};


class ListTwo {
public:
	ListTwo();
	~ListTwo();

	void pop_front();
	void push_back(listPeaple data);
	void clear();
	int GetSize() { return Size; }
	listPeaple& operator[](const int index);
	void push_front(listPeaple data);
	void insert(listPeaple data, int index);
	void removeAt(int index);
	void pop_back();

private:
	class Node {
	public:
		Node* pNext;
		Node* pEarly;
		listPeaple data;

		Node(listPeaple data = listPeaple(), 
			Node* pNext = nullptr, 
			Node* pEarly = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pEarly = pEarly;
		}
	};
	int Size;
	Node* head;
	Node* tail;
};




