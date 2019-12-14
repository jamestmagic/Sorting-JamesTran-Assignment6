#include <iostream>
#include "ListNode.h"

class GenLinkedList{
  private:
    ListNode *front;
    unsigned int size;

  public:
    GenLinkedList();
    ~GenLinkedList();
    void insertFront(double d);
    int removeFront();
    int deleteAtPos(int pos);
    int find(int d);

    bool isEmpty();
    void printList();
    unsigned int getSize();
};
