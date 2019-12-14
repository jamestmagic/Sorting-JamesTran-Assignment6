#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include "Algorithms.h"

using namespace std;


int size;
double* bubbleList;
double* insertionList;
double* quickList;
double* selectionList;

Algorithms::Algorithms(){ //constructor
  size = 0;
  bubbleList = new double[0];
  insertionList = new double[0];
  quickList = new double[0];
  selectionList = new double[0];
}

Algorithms::~Algorithms(){
  delete[] bubbleList;
  delete[] insertionList;
  delete[] quickList;
  delete[] selectionList;
}

void Algorithms::bubbleSort(){
  for(int i = 0;i<size;++i){
    double temp = 0;
    for(int j = 0;j<size-1;++j){
      if(bubbleList[j] > bubbleList[j+1]){
        temp = bubbleList[j+1];
        bubbleList[j+1] = bubbleList[j];
        bubbleList[j] = temp;
      }
    }
  }
}

void Algorithms::insertionSort(){
  for(int j = 0;j<size;++j){
    double temp = insertionList[j];
    int k = j;
    while(k>0 && insertionList[k-1] >= temp){
      insertionList[k] = insertionList[k-1];
      --k;
    }
    insertionList[k] = temp;
  }
}

void Algorithms::quickSort(int left, int right){
  int i = left;
  int j = right;
  double temp;
  double pivot = quickList[(i+j)/2];
    while(i <= j){
      while(quickList[i] < pivot){
        i++;
      }
      while(quickList[j] > pivot){
        j--;
      }
      if(i<=j){
        temp = quickList[i];
        quickList[i] = quickList[j];
        quickList[j] = temp;
        i++;
        j--;
      }
    }
    if(left < j){
      quickSort(left, j);
    }
    if (i < right){
      quickSort(i, right);
    }
}

void Algorithms::selectionSort(){
  int i,j,minIndex,tmp;
  for(i = 0;i<size-1;++i){
    minIndex = 1;
    for(j = i+1;j<size;j++){
      if(selectionList[j] < selectionList[minIndex]){
        minIndex = j;
      }
    }
    if(minIndex != i){
      tmp = selectionList[i];
      selectionList[i] = selectionList[minIndex];
      selectionList[minIndex] = tmp;
    }
  }
}

void Algorithms::setFile(string fileName){ //translates info from map file and creates the grid
  try{
    ifstream readFile(fileName);
    string tempString;
    int index = 0;
    while(getline(readFile, tempString)){
      if(index == 0){
        size = stoi(tempString);
        bubbleList = new double[stoi(tempString)];
        insertionList = new double[stoi(tempString)];
        quickList = new double[stoi(tempString)];
        selectionList = new double[stoi(tempString)];
        ++index;
      }
      else{
        bubbleList[index - 1] = stoi(tempString);
        insertionList[index - 1] = stoi(tempString);
        quickList[index - 1] = stoi(tempString);
        selectionList[index - 1] = stoi(tempString);
        ++index;
      }
    }
  }
  catch(ifstream::failure e){ //throws expection in case of ioexception
    cout << "Exception: Could not read or open file" << endl;
  }
}

void Algorithms::printList(){
  time_t start;
  time_t end;
  cout << "Bubble Sort" << endl;
  time(&start);
  bubbleSort();
  time(&end);
  cout << "Sort Start: " << start << endl;
  cout << "Sort End: " << end << endl;
  cout << endl;

  cout << "Insertion Sort" << endl;
  time(&start);
  insertionSort();
  time(&end);
  cout << "Sort Start: " << start << endl;
  cout << "Sort End: " << end << endl;
  cout << endl;

  cout << "Quick Sort" << endl;
  time(&start);
  quickSort(0, size-1);
  time(&end);
  cout << "Sort Start: " << start << endl;
  cout << "Sort End: " << end << endl;
  cout << endl;

  cout << "Selection Sort" << endl;
  time(&start);
  selectionSort();
  time(&end);
  cout << "Sort Start: " << start << endl;
  cout << "Sort End: " << end << endl;
  cout << endl;
}

int Algorithms::getSize(){
  return size;
}
