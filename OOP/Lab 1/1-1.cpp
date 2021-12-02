// Lab 1
// Question 1
// Write a program to find the average expenditure of a company for each month of each year, each year and average over the range of years specified. Use arrays to construct a table, display the table of expenditure and find the sum and average.

#include <iostream>
using namespace std;

int main()
{
    const char* months[] = {"jan","feb","mar","apr","may","june","july","aug","sep","oct","nov","dec"};
    int startYear, n;
    cout << "Enter starting year: ";
    cin >> startYear;
    cout << "Enter number of years: ";
    cin >> n;

    int e[n][12];
    int avgOfEachYear[n] = {0}, avgOfEachMonth[12] = {0}, totalSum = 0;

    for (int i=0; i<n; i++) {
        cout << "Enter expenditures for year " << startYear+i << endl;
        for (int j=0; j<12; j++) {
            cout << months[j] << ": ";
            cin >> e[i][j];
            avgOfEachYear[i] += e[i][j];
            avgOfEachMonth[j] += e[i][j];
        }
        totalSum += avgOfEachYear[i];
    }
    cout << endl;

    // each month expenditure and yearly average
    cout << "Year\tJan | Feb | Mar | Apr | May | June | July | Aug | Sep | Oct | Nov | Dec";
    for (int i=0; i<n; i++) {
        cout << "\n" << startYear+i << "\t";
        for (int j=0; j<12; j++) {
            cout << e[i][j] << " | ";
        }
        cout << "Average = " << float(avgOfEachYear[i])/12;
    }
    cout << "\n\n";

    // monthly average
    cout << "Months->\tJan | Feb | Mar | Apr | May | June | July | Aug | Sep | Oct | Nov | Dec\nAverage->\t";
    for (int i=0; i<12; i++) {
        cout << float(avgOfEachMonth[i])/n << " | ";
    }
    cout << endl;

    //total sum and average
    cout << "\nTotal expenditure = " << totalSum;
    cout << "\nAverage expenditure = " << float(totalSum)/(n*12);
}