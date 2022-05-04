#pragma once
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <locale.h>
#include <string>
#include <regex>

using namespace std;

class ChelValue {

public:
	
	string inputBirthdayAndPlaces();
	string inputFullDate();
	string inputFIO();
	string inputPasport();
	string inputSIM();
	string inputArress();
	int inputYear();
	string inputTarifSIM();
	int inputMenu();
	
	string trimValue(const string& str);
	string nameCheck(string name);
	string pasportCheck(string pasport);
	int yearCheck(int year);
	string SIM_Check(string nomerSIM);
	
	bool chekDifferentDate(string, string);
};

