#include <stdio.h>
int main()
{
	int p, q, j;
	for (p = 1; p < 100; p++)
	{
		j = 1;
		for (q = 2; q < p; q++)	//1和2不会被执行循环，但能输出
		{
			if (p % q == 0)
			{
				j = 0;
				break;
			}
		}
		if (j == 1)
		{
			printf("%d\n", p);
		}
	}
	return 0;
}
