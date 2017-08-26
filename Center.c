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
	if(D == NULL){
		return THE_EXIT_FAILURE;
	}
	printf("Hey there, %d!\n",n);
	D->max = 21;
	perm(4,D);

	printf("\nNow for a test!\n");
	for(i=0;i < 24; i++){
		printf("\nCycle %d: ",i);
		for(j=0;j<4;j++){
			printf("%d",D->first[i][j]);
		}
	}
	freeDraw(D);
}

Draw * allocateDraw(void){
	int i;
	Draw * D = malloc(sizeof(Draw));
	if(D == NULL){
		printf("Memory issues.\n");
		return NULL;
	}
	D->first = malloc(sizeof(int *) * 24);
	if(D->first == NULL){
		printf("Memory issues.\n");
		return NULL;
	}
	D->third = malloc(sizeof(int *) * 24);
	if(D->third == NULL){
		printf("Memory issues.\n");
		return NULL;
	}
	D->groups = malloc(sizeof(int *) * 4);
	if(D->groups == NULL){
		printf("Memory issues.\n");
		return NULL;
	}
	D->teams = malloc(sizeof(int *) * 16);
	if(D->teams == NULL){
		printf("Memory issues.\n");
		return NULL;
	}
	D->teamResults = malloc(sizeof(int *) * 16);
	if(D->teamResults == NULL){
		printf("Memory issues.\n");
		return NULL;
	}

	for(i=0;i < 24;i++){
		D->first[i] = malloc(sizeof(int) * 4);
		if(D->first[i] == NULL){
		printf("Memory issues.\n");
		return NULL;
		}
	}
	for(i=0;i < 24;i++){
		D->third[i] = malloc(sizeof(int) * 4);
		if(D->third[i] == NULL){
			printf("Memory issues.\n");
			return NULL;
		}
	}
	for(i=0;i < 4;i++){
		D->groups[i] = malloc(sizeof(int) * 4);
		if(D->groups[i] == NULL){
			printf("Memory issues.\n");
			return NULL;
		}
	}
	for(i=0;i < 16;i++){
		D->teams[i] = malloc(sizeof(int) * 2);
		if(D->teams[i] == NULL){
			printf("Memory issues.\n");
			return NULL;
		}
	}
	for(i=0;i < 16;i++){
		D->teamResults[i] = malloc(sizeof(int) * 3);
		if(D->teamResults == NULL){
			printf("Memory issues.\n");
			return NULL;
		}
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