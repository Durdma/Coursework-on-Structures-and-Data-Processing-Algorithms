#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <fstream>

#include "HashTable.h"
#include "ListTwo.h"
#include "Tree.h"
#include "ChelValue.h"

using namespace std;

//  СОРТИРОВКА СПИСКА ИЗВЛЕЧЕНИЕМ
void sortList(ListTwo& list) {
	for (int i = 0; i < list.GetSize(); i++)
	{
		listPeaple min = list[i];
		int index = i;
		for (int t = i+1; t < list.GetSize(); t++)
		{
			if (stoi(list[t].nomerSim) < stoi(min.nomerSim)) {
				min = list[t];
				index = t;
			}
		}
		list[index] = list[i];
		list[i] = min;
	}
}

int main() {
	
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int key;
	
	HashTable Table;
	ListTwo MList;
	Tree MTree;
	ChelValue Chek;
	
	while (true) {
		system("cls");
		cout << "\n |-----------------------МЕНЮ------------------------|\n";
		cout << " | 1.  Зарегистрировать нового клиента               |" << endl;
		cout << " | 2.  Снять с обслуживания клиента                  |" << endl;
		cout << " | 3.  Просмотреть всех зарегистрированных клиентов  |" << endl;
		cout << " | 4.  Очистить все данные о клиентах                |" << endl;
		cout << " | 5.  Поиск клиента по паспорту                     |" << endl;
		cout << " | 6.  Поиск клиента по фрагменту ФИО или адресса    |" << endl;
		cout << " | 7.  Добавить новую SIM-карту                      |" << endl;
		cout << " | 8.  Удалить сведения о SIM-карте                  |" << endl;
		cout << " | 9.  Просмотреть все имеющиеся SIM-карт            |" << endl;
		cout << " | 10. Очистить все данные о SIM-картах              |" << endl;
		cout << " | 11. Поиск SIM-карты по номеру SIM-карты           |" << endl;
		cout << " | 12. Поиск SIM-карты по тарифу                     |" << endl;
		cout << " | 13. Зарегистрировать выдачу клиенту SIM-карты     |" << endl;
		cout << " | 14. Зарегистрировать возврат SIM-карты от клиента |" << endl;
		cout << " | 15. Выход                                         |" << endl;
		cout << " |---------------------------------------------------|" << endl<<endl;

		key = Chek.inputMenu();

		if (key == 1)
		{
			system("cls");
			cout << " Зарегистрировать нового клиента\n" << endl;
			
			string pasport = Chek.inputPasport();

			if (MTree.checkPasport(pasport, MTree.root)) {
				cout << "Клиент с таким паспортом уже существует." << endl;
			}
			else {
				string placeAndDate = Chek.inputBirthdayAndPlaces();
				string FIO = Chek.inputFIO();
				int birthyear = Chek.inputYear();
				string address = Chek.inputArress();
				clientTree clientAdd(pasport, placeAndDate, FIO, birthyear, address);
				MTree.addKlitnt(clientAdd);
			}
			cout << "\n";
			system("pause");
		}

		if (key == 2) {
			system("cls");
			cout << " Снятие с обслуживания клиента\n" << endl;
			string pas = Chek.inputPasport();

			cout << " Введите дату удаления обслуживания клиента: ";
			string data = Chek.inputFullDate();

			cout << " Данные о удаляемоим клиенте: \n";
			MTree.findCustomer(MTree.root, pas);
			MTree.deleteKlient(pas);

			
			bool chek = false;
			for (int i = 0; i < MList.GetSize(); i++)
			{
				if (MList[i].pasport == pas && MList[i].endSrok == "") {
					chek = true;
				}
			}

			if(chek) {
				cout << " У него снимаются с обслуживания SIM карты: \n";
				for (int i = 0; i < MList.GetSize(); i++)
				{
					if (MList[i].pasport == pas && MList[i].endSrok == "") {
						cout << " " << MList[i].nomerSim << endl;
						Table.switchTarif(MList[i].nomerSim);
						MList[i].endSrok = data;
					}
				}
			}
			else {
				cout << " У данного клиента не было выданных SIM карт \n";
			}
			cout << "\n";
			system("pause");
		}

		if (key == 3) {
			system("cls");
			cout << " Просмотреть всех зарегистрированных клиентов\n" << endl;
			MTree.showKlient();
			cout << "\n";
			system("pause");
		}

		if (key == 4) {
			system("cls");
			cout << " Все данные о клинтах удалены. \n";
			MTree.removeAll();

			for (int i = 0; i < MList.GetSize(); i++)
			{
				if (MList[i].endSrok == "") {
					Table.switchTarif(MList[i].nomerSim);
					MList[i].endSrok = "AllDeleteKlient";
				}
			}
			cout << "\n";
			system("pause");
		}

		if (key == 5) {
			system("cls");
			cout << " Поиск клиента по паспорту\n" << endl;
			string pasport = Chek.inputPasport();
			if (!MTree.checkPasport(pasport, MTree.root)) {
				cout << " Клиент с таким паспортом не существует" << endl;
			}
			else {
				MTree.findCustomer(MTree.root, pasport);

				bool chek = false;
				for (int i = 0; i < MList.GetSize(); i++)
				{
					if (MList[i].pasport == pasport && MList[i].endSrok == "") {
						chek = true;
					}
				}

				if (chek) {
					cout << " Ему выданы SIM карты: \n";
					for (int i = 0; i < MList.GetSize(); i++)
					{
						if (MList[i].pasport == pasport && MList[i].endSrok == "") {
							cout << " " << MList[i].nomerSim << endl;
						}
					}
				}
				else {
					cout << " У данного клиента не было выданных SIM карт \n";
				}
			}
			cout << "\n";
			system("pause");
		}

		if (key == 6) {
			system("cls");
			cout << " Поиск клиента по фрагментам ФИО или адресу\n" << endl;

			string str;
			cout << "\n Введите часть ФИО или адресса клиента, которого хотите найти: ";
			getline(cin, str);
			bool chek = false;
			MTree.findKlientOnString(MTree.root, str,chek);
			if (!chek) {
				cout << "\n Совпадений не найденно\n";
			}
			cout << "\n";
			system("pause");
		}

		if (key == 7) {
			system("cls");
			cout << " Добавить новую SIM-карту\n" << endl;

			string nomerSIM = Chek.inputSIM();

			if (!Table.chekSIM(nomerSIM)) {
				string tarif = Chek.inputTarifSIM();
				int vipusk = Chek.inputYear();
				SIM newSIM(nomerSIM, tarif, vipusk);
				Table.addKeyHashTable(newSIM);
			}
			else {
				cout << "\n Такая SIM карта уже добавлена\n";
			}
			cout << "\n";
			system("pause");
		}


		if (key == 8) {
			system("cls");
			cout << " Удаление сведения о SIM-карте\n" << endl;

			string nomerSIM = Chek.inputSIM();
			Table.deleteObject(nomerSIM);

			cout << " Введите дату удаления SIM карты: ";
			string data = Chek.inputFullDate();

			for (int i = 0; i < MList.GetSize(); i++)
			{
				if (MList[i].nomerSim == nomerSIM && MList[i].endSrok == "")
				{
					MList[i].endSrok = data;
				}
			}
			cout << "\n";
			system("pause");
		}


		if (key == 9) {
			system("cls");
			cout << " Просмотреть все имеющиесяя SIM-карт\n" << endl;

			Table.printHashTable();
			cout << "\n";
			system("pause");
		}


		if (key == 10) {
			system("cls");
			cout << " Очистить все данные о SIM-картах\n" << endl;

			Table.allDelete();

			cout << " Все SIM карты удалены\n ";
			for (int i = 0; i < MList.GetSize(); i++)
			{
				if (MList[i].endSrok == "")
				{
					MList[i].endSrok = "AllDeleteSIM";
				}
			}
			cout << "\n";
			system("pause");
		}

		if (key == 11) {
			system("cls");
			cout << " Поиск SIM-карты по номеру SIM-карты\n" << endl;

			string nomerSIM = Chek.inputSIM();
			SIM poisk = Table.searchObjectKey(nomerSIM);
			if (poisk.nomerSIM != "") {
				cout << setw(15) << " Номер" << setw(15) << "Тариф" << setw(15) << "Год" << setw(15) << "Статус" << '\n';
				string status = poisk.statusWork ? "выдана" : "невыдана";
				cout << setw(15) << poisk.nomerSIM << setw(15) << poisk.tarif << setw(15) << poisk.vipusk << setw(15) << status << '\n';

				
				
				bool chek = false;
				for (int i = 0; i < MList.GetSize(); i++)
				{
					if (MList[i].endSrok == "" && MList[i].nomerSim == nomerSIM)
					{
						chek = true;
					}
				}

				if (chek)
				{
					cout << " Данная SIM карта принадлежит: \n" << endl;
					
					for (int i = 0; i < MList.GetSize(); i++)
					{
						if (MList[i].endSrok == "" && MList[i].nomerSim == nomerSIM)
						{
							MTree.findCustomer(MTree.root, MList[i].pasport);
						}
					}
				}
				else {
					cout << " Данная SIM карта никому не выдана \n" << endl;
				}
				
			}
			cout << "\n";
			system("pause");
		}


		if (key == 12) {
			system("cls");
			cout << " Поиск SIM-карты по тарифу\n" << endl;

			string tarif = Chek.inputTarifSIM();
			Table.searchSimTarif(tarif);
			cout << "\n";
			system("pause");
		}


		if (key == 13) {
			system("cls");
			cout << " Зарегистрировать выдачу клиенту SIM-карты\n" << endl;

			string pasport = Chek.inputPasport();
			if (!MTree.checkPasport(pasport, MTree.root)) {
				cout << " Клиент с таким паспортом не существует" << endl;
			}
			else {
				string nomerSIM = Chek.inputSIM();
				SIM poisk = Table.searchObjectKey(nomerSIM);
				if (poisk.nomerSIM != "") {
					if (poisk.statusWork == false) {
						cout << " Введите дату выдачи SIM карты: " ;
						string data = Chek.inputFullDate();
						listPeaple vip(pasport, nomerSIM, data);
						MList.push_back(vip);
						
						sortList(MList); // отсортировать список извлечением
						
						cout << " SIM карта выдана\n";
						Table.switchTarif(nomerSIM);
					}
					else {
						cout << " SIM карты с таким номером уже зарегистрирована клиенту" << endl;
					}
				}
			}
			cout << "\n";
			system("pause");
		}


		if (key == 14) {
			system("cls");
			cout << " Зарегистрировать возврат SIM-карты от клиента\n" << endl;

			string pasport = Chek.inputPasport();
			if (!MTree.checkPasport(pasport, MTree.root)) {
				cout << " Клиент с таким паспортом не существует" << endl;
			}
			else {
				string nomerSIM = Chek.inputSIM();
				SIM poisk = Table.searchObjectKey(nomerSIM);
				if (poisk.nomerSIM != "") {
					bool chek = false;

					for (int i = 0; i < MList.GetSize(); i++)
					{
						if (MList[i].nomerSim == nomerSIM && MList[i].endSrok == "" && MList[i].pasport == pasport)
						{
							chek = true;
						}
					}
					
					
					if (poisk.statusWork == true && chek) {
						for (int i = 0; i < MList.GetSize(); i++)
						{
							if (MList[i].nomerSim == nomerSIM && MList[i].pasport == pasport && MList[i].endSrok == "")
							{
								string data;
								do {
									cout << " Введите дату возврата SIM карты: ";
									data = Chek.inputFullDate();
									
								} while (!Chek.chekDifferentDate(MList[i].vipusk, data));

								MList[i].endSrok = data;
								break;
							}
						}
						cout << " SIM карта возвращена\n";
						Table.switchTarif(nomerSIM);
					}
					else {
						cout << " SIM карты с таким номером не зарегистрирована клиенту" << endl;
					}
				}
			}
			cout << "\n";
			system("pause");
		}


		if (key == 15) {
			break;
		}



		if (key == 16) {
			
			string pasport = "2000-300450";
			string  placeAndDate  = "Самара 20.12.2016";
			string FIO = "Морозов Андрей Витальевич";
			int birthyear = 2002;
			string address = "г. Санкт-Петербург ул. Зенитчиков 26";
			clientTree clientAdd(pasport, placeAndDate, FIO, birthyear, address);
			MTree.addKlitnt(clientAdd);
			
			
			string pasport1 = "1234-123456";
			string placeAndDate1 = "Ростов-на-Дону 20.12.2016";
			string FIO1 = "Гулов Георгий Витальевич";
			int birthyear1 = 2002;
			string address1 = "г. Санкт-Петербург ул. Передовиков 13 кв. 151.2б";
			clientTree clientAdd1(pasport1, placeAndDate1, FIO1, birthyear1, address1);
			MTree.addKlitnt(clientAdd1);

			string pasport6 = "3456-987654";
			string placeAndDate6 = "Екатеринбург 11.04.2015";
			string FIO6 = "Шлифер Роберт Александрович";
			int birthyear6 = 2001;
			string address6 = "Санкт-Петербург ул. Передовиков 13 кв. 120";
			clientTree clientAdd6(pasport6, placeAndDate6, FIO6, birthyear6, address6);
			MTree.addKlitnt(clientAdd6);


			string pasport2 = "2234-123456";
			string  placeAndDate2 = "Шахты 20.12.2016";
			string FIO2 = "Лысенко Денис Вячеславович";
			int birthyear2 = 2002;
			string address2 = "г. Воронеж пер. Строителей 22";
			clientTree clientAdd2(pasport2, placeAndDate2, FIO2, birthyear2, address2);
			MTree.addKlitnt(clientAdd2);



				string n = "123-1234567";
				string t = "полный";
				int v = 2022;
				bool b = false;
				SIM s(n, t, v, b);
				Table.addKeyHashTable(s);

				string n1 = "321-9876543";
				string t1 = "средний";
				int v1 = 2022;
				bool b1 = false;
				SIM s1(n1, t1, v1, b1);
				Table.addKeyHashTable(s1);

				string n2 = "543-1234567";
				string t2 = "минимальный";
				int v2 = 2022;
				bool b2 = false;
				SIM s2(n2, t2, v2, b2);
				Table.addKeyHashTable(s2);


				string n3 = "987-1111111";
				string t3 = "полный";
				int v3 = 2022;
				bool b3 = false;
				SIM s3(n3, t3, v3, b3);
				Table.addKeyHashTable(s3);

				string n4 = "222-2222222";
				string t4 = "полный";
				int v4 = 2022;
				bool b4 = false;
				SIM s4(n4, t4, v4, b4);
				Table.addKeyHashTable(s4);

		}
	}
}