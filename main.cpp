#include <iostream>
#include <fstream>
#include <math.h>
#include "Algorithms.h"
//Check task manager for difference in cpu
using namespace std;

int main(int argc, char **argv){
  string fileName = argv[1];
  Algorithms* a = new Algorithms();
  a->setFile(fileName);
  a->printList();
  a->bubbleSort();
  a->insertionSort();
  a->quickSort(0, a->getSize()-1);
  a->printList();
}
