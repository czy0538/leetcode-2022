#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        const auto target = "%20";
        string newS;
        for(const auto &i:s){
            if (i==' '){
                newS.append(target);
            }else{
                newS.append(1,i);
            }
        }
        return newS;
    }
};