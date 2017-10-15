/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: October 14, 2017
 * File: main.cpp
 * Purpose: Service Desk Simulation.
 *          Module 02 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: main program
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <array>
#include <vector>

#include "Priority.h"
#include "Service.h"
#include "Customer.h"

using namespace std;

// program name
const string APP_NAME = "Service Desk Simulation";

// main menu options
const array<string, 3> MENU_OPTIONS = {
    "Simulate 1 Service Station",
    "Simulate 2 Services Station",
    "End Simulation"
};

// number of customers
const int CUSTOMERS = 100;

const int SERVICE_MIN = 5;
const int SERVICE_MAX = 8;

/**
 * Print main menu options
 */
void printMenuOptions() {
    cout << endl << "---------------------------" << endl;
    cout << APP_NAME << endl;
    cout << "---------------------------" << endl;

    for (int i=0; i<MENU_OPTIONS.size(); i++) {
        cout << i+1 << ". " << MENU_OPTIONS[i] << endl;
    }

    cout << endl << "Select an option: ";
}

/**
 * Returns random service duration between 5 and 8
 * @return 
 */
double getRandomServiceDuration() {
    return 5 + (static_cast<double>(rand() % (8 - 5 + 1)));
}

/**
 * Returns random service priority in {high, medium, low}
 * @return 
 */
Priority getRandomServicePriority() {
    Priority p;

    int r = 1 + (static_cast<int>(rand() % (3 - 1 + 1)));
    
    switch (r) {
        case 1:
            p = Priority::high;
            break;
        case 2:
            p = Priority::medium;
            break;
        case 3:
        default:
            p = Priority::low;
            break;
    }

    return p;    
}

/**
 * Simulate station services
 * @param numStations
 * @param services
 */
void simulate(int numStations, vector<Service*> services) {
    Service* station1;
    Service* station2;
    int total = 0;
    int waiting1 = 0;
    int waiting2 = 0;
    int totCustHigh = 0;
    int totCustMedium = 0;
    int totCustLow = 0;
    double avgTimeHigh = 0;
    double avgTimeMedium = 0;
    double avgTimeLow = 0;
    double totTimeHigh = 0;
    double totTimeMedium = 0;
    double totTimeLow = 0;
    
    for (std::vector<Service*>::iterator it = services.begin(); it != services.end(); ++it) {
        // get service for 1st station
        station1 = *(it);
        
        total++;

        cout << "Customer #" << total << " Waiting Time @ Station #1:" << waiting1 << " minutes" << endl;

        waiting1 += station1->getDuration();
        
        switch (station1->getPriority()) {
            case Priority::high:
                totCustHigh++;
                totTimeHigh += station1->getDuration();
                avgTimeHigh = totTimeHigh / totCustHigh;
                break;
            case Priority::medium:
                totCustMedium++;
                totTimeMedium += station1->getDuration();
                avgTimeMedium = totTimeMedium / totCustMedium;
                break;
            case Priority::low:
                totCustLow++;
                totTimeLow += station1->getDuration();
                avgTimeLow = totTimeLow / totCustLow;
                break;
        } // switch

        if (numStations == 2) {
            // get service for 2nd station
            ++it;
            station2 = *(it);
            total++;

            cout << "Customer #" << total << " Waiting Time @ Station #2:" << waiting2 << " minutes" << endl;

            waiting2 += station2->getDuration();
            
            switch (station2->getPriority()) {
                case Priority::high:
                    totCustHigh++;
                    totTimeHigh += station2->getDuration();
                    avgTimeHigh = totTimeHigh / totCustHigh;
                    break;
                case Priority::medium:
                    totCustMedium++;
                    totTimeMedium += station2->getDuration();
                    avgTimeMedium = totTimeMedium / totCustMedium;
                    break;
                case Priority::low:
                    totCustLow++;
                    totTimeLow += station2->getDuration();
                    avgTimeLow = totTimeLow / totCustLow;
                    break;
            } // switch

        } // if

    } // for

    // print summary
    cout << endl;
    cout << "Customers served:" << total << " of 100" << endl;
    cout << "[Customers by Priority] High:" << totCustHigh;
    cout << " Medium:" << totCustMedium;
    cout << " Low:" << totCustLow << endl;

    cout << "[Average Waiting Time] High:" << avgTimeHigh << " minutes";
    cout << " Medium:" << avgTimeMedium << " minutes";
    cout << " Low:" << avgTimeLow << " minutes" << endl;

}

/**
 * main program function
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv) {
    // declare some variables
    vector<Service*> services;
    bool exitApp = false;
    int choice = 0;

    // generate array with 100 customers with random service requests
    for (int i=0; i<CUSTOMERS; i++) {
        Service * randService = new Service(getRandomServicePriority(), getRandomServiceDuration());
        randService->setCustomer(new Customer());
        services.push_back(randService);
    }

    // main loop
    while (!exitApp) {
        // print menu options
        printMenuOptions();
        
        // get user selection
        cin >> choice;

        switch (choice) {
            case 1:
                // simulate 1 service station
                simulate(1, services);
                break;
            case 2:
                // simulate 2 service station
                simulate(2, services);
                break;
            case 3:
                // end program
                exitApp = true;
                break;
            default:
                cout << endl << "Incorrect choice. Please try again." << endl;
        } // switch

    } // while
    
    return 0;
}
