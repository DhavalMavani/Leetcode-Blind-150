#include <bits/stdc++.h>


using namespace std;

void pairFunction()
{

    pair<int, int> p(13, 1989);
    cout << p.first << " " << p.second << endl;

    pair<int, int> p3 = {1314, 2001};
    cout << p3.first << " " << p3.second << endl;

    pair<int, pair<int, int>> p2(14, p);
    cout << p2.first << " " << p2.second.second << endl;
    // cin>>p2.second.second;

    pair<int, string> p9 = {13, "Taylor"};
    pair<int, string> arr[] = {{4, "Dhaval"}, p9};
    cout << arr[1].second << endl;
};

void vectorFunction()
{

    vector<int> v1 = {1, 2, 3};
    v1.push_back(14);
    v1.emplace_back(13);
    cout << "v1 " << v1[4] << endl;

    vector<pair<int, string>> v2 = {{1, "tay"}, {2, "abc"}}; // or vector<pair<int,string>> v2 {{1,"tay"},{2,"abc"}};
    v2.push_back({3, "dhaval"});
    v2.emplace_back(4, "taylor");
    cout << v2[3].second << endl;

    vector<pair<int, int>> v3(5, {13, 1989});
    cout << v3[4].first << endl;

    vector<int> v4 = v1; // or vector <int> v4 (v1) ;        or          vector <int> v4 = (v1);
    cout << "v4 " << v4[3] << endl;

    // v1={1,2,3,14,13}
    cout << v1.back() << "\n"; // prints 13 (last element)



    // v2 = {{1, "tay"}, {2, "abc"}, {3, "dhaval"}, {4, "taylor"} }
    vector <pair<int, string>>::iterator it=v2.begin();
    cout<<(*(it)).second<<endl;


    it=v2.end();
    it--;
    cout<<(*(it)).second<<"\n\n";

    vector <pair<int, string>>::reverse_iterator rit = v2.rbegin();                         
    rit = v2.rend();

    for (vector <pair<int, string>>::iterator it2 = v2.begin(); it2!=v2.end() ; it2++)
    {
        cout<< (*(it2)).first<< " -> "<<(*(it2)).second<<endl;
    } 
    cout<<endl;
    // 1 -> tay
    // 2 -> abc
    // 3 -> dhaval
    // 4 -> taylor

    for (auto it2 = v2.begin(); it2!=v2.end() ; it2++)
    {
        cout<< (*(it2)).first<<" ";
    }
    cout<<endl;

    for (auto it2 : v2) // over here it2 is not a iterator, it is a pair because v2 contains pair data type
    {
        cout<< it2.second<<" ";
    }
    cout<<endl;
    

    // v1={1,2,3,14,13}
    
    v1.erase(v1.begin()+1);
    // v1={1,3,14,13}
    
    v1.erase(v1.begin()+1, v1.begin()+3);
    // v1={1,13}

    for (auto i : v1)
        cout<<i<<" ";
    cout<<endl;
    
    // Inster Function
    v1.insert(v1.begin()+1,2);
    // v1={1,2,13}

    v1.insert(v1.begin()+2,2,66); 
    // v1={1,2,66,66,13}

    vector <int> v5 ={3,3,3,3};
    v5.insert(v5.begin()+4,v1.begin(), v1.end());
    // v5={3,3,3,3,1,2,66,66,13}

    for (auto i : v5)
        cout<<i<<" ";
    cout<<endl;

    // v1={1,2,66,66,13}
    v1.size(); // 5

    v1.pop_back(); // v1={1,2,66,66}

    v1.swap(v5); // v1={3,3,3,3,1,2,66,66,13} v5={1,2,66,66} 

    v5.clear(); // erases the entire vector

    v1.empty(); // 0 or false
    v5.empty(); // 1 or true
};

