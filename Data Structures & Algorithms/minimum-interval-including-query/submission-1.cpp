class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int q = queries.size();

        // sort intervals by left value
        sort(intervals.begin(), intervals.end());

        // pair each query with its original index, then sort by query value
        vector<pair<int,int>> sortedQueries(q); // (query value, original index)
        for (int i = 0; i < q; i++) {
            sortedQueries[i] = {queries[i], i};
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        // min-heap of (size, right) — smallest size on top
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;

        vector<int> answers(q, -1);
        int ptr = 0;

        for (auto& [queryVal, originalIndex] : sortedQueries) {
            // activate intervals whose left <= queryVal
            while (ptr < n && intervals[ptr][0] <= queryVal) {
                int left = intervals[ptr][0];
                int right = intervals[ptr][1];
                int size = right - left + 1;
                minHeap.push({size, right});
                ptr++;
            }
            // deactivate expired intervals
            while (!minHeap.empty() && minHeap.top().second < queryVal) {
                minHeap.pop();
            }
            if (!minHeap.empty()) {
                answers[originalIndex] = minHeap.top().first;
            }
        }
        return answers;
    }
};