//
// Created by root on 2016-05-13.
//
#include <iostream>
#include "DisjointSets.h"

// Create garbage and constructs one obj for caller
//DBG_status : tested
DisjointSets::DisjointSets(int size)
{
    this->unionSetsRankUsed=false;
    this->size = size;
    this->set = new int[this->size];
    for(int u=0; u < size;u++)
    {
        //-1 where minus illustrate root
        this->set[u]= -1;

    }
    DBG_print();

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
//check all sets at every index and returns longest path, works with Rank system.
//DBG_status : tested
int DisjointSets::maxHeight() const
{
    int height;
    int results =0; //only the highest value;
    int pathWalker=0; //walks until -1
    int indexWalker=0;
    int iteration=1;
    if(this->unionSetsRankUsed)
    {
        do {
            height = 0;
            while (this->set[pathWalker] > -1)
            {
                pathWalker = this->set[pathWalker];
            }
            //store only highest path
            if (this->set[pathWalker] < -1)
            {
                results = abs(this->set[pathWalker]) -1;
            }
            indexWalker++;
            pathWalker = iteration;
            iteration++;

        } while (indexWalker < this->size);
    }
    else
    {
        do
        {
            height = 0;
            while (this->set[pathWalker] != -1) {
                pathWalker = this->set[pathWalker];
                height++;
            }
            //store only highest path
            if (results < height) {
                results = height;
            }
            indexWalker++;
            pathWalker = iteration;
            iteration++;

        } while (indexWalker < this->size);
    }
    return results;

}
//merge sets
//DBG_status : works
void DisjointSets::unionSets(int root1, int root2)
{
    if(!this->unionSetsRankUsed)
    {
        if (find(root1) != find(root2) )
        {
            this->set[root2] = root1; //root1 becomes root for root2

        }
        DBG_print();
    }

}
// merge disjunctsets, however if one tree dose not have the same rank the height shall remain the same and the merge gets reversed.
//DBG_status : works
void DisjointSets::unionSetsRank(int root1, int root2)
{
    this->unionSetsRankUsed=true;
    //check if ranks are equal
    int a = this->set[root1];
    int b = this->set[root2];
    if(a == b)
    {
        this->set[root2] = root1; //root1 becomes root for root2
        this->set[root1]--; //root becomes lower
    }
    else
    {
        this->set[root1] = root2; //root2 becomes root for root1 but the root doesn't increase height nor rank.
    }
    DBG_print();
}
//find root for node and if necesery rearrange, but don't work on ranks
//DBG_status : tested
int DisjointSets::findCompress(int x)
{
    int holder = x; //reminds me of pointer :-)
    int numberOfRedirects=0;
    if(this->unionSetsRankUsed)
    {
        int tmp = holder;
        //find a root with some negative integer

        while (this->set[holder] > -1)
        {
            holder = this->set[holder];
        }
        //compress
        int BranchWalker= tmp;

        while (this->set[BranchWalker] > -1)
        {
            if( this->set[BranchWalker] != holder)
            {
                BranchWalker = this->set[tmp];
                this->set[tmp] = holder;
                numberOfRedirects++;
                tmp = BranchWalker;
            }
            else
                BranchWalker = this->set[tmp];//in the node before root we don't do any changes
        }
        //make root rank correct for each level decrement.
        for (int t = 0; t < numberOfRedirects;t++)
        {
            this->set[holder]++;
        }
        return holder;
    }
    else
    {
        //find root

        while (this->set[holder] != -1)
        {
            holder = this->set[holder];
        }
        //compress
        int BranchWalker = x;
        int tmp = BranchWalker;
        while (this->set[BranchWalker] != -1)
        {
            BranchWalker = this->set[tmp];
            this->set[tmp] = holder;
            tmp = BranchWalker;
        }
        return holder;
    }

}
