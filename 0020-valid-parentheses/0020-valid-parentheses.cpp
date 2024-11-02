class Solution {
public:
    bool isValid(string s) {

        stack <int> s1;
        for (auto &ch: s){
            if(ch=='{' || ch=='(' || ch=='[') s1.emplace(ch);
            else if( !s1.empty() && ((ch=='}' && s1.top()=='{') || (ch==']' && s1.top()=='[') || (ch==')' && s1.top()=='(')) ) s1.pop();
            else return false;
        }
        
        return s1.empty();
    }
};