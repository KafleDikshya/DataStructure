#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stack>
#include <stdexcept>
#include <vector>
#include <algorithm>

#include "Car.h"

using namespace std;

const unsigned int PARKING_SPOTS_PER_AISLE = 3;
const unsigned int NUMBER_OF_AISLES = 5;

void handle_arrival(vector<Car>&, vector<stack<string> >&, const string&);
void handle_departure(vector<Car>&, vector<stack<string> >&, const string&);
Car& find_car(vector<Car>&, string);

int main(/*int argc, char* argv[]*/) {

	try
{
		/*
		if (argc != 2) {
			cerr << "Usage:\n" << argv[0] << " data-file";
			return EXIT_FAILURE;
		}*/

		ifstream inf("data.txt");
		if (!inf) {
			cerr << "Could not open ";
			return EXIT_FAILURE;
		}

		vector<Car> cars;
		vector< stack<string> > parking_lot(NUMBER_OF_AISLES);

		while (!inf.eof()) {

			string action, plate;
			inf >> plate >> action;

			if (action == "arrives") {
				handle_arrival(cars, parking_lot, plate);
			}
			else if (action == "departs") {
				handle_departure(cars, parking_lot, plate);
			}
			else {
				cerr << "Unknown action: " << action << endl;
			}

		}
		inf.close();

		/* Begin Student Code */
		cout << endl << "\nThe following cars visited the lot today:" << endl << endl;
		sort(cars.begin(), cars.end());// we sort vector in alphabetical order
		vector<Car>::iterator it; //we use iterator (it) to go through the vector
		for (it = cars.begin(); it != cars.end(); it++)
		{
			cout << it->getPlate() << endl;
		}
		/* End Student Code */

		getchar();
		getchar();
		return EXIT_SUCCESS;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
	}
	catch (...) {
		cerr << "Unknown exception caught!" << endl;

	return EXIT_FAILURE;
	}
}

void handle_arrival(vector<Car>& cars, vector< stack<string> >& parking_lot, const string& plate)
{
	/* Begin Student Code */
	vector<stack<string> >::iterator it;
	int asile = 0;
	bool full = true;

	for (it = parking_lot.begin(); it != parking_lot.end(); it++, asile++)
	{
		if (it->size() < PARKING_SPOTS_PER_AISLE)
		{
			full = false;
			break;
		}
	}
	if (!full)
	{
		Car arrival(plate, asile);
		it->push(plate);
		cars.push_back(arrival);
	}
	else
	{
		cout << "Sorry " << plate << ", the lot is full\n";
	}
	/* End Student Code */
}

void handle_departure(vector<Car>& cars, vector< stack<string> >& parking_lot, const string& plate)
{
	/* Begin Student Code */
	Car departing = find_car(cars, plate);
	stack<string> temp;
	stack<string> & asile = parking_lot[departing.getAisle()];

	while (asile.top() != plate)
	{
		Car& moving = find_car(cars, asile.top());
		moving.setTimesMoved(moving.getTimesMoved() + 1);
		temp.push(asile.top());
		asile.pop();
	}

	cout << departing.getPlate() << " was moved "<< departing.getTimesMoved() << " times while it was here\n";
	asile.pop();

	while (!temp.empty())
	{
		asile.push(temp.top());
		temp.pop();
	}

	/* End Student Code */
}

Car& find_car(vector<Car>& cars, string plate)
{

	/* Begin Student Code */
	vector<Car>::iterator car;
	Car key(plate);
	car = find(cars.begin(), cars.end(), key);
	return *car;
	/* End Student Code */
}
