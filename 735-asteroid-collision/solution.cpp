class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n = asteroids.size();
        stack<int>st;
        for(int i =0;i<n;i++ )
        {
            if(asteroids[i] > 0)
            {
                st.push(i);
            }
            else
            {
                while(!st.empty() && asteroids[i] !=0)
                {
                     int index = st.top();
                     st.pop();
                    if(asteroids[index]  > abs(asteroids[i]))
                    {
                        asteroids[i]= 0;
                        st.push(index);
                    }
                    else if(asteroids[index] < abs(asteroids[i]))
                    {
                        
                        asteroids[index] =0;
                    }
                    else
                    {
                        asteroids[index] =0;
                        asteroids[i] =0;

                    }
                }
            }
        }

        vector<int>result;
        for(int i =0; i<n;i++)
        {
            if(asteroids[i] !=0) result.push_back(asteroids[i]);
        }

        return result;
    }
};