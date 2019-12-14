#include <iostream>
#include "ListNode.h"

using namespace std;

ListNode::ListNode(){}

ListNode::ListNode(double d){
  data = d;
  next = NULL;
}

ListNode::~ListNode(){
  if(next == NULL)
    delete next;
}
