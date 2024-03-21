#include<stdio.h>
#include<string.h>
#include<conio.h>

int login(){
    char name[20];
    char password[10];
    int i = 0;
    char ch;

    printf("Enter username: ");
    fgets(name, 20, stdin); 

    printf("Enter password: ");
    while(i<10){
        ch = getch();
        if(ch == '\r')
            break;
        password[i++] = ch;
        printf("*");
    }
    password[i] = '\0'; 

    if (strcmp(name, "Admin\n") == 0 && strcmp(password, "pass") == 0) 
        printf("\nVALID\n");
    else 
        printf("\nINVALID\n");

    return 0;
}

int main(){
    return login();
}
