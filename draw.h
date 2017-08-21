typedef struct Draw{
	int first[24][4];
	int third[24][4];
	int groups[4][4];
	int teams[16][2];
	Results * r;
	int max;
	
} Draw;

typedef struct Results{

	int teamResults[16][3];
	int numPerms;
	
} Results;

typedef struct Permute{
	int v[8];
	int d[8];
	int cnt;
} Permute;

#define LEFT 0
#define RIGHT 1