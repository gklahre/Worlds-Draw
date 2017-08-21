#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "draw.h"
int main(int argc,char ** argv){
	if(argc != 2){
		printf("Not enough arguments\n");
		return;
	}
	Draw draw;
	if(atoi(argv[1]) == 0){
		draw.max = atoi(argv[1]);
	}else{
		printf("Argument not an integer\n");
		return;
	}
	char teamNames[16][3];
	createTeams(teamNames);
	getFirstThird();
	poolpermtest(draw,teamNames);
	return 0;
}
void createTeams(int ** teamNames){
	//POOL 1 TEAMS
	teamNames[0] = "ROX";
	teamNames[1] = "EDG";
	teamNames[2] = "FW";
	teamNames[3] = "TSM";
	//POOL 2 TEAMS
	teamNames[4] = "G2";
	teamNames[5] = "SKT";
	teamNames[6] = "RNG";
	teamNames[7] = "H2K";
	teamNames[8] = "CLG";
	teamNames[9] = "SSG";
	teamNames[10] = "IM";
	teamNames[11] = "AHQ";
	//POOL 3 TEAMS
	teamNames[12] = "SPY";
	teamNames[13] = "C9";
	teamNames[14] = "ANX";
	teamNames[15] = "INZ";
}