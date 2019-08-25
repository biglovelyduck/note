//7-整数反转
class Solution {
    public: int reverse(int x) {
        int rev = 0;			//新栈里已经保存的数字 
        while(x != 0){
            int pop = x % 10;	//弹出来的最后一个数字 
            x = x / 10;
            if(rev > INT_MAX / 10 || 	//这个一定会溢出 
			(rev == INT_MAX / 10 && pop > INT_MAX % 10)){
                rev = 0;
                break;
            }else if(rev < INT_MIN / 10 || 
			(rev == INT_MIN / 10 && x < INT_MIN % 10)){
                rev = 0;
                break;
            }
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        while (x) {
            int pop = x % 10;
            x /= 10;
            rev = rev * 10 + pop;
        }
        return (rev > INT_MAX || rev < INT_MIN) ? 0 : static_cast<int>(rev);
    }
};

