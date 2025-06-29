   unordered_set<string> seen;
        vector<string> result;
        int i = 0;
        int n = s.size();
        bool allSame = true;
        for(int i = 1; i < s.size(); i++){
            if(s[i] != s[0]){
                allSame = false;
                break;
            }
        }
        if(allSame){
            vector<string> ans;
            string first = "";
            first += s[0];
            ans.push_back(first);
            ans.push_back(s.substr(1));
            return ans;
        }
        
        while (i < n) {
            string segment = "";
            bool found = false;
            for (int j = i; j < n; ++j) {
                segment += s[j];
                if (!seen.count(segment)) {
                    seen.insert(segment);
                    result.push_back(segment);
                    i = j + 1;
                    found = true;
                    break;
                }
            }
            if (!found) {
                result.push_back(s.substr(i));
                break;
            }
        }
        return result;
    }