#include <cstdlib>
#include "Sequential.h"
#include "Linked.h"
#include "Menu.h"
#include <iostream>

using std::cout;
using std::endl;
using namespace std;

int main() {    
    Menu menu;
    menu.showMenu();
    
    /*Sequential seq;
    seq.importTxt("NomeRG10.txt");
    seq.insertion();
    seq.showList();*/
    
    /*Linked lin;
    lin.insertBeg("otavio", 84151841);
    lin.removeBeg();*/

    return 0;
}

