typedef struct SwapPass {
  int cnt;
  int *v;
  int *d;
} SwapPass;

typedef struct Draw {
	//24 Possible permutations of 4 teams.
	int first[24][4];
	int third[24][4];
	//4 groups of 4 teams.
	int groups[4][4];
	//16 Teams: Region, Weight
	int teams[16][2];
	//16 Teams: GoD, GoL, (Avg. Team Place, or % of time they are among the 2 best.)
	int teamResults[16][3];
	int numPerms;
	int max;

} Draw;

#define EXIT_FAILURE 0
#define EXIT_SUCCESS 1