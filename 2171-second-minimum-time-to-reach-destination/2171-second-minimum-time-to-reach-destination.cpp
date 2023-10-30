class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        // Initialize a vector of priority queues for distances, one for each node in the graph.
        vector<priority_queue<int>> dis(n);
        for (int i = 0; i < n; i++) {
            dis[i].push(1e8); // Initialize all distances with a very large value.
        }

        // Create an adjacency list for the graph.
        vector<int> adj[n];
        for (auto it : edges) {
            adj[it[0] - 1].push_back(it[1] - 1);
            adj[it[1] - 1].push_back(it[0] - 1);
        }
        
        // Create a priority queue to store the node and time pair, sorted by time.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0}); // Start at node 0 with time 0.
        dis[0].pop();    // Remove the initial large distance value.
        dis[0].push(0);  // Set the distance to 0 for the starting node.

        // Dijkstra's algorithm to find the second minimum distance.
        while (!pq.empty()) {
            int dist = pq.top().first;  // Get the current time.
            int node = pq.top().second; // Get the current node.
            pq.pop();

            // Calculate the number of times 'change' needs to be added to 'dist' to make it even.
            int k = dist / change;

            // If k is odd, make the time even by adding 'change' to it.
            if (k % 2 == 1) {
                dist = dist + (change - dist % change);
            }

            // Iterate through adjacent nodes.
            for (auto adjnode : adj[node]) {
                int adjdis = dist + time; // Calculate the new time to reach the adjacent node.

                // If the distance is not set (1e8), set it and push it into the priority queue.
                if (dis[adjnode].top() == 1e8) {
                    dis[adjnode].pop();
                    dis[adjnode].push(adjdis);
                    pq.push({adjdis, adjnode});
                }
                // If the distance queue has less than 2 values and the new distance is not equal to the current value,
                // add the new distance and push it into the priority queue.
                else if (dis[adjnode].size() < 2 && dis[adjnode].top() != adjdis) {
                    dis[adjnode].push(adjdis);
                    pq.push({adjdis, adjnode});
                }
                // If the new distance is smaller than the current smallest distance, update it and push it into the priority queue.
                else {
                    if (dis[adjnode].top() > adjdis) {
                        dis[adjnode].pop();
                        dis[adjnode].push(adjdis);
                        pq.push({adjdis, adjnode});
                    }
                }
            }
        }
        
        // Return the top value (second minimum distance) of the last node in the distances vector.
        return dis[n - 1].top();
    }
};
