#include <stdio.h>
int loguser(char username[], char password[])
{
    char line[200];
    int condition1 = 0, condition2 = 0;
    FILE *f1 = fopen("users.txt", "r");
    while (fgets(line, 1000, f1))
    {
        int count = 0;
        char *userdata = strtok(line, ",");
        while (userdata!=NULL)
        {
            count++;
            if (count == 1)
            {
                condition1 = !strcmp(userdata, username);
            }
            if (count == 2)
            {
                condition2 = !strcmp(userdata, password);
            }
            userdata++;
            userdata = strtok(NULL,",");
        }
        if (condition1 && condition2)
        {
            fclose(f1);
            return 1;
        }
    }
    fclose(f1);
    return 0;
}
void dolog()
{
    system("cls");
    printf("login page\n\n\n");
    char username[20], password[20], name[20];

    printf("please enter username: ");
    fflush(stdout);
    scanf("%s", &username);
    fflush(stdin);
    printf("please enter password: ");
     scanf("%s", &password);
  fflush(stdin);
  fflush(stdout);
    if ( loguser(username, password))
    {
        printf("login successful\n");
    }
    else
    {
        printf("login fail\n");
    }
}