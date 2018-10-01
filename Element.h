#ifndef ELEMENT_H
#define ELEMENT_H

class Element {
public:
    Element();
    ~Element();
    void setPos(int n);
    int getPos();
    void setName(char* name);
    char* getName();
    void setRg(int rg);
    int getRg();
    void sumPos(int n);
private:
    char name[30];
    int rg;
    int position;
};

#endif /* ELEMENT_H */

