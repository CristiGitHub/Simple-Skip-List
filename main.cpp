#include <iostream>
#include <ctime>
#include "SkipList.h"
//#include "Aplicatie.h"

using namespace std;
int main() {
//   Aplicatie * ap = ap->getStarted();
//   ap->optiuni();
   SkipList lst(3,0.60);
    lst.insert(1);
    lst.insert(10);
    lst.insert(15);
    lst.insert(12);
    lst.insert(4);
    lst.insert(22);
    cout<<&lst;
    lst.sterge(10);
    cout<<&lst;
    lst.succesor(15);
    cout<<&lst;
    lst.predecesor(22);


    return 0;
}
