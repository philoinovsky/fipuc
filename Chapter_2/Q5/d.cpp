// d. catch the error and open the file again, does it work?
// - ans: why not?
#include <stdio.h>
#include <iostream>
#include <memory>
using namespace std;

int main()
{
    shared_ptr<FILE> fp(fopen("file.txt", "r"), &fclose);
    char buf[30];
    fgets(buf, 30, fp.get());
    cout << buf << endl;
    try
    {
        throw 1;
    }
    catch (int e)
    {

    };
    shared_ptr<FILE> fpp(fopen("file.txt", "r"), &fclose);
    cout << fp.use_count() << endl;
    return 0;
}