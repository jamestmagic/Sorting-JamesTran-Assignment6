#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Algorithms.h"

using namespace std;

int size;
double* myList;
double* bubbleList;
double* insertionList;
double* quickList;
double* mergeList;

Algorithms::Algorithms(){
  size = 0;
  bubbleList = new double[0];
  insertionList = new double[0];
  quickList = new double[0];
  mergeList = new double[0];
}

Algorithms::~Algorithms(){

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
        mergeList = new double[stoi(tempString)];
        ++index;
      }
      else{
        bubbleList[index - 1] = stoi(tempString);
        insertionList[index - 1] = stoi(tempString);
        quickList[index - 1] = stoi(tempString);
        mergeList[index - 1] = stoi(tempString);
        ++index;
      }
    }
  }
  catch(ifstream::failure e){ //throws expection in case of ioexception
    cout << "Exception: Could not read or open file" << endl;
  }
}

void Algorithms::printList(){
  cout << "bubble" << endl;
  for(int i = 0;i<size;++i){
    cout << bubbleList[i] << ",";
  }
  cout << endl;

  cout << "Insertion" << endl;
  for(int i = 0;i<size;++i){
    cout << insertionList[i] << ",";
  }
  cout << endl;

  cout << "quick" << endl;
  for(int i = 0;i<size;++i){
    cout << quickList[i] << ",";
  }
  cout << endl;
}

int Algorithms::getSize(){
  return size;
}
