#include <iostream>
#include <string>
#include<iomanip>

using namespace std;

// Constants for ticket prices
const double TICKET_PRICES[5][2] = {
    {20.00, 30.00},   // one adult
    {12.00, 18.00},   // one child
    {16.00, 24.00},   // one senior
    {60.00, 90.00},   // family ticket
    {15.00, 22.50}    // group
};

// Constants for extra attraction prices
const double EXTRA_ATTRACTIONS[3] = {2.50, 2.00, 5.00};

// Function to display ticket options and extra attractions
void display_options() {
    cout << "Ticket Options:" << endl;
    cout << setw(15) << left << "Ticket Type" << setw(15) << "One Day" << setw(15) << "Two Days" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << setw(15) << left << i + 1;
        cout << setw(15) << TICKET_PRICES[i][0] << setw(15) << TICKET_PRICES[i][1] << endl;
    }
    cout << "\nExtra Attractions:" << endl;
    cout << setw(20) << left << "1. Lion Feeding" << EXTRA_ATTRACTIONS[0] << endl;
    cout << setw(20) << left << "2. Penguin Feeding" << EXTRA_ATTRACTIONS[1] << endl;
    cout << setw(20) << left << "3. Evening Barbecue" << EXTRA_ATTRACTIONS[2] << endl;
    cout << "\nDays Available for Booking:" << endl;
    // Assuming next 7 days
    for (int i = 0; i < 7; ++i) {
        time_t t = time(0) + i * 24 * 60 * 60; // Add i days
        cout << setw(2) << right << i + 1 << ". " << asctime(localtime(&t));
    }
}

// Function to process a booking
void process_booking() {
    // Input ticket type
    int ticket_choice;
    cout << "Enter ticket type (1-5): ";
    cin >> ticket_choice;
    if (ticket_choice < 1 || ticket_choice > 5) {
        cout << "Invalid ticket type." << endl;
        return;
    }

    // Input number of days
    int num_days;
    cout << "Enter number of days (1 or 2): ";
    cin >> num_days;
    if (num_days != 1 && num_days != 2) {
        cout << "Number of days must be 1 or 2." << endl;
        return;
    }

    // Input extra attractions
    double total_cost = TICKET_PRICES[ticket_choice - 1][num_days - 1];
    string attractions[3] = {"Lion Feeding", "Penguin Feeding", "Evening Barbecue"};
    string chosen_attractions = "";
    char choice;
    cout << "Do you want to add extra attractions? (Y/N): ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        cout << "Select attractions (1-3, separated by spaces): ";
        int attraction_choice;
        while (cin >> attraction_choice) {
            if (attraction_choice < 1 || attraction_choice > 3) {
                cout << "Invalid attraction choice." << endl;
                continue;
            }
            total_cost += EXTRA_ATTRACTIONS[attraction_choice - 1];
            chosen_attractions += attractions[attraction_choice - 1] + ", ";
        }
    }

    // Display booking details
    cout << "\nBooking Details:" << endl;
    cout << "Ticket Type: " << ticket_choice << endl;
    cout << "Number of Days: " << num_days << endl;
    cout << "Extra Attractions: " << (chosen_attractions.empty() ? "None" : chosen_attractions.substr(0, chosen_attractions.size() - 2)) << endl;
    cout << "Total Cost: $" << fixed << setprecision(2) << total_cost << endl;
}

int main() {
    while (true) {
        cout << "\nWelcome to Wildlife Park Ticketing System" << endl;
        cout << "1. Display Ticket Options and Extra Attractions" << endl;
        cout << "2. Process a Booking" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                display_options();
                break;
            case 2:
                process_booking();
                break;
            case 3:
                cout << "Thank you for using Wildlife Park Ticketing System. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }
    }
    return 0;
}
