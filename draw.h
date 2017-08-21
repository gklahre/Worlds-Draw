
typedef struct Results{

	int teamResults[16][3];
	int numPerms;
	
}Results;

typedef struct Permute{
	int v[8];
	int d[8];
	int cnt;
}Permute;

typedef struct Draw{
	int first[24][4];
	int third[24][4];
	int groups[4][4];
	int teams[16][2];
	Results * r;
	int max;
	
}Draw;

int poolpermtest(Draw draw,char teamNames[16][3]);
int poolperm(Draw draw,Permute p);
int perm(int n,Draw draw,int (*f)(Draw,Permute));
void createTeams(char teamNames[16][3]);
void getFirstThird(Draw draw);

#define LEFT 0
#define RIGHT 1