#include <iostream>
#include <string>
using namespace std;

const int MIN_ITEMS = 10;
const double fees = 0.10;

struct AuctionItem {
    int itemNumber;
    string description;
    double reservePrice;
    int numberOfBids;
    double highestBid;
};

void auctionSetup(AuctionItem items[], int numItems) {
    for (int i = 0; i < numItems; ++i) {
        cout << "Enter details for Item " << i + 1 << ":" << endl;
        cout << "Item Number: ";
        cin >> items[i].itemNumber;

        cout << "Description: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, items[i].description);

        cout << "Reserve Price: $";
        cin >> items[i].reservePrice;

        items[i].numberOfBids = 0; // Initializing the number of bids to zero
        items[i].highestBid = 0.0; // Initializing the highest bid to zero
    }
}

void placeBid(AuctionItem items[], int numItems, int buyerNumber) {
    int itemNumber;
    double bidAmount;

    cout << "Enter the item number you want to bid for: ";
    cin >> itemNumber;

    // Find the item in the array
    int index = -1;
    for (int i = 0; i < numItems; ++i) {
        if (items[i].itemNumber == itemNumber) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Error: Item not found." << endl;
        return;
    }

    cout << "Item Number: " << items[index].itemNumber << endl;
    cout << "Description: " << items[index].description << endl;
    cout << "Current Highest Bid: $" << items[index].highestBid << endl;

    cout << "Enter your buyer number: ";
    int currentBuyerNumber;
    cin >> currentBuyerNumber;

    if (currentBuyerNumber != buyerNumber) {
        cout << "Error: Invalid buyer number." << endl;
        return;
    }

    cout << "Enter your bid amount: $";
    cin >> bidAmount;

    if (bidAmount <= items[index].highestBid) {
        cout << "Error: Bid must be higher than the current highest bid." << endl;
        return;
    }

    // Update the item details with the new bid
    items[index].numberOfBids++;
    items[index].highestBid = bidAmount;

    cout << "Bid successfully placed!" << endl;
}

void endAuction(AuctionItem items[], int numItems, double& totalFee, int& itemsSold, int& itemsNotMeetingReserve, int& itemsWithNoBids) {
    totalFee = 0.0;
    itemsSold = 0;
    itemsNotMeetingReserve = 0;
    itemsWithNoBids = 0;

    cout << "\nEnd of Auction Results:" << endl;

    for (int i = 0; i < numItems; ++i) {
        if (items[i].highestBid >= items[i].reservePrice) {
            itemsSold++;
            double fee = fees * items[i].highestBid;
            totalFee += fee;

            cout << "Item " << items[i].itemNumber << " - Sold for: $" << items[i].highestBid << " (Fee: $" << fee << ")" << endl;
        } else {
            if (items[i].numberOfBids == 0) {
                itemsWithNoBids++;
                cout << "Item " << items[i].itemNumber << " - No bids received." << endl;
            } else {
                itemsNotMeetingReserve++;
                cout << "Item " << items[i].itemNumber << " - Final Bid: $" << items[i].highestBid << " (Did not meet reserve)" << endl;
            }
        }
    }

    cout << "\nTotal Fee for Sold Items: $" << totalFee << endl;
    cout << "Number of Items Sold: " << itemsSold << endl;
    cout << "Number of Items Not Meeting Reserve Price: " << itemsNotMeetingReserve << endl;
    cout << "Number of Items with No Bids: " << itemsWithNoBids << endl;
}

int main() {
    int numItems, buyerNumber;

    cout << "Enter the number of items in the auction (at least 10): ";
    cin >> numItems;

    if (numItems < MIN_ITEMS) {
        cout << "Error: The auction must have at least 10 items." << endl;
        return 1; // Exit with an error code
    }

    AuctionItem items[numItems];
    auctionSetup(items, numItems);

    cout << "Enter your buyer number: ";
    cin >> buyerNumber;

    char option;
    do {
        cout << "\nOptions:" << endl;
        cout << "1. Place Bid" << endl;
        cout << "2. End Auction" << endl;
        cout << "Enter your choice (1/2): ";
        cin >> option;

        switch (option) {
            case '1':
                placeBid(items, numItems, buyerNumber);
                break;
            case '2':
                double totalFee;
                int itemsSold, itemsNotMeetingReserve, itemsWithNoBids;
                endAuction(items, numItems, totalFee, itemsSold, itemsNotMeetingReserve, itemsWithNoBids);
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }

    } while (option != '2');

    return 0; // Exit successfully
}
