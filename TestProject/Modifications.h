
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
