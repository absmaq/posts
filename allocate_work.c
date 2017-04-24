/*

There is a bunch of tasks, each have different time to complete, task is independent, and then there are some workers,
How to allocate tasks to these workers to minimize the total time to complete all the task. The tasks can be randomly picked from the task list.
Example
Task: 2,2,3,7, 1
Worker: 2.
Return 8, because the first worker can work on the first three tasks : 2 + 2 + 3 = 7, and the second worker can work on the last two tasks: 
7 + 1 = 8, so the total time to finish all the task is 8.
public int getMini(int[] tasks, int k)

*/

/* Greedy algorithm: Each worker take the task with highest value after they finish the previous task
 * It will have a auxiliary array that holds the times of tasks for each worker
 * Then, this array is rearranged so that the worker holding the task with shortest duration goes to the first position and receive the next task
 *
 */

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
