package test;

import java.util.Scanner;
public class recursiveMaze{
	private static int N=8;
	private static int[][] maze={
			{0,0,0,0,0,0,0,1},
			{0,1,1,0,1,1,0,1},
			{0,0,0,1,0,0,0,1},
			{0,1,0,0,1,1,0,0},
			{0,1,1,1,0,0,1,1},
			{0,1,0,0,0,1,0,1},
			{0,0,0,1,0,0,0,1},
			{0,1,1,1,0,1,0,0}
	};
	
private static final int pathway_color=0;
private static final int wall_color=1;
private static final int blocked_color=2;
private static final int path_color=3;	

public static boolean findMazePath(int x, int y){
if(x<0 || y<0 || x>=N || y>=N)        
	return false;
else if(maze[x][y]!=pathway_color)    //if not path, false
	return false;
else if(x==N-1&&y==N-1){              //if exit, true
	maze[x][y]=path_color;
	return true;
}
else{                                     
	maze[x][y]=path_color;
	if(findMazePath(x-1,y)||findMazePath(x,y+1)||
			findMazePath(x+1,y)||findMazePath(x,y-1)){
		return true;
	}
	maze[x][y]=blocked_color;
	return false;
	}
}
private static void printMaze() {
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			System.out.print(maze[i][j]);
		}
		System.out.print('\n');
	}
	System.out.print('\n');
}
		
	public static void main(String[] args)
	{
		printMaze();
		findMazePath(0,0);
		printMaze();
	}
}
