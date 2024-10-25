#include <iostream>
#include <vector>

//a complicated data type is being nicknamed into pair list
typedef std::vector<std::pair<std::string,int>> pairlist_t; //common convention for unique identifier is ending with '_t' 

//it's recommended and more popular to use 'using' instead of 'typedef' because it's more suitable for template
using text_t = std::string; 

int main() {

//Typedef 
    // = reserved keyword used to create an additional name (alias) for another data type
    //   New identifier for an existing type helps with readability and reduce typos

    pairlist_t pairlist; 
    text_t name = "Bro";


    return 0;
}