//
// Created by root on 2016-05-13.
//
#include <iostream>
#include "DisjointSets.h"

// Create garbage and constructs one obj for caller
//DBG_status : tested
DisjointSets::DisjointSets(int size)
{

    this->size = size;
    this->set = new int[this->size];
    for(int u=0; u < size;u++)
    {
        //-1 where minus illustrate root
        this->set[u]= -1;
        //DBG printing.
        cout <<" "<< this->set[u];
    }


}
//collect garbage
//DBG_status : tested
DisjointSets::~DisjointSets()
{
    delete []  this->set;
}
//find root for value node in set.
//DBG_status: works
int DisjointSets::find(int x) const
{
    int holder = x;
    while(this->set[holder] != -1)
    {
        holder = this->set[holder];
    }
    return holder;
}
//check all sets at every index and returns longest path
//DBG_status : tested
int DisjointSets::maxHeight() const
{
    int height;
    int results =0; //only the highest value;
    int pathWalker=0; //walks until -1
    int indexWalker=0;
    int iteration=1;
    do
    {
        height=0;
        while( this->set[pathWalker] != -1)
        {
               pathWalker= this->set[pathWalker];
               height++;
        }
        //store only highest path
        if(results < height)
        {
            results = height;
        }
        indexWalker++;
        pathWalker= iteration;
        iteration++;

    }while (indexWalker < this->size);
    return results;

}
//check all sets at every index and returns longest path
//DBG_status : combine roots from different
void DisjointSets::unionSets(int root1, int root2)
{
    this->set[root2]=root1; //root1 becomes root for root2
    //DBG printing.
    for(int u=0; u < size;u++)
    {

        cout <<" "<< this->set[u];
    }

}
