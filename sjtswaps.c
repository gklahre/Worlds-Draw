// Generates swaps in S-J-T algorithm
// generates permutations applying these swaps
// Copyright, 2009.  Seenu S. Reddi, reddiss at aol dot com
// www.rspq.org/pubs


#include "stdio.h"

#define LEFT 0
#define RIGHT 1


void swap(int i, int j,Permute p)
{
  int tmp;

  tmp = p.v[i];
  p.v[i] = p.v[j];
  p.v[j] = tmp;

  tmp = p.d[i];
  p.d[i] = p.d[j];
  p.d[j] = tmp;
}


int sjtSwap(int n, int start, Permute p)
{
  int i, j;
  int k = -1, dir, s;
  static int sjtCount = 0;

  for (i = start; i < n + start; i++) {
    if (d[i] == LEFT && i > start + 0) {
      if (v[i] > v[i - 1]) {
        if (v[i] > k) {
          k = v[i];
          s = i;
          dir = LEFT;
        }
      }
    } else if (d[i] == RIGHT && i < start + n - 1) {
      if (v[i] > v[i + 1]) {
        if (v[i] > k) {
          k = v[i];
          s = i;
          dir = RIGHT;
        }
      }
    }
  }

  if (k == -1)
    return k;


  if (dir == LEFT) {
    swap(s, s - 1);
  } else {
    swap(s, s + 1);
  }

  // printf("%3d ", s * (dir ? 1 : -1));
  sjtCount++;
  if (sjtCount == 2 * n) {
    // printf("\n");
    sjtCount = 0;
  }

  for (i = start; i < start + n; i++) {
    if (v[i] <= k)
      continue;
    else
      d[i] = (d[i] + 1) % 2; // change direction
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

void perm(int n, Draw draw,int (*f)(Draw,Permute))
{
  int i, k, r;
  Permute p;
  for (i = 0; i < n; i++) {
    p.v[i] = i + 1;
    p.d[i] = LEFT;
  }
  p.cnt = 1;
  r = (*f)(draw,p);
  if(r == 1){
    return;
  }
  while (1) {
    // generate n permutations travelling left with n moving
    for (i = n - 1; i > 0; i--) {
      swap(i, i - 1,p);
      p.cnt++;
      r = (*f)(draw,p);
      if(r == 1){
        return;
      }
    }

    // change direction
    k = sjtSwap(n - 1, 1,p);
    if (k == -1) {
      printf("\nperms = %d\n", cnt);
      return; 
    }
    p.cnt++;
    r = (*f)(draw,p);
    if (r==1){
      return;
    }

    // generate n permutations travelling right with n moving
    for (i = 0; i < n - 1; i++) {
      swap(i, i + 1,p);
      p.cnt++;
      r =(*f)(draw,p);
      if(r==1){
        return;
      }
    }

    // change direction
    k = sjtSwap(n - 1, 0,p);
    if (k == -1) {
      printf("\nperms = %d\n", cnt);
      return; 
    }
    p.cnt++;
    r = (*f)(draw,p);
    if(r == 1){
      return;
    }
  }  
}

