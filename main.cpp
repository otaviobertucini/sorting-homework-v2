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
    seq.insertion();
    seq.showList();*/
    
    Linked lin;
    lin.importTxt("NomeRG10.txt");
    lin.selection();
    lin.showList();

    return 0;
}

