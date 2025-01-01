#include <iostream>

//constuctor = special method that is automatically called when an aboject is instantiated
                // useful for assigning value to attributes as arguments

//overloaded constructor = multiple constructor w/ same name but different parameter
                // allos for varying arguments when instantiating an object

// Abstraction = hiding unnecessary data form outside a class
// getter = function that makes a private attribute READABLE
// setter = function that makes a private attribute WRITABLE

class Human {
    public: //access modifier. The objects, methods is publicly available
        std::string name;
        std::string occupation;
        int age;

        void eat() {
            std::cout << "This guy is eating\n";
        }

};

class Student {
    public:
        std::string name;
        std::string alias;
        int age;
        double gpa;

    // Constructor with member initializer list
    // Student(std::string val, std::string alias = "", int age = 0, double gpa = 0.0)  : name(val), alias(alias), age(age), gpa(gpa) {}

    Student(std::string name, int age, double gpa) { //This is the constructor. When we instantiate the student object, we automatically run this function
        // if the attribute name and parameter name are different, you don't need to add 'this->'
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }

    //overloaded constructor
    Student(std::string name, std::string alias) { //for student2
        this->name = name;
        this->alias = alias;
    }

    Student() {} //for student3
};

// Abstraction 
class Stove  {
    private: //this can't be read and set outside of the class
        int temperature = 0;

    public:
        //getter (readable)
        int getTemperature() { 
            return temperature;
        };

        //setter (editable)
        void setTemperature(int temperature) {
            if (0 <= temperature && temperature <= 100) {
                this->temperature = temperature;
            } else if (temperature < 0) {
                this->temperature = 0;
            } else {
                this->temperature = 100;
            }
        };

        // constructor 
        // Stove(int temperature) {
        //     setTemperature(temperature);
        // }
};

class Animal {
    public:
        bool alive;
        

    void eat() {
        std::cout << "This animal is eating\n";
    }
};

class Dog : public Animal {
    public:

    void bark() {
        std::cout << "Woof \n";
    }
};

int main() {
// OOP

    Human human1;
    human1.name = "Wreck";
    human1.occupation = "scienctist";
    human1.age = 69;

    // using constructor
    Student student1("Spongebob", 25, 3.89);
    Student student2("James Bond", "John Doe");
    Student student3;

    std::cout << student2.name << '\n';
    std::cout << student2.alias << '\n';

    Stove stove1;
    //std::cout << stove1.temperature << '\n'; // error because 'temperature' is unreadable
    std::cout << stove1.getTemperature() << '\n';

    stove1.setTemperature(100000);
    std::cout << stove1.getTemperature() << '\n';


    // Inheritance
    Dog dog;
    dog.eat();
    dog.bark();

    return 0;
}