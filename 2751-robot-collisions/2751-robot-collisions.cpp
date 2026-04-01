class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<int> actual_index(n);
        for(int i=0; i<n; i++){
            actual_index[i] = i;
        }

        auto lambda = [&](int &i, int &j){
            return positions[i] < positions[j];
        };

        sort(actual_index.begin(), actual_index.end(), lambda);

        vector<int> result;
        stack<int> st;

        for(int &currIdx : actual_index){
            if(directions[currIdx] == 'R'){
                st.push(currIdx);
            }else{
                while(!st.empty() && healths[currIdx] > 0){
                    int topIdx = st.top();
                    st.pop();

                    if(healths[topIdx] > healths[currIdx]){
                        healths[topIdx] -= 1;
                        healths[currIdx] = 0;
                        st.push(topIdx);
                    }else if(healths[topIdx] < healths[currIdx]){
                        healths[topIdx] = 0;
                        healths[currIdx] -= 1;
                    }else if(healths[topIdx] == healths[currIdx]){
                        healths[topIdx] = 0;
                        healths[currIdx] = 0;
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            if(healths[i] > 0) result.push_back(healths[i]);
        }

        return result;
    }
};