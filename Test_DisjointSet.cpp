//made by R.L.B.

#include <iostream>
#include "DisjointSets.h"
using namespace std;

int main()
{
    DisjointSets myObj(6);

    cout <<"förväntar mig max höjd för ett av träden i skogen är, 1, fick resultat: "<< myObj.maxHeight() ;
    cout << "\nExiting!\n" << endl;
    return 0;
}