#include "job_scheduler.hpp"
#include <algorithm>

JobScheduler::JobScheduler() : nextWorkerId(0) {}

vector<string> JobScheduler::assignWorkers(
    const vector<tuple<int, int, string>>& jobs) {
    vector<string> assigned(jobs.size());
    typedef pair<tuple<int, int, string>, int> OrderedJob;
    vector<OrderedJob> orderedJobs;
    orderedJobs.reserve(jobs.size());

    for (int i = 0; i < static_cast<int>(jobs.size()); i++) {
        orderedJobs.push_back({jobs[i], i});
    }

    stable_sort(orderedJobs.begin(), orderedJobs.end(),
         [](const OrderedJob& left, const OrderedJob& right) {
             return get<0>(left.first) < get<0>(right.first);
         });

    for (const auto& orderedJob : orderedJobs) {
        const auto& job = orderedJob.first;
        int originalIndex = orderedJob.second;
        int currStart = get<0>(job);
        int duration = get<1>(job);
        while(!busy.empty() && busy.top().first <= currStart) {
            pair<int, int> availableJob = busy.top();
            busy.pop();

            freeWorkers.push(availableJob.second);
        }

        int selectedWorker;
        if (!freeWorkers.empty()) {
            int freeWorker = freeWorkers.top();
            freeWorkers.pop();

            selectedWorker = freeWorker;
        } else {
            selectedWorker = nextWorkerId++;
        }

        busy.push(make_pair(currStart + duration, selectedWorker));
        assigned[originalIndex] = "W" + to_string(selectedWorker);
    }

    return assigned;
}