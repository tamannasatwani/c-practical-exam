#include <iostream>
#include <stdexcept> 
using namespace std;

class MathOperations {
public:
    double divide(double numerator, double denominator) {
        if (denominator == 0) {
            throw runtime_error("Error: Division by zero is not allowed.");
        }
        if (numerator < 0 || denominator < 0) {
            throw invalid_argument("Error: Negative numbers are not allowed.");
        }
        return numerator / denominator;
    }
};

int main() {
    MathOperations mathOp;
    double numerator, denominator;

    for (int i = 0; i < 3; ++i) {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;

        try {
            double result = mathOp.divide(numerator, denominator);
            cout << "Result: " << result << endl;
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
        } catch (...) {
            cout << "An unexpected error occurred." << endl;
        }

        cout << endl; 
    }

    return 0;
}

