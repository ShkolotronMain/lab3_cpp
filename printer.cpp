#include "classes.h"
#include <iostream>

void Printer::print_stock()
{
    for (int i=0; i<cnt; i++)
        stock[i].print();
}

Printer::Printer(Course* mas, int c)
{
    stock = mas;
    cnt = c;
}

void Printer::print_exp_usd()
{
    Course usd = {};
    bool usd_exists = 0;

    std::cout << "Стоят дороже доллара:" << endl;

    for (int i=0; i<cnt && usd_exists==0; i++)
        if (stock[i].get_code().compare("USD") == 0)
        {
            usd = stock[i];
            usd_exists = 1;
        }

    if (usd_exists==1)
    {
        for (int i=0; i<cnt; i++)
            if (diff(usd, stock[i]) < 0)
            {
                stock[i].print();
                cout << endl;
            }
    }
    else
        std::cout << "\tДоллара в выборке нет, сравнение невозможно" << endl;
}

double Printer::diff(Course left, Course right)
{
    return (left.get_rate() - right.get_rate());
}
