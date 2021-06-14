
#include <iostream>
#include <cmath>
#include <regex>
using namespace std;

int main()
{

    regex pat("^[-+]?\\d*\\.?\\d*$"); //RegEx, kas pārbauda, vai ir skaitlis!
    
    string C; // mainīgais cikla turpināšanas noteikšanai
    while(true){
        cout << "Info:\n";
        cout << "\ta(x) = 3x ^ 2 + 4x\n\tb(x) = x + 1/x\n\n";
        cout << "\tf1(x) = (a + b) ^ 0.5\n\tf2(x) = (1 - a) / 10 + b\n\n\tC = a < 10\n" << endl;
        cout << "Padoms: a < 10, ja x = (-2.611; 1.277)\n" << endl;
        
        string xs; //mainīgais lietotāja ievadei, kuru var pārbaudīt ar RegEx
        double x, a, b; //mainīgie funkcijas izpildei
        
        cout << "Ievadiet x vērtību:\nx = ";
        cin >> xs;
        
        if (!regex_match(xs, pat)){ //RegEx pārbaude
            cout << "Nepareiza ievade! Jāievada skaitlis!" << endl;
        }
        
        else{
            x = stod(xs); //pārveido string xs uz double x
            if (x == 0)
                cout << "Kļūda - dalīšana ar 0!" << endl;
            else{
                a = x * (3 * x + 4);
                b = 1 / x + x;
                
                if (a < 10)
                    if(a + b < 0)
                        printf("Y = f1(x) = %.3fi\n", sqrt(abs(a + b)));
                    else
                        printf("Y = f1(x) = %.3f\n", sqrt(a + b));
                else
                    printf("Y = f2(x) = %.3f\n",  0.1 - 0.1 * a + b);
            }
        }
        
        cout<<"\nVai vēlaties turpināt? ('Y' vai 'y', lai turpinātu!)" << endl;
        cin >> C;
        if(C != "y" && C != "Y")
            break;
    }
    
    cout << "Programma izbeigta!" << endl;
    
    return 0;
}




