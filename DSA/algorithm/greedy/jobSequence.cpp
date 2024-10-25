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
    // Sort The Jobs based on the deadline
    std::sort(jobs.begin(),jobs.end(), [](const Jobs& a, const Jobs& b) {
        return a.deadline > b.deadline;
    });

    // Displaying The Sorted Sequence
    // for (int i=0;i<jobs.size();i++) {
    //     std::cout << jobs[i].profit << " " << jobs[i].index << '\n';
    // }

    int profit = 0;
    std::vector<Jobs> jobToDo;
    std::vector<Jobs> jobNotDone;
    std::vector<Jobs> jobThisHour;
    std::vector<int> deadlines;
    int i = 0;
    int j = 0;

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

        for (int k=0;k<jobThisHour.size();k++) {
            std::cout << jobThisHour[k].profit << ",";
        }
        std::cout << '\n';

        // Sort the jobThisHour based on the profit
        std::sort(jobThisHour.begin(),jobThisHour.end(),[](const Jobs& a, const Jobs& b) {
            return a.profit > b.profit;
        });
        
        // Sort the jobNotDone based on the profit (if the element is not empty)
        if (jobNotDone.size() != 0) {
            std::sort(jobNotDone.begin(),jobNotDone.end(),[](const Jobs& a, const Jobs& b) {
                return a.profit > b.profit;
            });
        }
        
        // Compare the highest profit job in jobThisHour with the highest profit job in jobNotDone, If jobNotDone exist
        // Pick the highest profit job.
        if (jobNotDone.size() != 0) {
            if (jobNotDone[0].profit > jobThisHour[0].profit) {
                jobToDo.push_back(jobNotDone[0]);
                profit += jobNotDone[0].profit;
                jobNotDone.erase(jobNotDone.begin());
            } else if (jobNotDone[0].profit < jobThisHour[0].profit) {
                jobToDo.push_back(jobThisHour[0]);
                profit += jobThisHour[0].profit;
                jobThisHour.erase(jobThisHour.begin());
            }
        } else {
            jobToDo.push_back(jobThisHour[0]);
            profit += jobThisHour[0].profit;
            jobThisHour.erase(jobThisHour.begin());
        }
        

        // Fill the jobNotDone with the remaining job avaliable (in jobThisHour)
        for (int k=0;k<jobThisHour.size();k++){ 
            jobNotDone.push_back(jobThisHour[k]);
        }

        // Reset the jobThisHour 
        jobThisHour.clear();
        jobThisHour.shrink_to_fit();

        i++;
    }

    
    for (int i=0;i<jobToDo.size();i++) {
        std::cout << jobToDo[i].profit << " " << jobToDo[i].index << '\n';
    }
    std::cout << '\n';
    std::cout << "Profit: " << profit << '\n';
    std::cout << '\n';
    std::cout << '\n';

}

int main() {

    std::vector<Jobs> jobs1 = {
        Jobs(0,10,1),
        Jobs(1,20,2),
        Jobs(2,1,3),
        Jobs(3,5,3),
        Jobs(4,15,2),
    };

    std::vector<Jobs> jobs2 = {
        Jobs(0,100,2),
        Jobs(1,19,1),
        Jobs(2,27,2),
        Jobs(3,25,1),
        Jobs(4,15,3),
    };

    std::vector<Jobs> jobs3 = {
        Jobs(0,50,2),
        Jobs(1,60,1),
        Jobs(2,30,2),
        Jobs(3,40,1),
        Jobs(4,10,3),
    };

    std::vector<Jobs> jobs4 = {
        Jobs(0,70,3),
        Jobs(1,20,1),
        Jobs(2,40,2),
        Jobs(3,30,2),
        Jobs(4,10,3),
    };

    std::vector<Jobs> jobs5 = {
        Jobs(0,40,2),
        Jobs(1,20,1),
        Jobs(2,50,3),
        Jobs(3,10,1),
        Jobs(4,60,2),
    };

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

    jobsSequencing(jobs1);
    jobsSequencing(jobs2);
    jobsSequencing(jobs3);
    jobsSequencing(jobs4); 
    jobsSequencing(jobs5); 
    jobsSequencing(jobs6);

    return 0;
}