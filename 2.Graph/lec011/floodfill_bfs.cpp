#include <iostream>
#include <vector>
#include <queue>
using namespace std; 
 
 
 bool isvalid(int r,int c,vector<vector<int>>& grid)
  {if(r<0 || c<0 || r>=grid.size()|| c>=grid.size())
      return false;
   return true;
      
  }
 vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1},{-1,1},{-1,-1},{1,-1},{1,1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n=grid.size();
        if(n==0 || grid[0][0]!=0|| grid[n-1][n-1]!=0)return -1;
        
        queue<int> q;
        q.push(grid[0][0]);
        grid[0][0]=1;
        int level =1;
        while(q.size()!=0)
        {
            int size=q.size();
            while(size-->0)
            {
                int vtx=q.front();q.pop();
                int r=vtx/n;
                int c=vtx%n;
               
                if(r==n-1 && c==n-1) return level;
                
                for(int i=0;i<8;i++)
                {
                    int x=r+dir[i][0];
                    int y=c+dir[i][1];
                    if(isvalid(x,y,grid) && grid[x][y]==0)
                    {
                        grid[x][y]=1;
                        q.push(x*n+y);
                    }

                }
            }
            level++;
        }
        
        
        
        return -1;  
    }