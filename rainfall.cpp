/*
    rainfall.cpp

    Rainfall report. Inputs are rain amounts per hour. Output is the average
    and heaviest hourly rainfall.
*/

#include <iostream>
#include <iomanip>
#include <vector>

int main() {

    // input the hourly rainfall date
    std::vector<double> rainfall;
    double n;
    while (std::cin >> n) {
        rainfall.push_back(n);
    }
    if (!rainfall.size()) {
        std::cerr << "Error: no rainfall data\n";
        return 1;
    }

    // heaviest rainfall
    auto heaviest = rainfall[0];
    for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
        if (rainfall[i] > heaviest)
            heaviest = rainfall[i];
    }

    // average rainfall
    auto total  = rainfall[0];
    for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
        total += rainfall[i];
    }
    auto average = total / rainfall.size();

    // output the rainfall report
    std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
    std::cout << "|:----------------|----------------|" << '\n';
    std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << average << " |" << '\n';
    std::cout << "| Heaviest        |     " << std::left << std::setw(10) << heaviest << " |" << '\n';

    return 0;
}
