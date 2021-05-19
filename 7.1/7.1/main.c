#include<stdio.h>
#define hang 9
#define lie 9
int main()
{
	int a[hang][lie] = { {0} };
	int i=0, j=lie/2;
	int num = 2;
	int c=i,d=j;
	a[0][lie / 2] = 1;             //*********将1放在第0行中间
	for (; num <= hang * lie; num++)  //**********将每个位置赋值
	{
		if (i == 0)       //***********************如果在第0行，则下一行为最后一行
			i = hang - 1;
		else i--;     //***************不在第一行，则下一次行数减1
		if (j == lie - 1)    //**************如果在最后一列，下一列为第0列
			j = 0;
		else j++;    //****************不在最后一列，下一次列数加1
		if (a[i][j] == 0)    //********如果i行j列没有数，将num存放在此处
		{
			a[i][j] = num;
			c = i, d = j;   //*************记录存放的位置
		}
		else    //*************i行j列有数，将数存放在上一个数的下方
		{
			i = c + 1;
			j = d;
			if (i >= lie)   
				i = 0;
			a[i][j] = num;
		}
	}
	for (i = 0; i < hang; i++)   //**********输出数组
	{
		for (j = 0; j < lie; j++)
		{
			printf("%5d", a[i][j]);
			if ((j + 1) % lie == 0)
				printf("\n");
		}
	}
	
}