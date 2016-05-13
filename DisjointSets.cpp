//
// Created by root on 2016-05-13.
//
#include "DisjointSets.h"

DisjointSets::DisjointSets(int size)
{
    this->size = size;
    this->set = new int[this->size];

}

DisjointSets::~DisjointSets()
{
    delete []  this->set;
}

int DisjointSets::find(int x) const
{
    return x;
}
