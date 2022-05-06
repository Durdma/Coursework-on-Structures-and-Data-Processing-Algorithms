#pragma once
#include <iostream>
#include <string>
using namespace std;


struct listPeaple {
	string pasport;
	string nomerSim;
	string vipusk;
	string endSrok;

	listPeaple(string pasport = "", string nomerSim = "", string vipusk = "", string endSrok = "")
	{
		this->pasport = pasport;
		this->nomerSim = nomerSim;
		this->vipusk = vipusk;
		this->endSrok = endSrok;
	}
};


class ListTwo
{
public:
	ListTwo();
	~ListTwo();

	//удаление первого элемента в списке
	void pop_front();

	//добавление элемента в конец списка
	void push_back(listPeaple data);

	// очистить список
	void clear();

	// получить количество елементов в списке
	int GetSize() { return Size; }

	// перегруженный оператор [] 
	listPeaple& operator[](const int index);

	//добавление элемента в начало списка
	void push_front(listPeaple data);

	//добавление элемента в список по указанному индексу
	void insert(listPeaple data, int index);

	//удаление элемента в списке по указанному индексу
	void removeAt(int index);

	//удаление последнего элемента в списке
	void pop_back();


	//сортировка извлечением списка
	//void sort();

private:

	class Node
	{
	public:
		Node* pNext;
		Node* pEarly;
		listPeaple data;

		Node(listPeaple data = listPeaple(), Node* pNext = nullptr, Node* pEarly = nullptr)
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




