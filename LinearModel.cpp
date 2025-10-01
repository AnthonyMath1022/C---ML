#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class Linearmodel
{
private:
    std::vector<double> weights;
    double bias;
    double learning_rate;
public:
    Linearmodel(int num_features, double lr) : weights(num_features, 0.0), bias(0.0), learning_rate(lr) {}

    double LinearLoss(const std::vector<double>& X_feature, double y_true)
    {   
        double y_pred = predict(X_feature);
        return 0.5 * std::pow(y_true - y_pred, 2);
    }

    double predict(const std::vector<double>& features) const {
        double linear_combination = bias;
        for (size_t i = 0; i < weights.size(); ++i) {
            linear_combination += weights[i] * features[i];
        }
        return linear_combination;
    }

    void train(const std::vector<std::vector<double>>& X, const std::vector<double>& y, int epochs) {
        for (int epoch = 0; epoch < epochs; ++epoch) {
            for (size_t i = 0; i < X.size(); ++i) {
                double prediction = predict(X[i]);
                double error = y[i] - prediction;

                // Update weights and bias
                for (size_t j = 0; j < weights.size(); ++j) {
                    weights[j] += learning_rate * error * X[i][j];
                }
                bias += learning_rate * error;
            }
        }
    }
};