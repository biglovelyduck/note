//礼物的最大价值 
#include <iostream>
#include <vector>

using namespace std;

int getMaxValue_solution2(vector<int> mat, int row, int col);

int main()
{
    vector<int> mat = {1,10,3,8,12,2,9,6,5,7,4,11,3,7,16,5};
    int result = getMaxValue_solution2(mat,4,4);
    cout << result <<endl;
    return 0;
}

int getMaxValue_solution2(vector<int> mat, int row, int col)
{
    int result = -1;
    if(mat.empty() || row < 1 || col < 1)
    {
        return result;
    }
    int* temp = new int[col];
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            int up = 0;
            int left = 0;
            if(i > 0)
                up = temp[j];
            if(j > 0)
                left = temp[j-1];

            temp[j] = max(left , up) + mat[i * col + j];
        }
    }
    result = temp[col - 1];
    delete[] temp;
    return result;
}

