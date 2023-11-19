#include <stdio.h>
#include <unistd.h>

void Timer(int seconds) 
{
    int h = seconds / 3600;					//converting seconds into minutes and hours..
    int m = (seconds % 3600) / 60;
    int s = seconds % 60;
                     
    printf("\r%02d:%02d:%02d", h, m, s);	 // \r is used to move the cursor to the beginning of current line
    fflush(stdout);                          //TO ensure that data is displayed immediately...
}

int main() 
{
    int seconds=360;						
    while(seconds>0) 
	{
        Timer(seconds);
        sleep(1); 							//delays the program by 1sec.
        seconds--;
    }
    printf("\rTIME UP!\n");
    return 0;
}

