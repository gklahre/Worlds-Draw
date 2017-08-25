#include <stdio.h>
#include <stdlib.h>
#include "WD.h"

int main(int argc, char ** argv){
	if(argc != 2){
		printf("Wrong number of arguments.\n");
		return THE_EXIT_FAILURE;
	}
	int n = atoi(argv[1]);
	int i, j;
	Draw * D = allocateDraw();
	printf("Hey there, %d!\n",n);
	perm(4, D);
	printf("\nNow for a test!\n");
	for(i=0;i < 24; i++){
		printf("\nCycle %d: ");
		for(j=0;j<4;j++){
			printf("%d",D->first[i][j]);
		}
	}
	freeDraw(D);
}

Draw * allocateDraw(void){
	int i;
	Draw * D = malloc(sizeof(Draw));
	D->first = malloc(sizeof(int *) * 24);
	D->third = malloc(sizeof(int *) * 24);
	D->groups = malloc(sizeof(int *) * 4);
	D->teams = malloc(sizeof(int *) * 16);
	D->teamResults = malloc(sizeof(int *) * 16);

	for(i=0;i < 24;i++){
		D->first[i] = malloc(sizeof(int) * 4);
	}
	for(i=0;i < 24;i++){
		D->third[i] = malloc(sizeof(int) * 4);
	}
	for(i=0;i < 4;i++){
		D->groups[i] = malloc(sizeof(int) * 4);
	}
	for(i=0;i < 16;i++){
		D->teams[i] = malloc(sizeof(int) * 2);
	}
	for(i=0;i < 16;i++){
		D->teamResults[i] = malloc(sizeof(int) * 3);
	}
	return D;
}

void freeDraw(Draw * D){
	int i;
	for(i=0;i < 24;i++){
		free(D->first[i]);
	}
	for(i=0;i < 24;i++){
		free(D->third[i]);
	}
	for(i=0;i < 4;i++){
		free(D->groups[i]);
	}
	for(i=0;i < 16;i++){
		free(D->teams[i]);
	}
	for(i=0;i < 16;i++){
		free(D->teamResults[i]);
	}
	free(D->first);
	free(D->third);
	free(D->groups);
	free(D->teams);
	free(D->teamResults);
	free(D);
}