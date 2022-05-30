#include <iostream>
#include <string>

using namespace std;

int main() {
    double pricePrintingOnePage, priceCover;
    int percentDiscount;
    double designer;
    int percentTeam;
 
    cin >> pricePrintingOnePage >> priceCover >> percentDiscount >> designer >> percentTeam;

    double priceBook = (pricePrintingOnePage * 899) + (2 * priceCover);

    double bookAfterDiscount = (priceBook * (1 - (percentDiscount * 1.0 / 100))) + designer;

    double finalPrice = bookAfterDiscount * (1 - (percentTeam * 1.0) / 100);

    cout.setf(ios::fixed);
    cout.precision(2);

    cout << "Avtonom should pay " << finalPrice << " BGN."<< endl;

    return 0;
}
