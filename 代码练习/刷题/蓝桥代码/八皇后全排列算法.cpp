int count=0; 
void generateP(int index){
	//1~n的全排列 
	if(index=n+1){//递归边界，生成一个排列 
		bool flag=true;//flag为true表示当前是一个合法方案 
		for(int i=1;i<=n;i++){//遍历任意两个皇后 
			for(int j=i+1;j<=n;j++){
				if(abs(i-j)==abs(P[i]-P[j])){//如果在同一对角线上 
					flag=false;//不合法 
				} 
			}
		}
		if(flag) count++;
		return; 
	}
	//主程序
	for(int x=1;x<=n;x++){//每行 
		if(hasTable[x]==false){//当前x行没被访问过 
			P[index]=x;//index列对应的行 ,试探所有的行 
			hasTable[x]=true;
			generateP(index+1);
			hasTable[x]=false;
		}
	} 
} 
