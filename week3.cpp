#include<iostream>
#include<vector>
#include<map>

using namespace std;

const int numcows = 4;
const int numdays = 7;
const int milkthreshold = 12;

struct cow
{
    string identitycode;
    vector<vector<double>> dailyyields;
};

void recordyield(cow& cow);
double calculateweeklyvolume(const cow& cow);
double calculateaverageyield(const cow& cow);
void identifymostproductive(const map<string, cow>& herd);

int main()
{
    map<string, cow> herd;

    for (int i = 0; i < numcows; i++)
    {
        cow c;
        cout << "Enter the 3-digit identity code for cow " << i + 1 << ": ";
        cin >> c.identitycode;
        for (int day = 0; day < numdays; day++)
        {
            cout << "\nDay " << day + 1 << ":";
            recordyield(c);
        }
        herd[c.identitycode] = c;
    }

    double totalvolume = 0;
    for (const auto& pair : herd)
    {
        totalvolume += calculateweeklyvolume(pair.second);
    }
    double averageyield = totalvolume / (numcows * numdays);

    cout << "\nTotal weekly volume of milk for the herd: " << totalvolume << " liters.";
    cout << "\nAverage yield volume per cow in the week: " << averageyield << " liters.";

    identifymostproductive(herd);
}

void recordyield(cow& c)
{
    vector<double> yields;
    for (int i = 0; i < 2; i++)
    {
        double yield;
        cout << "Enter the yield for milking " << i + 1 << ": ";
        cin >> yield;
        yields.push_back(yield);
    }
    c.dailyyields.push_back(yields);
}

double calculateweeklyvolume(const cow& c)
{
    double weeklyvolume = 0;
    for (const auto& day : c.dailyyields)
    {
        for (double yield : day)
        {
            weeklyvolume += yield;
        }
    }
    return weeklyvolume;
}

double calculateaverageyield(const cow& c)
{
    double total = 0;
    for (const auto& day : c.dailyyields)
    {
        for (double yield : day)
        {
            total += yield;
        }
    }
    return total / (numdays * 2); // Two milkings per day
}

void identifymostproductive(const map<string, cow>& herd)
{
    string mostProductiveCow;
    double maxTotalYield = 0;

    for (const auto& pair : herd)
    {
        double totalYield = calculateweeklyvolume(pair.second);

        if (totalYield > maxTotalYield)
        {
            maxTotalYield = totalYield;
            mostProductiveCow = pair.first;
        }
    }

    cout << "\nMost productive cow this week:" << endl;
    cout << "Cow ID: " << mostProductiveCow << endl;
    cout << "Weekly yield: " << maxTotalYield << " liters" << endl;
}
