#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

class matrix_operations 
{
    public:
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

        static  float euclidean_distance(const std::vector<float>& vec1, const std::vector<float>& vec2) {
            if (vec1.size() != vec2.size()) {
                throw std::invalid_argument("Vectors must be of the same length for Euclidean distance.");
            }
            float sum = 0.0f;
            for (size_t i = 0; i < vec1.size(); ++i) {
                sum += std::pow(vec1[i] - vec2[i], 2);
            }
            return std::sqrt(sum);
        }
};