#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string newS;
        for (int i = s.size() - 1; i >= 0;) {
            while(i>=0&&s[i]==' '){
                i--;
            }
            int j = i;
            while(j>=0&&s[j]!=' '){
                j--;
            }
            if(j<0){
                newS.append(s.substr(0, i+1));
            }else{
                newS.append(s.substr(j + 1, i - j));
                newS.append(" ");
            }
            i = j;
        }
        if(*(newS.end()-1)==' '){
            newS.erase(newS.end() - 1);
        }

        return newS;
    }
};