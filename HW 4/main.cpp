#include <iostream>
#include "singleton.h"
using namespace std;

int main()
{
    Single* Single1 = Single::getInstance();
        Single* Single2 = Single::getInstance();

        if (Single1 == Single2)
            fprintf(stderr,"Single1 = Single2\n");

        return 0;
    return 0;
}
