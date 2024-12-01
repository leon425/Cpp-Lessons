#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <algorithm>
#include <queue>


int main() {
    int length;
    
    std::cin >> length;

    std::vector<int> counter;

    // Every length
    for (int a=0; a<length; a++) {

        int hurdleLength;
        int powerupLength;
        int destination;
        int strength = 0;
        int count = 0;
        int powerupIndex = 0;

        std::cin >> hurdleLength >> powerupLength >> destination;

        std::vector<std::pair<int,int>> hurdle(hurdleLength);
        std::vector<std::pair<int,int>> powerup(powerupLength);
        std::priority_queue<int> currentPowerup;

        for (int i=0; i<hurdleLength; i++) {
            std::cin >> hurdle[i].first >> hurdle[i].second; 
        }

        for (int i=0; i<powerupLength; i++) {
            std::cin >> powerup[i].first >> powerup[i].second; 
        }

        // Every hurdle
        for (int i=0; i<hurdleLength;i++) {
            int strengthRequired = hurdle[i].second - hurdle[i].first + 1;
            
            while (powerupIndex < powerupLength && powerup[powerupIndex].first < hurdle[i].first) { 
                currentPowerup.push(powerup[powerupIndex].second); 
                powerupIndex++;
            }

            // On the assumption that taking the biggest powerup is always better
            while (currentPowerup.size() > 0) {
                if (strength >= strengthRequired) {
                    break;
                }
                strength += currentPowerup.top();
                currentPowerup.pop();
                count++;
            }

            if (currentPowerup.size() == 0 && strength < strengthRequired) {
                count = -1;
                break;
            }
        }

        counter.push_back(count);

    }

    for (int i=0;i<length;i++) {
        std::cout << counter[i] << '\n';
    }
    


    return 0;
}

// Lessons
// 1) Instead of sorting, use priority queue
// 2) Instead of deleting the first element of sorted list, just save the iterator, and keep iterating into the next element
    // because .erase on a vector is O(n)