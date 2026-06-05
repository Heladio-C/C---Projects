#include <iostream>
#include <iomanip>
#include "SelfPayKiosk.h"

using namespace std;

int main() {
    SelfPayKiosk* kiosk = new SelfPayKiosk();

    // Test basic operations
    kiosk->ScanItem(20.49);
    kiosk->CheckOut();
    kiosk->MakePayment(25.20);
    
    cout << fixed << setprecision(2);
    cout << "Number of customers: " << kiosk->GetNumCustomers() << endl;
    cout << "Amount due: " << kiosk->GetAmountDue() << endl;
    cout << "Total Sales: " << kiosk->GetTotalSales() << endl;

    // Test simulateSales()
    kiosk->ResetKiosk();
    kiosk->SimulateSales(100, 5, 2.5);
    
    cout << "Number of customers: " << kiosk->GetNumCustomers() << endl;
    cout << "Amount due: " << kiosk->GetAmountDue() << endl;
    cout << "Total Sales: " << kiosk->GetTotalSales() << endl;

    delete kiosk;
    return 0;
}