#include<stdio.h>
int pick[6] = { 0 };//记录要打印的物品的下标  
int sz = 0;//记录打印答案的个数  
int flag = 0; //标志符号：记录有没有解  
 
int KNAP(int s, int w[], int n)
{
	if (s == 0)
	{
		printf("{ ");
		for (int i = 0; i < sz; i++)
		{
			printf("%d ", w[pick[i]]);
		}
		printf("},");
		flag = 1;
		return 1;
	}
	else if (s < 0 || n < 1)
		return 0;
	else
	{
		KNAP(s, w, n - 1);//所选物品不包括w[n-1]
		pick[sz++] = n - 1;
		KNAP(s - w[n - 1], w, n - 1);// 所选物品包括w[n-1]	
		sz--;
	}
	return flag;
}
 
int main()
{
	int s= 0;
	int n = 0;
	int w[100] = { 0 };
	printf("请输入一个背包可以放入物品的重量：\n");
	scanf_s("%d", &s);
	printf("请输入物品的个数：\n");
	scanf_s("%d", &n);
	printf("请输入物品的重量：\n");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &w[i]);
	}
	if (KNAP(s, w, n))
		printf("有解\n");
	else
		printf("背包问题\n");
	return 0;
}