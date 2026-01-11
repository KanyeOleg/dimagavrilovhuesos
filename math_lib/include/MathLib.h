#ifndef MATH_LIB_H
#define MATH_LIB_H

#include <vector>

class MathLib {
public:
    static std::vector<double> generateNumbers(int N, double S);
    static double productOfKLargest(const std::vector<double>& numbers, int K);
    static char checkCondition(double product);
};

#endif
