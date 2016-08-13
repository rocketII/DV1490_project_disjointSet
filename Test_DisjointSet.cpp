//made by R.L.B.
/*
 *
 * ---------------------------------Instructions--------------------------------------------
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






        ---------------------------------feedback2--------------------------------------------

                                        DEADLINE 6 juni.

================================================Rapport

*     Vid beskrivning av ADT ska inter representation inte ”vara känd”, dvs i detta fall träd.
      Find och union ska därför beskrivas utan inblandning av träd.

*     I samband med testet behövs däremot en beskrivning av hur mängder kan representeras med
      träd för att därefter gå in på de olika varianterna av find och union.

*     Testet är inte ”ifyllt” eftersom programmet inte gett resultat.
      Ändra enligt noteringarna under rubriken Program här nedanför
      och tillse dessutom att ditt program fungerar i övrigt.

*     Beskriv användningsområden lite fylligare

=================================================Program
fixcode    fixed      details
0x11       1      Vid varje nytt test krävs ”nya” mängder, eftersom alla försök fortsätter på samma mängder ”hänger sig” programmet

0x22      1       Behöver du kontrollera alla fyra mängderna avseende om två element är i disjunkta mängder eller ej?

0x33      1       Kontrollera FindComlpress.

0x44      0       maxheight verkar onödigt omständiga. För att bestämma max-höjden för de träd som representerar
                  mängderna ska du för varje nod bestämma dess djup (dvs hur långt från roten den är) och den nod
                  som har högst djup motsvarar det träd som är högst. Du ska inte använda de uppskattade
                  höjderna/rankerna utan vekrligen kontrollera djupen för noderna.


                                        DEADLINE 6 juni.

 * */
#include <iostream>
#include "DisjointSets.h"
#include <random>
#include <ctime>
using namespace std;

//fixcode 0x22, 0x11
int main()
{
    /*  find = S findCompress=D  Union=F UnionRank=G
     *  ptr[0](sets), ptr[1](sets),ptr[2](sets),ptr[3](sets);
     *   F,S               F,D            G,S           G,D
     *
     */
    int a1=-1,a2=-1,b1=-1,b2=-1,c1=-1,c2=-1,d1=-1,d2=-1;
    const int sets = 10000; //default 10000;
    int nrOfTests = 100; //default 100
    float average1=0,average2=0, average3=0, average4=0;
    int randomRootCandidateHolderA, randomRootCandidateHolderB;
    std::srand((unsigned)std::time(NULL));
    DisjointSets* ptr[4];

    //start testing.
    for (int j = 0; j < nrOfTests; ++j) //loop test 100 times
    {
        for (int k = 0; k < 4 ; ++k)
        {
            ptr[k] = new DisjointSets(sets);
        }
        for (int i = 0; i < (5000) ; ++i) // loop set generator 50 times
        {

            //random number in range makes root kandidates
            randomRootCandidateHolderA = rand() % sets;
            randomRootCandidateHolderB = rand() % sets;//counter=0;
            a1 = ptr[0]->find(randomRootCandidateHolderA);
            a2 = ptr[0]->find(randomRootCandidateHolderB);
            b1=ptr[1]->findCompress(randomRootCandidateHolderA);
            b2=ptr[1]->findCompress(randomRootCandidateHolderB);
            c1=ptr[2]->find(randomRootCandidateHolderA);
            c2=ptr[2]->find(randomRootCandidateHolderB);
            d1=ptr[3]->findCompress(randomRootCandidateHolderA);
            d2=ptr[3]->findCompress(randomRootCandidateHolderB);


            //compare random roots until none are the same.
            while (a1 == a2 )
            {
                randomRootCandidateHolderA = rand() % sets;
                randomRootCandidateHolderB = rand() % sets;

                a1 = ptr[0]->find(randomRootCandidateHolderA);
                a2 = ptr[0]->find(randomRootCandidateHolderB);
                b1 = ptr[1]->findCompress(randomRootCandidateHolderA);
                b2 = ptr[1]->findCompress(randomRootCandidateHolderB);
                c1 = ptr[2]->find(randomRootCandidateHolderA);
                c2 = ptr[2]->find(randomRootCandidateHolderB);
                d1 = ptr[3]->findCompress(randomRootCandidateHolderA);
                d2 = ptr[3]->findCompress(randomRootCandidateHolderB);


            }
            //DBG
            if( a1 == a2 )
                cout <<"warning!"<<endl;
            //DBG end
            //make sure only roots from different trees are used below.
            //We get 100*50=5000 calls to unionSets and unionSetsRank
            ptr[0]->unionSets(a1, a2);
            ptr[1]->unionSets(b1, b2);
            ptr[2]->unionSetsRank(c1, c2);
            ptr[3]->unionSetsRank(d1, d2);

        }



        //collect 100 times
        average1+=ptr[0]->maxHeight();
        average2+=ptr[1]->maxHeight();
        average3+=ptr[2]->maxHeight();
        average4+=ptr[3]->maxHeight();
        for (int k = 0; k < 3 ; ++k)
        {
            delete ptr[k];
            ptr[k]= nullptr;
        }
    }
    //calc average height for all the tallest trees in the forests.
    average1=average1/nrOfTests + (int)average1 % nrOfTests;
    average2=average2/nrOfTests + (int)average2 % nrOfTests;
    average3=average3/nrOfTests + (int)average3 % nrOfTests;
    average4=average4/nrOfTests + (int)average4 % nrOfTests;
    cout<<"\n==========================&\\*Results*/&======================\n";
    cout<<"       ||  Find utan Komprimering || Find med komprimering ||";
    cout<<"\n-------------------------------------------------------------";
    cout<<"\n union    ||  "<< average1  << "                       || "<<average2<<" ||";
    cout<<"\n-------------------------------------------------------------";
    cout<<"\n unionRank||  "<< average3  << "                       || "<<average4<<" ||";
    cout<<"\n==========================&\\*Results*/&======================\n";
    cout << "\nExiting!\n" << endl;
    return 0;
}