#ifndef JOB_SCHEDULE
#define JOB_SCHEDULE

#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>

using namespace std;

class JobScheduler {
    private:
        priority_queue<int, vector<int>, greater<int>> freeWorkers; //pq for free workers
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>  busy; //pq for busy workers doing a job {endtime, worker}
        int nextWorkerId;
    public:
        JobScheduler();
        vector<string> assignWorkers(const vector<tuple<int, int, string>>& jobs); //{start, duration, job id}
};


#endif