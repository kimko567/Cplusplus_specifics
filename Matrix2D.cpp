#include <iostream>
#include <regex>
#include <random>
using namespace std;


int matrix_row_input(){
    regex re("^\\d+$");
    while(true){
        string input_text;
        cout << "\nRindu skaits: ";
        cin >> input_text;
        if (regex_match(input_text, re) && stoi(input_text) != 0){
            return stoi(input_text);
        }
        else{
            cout << "IEVDES KĻŪDA! LŪDZU IEVDIET NATURĀLU SKAITLI!" << endl;
        }
    }
}

int matrix_column_input(){
    regex re("^\\d+$");
    while(true){
        string input_text;
        cout << "\nKolonu skaits: ";
        cin >> input_text;
        if (regex_match(input_text, re) && stoi(input_text) != 0){
            return stoi(input_text);
        }
        else{
            cout << "IEVDES KĻŪDA! LŪDZU IEVDIET NATURĀLU SKAITLI!" << endl;
        }
    }
}

double** create_matrix(int rows, int columns){
    regex re("^[-+]?[0-9]*\\.?[0-9]+$");
    cout << "Ievadiet matricas vērtības: " << endl;
    
    double** matrix = new double*[rows];
    for(int i = 0; i < rows; i++){
        matrix[i] = new double[columns];
    }
    
    for(int row = 0; row < rows; row++){
        for(int column = 0; column < columns; column++){
            while(true){
                string input_text;
                cout << "[" << row << "] [" << column << "]: ";
                cin >> input_text;
                if(regex_match(input_text, re)){
                    matrix[row][column] = stod(input_text);
                    break;
                }
                else{
                    cout << "IEVDES KĻŪDA! LŪDZU IEVADIET NATURĀLU SKAITLI!" << endl;
                }
            }
        }
    }
    return matrix;
}

double** random_matrix(){
    double** matrix = new double*[10];
    for(int i = 0; i < 10; i++)
        matrix[i] = new double[10];
    srand(time(0));    
    for(int row = 0; row < 10; row++){
        for(int column = 0; column < 10; column++){
            matrix[row][column] = (100 * double(rand())/RAND_MAX) - 50;
        }
    }
    return matrix;
}

void print_matrix(double** matrix, int rows, int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            printf("%-10.2f", matrix[i][j]);
        }
        cout << endl;
    }
}

void reverse_odd_rows(double** matrix, int rows, int columns){
    for(int row = 1; row < rows; row += 2){
        for(int column = 0; column < columns/2; column++){
            double temp = matrix[row][column];
            matrix[row][column] = matrix[row][columns - 1 - column];
            matrix[row][columns - 1 - column] = temp;
        }
    }
}

void swap_rows(double** matrix, int rows){
    for(int row = 0; row < rows - 1; row += 2){
        double* temp = matrix[row];
        matrix[row] = matrix[row + 1];
        matrix[row + 1] = temp;
    }
}

void free_matrix(double** matrix, int rows, int columns){
    for(int row = 0; row < rows; row++)
        free(matrix[row]);
    free(matrix);
}

int main(int argc, char** argv)
{

    string str;
    if(argc == 2)
        str = argv[1];
    
    if(str == "-rand"){   
        double** matrix = random_matrix();
        cout << "\nMatrica pirms pārveidošanas:" << endl;
        print_matrix(matrix, 10, 10);

        reverse_odd_rows(matrix, 10, 10);
        swap_rows(matrix, 10);
        cout << "\nMatrica pēc pārveidošanas:" << endl;
        print_matrix(matrix, 10, 10);
    
        free_matrix(matrix, 10, 10);   
    }
    else{
        int rows = matrix_row_input();
        int columns = matrix_column_input();
    
        double** matrix = create_matrix(rows, columns);
    
        cout << "\nMatrica pirms pārveidošanas:" << endl;
        print_matrix(matrix, rows, columns);

        
        reverse_odd_rows(matrix, rows, columns);
        swap_rows(matrix, rows);
        
        cout << "\nMatrica pēc pārveidošanas:" << endl;
        print_matrix(matrix, rows, columns);
    
        free_matrix(matrix, rows, columns);
    }
    
    return 0;
}
