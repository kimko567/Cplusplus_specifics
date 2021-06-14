#include <iostream>
#include <map>
using namespace std;

string checkAnagram(string str1, string str2){
    
    if(str1.length() != str2.length())
        return "NO";
        
    map <char, int> m1;
    map <char, int> m2;
    
   for(char c : str1){
       c = tolower(c);
       m1[c]++;
     
   }
   for(char c : str2){
       c = tolower(c);
      m2[c]++;
    
   }
   
   if(m1 == m2)
        return "YES";
    else
        return "NO";
}

int main()
{
   string s1, s2;
   
   cout << "Input first word: ";
   cin >> s1;
   
   cout << "Input second word: ";
   cin >> s2;
   
   cout << checkAnagram(s1, s2) << endl;

    return 0;
}

