#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

struct phone
{
    int srl;
    char name[20];
    int p_no;
    int ex1;
    struct phone *next;

}*start=NULL,*point=NULL;



void extra();
void add();
void display();
void display_all();
void modify();
void delt();
void search();
char mygetch();


int main()
{
    int x;

    while(1)
    {
        system("cls");
        system("COLOR 70");

        printf("====================* Phonebook Database Management System *====================");
        printf("\n====================================* MENU *====================================\n\n");

        printf("1. Add new record\n\n");
        printf("2. Modify a record\n\n");
        printf("3. Delete a record\n\n");
        printf("4. Search contact by Name\n\n");
        printf("5. Display any record by serial no.\n\n");
        printf("6. Display All records\n\n");
        printf("0. Exit from the program\n\n");

        printf("================================================================================\n");

        printf("\nPlease Select any Option from Menu: ");
        scanf("%d",&x);

        switch(x)
        {
        case 1:
            add();
            break;

        case 2:
            modify();
            break;

        case 3:
            delt();
            break;

        case 4:
            search();
            break;

        case 5:
            display();
            break;

        case 6:
            display_all();
            break;

        case 0:
                getchar();
                printf("\n\n\t\t----------------------------------------------------------\n");
                printf("\t\tProject developed by Meherin Akter and Jannat Ul Nayeem\n");
                printf("\t\t----------------------------------------------------------\n\n");

                printf("Press any key to exit!....");

                getchar();

            exit(0);

            system("cls");
        }

        printf("\n\nPress Any Key to continue.....");

        mygetch();

    }


    return 0;
}


void add()
{
    struct phone *t1,*current;

    t1=(struct phone*)malloc(sizeof(struct phone));

    printf("\nEnter serial: ");
    scanf("%d",&t1->srl);
    printf("\nEnter User name: ");
    scanf("%s",t1->name);
    printf("\nEnter phone no.: ");
    scanf("%d",&t1->p_no);

    t1->ex1=0;


    jump:

    current=start;
    while(current!=NULL)
    {
        if(current->srl==t1->srl)
        {
         printf("\n\tAlready got the serial\n\tTry another one or to added another number on the same,\n\tuse 'Modify' option from menu!\n");
         printf("\n\nEnter a different serial: ");
         scanf("%d",&t1->srl);
         goto jump;
        }

    current=current->next;
    }

    t1->next=NULL;


    if(start==NULL)
    {
        start=t1;
        point=t1;
    }
    else
    {
        point->next=t1;
        point=t1;
    }

}

void modify()
{
    struct phone *t,*current;
    int sl,found=0,count=0,k;


    if(start==NULL)
    {
        printf("\n\tNo DATA inserted on the DataBase!\n");
        return ;
    }


    rpt:

    printf("\n\nDo you want to Add\\Edit an extra number?[press '1' for Yes/ '0' for No]: ");
    scanf("%d",&k);

    switch(k)
    {

    case 1:

    extra();
    goto ext;

    case 0:

    goto next;


    default:

    printf("\n\nWrong Input!\n");
    goto rpt;

    }


    next:


    printf("\n\nEnter the serial no. of the record you want to Modify: ");
    scanf("%d",&sl);


    t=start;
    while(t!=NULL)
    {
        if(t->srl==sl)
        {
            found=1;

            t->srl=sl;

            printf("\n\nEnter User Name: ");
            scanf("%s",t->name);
            printf("\nEnter phone no.: ");
            scanf("%d",&t->p_no);

            break;
        }

        t=t->next;

    }

    if(found==0)
    {
        printf("Sorry...No Record Found\n\n");
    }

    ext:

        return;

}


void delt()
{
    struct phone *t,*t1;
    int sl,found=0,count=0,pos=0,i=1;

    printf("\nEnter the Serial of the record you want to Delete: ");
    scanf("%d",&sl);


    if(start==NULL)
    {
        printf("\n\tNo DATA inserted on the DataBase!\n");
        return;
    }

    while(1)
    {
    t1=start;
    while(t1!=NULL)
    {
        count++;
        if(t1->srl==sl)
        {
            pos=count;
            found=1;
            break;
        }
        t1=t1->next;
    }

    if(found==0)
    {
        printf("\n\tDATA not FOUND!\n");
        break;
    }

    t=start;
    while(i<=pos-2)
    {
       t=t->next;
       i++;
    }

    if(start==t1)
    {
        start=t1->next;
    }

    else if(t1->next==NULL)
    {
        t->next=NULL;
    }

    else
    {
        t->next=t1->next;
    }

    printf("\n\tRecord Successfully Deleted!\n");
    break;

   }
}

