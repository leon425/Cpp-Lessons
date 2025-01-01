#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

struct CityRecords {
    long long population;
    double longitude;
    double latitude;
};

int main() {
    std::map<std::string,CityRecords> cities;
    cities["London"] = CityRecords {500000,6.4,8.9};
    cities["Melbourne"] = CityRecords {500000,6.4,8.9};
    cities["New York"] = CityRecords {500000,6.4,8.9};

    std::cout << cities["London"].population << '\n';

    CityRecords& londonData = cities["London"]; //reference of one of the CityRecords struct, without a creating a new copy.
    // However, if London doesn't exist, then the code above will create it.

    CityRecords& berlinData = cities["Berlin"]; // since berlin doesn't exist, this code creates it
    berlinData.population = 252353;
    berlinData.longitude = 6.5;
    berlinData.latitude = 5.6;

    // use .at() operator instead of [] when working with a const hashmap. e.g if const auto& cities. OR we only want to retrieve it
    // and don't want to insert anything. if it doesn't exist, it will throw and error
    CityRecords& melbourneData = cities.at("Melbourne");
    
    if (cities.find("Berlin") != cities.end()) {
        std::cout << "Berlin isn't in the list" << '\n';
    }
    // if the key exists, it returns an iterator pointing to the key-value pair in the map
    // if the key doesn't exist, it returns an iterator equal to cities.end()
    // cities.end() represents an iterator to the end of the map
  
    cities.erase("New York");

    std::unordered_map<std::string,int> vertex = {{"Station A",1},{"Station B",2}};

    // It's notable that the key is hashable. Custom type (struct) is not hashable. So, when you want to use a custom type as a key
    // use a pointer to that custom type. Pointer is hashable since it's basically a 64-bit integer. OR create a hashing function for the custom type

// Iterate through Hashmap
    for (const auto& pair : vertex) { // Provide access to key-value pair as a std::pair
        std::cout << pair.first << " " << pair.second << '\n';
    }

    // don't use const is you want to update the value 
    for (auto& pair : vertex) { 
        pair.second++;
    }

    // Using an iterator
    for (auto it=vertex.begin(); it != vertex.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << '\n';
    }

// Delete a hashmap by key
    vertex.erase("Station A");

// Delete a hashmap by iterator
    auto it = cities.find("New York");
    if (it != cities.end()) { // if there's no key of "New York", the iterator returns cities.end()
        cities.erase(it); // Erase the element
    }

// delete a range of elements using iterator.
    auto start = cities.find("London");
    cities.erase(start,cities.end());

// delete a hashmap given the value
    for (auto it = vertex.begin(); it != vertex.end(); ) {
            if (it->second == 2) {
                it = vertex.erase(it); // Erase element and get new iterator. Update the iterator because the last iterator is no longer valid. 
                                    // Trying to dereference an invalid iterator (it->second) can cause a segmentation fault or undefined behavior.
                                    // .erase(iterator) returns an iterator pointing to the next element
            } else {
                ++it; // Move to the next element // save version of incrementing the iterator. (Without the risk of iterator invalidation because of hashmap deletion)
            }
        }

//myMap.end(), which is a special iterator representing one past the last element of the map. This position is invalid for accessing or erasing elements.

    return 0;
}