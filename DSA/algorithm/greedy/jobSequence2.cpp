#include <iostream>
#include <vector>
#include <algorithm>

class Jobs {
    public:
    int index;
    int profit;
    int deadline;

    // Default Constructor
    // Required for dynamic memory allocation. Each element must have default value before any values are assigned.
    Jobs() {
        index = 0;
        profit = 0;
        deadline = 0;
    }

    // Parameterized Constructor
    Jobs(int index, int profit, int deadline) {
        this->index = index;
        this->profit = profit;
        this->deadline = deadline;
    }

    void display () {
        std::cout << "Index: " << index << "  Profit: " << profit << "  Deadline: " << deadline;
    }
};

void jobsSequencing(std::vector<Jobs> jobs) {

    int profit = 0;
    std::vector<Jobs> jobToDo;
    std::vector<Jobs> jobNotDone;
    std::vector<Jobs> jobThisHour;
    std::vector<int> deadlines;
    int i = 0;
    int j = 0;

    // Sort The Jobs based on the deadline
    std::sort(jobs.begin(),jobs.end(), [](const Jobs& a, const Jobs& b) {
        return a.deadline > b.deadline;
    });

    // List all the distinct deadlines
    for (int k=0;k<jobs.size();k++){
        if (deadlines.size() == 0) {
            deadlines.push_back(jobs[k].deadline);
        } else if (jobs[k-1].deadline != jobs[k].deadline) {
            deadlines.push_back(jobs[k].deadline);
        }
    }

    // Start the algorithm (Explain in another file)
    while (i < deadlines.size()) { // while there are still jobs to do // CHANGE THIS TO BASED ON DEADLINE

        // Loop for filling jobThisHour
        j = 0;
        while (j < jobs.size()) {
            if (deadlines[i] == jobs[j].deadline) {
                jobThisHour.push_back(jobs[j]);
                j++;
            } else if (jobs[j].deadline > deadlines[i]) {
                j++;
            }
             else {
                break;
            }
        }

        // for (int k=0;k<jobs.size();k++) {
        //     std::cout << jobs[k].profit << "," << jobs[k].deadline;
        //     std::cout << '\n';
        // }
        // std::cout << '\n';
        // std::cout << '\n';

        for (int k=0;k<jobThisHour.size();k++) {
            std::cout << jobThisHour[k].profit << ",";
        }
        std::cout << '\n';

        jobThisHour.clear();
        jobThisHour.shrink_to_fit(); 
        i++;
    }

}

int main() {


    std::vector<Jobs> jobs6 = {
        Jobs(0,100,5),
        Jobs(1,200,2),
        Jobs(2,150,8),
        Jobs(3,70,6),
        Jobs(4,90,3),
        Jobs(4,50,4),
        Jobs(4,120,10),
        Jobs(4,30,1),
        Jobs(4,110,7),
        Jobs(4,60,9),
        Jobs(4,210,5),
        Jobs(4,85,6),
        Jobs(4,130,2),
        Jobs(4,95,3),
        Jobs(4,140,4),
        Jobs(4,65,5),
        Jobs(4,180,7),
        Jobs(4,105,9),
        Jobs(4,55,2),
        Jobs(4,75,1),
    };

    jobsSequencing(jobs6);

    return 0;
}