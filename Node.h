#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node();
    ~Node();
    void setPrev(Node* prev);
    Node* getPrev();
    void setNext(Node* next);
    Node* getNext();
    void setReg(int n);
    int getReg();
    void setName(char* name);
    char* getName();
    void setRg(int rg);
    int getRg();
    void setPos(int pos);
    int getPos();
    void sumPos(int sum);
private:
    char name[30];
    int rg;
    int position;
    int n_register;
    Node *next;
    Node *prev;
};

#endif /* NODE_H */

