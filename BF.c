#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int graph[1100][1100] ;
int buff[1100][1100] ;
char strgraph[1100*1100] ;
int vis[1100][1100] ;
int step , least ;
int n, m ;
char path[1100] ;
int pathcnt ;
char res[1500];
int *way;

int check(int k){
	int i = 0, j = 0;
	int s = 0;
	while (i < n && j < m) {
		if (way[s++ % k] == 0) i++;
		else j++;
		if (graph[i][j]==1) return 0;
	}
	return 1;
}

// D 0	R 1
int brute_force(int k){
	int i, j;
	for (i = 0; i < (1<<k); i++) {
		int tmp = i;
		way = (int *)malloc(sizeof(int)*k);
		for (j = 0; j < k; j++) {
			way[j] = tmp%2;
			tmp /= 2;
		}
		if (check(k)) return 1;
		free(way);
	}
	return 0;
}

int BF_steps(){
	int i;
	for (i = least; i <= step; i++) {
		if (brute_force(i)) 
			return i;
	}
	return -1;
}

void runc(char *a, char *b, char *c, char *d, char *e, char *r) {
	int i, j;
	//freopen ("in.txt", "r", stdin) ;
	sscanf (a,"%s", strgraph) ;
	sscanf(b,"%d",&step);
	sscanf(c,"%d",&least);	
	sscanf(d,"%d",&n);
	sscanf(e,"%d",&m);
	memset(res,'\0',sizeof res);
//	scanf ("%d %d%*c", &n, &m) ;
	for (i = 0 ; i < n ; i++)
		for (j = 0 ; j < m  ;j++)
		//	scanf ("%d%*c", &graph[i][j]) ;
			graph[i][j] = ((strgraph[i*m+j]=='X')?1:0) ;
//	for (i = 0 ; i < n ; i++)
//	{
//		for (j = 0 ; j < m ;j++)
//			printf ("%d", graph[i][j]) ;
//		printf ("\n") ;
//	}
	int S = BF_steps();
	for (i = 0; i < S; i++) {
		if (way[i]) res[i] = 'R';	//putchar('R');
		else res[i] = 'D'; 		//putchar('D');
	}
	res[S] = '\0';
	strcpy(r,res);
}

//int main(int argc, char *argv[]) {
//	int i, j;
//	freopen ("in.txt", "r", stdin) ;
//	scanf ("FVterrainString=%[^&]", strgraph) ;
//	scanf ("&FVinsMax=%d&FVinsMin=%d", &step, &least) ;
//	scanf ("&FVboardX=%d&FVboardY=%d", &n, &m) ;
//	scanf ("&FVlevel=%*d") ;
//	for (i = 0 ; i < n ; i++)
//		for (j = 0 ; j < m  ;j++)
//		graph[i][j] = ((strgraph[i*m+j]=='X')?1:0);
//
//	int S = BF_steps();
//	for (i = 0; i < S; i++) {
//		if (way[i]) putchar('R');
//		else putchar('D');
//	}
//	puts("");
//	return 0;
//}

