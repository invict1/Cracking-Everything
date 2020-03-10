class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> ht(26);
        for (int c=0; c<order.size(); c++) {
            ht[order[c]- 'a'] = c;
        }
        for (int i=0; i<words.size()-1; i++) {
            string first = words[i];
            string second = words[i+1];
            int minLength = min(first.length(), second.length());
            for (int j=0; j<minLength; j++) {
                if (first[j] != second[j]) {
                    if (ht[first[j]- 'a'] > ht[second[j]- 'a']) return false;
                    if (j == second.length() - 1) return true;
                    break;
                }
            }
            if (first.length() > second.length()) return false;
        }
        return true;
    }
};
