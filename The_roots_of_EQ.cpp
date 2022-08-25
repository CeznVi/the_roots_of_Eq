#include <iostream>
#include <Windows.h>
#include "rootsEQ.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    //покажчик базового класу
    Equation* p;

    EqLine l;
    EqQuad q;

    //Лінійні рівняння
    p = &l;
    p->Solution();
    cout << '\n';

    //Квадратні рівняння
    p = &q;
    p->Solution();
    cout << '\n';


    return 0;
}
