#include<stdio.h>
#include<string.h>
int main(){
    FILE *f;
    char username[30],password[30];
    f = fopen("signup.txt","a+");
    if(f != NULL){
            printf("\nEnter your username\n");
            scanf("%s",username);
            fprintf(f,"%s\n",username);
            printf("\nEnter your password\n");
            scanf("%s",password);
            fprintf(f,"%s\n",password);
    }
    else{
        printf("FILE ERROR");
    }
    fclose(f);
    return 0;
}