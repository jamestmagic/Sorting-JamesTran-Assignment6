#include <iostream>

using namespace std;

class Algorithms{
public:
  Algorithms(); //constructor
  ~Algorithms(); //destructor

  int size; //size of the array

  void setFile(string fileName); //sets each array to data in text file
  void bubbleSort(); //implements bubble sort
  void insertionSort();//implements insertion sort
  void quickSort(int left, int right); //implements quick sort with left = first index, right=last index
  void selectionSort(); //implements selection sort
  void printList(); //prints results of analysis
  int getSize(); //returns the size of the data set

  //Dynamic Arrays for each sorting algorithm
  double* bubbleList;
  double* insertionList;
  double* quickList;
  double* selectionList;
};
