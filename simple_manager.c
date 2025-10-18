#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct {int id; char name[50]; int age;} Item;
Item db[MAX]; int db_count=0;
void print_title(void){printf("Simple Manager - Basic C Program\n");printf("================================\n");}
int find_index(int id){for(int i=0;i<db_count;i++) if(db[i].id==id) return i; return -1;}
void add_item(void){
    if(db_count>=MAX){printf("Database full\n");return;}
    int id,age; char name[50];
    printf("Enter id: ");
    if(scanf("%d",&id)!=1){while(getchar()!='\n');printf("Invalid input\n");return;}
    if(find_index(id)!=-1){printf("Id already exists\n");return;}
    printf("Enter name: "); while(getchar()!='\n');
    if(!fgets(name,sizeof(name),stdin)){printf("Read error\n");return;}
    name[strcspn(name,"\n")]=0;
    printf("Enter age: ");
    if(scanf("%d",&age)!=1){while(getchar()!='\n');printf("Invalid input\n");return;}
    db[db_count].id=id; strncpy(db[db_count].name,name,sizeof(db[db_count].name)-1); db[db_count].name[sizeof(db[db_count].name)-1]=0;
    db[db_count].age=age; db_count++; printf("Record added\n");
}
void list_items(void){
    if(db_count==0){printf("No records\n");return;}
    for(int i=0;i<db_count;i++) printf("ID:%d Name:%s Age:%d\n",db[i].id,db[i].name,db[i].age);
}
void delete_item(void){
    int id; printf("Enter id to delete: ");
    if(scanf("%d",&id)!=1){while(getchar()!='\n');printf("Invalid input\n");return;}
    int idx=find_index(id); if(idx==-1){printf("Not found\n");return;}
    for(int i=idx;i<db_count-1;i++) db[i]=db[i+1]; db_count--; printf("Deleted\n");
}
void update_item(void){
    int id; printf("Enter id to update: ");
    if(scanf("%d",&id)!=1){while(getchar()!='\n');printf("Invalid input\n");return;}
    int idx=find_index(id); if(idx==-1){printf("Not found\n");return;}
    char name[50]; int age; printf("Enter new name: "); while(getchar()!='\n');
    if(!fgets(name,sizeof(name),stdin)){printf("Read error\n");return;} name[strcspn(name,"\n")]=0;
    printf("Enter new age: "); if(scanf("%d",&age)!=1){while(getchar()!='\n');printf("Invalid input\n");return;}
    strncpy(db[idx].name,name,sizeof(db[idx].name)-1); db[idx].name[sizeof(db[idx].name)-1]=0; db[idx].age=age; printf("Updated\n");
}
void stats(void){
    printf("Total records: %d\n",db_count); if(db_count==0) return;
    int min=db[0].age,max=db[0].age; double sum=0;
    for(int i=0;i<db_count;i++){ if(db[i].age<min) min=db[i].age; if(db[i].age>max) max=db[i].age; sum+=db[i].age; }
    printf("Min:%d Max:%d Avg:%.2f\n",min,max,sum/db_count);
}
void search_name(void){
    char q[50]; printf("Enter name to search: "); while(getchar()!='\n');
    if(!fgets(q,sizeof(q),stdin)){printf("Read error\n");return;} q[strcspn(q,"\n")]=0;
    int found=0;
    for(int i=0;i<db_count;i++) if(strstr(db[i].name,q)){printf("ID:%d Name:%s Age:%d\n",db[i].id,db[i].name,db[i].age); found=1;}
    if(!found) printf("No match\n");
}
void sort_by_age(void){
    for(int i=0;i<db_count;i++) for(int j=i+1;j<db_count;j++) if(db[i].age>db[j].age){
        Item t=db[i]; db[i]=db[j]; db[j]=t;
    }
    printf("Sorted by age\n");
}
void save_db(void){
    FILE *f=fopen("db.txt","w"); if(!f){printf("Save error\n");return;}
    for(int i=0;i<db_count;i++) fprintf(f,"%d\t%s\t%d\n",db[i].id,db[i].name,db[i].age);
    fclose(f); printf("Saved to db.txt\n");
}
void load_db(void){
    FILE *f=fopen("db.txt","r"); if(!f){printf("No file\n");return;}
    db_count=0;
    while(db_count<MAX && !feof(f)){
        int id,age; char name[50];
        if(fscanf(f,"%d\t%49[^\t]\t%d\n",&id,name,&age)!=3) break;
        db[db_count].id=id; strncpy(db[db_count].name,name,sizeof(db[db_count].name)-1); db[db_count].name[sizeof(db[db_count].name)-1]=0;
        db[db_count].age=age; db_count++;
    }
    fclose(f); printf("Loaded %d records\n",db_count);
}
void clear_db(void){
    db_count=0; printf("Cleared all records\n");
}
int main(void){
    int choice=0; print_title(); load_db();
    while(1){
        printf("\n1.Add 2.List 3.Update 4.Delete 5.Stats 6.Search 7.Sort 8.Save 9.Clear 10.Exit\nChoose: ");
        if(scanf("%d",&choice)!=1){while(getchar()!='\n');printf("Invalid input\n"); continue;}
        if(choice==1) add_item();
        else if(choice==2) list_items();
        else if(choice==3) update_item();
        else if(choice==4) delete_item();
        else if(choice==5) stats();
        else if(choice==6) search_name();
        else if(choice==7) sort_by_age();
        else if(choice==8) save_db();
        else if(choice==9) clear_db();
        else if(choice==10){printf("Exiting\n"); save_db(); break;}
        else printf("Invalid choice\n");
    }
    return 0;
}