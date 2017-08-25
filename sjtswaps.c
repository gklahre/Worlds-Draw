// Generates swaps in S-J-T algorithm
// generates permutations applying these swaps
// Copyright, 2009.  Seenu S. Reddi, reddiss at aol dot com
// www.rspq.org/pubs


#include "stdio.h"
#include <stdlib.h>

#define LEFT 0
#define RIGHT 1

//int v[16], d[16];

typedef struct SwapPass {
  int cnt;
  int *v;
  int *d;
} SwapPass;

void swap(SwapPass *p, int i, int j)
{
  int tmp;

  tmp = p->v[i];
  p->v[i] = p->v[j];
  p->v[j] = tmp;

  tmp = p->d[i];
  p->d[i] = p->d[j];
  p->d[j] = tmp;
}

void print_p(int n, SwapPass *p)
{
  int i;

  for (i = 0; i < n; i++)
    printf("%d ", p->v[i]);
  printf("\n");
}

int sjtSwap(int n, int start, SwapPass *p)
{
  int i, j;
  int k = -1, dir, s;
  static int sjtCount = 0;

  for (i = start; i < n + start; i++) {
    if (p->d[i] == LEFT && i > start + 0) {
      if (p->v[i] > p->v[i - 1]) {
        if (p->v[i] > k) {
          k = p->v[i];
          s = i;
          dir = LEFT;
        }
      }
    } else if (p->d[i] == RIGHT && i < start + n - 1) {
      if (p->v[i] > p->v[i + 1]) {
        if (p->v[i] > k) {
          k = p->v[i];
          s = i;
          dir = RIGHT;
        }
      }
    }
  }

  if (k == -1)
    return k;


  if (dir == LEFT) {
    swap(p,s, s - 1);
  } else {
    swap(p,s, s + 1);
  }

  // printf("%3d ", s * (dir ? 1 : -1));
  sjtCount++;
  if (sjtCount == 2 * n) {
    // printf("\n");
    sjtCount = 0;
  }

  for (i = start; i < start + n; i++) {
    if (p->v[i] <= k)
      continue;
    else
      p->d[i] = (p->d[i] + 1) % 2; // change direction
  }
  return k;
}

// S-J-T akgorithm for n = 4
// 1 2 3 4 -> shift 4 left 4 times
// 1 2 4 3 
// 1 4 2 3 
// 4 1 2 3 -> apply sjt swap -3 (3, 2)

// 4 1 3 2 -> shift 4 right 4 times
// 1 4 3 2 
// 1 3 4 2 
// 1 3 2 4 -> apply sjt swap -1 (1, 0)

// 3 1 2 4 -> shift 4 left 4 times
// 3 1 4 2 
// 3 4 1 2 
// 4 3 1 2 -> apply sjt swap -3 (3, 2)

// 4 3 2 1 -> shift 4 right 4 times
// 3 4 2 1 
// 3 2 4 1 
// 3 2 1 4 -> apply sjt swap 0 (0, 1)
 
// 2 3 1 4 -> shift 4 left 4 times
// 2 3 4 1 
// 2 4 3 1 
// 4 2 3 1 -> apply sjt swap 2 (2, 3)
 
// 4 2 1 3 -> shift 4 right 4 times
// 2 4 1 3 
// 2 1 4 3 
// 2 1 3 4 

void main(int argc, char *argv[])
{
  SwapPass * p = malloc(sizeof(SwapPass));
  p->v = malloc(sizeof(int) * 16);
  p->d = malloc(sizeof(int) * 16);
  int n = atoi(argv[1]);
  int i, k;

  for (i = 0; i < n; i++) {
    p->v[i] = i + 1;
    p->d[i] = LEFT;
  }

  print_p(n,p);
  p->cnt = 1;
  while (1) {
    // generate n permutations travelling left with n moving
    for (i = n - 1; i > 0; i--) {
      swap(p,i, i - 1);
      p->cnt++;
      print_p(n,p);
    }

    // change direction
    k = sjtSwap(n - 1, 1,p);
    if (k == -1) {
      printf("\nperms = %d\n", p->cnt);
      free(p->v);
      free(p->d);
      free(p);
      return; 
    }
    p->cnt++;
    print_p(n,p);

    // generate n permutations travelling right with n moving
    for (i = 0; i < n - 1; i++) {
      swap(p,i, i + 1);
      print_p(n,p);
      p->cnt++;
    }

    // change direction
    k = sjtSwap(n - 1, 0,p);
    if (k == -1) {
      printf("\nperms = %d\n", p->cnt);
      free(p->d);
      free(p->v);
      free(p);
      return; 
    }
    p->cnt++;
    print_p(n,p);
  }  
}

