#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    char line[200];
    int i=0,found=0;

    fgets(line,sizeof(line),stdin);


    line[strcspn(line, "\n")] = '\0';

   for (i=0; line[i]!='\0'; i++)
   {
    if(line[i]=='/')
    {
        if(line[i+1]=='/' || line[i+1]== '*')
        {
            printf("%d",i);
            found = 1;
        
    }
    else if (i>0 && line[i - 1] != '/' && line[i + 1] != '/' && line[i + 1] != '*')
    {
         printf("%d",i);
            found = 1;
    }
}
   }
   if (found) {
        printf("\nResult: '/' symbol FOUND in the program\n");
    } else {
        printf("\nResult: '/' symbol NOT FOUND in the program\n");
    }
return 0;

}
