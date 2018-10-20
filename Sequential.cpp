#include "Sequential.h"
#include <cstddef>
#include "Element.h"
#include "Linked.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include<ctime> 
using std::cout;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::string;

Sequential::Sequential() {
    start = NULL;
    n_elements = 0;
}

void Sequential::insertBeg(char* name, int rg){    
    int start_s=clock(), i, c=0, m=0;
    
    Element* new_array = new Element[n_elements+1];
    Element new_node;
    new_node.setName(name);
    new_node.setRg(rg);
    new_node.setPos(n_elements+1);
    m+=4;
    c++;
    if(n_elements == 0){        
        start = new_array;
        *start = new_node;
        m+=2;
    }
    else{        
        Element* aux=start;        
        start=new_array;
        *start = new_node;    
        m+=2;        
        for(i=1; i<=n_elements; i++){  
            start[i] = aux[i-1];
            start[i].setPos(i);
            m+=2;
        }
        //delete aux;
    }
    n_elements++;
    for(i=0; i<n_elements; i++){
        start[i].setPos(i+1);
        m++;
    }
    
    int stop_s=clock();  
    
    printInfo(name, rg, c, m, (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000, "adicionada");
}

void Sequential::insertEnd(char* name, int rg){
    int start_s=clock(), i, c=0, m=0;
    
    Element* new_array = new Element[n_elements+1];    
    Element new_node;
    new_node.setName(name);
    new_node.setRg(rg);
    new_node.setPos(n_elements+1);
    Element* aux=start;
    start = new_array;
    start[n_elements] = new_node;
    m+=7;
    for(i=0; i<n_elements; i++){            
        start[i] = aux[i];
        start[i].setPos(i+1);
        m+=2;
    }
    n_elements++;
    delete[] aux;    
    int stop_s=clock();
    
    printInfo(name, rg, c, m, (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000, "adicionada");
}

void Sequential::insertIndex(char* name, int rg, int index){
    int start_s=clock(), c=0, m=0;
    
    c++;
    if(index>n_elements+1 || index <=0){
        cout << "Índice inexistente!" << endl;
    }
    else{
        index--;
        int i;
        Element* new_array = new Element[n_elements+1];    
        Element new_node;
        new_node.setName(name);
        new_node.setRg(rg);
        Element* aux=start;
        start = new_array;
        m+=5;
        for(i=0; i<index; i++){
            start[i] = aux[i];
            m++;
        }
        start[i] = new_node;
        start[i].setPos(i+1); 
        m+=2;
        for(i++; i<=n_elements; i++){
            start[i] = aux[i-1];
            start[i].setPos(i+1);
            m+=2;
        }
        n_elements++;
        delete[] aux;
        
        int stop_s=clock();    
        printInfo(name, rg, c, m, (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000, "adicionada");
    }    
    
}

void Sequential::removeBeg(){
    int start_s=clock(), c=0, m=0, rg;
    char name[30];
    strcpy(name, start[0].getName());
    rg = start[0].getRg();    
    c++;
    if(n_elements == 0){
        cout << "Lista vazia!" << endl;
    }
    else{
    int i;
        Element* new_array = new Element[n_elements-1];
        for(i=1; i<n_elements; i++){
            new_array[i-1] = start[i];
            new_array[i-1].setPos(i);
            m+=2;
        }
        start = new_array;
        n_elements--;
        //delete[] new_array;
    }
    int stop_s=clock();
    
    printInfo(name, rg, c, m, (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000, "removida");
}

void Sequential::removeEnd(){
    int start_s=clock(), c=0, m=0, rg;
    char name[30];
    strcpy(name, start[n_elements-1].getName());
    rg = start[n_elements-1].getRg();    
    c++;
    if(n_elements == 0){
        cout << "Lista vazia!" << endl;
    }
    else{
        int i;
        Element* new_array = new Element[n_elements-1];
        for(i=0; i<n_elements-1; i++){
            new_array[i] = start[i];
            m++;
        }
        start = new_array;
        n_elements--;
        //delete[] new_array;
    }
    int stop_s=clock();
    
    printInfo(name, rg, c, m, (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000, "removida");
}

void Sequential::removeIndex(int index){
    int start_s=clock(), c=0, m=0, rg;
    char name[30];
    
    c+=2;
    if(n_elements == 0)
        cout << "Lista vazia!" << endl;
    else if(index > n_elements)     
        cout << "Posição inexistente!" << endl;
    else{
        int i;
        index--;
        Element* new_array = new Element[n_elements-1];
        for(i=0; i<index; i++){
            new_array[i] = start[i];
            new_array[i].setPos(i+1);
            m+=2;
        }
        strcpy(name, start[i].getName());
        rg = start[i].getRg();
        for(i++; i<n_elements; i++){
            new_array[i-1] = start[i];
            new_array[i-1].setPos(i);
            m+=2;
        }
        start = new_array;
        n_elements--;
        int stop_s=clock();
    
        printInfo(name, rg, c, m, (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000, "removida");
    }    
    
}

void Sequential::searchRg(int rg){
    int start_s=clock(), c=0, m=0, i;
    char name[30];
    int rg_c;

    for(i=0; i<n_elements; i++){
        m++;
        c++;
        if(start[i].getRg() == rg){
            //showElement(start[i]);
            strcpy(name, start[i].getName());
            rg_c = start[i].getRg();
            m+=2;
            int stop_s=clock();    
            printInfo(name, rg_c, c, m, (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000, "encontrada");
            return;
        }
    }
    cout << "Elemento não encontrado!" << endl;
    int stop_s=clock();
    cout << "Tempo de execução: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000 << endl;
}

void Sequential::callBinarySearch(int rg){
    Element* found = binarySearch(rg, 0, n_elements-1);
    if(found != NULL)
        cout << found->getName() << endl;
}

Element* Sequential::binarySearch(int rg, int begin, int end){
    int middle = (begin + end)/2;    
    if(start[middle].getRg() == rg){
        return &start[middle];
    }
    if(begin == end){
        cout << "Elemento não encontrado!" << endl;
        return NULL;
    }
    if(start[middle].getRg() < rg)
        return binarySearch(rg, middle+1, end);
    return binarySearch(rg, begin, middle-1);
}

void Sequential::importTxt(char* file){
    int start_s=clock(), c=0, m=0, i, n_lines;
    string line;
    ifstream myfile (file);
    if (myfile.is_open()){
        n_lines = countLines(file);
        start = newArray(n_lines, &m);
        if(start == 0 || start == NULL)
            cout << "Erro!" << endl;            
        else{
            while ( getline (myfile,line)){
                for(i=0; line.size();i++){
                    c++;
                    if(line[i]==',')
                        break;
                }
                string name(line, 0, i);
                string rg(line, i+1, line.size()-1);            
                start[n_elements].setName((char *)name.c_str());
                start[n_elements].setRg((int) atoi(rg.c_str()));
                start[n_elements].setPos(n_elements+1);
                m+=5;
                n_elements++;
            }
        }            
        myfile.close();
        int stop_s=clock();
        cout << "---------------------------------------------------" << endl;
        cout << "Tempo de execução total (importar para sequencial): " << 
                (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
        cout << "---------------------------------------------------" << endl;
    }
    else cout << "Não foi possível abrir o arquivo!" << endl;  
}

int Sequential::countLines(char* file){
    string line;
    int i=0;
    ifstream myfile (file);
    if (myfile.is_open()){
        while ( getline (myfile,line)){
            i++;
        }
        myfile.close();
    }
    else 
        cout << "Não foi possível abrir o arquivo!" << endl;
    return i;
}

Element* Sequential::newArray(int n, int* m){
    int i;
    Element* new_array = new Element[n_elements+n];
    if(new_array != 0 && new_array != NULL){
        for(i=0; i<n_elements; i++){
            new_array[i] = start[i];
            new_array[i].setPos(i+1);
            (*m)+=2;
        }
        return new_array;
    }
    return NULL;
}

void Sequential::exportTxt(char* name){
    int start_s=clock();
    int i;
    ofstream myfile(name);
    if(myfile.is_open()){
        for(i=0; i<n_elements; i++){
            myfile << start[i].getName();
            myfile << ",";
            myfile << start[i].getRg();
            myfile << "\n";
        }
        int stop_s=clock();
        cout << "---------------------------------------------------" << endl;
        cout << "Tempo de execução (exportar sequencial): " << 
                (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000  << endl;
        cout << "---------------------------------------------------" << endl;
    }
    else
        cout << "Não foi possível abrir o arquivo!" << endl;
}

void Sequential::mergeSort(int begin, int end){
    int pivot;
    pivot = (begin+end)/2;
    if(begin < end){
        mergeSort(begin, pivot);
        mergeSort(pivot+1, end);
        merge(begin, pivot, end);
    }
}

void Sequential::merge(int begin, int pivot, int end){
    
    int index1, index2, size, i, enter, j;
    index1 = begin;
    index2 = pivot+1;
    size = end-begin+1;
    Element* aux = new Element[size];
    enter = 1;
    for(i=0; i<size; i++){
        if((index1 <= pivot && index2 <= end) || enter){
            enter = 0;            
            if(start[index1].getRg() < start[index2].getRg()){
                aux[i] = start[index1];
                index1++;
            }
            else{
                aux[i] = start[index2];
                index2++;
            }
        }
        else{
            if(index1 <= pivot){
                aux[i] = start[index1];
                index1++;
            }
            else{
                aux[i] = start[index2];
                index2++;
            }
        }
    }
    for(i=0, j=begin; i<size; i++, j++){
        start[j] = aux[i];
        start[j].setPos(j+1);
    }
    //showList();
}

void Sequential::quickSort(){
    quick(0, n_elements-1);
}

void Sequential::quick(int begin, int end){
    int i=begin, j=end, aux_pos1, aux_pos2;
    Element aux;
    int pivot = start[(begin+end)/2].getRg();
    while(i<j){
        while(start[i].getRg() < pivot)
            i++;
        while(start[j].getRg() > pivot)
            j--;
        if(i<=j){
          aux = start[i];
          aux_pos1 = aux.getPos();  
          aux_pos2 = start[j].getPos();
          start[i] = start[j];    
          start[i].setPos(aux_pos1);
          start[j] = aux;
          start[j].setPos(aux_pos2);
          i++;
          j--;
        }
    }
    if(begin < j)
        quick(begin, j);
    if(i < end)
        quick(i, end);
}

void Sequential::shell(){
    int len, i;
    Element aux;
    len = (n_elements-1)/2;
    while(len > 0){
        for(i=0; i<(n_elements)-len; i++){
            if(start[i].getRg() > start[i+len].getRg()){
                aux = start[i];
                start[i] = start[i+len];
                start[i+len] = aux;
            }
        }
        len /= 2;
    }
}

void Sequential::selection(){
    int i, j, p_smaller, aux_pos1, aux_pos2;
    Element aux;
    for(i=0; i<n_elements; i++){
        j = i+1;
        p_smaller = i;
        for(j; j<n_elements; j++){
            if(start[j].getRg() < start[p_smaller].getRg()){
                p_smaller = j;
            }
        }        
        aux = start[i];
        aux_pos1 = aux.getPos();  
        aux_pos2 = start[p_smaller].getPos();
        start[i] = start[p_smaller];    
        start[i].setPos(aux_pos1);
        start[p_smaller] = aux;
        start[p_smaller].setPos(aux_pos2);
    }
}

void Sequential::insertion(){
    int i, j;
    Element n;
    for(i=1; i<n_elements; i++){
        n = start[i];
        j = i-1;
        while(j >= 0 && n.getRg() < start[j].getRg()){
            start[j+1] = start[j];
            start[j+1].setPos(j+2);
            j--;
        }
        start[j+1] = n;
        start[j+1].setPos(j+2);
    }
}

void Sequential::bubble(){
    int t=-1, i;
    Element aux;
    int len = n_elements;
    while(t != 0){
        t = 0;
        for(i=0; i<len-1; i++){
            if(start[i].getRg() > start[i+1].getRg()){
                aux = start[i];                
                start[i] = start[i+1];                
                start[i+1] = aux;
                start[i].sumPos(-1);
                start[i+1].sumPos(1);
                t++;
            }
        }
        len--;
    }
}

void Sequential::showList(){
    int start_s=clock();
    
    cout << "---------------------------------------------------" << endl;
    if(n_elements == 0){
        cout << "Lista vazia!" << endl;
    }
    else{
        int i;
        for(i=0; i<n_elements; i++){
            cout << "Nome: " << start[i].getName() << " RG: " <<
            start[i].getRg() << " Posição: "<< start[i].getPos() << endl;
        }
    }
    
    int stop_s=clock();    
    
    cout<<"Tempo de execução (mostrar lista sequencial): "<<(stop_s-start_s)
            /double(CLOCKS_PER_SEC)*1000 << endl;
    cout << "---------------------------------------------------" << endl;
}

void Sequential::showElement(Element element){
    cout << "Elemento encontrado!" << endl;
    cout << "Nome: " << element.getName() << endl;
    cout << "RG: " << element.getRg() << endl;
    cout << "Posição: " << element.getPos() << endl;
}

void Sequential::printInfo(char* name, int rg, int c, int m, 
        double time, char* action){    
    cout << "---------------------------------------------------" << endl;
    cout << "Lista sequencial: " << endl;
    cout << "Pessoa " << name << " (" << rg <<") " << "Foi " << action << 
            " com sucesso!" << endl;
    cout << "Tempo de execução: " << time << endl;
    cout << "Comparações: " << c << endl;
    cout << "Cópias: " << m << endl;
    cout << "---------------------------------------------------" << endl;
}

Sequential::~Sequential() {
    delete [] start;
}

