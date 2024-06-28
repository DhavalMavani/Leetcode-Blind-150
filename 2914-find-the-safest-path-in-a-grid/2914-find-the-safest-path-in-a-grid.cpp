class Solution {
public:
    
    bool isPossible(vector<vector<int>>& grid,int &safenessFactor){
        int offset[]={0,1,0,-1,0};
        if(grid[0][0]<safenessFactor) return false;
        int n=grid.size();
        queue<int> q;
        q.emplace(0);
        vector<bool> visited(n*n,false);
        visited[0]=true;
        while(!q.empty()){
            int s=q.size();

            for(int i=0;i<s;i++){
                int t=q.front();
                q.pop();
                int x=t/n, y=t%n;
                if(x==n-1 && y==n-1) return true;
                for(int j=0;j<4;j++){
                    int a=x+offset[j], b= y+offset[j+1];
                    if(a>=0 && b>=0 && a<n && b<n && !visited[a*n+b]){
                        visited[a*n+b]=true;
                        if(grid[a][b]>=safenessFactor) q.emplace(a*n+b);
                    }
                }
            }

        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return 0;

        queue<int> q;
        vector<bool> visited(n*n,false);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.emplace(i*n+j);
                    visited[i*n+j]=true;
                }
            }
        }

        
        int safety=0;
        int offset[]={0,1,0,-1,0};
        while(!q.empty()){
            int s=q.size();

            for(int i=0;i<s;i++){
                int t=q.front();
                q.pop();
                int x=t/n, y=t%n;
                grid[x][y]=safety;
                for(int j=0;j<4;j++){
                    int a=x+offset[j], b= y+offset[j+1];
                    if(a>=0 && b>=0 && a<n && b<n && !visited[a*n+b]){
                        visited[a*n+b]=true;
                        q.emplace(a*n+b);
                    }
                }
            }
            safety++;
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<endl;


        int l=1,r=n;
        while(l<=r){
            int mid=(l+r)/2;
            cout<<mid<<" ";
            if( isPossible(grid,mid) ){
                l=mid+1;
                cout<<"t | ";

            }
            else{
                r=mid-1;
                cout<<"f | ";
            }
        }

        return r;

    }
};