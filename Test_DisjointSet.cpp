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

    cout<<"\nmax height "<< myObj.maxHeight();

    cout<<"\nNow we use findcompress(9) returns 0 and makes the tree height one level lower, findcomp():  "<< myObj.findCompress(9);
    cout<<"\n Height: "<< myObj.maxHeight();
    cout<<"\n content: \n";
    myObj.DBG_print();
    cout<<"\ninit data\n 0  1  2  3  4  5  6  7  8  9 "<<endl;

    cout << "\nExiting!\n" << endl;
    return 0;
}