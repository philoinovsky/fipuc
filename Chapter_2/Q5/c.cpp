// c. test three
#include <stdio.h>
#include <iostream>
#include <memory>
using namespace std;

struct deleter
{
    void operator() (FILE* fp)
    {
        fclose(fp);
    }
};

void free_function()
{
    unique_ptr<FILE, decltype(&fclose)> fp(fopen("file.txt", "r"), fclose);
    char buf[30];
    fgets(buf, 30, fp.get());
    cout << buf << endl;
}

void function_object()
{
    shared_ptr<FILE> fp(fopen("file.txt", "r"), deleter());
    char buf[30];
    fgets(buf, 30, fp.get());
    cout << buf << endl;
}

void lambda_function()
{
    auto deleter = [] (FILE* fp) {
        fclose(fp);
    };
    unique_ptr<FILE, decltype(deleter)> fp(fopen("file.txt", "r"), deleter);
    char buf[30];
    fgets(buf, 30, fp.get());
    cout << buf << endl;
}

int main()
{
    free_function();
    function_object();
    lambda_function();
    return 0;
}