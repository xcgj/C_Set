#include <stdio.h>
int main()
{
	int q, w, e, r;
	for (q = 100; q < 1000; q++)
	{
		w = q % 10;	        //个位
		e = q / 10 % 10;	//十位
		r = q / 100;	    //百位
		if (q == (w*w*w + e*e*e + r*r*r))
		{
			printf("%d\n", q);
		}
	}
	return 0;
}
