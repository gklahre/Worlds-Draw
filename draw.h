
typedef struct Results{

	int teamResults[16][3];
	int numPerms;
	
}Results;

typedef struct Permute{
	int v[16];
	int d[16];
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

void poolpermtest(Draw draw,const char *teamNames[16]);
int poolperm(Draw draw,Permute p);
void perm(int n,Draw draw,int (*f)(Draw,Permute));
void createTeams(const char* teamNames[16]);
void getFirstThird(Draw draw);

#define LEFT 0
#define RIGHT 1