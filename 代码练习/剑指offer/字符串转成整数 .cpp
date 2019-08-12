//字符串转成整数 
#include <string>
using namespace std;
class Solution {
public:
    int StrToInt(string str) {
        int n = str.size(), s = 1;
        long long res = 0;
        if(!n) return 0;
        if(str[0] == '-') s = -1;
        for(int i = (str[0] ==  '-' || str[0] == '+') ? 1 : 0; i < n; ++i){
            if(!('0' <= str[i] && str[i] <= '9')) return 0;
            res = (res << 1) + (res << 3) + str[i]-'0';//res=res*10+str[i]-'0';
        } 
        return res * s;       
    }
};
