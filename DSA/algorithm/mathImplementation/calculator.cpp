#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>

// Rule: Bisection Method only uses 2 decimal point of every a, b, and c.
//       it stops when the rounded value of 2 decimal point of c is equal to a or c.

// Parenthesis Method:
/*
1) If the opening parenthesis exist
2) Store the opening and closing parenthesis index
3) run calculate() just the equation in index between opening and closing parenthesis (Recursively)
4) If the calculation is complete, insert the answer to the original equation
*/

// Sub Functions
// Put the x value to the function
std::string convertVar(std::string equation, double num) {
    std::string strValue = std::to_string(num);
    for (int i=0; i<equation.size();i++){
        if (equation[i] == 'x') {
            equation.erase(i,1);
            equation.insert(i,strValue); 
        } 
        if (equation[i] == ' ') {
            equation.erase(i,1);
        }
    }
    return equation;
}

// Convert operation in string into computer operation
std::string mathOperator(char operation, std::string equation) {
    std::string operated;
    std::string operating;
    std::string result;
    double operatedNum;
    double operatingNum;
    double operationResult;
    int index = equation.find(operation); // This is a mistake
    int startIndex = index - 1;
    int endIndex = index + 1;

    // Find the operated
    while (startIndex >= 0 && (std::isdigit(equation[startIndex]) || equation[startIndex] == '.' || equation[startIndex] == 'g' || equation[startIndex] == '-')) {

        if (equation[startIndex] == 'g' || (equation[startIndex] == '-' && (startIndex == 0 || std::isdigit(equation[startIndex-1] == false))) ) {
            operated.push_back('-');
            startIndex--;
            break;
        }
        if (std::isdigit(equation[startIndex]) || equation[startIndex] == '.' || equation[startIndex] == 'g') {
            operated.push_back(equation[startIndex]);   
            startIndex--;
        }
    
    }
    startIndex++; // restore to the last starting index
    std::reverse(operated.begin(),operated.end());

    // Find the operating
    while (endIndex < equation.size() && (std::isdigit(equation[endIndex]) || equation[endIndex] == '.' || equation[endIndex] == '-')) {
        operating.push_back(equation[endIndex]);
        endIndex++;
    }
    endIndex--; // restore to the last ending index

    std::cout << '\n';
    std::cout << "Equation : " << equation << '\n';
    std::cout << "Operated is " << operated << '\n';
    std::cout << "Operation is " << operation << '\n';
    std::cout << "Operating is "<< operating << '\n';
    
    operatedNum = std::stod(operated);
    operatingNum = std::stod(operating);
    if (operation == '^') {
        operationResult = pow(operatedNum,operatingNum);
    } else if (operation == '*') {
        operationResult = operatedNum*operatingNum;
    } else if (operation == '/') {
         operationResult = operatedNum/operatingNum;
    } else if (operation == '+') {
         operationResult = operatedNum+operatingNum;
    } else if (operation == '-') {
         operationResult = operatedNum-operatingNum;
    }
    
    // Convert double into string
    std:: ostringstream oss;
    oss.precision(3); // set precision to 3 decimal places
    oss << std::fixed << operationResult;
    result = oss.str();

    std::cout << "Operation Result : " << result << '\n';

    if (operationResult < 0) {
        result.erase(0,1);
        result.insert(0,"g");
    }

    // Update The Equation
    equation.erase(startIndex,endIndex-startIndex+1);
    equation.insert(startIndex,result);
    return equation;
}

// Calculate the whole
std::string calculate(std::string equation, int start = -1, int end = -1) {
    if (start == -1) {
        start = 0;
    }
    if (end == -1) {
        end = equation.size()-1;
    }

    // Base Case
    if (std::count(equation.begin(),equation.end(),'(') == 0 && std::count(equation.begin(),equation.end(),'^') == 0 && std::count(equation.begin(),equation.end(),'*') == 0 && 
    std::count(equation.begin(),equation.end(),'/') == 0 && std::count(equation.begin(),equation.end(),'+') == 0 && 
    // if there's no more substraction sign. If there's the sign, make sure it's for declaring negative value
    (std::count(equation.begin(),equation.end(),'-') == 0 || (std::count(equation.begin(),equation.end(),'-') > 0 && equation.find('-') == 0))) 
    {   
        // Convert back 'g' into '-'
        if (std::count(equation.begin(),equation.end(),'g' ) > 0) {
            equation.insert(equation.find('g'),"-");
            equation.erase(equation.find('g'),1);
        }
        return equation;
    }

    // Parenthesis
    else if (std::count( equation.begin(),equation.end(),'(' ) > 0) {
        int startIndex = equation.find('(');
        int endIndex = equation.find(')');

        std::string subAnswer = calculate(equation.substr((startIndex+1), (endIndex-1)-(startIndex+1)+1));
        equation.erase(startIndex,endIndex-startIndex+1+1); // +1 again because we want to erase the last parenthesis.
        equation.insert(startIndex,subAnswer);
        return calculate(equation);
    }

    // Power
    else if (std::count(equation.begin(),equation.end(),'^') > 0) {
        return calculate(mathOperator('^',equation)); // This means, calculate the equation after '^' operation if '^' operation exists.
    } 

    // Multiplication & Division
    else if (std::count(equation.begin(),equation.end(),'*') > 0 && std::count(equation.begin(),equation.end(),'/') > 0) {
        if (equation.find('*') < equation.find('/')) {
            return calculate(mathOperator('*',equation));
        } else {
            return calculate(mathOperator('/',equation));
        }
    }
    else if (std::count(equation.begin(),equation.end(),'*') > 0){
        return calculate(mathOperator('*',equation));
    }
    else if (std::count(equation.begin(),equation.end(),'/') > 0){
        return calculate(mathOperator('/',equation));
    }

    // Addition & Substraction
    else if (std::count(equation.begin(),equation.end(),'+') > 0 && std::count(equation.begin(),equation.end(),'-') > 0) {
        if (equation.find('+') < equation.find('-') || (equation.find('-') == 0 || std::isdigit(equation[equation.find('-')-1]) == false) ) {
            return calculate(mathOperator('+',equation));
        } else {
            return calculate(mathOperator('-',equation));
        }
    }
    else if (std::count(equation.begin(),equation.end(),'+') > 0){
        return calculate(mathOperator('+',equation));
    }
    else if (std::count(equation.begin(),equation.end(),'-') > 0){

        return calculate(mathOperator('-',equation));
    }
    
}



int main() {
    std::string equation = "x^3 - 3*x^2 + 2";
    std::string equation2 = "x-5+62.5*20+x^2/75*65"; //"x-5+x^3*4"
    std::string equation3 = "-2*(5*(-3+2))";
    std::string equation4 = "-5-8";
    double num = 2.5;
    double num2 = 5;
    //std::cout << convertVar(equation2, num) << '\n';
    //calculate(convertVar(equation2,num));
    //std::cout << "Result is " << calculate(convertVar(equation2,num));
    std::cout << calculate(equation4);
    //bisection(equation, num);
    return 0;
}
