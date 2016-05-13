//made by R.L.B.

#include <iostream>
#include "DisjointSets.h"
#include <random>
using namespace std;

int main()
{
    srand(2);
    cout<<"init data"<<endl;
    DisjointSets myObj(10);
    cout<<"\nunion(0,1) data"<<endl;
    myObj.unionSets(0,1);
    cout<<"\nunion(2,9) data"<<endl;
    myObj.unionSets(2,9);
    cout<<"\nunion(0,2) data"<<endl;
    myObj.unionSets(0,2);
    cout<<"\nunion(3,0) data"<<endl;
    myObj.unionSets(3,0);
    cout << "\nExiting!\n" << endl;
    cout<<"max height "<< myObj.maxHeight();
    cout<<" ";
    return 0;
}