#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>

#include "job_scheduler.hpp"
using namespace std;

int main() {
    
    //read file and generate vector of jobs
    ifstream file("jobs_input.txt");
    if (!file) {
        cerr << "Could not open jobs_input.txt\n";
        return 1;
    }

    //first, get number of jubs
    int nJobs;
    if (!(file >> nJobs) || nJobs < 0) {
        cerr << "Invalid number of jobs\n";
        return 1;
    }
    file.ignore(numeric_limits<streamsize>::max(), '\n');
    
    string line, row;
    vector<tuple<int, int, string>> jobs;
    for (int i = 0; i < nJobs && getline(file, line); i++) { //J0,1030 10
        stringstream row(line);
        
        string jobID;
        int startTime, duration; // in minutes
        if (!getline(row, jobID, ',') || !(row >> startTime >> duration)) {
            cerr << "Invalid job record: " << line << '\n';
            return 1;
        }
        
        // Store start time, end time, and job ID.
        startTime = ((startTime / 100) * 60) + startTime % 100;
        jobs.push_back({startTime, duration, jobID});
    }
    
    if (jobs.size() != static_cast<size_t>(nJobs)) {
        cerr << "Expected " << nJobs << " jobs, but found " << jobs.size() << '\n';
        return 1;
    }

    JobScheduler js;
    vector<string> assigned = js.assignWorkers(jobs);
    for (size_t i = 0; i < jobs.size(); i++) {
        cout << get<2>(jobs[i]) << " " << assigned[i] << endl;
    }

    return 0;
}