#include <stdio.h>

int main() 
{
        /*

        Macros are defined in C __APPLE__ AND _WIN64 / _WIN32
        __APPLE__ : 1 if MacOS, 0 otherwise
        _WIN64 : 1 if windows 64 bit
        _WIN32 : 1 if windows 32 bit

        */
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