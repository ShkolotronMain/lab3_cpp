#include <iostream>
#include "classes.h"

using namespace std;

int main()
{
    int cnt;

    ifstream file;
    file.open("data.txt");
    file >> cnt;

    Course* stock = new Course[cnt];

    for (int i=0; i<cnt; i++)
        stock[i].read_from_file(file);

    file.close();

    Printer prt = Printer(stock, cnt);
    prt.print_stock();

    prt.print_exp_usd();

    for (int i=0; i<cnt; i++)
        stock[i].write_to_file("wrt.txt", 't');

    delete[] stock;

    return 0;
}