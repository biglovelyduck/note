#include <vector>
using namespace std;
//��̬������ά��������ַ��� 

int main(){
	//1.
	int row,col;
	int **arr=new int*[row]; 
	for(int i=0;i<col;i++){
		arr[i]=new int[col];
	}
	
	//2.
	vector<vector<int> > array(row);
	for(int i=0;i<col;i++)
		array[i].resize(col);
	return 0;
}
