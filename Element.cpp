#include "Element.h"
#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include<ctime> 
using std::cout;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::string;

Element::Element() {
}

void Element::setName(char* name){
    strcpy(this->name, name);
}

void Element::setRg(int rg){
    this->rg = rg;
}

void Element::setPos(int n){
    position = n;
}

int Element::getPos(){
    return position;
}

char* Element::getName(){
    return name;
}

int Element::getRg(){
    return rg;
}

void Element::sumPos(int n){
    position += n;
}

Element::~Element() {
}

