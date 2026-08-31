class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string>s(wordList.begin(), wordList.end());
        if(s.find(endWord) == s.end()) return 0;

        queue<string>q;
        q.push(beginWord);
        int length = 1;
        while(!q.empty())
        {
            int n= q.size();
            length++;
            while(n--)
            {

                string st = q.front();
                q.pop();

                for(int i =0; i<st.length();i++)
                {
                    char org = st[i]; // store thr original char
                    for(char j ='a'; j<='z'; j++)
                    {
                        
                        if( j == org) continue;
                        st[i] = j;
                        if(st ==endWord ) return length;
                        if(s.find(st) != s.end())
                        {
                            q.push(st);
                            s.erase(st); // Remove from set to avoid repetation
                        }

                    }
                    st[i] =org;
                }
            }
        }

        return 0;
        
    }
};