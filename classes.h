#include <string>
#include <fstream>

using namespace std;

#ifndef course
#define course

class Course
{
    private:
        string currency;
        string state;
        string code;
        string subunit;
        int fraction;
        double rate;

        void write_to_txt(string path);
        void write_to_bin(string path);

    public:
        Course();

        void read_from_file(ifstream& fp);
        void read_from_console();

        void print();
        void write_to_file(string path, char mode);

        string get_code();
        double get_rate();
};

class Printer
{
    private:
        Course* stock;
        int cnt;
        double diff(Course left, Course right);

    public:
        void print_stock();
        void print_exp_usd();
        Printer(Course*, int);
};

#endif