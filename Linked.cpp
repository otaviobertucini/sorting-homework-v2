#include "Linked.h"
#include <cstddef>
#include <iostream>
using namespace std;
using std::cout;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::string;

Linked::Linked() {
    n_nodes = 0;
    first = NULL;
    last = NULL;
}

void Linked::insertBeg(char* name, int rg, long print, long c) {
    int start_s = clock();
    long m = 0;

    Node *new_node = new Node;
    new_node->setName(name);
    new_node->setRg(rg);
    c++;
    if (n_nodes == 0) {
        first = new_node;
        last = new_node;
        first->setPrev(NULL);
        first->setNext(NULL);
        m += 7;
    } else if (n_nodes == 1) {
        c++;
        first = new_node;
        first->setNext(last);
        last->setPrev(new_node);
    } else {
        first->setPrev(new_node);
        new_node->setNext(first);
        first = new_node;
    }

    adjustPosition(first, 1, &m);
    n_nodes++;
    int stop_s = clock();

    if (print == 0) {
        printInfo(name, rg, c, m, (stop_s - start_s) / double(CLOCKS_PER_SEC)
                *1000, "adicionada");
    }
}

void Linked::insertEnd(char* name, int rg, long print, long c) {
    int start_s = clock();
    long m = 0;

    c++;
    if (n_nodes == 0) {
        insertBeg(name, rg, 1, c);
    } else {
        Node *new_node = new Node;
        new_node->setName(name);
        new_node->setRg(rg);
        new_node->setPrev(last);
        last->setNext(new_node);
        last = new_node;
        last->setPos(n_nodes + 1);
        n_nodes++;
        m += 6;
    }
    int stop_s = clock();

    if (print == 0) {
        printInfo(name, rg, c, m, (stop_s - start_s) / double(CLOCKS_PER_SEC)
                *1000, "adicionada");
    }
}

void Linked::insertIndex(char* name, int rg, int index) {
    int start_s = clock();
    long c = 0, m = 0;

    c++;
    if (index > n_nodes + 1) {
        cout << "Índice inválido!" << endl;
    } else if (index == n_nodes + 1) {
        c++;
        insertEnd(name, rg, 0, c);
    } else {
        int i;
        Node *node = first;
        Node *new_node = new Node;
        new_node->setName(name);
        new_node->setRg(rg);
        index--;
        m += 4;
        for (i = 1; i < index; i++) {
            node = node->getNext();
            m++;
        }
        node->getNext()->setPrev(new_node);
        new_node->setNext(node->getNext());
        node->setNext(new_node);
        new_node->setPrev(node);
        new_node->setPos(i);
        m += 5;
        adjustPosition(new_node, 1, &m);
        n_nodes++;
        int stop_s = clock();

        printInfo(name, rg, c, m, (stop_s - start_s) / double(CLOCKS_PER_SEC)
                *1000, "adicionada");
    }

}

void Linked::removeBeg(long c, long m) {
    int start_s = clock();
    char *name;
    int rg;

    c++;
    if (n_nodes == 0)
        cout << "Não existe item para remover!" << endl;
    else {
        name = first->getName();
        rg = first->getRg();
        first = first->getNext();
        first->setPrev(NULL);
        m += 2;
        adjustPosition(first, -1, &m);
        n_nodes--;
        int stop_s = clock();

        printInfo(name, rg, c, m, (stop_s - start_s) / double(CLOCKS_PER_SEC)
                *1000, "removida");
    }
}

void Linked::removeEnd(long c, long m) {
    int start_s = clock();
    char *name;
    int rg;

    c++;
    if (n_nodes == 0)
        cout << "Não existe item para remover!" << endl;
    else {
        name = last->getName();
        rg = last->getRg();
        last = last->getPrev();
        last->setNext(NULL);
        m += 2;
        n_nodes--;
        int stop_s = clock();

        printInfo(name, rg, c, m, (stop_s - start_s) / double(CLOCKS_PER_SEC)
                *1000, "removida");
    }
}

