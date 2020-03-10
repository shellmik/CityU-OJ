#include<iostream>
#include<stdio.h>
using namespace std;

int index = 0;

//输出结果
void print(int board[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			if (board[k][i] == 1)
			{
				if (i != 0) printf(" ");//a space in front of the digit if not last
				printf("%d", k+1);
				break;
			}
		}
	}
}

//检查这个位置可不可以放棋子
bool ok(int board[8][8], int row, int col)
{
	int i, j;
	//Same row to the left
	for (int i = 0; i < col; i++)
	{
		if (board[row][i])
			return false;
	}

    //左上角	
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (board[i][j])
			return false;

	}

    //左下角
	for (i = row, j = col; j >= 0 && i < 8; i++, j--)
	{
		if (board[i][j])
			return false;
	}
		
	return true;
}

bool solve(int board[8][8], int col,int start_x, int start_y)
{
	if (col >= 8)//all queens are placed
	{
		if (board[start_x][start_y] == 1)
		{
			printf("%2d      ", ++index);
			print(board);
			printf("\n");//each test case in a new line
		}
		return true;
	}
	for (int i = 0; i < 8; i++)
	{
		if (ok(board, i, col))
		{
			board[i][col] = 1;
			if (solve(board, col + 1, start_x, start_y))
			{
				board[i][col] = 0;
				continue;
			}
			board[i][col] = 0;
		}
	}
	return false;
}

int main()
{
	int cases;
	scanf_s("%d", &cases);
	for (int i = 0; i < cases; i++)
	{
		//initialize
		index = 0;
		int start_x, start_y;
		int board[8][8] = { 0 };//from 0 to N-1

		//starting points
		scanf_s("%d %d", &start_x, &start_y);
		start_x--;
		start_y--;

		//printing
		if (i != 0) printf("\n");//a new line between test cases if not the last
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		solve(board, 0, start_x, start_y);
	}
}