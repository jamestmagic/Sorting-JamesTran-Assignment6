#include <iostream>

using namespace std;

class Algorithms{
public:
  Algorithms();
  Algorithms(int s);
  ~Algorithms();

  int size; //size of the array

  void setFile(string fileName);
  void bubbleSort();
  void insertionSort();
  void quickSort(int left, int right);
  void printList();
  int getSize();

  double* bubbleList;
  double* insertionList;
  double* quickList;
  double* mergeList;
};
