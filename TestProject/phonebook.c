
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
typedef struct
{
    char day[8];
    char month[8];
    char year[16];
} date;
typedef struct
{
    char name1[85];
    char name2[85];
    date d;
    char address[100];
    char city[90];
    char number[15];
} info;
info x[100];
info y[100];
int count (char str[])
{
    int n=0;
    FILE*f;
    f=fopen(str,"r");
    while(!feof(f))
    {
        char c=fgetc(f);
        if(c=='\n')
            n++;

    }
    fclose(f);
    return n+1;

}
int len,leny;
void Switch(int n)
{
    int ch;
    printf("Please choose the field of modification :\n1-First name\n2-Last name\n3-Address\n4-Email\n5-Number\n6-Date\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("Please enter the needed modification:\t");
        scanf("%s",x[n].name1);
        while(valided(x[n].name1)!=0)
        {
            printf("You have entered an invalid Name\nPlease re-enter a valid Name!\n");
            scanf("%s,",x[n].name1);
        }
        break;
    case 2:
        printf("Please enter the needed modification:\t");
        scanf("%s",x[n].name2);
        while(valided(x[n].name2)!=0)
        {
            printf("You have entered an invalid Name\nPlease re-enter a valid Name!\n");
            scanf("%s,",x[n].name2);
        }
        break;
    case 3:
        printf("Please enter the needed modification:\t");
        scanf(" %[^\t\n]s",x[n].address);
        break;
    case 4:
        printf("Please enter the needed modification:\t");
        scanf("%s",x[n].city);
        while(validedx(x[n].city)==0)

        {
            printf("You have entered an invalid email\nplease re-enter a valid email!\n");
            scanf("%s",x[n].city);
        }
        break;
    case 5:
        printf("Please enter the needed modification:\t");
        scanf("%s",x[n].number);
        while(validedz(x[n].number)!=0)
        {
            printf("You have entered an invalid value for a phone number\nplease re-enter a valid number!\n");
            scanf("%s",x[n].number);
        }
        break;
    case 6:
        printf("Please enter the needed modification:\t");
        printf("\nPlease enter the day\n");
        scanf("%s",x[n].d.day);
        while((atoi(x[n].d.day)>31||atoi(x[n].d.day)<0)||validedz(x[n].d.day)!=0)
        {
            printf("You have entered an invalid value for a day\nplease re-enter a valid day value!\n");
            scanf("%s",x[n].d.day);
        }
        printf("Please enter the month:\n");
        scanf("%s",x[n].d.month);
        while((atoi(x[n].d.month)>12||atoi(x[n].d.month)<0)||validedz(x[n].d.month)!=0)
        {
            printf("You have entered an invalid value for a month\nplease re-enter a valid month value!\n");
            scanf("%s",x[n].d.month);
        }
        printf("Please enter the year:\n");
        scanf("%s",x[n].d.year);
        while((atoi(x[n].d.year)>2018||atoi(x[n].d.year)<0)||validedz(x[n].d.year)!=0)
        {
            printf("You have entered an invalid value for a year\nplease re-enter a valid year value!\n");
            scanf("%s",x[n].d.year);
        }

    }

}
int valided(char a[])
{
    int k=0;
    int flag=0;
    int n=1;
    while(a[k]!='\0')
    {
        if(!isdigit(a[k])&&!isalpha(a[k]))
            n=0;
        if(isdigit(a[k]))
            flag=1;
        k++;
    }
    if(flag==1||n==0)
        return 1;
    else
        return 0;
}
int validedx(char a[])
{
    int flag=0;
    int k=0;
    int j=0;
    int count=0;
    int m=0;
    int x;
    int n=0;
    int z=0;
    int countx=0;
    int q;
    while(a[k]!='\0')
    {
        if(a[0]=='.')
            n=1;
              if(a[k]=='@')
            {
                count++;
                x=k;
                q=k;
            }
            if(a[k]=='.'){
                z=1;
            }

        if(!isdigit(a[k])&&!isalpha(a[k])&&a[k]!='_'&&a[k]!='@'&&a[k]!='.')
            flag=1;
        k++;
    }
    while(a[x]!='\0'){
        if(a[x]=='.')
        countx++;
        x++;
    }

    if(k-q>5)
    {
        m=1;
    }
    if(x<=2)
        n=1;
    if(count==1&&flag==0&&m==1&&n==0&&z==1&&countx==1)
    {
        return 1;
    }
    else
        return 0;

}
int validedz(char a[])
{

    int k=0;
    int flag=0;
    int n=1;
    while(a[k]!='\0')
    {
        if(!isdigit(a[k])&&!isalpha(a[k]))
            n=0;
        if(isalpha(a[k]))
            flag=1;
        k++;
    }
    if(flag==1||n==0)
        return 1;
    else
        return 0;
}
void clean()
{
    int c, d;
    for (c=1; c<1000; c++)
        for (d=1; d<1000; d++)
        {}
    system("@cls||clear");
}
void load(char str[])
{
    int i=0;
    FILE*f;
    f=fopen(str,"r");
    while(1)
    {
        fscanf(f,"\n%[^,],",x[i].name1);
        fscanf(f,"%[^,],",x[i].name2);
        fscanf(f,"%[^-]-",x[i].d.day);
        fscanf(f,"%[^-]-",x[i].d.month);
        fscanf(f,"%[^,],",x[i].d.year);
        fscanf(f,"%[^,],",x[i].address);
        fscanf(f,"%[^,],",x[i].city);
        fscanf(f,"%[^\n]\n",x[i].number);
        i++;
        if(feof(f))
            break;
    }
    len=count(str);
    int k=0;
    for(k; k<leny; k++)
        y[k]=x[k];
    leny=len;
}
void save(char str[])
{
    FILE*f;
    f=fopen(str,"w");
    int i;
    for(i=0; i<len; i++)
    {
        fprintf(f,"%s,",x[i].name1);
        fprintf(f,"%s,",x[i].name2);
        fprintf(f,"%d-",atoi(x[i].d.day));
        fprintf(f,"%d-",atoi(x[i].d.month));
        fprintf(f,"%d,",atoi(x[i].d.year));
        fprintf(f,"%s,",x[i].address);
        fprintf(f,"%s,",x[i].city);
        fprintf(f,"%s\n",x[i].number);

    }
    fclose(f);
    printf("\n\nData saved successfully!\n");
}
void search()
{
    info z[100];
    char name[85];
    char choice[50];
    int i=0,j=0,k=0;
    int flag=0;
    //load(str);
    printf("Enter the searching parameter\n1-First name\n2-Last Name\n3-Number\n4-Email\n5-Address\n6-Birth date\n");
    scanf("%s",&choice);
    clean();
    if(atoi(choice)==2)
    {
        printf("Enter the last name\t");
        scanf("%s",name);

        while(i<len)
        {
            if(strcasecmp(name,x[i].name2)==0)
            {
                printf("\nContact %d\n",i+1);
                printf("First Name:%s\n",x[i].name1);
                printf("Second Name:%s\n",x[i].name2);
                printf("Birth Date:%s-",x[i].d.day);
                printf("%s-",x[i].d.month);
                printf("%s\n",x[i].d.year);
                printf("Address:%s\n",x[i].address);
                printf("Email:%s\n",x[i].city);
                printf("Number:%s\n\n\n",x[i].number);
                flag++;
                z[j]=x[i];
                j++;
            }
            i++;
        }
        if(flag==0)
        {
            printf("Contact doesn't exist!\ntry again?!\n");
            char tr[50];
            scanf("%s",tr);
            if(strcasecmp(tr,"yes")==0)
            {
                clean();
                search();
            }
        }
        for(k; k<len; k++)
            x[k]=z[k];
        printf("search with another parameter?!");
        char ans[50];
        scanf("%s",ans);
        if(strcasecmp(ans,"yes")==0)
        {
            clean();
            search();
        }


    }
    else if(atoi(choice)==1)
    {
        printf("Enter the first name\t");
        scanf("%s",name);
        while(i<len)
        {
            if(strcasecmp(name,x[i].name1)==0)
            {
                printf("Contact %d\n",i+1);
                printf("First Name:%s\n",x[i].name1);
                printf("Second Name:%s\n",x[i].name2);
                printf("Birth Date:%s-",x[i].d.day);
                printf("%s-",x[i].d.month);
                printf("%s\n",x[i].d.year);
                printf("Address:%s\n",x[i].address);
                printf("Email:%s\n",x[i].city);
                printf("Number:%s\n\n\n",x[i].number);
                flag++;
                z[j]=x[i];
                j++;
            }
            i++;

        }
        if(flag==0)
        {
            printf("Contact doesn't exist!\ntry again?!\n");
            char tr[50];
            scanf("%s",tr);
            if(strcasecmp(tr,"yes")==0)
            {
                clean();
                search();
            }
        }
        for(k; k<len; k++)
            x[k]=z[k];
        printf("search with another parameter?!");
        char ans[50];
        scanf("%s",ans);
        if(strcasecmp(ans,"yes")==0)
        {
            clean();
            search();

        }

    }
    else if(atoi(choice)==4)
    {
        printf("Enter the Email\t");
        scanf("%s",name);
        while(i<len)
        {
            if(strcasecmp(name,x[i].city)==0)
            {
                printf("Contact %d\n",i+1);
                printf("First Name:%s\n",x[i].name1);
                printf("Second Name:%s\n",x[i].name2);
                printf("Birth Date:%s-",x[i].d.day);
                printf("%s-",x[i].d.month);
                printf("%s\n",x[i].d.year);
                printf("Address:%s\n",x[i].address);
                printf("Email:%s\n",x[i].city);
                printf("Number:%s\n\n\n",x[i].number);

                flag++;
                z[j]=x[i];
                j++;
            }
            i++;
        }
        if(flag==0)
        {
            printf("Contact doesn't exist!\ntry again?!\n");
            char tr[50];
            scanf("%s",tr);
            if(strcasecmp(tr,"yes")==0)
            {
                clean();
                search();
            }
        }
        for(k; k<len; k++)
            x[k]=z[k];
        printf("search with another parameter?!");
        char ans[50];
        scanf("%s",ans);
        if(strcasecmp(ans,"yes")==0)
        {
            clean();
            search();

        }

    }
    else if(atoi(choice)==5)
    {
        printf("Enter the address\t");
        scanf(" %[^\t\n]s",name);
        while(i<len)
        {
            if(strcasecmp(name,x[i].address)==0)
            {
                printf("Contact %d\n",i+1);
                printf("First Name:%s\n",x[i].name1);
                printf("Second Name:%s\n",x[i].name2);
                printf("Birth Date:%s-",x[i].d.day);
                printf("%s-",x[i].d.month);
                printf("%s\n",x[i].d.year);
                printf("Address:%s\n",x[i].address);
                printf("Email:%s\n",x[i].city);
                printf("Number:%s\n\n\n",x[i].number);
                flag++;
                z[j]=x[i];
                j++;
            }
            i++;
        }
        if(flag==0)
        {
            printf("Contact doesn't exist!\ntry again?!\n");
            char tr[50];
            scanf("%s",tr);
            if(strcasecmp(tr,"yes")==0)
            {
                clean();
                search();
            }
        }
        for(k; k<len; k++)
            x[k]=z[k];
        printf("search with another parameter?!");
        char ans[50];
        scanf("%s",ans);
        if(strcasecmp(ans,"yes")==0)
        {
            clean();

            search();
        }

    }
    else if(atoi(choice)==3)
    {
        printf("Enter the number\t");
        scanf("%s",name);
        while(i<len)
        {
            if(strcasecmp(name,x[i].number)==0)
            {
                printf("Contact %d\n",i+1);
                printf("First Name:%s\n",x[i].name1);
                printf("Second Name:%s\n",x[i].name2);
                printf("Birth Date:%s-",x[i].d.day);
                printf("%s-",x[i].d.month);
                printf("%s\n",x[i].d.year);
                printf("Address:%s\n",x[i].address);
                printf("Email:%s\n",x[i].city);
                printf("Number:%s\n\n\n",x[i].number);
                flag++;
                z[j]=x[i];
                j++;
            }
            i++;
        }
        if(flag==0)
        {
            printf("Contact doesn't exist!\ntry again?!\n");
            char tr[50];
            scanf("%s",tr);
            if(strcasecmp(tr,"yes")==0)
            {
                clean();
                search();
            }
        }
        for(k; k<len; k++)
            x[k]=z[k];
        printf("search with another parameter?!");
        char ans[50];
        scanf("%s",ans);
        if(strcasecmp(ans,"yes")==0)
        {
            clean();
            search();

        }

    }

    else if(atoi(choice)==6)
    {
        printf("Enter the birth date\t");
        //gets(name);
        date v;
        scanf("%s%s%s",v.day,v.month,v.year);

        while(i<len)
        {
            if(strcmp(v.day,x[i].d.day)==0&&strcmp(v.month,x[i].d.month)==0&&strcmp(v.year,x[i].d.year)==0)
            {

                printf("Contact %d\n",i+1);
                printf("First Name:%s\n",x[i].name1);
                printf("Second Name:%s\n",x[i].name2);
                printf("Birth Date:%s-",x[i].d.day);
                printf("%s-",x[i].d.month);
                printf("%s\n",x[i].d.year);
                printf("Address:%s\n",x[i].address);
                printf("Email:%s\n",x[i].city);
                printf("Number:%s\n\n\n",x[i].number);
                flag++;
                z[j]=x[i];
                j++;

            }
            i++;
        }
        if(flag==0)
        {
            printf("Contact doesn't exist!\ntry again?!\n");
            char tr[50];
            scanf("%s",tr);
            if(strcasecmp(tr,"yes")==0)
            {
                clean();
                search();
            }
        }
        for(k; k<len; k++)
            x[k]=z[k];
        printf("search with another parameter?!");
        char ans[50];
        scanf("%s",ans);
        if(strcasecmp(ans,"yes")==0)
        {
            clean();
            search();

        }

    }
else {printf("\nInvalid choice..Enter valid one\n");
    search();
}


}
void sort()
{
    int i,j,k=0;
    //load(str);
    //info y[count(str)];
    info temp;
    //strcpy(x[0].name2,y[0].name2);
    printf("Enter the type of sorting:\n1-Default sorting\n2-Birth date sorting \n");
    char choice[50] ;
    scanf("%s",&choice);
    if(atoi(choice)==1)
    {

        for(i=0; i<len; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcasecmp(x[i].name2,x[j].name2)>0)
                {
                    temp=x[i];
                    x[i]=x[j];
                    x[j]=temp;
                }
                else if(strcasecmp(x[i].name2,x[j].name2)==0)
                {
                    if(strcasecmp(x[i].name1,x[j].name1)>0)
                    {
                        temp=x[i];
                        x[i]=x[j];
                        x[j]=temp;
                    }
                    else if(strcasecmp(x[i].name1,x[j].name1)==0)
                    {
                        if(atoi(x[i].number)>atoi(x[j].number))
                        {
                            temp=x[i];
                            x[i]=x[j];
                            x[j]=temp;
                        }

                    }
                }
            }
        }
    printf("\n\nContacts sorted!\n\n");

    while(k<len)
    {
        printf("Contact %d\n",k+1);
        printf("First Name:%s\n",x[k].name1);
        printf("Second Name:%s\n",x[k].name2);
        printf("Birth Date:%s-",x[k].d.day);
        printf("%s-",x[k].d.month);
        printf("%s\n",x[k].d.year);
        printf("Address:%s\n",x[k].address);
        printf("Email:%s\n",x[k].city);
        printf("Number:%s\n\n\n",x[k].number);
        k++;

    }


    }
    else if (atoi(choice)==2)
    {
        //int temp;
        for(i=0; i<len; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(atoi(x[i].d.year)>atoi(x[j].d.year))
                {
                    temp=x[i];
                    x[i]=x[j];
                    x[j]=temp;
                }
                else if(atoi(x[i].d.year)==atoi(x[j].d.year))
                {
                    if(atoi(x[i].d.month)>atoi(x[j].d.month))
                    {
                        temp=x[i];
                        x[i]=x[j];
                        x[j]=temp;
                    }
                    else if(atoi(x[i].d.month)==atoi(x[j].d.month))
                    {
                        if(atoi(x[i].d.day)>atoi(x[j].d.day))
                        {
                            temp=x[i];
                            x[i]=x[j];
                            x[j]=temp;
                        }
                    }
                }

            }
        }
   printf("\n\nContacts sorted!\n\n");

    while(k<len)
    {
        printf("Contact %d\n",k+1);
        printf("First Name:%s\n",x[k].name1);
        printf("Second Name:%s\n",x[k].name2);
        printf("Birth Date:%s-",x[k].d.day);
        printf("%s-",x[k].d.month);
        printf("%s\n",x[k].d.year);
        printf("Address:%s\n",x[k].address);
        printf("Email:%s\n",x[k].city);
        printf("Number:%s\n\n\n",x[k].number);
        k++;

    }


    }
    else {printf("\nInvalid choice\n");

    }

