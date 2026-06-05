#include "SelfPayKiosk.h"

// Constructor
SelfPayKiosk::SelfPayKiosk() {
    customersServed = 0;
    totalSales = 0.0;
    amountDue = 0.0;
    checkedOut = false;
}

// Return total daily sales
double SelfPayKiosk::GetTotalSales() {
    return totalSales;
}

// Return current amount due
double SelfPayKiosk::GetAmountDue() {
    return amountDue;
}

// Return number of customers served
int SelfPayKiosk::GetNumCustomers() {
    return customersServed;
}

// Scan one item
void SelfPayKiosk::ScanItem(double price) {
    if (price >= 0.0) {
        amountDue += price;
    }
}

// Apply sales tax to current purchases
void SelfPayKiosk::CheckOut() {
    amountDue += (amountDue * SALES_TAX);
    checkedOut = true;
}

// Cancel current purchases
void SelfPayKiosk::CancelTransaction() {
    if (!checkedOut) {
        amountDue = 0.0;
    }
}

// Reset register for the day
void SelfPayKiosk::ResetKiosk() {
    customersServed = 0;
    totalSales = 0.0;
    amountDue = 0.0;
    checkedOut = false;
}

// Apply payment to amount due
void SelfPayKiosk::MakePayment(double payment) {
    // Only allow payment if checked out and payment is not negative
    if (checkedOut && payment >= 0.0) {
        if (payment >= amountDue) {
            totalSales += amountDue;
            customersServed++;
            amountDue = 0.0;
            checkedOut = false; // Reset only after full payment
        } else {
            totalSales += payment;
            amountDue -= payment;
        }
    }
}

// Simulate multiple transactions
void SelfPayKiosk::SimulateSales(int numSales, double initialPrice, double incrPrice) {
    for (int i = 0; i < numSales; ++i) {
        ScanItem(initialPrice);
        CheckOut();
        MakePayment(amountDue + 1.0);
        initialPrice += incrPrice;
    }
}