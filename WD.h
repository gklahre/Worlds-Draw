typedef struct SwapPass {
  int cnt;
  int *v;
  int *d;
} SwapPass;

typedef struct Draw {
	//24 Possible permutations of 4 teams.
	int ** first;
	int ** third;
	//4 groups of 4 teams.
	int ** groups;
	//16 Teams: Region, Weight
	int ** teams;
	//16 Teams: GoD, GoL, (Avg. Team Place, or % of time they are among the 2 best.)
	int ** teamResults;
	int numPerms;
	int max;

} Draw;

Draw * allocateDraw(void);
void freeDraw(Draw * D);
void perm(int n);

#define THE_EXIT_FAILURE 0
#define THE_EXIT_SUCCESS 1