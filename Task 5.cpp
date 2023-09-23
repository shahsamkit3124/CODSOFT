/* Develop a program that simulates a movie ticket booking system.
Allow users to view movie listings, select seats, make bookings,
and calculate the total cost. Consider implementing seat
availability and seat selection validation. */

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Constants
const int NUM_ROWS = 5;
const int NUM_COLS = 5;
const double TICKET_PRICE = 10.0;

// Function to display the seating chart
void displaySeatingChart(vector<vector<char>>& seats) {
    cout << "  ";
    for (int i = -1; i < NUM_COLS; i++) {
        cout << setw(3) << i+1;
    }
    cout << endl;

    for (int i = 0; i < NUM_ROWS; i++) {
        cout << char('A' + i) << " ";
        for (int j = 0; j < NUM_COLS; j++) {
            cout << setw(3) << seats[i][j];
        }
        cout << endl;
    }
}

// Function to check seat availability
bool isSeatAvailable(vector<vector<char>>& seats, char row, int col) {
    int rowIndex = row - 'A';
    if (rowIndex < 0 || rowIndex >= NUM_ROWS || col < 1 || col > NUM_COLS) {
        return false;
    }
    return seats[rowIndex][col - 1] == 'O';
}

// Function to book a seat
bool bookSeat(vector<vector<char>>& seats, char row, int col) {
    int rowIndex = row - 'A';
    if (isSeatAvailable(seats, row, col)) {
        seats[rowIndex][col - 1] = 'X';
        return true;
    }
    return false;
}

// Function to calculate the total cost
double calculateTotalCost(int numTickets) {
    return numTickets * TICKET_PRICE;
}

int main() {
    vector<vector<char>> seats(NUM_ROWS, vector<char>(NUM_COLS, 'O')); // 'O' represents an available seat

    cout << "Welcome to the Movie Ticket Booking System!" << endl;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. View Seating Chart\n";
        cout << "2. Book a Seat\n";
        cout << "3. Calculate Total Cost\n";
        cout << "4. Quit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displaySeatingChart(seats);
                break;

            case 2:
                char row;
                int col;
                cout << "Enter the seat (e.g., A1): ";
                cin >> row >> col;
                if (bookSeat(seats, row, col)) {
                    cout << "Seat " << row << col << " booked successfully!" << endl;
                } else {
                    cout << "Seat " << row << col << " is not available or invalid." << endl;
                }
                break;

            case 3:
                int numTickets;
                cout << "Enter the number of tickets: ";
                cin >> numTickets;
                cout << "Total cost: $" << calculateTotalCost(numTickets) << endl;
                break;

            case 4:
                cout << "Thank you for using the Movie Ticket Booking System! Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
