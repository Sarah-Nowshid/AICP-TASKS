#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function to calculate the check digit for the frequent parking number
int calculateCheckDigit(int num) {
    int weight = 1;
    int sum = 0;
    
    while (num > 0) {
        int digit = num % 10;
        sum += digit * weight;
        weight++;
        num /= 10;
    }
    
    int remainder = sum % 11;
    return (remainder == 10) ? 0 : remainder;
}

// Function to calculate the price to park
double calculateParkingPrice(string day, int arrivalHour, int numHours, string frequentParkingNumber) {
    const double discountBefore16 = 0.1;
    const double discountAfter16 = 0.5;
    const double midnightPrice = 2.00;
    const double eveningPrice = 2.00;
    
    double pricePerHour = 0.00;
    
    // Determine the price per hour based on the day and arrival time
    if (day == "Sunday")
        pricePerHour = (arrivalHour >= 8 && arrivalHour < 16) ? 2.00 : midnightPrice;
    else if (day == "Saturday")
        pricePerHour = (arrivalHour >= 8 && arrivalHour < 16) ? 3.00 : midnightPrice;
    else
        pricePerHour = (arrivalHour >= 8 && arrivalHour < 16) ? 10.00 : midnightPrice;
    
    // Calculate discount based on arrival time
    double discount = (arrivalHour >= 16) ? discountAfter16 : discountBefore16;
    
    // Apply discount if frequent parking number is valid
    if (frequentParkingNumber.length() == 5) {
        int enteredNumber = stoi(frequentParkingNumber.substr(0, 4));
        int enteredCheckDigit = frequentParkingNumber.back() - '0';
        if (calculateCheckDigit(enteredNumber) == enteredCheckDigit)
            discount = (arrivalHour >= 16) ? discountAfter16 : discountBefore16;
        else
            cout << "Frequent parking number is invalid. No discount applied.\n";
    }
    
    // Calculate total price
    double totalPrice = numHours * pricePerHour;
    totalPrice -= totalPrice * discount;
    
    return totalPrice;
}

int main() {
    string day;
    int arrivalHour;
    int numHours;
    string frequentParkingNumber;
    double amountPaid = 0.00;
    double dailyTotal = 0.00;
    
    // Task 1 - Calculating the price to park
    cout << "Enter the day (e.g., Sunday): ";
    cin >> day;
    cout << "Enter the arrival hour (0-23): ";
    cin >> arrivalHour;
    cout << "Enter the number of hours to park: ";
    cin >> numHours;
    cout << "Enter the frequent parking number (if available): ";
    cin >> frequentParkingNumber;
    
    double price = calculateParkingPrice(day, arrivalHour, numHours, frequentParkingNumber);
    cout << "Price to park: $" << fixed << setprecision(2) << price << endl;
    
    // Task 2 - Keeping a total of the payments
    amountPaid = price;
    dailyTotal += amountPaid;
    
    // Task 3 - Making payments fairer
    if (arrivalHour < 16 && (arrivalHour + numHours) >= 16) {
        int hoursBefore16 = 16 - arrivalHour;
        double priceBefore16 = calculateParkingPrice(day, arrivalHour, hoursBefore16, frequentParkingNumber);
        double priceAfter16 = calculateParkingPrice(day, 16, numHours - hoursBefore16, frequentParkingNumber);
        price = priceBefore16 + priceAfter16;
        cout << "Price adjusted for fairness: $" << fixed << setprecision(2) << price << endl;
    }
    
    // Task 2 - Display daily total
    cout << "Daily total: $" << fixed << setprecision(2) << dailyTotal << endl;
    
    return 0;
}
