#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b,c,d,e,f;
 	for(a=1;a<=9;a++)
 	{
 		for(b=1;b<=9;b++)
 		{
 			for(c=1;c<=9;c++)
 			{
				for(d=1;d<=9;d++)
 				{
				 	for(e=1;e<=9;e++)
 					{
 						for(f=1;f<=9;f++)
 						{
							if( a!=b && a!=c && a!=d && a!=e && a!=f&& b!=c && b!=d && b!=e && b!=f&& c!=d && c!=e && c!=f&& d!=e && d!=f&& e!=f)
 							{
								if(a+b+c==a+d+e && c+e+f==a+b+c)
								{
									printf("%d+%d+%d ",a,b,c);
									printf("%d+%d+%d ",a,d,e);
									printf("%d+%d+%d \n",c,e,f);
								}
							}
						}
					}
				}	
			}
		}	
	}
	return 0; 
}

