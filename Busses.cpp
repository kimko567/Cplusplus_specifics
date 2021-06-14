#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void addNewBus(map<string, vector<string>> &buses, map<string, vector<string>> &stops);
void printAllBuses(const map<string, vector<string>> &buses);
void printStop(map<string, vector<string>> &stops);

int main() {

	map<string, vector<string>> buses;
    map<string, vector<string>> stops;
	while (true) {
		string cmd;
		cout << "command:>";
		cin >> cmd;

		if (cmd == "done")
			break;

		if (cmd == "add") {
			addNewBus(buses, stops);
			continue;
		}
        
        if (cmd == "stop") {
            printStop(stops);
            continue;
        }
        
		if (cmd == "print") {

			printAllBuses (buses);
			continue;
		}
	}

	return 0;
}

void printStop(map<string, vector<string>> &stops) {
    string stop;
    cout << "input stop: ";
    cin >> stop;
    
    if(stops.count(stop)){
        for (auto elem : stops[stop])
            cout << elem << " ";
        cout << endl;
    }
    else    
        cout << "No buses for this stop!" << endl;

}

void addNewBus(map<string, vector<string>> &buses, map<string, vector<string>> &stops) {
	string bus;
	cout << "bus #: ";
	cin >> bus;

	int stop_count;
	cout << "count of stops: ";
	cin >> stop_count;

	vector<string> &listOfStops = buses[bus];
	listOfStops.resize(stop_count);
	
	cout << "stops:" << endl;
	for (string &stop : listOfStops) {
		cin >> stop;
	    vector<string> &listOfBuses = stops[stop];
	    listOfBuses.resize(listOfBuses.size() + 1);
	    listOfBuses[listOfBuses.size() - 1] = bus;
	}

	    
}

void printAllBuses(const map<string, vector<string>> &buses) {
	if (buses.empty()) {
		cout << "No buses" << endl;
	} else {
		for (const auto &bus_item : buses) {
			cout << "Bus " << bus_item.first << ": ";
			for (const string &stop : bus_item.second) {
				cout << stop << " ";
			}
			cout << endl;
		}
	}
}
