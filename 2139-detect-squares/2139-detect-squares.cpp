class DetectSquares {
public:
    map<vector<int>,int> sq;
    void add(vector<int> point) {
        sq[point]++;
    }
    
    int count(vector<int> point) {
        int ans=0;
        for(auto i: sq){

            int side1= abs(point[1]-i.first[1]);
            int side2= abs(point[0]-i.first[0]);

            if(side1!=side2 || side1==0){
                continue;
            }
            // vector<int> temp1={point[0],i.first[1]};
            // vector<int> temp2={i.first[0],point[1]};

            ans=ans+i.second*sq[{point[0],i.first[1]}]*sq[{i.first[0],point[1]}];
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */