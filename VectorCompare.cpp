#include <iostream>
#include <vector> ;
using namespace std;

void compare(vector<int>& a, vector<int>& b){
    bool test;
   for(auto n : a){
       test = true;
       for(auto m : b){
           if( n == m)
                test = false;
       }
       if(test)
            cout << n << " ";
   }
    
}

vector<int> input(){
    
    vector<int> vec;
    int x;
    while(true){
        cin >> x;
        vec.push_back(x);
        if(x == 0)
            break;
    }
    return vec;
}

int main()
{
    
    cout << "Input vector Nr.1 : " << endl;
    vector<int> vec1 = input();
    
    cout << "Input vector Nr.2 : " << endl;
    vector<int> vec2 = input();
    
    cout << "Compare result: " << endl;
    compare(vec1, vec2);
    return 0;
}

