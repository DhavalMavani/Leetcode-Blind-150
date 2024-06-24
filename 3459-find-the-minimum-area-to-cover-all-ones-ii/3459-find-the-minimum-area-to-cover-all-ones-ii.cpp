class Solution {
public:
    int minimumArea(vector<vector<int>>& grid,int l,int r,int t,int b) {
        int rLeft=INT_MAX,rRight=INT_MIN, cTop=INT_MAX, cBottom=INT_MIN;
        
        for(int i=t;i<=b;i++){
            for(int j=l;j<=r;j++){
                if(grid[i][j]==1){
                    rLeft=min(rLeft,i);
                    rRight=max(rRight,i);
                    cTop=min(cTop,j);
                    cBottom=max(cBottom,j);
                }
            }
        }
        
        if (rLeft == INT_MAX) return 0; // If no '1' is found in the subgrid, return 0

        return (rRight-rLeft+1)*(cBottom-cTop+1);
    }
    int minimumSum(vector<vector<int>>& grid) {
        
        int ans=1e9;
        int row=grid.size()-1,col=grid[0].size()-1;

        // case 1: (top row -> 1) ( bottom col -> 2 )
        for(int i=0;i<row;i++){
            int a1=minimumArea(grid,0,col,0,i);
            for(int j=0;j<col;j++){
                int a2=minimumArea(grid,0,j,i+1,row);
                int a3=minimumArea(grid,j+1,col,i+1,row);
                ans=min(a1+a2+a3,ans);
            }
        }

        // case 2: ( top row -> 2 ) (bottom row -> 1)
        for(int i=row;i>0;i--){
            int a1=minimumArea(grid,0,col,i,row);
            for(int j=0;j<col;j++){
                int a2=minimumArea(grid,0,j,0,i-1);
                int a3=minimumArea(grid,j+1,col,0,i-1);
                ans=min(a1+a2+a3,ans);
            }
        }

        // case 3: (left col -> 1) (right col -> 2)
        for(int i=0;i<col;i++){
            int a1=minimumArea(grid,0,i,0,row);
            for(int j=0;j<row;j++){
                int a2=minimumArea(grid,i+1,col,0,j);
                int a3=minimumArea(grid,i+1,col,j+1,row);
                ans=min(a1+a2+a3,ans);
            }
        }

        // case 4: (left col -> 2) (right col -> 1)
        for(int i=col;i>0;i--){
            int a1=minimumArea(grid,i,col,0,row);
            for(int j=0;j<row;j++){
                int a2=minimumArea(grid,0,i-1,0,j);
                int a3=minimumArea(grid,0,i-1,j+1,row);
                ans=min(a1+a2+a3,ans);
            }
        }


        // case 5: (col -> 3)
        for(int i=0;i<col-1;i++){
            int a1=minimumArea(grid,0,i,0,row);
            for(int j=i+1;j<col;j++){
                int a2=minimumArea(grid,i+1,j,0,row);
                int a3=minimumArea(grid,j+1,col,0,row);
                ans=min(a1+a2+a3,ans);
            }
        }

        // case 6: (col -> 3)
        for(int i=0;i<row-1;i++){
            int a1=minimumArea(grid,0,col,0,i);
            for(int j=i+1;j<row;j++){
                int a2=minimumArea(grid,0,col,i+1,j);
                int a3=minimumArea(grid,0,col,j+1,row);
                ans=min(a1+a2+a3,ans);
            }
        }

        return ans;
    }
};