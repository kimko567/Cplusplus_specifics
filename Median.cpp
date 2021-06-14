#include <iostream>
using namespace std;

int main(){
    
    int a, b, c;
    
    cout << "Input three nnumbers: " << endl;
    
    cin >> a >> b >> c;
    
    cout << "median: ";
    
    if (a == b && b == c)
        cout << a;

    if ((a > b && a < c) || (a > c && a < b))
        cout << a;
    if ((b > a && b < c) || (b > c && b < a))
        cout << b;
    if ((c > b && c < a) || (c > a && c < b))
        cout << c;

    return 0;
}

