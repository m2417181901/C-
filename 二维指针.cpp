#include <iostream>
bool identity_matrix(int **mat, int nNum)
{
    int sum = 0;
    int *pnCur;
    int *pnXAddr = (int *)mat; // jernymy �ҵ�������׵�ַ����ΪX���׵�ַ
 
    for (int a = 0; a < nNum; a++)
    {
        for (int b = 0; b < nNum; b++)
        {    
            pnCur = ((pnXAddr + a * nNum) + b); // jernymy ��Ϊ��ά�������һά���飬����Ҫ�ҵ�y��Ӧƫ�Ƶ�ַ
            if (*pnCur != 0 && *pnCur != 1) // jernymy �����ֵ�Ȳ�Ϊ0��ͬʱҲ��Ϊ1�����ǡ�
            {
                return 0;
            }
            else if ((*pnCur == 1) && (a == b))
            {
                sum++;
            }
            else if ((*pnCur == 1) && (a != b))
            {
                return 0;
            }
        }
    }
 
    if(sum == nNum)
    {
        return 1;
    }
    return 0;
}
 
int main()
{
    int a[10][10]={1,2,3,4,5,6,7,8,9,0,
                   1,2,3,4,5,6,7,8,9,0,
                   1,2,3,4,5,6,7,8,9,0,
                   1,2,3,4,5,6,7,8,9,0,
                   1,2,3,4,5,6,7,8,9,0,
                   1,2,3,4,5,6,7,8,9,0,
                   1,2,3,4,5,6,7,8,9,0,
                   1,2,3,4,5,6,7,8,9,0,
                   1,2,3,4,5,6,7,8,9,0,
                   1,2,3,4,5,6,7,8,9,0};
 
    int matrix[100] = 
    {
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1
    };
 
 
    int nRet = identity_matrix((int **)a, 10);
    printf("matrix a is.....:%d[0-not, 1-yes]\n", nRet);    
 
    nRet = identity_matrix((int **)matrix, 10);
    printf("matrix matrix is:%d[0-not, 1-yes]\n", nRet);    
 
    return 0;
}
 