void listFunction(){
    list <int> ls ={1,2,3,4,5,6,7,8};
    ls.push_back(2); // {2}  to insert an element at the end of the list.
    ls.emplace_back(5); // {2,5} to insert an element at the end of the list.
    ls.push_front(1);  // to insert an element at the front of the list.
    ls.emplace_front(9); 
    ls.emplace_front(-1);

    ls.pop_back(); //  deletes the last element of the list.
    ls.pop_front(); // deletes the front element of the list.
    ls.reverse(); //reverse the list.

    // ls={2,8,7,6,5,4,3,2,1,1,9}
    
    cout<<ls.front()<<endl; //2     // it gives a reference to the first element of the list.
    cout<<ls.back()<<endl; //9     // it gives a reference to the last element of the list.

    ls.sort();       // sorts the list in ascending order.
    ls.size();      //11    // returns the number of elements on the list.
    ls.empty();     // to check if the list is empty or not.


    for ( auto i = ls.begin(); i !=ls.end(); i++ )
        cout<<*(i)<<" ";
    cout<<endl;
}

void stackFunction(){
    stack <int> st,st2;
    st.push(1);
    st.push(2);
    st.push(3);
    st.emplace(4);
    st.emplace(5);
    st.emplace(6);

    st.top(); //6  //returns the element at the top of the stack.
    st.size(); // returns the number of elements on the stack.
    st.empty(); // to check if the stack is empty or not.
    st.swap(st2); // swap the contents of one stack with another stack of same type but the size may vary
}

void queueFunction(){
    queue <int> q1,q2;

    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.emplace(4);
    q1.emplace(5);
    q1.emplace(6);

    q1.pop();
    q1.front();    //2  // returns a reference to the first element of the queue
    q1.back();     //6  // returns a reference to the last element of the queue
    q1.size();          // returns the number of elements on the queue.
    q1.empty();         //  to check if the queue is empty or not.
    q1.swap(q2);

}

void priorityQueueFunction(){

    // first element will be the maximum of all elements in the queue
    // max heap (implemented by default)
    priority_queue<int> pq1,pq2;

    pq1.push(5);            //{5}
    pq1.emplace(2);         //{5,2}
    pq1.emplace(8);         //{8,5,2}
    pq1.emplace(10);        //{10,8,5,2}
    pq1.emplace(1);         //{10,8,5,2,1}
    pq1.emplace(3);         //{10,8,5,3,2,1}
    pq1.emplace(13);        //{13,10,8,5,3,2,1}

    pq1.top();              //13
    pq1.pop();
    pq1.size();
    pq1.swap(pq2);


    // min heap

    priority_queue< int , vector<int>, greater<int> >pq3;

    pq3.push(5);            //{5}
    pq3.emplace(2);         //{2,5}
    pq3.emplace(8);         //{2,5,8}
    pq3.emplace(10);        //{2,5,8,10}
    pq3.emplace(1);         //{1,2,5,8,10}
    pq3.emplace(3);         //{1,2,3,5,8,10}
    pq3.emplace(13);        //{1,2,3,5,8,10,13}

    pq3.pop();
    pq3.top();              // 2
    
}

void setFunction(){
    
    // sorted and unique

    set <int> st;

    st.insert(3);       // {3}
    st.emplace(2);      // {2,3}
    st.insert(3);       // {2,3}
    st.emplace(1);      // {1,2,3}
    st.emplace(6);      // {1,2,3,6}
    st.emplace(5);      // {1,2,3,5,6}
    st.emplace(13);      // {1,2,3,5,6,13}
    st.emplace(14);      // {1,2,3,5,6,13,14}
    st.emplace(15);      // {1,2,3,5,6,13,14,15}
    st.emplace(16);      // {1,2,3,5,6,13,14,15,16}
    st.emplace(17);      // {1,2,3,5,6,13,14,15,16,17}

    // Functionality of insert in vector can be used also, that only increases efficiency
    // begin(), end(), rbegin(), rend(), size(),
    // empty () and swap() are same as those of above

    auto it = st.find(2);
    cout<<*it<<endl;  // 2
    it = st.find(10);
    cout<<*(it)<<endl;
    
    st.erase(3);        // erases 3 // takes logarithmic time
    it=st.find(6);
    st.erase(it); // erases 4 // takes constant time

    auto it2= st.find(13);
    auto it3= st.find(16);
    st.erase(it2,it3);
    cout << "Elements after deleting the first element: ";
    for (auto it = st.begin(); it != st.end(); it++) {
        cout << * it << " ";
    }
    cout<<endl;
    
    st.count(2);  // returns true or false based on whether the element is present in the set or not.

    // lower bound() and upper bound() function works in the same way as in vector it does.
    it=st.lower_bound(2);
    it=st.upper_bound(4);

}

