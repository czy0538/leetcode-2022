#include <string>
#include <algorithm>
using namespace std;
// 构建新的串的方法，时间和空间复杂度均为O(n)
// class Solution {
// public:
//     string replaceSpace(string s) {
//         const auto target = "%20";
//         string newS;
//         for(const auto &i:s){
//             if (i==' '){
//                 newS.append(target);
//             }else{
//                 newS.append(1,i);
//             }
//         }
//         return newS;
//     }
// };

// 双指针法，空间复杂度为O(1)，这得益于 c++ 的字符串特性
class Solution {
public:
    string replaceSpace(string s) {
        int n=0;
        for (const auto& c : s) {
            if (c == ' ') {
                n++;
            }
        }
        int j = s.size() + n * 2-1;
        int i = s.size() - 1;
        s.resize(j+1);
        while(i>=0){
            if(s[i]==' '){
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            }else{
                s[j--] = s[i];
            }
            i--;
        }
        return s;
    }
};