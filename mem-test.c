#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int
main(int argc, char * argv[])
{
  if (argc < 2) return -1;
  long int * array = (long int *) malloc(atoi(argv[1]) * sizeof(long int) * 1000);
  printf("address of array: %p\nsize of array: %zu\n", &array, sizeof(array) * atoi(argv[1]));
  int i = 0;
  while (1) {
    if (i == atoi(argv[1])) i = 0;
    printf("address of array at index: %d\t %p\n", i, &array[i]); 
    ++i;
  }
  return 0;
}

