#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#define _GNU_SOURCE

void Timer(int seconds) 
{
    int h = seconds / 3600;					//converting seconds into minutes and hours..
    int m = (seconds % 3600) / 60;
    int s = seconds % 60;
                     
    printf("\r%02d:%02d:%02d", h, m, s);	 // \r is used to move the cursor to the beginning of current line
    fflush(stdout);                          //TO ensure that data is displayed immediately...
}

int extractRollNumber(const char *fileName) 
{
    const char *rollNumberStart = fileName;
    while (*rollNumberStart && !isdigit(*rollNumberStart)) 		//function is provided with file name.	
	{															//extarcts roll no from file name
        rollNumberStart++;			                            //iterates through the file name 
    }
    return atoi(rollNumberStart);								//converts string into an integer
}

int findLastFile() 
{
    DIR *dir;													//pointer to a directory
    struct dirent *ent;
    int maxRollNumber = -1;

    if ((dir = opendir(".")) != NULL) 							//opens directory
	{
        while ((ent = readdir(dir)) != NULL) 			//iterates through the latest files and checks for the highest roll no among them
		{
            int rollNumber = extractRollNumber(ent->d_name);	//extracts roll no from file name and converts it into a integer from string
            if (rollNumber > maxRollNumber) 
			{
                 maxRollNumber = rollNumber;
            }
        }
        closedir(dir);
    } 
	else 
	{
        perror("Error opening directory");
        return -1;
    }

    return maxRollNumber;
}

