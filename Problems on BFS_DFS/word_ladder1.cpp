class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Store pair of word and its step level
        queue<pair<string, int>> q;
        // Store wordlist into set for O(1) search and deletion
        unordered_set<string> st(wordList.begin(), wordList.end());
        q.push(make_pair(beginWord,1));
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            // Check word to targetword
            if(word==endWord){
                return steps;
            }
            for(int i=0;i<word.size();i++){
                char original=word[i];
                // try every combination of word and check their presence in wordList
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        // If present then push the word to queue for next search
                        q.push(make_pair(word,steps+1));
                        // Erase from set to avoid word search in future traversals 
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};
