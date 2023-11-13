#include<stdio.h>

void checker(char ques[30])
{
	char ans[30]={'A','C','A','D','A','A','B','B','B','C','B','D','B','B','D','B','B','B','B','B','B','A','A','C','C','B','D','D','B','D' };
	
	int i,j,skip[30],wrong=0;
	float total=0,basic=0,adv=0,english=0,iq=0;
	
	for(i=0;i<30;i++)
	{
		if(i<10)			//CHECKING ANS OF ADVANCE MATHS PORTION
		{
		char ans1;
		printf("%s",ques[i]);
		scanf(" %c",&ans1);
		
		if(ans1==ans[i])
		{
			adv++;
			skip[i]=0;
		}
		else if(ans1=='E')
		{
			skip[i]=1;
		}
		else 
		{
			adv--;
			wrong++;
			skip[i]=0;
		}
		}
		else if(i<20)		//CHECKING ANS OF BASIC MATHS QUESTIONS
		{
		char ans1;
		printf("%s",ques[i]);
		scanf(" %c",&ans1);
		
		if(ans1==ans[i])
		{
			basic++;
			skip[i]=0;
		}
		else if(ans1=='E')
		{
			skip[i]=1;
		}
		else 
		{
			basic--;
			wrong++;
			skip[i]=0;
		}
		}
		else if(i<25)		//CHECKING ANS OF IQ PORTION
		{
		char ans1;
		printf("%s",ques[i]);
		scanf(" %c",&ans1);
		
		if(ans1==ans[i])
		{
			iq++;
			skip[i]=0;
		}
		else if(ans1=='E')
		{
			skip[i]=1;
		}
		else 
		{
			iq--;
			wrong++;
			skip[i]=0;
		}
		}
		else				//CHECKING ANS OF ENGLISH PORTION
		{
		char ans1;
		printf("%s",ques[i]);
		scanf(" %c",&ans1);
		
		if(ans1==ans[i])
		{
			basic++;
			skip[i]=0;
		}
		else if(ans1=='E')
		{
			skip[i]=1;
		}
		else 
		{
			basic--;
			wrong++;
			skip[i]=0;
		}
		}
	}
}
