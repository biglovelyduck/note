/*Fence Repair(PKU3253)*/
//���⣺����N�鳤��ΪLi��ľ�壬��ָ��������ľ�����С����
typedef long long ll;
int N,L[MAX_N];
void solve(){
	ll ans=0;
	//����һ����С����ȡ����ֵ�����ȶ���
	priority_queue<int,vector<int>,greater<int> > que;
	for(int i=0;i<N;i++){
		que.push(L[i]);
	}
	//ѭ����ֻʣ��һ��ľ��Ϊֹ
	while(que.size()>1){
		//ȡ����̺ʹζ�ľ��
		int l1,l2;
		l1=que.top();l1.pop();
		l2=que.top();l2.pop();
		ans+=l1+l2;
		que.push(l1+l2); 
	}
	cout<<ans; 
} 