void Linked::removeIndex(int index) {
    int start_s = clock();
    long c = 0, m = 0;
    char *name;
    int rg;

    c++;
    if (n_nodes == 0 || index > n_nodes)
        cout << "Índice não pode ser removido!" << endl;
    else if (index == 1) {
        c++;
        removeBeg(c, m);
    } else if (index == n_nodes) {
        removeEnd(c, m);
        c++;
    } else {
        index--;
        int i;
        Node* node = first;
        for (i = 1; i < index; i++) {
            node = node->getNext();
            m++;
        }
        name = node->getNext()->getName();
        rg = node->getNext()->getRg();
        node->setNext(node->getNext()->getNext());
        node->getNext()->setPrev(node);
        m += 3;
        adjustPosition(node->getNext(), -1, &m);
        n_nodes--;
        int stop_s = clock();

        printInfo(name, rg, c, m, (stop_s - start_s) / double(CLOCKS_PER_SEC)
                *1000, "removida");
    }
}

void Linked::searchRg(int rg) {
    int start_s = clock(), c = 0, m = 0;

    c++;
    if (n_nodes == 0)
        cout << "Lista não tem elementos!" << endl;
    else {
        int cmp;
        Node* aux = first;
        while (aux != NULL) {
            m++;
            c++;
            if (aux->getRg() == rg) {
                int stop_s = clock();
                printInfo(aux->getName(), aux->getRg(), c, m, (stop_s - start_s)
                        / double(CLOCKS_PER_SEC)*1000, "encontrada");
                return;
            }
            aux = aux->getNext();
            m++;
        }
        cout << "Pessoa não encontrada!" << endl;
        int stop_s = clock();
        cout << "Tempo de execução: " << (stop_s - start_s) / double(CLOCKS_PER_SEC)
                *1000 << endl;
    }
}

void Linked::adjustPosition(Node* start, int amnt, long* m) {
    while (start != NULL) {
        start->sumPos(amnt);
        start = start->getNext();
        (*m)++;
    }
}

void Linked::showList() {
    Node *i = first;
    if (n_nodes == 0) {
        cout << "Lista vazia!" << endl;
    } else {
        cout << "---------------------------------------------------" << endl;
        int start_s = clock();
        while (i != NULL) {
            cout << "Nome: " << i->getName() << " RG: " << i->getRg() <<
                    " Posição: " << i->getPos() << endl;
            i = i->getNext();
        }
        cout << "Total de clientes registrados: " << n_nodes << endl;
        int stop_s = clock();
        cout << "Tempo de execução (mostrar lista encadeada): " <<
                (stop_s - start_s) / double(CLOCKS_PER_SEC)*1000 << endl;
        cout << "---------------------------------------------------" << endl;
    }
}

Node* Linked::getIndex(int index) {
    int i;
    Node* aux = first;
    for (i = 0; i < index; i++) {
        aux = aux->getNext();
    }
    return aux;
}

void Linked::selection(){
    Node* i = first;    
    Node *aux, *j;
    while(i != NULL){
        aux = i;
        j = i->getNext();
        while(j != NULL){            
            if(j->getRg() < aux->getRg())
                aux = j;
            j = j->getNext();
        }
        swap(i, aux);
        i = i->getNext();
    }
}

void Linked::insertion() {
    Node* node = first->getNext();
    Node* curr = node->getNext();
    Node* prev;
    while (node != NULL) {
        prev = node->getPrev();
        if (prev->getRg() > node->getRg()) {
            prev->setNext(node->getNext());
            if (node->getNext() != NULL)
                node->getNext()->setPrev(prev);
            while (prev != NULL) {               
                if (prev == first) {        
                    if(prev->getRg() > node->getRg()){
                        first = node;                    
                        first->setPrev(NULL);
                        first->setNext(prev);
                        prev->setPrev(first);                       
                    }
                    else{
                        node->setNext(first->getNext());
                        first->getNext()->setPrev(node);
                        first->setNext(node);
                        node->setPrev(first);                        
                    }
                    prev = NULL;
                } else if (prev->getRg() < node->getRg()) {
                    node->setNext(prev->getNext());
                    prev->getNext()->setPrev(node);
                    prev->setNext(node);
                    node->setPrev(prev);
                    prev = NULL;
                }
                else if (prev->getRg() > node->getRg()){
                    prev = prev->getPrev();
                }
            }
        }
        showList();
        node = curr;
        if (curr != NULL)
            curr = curr->getNext();
    }
}

