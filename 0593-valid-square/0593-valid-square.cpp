class Solution {
public:
    double calcDist(vector<int>& p1,vector<int>& p2){
        return  sqrt( (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]) );
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<double,int> mp;
        mp[calcDist(p1,p2)]++;
        mp[calcDist(p1,p3)]++;
        mp[calcDist(p1,p4)]++;
        mp[calcDist(p2,p3)]++;
        mp[calcDist(p2,p4)]++;
        mp[calcDist(p3,p4)]++;

        if(mp.size()!=2){
            return false;
        }
        
        if(mp[mp.begin()->first]!=4){
            return false;
        }
        return true;
    }
};