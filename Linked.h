#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include <string.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <exception>

class Linked {
public:
    Linked();
    ~Linked();
    void insertBeg(char* name, int rg, long = 0, long = 0);
    void insertEnd(char* name, int rg, long = 0, long = 0);
    void insertIndex(char* name, int rg, int index);
    void removeBeg(long = 0, long = 0);
    void removeEnd(long = 0, long = 0);
    void removeIndex(int index);
    void searchRg(int rg);
    void adjustPosition(Node* start, int amnt, long* m=NULL);
    void showList();
    void mergeSort(Node** array, int begin, int end, int* c, int* m);
    void quick(Node** array, int begin, int end, int* c, int* m);
    void selection();
    void insertion(int t=0);
    void bubble();
    void shell();
    void exportTxt(char* name);
    void importTxt(char* name);
    void printInfo(char* name, int rg, long c, long m, 
         double time, char* action);
    Node** toArray();
    void callMerge();
    void callQuick();
    void quickSort();
    void resetPosition();
    void printInfoSort(char* type, int c, int m, double time);
private:
    void merge(Node** array, int begin, int pivot, int end, int* c, int* m);
    Node* getIndex(int index);
    void swap(Node* node1, Node* node2, int* c, int* m);
    Node* split(Node* node1, Node* node20);    
    Node *first;
    Node *last;
    int n_nodes;
};

#endif /* LIST_H */

