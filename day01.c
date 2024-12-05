#include <stdio.h>
#include <stdlib.h>

// https://adventofcode.com/2024/day/1

int compare(const void* a, const void* b) {
  int arg1 = *(const int*)a;
  int arg2 = *(const int*)b;

  if (arg1 < arg2) return -1;
  if (arg1 > arg2) return 1;
  return 0;
}

#define N 1000
#define MAX_VALUE 100000
    
int main(void) {
  char line[16];
  int left[N];
  int right[N];

  int i = 0;
  while(scanf("%d %d", &left[i], &right[i]) > 0) {
    i++;
  }

  qsort(left, N, sizeof(int), compare);
  qsort(right, N, sizeof(int), compare);

  int total_dist = 0;
  for (int i = 0; i < N; i++) {
    int dist = abs(left[i] - right[i]);
    total_dist += dist;
  }
  printf("Answer 1: %d\n", total_dist);

  // Part 2

  int counter[MAX_VALUE];
  for (int i = 0; i < MAX_VALUE; i++) {
    counter[i] = 0;
  }

  for (int i = 0; i < N; i++) {
    counter[right[i]] += 1; 
  }

  int similarity = 0;
  for (int i = 0; i < N; i++) {
    similarity += left[i] * counter[left[i]];
  }

  printf("Answer 2: %d\n", similarity);

  return 0;
}
