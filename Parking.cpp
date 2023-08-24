#include <iostream>
#include <vector>


using namespace std;

class ParkingLot {
private:
	int capacity;
	vector<bool> parkingSpaces;

public:
	ParkingLot(int size): capacity(size), parkingSpaces(size, false) {}


	bool parkCar() {
		for(int i = 0; i < capacity; i++){
			if(!parkingSpaces[i]){
				parkingSpaces[i] = true;
				cout << "car parked at" << i + 1 << endl;
				return true;

			}
		}

		cout << "parking is full" << endl;
		return false;

	}


	bool leaveParking(int space){
		if( space < 1 || space > capacity){
			cout << "invalid space number";
		}

		if(parkingSpaces[space -1]){
			parkingSpaces[space -1] = false;
			cout << "car left space is " << space << endl;
			return true;
		} else {
			cout << "No car found in " << space << endl;
			return false;
		}
	}

};




int main() {
	int parkingCapacity;
	cout << "Enter the capacity";
	cin >> parkingCapacity;

	ParkingLot parkinglot(parkingCapacity);

	while(true){
		cout << "Menu" << endl;
		cout << "1 park a car" << endl;
		cout << "2 leave a car" << endl;
		cout << "exit" << endl;


	 int choice;
	 cout << "put a choice";
	 cin >> choice;

	 switch(choice){
	 case 1:
		 parkinglot.parkCar();
		 break;
	 case 2:
		 int space;
		 cout << "enter number of parking space to leave";
		 cin >> space;
		 parkinglot.leaveParking(space);
		 break;

	 case 3:
		 return 0;

	 default:
		 cout << "invalid choice bro" << endl;
		 break;

	 }
	}
	return 0;
}

