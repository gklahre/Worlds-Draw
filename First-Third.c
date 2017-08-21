#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getFirstThird(Draw draw){
	perm(4,draw,poolperm);
}
int poolperm(Draw draw,Permute p){
	int i;
	for(i=0,i<4;i++){
		draw.first[p.cnt-1][i] = p.v[i]; 
		draw.third[p.cnt-1][i] = p.v[i];
	}
}