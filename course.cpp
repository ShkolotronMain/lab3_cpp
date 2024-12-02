#include <iostream>
#include "classes.h"

void Course::print()
{
    cout << "===================" << endl;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << currency << endl;
    cout << state << endl;
    cout << code << endl;
    cout << "1 " + code + " = " << rate << endl;
    cout << "===================" << endl;
}

void Course::read_from_file(ifstream& fp)
{
    string trash;
    getline(fp, trash);

    getline(fp, currency);
    getline(fp, state);
    getline(fp, code);
    getline(fp, subunit);
    fp >> fraction;
    fp >> rate;
}

void Course::read_from_console()
{
    cout << "Введите название валюты:" << endl;
    getline(cin, currency);
    cout << "Введите государство:" << endl;
    getline(cin, state);
    cout << "Введите код валюты:" << endl;
    getline(cin, code);
    cout << "Введите название разменной валюты:" << endl;
    getline(cin, subunit);
    cout << "Сколько разменной валюты в основной:" << endl;
    cin >> fraction;
    cout << "Введите курс валюты к российскому рублю:" << endl;
    cin >> rate;   
}

void Course::write_to_file(string path, char mode)
{
    switch (mode)
    {
    case 't':
        write_to_txt(path);
        break;

    case 'b':
        write_to_bin(path);
        break;
    
    default:
        cout << "Неверно указан режим, файл записан не будет" << endl;
        break;
    }
}

void Course::write_to_txt(string path)
{
    ofstream wt;
    wt.open(path, ios_base::app);
    
    wt << currency << endl;
    wt << state << endl;
    wt << code << endl;
    wt << subunit << endl;
    wt << fraction << endl;
    wt << rate << endl;

    wt.close();
}

void Course::write_to_bin(string path)
{
    ofstream wb;
    wb.open(path, ios_base::app | ios_base::binary);

    wb << currency << endl;
    wb << state << endl;
    wb << code << endl;
    wb << subunit << endl;
    wb << fraction << endl;
    wb << rate << endl;

    wb.close();
}

string Course::get_code()
{
    return code;
}

double Course::get_rate()
{
    return this->rate;
}

Course::Course()
{

}
