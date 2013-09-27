#include <stdlib.h>

int *array_merge(int num_arrays, int *sizes, int **values){
  int i, j;
  int count = 1;
  int largest = 0;
  int *uniq;
  int *results;
 
  for(i = 0; i < num_arrays; i++)
    for(j = 0; j < sizes[i]; j++)
      if(values[i][j] > largest)
	largest = values[i][j];

  uniq = calloc(largest, sizeof(int));
  
  for(i = 0; i < num_arrays; i++)
    for(j = 0; j < sizes[i]; j++)
      uniq[values[i][j]] += 1;
  
  for(i = 0; i < largest + 1; i++)
    if(uniq[i] > 0)
      count++;
  
  results = calloc(count, sizeof(int));
  results[0] = count - 1;
  j = 1;

  for(i = 0; i < largest + 1; i++){
    if(uniq[i] > 0){
      results[j] = i;
      j++;
    }
  }
  free(uniq);
  return results;
      
    
}