void Linked::swap(Node* node1, Node* node2) { 
    if(node1 == node2)
        return;
    if(node1->getNext() != node2){
        Node* aux1 = node2->getNext();
        Node* aux2 = node2->getPrev();
        
        node2->setPrev(node1->getPrev());
        node2->setNext(node1->getNext());
        
        node1->setPrev(aux2);
        node1->setNext(aux1);
        
        if(node2->getNext() != NULL)
            node2->getNext()->setPrev(node2);
        if(node2->getPrev() != NULL)
            node2->getPrev()->setNext(node2);
        
        if(node1->getNext() != NULL)
            node1->getNext()->setPrev(node1);
        if(node1->getPrev() != NULL)
            node1->getPrev()->setNext(node1);
        
        /*Node *aux_next, *aux_prev;
        node2->getPrev()->setNext(node1);

        if (node1->getNext() != NULL)
            node1->getNext()->setPrev(node2);
        if (node2->getNext() != NULL)
            node2->getNext()->setPrev(node1);

        aux_next = node1->getNext();
        node1->setNext(node2->getNext());
        node2->setNext(aux_next);

        aux_prev = node2->getPrev();
        node2->setPrev(node1->getPrev());
        node1->setPrev(aux_prev);*/
    }
    else{              
        if(node1->getPrev() != NULL)
            node1->getPrev()->setNext(node2);
        if(node2->getNext() != NULL)
            node2->getNext()->setPrev(node1);          
        
        node2->setPrev(node1->getPrev());        
        node1->setNext(node2->getNext());        
       
        node2->setNext(node1);
        node1->setPrev(node2);
        
    }
    if (node1 == first)
        first = node2;       
    if (node2 == last)
        last = node1;    
}

/*For some reason, if we aplly the same logic of sequential lists in linked
 list we do not get in the same result. */
void Linked::bubble() {
    Node *node1, *node2;
    int i, t = -1, len = n_nodes;
    while (t != 0) {
        t = 0;
        node1 = first;
        for (i = 0; i < len-1; i++) {
            node2 = node1->getNext();
            if (node1->getRg() > node2->getRg()) {
                swap(node1, node2);
                node1->sumPos(1);
                node2->sumPos(-1);
                t++;
            }
            node1 = node2;
        }
    }
}

Node** Linked::toArray(){    
    int i = 0;
    Node* aux = first;
    Node** array = new Node*[n_nodes];
    for(i=0; i<n_nodes; i++){
        array[i] = aux;
        aux = aux->getNext();
    }    
    return array;    
}

void Linked::callMerge(){
    int i;
    Node** array;
    Node* aux;
    array = toArray();
    mergeSort(array, 0, n_nodes-1);
    
    aux = array[0];
    first = aux;
    first->setPrev(NULL);
    for(i=1; i < n_nodes-1; i++){
        aux->setNext(array[i]);
        aux->getNext()->setPrev(aux);
        aux = aux->getNext();
    }
    aux->setNext(array[i]);  
    aux->getNext()->setPrev(aux);
    aux->getNext()->setNext(NULL);
}

void Linked::mergeSort(Node** array, int begin, int end){
    int pivot;
    pivot = (begin+end)/2;
    if(begin < end){
        mergeSort(array, begin, pivot);
        mergeSort(array, pivot+1, end);
        merge(array, begin, pivot, end);
    }
}

