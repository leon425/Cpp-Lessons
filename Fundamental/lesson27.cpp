#include <iostream>
#include <vector>

struct student {
    std::string name;
    double gpa;
    bool enrolled = true; //default value
};

struct Car {
    std::string model;
    int year;
    std::string color;
};

// A function that prints a struct. pass struct as an argument
void printCar(Car car);
void printCar2(Car &car);

// Struct with parameter & default parameter - Example usage: Linkedlist
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} // if 0 argument passed
    ListNode(int x) : val(x), next(nullptr) {} // if 1 argument passed
    ListNode(int x, ListNode *next) : val(x), next(next) {} // if all argument passed
};


int main() {
// struct = A Structure that group related vaariables under on name
            // structs can contain many different datatype. Variables in struct are knwon as members.
            // Members can be access with . "Class Member Access operator"

    student student1;
    student1.name = "Spongebob";
    student1.gpa = 3.78;
    student1.enrolled = true;

    // std::cout << student1.name << '\n';

    Car car1;
    car1.model = "Mustang";
    car1.year = 1980;
    car1.color = "Black";

    printCar(car1);
    printCar2(car1);

    ListNode node1(5);
    ListNode node2(3,&node1);
    ListNode node3(2,&node2);
    ListNode node4(1,&node3);
    // 1 -> 2 -> 3 -> 5
    // node4 -> node3 -> node2 -> node1

    // Vector/List of cars
    std::vector<Car> carForSales;
    carForSales.emplace_back("911",2000,"White");
    carForSales.emplace_back("Phantom",2000,"White");
    carForSales.emplace_back("R8",2000,"White");

    for (const auto& car : carForSales) {
        if (car.model == "R8") {
            std::cout << "The color of the R8 is " << car.color;
            break;
        }
    }

    return 0;
}

// Pass by value and not by reference (create a copy of another struct). So, make sure to 
void printCar(Car car) {
    std::cout << car.model << '\n';
    std::cout << car.year << '\n';
    std::cout << car.color << '\n';
}

// Pass By Reference
void printCar2(Car &car) {
    std::cout << car.model << '\n';
    std::cout << car.year << '\n';
    std::cout << car.color << '\n';
}