// b. lambda
#include <stdio.h>
#include <iostream>
#include <memory>

using namespace std;

int main()
{
    auto deleter = [] (FILE* fp) {
        fclose(fp);
    };
    unique_ptr<FILE, decltype(deleter)> fp(fopen("file.txt", "r"), deleter);
    char buf[30];
    fgets(buf, 30, fp.get());
    cout << buf << endl;
    return 0;
}