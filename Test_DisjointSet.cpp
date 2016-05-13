//made by R.L.B.

#include <iostream>
#include "DisjointSets.h"
#include <random>
using namespace std;

int main()
{
    //srand(2);
    cout<<"init data\n 0  1  2  3  4  5  6  7  8  9 "<<endl;
    DisjointSets myObj(10);
    cout<<"\nunion(0,1) data"<<endl;
    myObj.unionSets(0,1);
    cout<<"\nunion(2,9) data"<<endl;
    myObj.unionSets(2,9);
    cout<<"\nunion(0,2) data"<<endl;
    myObj.unionSets(0,2);
    cout<<"\nunionRank(3,0) data"<<endl<<" ";
    myObj.unionSets(3,0);

    cout<<"\nmax height "<< myObj.maxHeight();

    cout<<"\nNow we use findcompress(9) returns 0 and makes the tree height one level lower, findcomp():  "<< myObj.findCompress(9);
    cout<<"\n Height: "<< myObj.maxHeight();
    cout<<"\n content: \n";
    myObj.DBG_print();
    cout<<"\nnodes\n 0  1  2  3  4  5  6  7  8  9 "<<endl;
    cout<<"----------------\nrun compress again"<<myObj.findCompress(1);
    cout<<"\n Height: "<< myObj.maxHeight();
    cout<<"\n content: \n";
    myObj.DBG_print();
    cout<<" ";
    cout<<"\n rest is junk"<<endl;
    DisjointSets set1 = myObj;
    DisjointSets copyObj(2), copyObj2(100);
    copyObj = copyObj2 = set1;
    cout << "\nExiting!\n" << endl;
    return 0;
}