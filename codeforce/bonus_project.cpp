#include <iostream>
#include <vector>
#include <sstream>
#include <string>

std::vector<int> project(int length, int works, std::vector<int> wage, std::vector<int> wagePerCost) {
    std::vector<int> work = {};
    int remaining = works;
    for (int i=0;i<length;i++) {
        work.push_back(wage[i]/wagePerCost[i]);
    }
    for (int i=length-1;i>=0;i--) {
        if (remaining >= work[i]) {
            remaining -= work[i];
        } else {
            work[i] = remaining;
            remaining = 0;
        }
    } 

    if (remaining > 0) {
        for (int i=0;i<length;i++) {
        work[i] = 0;
        }
    } 
    return work;
}

int main() {
    int engineer;
    int totalWork;
    std::cin >> engineer >> totalWork;

    // Declare the vector to store the data and the string to receive the input
    std::vector<int> engineerWage;
    std::string wageLine;
    std::vector<int> engineerWagePerCost;
    std::string wagePerCostLine;

    // Get the wage
    std::getline(std::cin >> std::ws,wageLine);

    // Get wage per cost
    std::getline(std::cin >> std::ws,wagePerCostLine);

    // Convert to vector of int (Wage)
    std::stringstream ss(wageLine);
    int wageNum;
    while (ss >> wageNum) {
        engineerWage.push_back(wageNum);
    }

    // Convert to vector of int (WagePerCost)
    std::stringstream ss2(wagePerCostLine);
    int wagePerCostNum;
    while (ss2 >> wagePerCostNum) {
        engineerWagePerCost.push_back(wagePerCostNum);
    }
    
    std::vector<int> result = project(engineer,totalWork,engineerWage,engineerWagePerCost);
    for (int i=0;i<result.size();i++) {
        std::cout << result[i] << " ";
    }
    
    return 0;
}
