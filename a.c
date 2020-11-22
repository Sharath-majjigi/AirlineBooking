#include <stdio.h>

int main() 
{
	#if __APPLE__
            printf("MacOS\n");
    #elif _WIN32
            printf("Windows 32 bit\n");
    #elif _WIN64
            printf("Windows 64 bit\n");
	#endif
        printf("%d",__APPLE__);
	return 0;
}