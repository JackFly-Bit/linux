#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    while(1)
    {
        char* lp = (char*)malloc(1024*1024*512);
        if(!lp)
        {
            printf("malloc failed\n");
            continue;
        }
        //strcpy(lp, "57-linux");
    }
    return 0;
}
