// a. custom deleter
#include <stdio.h>
#include <iostream>
#include <memory>

using namespace std;

void native_function()
{
    unique_ptr<FILE, decltype(&fclose)> fp(fopen("file.txt", "r"), fclose);
    char buf[30];
    fgets(buf, 30, fp.get());
    cout << buf << endl;
}

struct deleter
{
    void operator() (FILE* fp)
    {
        fclose(fp);
    }
};

void custom_deleter()
{
    shared_ptr<FILE> fp(fopen("file.txt", "r"), deleter());
    char buf[30];
    fgets(buf, 30, fp.get());
    cout << buf << endl;
}

int main()
{
    custom_deleter();
    return 0;
}