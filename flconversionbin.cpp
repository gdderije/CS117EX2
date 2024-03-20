/* CmSc 117 Exercise 2
*  Gisselle Derije & Benjamin Julien Roque
*  15 October 2020
*/

#include <iomanip>
#include <cmath>
#include <utility>
#include <limits>
#include "binary64.hpp"

double chop(double x, int p ) {
    double shift = pow(2.0, p);
    x *= shift;
    x = (x > 0) ? floor(x) : ceil(x);
    return x/shift;
}

double round(double x, int p) {
    double shift = pow(2.0, p);
    x *= shift;
    x = (x > 0) ? floor(x + 0.5) : ceil(x - 0.5);
    return x/shift;
}

void printChopped(double x) {
    std::cout << "p\tChopped Float\t\tRelative Error\t\tRatio: RelErr/PredErr" << std::endl;
    for(int p = 0; p <= 51; p++){
        std::cout << std::fixed << std::setprecision(14);
        //Chopped FLoat
        std::cout << std::dec << p + 1 << "\t" << chop(x, p - 3);
        std::cout << std::scientific << std::setprecision(10);
        //Relative Error
        std::cout << "\t" << std::abs(chop(x, p - 3) - x) / std::abs(x);
        //Ratio: RellError/PredError
        std::cout << "\t" << (std::abs(chop(x, p - 3) - x))/(pow(2, -p)*(std::abs(x))) << std::endl;
    }
}

void printRounded(double x) {
    //rounding
    std::cout << std::endl << "p\tRounded Float\t\tRelative Error\t\tRatio: RelErr/PredErr" << std::endl;
    for(int p = 0; p <= 51; p++){
        std::cout << std::fixed << std::setprecision(14);
        //Chopped Float
        std::cout << std::dec << p + 1 << "	" << round(x, p - 3);
        std::cout << "\t" << std::scientific << std::setprecision(10);
        //Relative Error
        std::cout << std::abs((round(x, p - 3) - x) / x);
        //Ratio: RelError/PredError
        std::cout << "\t" << (std::abs((round(x, p - 3) - x)))/(pow(2, - p - 1)*std::abs(x)) << std::endl;
    }
}

int main(){
    double x = -10.0 * M_PI;
    std::cout << "USING BINARY CONVERSION:" << std::endl;
    std::cout << std::scientific << std::setprecision(15);
    std::cout << Binary64(x) << std::endl;
    printChopped(x);
    printRounded(x);
    return 0;
}
