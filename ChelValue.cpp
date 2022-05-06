#include "ChelValue.h"

string ChelValue::trimValue(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}




string ChelValue::pasportCheck(string pasport) {
    regex regPasport("([0-9]{4})([\\-]{1})([0-9]{6})");
    pasport = trimValue(pasport);
    while (cin.fail() || ((regex_match(pasport, regPasport) == false))) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail(), '\n');
        cout << " Неверно!" << endl;
        cout << " Введите серию и номер паспорта заново в формате (NNNN-NNNNNN):" << endl;
        getline(cin, pasport);
        pasport = trimValue(pasport);
    }
    return pasport;
}


int ChelValue::yearCheck(int year) {
    while (cin.fail()) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail(), '\n');
        cout << " Неверно!" << endl;
        cout << " Введите год заново: " << endl;
        cin >> year;
    }
    return year;
}



string ChelValue::SIM_Check(string nomerSIM) {
    regex regNomerSIM("([0-9]{3})[-]([0-9]{7})");
    nomerSIM = trimValue(nomerSIM);
    while (cin.fail() || ((regex_match(nomerSIM, regNomerSIM) == false))) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail(), '\n');
        cout << " Неверно!" << endl;
        cout << " Введите номер SIM карты заново в формате (NNN-NNNNNNN): " << endl;
        getline(cin, nomerSIM);
        nomerSIM = trimValue(nomerSIM);
    }
    return nomerSIM;
}



string ChelValue::inputBirthdayAndPlaces() {
    regex regular("([абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ\\-\\s]{0,45})");
    string place;
    cmatch result2;
    cout << "\n Введите место выдачи паспота: ";
    getline(cin, place);
    regex_match(place.c_str(), result2, regular);


    while (!regex_match(place.c_str(), result2, regular)) {
        cout << "\n Неверный ввод.\n Попробуйте заново введите место выдачи паспота: ";
        getline(cin, place);
    }


    regex regDATA("([0-9]{1,2})(\\.)([0-9]{1,2})(\\.)([0-9]{1,4})");

    string birthdayDate;
    cmatch result;
    cout << "\n Введите дату выдачи паспорта в формате (dd.mm.yy): ";
    getline(cin, birthdayDate);
    regex_match(birthdayDate.c_str(), result, regDATA);

    while (!regex_match(birthdayDate.c_str(), result, regDATA) || (stoi(result[1]) > 31 && stoi(result[3]) == 12) ||
        (stoi(result[1]) > 30 && stoi(result[3]) == 11) || (stoi(result[1]) > 31 && stoi(result[3]) == 10) ||
        (stoi(result[1]) > 30 && stoi(result[3]) == 9) || (stoi(result[1]) > 31 && stoi(result[3]) == 8) ||
        (stoi(result[1]) > 31 && stoi(result[3]) == 7) || (stoi(result[1]) > 30 && stoi(result[3]) == 6) ||
        (stoi(result[1]) > 31 && stoi(result[3]) == 5) || (stoi(result[1]) > 30 && stoi(result[3]) == 4) ||
        (stoi(result[1]) > 31 && stoi(result[3]) == 3) || (stoi(result[1]) > 31 && stoi(result[3]) == 1) ||
        stoi(result[1]) == 0 || stoi(result[3]) > 12 || stoi(result[3]) == 0 || (((stoi(result[5]) % 4 == 0) ||
            (stoi(result[5]) % 100 == 0 && stoi(result[5]) % 400)) && stoi(result[3]) == 2 && stoi(result[1]) > 29) ||
        (!((stoi(result[5]) % 4 == 0) || (stoi(result[5]) % 100 == 0 && stoi(result[5]) % 400)) && stoi(result[3]) == 2 && stoi(result[1]) > 28)) {
        cout << " Неверный ввод. Попробуйте заново ввести дату выдачи паспорта в формате (dd.mm.yy): ";
        getline(cin, birthdayDate);
    }

    birthdayDate = place + " " + birthdayDate;

    return birthdayDate;
}


