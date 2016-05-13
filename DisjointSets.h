#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

using namespace std;

class DisjointSets
{
private:
	int* set;
	int size;
	bool unionSetsRankUsed;
public:
	DisjointSets(int size);
	DisjointSets(const DisjointSets &orig);
	virtual ~DisjointSets();
	DisjointSets& operator=(const DisjointSets &orig);
	int find(int x) const;
	int findCompress(int x);
	void unionSets(int root1, int root2);
	void unionSetsRank(int root1, int root2);
	int maxHeight() const;

};

#endif