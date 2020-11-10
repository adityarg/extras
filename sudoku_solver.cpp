#include <iostream>

using namespace std;

const int n=9;
int mat[n][n];

bool isPresentInCol(int c, int x)
{
	for(int r=0;r<n;r++)
		if(mat[r][c]==x) return true;
	return false;
}

bool isPresentInRow(int r, int x)
{
	for(int c=0;c<n;c++)
		if(mat[r][c]==x) return true;
	return false;
}

bool isPresentInBox(int i, int j, int x)
{
	for(int r=0;r<3;r++)
		for(int c=0;c<3;c++)
			if(mat[r+i][c+j] ==x) return true;
	return false;
}

void printSudoku()
{
	for(int r=0;r<n;r++)
	{
		for (int c=0;c<n;c++)
		{
			if(c==3 || c==6) cout<<" | ";
			cout<<mat[r][c]<<" ";
		}
		if(r==2 || r==5)
		{
			cout<<endl;
			for(int i=0;i<n;i++) cout<<"---";
		}
		cout<<endl;
	}
}

bool findPosition(int &r, int &c)
{
	for(r=0;r<n;r++)
		for(c=0;c<n;c++)
			if(mat[r][c]==0) return true;
	return false;
}

bool valid(int r, int c, int x)
{
	return !isPresentInRow(r,x) && !isPresentInCol(c,x)
	&& !isPresentInBox(r-r%3 ,c-c%3,x);
}

bool sol()
{
	int r,c;
	if(!findPosition(r,c)) return true;
	for(int x=1;x<=9;x++)
	{
		if(valid(r,c,x))
		{
			mat[r][c]=x;
			if(sol()) return true;
			mat[r][c]=0;
		}
	}
	return false;
}

int main()
{
	cout<<"Input sudoku entries in row major order"<<endl;
	for(int i=0;i<n;i++)
		for(int j=0;i<n;j++) cin>>mat[i][j];

	if(sol()) printSudoku();
	else cout<<"No solution";
}