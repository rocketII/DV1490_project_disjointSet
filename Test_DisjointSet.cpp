//made by R.L.B.
/*
 *
        I en annan fil innehållande main-funktionen implementerar du testet. Här skapar du 4

        objekt av typen DisjointSets så att du har olika objekt för var och en av de kombinationer av

        find och union som ska undersökas. Definiera en konstant för antalet element (var och ett i

        en egen mängd vid initialiseringen) vilken sätts till 10000.

        Operationen union ska utföras 5000 gånger där mängderna slumpas fram. Det måste vara

        identiska mängder för alla 4 objekten.

        Testerna ska upprepas 100 gånger och medelvärdet av maxhöjden på träden för respektive

        DisjontSet-objekt ska beräknas (använd funktionen maxHeight()). Resultaten ska

        presenteras i en tabell med 2 rader (union utan och med rank) och 2 kolumner (find utan

        och med komprimering).

        Tips! Gör union på returerna av find(...) resp findCompress(...) då dessa visat att två
        disjunkta mängder identifierats.
 * */
#include <iostream>
#include "DisjointSets.h"
#include <random>
using namespace std;

int main()
{
    /*  find = S findCompress=D  Union=F UnionRank=G
     *  testing1(sets), testing2(sets),testing3(sets),testing4(sets);
     *   F,S               F,D            G,S           G,D
     *
     */
    const int sets = 10000;
    float average1,average2, average3, average4;
    int randomHolderA,randomHolderB;
    srand(2);
    int counter;
    DisjointSets testing1(sets), testing2(sets),testing3(sets),testing4(sets);
    for (int j = 0; j < 100 ; ++j)
    {
        for (int i = 0; i < 5000 ; ++i)
        {
            while (testing1.find(randomHolderA) == testing1.find(randomHolderB))
            {
                randomHolderA = rand() % 1000;
                randomHolderB = rand() % 1000;
            }
            testing1.unionSets(randomHolderA, randomHolderB);

        }
    }
    cout << "\nExiting!\n" << endl;
    return 0;
}