class Solution {
public:
typedef pair<int, int> P;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available_servers;
        for(int i=0; i<k; i++){
            available_servers.insert(i);
        }

        priority_queue<P, vector<P>, greater<P>> busy_servers;
        vector<int> countRequest(k, 0);

        for(int i=0; i<arrival.size(); i++){
            int time = arrival[i];

            while(!busy_servers.empty() && busy_servers.top().first <= time){
                int server = busy_servers.top().second;
                busy_servers.pop();
                available_servers.insert(server);
            }

            int target = i%k;
            auto it = available_servers.lower_bound(target);

            if(it == available_servers.end()){
                it = available_servers.begin();
            }

            if(available_servers.empty()){
                continue; //no server available, drop the request
            }

            int targetServer = *it;
            available_servers.erase(it);

            busy_servers.push({time + load[i], targetServer});
            
            countRequest[targetServer]++;
        }

        int maxNumberOfRequests = *max_element(countRequest.begin(), countRequest.end());

        vector<int> result;
        for(int i=0; i<k; i++){
            if(countRequest[i] == maxNumberOfRequests){
                result.push_back(i);
            }
        }

        return result;;
    }
};