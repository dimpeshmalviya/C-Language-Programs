#include<stdio.h>
int option = 0;
int checkuser(char username[])
{
    char line[200];
    FILE *f1 = fopen("users.txt", "r");
    while (fgets(line, 1000, f1))
    {
        char *userdata = strtok(line, ",");
        // printf("username = %s\n", userdata);
        if (!strcmp(userdata, username))
        {
            fclose(f1);
            return 1;
        }
    }
    fclose(f1);
    return 0;
}

int reg(char username[], char password[], char name[])
{
    if (checkuser(username))
    {

        return 0;
    }
    FILE *f1 = fopen("users.txt", "a");
    fprintf(f1, "%s,%s,%s\n", username, password, name);
    fclose(f1);
    return 1;
}

void doreg()
{
    system("cls");
    printf("registration page\n\n\n");
    char username[20], password[20], name[20];

    printf("please enter username: ");
    fflush(stdout);
    scanf("%s", &username);
    fflush(stdin);
    printf("please enter password: ");
    gets(password);
    printf("please enter name: ");
    gets(name);
    if (reg(username, password, name))
    {
        printf("registration is successful\n\n");
        // printf(("please enter 1 for login: "));
        // scanf("%d", &option);
    }
    else
    {
        printf("user already exists");
    }
}