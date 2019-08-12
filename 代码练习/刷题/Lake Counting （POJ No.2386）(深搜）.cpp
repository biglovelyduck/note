/*��һ����СΪN��M��԰�ӣ���������ˮ������ͨ�Ļ�ˮ����Ϊ��������һ��ġ������
԰�����ܹ��ж���ˮ�ݣ�������ָͨ������ͼ�����W ��*�Ĳ��֣�
***
*W*
***
��������
. N, M �� 100*/ 

// ����
int N, M;
char field[MAX_N][MAX_M + 1]; // ԰��
// ����λ��(x,y)
void dfs(int x, int y) {
// ����������λ���滻Ϊ.
	field[x][y] = '.';
// ѭ�������ƶ���8������
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
// ��x�����ƶ�dx����y�����ƶ�dy���ƶ��Ľ��Ϊ��nx,ny��
			int nx = x + dx, ny = y + dy;
// �ж�(nx,ny)�ǲ�����԰���ڣ��Լ��Ƿ��л�ˮ
			if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W') dfs(nx, ny);
		}
	}
	return ;
}
void solve() {
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] == 'W') {
// ����W�ĵط���ʼdfs
				dfs(i, j);
				res++;
			}
		}
	}
	printf("%d\n", res);
}