void SKIP(char *ques[30],char ans[30],int skip[30],int adv,int basic,int iq,int english)
{
	int i;
	for(i=0;i<30;i++)
	{
		if(skip[i]==1)                //if the flag is 1 only then we will repeat the question otherwise we will will not repeat the question  
		{
			char ans1;
			printf("%s",ques[i]);
			scanf(" %c",&ans1);
			system("cls");
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

void checker(char *ques[30])
{
	char ans[30]={'A','C','A','D','A','A','B','B','B','C','B','D','B','B','D','B','B','B','B','B','B','A','A','C','C','B','D','D','B','D'};
	
	int i,j,skip[30],wrong=0;
	int total=0,basic=0,adv=0,english=0,iq=0;
	
	for(i=0;i<30;i++)
	{
		skip[30]=0;
	}
	for(i=0;i<30;i++)
	{
		if(i<10)			//CHECKING ANS OF ADVANCE MATHS PORTION
		{
		char ans1;
		printf("%s",ques[i]);
		scanf(" %c",&ans1);
		system("cls");
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
		system("cls");
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
		system("cls");
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
		else if(i<30)				//CHECKING ANS OF ENGLISH PORTION
		{
		char ans1;
		printf("%s",ques[i]);
		scanf(" %c",&ans1);
		system("cls");
		if(ans1==ans[i])
		{
			english++;
			skip[i]=0;
		}
		else if(ans1=='E')
		{
			skip[i]=1;
		}
		else 
		{
			english--;
			wrong++;
			skip[i]=0;
		}
		}
	}
	SKIP(ques,ans,skip,adv,basic,iq,english);
}

void question() 
{
    int i;
	char *ques[30] = {
        "1. What is the derivative of ln(x) with respect to x?\n   A) 1/x\n   B) x\n   C) 0\n   D) e^x\n",
        "2. Which of the following is a prime number?\n   A) 10\n   B) 25\n   C) 29\n   D) 35\n",
        "3. What is the value of p (pi) to three decimal places?\n   A) 3.142\n   B) 3.141\n   C) 3.1416\n   D) 3.140\n",
        "4. If a triangle has angles measuring 30 degrees, 60 degrees, and 90 degrees, what type of triangle is it?\n   A) Isosceles\n   B) Scalene\n   C) Equilateral\n   D) Right-angled\n",
        "5. What is the value of the square root of 144?\n   A) 12\n   B) 14\n   C) 10\n   D) 11\n",
        "6. If f(x) = 2x^2 + 3x - 1, what is the derivative of f(x) with respect to x?\n   A) 4x + 3\n   B) 2x^2 + 3x - 1\n   C) 2x + 3\n   D) 4x^2 + 3\n",
        "7. What is the area of a circle with a radius of 5 units?\n   A) 10 square units\n   B) 25 square units\n   C) 50 square units\n   D) 5p square units\n",
        "8. If log(base 2) 16 = 4, what is log(base 2) 64?\n   A) 4\n   B) 5\n   C) 6\n   D) 3\n",
        "9. In a geometric progression, if the first term is 2 and the common ratio is 3, what is the fourth term?\n   A) 6\n   B) 18\n   C) 9\n",
        "10. What is the solution to the equation 2x^2 + 5x - 3 = 0?\n    A) x = 1, x = -3/2\n    B) x = 3, x = -1/2\n    C) x = 1, x = -1/2\n    D) x = 3, x = -3/2\n",
        "11. What is the square of 9?\n   A) 63\n   B) 81\n   C) 72\n   D) 64\n",
        "12. If a triangle has sides measuring 3 cm, 4 cm, and 5 cm, what type of triangle is it?\n   A) Equilateral\n   B) Isosceles\n   C) Scalene\n   D) Right-angled\n",
        "13. What is the value of 5! (5 factorial)?\n   A) 20\n   B) 120\n   C) 25\n   D) 60\n",
        "14. If x = 4 and y = 2, what is the value of x^2 + 2xy + y^2?\n   A) 12\n   B) 16\n   C) 36\n   D) 64\n",
        "15. Solve for x: 2x - 3 = 7.\n   A) x = 4\n   B) x = 5\n   C) x = 6\n   D) x = 7\n",
        "16. What is the perimeter of a rectangle with length 10 cm and width 5 cm?\n   A) 10 cm\n   B) 20 cm\n   C) 30 cm\n   D) 50 cm\n",
        "17. Find the greatest common divisor (GCD) of 24 and 36.\n   A) 4\n   B) 6\n   C) 8\n   D) 12\n",
        "18. If the selling price of an item is $150, and the cost price is $120, what is the profit made?\n   A) $20\n   B) $30\n   C) $40\n   D) $150\n",
        "19. What is the value of v(25) + v(16)?\n   A) 9\n   B) 7\n   C) 11\n   D) 8\n",
        "20. If a circle has a radius of 7 cm, what is its circumference (use p = 3.14)?\n    A) 14.28 cm\n    B) 22 cm\n    C) 43.96 cm\n    D) 44 cm\n",
        "21. What comes next in the sequence: 2, 4, 8, 16, ____?\n   A) 24\n   B) 32\n   C) 48\n   D) 64\n",
        "22. If three cats can catch three mice in three minutes, how many cats are needed to catch 100 mice in 100 minutes?\n   A) 1 cat\n   B) 2 cats\n   C) 3 cats\n   D) 100 cats\n",
        "23. Which letter of the alphabet comes next in the series: J, F, M, A, M, J, ____?\n   A) J\n   B) F\n   C) M\n   D) J\n",
        "24. A farmer has 17 sheep, and all but 9 die. How many sheep does the farmer have left?\n   A) 17\n   B) 8\n   C) 9\n   D) 26\n",
        "25. If a plane crashes on the border of the United States and Canada, where do they bury the survivors?\n   A) The United States\n   B) Canada\n   C) Nowhere, survivors are not buried\n   D) Both the United States and Canada\n",
        "26. What is the definition of a palindrome?\n   A) A type of poem\n   B) A word or phrase that reads the same backward as forward\n   C) A type of grammar rule\n   D) A foreign language\n",
        "27. Which part of speech is used to describe a verb, adjective, or adverb?\n   A) Noun\n   B) Pronoun\n   C) Conjunction\n   D) Adverb\n",
        "28. What is the correct plural form of 'child'?\n   A) Childs\n   B) Childrens\n   C) Childs' \n   D) Children\n",
        "29. Which of the following is an example of an indefinite article?\n   A) The\n   B) An\n   C) In\n   D) Is\n",
        "30. What is the term for a group of words that expresses a complete thought and typically includes a subject and a predicate?\n   A) Paragraph\n   B) Clause\n   C) Phrase\n   D) Sentence\n"
    };

    	checker(ques);
}

int main()
{
	 int seconds=360;
	// Find the last file
    int lastRollNumber = findLastFile();

    if (lastRollNumber == -1) 
	{
        printf("No files found.\n");
    } 
	else 
	{
        printf("Last Roll Number: %d\n", lastRollNumber);

        // Increment the last roll number by 1
        int newRollNumber = lastRollNumber + 1;
        printf("New Roll Number: %d\n", newRollNumber);
        
        // Create a new file with the next roll number
        char newFileName[10];
        snprintf(newFileName, sizeof(newFileName), "%04d", newRollNumber);

        FILE *newFile = fopen(newFileName, "w");
        if (newFile == NULL) 
		{
            perror("Error creating new file");
            return 1;
        }
        // Write data to the new file
        fprintf(newFile, "Candidate Roll No: %d\n", newRollNumber);
        fclose(newFile);
        printf("New file created: %s\n", newFileName);
    }
    question();
}