void Linked::merge(Node** array, int begin, int pivot, int end){    
    int index1, index2, size, i, enter, j;
    index1 = begin;
    index2 = pivot+1;
    size = end-begin+1;
    Node** aux = new Node*[size];
    enter = 1;    
    for(i=0; i<size; i++){
        if((index1 <= pivot && index2 <= end) || enter){
            enter = 0;            
            if(array[index1]->getRg() < array[index2]->getRg()){
                aux[i] = array[index1];
                index1++;
            }
            else{
                aux[i] = array[index2];
                index2++;
            }
        }
        else{
            if(index1 <= pivot){
                aux[i] = array[index1];
                index1++;
            }
            else{
                aux[i] = array[index2];
                index2++;
            }
        }
    }    
    for(i=0, j=begin; i<size; i++, j++){
        array[j] = aux[i];
        array[j]->setPos(j+1);
    }
}

/*void Linked::callBinarySearch(int rg){
    Node* found = binarySearch(rg, first, last);
    cout << "Pessoa: " << found->getName() << " encontrada!" << endl;
}*/

/*Node* Linked::binarySearch(int rg, Node* begin, Node* end){
    Node* middle = split(begin, end);
    if(middle->getRg() == rg)
        return middle;
    if(begin == end){
        return NULL;
    }
    if(middle->getRg() < rg)
        return binarySearch(rg, middle->getNext(), end);
    return binarySearch(rg, begin, middle->getPrev());
}*/

/*Node* Linked::split(Node* node1, Node* node2){
    Node *slow=first, *fast=first;
    while(fast != NULL && fast->getNext() != NULL){
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
    }
    return slow;
}*/

void Linked::exportTxt(char* name) {
    Node* aux = first;
    ofstream myfile(name);
    if (myfile.is_open()) {
        cout << "---------------------------------------------------" << endl;
        int start_s = clock();
        while (aux != NULL) {
            myfile << aux->getName();
            myfile << ",";
            myfile << aux->getRg();
            myfile << "\n";
            aux = aux->getNext();
        }
        int stop_s = clock();
        cout << "Tempo de execução (exportar encadeada): " <<
                (stop_s - start_s) / double(CLOCKS_PER_SEC)*1000 << endl;
        cout << "---------------------------------------------------" << endl;
        myfile.close();
    } else
        cout << "Não foi possível abrir o arquivo!" << endl;
}

void Linked::importTxt(char* name) {
    string line;
    int i, c = 0;
    ifstream myfile(name);
    if (myfile.is_open()) {
        int start_s = clock();
        while (getline(myfile, line)) {
            for (i = 0; line.size(); i++) {
                if (line[i] == ',')
                    break;
            }
            string name(line, 0, i);
            string rg(line, i + 1, line.size() - 1);
            insertEnd((char *) name.c_str(), (int) atoi(rg.c_str()), 1);
            c++;
            //11748443
        }
        myfile.close();
        int stop_s = clock();
        cout << "---------------------------------------------------" << endl;
        cout << "Tempo de execução total (importar para encadeada): " <<
                (stop_s - start_s) / double(CLOCKS_PER_SEC)*1000 << endl;
        cout << "---------------------------------------------------" << endl;
    }
    else
        cout << "Não foi possível abrir o arquivo!" << endl;

}

void Linked::printInfo(char* name, int rg, long c, long m,
        double time, char* action) {
    cout << "---------------------------------------------------" << endl;
    cout << "Lista encadeada: " << endl;
    cout << "Pessoa " << name << " (" << rg << ") " << "Foi " << action <<
            " com sucesso!" << endl;
    cout << "Tempo de execução: " << time << endl;
    cout << "Comparações: " << c << endl;
    cout << "Cópias: " << m << endl;
    cout << "---------------------------------------------------" << endl;
}

Linked::~Linked() {
    Node *aux, *aux2;
    aux = first;
    while (aux != NULL) {
        aux2 = aux->getNext();
        delete aux;
        aux = NULL;
        aux = aux2;
    }
}

