#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdexcept>

class LogisticModel
{
private:
    std::vector<double> weights;
    double bias;
    double learning_rate;

    double sigmoid(double z) const {
        return 1.0 / (1.0 + std::exp(-z));
    }
};