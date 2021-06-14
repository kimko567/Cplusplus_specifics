#include <iostream>
#include <set>
#include <map>
#include <regex>
using namespace std;

string trim(string s) {
    regex e("^\\s+|\\s+$");   // remove leading and trailing spaces
    return regex_replace(s, e, "");
}

string lower(string s){
    for(int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
    return s;
}

void add(map<string, set<string>> &dict){
    string word1, word2;
    
    cout << "first word: ";
    cin >> word1;
    word1 = lower(trim(word1));
    
    cout << "second word: ";
    cin >> word2;
    word2 = lower(trim(word2));
    
    if (word1 != word2){
        if (!dict.count(word1)){
            set<string> temp = {word2};
            dict[word1] = temp;
        }
        else{
            dict[word1].insert(word2);
        }
        if (!dict.count(word2)){
            set<string> temp = {word1};
            dict[word2] = temp;
        }
        else{
            dict[word2].insert(word1);
        }
    }
}

void count(map<string, set<string>> &dict){
    string word;
    
    cout << "word: ";
    cin >> word;
    
    word = lower(trim(word));
    
    if (dict.count(word)){
        int i = dict[word].size();
        cout << dict[word].size() << endl;
    }
    else{
        cout << 0 << endl;
    }
}

void check(map<string, set<string>> &dict){
    string word1, word2;
    
    cout << "first word: ";
    cin >> word1;
    word1 = lower(trim(word1));
    
    cout << "second word: ";
    cin >> word2;
    word2 = lower(trim(word2));
    
    if (word1 != word2 && dict.count(word1) && dict.count(word2)){

        if (dict[word1].count(word2)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    else{
        cout << "No" << endl;
    }
}
int main(){
    
    map<string, set<string>> dict;
    string command;
    while(true){
        cout << "cmd:> ";
        cin >> command;
        command = lower(trim(command));
        
        if (command == "add")
            add(dict);
        if (command == "count")
            count(dict);
        if (command == "check")
            check(dict);
        if (command == "done")
            break;
        
    }
}
