//N只动物，属于三种物种ABC，三种关系A吃B，B吃C，C吃A
//给出两种信息的个数各种信息，判断错误数
//思路：i-x表示i属于种类x,并查集里每一个组表示组内所有蒜素代表的情况都同时发生 
//第一种：x和y属于同一类。。。合并x-A和y-A,x-B和y-B,x-C和y-C
//第二种：x吃y。。。合并x-A和y-B，合并x-B和y-C，合并x-C和y-A， 
int N,K;//N只动物，K条信息
int T[MAX_K],X[MAX_K],Y[MAX_K];
//在这里省略的并查集的代码
void solve(){
	//初始化并查集
	//元素x，x+N,x+2*N分别代表x-A,x-B,x-C
	init(N*3);
	
	int ans=0;
	for(int i=0;i<K;i++){
		int t=T[i];//每条信息
		int x=X[i]-1,y=Y[i]-1;//吧输入变成0...N-1的范围
		//不正确的编号
		if(x<0||N<=x||y<0||N<=y){
			ans++;
			continue;
		}
		//判断属于哪一种信息 
		if(t==1){
			//x和y属于同一类的信息
			//不属于同一类 
			//同一个种类是一个组 
			if(same(x,y+N)||same(x,y+2*N)) {
				ans++;
			}
			//属于同一类 
			else{
				unite(x,y);
				unite(x+N,y+N);
				unite(x+N*2,y+N*2);
			}
		} 
		else{
			//x吃y的信息
			if(same(x,y)||same(x,y+2*N)){
				ans++;
			} 
			else{
				unite(x,y+N);
				unite(x+N,y+2*N);
				unite(x+2*N,y);
			}
		}
	} 
	cout<<ans;
} 
