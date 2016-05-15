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

        kontroll:
        Har du kollat att du skapa nya mängder för varje nytt försök (de 100 som ska göras totalt)?

        Kontrollera dessutom att du gör union på rötter i träden, dvs på resultaten vid find,
        dvs om du gör root1 = set.find(x) och root2 = set.find(y)
        där x och y är slumpade värden ska du göra union på root1 och root2 om de är olika.
 * */
#include <iostream>
#include "DisjointSets.h"
#include <random>
#include <ctime>
using namespace std;

int main()
{
    /*  find = S findCompress=D  Union=F UnionRank=G
     *  testing1(sets), testing2(sets),testing3(sets),testing4(sets);
     *   F,S               F,D            G,S           G,D
     *
     */
    int a1=220,a2=220,b1=220,b2=220,c1=220,c2=220,d1=220,d2=220; //dbg symbols
    const int sets = 10;
    float average1=0,average2=0, average3=0, average4=0;
    int randomRootCandidateHolderA, randomRootCandidateHolderB;
    std::srand(std::time(0));
    bool flag =false;
    DisjointSets testing1(sets), testing2(sets),testing3(sets),testing4(sets);
    for (int j = 0; j < 100; ++j) //loop test 100 times
    {
        for (int i = 0; i < (sets/2) ; ++i) // loop set generator
        {
            //dbg
            bool a = (a1 == a2);
            bool b = (b1 == b2);
            bool c = (c1 == c2);
            bool d = (d1 == d2);
            ;
            // end dbg
            randomRootCandidateHolderA = rand() % sets;
            randomRootCandidateHolderB = rand() % sets;//counter=0;
            a1 = testing1.find(randomRootCandidateHolderA);
            a2 = testing1.find(randomRootCandidateHolderB);
            b1=testing2.findCompress(randomRootCandidateHolderA);
            b2=testing2.findCompress(randomRootCandidateHolderB);
            c1=testing3.find(randomRootCandidateHolderA);
            c2=testing3.find(randomRootCandidateHolderB);
            d1=testing4.findCompress(randomRootCandidateHolderA);
            d2=testing4.findCompress(randomRootCandidateHolderB);



            while (((a1 == a2) || (b1 == b2) || (c1 == c2) ||(d1==d2) ))
            {
                //dbg
                a = (a1 == a2);
                b = (b1 == b2);
                c = (c1 == c2);
                d = (d1 == d2);
                // end dbg

                randomRootCandidateHolderA = rand() % sets;
                randomRootCandidateHolderB = rand() % sets;
                bool dbgDiff = (randomRootCandidateHolderA != randomRootCandidateHolderB);
                if (randomRootCandidateHolderA != randomRootCandidateHolderB)
                {
                    a1 = testing1.find(randomRootCandidateHolderA);
                    a2 = testing1.find(randomRootCandidateHolderB);
                    b1 = testing2.findCompress(randomRootCandidateHolderA);
                    b2 = testing2.findCompress(randomRootCandidateHolderB);
                    c1 = testing3.find(randomRootCandidateHolderA);
                    c2 = testing3.find(randomRootCandidateHolderB);
                    d1 = testing4.findCompress(randomRootCandidateHolderA);
                    d2 = testing4.findCompress(randomRootCandidateHolderB);
                }
            }


            //make sure only roots from different trees are used below.
            testing1.unionSets(randomRootCandidateHolderA, randomRootCandidateHolderB);
            testing2.unionSets(randomRootCandidateHolderA, randomRootCandidateHolderB);
            testing3.unionSetsRank(randomRootCandidateHolderA, randomRootCandidateHolderB);
            testing4.unionSetsRank(randomRootCandidateHolderA, randomRootCandidateHolderB);



        }
        //collect 100 times
        average1+=testing1.maxHeight();
        average2+=testing2.maxHeight();
        average3+=testing3.maxHeight();
        average4+=testing4.maxHeight();
    }
    //calc average height for all the tall trees in the forests.
    average1=average1/100 + (int)average1 % 100;
    average2=average2/100 + (int)average2 % 100;
    average3=average3/100 + (int)average3 % 100;
    average4=average4/100 + (int)average4 % 100;
    cout<<"\n==========================&\\*Results*/&======================\n";
    cout<<"          ||  Find utan Komprimering || Find med komprimering ||";
    cout<<"\n-------------------------------------------------------------";
    cout<<"\n union    ||  "<< average1  << "                       || "<<average2<<" ||";
    cout<<"\n-------------------------------------------------------------";
    cout<<"\n unionRank||  "<< average3  << "                       || "<<average4<<" ||";
    cout<<"\n==========================&\\*Results*/&======================\n";
    cout << "\nExiting!\n" << endl;
    return 0;
}