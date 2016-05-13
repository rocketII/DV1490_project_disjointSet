//made by R.L.B.

#include <iostream>
#include "DisjointSets.h"
#include <random>
using namespace std;

int main()
{
    srand(2);
    cout<<"init data\n 0  1  2  3  4  5  6  7  8  9 "<<endl;
    DisjointSets myObj(10);
    cout<<"\nunionRank(0,1) data"<<endl;
    myObj.unionSetsRank(0,1);
    cout<<"\nunionRank(2,9) data"<<endl;
    myObj.unionSetsRank(2,9);
    cout<<"\nunionRank(0,2) data"<<endl;
    myObj.unionSetsRank(0,2);
    cout<<"\nunionRank(3,0) data"<<endl<<" ";
    myObj.unionSetsRank(3,0);
    cout << "\nExiting!\n" << endl;
    cout<<"max height "<< myObj.maxHeight();
    cout<<" ";
    return 0;
}