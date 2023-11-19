#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#define _GNU_SOURCE

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

    if ((dir = opendir(".")) != NULL) 							//opens directory   //readdir reads next directory entry
	{
        while ((ent = readdir(dir)) != NULL) 					//iterates through the latest files and checks for the highest roll no among them
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

int main() 
{
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

    return 0;
}

