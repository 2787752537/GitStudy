//
// Created by 86199 on 2023/3/14.
//

#include "1605.h"
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int** restoreMatrix(int* rowSum, int rowSumSize, int* colSum, int colSumSize, int* returnSize, int** returnColumnSizes){
    int **mat=(int **) malloc(sizeof (int *)*rowSumSize);
    for(int i=0;i<rowSumSize;i++)
    {
        mat[i]=(int *) malloc(sizeof (int)*colSumSize);
//        memset(mat[i], 0, sizeof(int) * colSumSize);
    }
    for(int i=0;i<rowSumSize;i++)
    {
        for(int j=0;j<colSumSize;j++)
        {
            mat[i][j]=0;
        }
    }
    int i=0;
    int j=0;
    while (i<rowSumSize&&j<colSumSize)
    {
        if(rowSum[i]>colSum[j])
        {
            mat[i][j]=colSum[j];
            rowSum[i]-=colSum[j];
            ++j;
        } else
        {
            mat[i][j]=rowSum[i];
            colSum[j]-=rowSum[i];
            ++i;
        }
    }
    *returnSize = rowSumSize;
    *returnColumnSizes = (int *)malloc(sizeof(int) * rowSumSize);
    for (int k = 0; k < rowSumSize; k++) {
        (*returnColumnSizes)[k] = colSumSize;
    }
    return mat;
}

void text_1605()
{
    int rowSumSize=0;
    int colSumSize=0;
    scanf("%d%d",&rowSumSize,&colSumSize);
    int *rowSum=(int *) malloc(sizeof (int)*rowSumSize);
    int *colSum=(int *) malloc(sizeof (int)*colSumSize);
    for(int i=0;i<rowSumSize;i++)
    {
        scanf("%d",rowSum+i);
    }
    for(int i=0;i<colSumSize;i++)
    {
        scanf("%d",colSum+i);
    }

    int returnSize;
    int *returnColumnSizes;
    int **mat =restoreMatrix(rowSum,rowSumSize,colSum,colSumSize,&returnSize,&returnColumnSizes);

    for(int i=0;i<returnSize;i++)
    {
        for(int j=0;j<returnColumnSizes[i];j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<returnSize;i++)
    {
        free(mat[i]);
    }
    free(rowSum);
    free(colSum);
    free(mat);
    free(returnColumnSizes);

}