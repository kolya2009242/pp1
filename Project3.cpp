#include <cmath>
#include <iomanip>
#include <iostream>
#include <numbers>
#include <sstream>
#include <string>

using namespace std;

// Calculates the expression for variant 170.
double f(const double x) {
    return sin(30.0 / 63.0)
        - (3.0 * numbers::pi / (56.0 * numbers::e))
        * 11.0 / ((x + 9.0) * (x + 10.0))
        - 5.0 * cos(x + 14.0)
        - (3.0 + sqrt(x - 3.0)) / (x + 12.0);
}

// Checks whether x belongs to the domain.
bool checkDomain(const double x) {
    return isfinite(x) && x >= 3.0;
}

int main() {
    cout << "The author of this program is Mykola Lukianiuk.\n";
    cout << "This program calculates a mathematical "
        "expression by given x. Variant 170.\n";

    cout << "Enter x (x >= 3): ";

    string line;
    getline(cin, line);

    istringstream input(line);
    double x = 0.0;

    if (!(input >> x) || !(input >> ws).eof()) {
        cout << "\nwrong input\n";
        return 0;
    }

    cout << "\n***** do calculations";

    const bool valid = checkDomain(x);
    double result = 0.0;

    if (valid) {
        result = f(x);
    }

    cout << " done\n";
    cout << fixed << setprecision(5);
    cout << "for x = " << x << '\n';

    if (valid) {
        cout << setprecision(9);
        cout << "result = " << result << '\n';
    }
    else {
        cout << "result = undefined\n";
    }

    return 0;
}