#include <iostream>

namespace first {
    int x = 1;
}

namespace second {
    int x = 2;
}

namespace third {
    int y = 0;
}

int main() {
// Namespace
    // = Provides a solution for preventing name conflicts in large projects. Each entity needs a unique name. 
    //   A namespace allows for identically named entities as long as the namespace are different

    int x = 3;
    
    std::cout << x << '\n'; //3 
    std::cout << first::x << '\n'; // 1 // the two columns ('::') is the scope resolution operator
    std::cout << second::x << '\n';

    using namespace third; // Specify which namespace we're using. Replace the third::var

    std::cout << y << '\n';


    // For standard
    using namespace std; //But this may result in conflicting name. e.g, there is a variable inside std called data. So, not recommended. Because
    // it's possible that the compiler or the C++ have the same variable name with the one you use.
    cout << y << '\n';
    string car = "Mustang";


    // Alternative
    using std::cout;
    using std::string;

    cout << y << '\n';
    string name ="Bro";

    // Not recommended to use 'using namespace std' and 'using std::cout' and 'using std::string'

    return 0;
}