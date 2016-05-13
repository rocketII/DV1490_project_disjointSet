//
// Created by root on 2016-05-13.
//
#include "DisjointSets.h"
#include <random>

DisjointSets::DisjointSets(int size)
{
    srand(2);
    this->size = size;
    this->set = new int[this->size];
    for(int u=0; u < size;u++)
    {
        //-1 where minus illustrate root
        this->set[u]= -1;
    }


}

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
//DBG_status :
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