void multisetFunction(){

    // sorted but not unique

    multiset <int> mst;

    mst.emplace(2);
    mst.emplace(2);
    mst.insert(1);
    mst.emplace(1);
    mst.emplace(1);
    mst.emplace(1);
    mst.emplace(3);     //{1,1,1,1,2,2,3}
    
    mst.erase(2);              // erases all 2's
    mst.erase(mst.find(1));     // only single 1 erased
    // rest all function same as set
     
}

void unorderedSetFunction(){

    // uniquie but not sorted

    unordered_set <int> ust;

    ust.emplace(2);
    ust.emplace(2);
    ust.insert(1);
    ust.emplace(1);
    ust.emplace(1);
    ust.emplace(1);
    ust.emplace(3);     //{2,1,3}

    // lower bound and upper bound function does not work as it is unsorted
    // rest all function as set
}

void mapFunction(){
    // {key,value}
    // each element consists of a key value and a mapped value
    // key is unique for each element. No two mapped values can have the same key values.
    // everything is stored in sorted order of key

    map <int, string> mp1;
    map <int , pair<int,string> > mp2;
    map <pair<int,string>, int > mp3;

    mp1.insert({1, "Apple"});
    mp1[2] = "Banana";
    mp1.emplace(3, "Cherry");

    mp1[2];     // Banana


    mp2.insert({1, {10, "Alice"}});
    mp2.insert({2, {20, "Bob"}});
    mp2.insert({3, {30, "Charlie"}});
    mp2.emplace(4, make_pair(40, "David"));
    mp2.emplace(5, make_pair(50, "Eve"));
    mp2.emplace(6, make_pair(60, "Frank"));

    mp3.insert( { {1, "Toyota Camry"}, 2020} );
    mp3.insert({{2, "Honda Civic"}, 2019});
    mp3.insert({{3, "Ford Mustang"}, 2021});
    mp3.emplace(make_pair(4,"Mercedes G-wagon"),2021);
    mp3[{5,"BMW X6"}]=2023;

    for(auto it: mp2)
        cout<<it.second.second<<" ";
    cout<<endl;

    for (auto it: mp3)
        cout<<it.first.second<<" ";
    cout<<endl;

    
    auto it = mp2.find(5);          // to search for an element in the map.
    cout << (*it).second.second<<endl;      // Eve
    it = mp2.find(10);                      // Element with key 10 dosen't exist, so it points iterator to mp2.end()

    auto it2 = mp3.find({3, "Ford Mustang"});
    cout<< (*it2).second<<endl;             // 2021

    mp1.begin();        // return an iterator pointing to the first element in the map.
    mp1.end();          // returns an iterator to the theoretical element after the last element.
    mp1.size();         // returns the number of elements on the map.
    mp1.empty();        // to check if the map is empty or not.
    mp1.erase(2);       // to delete a single element or elements between a particular range.
    // mp1.erase(iterator position);
    // mp1.erase(iterator position 1, iterator position 2);
    mp1.clear();        // deletes all the elements in the map.        
}

