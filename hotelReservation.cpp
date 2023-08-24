#include <iostream>

using namespace std;

bool isRoomAvailable(int rooms[], int roomNumber) {
    if (roomNumber < 101 || roomNumber > 110) {
        cout << "Room number is invalid" << endl;
        return false;
    }

    if (rooms[roomNumber - 101] == 0) {
        cout << "Room " << roomNumber << " is available" << endl;
    } else {
        cout << "Room " << roomNumber << " is NOT available" << endl;
    }

    return true; // Added a return statement
}

void reserveRoom(int rooms[], int roomNumber) {
    if (roomNumber < 101 || roomNumber > 110) {
        cout << "Invalid room number" << endl;
        return; // Added a return statement
    }

    if (rooms[roomNumber - 101] == 0) {
        rooms[roomNumber - 101] = 1;
        cout << "Room " << roomNumber << " has been reserved" << endl;
    } else {
        cout << "Cannot reserve" << endl;
    }
}

void cancelReservation(int rooms[], int roomNumber) {
    if (roomNumber < 101 || roomNumber > 110) {
        cout << "Invalid room number" << endl;
        return; // Added a return statement
    }

    if (rooms[roomNumber - 101] == 1) {
        rooms[roomNumber - 101] = 0;
        cout << "Room " << roomNumber << " has been made available" << endl;
    } else {
        cout << "Cannot cancel" << endl;
    }
}

int main() {
    int rooms[10] = {0}; // All are available at first

    while (true) {
        cout << "Menu" << endl;
        cout << "1: Check room availability" << endl;
        cout << "2: Reserve a room" << endl;
        cout << "3: Cancel a Reservation" << endl;
        cout << "4: Exit" << endl; // Added an exit option

        int choice;
        cout << "Please pick a choice: ";
        cin >> choice;

        if (choice == 1) {
            int roomNumber;
            cout << "Enter a room number please: ";
            cin >> roomNumber;
            isRoomAvailable(rooms, roomNumber);
        } else if (choice == 2) {
            int roomNumber;
            cout << "Enter a room number please: ";
            cin >> roomNumber;
            reserveRoom(rooms, roomNumber);
        } else if (choice == 3) {
            int roomNumber;
            cout << "Enter a room number please: ";
            cin >> roomNumber;
            cancelReservation(rooms, roomNumber);
        } else if (choice == 4) { // Exit the loop
            break;
        } else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
