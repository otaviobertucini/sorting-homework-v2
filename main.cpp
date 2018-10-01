#include <cstdlib>
#include "Sequential.h"
#include "Linked.h"
#include <iostream>

using std::cout;
using std::endl;
using namespace std;

int main() {  
    
    /*Sequential seq;
    seq.importTxt("NomeRG10.txt");
    seq.mergeSort(0, 9);
    seq.showList();*/
    
    int i;
    Node** array;
    Linked lin;
    /*lin.insertEnd("otavio", 12);
    lin.insertEnd("otavio", 3);
    lin.insertEnd("otavio", 1);
    lin.insertEnd("otavio", 1);
    lin.insertEnd("otavio", 8);
    lin.insertEnd("otavio", 8);
    lin.insertEnd("otavio", 6);*/
    
    lin.importTxt("NomeRG10.txt");  
    lin.callMerge();
    lin.showList();   
    
    /*lin.insertEnd("otavio", 6);
    lin.insertEnd("otavio", 1); */
    /*lin.insertEnd("otavio", 1);
    lin.insertEnd("otavio", 1);*/
    //lin.mergeSort();
    //lin.showList();
    
    //cout << "Antes" << endl;
    
    /*Linked lin;
    lin.importTxt("NomeRG10.txt");
    lin.insertion();
    lin.showList();*/

    return 0;
}

