#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

//	Структура  SIM карты
struct SIM
{
	string nomerSIM ;
	string tarif;
	int vipusk;
	  bool statusWork;

	  SIM(string nomerSIM = "", string tarif = "", int vipusk = NULL, bool statusWork = false) {
		  this->nomerSIM = nomerSIM;
		  this->tarif = tarif;
		  this->vipusk = vipusk;
		  this->statusWork = statusWork;
	  }
};

//	Структура ячейки хэш таблицы
struct element
{
	SIM sim;
	bool empty      =  1;   // пустой ли
	bool deleted    =  0;   // удалён ли
	 int pos        = -1;   // позиция
	 int collisions =  0;   // коллизии
};


class HashTable
{
public:
	HashTable();
	const int size = 500;					// размер таблицы
	int sizeCount = 0;						// сколько уже элементов в таблице

	element* hashTable; // во избежания переполнения стека выделим память для массива структур в кучу;

	int getHashOne(string key);
	int getHashTwo(string key);
	
	
	int  addKeyHashTable(SIM);
	void  deleteObject(string deleteSIM);
	SIM searchObjectKey(string key);
	void allDelete();


	void printHashTable();

	bool findString(string s, string c);

	void searchSimTarif(string str);

	void switchTarif(string str); 

	bool chekSIM(string key);  // ПРОВЕРКА СИМ КАРТЫ НА УНИКАЛЬНОСТЬ
};

