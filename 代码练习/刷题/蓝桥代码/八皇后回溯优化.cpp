void generateP(int index){//index是列 
	if(index==n+1){
		count++;//能到达这里一定是合法的 
		return; 
	}
	for(int x=1;x<=n;x++){
		if(hasTable[x]==false){//第x行还没有皇后
		//判断x行能否放置皇后 
			flag=true;//true表示当前皇后不会与之前的皇后冲突
			for(int pre=1;pre<index;pre++){//遍历之前的皇后 
				if(abs(index-pre)==abs(x-P[pre])){
					flag=false;
					berak;
				}
			}
			if(flag){
				P[index]=x;
				hasTable[x]=true;//第x行已经被占用 
				generateP(index+1);//递归处理第index+1行皇后
				hasTable[x]=false; 
			}
		}
	} 
} 
