#ifndef SEQUENTIAL_H
#define SEQUENTIAL_H
#include "Node.h"
#include "Element.h"
#include <fstream>
using std::fstream;
using std::ofstream;
using std::ifstream;

class Sequential {
public:
    Sequential();
    ~Sequential();
    void insertBeg(char* name, int rg);
    void insertEnd(char* name, int rg);
    void insertIndex(char* name, int rg, int index);
    void removeBeg();
    void removeEnd();
    void removeIndex(int index);
    void searchRg(int rg);
    void showList();
    void showElement(Element element);
    void insertion();
    void mergeSort(int begin, int end, int* c, int* m);
    void bubble();
    void shell();
    void callBinarySearch(int rg);
    Element* binarySearch(int rg, int begin, int end, int* c);
    void importTxt(char* file);
    void exportTxt(char* file);
    int countLines(char* file);
    Element* newArray(int n, int* m);
    void printInfo(char* name, int rg, int c, int m, 
         double time, char* action);
    void printInfoSort(char* type, int c, int m, double time);
    void selection();
    void quickSort();
    void merge();
private:
    void merge(int begin, int pivot, int end, int* c, int* m);
    void quick(int begin, int end, int* c, int* m);
    Element* start;
    int n_elements;
};

#endif /* SEQUENTIAL_H */

