#include <stdio.h>

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

int main(){
    //Read Input
    int busCount;
    scanf("%d", &busCount);
    int busList[busCount];
    for(int x = 0; x < busCount; x++){
        int newBus;
        scanf("%d", &newBus);
        busList[x] = newBus;
    }
    // Sort the unsorted list.
    // Chose quicksort for efficiency / ease of implementation
    quickSort(busList, 0, busCount-1);
    
    // With sorted list, turn into shortest list possible.
    int startLine = busList[0];
    int endLine = 0;
    for(int x = 1; x < busCount+1; x++){
        if(busList[x] == startLine + 1 || busList[x] == endLine + 1){
            endLine = busList[x];
        }
        else{
            if(endLine == 0){
                printf("%d ", startLine);
            }
            else if(endLine == startLine + 1){
                printf("%d %d ", startLine, endLine);
            }
            else{
                printf("%d-%d ", startLine, endLine);
            }
            startLine = busList[x];
            endLine = 0;
        }
    }
}