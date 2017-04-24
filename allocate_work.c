#include <stdio.h>
#include <stdlib.h>

int cmpFunction(const void * a, const void * b) {
  return (*(int *)a - *(int *)b);
};

int getMinTime(int * task, int num_workers, int size)
{
  int it_workers, it_task = size - 1;
  int * time_workers = (int*) calloc(num_workers, sizeof(int));

  while(it_task >= 0)
  {
    for(it_workers = 0; it_workers < num_workers; it_workers++)
    {
      if(it_task < 0)
	break;
      if(it_workers != 0) {
	if(time_workers[it_workers] > time_workers[it_workers-1])
	  break;
      }
      time_workers[it_workers] += task[it_task];
      printf("time_workers[%d] = %d\n", it_workers, time_workers[it_workers]);
      it_task--;
    }
    qsort(time_workers, num_workers, sizeof(int), cmpFunction);
  }

  return time_workers[num_workers-1];
};

int main()
{
  int task[] = {2, 2, 3, 7, 1, 6, 3, 1, 1, 7, 4};
  int nWorkers = 2, size = sizeof(task)/sizeof(int);

  qsort(task, size, sizeof(int), cmpFunction); /* Sorting the array before proceed */

  printf("Time to complete works: %d\n", getMinTime(task, nWorkers, size));
}
