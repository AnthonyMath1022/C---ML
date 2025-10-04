
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

class MatrixOperations {
public:
    // Vector addition: returns a new vector with element-wise sums
    static std::vector<float> add(const std::vector<float>& vec1, const std::vector<float>& vec2) {
        if (vec1.size() != vec2.size()) {
            throw std::invalid_argument("Vectors must be of the same length for addition.");
        }
        std::vector<float> result(vec1.size());
        for (size_t i = 0; i < vec1.size(); ++i) {
            result[i] = vec1[i] + vec2[i];
        }
        return result;
    }

    // Sum of all elements in a vector
    static float sum(const std::vector<float>& vec) {
        float result = 0.0f;
        for (float val : vec) {
            result += val;
        }
        return result;
    }

    // Dot product: sum of element-wise products
    static float dot_product(const std::vector<float>& vec1, const std::vector<float>& vec2) {
        if (vec1.size() != vec2.size()) {
            throw std::invalid_argument("Vectors must be of the same length for dot product.");
        }
        float result = 0.0f;
        for (size_t i = 0; i < vec1.size(); ++i) {
            result += vec1[i] * vec2[i];
        }
        return result;
    }

    // Euclidean distance between two vectors
    static float euclidean_distance(const std::vector<float>& vec1, const std::vector<float>& vec2) {
        if (vec1.size() != vec2.size()) {
            throw std::invalid_argument("Vectors must be of the same length for Euclidean distance.");
        }
        float sum = 0.0f;
        for (size_t i = 0; i < vec1.size(); ++i) {
            float diff = vec1[i] - vec2[i];
            sum += diff * diff;  // More efficient than pow(x, 2)
        }
        return std::sqrt(sum);
    }

    // Vector magnitude (length)
    static float magnitude(const std::vector<float>& vec) {
        float sum = 0.0f;
        for (float val : vec) {
            sum += val * val;
        }
        return std::sqrt(sum);
    }
};