void display()
{
    struct phone *t1;
    int sl,found=0;

    printf("\nEnter the serial no.: ");
    scanf("%d",&sl);

      if(start==NULL)
       {
        printf("\n\tNo DATA inserted on the DataBase!\n");
        return;
       }

    t1=start;
    while(t1!=NULL)
    {

        if(sl==t1->srl)
        {

            printf("\n================================================================================\n\n");
            printf("\t\t\t   User Details of serial [%d]\n\n",t1->srl);
            printf("================================================================================\n\n");

            printf("\t\t      Name\t\t       Phone\n\n");
            printf("\t\t     -------\t\t      -------\n\n");

            printf("\t\t     %s\t",t1->name);
            printf("\t    0%d\t\n",t1->p_no);

            if(t1->ex1!=0)
             {
               printf("\t\t\t\t\t    0%d\t\n",t1->ex1);
             }

            printf("\n================================================================================\n\n");

            found=1;
            break;

        }
        t1=t1->next;

    }
    if(found==0)
    {
        printf("\n\tSorry...No Record Found");
    }
}


void search()
{
    struct phone *t;
    int found=0;
    char name[20];

    printf("\nEnter the User Name: ");
    scanf("%s",&name);


    if(start==NULL)
    {
        printf("\n\tNo DATA inserted on the DataBase!\n");
        return;
    }

    t=start;
    while(t!=NULL)
    {

        if(strcmp(name,t->name)==0)
        {
            printf("\n================================================================================\n\n");
            printf("\t\t\t   User Details of serial [%d]\n\n",t->srl);
            printf("================================================================================\n\n");

            printf("\t\t      Name\t\t       Phone\n\n");
            printf("\t\t     -------\t\t      -------\n\n");

            printf("\t\t     %s\t",t->name);
            printf("\t    0%d\t\n",t->p_no);

            if(t->ex1!=0)
             {
               printf("\t\t\t\t\t    0%d\t\n",t->ex1);
             }

            printf("\n================================================================================\n\n");

            found=1;
        }
        t=t->next;
    }
    if(found==0)
    {
        printf("\nSorry...No Record Found");
    }
}


void display_all()
{
    struct phone *t;


    if(start==NULL)
    {
        printf("\n\tNo DATA inserted on the DataBase!\n");
        return;
    }


    printf("\n================================================================================\n\n");
    printf("\t\t\tAll User(s) Details\n\n");
    printf("================================================================================\n\n");

    printf(" serial\t    Name\t             Phone\n\n");
    printf(" -----\t    -----\t             -----\n\n");

    t=start;
    while(t!=NULL)
    {

        printf("  %d\t",t->srl);
        printf("    %s\t",t->name);
        printf("           0%d\t\n",t->p_no);

        if(t->ex1!=0)
        {
        printf("\t\t\t\t   0%d\t\n\n",t->ex1);
        }

        else
        {
            printf("\n");
        }

        t=t->next;
    }
    printf("================================================================================\n\n");

}


void extra()
{

    struct phone *t1;
    int found=0;
    char nme[20];


    if(start==NULL)
    {
        printf("\n\tNo DATA inserted on the DataBase!\n");
        return;
    }


    printf("\nEnter the User Name: ");
    scanf("%s",&nme);


    t1=start;
    while(t1!=NULL)
    {

        if(strcmp(nme,t1->name)==0)
        {
            printf("\nEnter extra phone no.: ");
            scanf("%d",&t1->ex1);

            printf("\n================================================================================\n\n");
            printf("\t\t\t\tUser Details of serial [%d]\n\n",t1->srl);
            printf("================================================================================\n\n");

            printf("   Name\t\t    Phone\n\n");
            printf("  -------\t   -------\n\n");

            printf("   %s\t",t1->name);
            printf("  0%d\t\n",t1->p_no);
            printf("\t\t  0%d\t\n\n",t1->ex1);

            printf("================================================================================\n\n");

            found=1;
        }

        t1 = t1->next;
    }

    if(found==0)
    {
        printf("\nSorry...No Record Found");
    }

    return;

}



char mygetch()
{
    char val;
    char rel;

    scanf("%c",&val);
    scanf("%c",&rel);
    return (val);
}

