#include<stdio.h>
#include<math.h>
int board[20],count;
void queen(int row,int n);

int main()
{
 	int n,i,j;
 	printf(" - N Queens Problem Using Backtracking -");
 	printf("\n\nEnter number of Queens:");
 	scanf("%d",&n);
 	queen(1,n);
 	printf("\nTotal Solutions with %d-Queens:%d",n,count);
 	return 0;
}
void print(int n)
{
 	int i,j;
 	printf("\nSolution %d:",++count);
 	for(i=1;i<=n;++i)
  		printf("%d  ",board[i]);
}

int place(int row,int column)
{
 	int i;
 	for(i=1;i<=row-1;++i)
 	{
    		if(board[i]==column)
   			return 0;
  		else
   			if(abs(board[i]-column)==abs(i-row))
    				return 0;
 	}
  	return 1; //no conflicts
}
void queen(int row,int n)
{
 	int column;
 	for(column=1;column<=n;++column)
 	{
  		if(place(row,column))
  		{
   			board[row]=column; //no conflicts so place queen
   			if(row==n) //dead end
    				print(n); //printing the board configuration
   			else //try queen with next position
    				queen(row+1,n);
  		}
 	}
}

