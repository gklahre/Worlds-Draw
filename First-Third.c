#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "draw.h"

void getFirstThird(Draw draw){
	perm(4,draw,poolperm);
}

//A function to be used exclusively in perm.
int poolperm(Draw draw,Permute p){
	int i;
	for(i=0,i<4;i++){
		draw.first[p.cnt-1][i] = ((p.v[i])- 1); 
		draw.third[p.cnt-1][i] = ((p.v[i]) + 11);
	}
}

void poolpermtest(Draw draw,teamNames[16][3]){
	int i, j;
	for(i=0;i<24;i++){		
		printf("Iteration %d|P1: %s|P2: %s|P3: %s|P4 :%s",i,teamNames[(draw.first[24][0])],\
			teamNames[(draw.first[24][1])],teamNames[(draw.first[24][2])],teamNames[(draw.first[24][3])]);
	}
}