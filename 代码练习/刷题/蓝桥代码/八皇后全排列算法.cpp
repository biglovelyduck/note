int count=0; 
void generateP(int index){
	//1~n��ȫ���� 
	if(index=n+1){//�ݹ�߽磬����һ������ 
		bool flag=true;//flagΪtrue��ʾ��ǰ��һ���Ϸ����� 
		for(int i=1;i<=n;i++){//�������������ʺ� 
			for(int j=i+1;j<=n;j++){
				if(abs(i-j)==abs(P[i]-P[j])){//�����ͬһ�Խ����� 
					flag=false;//���Ϸ� 
				} 
			}
		}
		if(flag) count++;
		return; 
	}
	//������
	for(int x=1;x<=n;x++){//ÿ�� 
		if(hasTable[x]==false){//��ǰx��û�����ʹ� 
			P[index]=x;//index�ж�Ӧ���� ,��̽���е��� 
			hasTable[x]=true;
			generateP(index+1);
			hasTable[x]=false;
		}
	} 
} 
