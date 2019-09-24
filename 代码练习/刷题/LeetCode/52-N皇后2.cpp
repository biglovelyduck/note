//52-N�ʺ�2
class Solution {
public:
    int totalNQueens(int n) {
        int ans=0;
        int a[n];
        dfs(0,ans,n,a);
        return ans;
    }
    bool attack(int x0,int y0,int x1,int y1){//��ʾ����λ���Ƿ���Թ������Ƿ���true
	    if(x0==x1||y0==y1) return true;
	    if(x0+y0==x1+y1||x0-y0==x1-y1) return true;
	    return false;
}
    void dfs(int row,int &ans,int&n,int *a){
    	if(row==n){
    		ans++;
    		return;
		}
		for(int i=0;i<n;i++){
			bool flag=true;
			for(int j=0;j<row;j++){
				if(attack(j,a[j],row,i)){
					flag=false;
					break;
				}
			}
			if(flag){
				a[row]=i;
				dfs(row+1,ans,n,a);
			} 
		}
	}
}; 
