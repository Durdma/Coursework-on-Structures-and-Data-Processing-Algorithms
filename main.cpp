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

//  ���������� ������ �����������
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
		cout << "\n |-----------------------����------------------------|\n";
		cout << " | 1.  ���������������� ������ �������               |" << endl;
		cout << " | 2.  ����� � ������������ �������                  |" << endl;
		cout << " | 3.  ����������� ���� ������������������ ��������  |" << endl;
		cout << " | 4.  �������� ��� ������ � ��������                |" << endl;
		cout << " | 5.  ����� ������� �� ��������                     |" << endl;
		cout << " | 6.  ����� ������� �� ��������� ��� ��� �������    |" << endl;
		cout << " | 7.  �������� ����� SIM-�����                      |" << endl;
		cout << " | 8.  ������� �������� � SIM-�����                  |" << endl;
		cout << " | 9.  ����������� ��� ��������� SIM-����            |" << endl;
		cout << " | 10. �������� ��� ������ � SIM-������              |" << endl;
		cout << " | 11. ����� SIM-����� �� ������ SIM-�����           |" << endl;
		cout << " | 12. ����� SIM-����� �� ������                     |" << endl;
		cout << " | 13. ���������������� ������ ������� SIM-�����     |" << endl;
		cout << " | 14. ���������������� ������� SIM-����� �� ������� |" << endl;
		cout << " | 15. �����                                         |" << endl;
		cout << " |---------------------------------------------------|" << endl<<endl;

		key = Chek.inputMenu();

		if (key == 1)
		{
			system("cls");
			cout << " ���������������� ������ �������\n" << endl;
			
			string pasport = Chek.inputPasport();

			if (MTree.checkPasport(pasport, MTree.root)) {
				cout << "������ � ����� ��������� ��� ����������." << endl;
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
			cout << " ������ � ������������ �������\n" << endl;
			string pas = Chek.inputPasport();

			cout << " ������� ���� �������� ������������ �������: ";
			string data = Chek.inputFullDate();

			cout << " ������ � ���������� �������: \n";
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
				cout << " � ���� ��������� � ������������ SIM �����: \n";
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
				cout << " � ������� ������� �� ���� �������� SIM ���� \n";
			}
			cout << "\n";
			system("pause");
		}

		if (key == 3) {
			system("cls");
			cout << " ����������� ���� ������������������ ��������\n" << endl;
			MTree.showKlient();
			cout << "\n";
			system("pause");
		}

		if (key == 4) {
			system("cls");
			cout << " ��� ������ � ������� �������. \n";
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
			cout << " ����� ������� �� ��������\n" << endl;
			string pasport = Chek.inputPasport();
			if (!MTree.checkPasport(pasport, MTree.root)) {
				cout << " ������ � ����� ��������� �� ����������" << endl;
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
					cout << " ��� ������ SIM �����: \n";
					for (int i = 0; i < MList.GetSize(); i++)
					{
						if (MList[i].pasport == pasport && MList[i].endSrok == "") {
							cout << " " << MList[i].nomerSim << endl;
						}
					}
				}
				else {
					cout << " � ������� ������� �� ���� �������� SIM ���� \n";
				}
			}
			cout << "\n";
			system("pause");
		}

		if (key == 6) {
			system("cls");
			cout << " ����� ������� �� ���������� ��� ��� ������\n" << endl;

			string str;
			cout << "\n ������� ����� ��� ��� ������� �������, �������� ������ �����: ";
			getline(cin, str);
			bool chek = false;
			MTree.findKlientOnString(MTree.root, str,chek);
			if (!chek) {
				cout << "\n ���������� �� ��������\n";
			}
			cout << "\n";
			system("pause");
		}

		if (key == 7) {
			system("cls");
			cout << " �������� ����� SIM-�����\n" << endl;

			string nomerSIM = Chek.inputSIM();

			if (!Table.chekSIM(nomerSIM)) {
				string tarif = Chek.inputTarifSIM();
				int vipusk = Chek.inputYear();
				SIM newSIM(nomerSIM, tarif, vipusk);
				Table.addKeyHashTable(newSIM);
			}
			else {
				cout << "\n ����� SIM ����� ��� ���������\n";
			}
			cout << "\n";
			system("pause");
		}


		if (key == 8) {
			system("cls");
			cout << " �������� �������� � SIM-�����\n" << endl;

			string nomerSIM = Chek.inputSIM();
			Table.deleteObject(nomerSIM);

			cout << " ������� ���� �������� SIM �����: ";
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
			cout << " ����������� ��� ���������� SIM-����\n" << endl;

			Table.printHashTable();
			cout << "\n";
			system("pause");
		}


		if (key == 10) {
			system("cls");
			cout << " �������� ��� ������ � SIM-������\n" << endl;

			Table.allDelete();

			cout << " ��� SIM ����� �������\n ";
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
			cout << " ����� SIM-����� �� ������ SIM-�����\n" << endl;

			string nomerSIM = Chek.inputSIM();
			SIM poisk = Table.searchObjectKey(nomerSIM);
			if (poisk.nomerSIM != "") {
				cout << setw(15) << " �����" << setw(15) << "�����" << setw(15) << "���" << setw(15) << "������" << '\n';
				string status = poisk.statusWork ? "������" : "��������";
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
					cout << " ������ SIM ����� �����������: \n" << endl;
					
					for (int i = 0; i < MList.GetSize(); i++)
					{
						if (MList[i].endSrok == "" && MList[i].nomerSim == nomerSIM)
						{
							MTree.findCustomer(MTree.root, MList[i].pasport);
						}
					}
				}
				else {
					cout << " ������ SIM ����� ������ �� ������ \n" << endl;
				}
				
			}
			cout << "\n";
			system("pause");
		}


		if (key == 12) {
			system("cls");
			cout << " ����� SIM-����� �� ������\n" << endl;

			string tarif = Chek.inputTarifSIM();
			Table.searchSimTarif(tarif);
			cout << "\n";
			system("pause");
		}


		if (key == 13) {
			system("cls");
			cout << " ���������������� ������ ������� SIM-�����\n" << endl;

			string pasport = Chek.inputPasport();
			if (!MTree.checkPasport(pasport, MTree.root)) {
				cout << " ������ � ����� ��������� �� ����������" << endl;
			}
			else {
				string nomerSIM = Chek.inputSIM();
				SIM poisk = Table.searchObjectKey(nomerSIM);
				if (poisk.nomerSIM != "") {
					if (poisk.statusWork == false) {
						cout << " ������� ���� ������ SIM �����: " ;
						string data = Chek.inputFullDate();
						listPeaple vip(pasport, nomerSIM, data);
						MList.push_back(vip);
						
						sortList(MList); // ������������� ������ �����������
						
						cout << " SIM ����� ������\n";
						Table.switchTarif(nomerSIM);
					}
					else {
						cout << " SIM ����� � ����� ������� ��� ���������������� �������" << endl;
					}
				}
			}
			cout << "\n";
			system("pause");
		}


		if (key == 14) {
			system("cls");
			cout << " ���������������� ������� SIM-����� �� �������\n" << endl;

			string pasport = Chek.inputPasport();
			if (!MTree.checkPasport(pasport, MTree.root)) {
				cout << " ������ � ����� ��������� �� ����������" << endl;
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
									cout << " ������� ���� �������� SIM �����: ";
									data = Chek.inputFullDate();
									
								} while (!Chek.chekDifferentDate(MList[i].vipusk, data));

								MList[i].endSrok = data;
								break;
							}
						}
						cout << " SIM ����� ����������\n";
						Table.switchTarif(nomerSIM);
					}
					else {
						cout << " SIM ����� � ����� ������� �� ���������������� �������" << endl;
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
			string  placeAndDate  = "������ 20.12.2016";
			string FIO = "������� ������ ����������";
			int birthyear = 2002;
			string address = "�. �����-��������� ��. ���������� 26";
			clientTree clientAdd(pasport, placeAndDate, FIO, birthyear, address);
			MTree.addKlitnt(clientAdd);
			
			
			string pasport1 = "1234-123456";
			string placeAndDate1 = "������-��-���� 20.12.2016";
			string FIO1 = "����� ������� ����������";
			int birthyear1 = 2002;
			string address1 = "�. �����-��������� ��. ����������� 13 ��. 151.2�";
			clientTree clientAdd1(pasport1, placeAndDate1, FIO1, birthyear1, address1);
			MTree.addKlitnt(clientAdd1);

			string pasport6 = "3456-987654";
			string placeAndDate6 = "������������ 11.04.2015";
			string FIO6 = "������ ������ �������������";
			int birthyear6 = 2001;
			string address6 = "�����-��������� ��. ����������� 13 ��. 120";
			clientTree clientAdd6(pasport6, placeAndDate6, FIO6, birthyear6, address6);
			MTree.addKlitnt(clientAdd6);


			string pasport2 = "2234-123456";
			string  placeAndDate2 = "����� 20.12.2016";
			string FIO2 = "������� ����� ������������";
			int birthyear2 = 2002;
			string address2 = "�. ������� ���. ���������� 22";
			clientTree clientAdd2(pasport2, placeAndDate2, FIO2, birthyear2, address2);
			MTree.addKlitnt(clientAdd2);



				string n = "123-1234567";
				string t = "������";
				int v = 2022;
				bool b = false;
				SIM s(n, t, v, b);
				Table.addKeyHashTable(s);

				string n1 = "321-9876543";
				string t1 = "�������";
				int v1 = 2022;
				bool b1 = false;
				SIM s1(n1, t1, v1, b1);
				Table.addKeyHashTable(s1);

				string n2 = "543-1234567";
				string t2 = "�����������";
				int v2 = 2022;
				bool b2 = false;
				SIM s2(n2, t2, v2, b2);
				Table.addKeyHashTable(s2);


				string n3 = "987-1111111";
				string t3 = "������";
				int v3 = 2022;
				bool b3 = false;
				SIM s3(n3, t3, v3, b3);
				Table.addKeyHashTable(s3);

				string n4 = "222-2222222";
				string t4 = "������";
				int v4 = 2022;
				bool b4 = false;
				SIM s4(n4, t4, v4, b4);
				Table.addKeyHashTable(s4);

		}
	}
}