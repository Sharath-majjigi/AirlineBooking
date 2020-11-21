#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    FILE *f;
    char username[30],password[30],buffer[40];
    int i,j;
    char str[100][30];
    char u[30],p[30];
    f = fopen("signup.txt","r");
    printf("\nEnter your username\n");
    scanf("%s",u);
    printf("\nEnter your password\n");
    scanf("%s",p);
    if(f != NULL)
    {
        i = 0;
        while(fscanf(f,"%s",buffer) == 1){
            strcpy(str[i],buffer);
            i++;
        }
        while(--i){
                 // printf("%s\n%s",str[j - 1],str[j - 2]);
                 // printf("%d\n%d\n%lu",strcmp(username,str[j-1]),strcmp(password,str[j-2]),strlen(username));
            if(!(strcmp(u,str[i-1]) && strcmp(p,str[i]))){
          
                printf("\nLogin Sucessful\n");
                exit(0);
            }
        }
        if(i == 0){
            printf("\nLogin Failed\n");
        }

    }
    else
    {
        printf("FILE ERROR");
    }
    fclose(f);
    return 0;
}