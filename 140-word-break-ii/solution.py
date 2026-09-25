class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> list[str]:

        wordset = set(wordDict)
        memo={}

        # recurtion Func
        def dfs( start):

            if start == len(s):
                return [""]
            
            if start in memo :
                return memo[start]
            
            result = []

            for end in range( start, len(s)):
                word = s[start : end+1]

                if word in wordset:

                    remain = dfs(end+1)

                    for sentence in remain:
                        if sentence == "":
                            result.append(word)
                        else:
                            result.append(word + " " + sentence)
            
            memo[start] = result
            return result
        

        return dfs(0)

        
        

        