void multimapFunction(){
    // everything same as map but can store duplicate keys
    // each element consists of a key value and a mapped value
    // everything is stored in sorted order of key

    multimap <int, pair<int,int> > mmp;

    mmp.insert({1,{2,6}});
    mmp.emplace(1,make_pair(2,22));
    mmp.emplace(2,make_pair(3,2));
    mmp.emplace(2,make_pair(1,23));
    mmp.emplace(1,make_pair(15,2));

    // only mpp [key] cannot be used here
    // mmp[2].first; ❌
}

void unorderedmapFunction(){
    // everything same as map but not sorted 
    // each element consists of a key value and a mapped value
    // key is unique for each element. No two mapped values can have the same key values.

    unordered_map <int, int> ump;

    ump.insert({1,2});
    ump.emplace(3,4);
    ump.emplace(10,14);
    ump.emplace(6,32);
    ump.emplace(5,46);
    ump[5]=69;
    ump.emplace(5,45);  // If you use the insert() function to insert a new element with a key that already exists in the map, 
                        // the insertion will fail, and the existing element will not be modified. 

    cout<<ump[5];  //69

}

bool comp(pair<int, int> p1, pair<int, int> p2){
    if (p1.second<p2.second) return true;
    else if (p1.first>p2.first) return true;
    else return true;
}

void sortFunction(){

    int arr[]= {5, 8, 3, 22, 7, 13, 9, 6, 4, 0};
    sort(arr,arr+ sizeof(arr)/sizeof(int), greater<int>() );

    for (auto i : arr)
        cout<<i<<" ";
    cout<<endl;
    
    vector <pair<int,string>> v1= {
        {1, "Apple"},
        {5, "Banana"},
        {2, "Cherry"},
        {11, "Durian"},
        {13, "Elderberry"},
        {6, "Fig"},
        {14, "Grape"}
    };

    sort(v1.begin(), v1.end(), greater<pair<int,string>> () );
    for (auto i : v1)
        cout<<i.first<<" "<<i.second<<endl;
    cout<<endl;



    vector < pair<int, int> > v2 = { {5,2}, {2, 1},{2, 1}, {4, 1}}; 

    sort(v2.begin(),v2.end(),comp);         // {4,1} {2,1} {2,1} {5,2} 

    /*
    bool comp(pair<int, int> p1, pair<int, int> p2){
        if (p1.second<p2.second) return true;
        else if (p1.first>p2.first) return true;
        else return true;
        } 
    */

    for (auto i : v2)
        cout<<"{"<<i.first<<","<<i.second<<"} ";

}

void builtinpopcountFunction(){

    int n=7;        // 7= 111 in binary
    int setBits= __builtin_popcount(n);     //3  //it returns number of set bit of a number or 
    n=6;        // 6=110
    setBits= __builtin_popcount(n);         // 2
    long long num = 165786578687;
    setBits= __builtin_popcountll(num);
}

void nextPermutationFunction(){
    // returns the next lexicographically greater permutation of the elements in the container passed to it as an argument.

    string str= "bca";
    do
    {
        cout<<str<<" ";
    } while ( next_permutation( str.begin(), str.end() ) );
    cout<<endl;

    sort(str.begin(),str.end());
    do
    {
        cout<<str<<" ";
    } while ( next_permutation( str.begin(), str.end() ) );
    


}




int main()
{

    // pairFunction();
    // vectorFunction();
    // listFunction();
    // stackFunction(); 
    // queueFunction();
    // priorityQueueFunction();
    // setFunction();
    // multisetFunction();    
    // unorderedSetFunction();
    // mapFunction(); 
    // multimapFunction();
    // unorderedmapFunction();
    // sortFunction();
    // builtinpopcountFunction();
    // nextPermutationFunction();



    cout << "\n\nC++ Standard Version: " << __cplusplus << endl;
    return 0;
}

// g++ -std=c++17 -o output_file STL.cpp
// alias g++='g++ -std=c++17'
