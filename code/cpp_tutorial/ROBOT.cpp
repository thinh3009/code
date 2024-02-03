/*#include "stdafx.h"
//#include <stdio.h>
#include<iostream>
const int MazeHeight = 9;
const int MazeWidth = 9;

char Maze[MazeHeight][MazeWidth + 1] =
{
    "# #######",
    "#   #   #",
    "# ### # #",
    "# #   # #",
    "# # # ###",
    "#   # # #",
    "# ### # #",
    "#   #   #",
    "####### #",
};

const char Wall = '#';
const char Free = ' ';
const char SomeDude = '*';

class COORD
{
public:
    int X;
    int Y;
    COORD(int x = 0, int y = 0) { X = x, Y = y; }
    COORD(const COORD &coord) { X = coord.X; Y = coord.Y; }
};

COORD StartingPoint(1, 0);
COORD EndingPoint(7, 8);

void PrintDaMaze()
{
    for (int Y = 0; Y < MazeHeight; Y++)
    {
        printf("%s\n", Maze[Y]);
    }
    printf("\n");
}

bool Solve(int X, int Y)
{
    // Make the move (if it's wrong, we will backtrack later.
    Maze[Y][X] = SomeDude;

    // If you want progressive update, uncomment these lines...
    //PrintDaMaze();
    //Sleep(50);

    // Check if we have reached our goal.
    if (X == EndingPoint.X && Y == EndingPoint.Y)
    {
        return true;
    }

    // Recursively search for our goal.
    if (X > 0 && Maze[Y][X - 1] == Free && Solve(X - 1, Y))
    {
        return true;
    }
    if (X < MazeWidth && Maze[Y][X + 1] == Free && Solve(X + 1, Y))
    {
        return true;
    }
    if (Y > 0 && Maze[Y - 1][X] == Free && Solve(X, Y - 1))
    {
        return true;
    }
    if (Y < MazeHeight && Maze[Y + 1][X] == Free && Solve(X, Y + 1))
    {
        return true;
    }

    // Otherwise we need to backtrack and find another solution.
    Maze[Y][X] = Free;

    // If you want progressive update, uncomment these lines...
    //PrintDaMaze();
    //Sleep(50);
    return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
    if (Solve(StartingPoint.X, StartingPoint.Y))
    {
        PrintDaMaze();
    }
    else
    {
        printf("Damn\n");
    }

    return 0;
}*/
#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int a[100][100];
bool ok [100][100];
int n;
vector <string> res;

void Try(int i, int j, string s){
	if (a[1][1]==0 || a[n][n]==0) return ;
	if (i==n && j==n)
		res.push_back(s);
	if (a[i+1][j]==1 && i!=n && !ok[i+1][j])
	{
		ok[i][j]=true;
		Try(i+1,j,s+"D");
		ok[i][j]= false;
	}
	if (a[i][j+1]==1 && j!=n && !ok[i][j+1])
	{
		ok[i][j]=true;
		Try(i,j+1,s+"R");
		ok[i][j]= false;
	}
	if (a[i][j-1]==1 && j!=1 && !ok[i][j-1])
	{
		ok[i][j]=true;
		Try(i,j-1,s+"L");
		ok[i][j]= false;
	}
	if (a[i-1][j]==1 && i!=1 && !ok[i-1][j])
	{
		ok[i][j]=true;
		Try(i-1,j,s+"U");
		ok[i][j]= false;
	}
	
}
void Solve()
{
	res.clear();
	cin>>n;
	for ( int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cin>>a[i][j];
			ok[i][j]=false;
		}
	}
	Try(1,1," ");
	if(res.size()==0)cout<<-1 ;
	else
	{
		sort(res.begin(),res.end());
		for (int i=0; i<res.size();i++)
		    cout<< res[i]<<" ";
	}
}
 int main()
 {
 	int t=1;
 	cin>>t;
 	while (t--)
 		Solve();
 		
 	return 0;
 }
/*#include<iostream>
#include<vector>
#include <Windows.h>
#include <stdlib.h>
using namespace std;
int n = 9;
vector <int> res;
bool ok[10][10];
int a[10][10] = { 
	{9,3,4,7,3,1,2,6,3},
	{9,1,9,5,2,1,4,5,6},
	{9,7,8,4,5,1,2,5,1},
	{2,3,9,1,4,1,2,4,1},
	{2,4,1,2,5,6,8,5,8},
	{2,5,7,4,7,3,7,2,6},
	{2,3,4,1,6,8,4,8,2},
	{4,5,1,7,2,9,5,1,2},
	{5,8,9,6,3,1,4,2,5}
	};
int b[10][10] = { 
	{9,3,4,7,3,1,2,6,3},
	{9,1,9,5,2,1,4,5,6},
	{9,7,8,4,5,1,2,5,1},
	{2,3,9,1,4,1,2,4,1},
	{2,4,1,2,5,6,8,5,8},
	{2,5,7,4,7,3,7,2,6},
	{2,3,4,1,6,8,4,8,2},
	{4,5,1,7,2,9,5,1,2},
	{5,8,9,6,3,1,4,2,5} 
	};
int p[10][10]={
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
};
bool ssl(int l,int x, int t,int p){
	if(l>=x && l>=t && l>=p){
		return true;
	}
	else{
		return false;	
	}
}
bool ssx(int l,int x, int t,int p){
	if(x>=l && x>=t && x>=p){
		return true;
	}
	else{
		return false;	
	}
}
bool sst(int l,int x, int t,int p){
	if(t>=l && t>=x && t>=p){
		return true;
	}
	else{
		return false;	
	}
}
bool ssp(int l,int x, int t,int p){
	if(p>=l && p>=t && p>=x){
		return true;
	}else{
		return false;	
	}
}
void xuat(int pi,int pj){
	for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (pi == i && pj == j)
                    cout << '$';
                else
                    cout << a[i][j];
            cout << endl;
            
        }
        Sleep(1000);
        system("cls");
}
void Try(int i,int j) {
			res.push_back(a[i][j]);
			p[i][j] = 1;
			ok[i][j] = false;
			b[i][j]=NULL;
			xuat(i,j);
			if (ssx(b[i-1][j],b[i+1][j],b[i][j-1],b[i][j+1]) && ok[i + 1][j] ) {//xu?ng
				Try(i+1,j);
				
			}
			else if ( ssp(b[i-1][j],b[i+1][j],b[i][j-1],b[i][j+1])&& ok[i][j + 1]) {//ph?i
				Try(i,j + 1);
			}
			else if (ok[i][j - 1] && sst(b[i-1][j],b[i+1][j],b[i][j-1],b[i][j+1])) {//trái
				Try(i,j-1);
			}
			else if (ok[i-1][j] && ssl(b[i-1][j],b[i+1][j],b[i][j-1],b[i][j+1])) {//lên	
				Try(i-1,j);
			}
}
void Solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ok[i][j] = true;
		}
	}
}
int main()
{

	int s=0;
	Solve();
	//p[0][0] = 1;
	Try(0,0);
	for(int i=0;i<res.size();i++){
		s+=res[i];
		cout << res[i] << " ";
	}
	cout <<endl<< s;
}*/