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
        //-1 where minus illustrate root.
        this->set[u]= -1;

    }


}
//collect garbage
//DBG_status : tested
DisjointSets::~DisjointSets()
{
    delete []  this->set;
}
//find root for value node in set.handles ranked trees.
//DBG_status: works, edited while loop 16/5.
int DisjointSets::find(int x) const
{
    if( this->set[ x ] < 0 )
        return x;
    else
        return find( this->set[ x ] );


}
//check all sets at every index and returns longest path, works with Rank system.
//fixcode: 0x44
/* 0x44:       maxheight verkar onödigt omständiga. För att bestämma max-höjden för de träd som representerar
               mängderna ska du för varje nod bestämma dess djup (dvs hur långt från roten den är) och den nod
               som har högst djup motsvarar det träd som är högst. Du ska inte använda de uppskattade
               höjderna/rankerna utan vekrligen kontrollera djupen för noderna.
 */
int DisjointSets::maxHeight() const
{
    int height;
    int results =0; //only the highest value;
    int pathWalker=0; //walks until -1
    int indexWalker=0;
    int iteration=1;
    //index   0  1  2  3  4 5 6  7
    //content 3 -1  1  2 -1 7 4  6
    do
    {
        height = 0;
        while (this->set[pathWalker] > -1)
        {
            pathWalker = this->set[pathWalker];
            height++;
        }
        //store only highest path
        if (results < height)
        {
            results = height;
        }
        indexWalker++;
        pathWalker = iteration;
        iteration++;

    } while (indexWalker < this->size);
    return results;
    //obsolete code below...
    /*if(this->unionSetsRankUsed)
    {
        do
        {
            height = 0;
            while (this->set[pathWalker] > -1)
            {
                pathWalker = this->set[pathWalker];
            }
            //if root less than -1 we encode rank to height
            if (this->set[pathWalker] < -1)
            {
                if(results < (abs(this->set[pathWalker]) - 1) )
                    results = (abs(this->set[pathWalker]) - 1);
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
            while (this->set[pathWalker] != -1)
            {
                pathWalker = this->set[pathWalker];
                height++;
            }
            //store only highest path
            if (results < height)
            {
                results = height;
            }
            indexWalker++;
            pathWalker = iteration;
            iteration++;

        } while (indexWalker < this->size);
    }*/


}
//merge sets, only insert roots that are from diff.
//DBG_status : works
void DisjointSets::unionSets(int root1, int root2)
{
    if(!this->unionSetsRankUsed)
    {
        this->set[root2] = root1; //root1 becomes root for root2
    }

}
// merge disjunctsets, however if one tree dose not have the same rank the height shall remain the same and the merge gets fixed so small rank join big rank.
// The following generate issues,  this->set[sameRoot] = sameRoot or/and  this->set[root] = number followed by this->set[number] = root;
//DBG_status : works
void DisjointSets::unionSetsRank(int root1, int root2)
{
    this->unionSetsRankUsed=true;
    //check if ranks are equal
    int rankA = this->set[root1];
    int rankB = this->set[root2];
    if((rankA < 0) && (rankB < 0))
    {
        if (rankA == rankB)
        {
            this->set[root2] = root1; //root1 becomes root for root2
            this->set[root1]--; //root becomes lower
        }
        else if(rankA > rankB)
        {
            this->set[root2] = root1;
        }
        else if( rankA < rankB)
        {
            this->set[root1] = root2;
        }
    }

}
//find root for node and if necesery rearrange, but don't work on ranks
//fixcode: 0x33
int DisjointSets::findCompress(int x)
{
    if( this->set[ x ] < 0 )
        return x;
    else
        return this->set[ x ] = findCompress( this->set[ x ] );
    //x some node.
    /*int holder = x; //reminds me of the pointer :-)
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
        // trash data: (this->set[holder] != -1 && this->set[holder] >0)
        while (this->set[holder] > -1)
        {
            holder = this->set[holder];
        }
        //compress
        int BranchWalker = x;
        int tmp = BranchWalker;
        while (this->set[BranchWalker] > -1)
        {
            BranchWalker = this->set[tmp];
            this->set[tmp] = holder;
            tmp = BranchWalker;
        }
        return holder;
    }*/

}
//CopyConstructor
//DBG_status : tested
DisjointSets::DisjointSets(const DisjointSets &orig)
{
    this->size = orig.size;
    this->set = new int[this->size];
    //or this->set = orig.set
    for (int i = 0; i < this->size; ++i)
    {
        this->set[i] = orig.set[i];
    }
    this->unionSetsRankUsed = orig.unionSetsRankUsed;

}
//operator=
//DBG_status : tested
DisjointSets& DisjointSets::operator=(const DisjointSets &orig)
{
    this->unionSetsRankUsed = orig.unionSetsRankUsed;
    this->size = orig.size;
    delete[] this->set;
    this->set = new int[this->size];
    for (int i = 0; i < this->size ; ++i)
    {
        this->set[i] = orig.set[i];
    }
    return *this;//return reference
}
