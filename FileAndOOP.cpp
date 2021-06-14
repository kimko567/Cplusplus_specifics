#include <iostream>
#include <vector>
#include <fstream>
#include <regex>
using namespace std;

class car{
    public:
        string model;
        int year;
        char transmission;
        int regnum;
        int drivelen;
        car(vector<string> info);
        void print_car();
};

car::car(vector<string> info){
    this->model = info[0];
    this->year = stoi(info[1]);
    this->transmission = info[2][0];
    this->regnum = stoi(info[3]);
    this->drivelen = stoi(info[4]);
}

void car::print_car(){
    printf("%-15s|%-8d|%-7c|%-15d|%-15d\n", this->model.c_str(), this->year, this->transmission, this->regnum, this->drivelen);
    
}        
const string WHITESPACE = " \n\r\t\f\v";
 
string ltrim(const string& s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == string::npos) ? "" : s.substr(start);
}
 
string rtrim(const string& s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}
 
string trim(const string& s)
{
    return rtrim(ltrim(s));
}

vector<string> split(string &str, char del){
	vector<string> res;
	string temp = "";
	for(char ch : str){
		if(ch == del){
			if(temp != ""){
				res.push_back(trim(temp));
				temp = "";
			}
		}
		else{
			temp += ch;
		}
	}
	if(temp != ""){
		res.push_back(trim(temp));
		temp = "";
	}
	return res;
}

bool is_valid_car(vector<string> info){
	regex isnum("^[1-9][0-9]*");
	regex isAM("^[am]$");
	if(regex_match(info[1], isnum) && regex_match(info[3], isnum) && regex_match(info[4], isnum) && regex_match(info[2], isAM))
		return true;
	else
		return false;
}

bool read_file(vector<car> &cars, vector<string> &errs){
	string filename;
    cout << "Ievadiet faila nosaukumu/atrašanās vietu: ";
    cin >> filename;
   	ifstream in(filename);
   	ofstream out("err.txt");
    if (in.is_open())
  	{
  		try{
	  		string line;
	    	while (true)
	    	{
				getline (in,line);
	    		string new_line = trim(line);
	    		vector<string> info = split(new_line, ';');
	    		if (info.size() == 5 && is_valid_car(info)){
					car c(info);
					cars.push_back(c);
				}
				else{
					errs.push_back(line);
				}
	    		if(in.eof())
	    			break;
	    	}
		}
		catch(...){
			cout << "\nFailu neizdevās atvērt - tas iespējams jau ir atvērts kādā citā procesā!\n" << endl;
		}
		try{
			for(string item : errs)
				out << item << endl;
		}
		catch(...){
			cout << "\nNeizdevās izveidot err.txt - tas iespējams jau ir atvērts kādā citā procesā!\n" << endl;
		}
	    	out.close();
	    	in.close();
	    	cout << "\nIzdevās nolasīt " << cars.size() << " rindas!\n" << endl;
    }
    
	else{
		cout << "\nFails netika atrasts vai neeksiste!\n" << endl;
		return false;
	} 
}

string lower(string s){
	string temp;
    for(char ch : s)
        temp += tolower(ch);
    return temp;
}

void table_border(){
    cout << "---------------+--------+-------+---------------+---------------" << endl;
}

void print_table(){
    printf("\n%-15s|%-8s|%-7s|%-15s|%-15s\n", "Marka", "Gads", "Karba", "Reg. numurs", "Nobraukums");
    table_border();
}

void print_car(car c){
    table_border();
    c.print_car();
}

void print_all(vector<car> cars){
    print_table();
    for(auto cart : cars)
        print_car(cart);
}

void find_model(vector<car> cars){
    string search_for;
    cout << "Ievadiet marku: ";
    cin >> search_for;

    print_table();
    for (auto cart : cars){
        string LCmodel = cart.model;
 
        if(lower(LCmodel) == lower(search_for))
            print_car(cart);
    }
}

void find_transmission(vector<car> cars){
    string search_for;
    cout << "Ievadiet pārnesumkārbas veidu(a/m): ";
    cin >> search_for;
    
    search_for = lower(search_for);
    regex isAM("^[am]$");
    if(regex_match(search_for, isAM) && search_for.length() == 1){
	
    	print_table();
    	for (auto cart : cars){
        	if(cart.transmission == search_for[0])
            	print_car(cart);
    	}
	}
	else
		cout << "\nNepareiza ievade!\n" << endl;
}

void find_year(vector<car> cars){
    string search_for;
    cout << "Ievadiet gadu: ";
    cin >> search_for;
    
    lower(search_for);
    
    regex isnum("^[1-9][0-9]*");
    if(regex_match(search_for, isnum)){
	    print_table();
	    for (auto cart : cars){
	        
	        if(cart.year >= stoi(search_for))
	            print_car(cart);
	    }
	}
	else
		cout << "\nNepareiza ievade!\n" << endl;
}
int main()
{
   
    vector<car> cars;
    vector<string> errs;
    string choice;
    while(true){
	    if(read_file(cars, errs)){
		    print_all(cars);
			while(true){
		    	
		        cout << "\na.Izdrukāt datus par noteiktās markas mašīnām\n" <<
		                "b.Meklēt mašīnas pēc pārnesumkārbas tipa\n" <<
		                "c.Meklēt mašīnas, kas tika izlaistas pēc norādītā gada\n" <<
		                "(Rakstiet 'all', lai redzētu visus ierakstus!)\n" <<
		                "(Rakstiet 'exit', lai izbeigtu programmu!)\n" << endl;
		   
		        cout << ">";
		        cin >> choice;
		       	choice = lower(choice);
		        if (choice == "a")
		            find_model(cars);
		        else if (choice == "b")
		            find_transmission(cars);
		        else if (choice == "c")
		            find_year(cars);
		        else if (choice == "all")
		            print_all(cars);
		        else if (choice == "exit"){
		            cout << "\nProgramma izbeigta!\n" << endl;	
					return 0;
				}
		        else
		            cout << "Ievades kļūda!" << endl;
			}
	    }
	    else{
	    	while(true){
	    		cout << "\nVai vēlaties mēģināt vļreiz?(y/n): ";
	    		cin >> choice;
	    		choice = lower(choice);
	    		
	    		if (choice == "y")
	    			break;
	    		else if (choice == "n"){
	    			cout << "\nProgramma izbeigta!\n" << endl;	
					return 0;
				}
				else
					cout << "\nNepareiza ievade!\n" << endl;
			}
	    	
		}
	}
    return 0;
}
