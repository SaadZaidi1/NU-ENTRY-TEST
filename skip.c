#include<stdio.h>

void skip(char *ques[30],char ans[30],int skip[30],float adv,float basic,float iq,float english)
{
	int i;
	for(i=0;i<30;i++)
	{
		if(skip[i]==1)                //if the flag is 1 only then we will repeat the question otherwise we will will not repeat the question  
		{
			char ans1;
			printf("%s",ques[i]);
			scanf(" %c",&ans1);
			if(ans1==ans[i])            //if ans is correct we will update the score by +1  in the respective portion
			{
				if(i<10)
				{
					adv++;
				}
				else if(i<20)
				{
					basic++;
				}
				else if(i<25)
				{
					iq++;
				}
				else
				{
					english++;
				}
			}
			else 				//updating the score by -1 when ans is incorrect 
			{
				if(i<10)
				{
					adv--;
				}
				else if(i<20)
				{
					basic--;
				}
				else if(i<25)
				{
					iq--;
				}
				else
				{
					english--;
				}
			}
		}
		else 				//if flag is 0 or any value other than 1 then we will skip the question as it has already been answered. 
		{
			continue;
		}
	}
}