string ChelValue::inputFullDate() {
    //  РЕГУЛЯРНОЕ ВЫРАЖЕНИЕ ДЛЯ ДАТЫ
    regex regDATA("([0-9]{1,2})(\\.)([0-9]{1,2})(\\.)([0-9]{1,4})");

    string birthdayDate;
    cmatch result;
    cout << "\n Введите дату в формате (dd.mm.yy): ";
    getline(cin, birthdayDate);
    regex_match(birthdayDate.c_str(), result, regDATA);

    while (!regex_match(birthdayDate.c_str(), result, regDATA) || (stoi(result[1]) > 31 && stoi(result[3]) == 12) ||
        (stoi(result[1]) > 30 && stoi(result[3]) == 11) || (stoi(result[1]) > 31 && stoi(result[3]) == 10) ||
        (stoi(result[1]) > 30 && stoi(result[3]) == 9) || (stoi(result[1]) > 31 && stoi(result[3]) == 8) ||
        (stoi(result[1]) > 31 && stoi(result[3]) == 7) || (stoi(result[1]) > 30 && stoi(result[3]) == 6) ||
        (stoi(result[1]) > 31 && stoi(result[3]) == 5) || (stoi(result[1]) > 30 && stoi(result[3]) == 4) ||
        (stoi(result[1]) > 31 && stoi(result[3]) == 3) || (stoi(result[1]) > 31 && stoi(result[3]) == 1) ||
        stoi(result[1]) == 0 || stoi(result[3]) > 12 || stoi(result[3]) == 0 || (((stoi(result[5]) % 4 == 0) ||
            (stoi(result[5]) % 100 == 0 && stoi(result[5]) % 400)) && stoi(result[3]) == 2 && stoi(result[1]) > 29) ||
        (!((stoi(result[5]) % 4 == 0) || (stoi(result[5]) % 100 == 0 && stoi(result[5]) % 400)) && stoi(result[3]) == 2 && stoi(result[1]) > 28)) {
        cout << " Неверный ввод. Попробуйте заново ввести дату в формате (dd.mm.yy): ";
        getline(cin, birthdayDate);
    }
    return birthdayDate;
}


bool ChelValue::chekDifferentDate(string dateFirs, string dateLast) {
    //  РЕГУЛЯРНОЕ ВЫРАЖЕНИЕ ДЛЯ ДАТЫ
    regex regDATA("([0-9]{1,2})(\\.)([0-9]{1,2})(\\.)([0-9]{1,4})");

    cmatch result1;
    cmatch result2;
    regex_match(dateFirs.c_str(), result1, regDATA);
    regex_match(dateLast.c_str(), result2, regDATA);

    if (stoi((string)result2[5]) > stoi((string)result1[5])) {
        return true;
    }
    else if (stoi((string)result2[5]) == stoi((string)result1[5])) {
        if (stoi((string)result2[3]) > stoi((string)result1[3])) {
            return true;
        }
        else if (stoi((string)result2[3]) == stoi((string)result1[3])) {
            if (stoi((string)result2[1]) > stoi((string)result1[1])) {
                return true;
            }
            else if (stoi((string)result2[1]) == stoi((string)result1[1])) {
                cout << "\n Дата выдачи должна быть позже даты возврата SIM карты\n";
                return false;
            }
            else {
                cout << "\n Дата выдачи должна быть позже даты возврата SIM карты\n";
                return false;
            }
        }
        else {
            cout << "\n Дата выдачи должна быть позже даты возврата SIM карты\n";
            return false;
        }
    }
    else {
        cout << "\n Дата выдачи должна быть позже даты возврата SIM карты\n";
        return false;
    }
}

string ChelValue::nameCheck(string name) {
    regex regFIO("([А-Я])([а-я]{0,45})([\\s])(([А-Я])[а-я]{0,45})([\\s])(([А-Я])[а-я]{0,45})");
    name = trimValue(name);
    while (cin.fail() || ((regex_match(name, regFIO) == false))) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail(), '\n');
        cout << " Неверно!" << endl;
        cout << " Введите ФИО заново:" << endl;
        getline(cin, name);
        name = trimValue(name);
    }
    return name;
}



string ChelValue::inputFIO() {
    string name;
    cout << "\n Введите ФИО в формате (Фамилия Имя Отчество): ";
    getline(cin, name);
    name = nameCheck(name);
    return name;
}


string ChelValue::inputPasport() {
    string pasport;
    cout << "\n Введите паспорт в формате (NNNN-NNNNNN): ";
    getline(cin, pasport);
    pasport = pasportCheck(pasport);
    return pasport;
}


string ChelValue::inputSIM() {
    string SIM;
    cout << "\n Введите SIM в формате (NNN-NNNNNNN): ";
    getline(cin, SIM);
    SIM = SIM_Check(SIM);
    return SIM;
}


int ChelValue::inputYear() {
    string year;
    cout << "\n Введите год: ";
    getline(cin, year);

    return yearCheck(stoi(year));
}


string ChelValue::inputArress() {
    string adres;
    cout << "\n Введите адресс проживания: ";
    getline(cin, adres);
    adres = trimValue(adres);
    return adres;
}

string ChelValue::inputTarifSIM() {
    string tarif;
    cout << "\n Введите название тарифа (минимальный, средний, полный): ";
    getline(cin, tarif);

    while (cin.fail() || (tarif != "минимальный" && tarif != "средний" && tarif != "полный")) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail(), '\n');
        cout << " Неверно!" << endl;
        cout << " Введите тариф заново (минимальный, средний, полный):" << endl;
        getline(cin, tarif);
        tarif = trimValue(tarif);
    }

    return tarif;
}


int ChelValue::inputMenu() {
    string itog;
    cout << " номер пункта меню: ";
    getline(cin, itog);

    while (cin.fail() || stoi(itog) <= 0 || stoi(itog) > 16) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail(), '\n');
        cout << " номер пункта меню заново (число от 1 до 15): ";
        getline(cin, itog);
    }
    return stoi(itog);
}



