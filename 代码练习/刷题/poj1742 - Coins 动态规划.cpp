/*��Ŀ���⣺��n��Ӳ�ң���n��Ӳ�ҵļ�ֵΪa[i]����i��Ӳ�ҵĸ���Ϊc[i]�������ж����ַ�����
ʹ��ЩӲ�Ҽ���������m
����һ������Ķ��ر�������������*/
//������� 
/*#include <iostream>
using namespace std;
#define MAXV 105
#define MAXM 100005
#include<iostream>
using namespace std;
#define MAXV 105
#define MAXM 100005
 
int weight[MAXV],c[MAXV],f[MAXM],user[MAXM];
 
int main(){
	int i,j,n,m,ans;
	while(scanf("%d%d",&n,&m) && n && m){	//n��m������0����0 0�˳�ѭ�� 
		for(i=1;i<=n;i++)
			scanf("%d",&weight[i]);
		for(i=1;i<=n;i++)
			scanf("%d",&c[i]);
 
		memset(f,0,sizeof(f));
		f[0]=1;ans=0;
		for(i=1;i<=n;i++){
			memset(user,0,sizeof(user));
			for(j=weight[i];j<=m;j++){
				if(!f[j] && f[j-weight[i]] && user[j-weight[i]]+1<=c[i]){
					f[j]=1;
					user[j]=user[j-weight[i]]+1;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}*/

//����˼· 
/*dp[i][j] := ��ǰi��Ӳ���ܷ�ճ�j

���ƹ�ϵʽ��

dp[i][j] = ������kʹ��dp[i �C 1][j �C k * A[i]]Ϊ�棬0 <= k <= m ���±�Ϸ���*/
/* 
#include <iostream>
#include <algorithm>
using namespace std;
 
bool dp[100 + 16][100000 + 16]; // dp[i][j] := ��ǰi��Ӳ���ܷ�ճ�j
int A[100 + 16];
int C[100 + 16];
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
	int n, m;
	while(cin >> n >> m && n > 0)
	{
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; ++i)
		{
			cin >> A[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> C[i];
		}
		dp[0][0] = true;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= m; ++j)
			{
				for (int k = 0; k <= C[i] && k * A[i] <= j; ++k)
				{
					dp[i + 1][j] |= dp[i][j - k * A[i]];
				}
			}
		}
		int answer = count(dp[n] + 1, dp[n] + 1 + m , true); // �ܶ�0�����ڴ���
		cout << answer << endl;
	}
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("out.txt");
#endif
    return 0;
}*/
/*����㷨ÿ��ֻ��¼һ��boolֵ����ʧ�˲�����Ϣ������������У������ܹ�����Ƿ��ܵõ�ĳ����
ͬʱ���ܰѵó��˴˽��ʱA_i��ʣ�¶��ٸ������������ֱ��ʡ����k����ѭ����
�Ż�dp���壺

dp[i][j] := ��ǰi��Ӳ�Ҵճ�jʱ��i��Ӳ�������ʣ����ٸ���-1��ʾ�䲻������
            ���dp[i - 1][j] >= 0(ǰi-1�������Դճ�j����ô��i���������ò���)ֱ��ΪC[i]
dp[i][j] =  ���j < A[i]����dp[i][j - a[i]] <=0 (���̫����������С������ʱ����ù��ˣ�-1
            ����������i�����õ�һ���� dp[i][j-a[i]] - 1
            ���ͳ��һ��dp�����n��>=0�ĸ�����֪�����ˣ�
*/
/*
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
 
int dp[100 + 16][100000 + 16]; // dp[i][j] := ��ǰi��Ӳ�Ҵճ�jʱ��i��Ӳ�������ʣ����ٸ�
int A[100 + 16];
int C[100 + 16];
 
int main(int argc, char *argv[])
{

	int n, m;
	while(cin >> n >> m && n > 0)
	{
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> A[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> C[i];
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= m; ++j)
			{
				if (dp[i][j] >= 0)
				{
					dp[i + 1][j] = C[i];
				}
				else if (j < A[i]						// ��һ���ͳ�����������
						|| dp[i + 1][j - A[i]] <= 0)		// ���ձ�jС������ʱ�������ˣ���ʱ����������
				{
					dp[i + 1][j] = -1;
				}
				else
				{
					dp[i + 1][j] = dp[i + 1][j - A[i]] - 1;		// ������һ����i��Ӳ��
				}
			}
		}
		int answer = count_if(dp[n] + 1, dp[n] + 1 + m , bind2nd(greater_equal<int>(), 0)); // �ܶ�0�����ڴ���
		cout << answer << endl;
	}

    return 0;
}*/
/*
dp[j] := �ڵ�i��ѭ��ʱ֮ǰ��ʾ��ǰi-1��Ӳ�Ҵճ�jʱ��i��Ӳ�������ʣ����ٸ���-1��ʾ�䲻��������ѭ��֮��ͱ�ʾ��i�ε�״̬

���Ǿ�ʡ��һά���飺*/
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
 
int dp[100000 + 16]; // dp[i][j] := ��ǰi��Ӳ�Ҵճ�jʱ��i��Ӳ�������ʣ����ٸ�
int A[100 + 16];
int C[100 + 16];
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
	int n, m;
	while(cin >> n >> m && n > 0)
	{
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> A[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> C[i];
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= m; ++j)
			{
				if (dp[j] >= 0)
				{
					dp[j] = C[i];
				}
				else if (j < A[i]						// ��һ���ͳ�����������
						|| dp[j - A[i]] <= 0)		// ���ձ�jС������ʱ�������ˣ���ʱ����������
				{
					dp[j] = -1;
				}
				else
				{
					dp[j] = dp[j - A[i]] - 1;		// ������һ����i��Ӳ��
				}
			}
		}
		int answer = count_if(dp + 1, dp + 1 + m , bind2nd(greater_equal<int>(), 0)); // �ܶ�0�����ڴ���
		cout << answer << endl;
	}
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("out.txt");
#endif
    return 0;
}
