//7-������ת
class Solution {
    public: int reverse(int x) {
        int rev = 0;			//��ջ���Ѿ���������� 
        while(x != 0){
            int pop = x % 10;	//�����������һ������ 
            x = x / 10;
            if(rev > INT_MAX / 10 || 	//���һ������� 
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