//save(str);

}

void Delete()
{
    printf("Please enter the first and last name\n");
    char name1[85];
    char name2[80];
    scanf(" %[^\t\n]s",name1);
    scanf(" %[^\t\n]s",name2);
    int k=0,j=0,count=0;
    //readFile("koko.txt");
    //  FILE*f=fopen(str,"w");
    for(k; k<len; k++)
    {
        if(strcasecmp(name1,x[k].name1)==0&&strcasecmp(name2,x[k].name2)==0)
        {
            count++;
            continue;
        }
        x[j]=x[k];

        j++;
    }
    if(count==0)
    {
        printf("Contact doesn't exist!\ntry again?!\n");
        char tr[50];
        scanf("%s",tr);
        if(strcasecmp(tr,"yes")==0)
        {
            clean();
            Delete();
        }
    }
    else
    {
        len--;
        char a[20];
        printf("Do you want to delete another contact?\nenter yes or no\n");
        scanf("%s",a);
        if(strcasecmp(a,"yes")==0)
        {
            //fclose(f);
            Delete();
        }
        else
        {
            printf("\nContact deleted!\n");
        }
        //readFile("koko.str");

    }
}

void Modify()
{
    char name2[80];
    char name1[80];
    printf("Enter the last name:\n");
    scanf("%s",name2);
    while(valided(name2)!=0)
    {
        printf("You have entered an invalid Name\nPlease re-enter a valid Name!\n");
        scanf("%s,",name2);
    }
    int k=0;
    int count=0;
    int ch;
    int j;
    int n,v;
    for(k; k<len; k++)
    {
        if(strcasecmp(name2,x[k].name2)==0)
        {
            printf("%s  ",x[k].name1);
            printf("%s  ",x[k].name2);
            printf("%s-",x[k].d.day);
            printf("%s-",x[k].d.month);
            printf("%s  ",x[k].d.year);
            printf("%s  ",x[k].address);
            printf("%s  ",x[k].city);
            printf("%s  \n",x[k].number);
            count++;
            if(count==1)
                n=k;
        }
    }

    if(count==0)
    {
        printf("Contact doesn't exist!\ntry again?!\n");
        char tr[50];
        scanf("%s",tr);
        if(strcasecmp(tr,"yes")==0)
        {
            clean();
            Modify();
        }
    }

    if(count>1)
    {
        int flag=0,flag2=0;
        printf("Please enter the first name:\n");
        scanf("%s",name1);
        while(valided(name1)!=0)
        {
            printf("You have entered an invalid Name\nPlease re-enter a valid Name!\n");
            scanf("%s,",name1);
        }
        for(j=0; j<len; j++)
        {
            if((strcasecmp(name1,x[j].name1))==0&&strcasecmp(name2,x[j].name2)==0)
            {
                v=j;
                flag++;
                //Switch(j);

                //break;
            }

        }

        if(flag==1)
        {
            Switch(v);
            printf("Modify another field?!\n");
            char ans[50];
            scanf("%s",ans);
            while(strcasecmp(ans,"yes")==0)
            {

                Switch(v);
                printf("modify another field?!\n");
                scanf("%s",ans);

            }
        }
        if(flag>1)
        {
            printf("Enter the phone number!");
            char num[50];
            scanf("%s",num);
            while(validedz(num)!=0)
            {
                printf("You have entered an invalid value for a phone number\nplease re-enter a valid number!\n");
                scanf("%s",num);
            }
            for(j=0; j<len; j++)
            {
                if(((strcmp(name1,x[j].name1))==0&&strcmp(name2,x[j].name2)==0)&&strcasecmp(x[j].number,num)==0)
                {
                    flag2++;
                    Switch(j);

                    break;
                }

            }
        }
        if(flag2==0&&flag==0)
        {
            printf("Contact doesn't exist!\ntry again?!\n");
            char tr[50];
            scanf("%s",tr);
            if(strcasecmp(tr,"yes")==0)
            {
                clean();
                Modify();
            }
        }
        if(flag!=1)
        {
            printf("Modify another field?!\n");
            char ans[50];
            scanf("%s",ans);
            while(strcasecmp(ans,"yes")==0)
            {

                Switch(j);
                printf("modify another field?!\n");
                scanf("%s",ans);

            }
        }
    }
    if(count==1)
    {
        Switch(n);
        printf("Modify another field?!\n");
        char ans[50];
        scanf("%s",ans);
        while(strcasecmp(ans,"yes")==0)
        {

            Switch(n);
            printf("modify another field?!\n");
            scanf("%s",ans);

        }
    }

}
void Add()
{

    int k=0;


    printf("Enter the first name: ");
    scanf("%s,",x[len].name1);
    while(valided(x[len].name1)!=0)
    {
        printf("You have entered an invalid Name\nPlease re-enter a valid Name!\n");
        scanf("%s,",x[len].name1);
    }
    printf("Enter the last name: ");
    scanf("%s,",x[len].name2);
    while(valided(x[len].name2)!=0)
    {
        printf("You have entered an invalid Name\nPlease re-enter a valid Name!\n");
        scanf("%s,",x[len].name2);
    }
    printf("Enter the birth day :");
    scanf("%s",x[len].d.day);
    while((atoi(x[len].d.day)>31||atoi(x[len].d.day)<=0)||validedz(x[len].d.day)!=0)
    {
        printf("You have entered an invalid value for a day\nplease re-enter a valid day value!\n");
        scanf("%s",x[len].d.day);
    }

    printf("Enter the birth month: ");
    scanf("%s",x[len].d.month);
    while((atoi(x[len].d.month)>12||atoi(x[len].d.month)<=0)||validedz(x[len].d.month)!=0)
    {
        printf("You have entered an invalid value for a month\nplease re-enter a valid month value!\n");
        scanf("%s",x[len].d.month);
    }

    printf("Enter the birth year: ");
    scanf("%s",x[len].d.year);
    while((atoi(x[len].d.year)>2018||atoi(x[len].d.year)<0)||validedz(x[len].d.year)!=0)
    {
        printf("You have entered an invalid value for a year\nplease re-enter a valid year value!\n");
        scanf("%s",x[len].d.year);
    }
    printf("Enter the address: ");
    scanf(" %[^\t\n]s",x[len].address);
    printf("Enter the email: ");
    scanf("%s",x[len].city);
    while(validedx(x[len].city)==0)

    {
        printf("You have entered an invalid email\nplease re-enter a valid email!\n");
        scanf("%s",x[len].city);
    }
    printf("Enter the number: ");
    scanf("%s",x[len].number);
    while(validedz(x[len].number)!=0)
    {
        printf("You have entered an invalid value for a phone number\nplease re-enter a valid number!\n");
        scanf("%s",x[len].number);
    }

    printf("Do you want to enter another contact?\nenter yes or no\n");
    char a[20];
    scanf("%s",a);
    len++;
    if(strcmp(a,"yes")==0)
    {
        Add();
    }
    else
        printf("\nYou have Added a new contact!\n");

}
void menu(char str[],int n)
{
    char ret[50],sa[50];
    char choice[50],i,flag=n;
    if(flag==0)
    {
        load(str);
    }
    printf("Enter your choice:\n_________________\n1-Add\t\t2-Delete\n3-search\t4-sort\n5-modify\t6-save\n7-Quit\n");
    scanf("%s",choice);

    clean();
    switch(atoi(choice))
    {
    case 1:
    {
        Add();
        printf("\nReturn to main menu?!\t");
        scanf("%s",ret);

        if(strcasecmp(ret,"yes")==0)
        {
            printf("\nDo you want to save changes?\t");
            scanf("%s",sa);
            if(strcasecmp(sa,"yes")==0)
            {
                save(str);
                clean();
                menu(str,0);
                break;
            }
            else
            {
                clean();
                menu(str,1);
                break;
            }
        }
        else
        {
            printf("\nDo you want to save changes?\t");
            scanf("%s",sa);
            if(strcasecmp(sa,"yes")==0)
            {
                save(str);
            }
            else
                exit(0);
        }

    }
    break;
    case 2:
    {
        Delete();
        printf("\nReturn to main menu?!\t");
        scanf("%s",ret);

        if(strcasecmp(ret,"yes")==0)
        {
            printf("\nDo you want to save changes?\t");
            scanf("%s",sa);
            if(strcasecmp(sa,"yes")==0)
            {
                save(str);
                clean();
                menu(str,0);
                break;
            }
            else
            {

                clean();
                menu(str,1);
                break;
            }
        }
        else
        {
            printf("\nDo you want to save changes?\t");
            scanf("%s",sa);
            if(strcasecmp(sa,"yes")==0)
            {
                save(str);
            }
            else
                exit(0);
        }

    }
    break;
    case 3:
    {
        search();
        printf("\nReturn to main menu?!\t");
        scanf("%s",ret);

        if(strcasecmp(ret,"yes")==0)
        {

            clean();
            menu(str,0);
            break;
        }


    }
    break;
    case 4:
    {
        sort();
        printf("\nReturn to main menu?!\t");
        scanf("%s",ret);

        if(strcasecmp(ret,"yes")==0)
        {
            printf("\nDo you want to save changes?\t");
            scanf("%s",sa);
            if(strcasecmp(sa,"yes")==0)
            {
                save(str);
                clean();
                menu(str,0);
                break;
            }
            else
            {
                clean();
                menu(str,1);
                break;
            }
        }
        else
        {
            printf("\nDo you want to save changes?\t");
            scanf("%s",sa);
            if(strcasecmp(sa,"yes")==0)
            {
                save(str);
            }
            else
                exit(0);
        }

    }
    break;
    case 5:
    {
        Modify();
        printf("\nReturn to main menu?!\t");
        scanf("%s",ret);

        if(strcasecmp(ret,"yes")==0)
        {
            printf("\nDo you want to save changes?\t");
            scanf("%s",sa);
            if(strcasecmp(sa,"yes")==0)
            {
                save(str);
                clean();
                menu(str,0);
                break;
            }
            else
            {
                clean();
                menu(str,1);
                break;
            }
        }
        else
        {
            printf("\nDo you want to save changes?\t");
            scanf("%s",sa);
            if(strcasecmp(sa,"yes")==0)
            {
                save(str);
            }
            else
                exit(0);
        }

    }
    break;
    case 6:
    {
        printf("\nDo you want to save changes?\t");
        scanf("%s",sa);
        if(strcasecmp(sa,"yes")==0)
        {
            save(str);
        }

        printf("\nReturn to main menu?!\t");
        scanf("%s",ret);

        if(strcasecmp(ret,"yes")==0)
        {
            clean();
            menu(str,0);
            break;
        }
        else
            exit(0);
    }


    break;

    case 7:
    {
        if(flag==1)
        {
            printf("\n\nAre you sure you want to exit without saving?!!\n\n");
            char ex[50];
            scanf("%s",ex);
            if(strcasecmp(ex,"no")==0)
            {
                save(str);
                exit(0);
            }
        }
        else

            exit(0);
    }
    break;


    default:printf("invalid choice!!..Try again\n");
        menu(str,0);
        break;
    }

}


