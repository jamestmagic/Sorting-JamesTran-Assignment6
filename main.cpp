#include <iostream>
#include <fstream>
#include <math.h>
#include "Algorithms.h"
using namespace std;

int main(int argc, char **argv){
  string fileName = argv[1]; //takes command line argument as input for filename
  Algorithms* a = new Algorithms(); //Pointer to Object
  a->setFile(fileName); //sets dimensions and data for arrays
  a->printList(); //prints the results
}
