void generateP(int index){//index���� 
	if(index==n+1){
		count++;//�ܵ�������һ���ǺϷ��� 
		return; 
	}
	for(int x=1;x<=n;x++){
		if(hasTable[x]==false){//��x�л�û�лʺ�
		//�ж�x���ܷ���ûʺ� 
			flag=true;//true��ʾ��ǰ�ʺ󲻻���֮ǰ�Ļʺ��ͻ
			for(int pre=1;pre<index;pre++){//����֮ǰ�Ļʺ� 
				if(abs(index-pre)==abs(x-P[pre])){
					flag=false;
					berak;
				}
			}
			if(flag){
				P[index]=x;
				hasTable[x]=true;//��x���Ѿ���ռ�� 
				generateP(index+1);//�ݹ鴦���index+1�лʺ�
				hasTable[x]=false; 
			}
		}
	} 
} 
