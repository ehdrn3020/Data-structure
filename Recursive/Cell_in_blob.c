//count cell in a blob

#include <stdio.h>

int BackgroundC = 0;  //white cell
int ImageC = 1;       //blue cell
int AlreadyC = 2;     //Cells to distinguish when a blue cell is once visited

int countCells(int (*grid)[8], int x,int y){  //grid[][8]

	if(x<0 || x>=8 || y<0 || y>=8) //1. inspection over value
		return 0;

	else if(grid[x][y]!=ImageC)    //2. inspection empty cell
		return 0;

	else{
		grid[x][y]=AlreadyC;    
			return 1 + countCells(grid,x-1,y+1) + countCells(grid,x,y+1)
			+ countCells(grid,x+1,y+1) + countCells(grid,x-1,y)
			+ countCells(grid,x+1,y) + countCells(grid,x-1,y-1)
			+ countCells(grid,x,y-1) + countCells(grid,x+1,y-1);
		//recursive
	}
}

int main(){
	int grid[8][8]={{1, 0, 0, 0, 0, 0, 0, 1},
	{0, 1, 1, 0, 0, 1, 0, 0},
	{1, 1, 0, 0, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 0, 0},
	{0, 1, 0 ,1, 0, 1, 0, 0},
	{0, 1, 0 ,1, 0, 1, 0, 0},
	{1, 0, 0, 0, 1, 0, 0, 1},
	{0, 1, 1, 0, 0, 1, 1, 1}};

	/*When receiving value
	int s1,s2;
	scanf("%d %d",&i,&j); 
	for(s1=0; s1<i; s1++){
	for(s2=0; s2<j s2++){
	scanf("%d",grid[s1][s2]);
	}
	}
	*/

	int i, j, result=0; 
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			result=countCells(grid,i,j);
			if(result>0)
			{
				printf("%d\n",result);   //output blob
			}

		}
	}

	for(i=0;i<8;i++){           //output all array value
		for(j=0;j<8;j++){
			printf("%d ",grid[i][j]);
		}
		printf("\n");
	}
}