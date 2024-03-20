/* CmSc 117 Exercise 2
*  Gisselle Derije & Benjamin Julien Roque
*  15 October 2020
*/

#include <iostream>
#include <cmath>
#include <iomanip>

double chop(double x, int p) {
    double shift = pow(10.0, p);
    x *= shift;
    x = (x > 0) ? floor(x) : ceil(x);
    return x/shift;
}

double round(double x, int p) {
    double shift = pow(10.0, p);
    x *= shift;
    x = (x > 0) ? floor(x + 0.5) : ceil(x - 0.5);
    return x/shift;
}

void printChopped(double x) {
    std::cout << "p\tChopped Float\t\tRelative Error " <<
        "\t\tRatio: RellErr / PredErr" << std::endl;
    for (int p = 0; p < 15; p++) {
        std::cout << std::fixed << std::setprecision(14);
        //Chopped Float
        std::cout << p + 1 << "\t" << chop(x, p);
        std::cout << std::scientific << std::setprecision(10);
        //Relative Error
        std::cout << "\t" << std::abs(chop(x, p)-x)/std::abs(x);
        //Ratio: RelError/PredError
        std::cout << "\t" << (std::abs(chop(x, p)-x))/(pow(10, -p) * std::abs(x)) << std::endl;
    }
    return;
}

void printRounded (double x) {
    std::cout << std::fixed << std::setprecision(15);
    std::cout << "p\tRounded Float\t\tRelative Error " <<
        "\t\tRatio: RellErr / PredErr" << std::endl;
    for (int p = 0; p < 15; p++) {
        std::cout << std::fixed << std::setprecision(14);
        //Rounded Float
        std::cout << p + 1 << "\t" << round(x, p);
        std::cout << std::scientific << std::setprecision(10);
        //Relative Error
        std::cout << "\t" << std::abs(round(x, p)-x)/std::abs(x);
        //Ratio: RelErr/PredErr
        std::cout << "\t" << (2*(std::abs(round(x, p)-x)))/(pow(10, -p)*std::abs(x)) << std::endl;
    }
    return;
}

int main () {
    double x = -10.0*M_PI;
    std::cout << std::fixed << std::setprecision(15);
    std::cout << "Number:              " << x << std::endl;
    std::cout << std::scientific << std::setprecision(16);
    std::cout << "Scientific Notation: " << x << std::endl;
    std::cout << "USING DECIMAL CONVERSION:\n" << std::endl;
    printChopped(x);
    std::cout << "\n" << std::endl;
    printRounded(x);
    return 0;
}
