#include <iostream>
#include <string>
#include <utility>

using namespace std;

int get_no_days(){
    int days;
    cout << "How many days was the trip: ";
    cin >> days;
    while(days < 1){
        cout << "Days should be more than 1: ";
        cin >> days;
    }
    return days;
}

pair<string, string> times(){
    string departure,arrival;
    cout << "Enter departure time on the first day (hh:mm): ";
    cin >> departure;
    cout << "Enter arrival time on the last day (hh:mm): ";
    cin >> arrival;
    return make_pair(departure, arrival);
}

double round_airfares(){
    double airfares;
    cout << "Enter the amount of round-trip airfare expenses: ";
    cin >> airfares;
    while(airfares < 0){
        cout << "Please enter a non-negative number: ";
        cin >> airfares;
    }
    return airfares;
}

double car_rental(){
    double rent_amount;
    cout << "Enter the amount of car rental expenses: ";
    cin >> rent_amount;
    while(rent_amount < 0){
        cout << "Please, enter a non-negative number: ";
        cin >> rent_amount;
    }
    return rent_amount;
}

double miles_driven_expense(){
    double miles;
    cout << "Enter the number of miles you have driven: ";
    cin >> miles;
    while(miles < 0){
        cout << "Please enter a non-negative number: ";
        cin >> miles;
    }
    return 0.27 * miles;
}

pair<double, double> parking_fees(int no_days){
    const double allowedPerDay = 6.0; // Maximum allowed parking fee per day
    double total_allowable = 0.0;
    double total_expense = 0.0;

    // Input parking fees for each day and calculate the total
    for (int i = 1; i <= no_days; i++) {
        double parkingFee;
        cout << "Enter parking fee for day " << i << ": $";
        cin >> parkingFee;
        total_expense += parkingFee;
        // Check if parking fee exceeds the allowed amount
        if (parkingFee > allowedPerDay) {
            total_allowable += allowedPerDay; // Add allowed amount to total
        }
        else {
            total_allowable += parkingFee; // Add actual fee to total
        }
    }

    return make_pair(total_expense, total_allowable);
}

pair<double, double> taxi_fees(int no_days){
    const double allowedPerDay = 10.0; // Maximum allowed parking fee per day
    double total_allowable = 0.0;
    double total_expense = 0.0;

    // Input parking fees for each day and calculate the total
    for (int i = 1; i <= no_days; i++) {
        double taxiFee;
        cout << "Enter taxi fee for day " << i << ": $";
        cin >> taxiFee;
        total_expense += taxiFee;
        // Check if parking fee exceeds the allowed amount
        if (taxiFee > allowedPerDay) {
            total_allowable += allowedPerDay; // Add allowed amount to total
        }
        else {
            total_allowable += taxiFee; // Add actual fee to total
        }
    }

    return make_pair(total_expense, total_allowable);
}

int main() {
    double days,rent,round_trip_fare,miles_driven;
    double tot_exp_park,tot_allow_park;
    days = get_no_days();
    pair<string, string> times1 = times();
    round_trip_fare = round_airfares();
    rent = car_rental();
    miles_driven = miles_driven_expense();
    pair<double, double> parking_fees1 = parking_fees(days);
    pair<double, double> taxi_fees1 = taxi_fees(days);
    
    cout << "Number of days: " << days << endl;
    cout << "Departure time: " << times1.first << endl;
    cout << "Arrival time: " << times1.second << endl;
    cout << "Round trip airplane expenses: " << round_trip_fare;
    cout << "Car rental expenses: $" << rent << endl;
    cout << "Vehicle expenses: $" << miles_driven << endl;
    
    cout << "Total actual expenses: " << endl;
    cout << round_trip_fare + rent + miles_driven + parking_fees1.first + taxi_fees1.first << endl;
    
    cout << "Total allowable expenses: " << endl;
    cout << parking_fees1.second + taxi_fees1.second << endl;
    return 0;
}
