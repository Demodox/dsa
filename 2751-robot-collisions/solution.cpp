class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
         
        int n = positions.size();

        vector<int>arr(n);

        for(int i = 0; i<n; i++)
        {
            arr[i] =i;
        }

        auto lambda = [&]( int &i, int &j)
        {
            return positions[i] <positions[j];
        };
        sort(arr.begin(), arr.end(), lambda);

        stack<int>st;
        vector<int>result;

        for(int idx : arr)
        {
            if(directions[idx] == 'R')
            {
                st.push(idx);

            }
            else
            {
                while(!st.empty() && healths[idx] >0)
                {
                    int i = st.top();
                    st.pop();
                    if(healths[i] > healths[idx])
                    {
                        healths[i] -=1;
                        st.push(i);
                        healths[idx]=0;
                    }
                    else if(healths[i] < healths[idx])
                    {
                        healths[i] =0;
                        healths[idx]-=1;

                    }
                    else
                    {
                        healths[i] =0;
                        healths[idx] = 0;
                    }


                }
            }
        }
        for( int i =0;i<n;i++)
        {
            if(healths[i] !=0) result.push_back(healths[i]);
        }

        return result;


        
    }
};