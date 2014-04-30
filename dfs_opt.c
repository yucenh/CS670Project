# include <stdio.h>
# include <string.h>

int graph[1100][1100] ;
int buff[1100][1100] ;
char strgraph[1100*1100] ;
int vis[1100][1100] ;
int step , least  ;
int n, m ;
char path[1100] ;
int pathcnt ;
char res[1500];


int dfs (int x, int y, int r, int c){
	if (x > r || y > c) return 0 ;
	if (buff[x][y] == 1) return 0 ;
	if (vis[x][y] == 1) return 0 ;
	vis[x][y] = 1 ;
	if (x == r  && y == c) return 1 ;
	if (dfs (x+1, y, r, c)){
		path[pathcnt++] = 'D' ;
		return 1 ;
	}
	if (dfs (x, y+1, r,c))
	{
		path[pathcnt++] = 'R' ;
		return 1 ; 
	}
	return 0 ;
}


void outputpath()
{
	int i ;
	int k = 0;
//	printf ("http://www.hacker.org/runaway/index.php?name=lzsz1212&password=9gufba2&path=") ;
	for (i = pathcnt-1 ; i >= 0; i--)
	{
	//	if (path[i] == 'R') printf ("°˙") ;
	//	else printf ("°˝") ;
		if (path[i] == 'R') {
			res[k++] = 'R';
//			printf ("R") ;
		}
		else {
			res[k++] = 'D';
//			printf ("D") ;
		}
	}
	res[k] = '\0';
//	printf ("\n") ;
//	puts(res);
}


int test(int col, int row)
{
	int x = 0, y = 0 ;
	int xx, yy ;
	int i, j ;
	for (i = 0 ; i <= row ; i++)
		for (j = 0 ; j <= col ; j++)
			buff[i][j] = 0 ;
	while (x <= n && y <= m)
	{
		for (i = 0 ; i <= row && x+i <= n ; i++)
			for (j = 0 ; j <= col && y+j <= m ;j++)
			{
				if (graph[x+i][y+j] == 1)
					buff[i][j] = 1 ;
			}
		xx = x + row ;
		yy = y + col ;
		if (xx <= n && yy <= m)
			if (graph[xx][yy] == 1) return 0 ;
		x = xx, y = yy ;
	}
	memset (vis, 0, sizeof(vis)) ;
	pathcnt = 0 ;
	if (dfs (0, 0, row, col))
	{
	//	for (i = 0 ; printf ("\n"), i <= row ; i++)
	//		for (j = 0 ; j <= col ; j++)
	//			printf ("%d ", buff[i][j]) ;
		outputpath() ;
		return 1 ;
	}
	return 0 ;
}


void gao()
{
	int i, j ;
	for (i = step-1 ; i >= least-1 ; i--)
//	for (i = least -1 ; i <= step - 1 ; i ++)
		for (j = 1 ; j <= i ; j++)
		{
			if (test(i-j+1, j))
			{
			//	printf ("%d, %d\n", j, i-j+1) ;
				return ;
			}
			
		}
	puts ("no") ;
}

void runc(char *a, char *b, char *c, char *d, char *e, char *r)
{
	int i, j ;
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
	gao();
	strcpy(r,res);
//	puts(r);
	puts ("") ;
}


