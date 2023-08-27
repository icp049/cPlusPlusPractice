#include <iostream>
using namespace std;

// Rooms are from 101-110

bool RoomIsAvailable(int rooms[], int roomNumber) {
    if (roomNumber < 101 || roomNumber > 110) {
        cout << "Invalid room number" << endl;
        return false;
    }

    if (rooms[roomNumber - 101] == 0) {
        rooms[roomNumber - 101] = 1;
        cout << "Room " << roomNumber << " has been reserved" << endl;
    } else {
        cout << "Room " << roomNumber << " is not available" << endl;
    }

    return true;
}

void reserveRoom(int rooms[], int roomNumber) {
    if (roomNumber < 101 || roomNumber > 110) {
        cout << "Invalid room number" << endl;
        return;
    }

    if (rooms[roomNumber - 101] == 0) {
        rooms[roomNumber - 101] = 1;
        cout << "Room " << roomNumber << " has been reserved" << endl;
    } else {
        cout << "Room " << roomNumber << " is not available" << endl;
    }
}

void cancelReservation(int rooms[], int roomNumber) {
    if (roomNumber < 101 || roomNumber > 110) {
        cout << "Invalid room number" << endl;
        return;
    }

    if (rooms[roomNumber - 101] == 1) {
        rooms[roomNumber - 101] = 0;
        cout << "Room " << roomNumber << " is canceled" << endl;
    } else {
        cout << "Room " << roomNumber << " can't be canceled, it is available" << endl;
    }
}

int main() {
    int rooms[10] = {0};  // Initialize rooms to be all available

    cout << "What do you want to do?" << endl;
    cout << "1. Check if room available" << endl;
    cout << "2. Reserve a room" << endl;
    cout << "3. Cancel a reservation" << endl;

    int choice;
    cout << "Type in your choice here: ";
    cin >> choice;

    int roomNumber;

    switch (choice) {
        case 1:
            cout << "Enter the room number: ";
            cin >> roomNumber;
            RoomIsAvailable(rooms, roomNumber);
            break;

        case 2:
            cout << "Enter the room number: ";
            cin >> roomNumber;
            reserveRoom(rooms, roomNumber);
            break;

        case 3:
            cout << "Enter the room number: ";
            cin >> roomNumber;
            cancelReservation(rooms, roomNumber);
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
    }

    return 0;
}
