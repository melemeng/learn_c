#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


/** Our old friend die from ex17. */

void die(const char* message){ // If a system error exits 
  if(errno){
    perror(message);
  }

  else{
    printf("Error: %s\n", message);
  }
  exit(1); // Exit with error status 
}


// a typedef void Emptiness;
// case for a funktion pointer
//
//
// Defining a type for a pointer to a comparison function 
typedef int (*compare_cb) (int a, int b);

// A bubble sort function that uses function pointer for comparon 
int *bubble_sort(int *numbers, int count, compare_cb cmp){
  
  int temp = 0;
  int i = 0;
  int j = 0;

  // Allocate memory for the array that will store the sorted numbers
  int *target = malloc(count * sizeof(int));

  if(!target){ // Check if memory allocation was succesfull
    die("Memory error.");
  }
    // Copy the original array to the target array
  memcpy(target, numbers, count* sizeof(int));

  // Begin bubble sort 
  for(i = 0; i < count; i++){
    for (j =0; j < count -1; j++) {
      // Use the comparison function pointer to cpmpare two numbers
      if(cmp(target[j], target[j + 1]) > 0){
        // Swap the two numbers
        temp = target[j + 1];
        target[j + 1] = target[j];
        target[j] = temp;
      }
    }
  }
  // Retun the sorted array 
  return target;

}

// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order// comparison function for sortin in ascending order
int sorted_order(int a, int b){
  return a - b;
}

int reverse_order(int a, int b){
  return b-a;

}


int strange_order(int a, int b){

  if( a == 0 || b == 0){
    return 0;

  }

  else{
    return a % b;
  }
}

/*
 * Used to test that we are sorting things srrectly 
 * by doing the sort and printing it out.
 * */

void test_sorting(int *numbers, int count, compare_cb cmp){
  // perform the sorting 
  int *sorted = bubble_sort(numbers,count,cmp);

  if(!sorted){
    die("Failed to sort as requested.");
  }

  for(int i = 0; i < count; i++){
    printf("%d ", sorted[i]);
  }
  
  printf("\n");
  free(sorted);
}

int main(int argc, char *argv[]){

  if(argc < 2){
    die("USAGE: ex18 4 3 1 5 6");
  }
  int count = argc -1;
  int i = 0;
  char **inputs = argv +1;

  int *numbers = malloc(count *sizeof(int));
  if(!numbers){
    die("Memory error.");
  }

  for(i = 0; i < count; i++){
    numbers[i]  = atoi(inputs[i]);
  }

  test_sorting(numbers, count, sorted_order);

  test_sorting(numbers, count, reverse_order);
  test_sorting(numbers, count, strange_order);

  free(numbers);

  return 0;
}
