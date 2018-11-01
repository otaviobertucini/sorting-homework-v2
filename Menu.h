#ifndef MENU_H
#define MENU_H
#include <string>
#include <string.h>
#include <iostream>
#include "Sequential.h"
#include "Linked.h"

class Menu {
public:
    Menu();
    ~Menu();
    void showMenu();
    void add(int operation);
    void remove(int operation);
    void search();
    void busca_binaria();
    void importar();
    void ordenar();
private:
    Sequential seq;
    Linked lin;
};

#endif /* MENU_H */

