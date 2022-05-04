#include "ListTwo.h"
// ÖÈÊËÈ×ÅÑÊÈÉ ÄÂÓÍÀÏÐÀÂËÅÍÍÛÉ ÑÏÈÑÎÊ


ListTwo::ListTwo() {
	Size = 0;
	head = nullptr;
	tail = nullptr;
}


ListTwo::~ListTwo() {
	clear();
}



void ListTwo::pop_front() {
	Node* temp = head;

	head = head->pNext;
	
	tail->pNext = head;

	head->pEarly = tail;

	delete temp;

	Size--;

}



void ListTwo::push_back(listPeaple data) {
	if (head == nullptr)
	{
		head = new Node(data);
		tail = head;
	}
	else
	{
		tail = new Node(data, head, tail);
		tail->pEarly->pNext = tail;
		tail->pNext->pEarly = tail;
	}

	Size++;
}



void ListTwo::clear() {
	while (Size)
	{
		pop_front();
	}
}



listPeaple& ListTwo::operator[](const int index) {
	int counter = 0;

	Node* current = this->head;

	if (index < Size) {
		do
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pNext;
			counter++;
		} while (current != head);
	}
}


void ListTwo::push_front(listPeaple data) {
	head = new Node(data, head, tail);
	head->pNext->pEarly = head;
	tail->pNext = head;
	Size++;
}


void ListTwo::insert(listPeaple data, int index) {

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node* newNode = new Node(data, previous->pNext, previous);

		previous->pNext = newNode;
		newNode->pNext->pEarly = newNode;

		Size++;
	}
}



void ListTwo::removeAt(int index) {
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;
		toDelete->pNext->pEarly = previous;

		delete toDelete;

		Size--;
	}
}


void ListTwo::pop_back() {
	Node* temp = tail;

	tail = tail->pEarly;

	tail->pNext = head;

	head->pEarly = tail;

	delete temp;

	Size--;
}
