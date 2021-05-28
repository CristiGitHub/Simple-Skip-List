#include <iostream>
#include <ctime>
#include <cmath>
#include "SkipList.h"
//#include "Aplicatie.h"

using namespace std;
int main() {
   int n,x,y,z;
    cout<<"Intializam SkipListul\nCate elemente crezi ca o sa aiba?:";
    cin>>n;
    SkipList lst(round(sqrt(n)),0.5);
    cout<<"Lista a fost initializata cu succes!\nAlege o comanda dintre cele 8 :\n";
    cout<<"1 : inserati numarul X in multime\n"
          "2 : stergeti numarul X din multime (daca acesta exista)\n"
          "3 : afisati 1 daca numarul X este in multime, alftel afisati 0\n"
          "4 : afisati cel mai mare numar Y, mai mic sau egal cu X\n"
          "5 : afisati cel mai mic numar Y, mai mare sau egal cu X\n"
          "6 : afisati in ordine sortata, toate numerele Z, unde X <= Z <= Y\n"
          "7 : afisati intreaga lista\n"
          "8 : iesiti din program";
    while(x!=8)
    {
        cin>>x;
        if(x==1)
        {cin>>y;
            lst.insert(y);}
        else
        if(x==2)
        {cin>>y;
            lst.sterge(y);}
        else
        if(x==3)
        {cin>>y;
            lst.contine(y);}
        else
        if(x==4)
        {cin>>y;
            lst.predecesor(y);}
        else
        if(x==5)
        {cin>>y;
        lst.succesor(y);}
        if(x==6)
        {
            cin>>y>>z;
            lst.interval(y,z);
        }
        else
        if(x==7)
        {
            cout<<&lst;
        }

    }


    return 0;
}
