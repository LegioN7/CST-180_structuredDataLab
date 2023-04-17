// Name: Aaron Pelto
// Week: 12
// Program: Structured Data and Abstract Data Types Lab

#include <iostream>
using namespace std;

struct weatherStats
{

    // Total Rainfall
    double rain;

    // Highest Temperature
    double high;

    // Lowest Temperature
    double low;

    // Average Temperature
    double averageTemp;
};

const int months = 12;

int main()
{
    weatherStats m[12];

    int i;
    double rainTotal, averageRainTotal, averageSum, averageTempTotal;
    averageRainTotal = 0;
    rainTotal = 0;
    averageSum = 0;
    averageTempTotal = 0;

    int lowMonth;
    lowMonth = 0;

    int highMonth;
    highMonth = 0;

    double max, min;

    for (i = 0; i < months; i++)
    {
        cout << "\nEnter the data for month " << (i + 1) << ".\n";

        // Rainfall
        cout << "Enter the Total Rainfall for the month" << endl;
        cin >> m[i].rain;

        // Highest Temp
        do
        {
            cout << "Enter the Highest Temperature for the month" << endl;
            cin >> m[i].high;
        } while (m[i].high < -100 || m[i].high > 140);

        // Lowest Temp
        do
        {
            cout << "Enter the Lowest Temperature for the month" << endl;
            cin >> m[i].low;
        } while (m[i].low < -100 || m[i].low > 140);
    }

    // Calculate Total Rainfall
    for (i = 0; i < months; i++)
    {
        rainTotal = rainTotal + m[i].rain;
    }

    // Calculate Average Monthly Rainfall
    averageRainTotal = rainTotal / months;

    // average temp for each month
    for (i = 0; i < months; i++)
    {
        m[i].averageTemp = m[i].high + m[i].low / 2;
    }

    // Total the data
    for (i = 0; i < months; i++)
    {
        averageSum = averageSum + m[i].averageTemp;
    }

    // Average Total Temperature
    averageTempTotal = averageSum / months;

    // find the highest and lowest temps
    max = m[0].high;
    for (i = 1; i < months; i++)
    {
        if (max < m[i].high)
        {
            max = m[i].high;
            highMonth = i;
        }
    }

    min = m[0].low;
    for (i = 1; i < months; i++)
    {
        if (min > m[i].low)
        {
            min = m[i].low;
            lowMonth = i;
        }
    }

    cout << "\nTotal Rainfall: " << rainTotal << endl;
    cout << "Average Monthly Rain: " << averageRainTotal << endl;
    cout << "Average Monthly Temperature: " << averageTempTotal << endl;
    cout << "Highest Temperature: " << max << endl;
    cout << "Month " << (highMonth + 1) << " had the highest temperature.";
    cout << "Lowest Temperature: " << min << endl;
    cout << "Month " << (lowMonth + 1) << " had the highest temperature.";
}
