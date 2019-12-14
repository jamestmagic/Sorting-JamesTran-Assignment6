#include <iostream>
#include "GenLinkedList.h"

GenLinkedList::GenLinkedList(){
  size = 0;
  front = NULL; //nullptr

}

GenLinkedList::~GenLinkedList(){
  delete front;
}

unsigned int GenLinkedList::getSize(){
  return size;
}

void GenLinkedList::printList(){
  ListNode *curr = front;
  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}

void GenLinkedList::insertFront(double d){
  ListNode *node = new ListNode(d);
  node->next = front;
  front = node;
  size++;
}

int GenLinkedList::removeFront(){
  int temp = front->data;
  ListNode *ft = front;
  front = front->next;
  ft->next = NULL;
  delete ft;
  size--;

  return temp;
}

int GenLinkedList::deleteAtPos(int pos){
  int idx = 0;
  ListNode *curr = front;
  ListNode *prev = front;
  while(idx != pos){
    prev = curr;
    curr = curr->next;
    idx++;
  }

  prev->next = curr->next;
  curr->next = NULL;
  int temp = curr->data;
  delete curr;
  size--;
  return temp;
}


int GenLinkedList::find(int d){
  int idx = 0;
  ListNode *curr = front;
  while(curr != NULL){
    idx++;
    if(curr->data == d){
      break;
    }
    curr = curr->next;
  }
  if(curr = NULL){//did not find data
    idx = -1;
  }
  return idx;

}
