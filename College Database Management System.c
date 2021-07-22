/*================COLLEGE RECORD MANAGEMENT SYSTEM===============
MINI PROJECT CREATED BY MADHAV CHANDOK
UNIVERSITY ROLL NO: 1902160130023
BRANCH: INFORMATION TECHNOLOGY 2ND YEAR 3RD SEMESTER
COLLEGE: IIMT COLLEGE OF ENGINEERING, GREATER NOIDA-201310
UNIVERSITY: ABDUL KALAM TECHNICAL UNIVERSITY (AKTU),LUCKNOW-226031
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//~~~~~~~~~~~~~~~~DECLARATION OF STRUCTURE USED~~~~~~~~~~~~~~~

struct authentication
{
    char username[20];
    char password[10];
};

struct stud
{
    char name[50];
    char f_name[50];
    char roll[50];
    char address[500];
    char contact[20];
    char branch_year[50];
    float sgpa[9];
    float cgpa;
};

struct faculty
{
    char name[50];
    char f_name[50];
    char id[50];
    char address[500];
    char contact[20];
    char branch[50];
} ;

//~~~~~~~~~~~~~~~~DECLARATION OF FUNCTION USED~~~~~~~~~~~~~~~

void printHead();
void printChar(char ch,int n);
void printLast();
void pass(FILE *pas);
int login(FILE *pas);
void add(FILE *fp1, FILE *fp2);
FILE *delstud(FILE *fp);
FILE *delfacul(FILE *fp);
void modifystud(FILE *fp);
void modifyfacul(FILE *fp);
void displayListstud(FILE *fp);
void displayListfacul(FILE *fp);
void searchRecordstud(FILE *fp);
void searchRecordfacul(FILE *fp);
void update_user_pass(FILE *pas);
FILE *deletepass(FILE *pas);
void loading_screen();
void information();
void thanks();

//~~~~~~~~~~~~~~~~FUNCTION THAT WILL PRINT COLLEGE NAME~~~~~~~~~~~~~~~

void printHead()
{
    printf("\e[01;97m");
    printChar('\xdb',120);
    printf("\n");
    printChar('=',120);
    printf("\n\t\t\t\t\t  [COLLEGE DATABASE MANAGEMENT SYSTEM]");
    printf("\n\n\t\t\t\t        IIMT COLLEGE OF ENGINEERING, GREATER NOIDA");
    printf("\n");
    printChar('=',120);
    printf("\n");
    printChar('\xdb',120);
    printf("\033[0m");
}

void printChar(char ch,int n)
{
    while(n--)
    {
        printf("%c",ch);
    }
}

void printLast()
{
    printf("\e[1;97m");
    printf("\n\n");
    printChar('=',120);
    printf("\n");
    printChar('\xdb',120);
    printf("\n");
    printChar('=',120);
    printf("\033[0m");
}

//~~~~~~~~~~~~~~~~FUNCTION THAT WILL ADD NEW USERNAME AND PASSWORD TO DATABASE~~~~~~~~~~~~~~~

void pass(FILE *pas)
{

    system("cls");
    printHead();

    struct authentication log;

    fseek(pas,0,SEEK_END);
    printf("\033[01;36m");
    printf("\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~ USERNAME AND PASSWORD ENTRY MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\033[01;33m");
    printf("\n\n\n\t\t\t Enter Username: ");
    scanf("%s",log.username);
    printf("\n\t\t\t Enter Password: ");
    scanf("%s",log.password);
    printf("\033[1;32m");
    printf("\n\n\n\t\t\t SUCCESS! YOUR USERNAME AND PASSWORD SUCCESSFULLY REGISTERED");
    printf("\033[0m");
    printf("\n\n\t\t\t Press any key to continue....");
    printLast();
    getch();
    fwrite(&log,sizeof(log),1,pas);
    fflush(stdin);
    fclose(pas);
}

//~~~~~~~~~~~~~~~~MULTI USER LOGIN SYSTEM FUNCTION~~~~~~~~~~~~~~~

int login(FILE *pas)
{
    struct authentication log;
    int x=0;
    char user[20];
    char pass[10];

    while(x!=3)
    {
        system("cls");
        printHead();

        printf("\e[01;36m");
        printf("\n\n\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n\t\t\t\t                      Login Page");
        printf("\n\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\033[01;33m");
        printf("\n\n\n\t\t\t\t Enter your username: ");
        scanf("%s",&user);
        printf("\n\t\t\t\t Enter your password: ");
        scanf("%s",&pass);
        printf("\033[0m");

        rewind(pas);
        while(fread(&log,sizeof(log),1,pas)==1)
        {
            if(strcmp(user,log.username)==0 && strcmp(pass,log.password)==0)
            {
                printf("\033[1;32m");
                printf("\n\n\n\t\t\t\t LOGIN SUCCESSFUL!....");
                printf("\033[0m");
                printf("\n\n\t\t\t\t Press any key to continue....");
                printf("\e[1;97m");
                printf("\n\n\n\n");
                printChar('=',120);
                printf("\n");
                printChar('\xdb',120);
                printf("\n");
                printChar('=',120);
                printf("\033[0m");
                getch();
                fclose(pas);
                return 1;
            }
        }
        if(strcmp(user,log.username)!=0 || strcmp(pass,log.password)!=0)
        {
            printf("\033[1;31m");
            printf("\n\n\n\t\t\t\t LOGIN UNSUCCESSFUL!....TRY AGAIN....");
            printf("\033[0m");
            x++;
        }
        printf("\n\n\t\t\t\t Press any key to continue....");
        printf("\e[1;97m");
        printf("\n\n\n\n");
        printChar('=',120);
        printf("\n");
        printChar('\xdb',120);
        printf("\n");
        printChar('=',120);
        printf("\033[0m");
        getch();
        if(x==3)
            fclose(pas);
    }
}

//~~~~~~~~~~~~~~~~FUNCTION THAT WILL ADD STUDENT AND FACULTY MEMBER INFORMATION TO DATABASE~~~~~~~~~~~~~~~

void add(FILE *fp1, FILE *fp2)
{
    int flag=1;
    while(flag==1)
    {
        struct stud s;
        struct faculty f;
        char x;
        char a='Y';

        system("cls");
        printHead();
        printf("\033[01;36m");
        printf("\n\n\n\t\t\t\t~~~~~~~~~~~~~~~ RECORD ENTRY MENU ~~~~~~~~~~~~~~~");
        printf("\033[01;33m");
        printf("\n\n\n\n\n\t\t\t\t PRESS[1]--------> ADD STUDENT RECORD");
        printf("\n\n\t\t\t\t PRESS[2]--------> ADD FACULTY MEMBER RECORD");
        printf("\n\n\t\t\t\t PRESS[3]--------> RETURN TO MAIN MENU");
        printf("\033[1;32m");
        printf("\n\n\n\n\n\t\t\t\t ENTER YOUR OPTION: ");
        scanf("%d",&x);
        printf("\033[0m");

        switch(x)
        {
            case 1:while(a=='Y' || a=='y')
                    {
                        system("cls");
                        printHead();
                        fseek(fp1,0,SEEK_END);
                        printf("\033[01;36m");
                        printf("\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~ ENTER INFORMATION OF STUDENT ~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                        printf("\033[01;33m");
                        printf("\n\n\n\t\t\t Enter Full Name: ");
                        fflush(stdin);
                        fgets(s.name,50,stdin);
                        s.name[strlen(s.name)-1]='\0';

                        printf("\n\t\t\t Enter Father's Name: ");
                        fflush(stdin);
                        fgets(s.f_name,50,stdin);
                        s.f_name[strlen(s.f_name)-1]='\0';

                        printf("\n\t\t\t Enter University Roll Number: ");
                        fflush(stdin);
                        fgets(s.roll,50,stdin);
                        s.roll[strlen(s.roll)-1]='\0';

                        printf("\n\t\t\t Enter Address: ");
                        fflush(stdin);
                        fgets(s.address,500,stdin);
                        s.address[strlen(s.address)-1]='\0';

                        printf("\n\t\t\t Enter Contact: ");
                        fflush(stdin);
                        fgets(s.contact,20,stdin);
                        s.contact[strlen(s.contact)-1]='\0';

                        printf("\n\t\t\t Enter Branch and Year: ");
                        fflush(stdin);
                        fgets(s.branch_year,50,stdin);
                        s.branch_year[strlen(s.branch_year)-1]='\0';

                        printf("\n\t\t\t Enter SGPA of 8 semesters\n\n");
                        float cgpa=0.0;
                        float sgpano=0.0;
                        for(int i=0;i<8;i++)
                        {
                            printf("\t\t\t\tSGPA %d semester: ",i+1);
                            scanf("%f",&s.sgpa[i]);
                            cgpa+=s.sgpa[i];
                            if(s.sgpa[i]!=0.0)
                                sgpano++;
                        }

                        cgpa/=sgpano;
                        s.cgpa=cgpa;
                        printf("\033[0m");

                        fwrite(&s,sizeof(s),1,fp1);

                        printf("\033[1;32m");
                        printf("\n\n\n\t\t\t DO YOU WANT TO ENTER ANOTHER STUDENT INFORMATION....(Y/N)\n");
                        printf("\033[0m");
                        fflush(stdin);
                        printLast();
                        a=getch();
                    }
                    flag=0;
                    break;
            case 2:while(a=='Y' || a=='y')
                    {
                        system("cls");
                        printHead();
                        fseek(fp2,0,SEEK_END);

                        printf("\033[01;36m");
                        printf("\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~ ENTER INFORMATION OF FACULTY MEMBER~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                        printf("\033[01;33m");
                        printf("\n\n\n\t\t\t Enter Full Name: ");
                        fflush(stdin);
                        fgets(f.name,50,stdin);
                        f.name[strlen(f.name)-1]='\0';

                        printf("\n\t\t\t Enter Father's Name: ");
                        fflush(stdin);
                        fgets(f.f_name,50,stdin);
                        f.f_name[strlen(f.f_name)-1]='\0';

                        printf("\n\t\t\t Enter Faculty ID: ");
                        fflush(stdin);
                        fgets(f.id,50,stdin);
                        f.id[strlen(f.id)-1]='\0';

                        printf("\n\t\t\t Enter Address: ");
                        fflush(stdin);
                        fgets(f.address,500,stdin);
                        f.address[strlen(f.address)-1]='\0';

                        printf("\n\t\t\t Enter Contact: ");
                        fflush(stdin);
                        fgets(f.contact,20,stdin);
                        f.contact[strlen(f.contact)-1]='\0';

                        printf("\n\t\t\t Enter Branch: ");
                        fflush(stdin);
                        fgets(f.branch,50,stdin);
                        f.branch[strlen(f.branch)-1]='\0';

                        fwrite(&f,sizeof(f),1,fp2);

                        printf("\033[1;32m");
                        printf("\n\n\n\t\t\t DO YOU WANT TO ENTER ANOTHER FACULTY MEMBER INFORMATION....(Y/N)\n");
                        fflush(stdin);
                        printLast();
                        a=getch();
                    }
                    flag=0;
                    break;

            case 3: flag=0;
                    break;

            default:flag=1;
                    printf("\033[1;31m");
                    printf("\n\n\n\t\t\t ERROR! YOU HAVE ENTERED WRONG OPTION!");
                    printf("\n\n\t\t\t TRY AGAIN!");
                    printf("\033[0m");
                    printLast();
                    getch();
                    break;
        }
    }
}

//~~~~~~~~~~~~~~~~FUNCTION THAT WILL REMOVE STUDENT INFORMATION FROM DATABASE~~~~~~~~~~~~~~~

FILE *delstud(FILE *fp)
{
    struct stud s;
    char tempRoll[30];
    int flag=0;
    FILE *ft;
    system("cls");
    printHead();

    ft=fopen("temp.txt","w+");

    printf("\033[01;36m");
    printf("\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~ STUDENT RECORD DELETION PAGE ~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\033[01;33m");
    printf("\n\n\n\t\t\t ENTER UNIVERSITY ROLL NUMBER OF STUDENT");
    printf("\n\n\t\t\t UNIVERSITY ROLL NO: ");
    scanf("%s",&tempRoll);

    rewind(fp);
    while((fread(&s,sizeof(s),1,fp))==1)
    {
        if(strcmp(s.roll,tempRoll)==0)
        {
            system("cls");
            printHead();
            printf("\033[1;32m");
            printf("\n\n\n\t\t\t SUCCESS! RECORD FOUND!");
            flag=1;
            sleep(2);

            system("cls");
            printHead();
            printf("\033[01;36m");
            printf("\n\n\n\t\t\t RECORD DELETED FOR");
            printf("\033[1;31m");
            printf("\n\n\t\t\t FULL NAME: %s",s.name);
            printf("\n\n\t\t\t FATHER'S NAME: %s",s.f_name);
            printf("\n\n\t\t\t UNIVERSITY ROLL NUMBER: %s",s.roll);
            printf("\n\n\t\t\t ADDRESS: %s",s.address);
            printf("\n\n\t\t\t CONTACT: %s",s.contact);
            printf("\n\n\t\t\t BRANCH AND YEAR: %s",s.branch_year);
            printf("\033[0m");
            printf("\n\n\n\n\t\t\t Press any key to continue.... ");
            getch();
            printf("\033[1;32m");
            printf("\n\n\n\n\t\t\t RECORD SUCCESSFULLY REMOVED FROM DATABASE!!!");
            printf("\033[0m");
            continue;
        }
        fwrite(&s,sizeof(s),1,ft);
    }

    fclose(fp);
    fclose(ft);

    remove("StudentInfo.txt");
    rename("temp.txt","StudentInfo.txt");

    if(flag==0)
    {
        system("cls");
        printHead();
        printf("\033[1;31m");
        printf("\n\n\n\t\t\t ERROR! RECORD NOT FOUND");
        printf("\033[0m");
    }
    printf("\n\n\n\t\t\t Press any key to continue....\n");
    getch();
    return fp;
}

//~~~~~~~~~~~~~~~~FUNCTION THAT WILL REMOVE FACULTY MEMBER INFORMATION FROM DATABASE~~~~~~~~~~~~~~~

FILE *delfacul(FILE *fp)
{
    struct faculty f;
    char tempRoll[30];
    int flag=0;
    FILE *ft;

    system("cls");
    printHead();

    ft=fopen("temp.txt","w+");

    printf("\033[01;36m");
    printf("\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~ FACULTY MEMBER RECORD DELETION PAGE ~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\033[01;33m");
    printf("\n\n\n\t\t\t ENTER FACULTY ID OF FACULTY MEMBER");
    printf("\n\n\t\t\t FACULTY ID: ");
    scanf("%s",&tempRoll);

    rewind(fp);
    while((fread(&f,sizeof(f),1,fp))==1)
    {
        if(strcmp(f.id,tempRoll)==0)
        {
            system("cls");
            printHead();
            printf("\033[1;32m");
            printf("\n\n\n\t\t\t SUCCESS! RECORD FOUND!");
            flag=1;
            sleep(2);

            system("cls");
            printHead();
            printf("\033[01;36m");
            printf("\n\n\n\t\t\t RECORD DELETED FOR");
            printf("\033[1;31m");
            printf("\n\n\t\t\t FULL NAME: %s",f.name);
            printf("\n\n\t\t\t FATHER'S NAME: %s",f.f_name);
            printf("\n\n\t\t\t FACULTY ID: %s",f.id);
            printf("\n\n\t\t\t ADDRESS: %s",f.address);
            printf("\n\n\t\t\t CONTACT: %s",f.contact);
            printf("\n\n\t\t\t BRANCH: %s",f.branch);
            printf("\033[0m");
            printf("\n\n\n\n\t\t\t Press any key to continue.... ");
            getch();
            printf("\033[1;32m");
            printf("\n\n\n\n\t\t\t RECORD SUCCESSFULLY REMOVED FROM DATABASE!!!");
            printf("\033[0m");
            continue;
        }
        fwrite(&f,sizeof(f),1,ft);
    }

    fclose(fp);
    fclose(ft);

    remove("facultyInfo.txt");
    rename("temp.txt","facultyInfo.txt");

    if(flag==0)
    {
        system("cls");
        printHead();
        printf("\033[1;31m");
        printf("\n\n\n\t\t\t ERROR! RECORD NOT FOUND");
        printf("\033[0m");
    }
    printf("\n\n\n\t\t\t Press any key to continue....\n");
    printLast();
    getch();
    return fp;
}

//~~~~~~~~~~~~~~~~FUNCTION THAT WILL MODIFY STUDENT INFORMATION IN DATABASE~~~~~~~~~~~~~~~

void modifystud(FILE *fp)
{
    struct stud s;
    int flag=0;
    char tempRoll[30];
    char a='Y';

    while(a=='Y' || a=='y')
    {
        system("cls");
        printHead();

        printf("\033[01;36m");
        printf("\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~ STUDENT RECORD MODIFICATION PAGE ~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\033[01;33m");
        printf("\n\n\n\t\t\t ENTER UNIVERSITY ROLL NUMBER OF STUDENT");
        printf("\n\n\t\t\t UNIVERSITY ROLL NO: ");
        scanf("%s",tempRoll);

        fseek(fp,0,SEEK_SET);
        while((fread(&s,sizeof(s),1,fp))==1)
        {
            if(strcmp(s.roll,tempRoll)==0)
            {
                flag=1;
                break;
            }
            else
                flag=0;
        }

        if(flag==1)
        {
            system("cls");
            printHead();

            printf("\033[1;32m");
            printf("\n\n\n\t\t\t SUCCESS! RECORD FOUND!");
            flag=1;
            sleep(2);

            system("cls");
            printHead();
            printf("\033[01;36m");
            printf("\n\n\n\t\t\t RECORD MODIFICATION FOR");
            printf("\033[1;32m");
            printf("\n\n\t\t\t FULL NAME: %s",s.name);
            printf("\n\n\t\t\t FATHER'S NAME: %s",s.f_name);
            printf("\n\n\t\t\t UNIVERSITY ROLL NUMBER: %s",s.roll);
            printf("\n\n\t\t\t ADDRESS: %s",s.address);
            printf("\n\n\t\t\t CONTACT: %s",s.contact);
            printf("\n\n\t\t\t BRANCH AND YEAR: %s",s.branch_year);
            printf("\n\n\t\t\t SGPA: ");
            for(int l=0;l<8;l++)
            {
                printf("|%.2f|",s.sgpa[l]);
            }
            printf("\n\n\t\t\t CGPA: %.2f",s.cgpa);
            printf("\033[0m");
            printf("\n\n\n\t\t\tPress any key to continue....");
            getch();

            system("cls");
            printHead();

            printf("\033[01;36m");
            printf("\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~ ENTER NEW INFORMATION OF STUDENT ~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            printf("\033[01;33m");
            printf("\n\n\n\t\t\t Enter Full Name: ");
            fflush(stdin);
            fgets(s.name,50,stdin);
            s.name[strlen(s.name)-1]='\0';

            printf("\n\t\t\t Enter Father's Name: ");
            fflush(stdin);
            fgets(s.f_name,50,stdin);
            s.f_name[strlen(s.f_name)-1]='\0';

            printf("\n\t\t\t Enter University Roll Number: ");
            fflush(stdin);
            fgets(s.roll,50,stdin);
            s.roll[strlen(s.roll)-1]='\0';

            printf("\n\t\t\t Enter Address: ");
            fflush(stdin);
            fgets(s.address,500,stdin);
            s.address[strlen(s.address)-1]='\0';

            printf("\n\t\t\t Enter Contact: ");
            fflush(stdin);
            fgets(s.contact,20,stdin);
            s.contact[strlen(s.contact)-1]='\0';

            printf("\n\t\t\t Enter Branch and Year: ");
            fflush(stdin);
            fgets(s.branch_year,50,stdin);
            s.branch_year[strlen(s.branch_year)-1]='\0';

            printf("\n\t\t\t Enter SGPA of 8 semesters\n\n");
            float cgpa=0.0;
            float sgpano=0.0;
            for(int i=0;i<8;i++)
            {
                printf("\t\t\t\tSGPA %d semester: ",i+1);
                scanf("%f",&s.sgpa[i]);
                cgpa+=s.sgpa[i];
                if(s.sgpa[i]!=0.0)
                    sgpano++;
            }

            cgpa/=sgpano;
            s.cgpa=cgpa;
            printf("\033[0m");

            fseek(fp,-760,SEEK_CUR);
            fwrite(&s,sizeof(s),1,fp);

        }
        else
        {
            system("cls");
            printHead();
            printf("\033[1;31m");
            printf("\n\n\n\t\t\t ERROR! RECORD NOT FOUND");
            printf("\033[0m");
        }

        printf("\033[1;32m");
        printf("\n\n\n\t\t\t DO YOU WANT TO MODIFY ANOTHER STUDENT RECORD....(Y/N)\n");
        printf("\033[0m");
        printLast();
        a=getch();
    }
}

//~~~~~~~~~~~~~~~~FUNCTION THAT WILL MODIFY FACULTY MEMBER INFORMATION IN DATABASE~~~~~~~~~~~~~~~

void modifyfacul(FILE *fp)
{
    struct faculty f;
    char tempRoll[30];
    char a='Y';
    int flag=0;
    while(a=='Y' || a=='y')
    {
        system("cls");
        printHead();

        printf("\033[01;36m");
        printf("\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~ FACULTY MEMBER RECORD MODIFICATION PAGE ~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\033[01;33m");
        printf("\n\n\n\t\t\t ENTER FACULTY ID OF FACULTY MEMBER");
        printf("\n\n\t\t\t FACULTY ID: ");
        scanf("%s",&tempRoll);

        rewind(fp);
        while((fread(&f,sizeof(f),1,fp))==1)
        {
            if(strcmp(f.id,tempRoll)==0)
            {
                flag=1;
                break;
            }
            else
                flag=0;
        }

        if(flag==1)
        {
            system("cls");
            printHead();

            printf("\033[1;32m");
            printf("\n\n\n\t\t\t SUCCESS! RECORD FOUND!");
            flag=1;
            sleep(2);

            system("cls");
            printHead();
            printf("\033[01;36m");
            printf("\n\n\n\t\t\t RECORD MODIFICATION FOR");
            printf("\033[1;32m");
            printf("\n\n\t\t\t FULL NAME: %s",f.name);
            printf("\n\n\t\t\t FATHER'S NAME: %s",f.f_name);
            printf("\n\n\t\t\t FACULTY ID: %s",f.id);
            printf("\n\n\t\t\t ADDRESS: %s",f.address);
            printf("\n\n\t\t\t CONTACT: %s",f.contact);
            printf("\n\n\t\t\t BRANCH: %s",f.branch);
            printf("\033[0m");
            printf("\n\n\n\t\t\tPress any key to continue....");
            getch();

            system("cls");
            printHead();

            printf("\033[01;36m");
            printf("\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~ ENTER NEW INFORMATION OF FACULTY MEMBER ~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            printf("\033[01;33m");
            printf("\n\n\n\t\t\t Enter Full Name: ");
            fflush(stdin);
            fgets(f.name,50,stdin);
            f.name[strlen(f.name)-1]='\0';

            printf("\n\t\t\t Enter Father's Name: ");
            fflush(stdin);
            fgets(f.f_name,50,stdin);
            f.f_name[strlen(f.f_name)-1]='\0';

            printf("\n\t\t\t Enter Faculty ID: ");
            fflush(stdin);
            fgets(f.id,50,stdin);
            f.id[strlen(f.id)-1]='\0';

            printf("\n\t\t\t Enter Address: ");
            fflush(stdin);
            fgets(f.address,500,stdin);
            f.address[strlen(f.address)-1]='\0';

            printf("\n\t\t\t Enter Contact: ");
            fflush(stdin);
            fgets(f.contact,20,stdin);
            f.contact[strlen(f.contact)-1]='\0';

            printf("\n\t\t\t Enter Branch: ");
            fflush(stdin);
            fgets(f.branch,50,stdin);
            f.branch[strlen(f.branch)-1]='\0';

            fseek(fp,-720,SEEK_CUR);
            fwrite(&f,sizeof(f),1,fp);
        }
        else
        {
            system("cls");
            printHead();
            printf("\033[1;31m");
            printf("\n\n\n\t\t\t ERROR! RECORD NOT FOUND");
            printf("\033[0m");
        }

        printf("\033[1;32m");
        printf("\n\n\n\t\t\t DO YOU WANT TO MODIFY ANOTHER FACULTY MEMBER RECORD....(Y/N)\n");
        printf("\033[0m");
        printLast();
        a=getch();
    }
}

//~~~~~~~~~~~~~~~~FUNCTION THAT WILL DISPLAY ALL STUDENT INFORMATION PRESENT IN DATABASE~~~~~~~~~~~~~~~

void displayListstud(FILE *fp)
{
    system("cls");
    printHead();
    struct stud s;

    printf("\033[01;36m");
    printf("\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~ STUDENT RECORD DISPLAY PAGE ~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("\033[0m");
    rewind(fp);

    while(fread(&s,sizeof(s),1,fp)==1)
    {
        printf("\033[01;33m");
        printf("\n\n\n\t\t\t FULL NAME: %s",s.name);
        printf("\n\n\t\t\t FATHER'S NAME: %s",s.f_name);
        printf("\n\n\t\t\t UNIVERSITY ROLL NO: %s",s.roll);
        printf("\n\n\t\t\t ADDRESS: %s",s.address);
        printf("\n\n\t\t\t CONTACT: %s",s.contact);
        printf("\n\n\t\t\t BRANCH AND YEAR: %s",s.branch_year);
        printf("\n\n\t\t\t SGPA: ");
        for(int i=0;i<8;i++)
        {
            printf("|%.2f|",s.sgpa[i]);
        }
        printf("\n\n\t\t\t CGPA: %.2f",s.cgpa);
        printf("\033[0m");
        printLast();
        sleep(1);

    }
    printf("\n\n\n\t\t\t Press any key to continue....\n");
    printLast();
    getch();
}

//~~~~~~~~~~~~~~~~FUNCTION THAT WILL DISPLAY ALL FACULTY MEMBER INFORMATION PRESENT IN DATABASE~~~~~~~~~~~~~~~

void displayListfacul(FILE *fp)
{
    system("cls");
    printHead();
    struct faculty f;

    printf("\033[01;36m");
    printf("\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~ FACULTY MEMBER RECORD DISPLAY PAGE ~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("\033[0m");
    rewind(fp);

    while(fread(&f,sizeof(f),1,fp)==1)
    {
        printf("\033[01;33m");
        printf("\n\n\n\t\t\t FULL NAME: %s",f.name);
        printf("\n\n\t\t\t FATHER'S NAME: %s",f.f_name);
        printf("\n\n\t\t\t FACULTY ID: %s",f.id);
        printf("\n\n\t\t\t ADDRESS: %s",f.address);
        printf("\n\n\t\t\t CONTACT: %s",f.contact);
        printf("\n\n\t\t\t BRANCH: %s",f.branch);
        printf("\033[0m");
        printLast();
        sleep(1);
    }
    printf("\n\n\n\t\t\t Press any key to continue....\n");
    printLast();
    getch();
}

//~~~~~~~~~~~~~~~~FUNCTION THAT WILL SEARCH STUDENT INFORMATION IN DATABASE~~~~~~~~~~~~~~~

void searchRecordstud(FILE *fp)
{
    int flag;
    struct stud s;
    char tempRoll[30];
    char a='Y';

    while(a=='Y' || a=='y')
    {
        system("cls");
        printHead();

        printf("\033[01;36m");
        printf("\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~ STUDENT RECORD SEARCHING PAGE ~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\033[01;33m");
        printf("\n\n\n\t\t\t ENTER UNIVERSITY ROLL NUMBER OF STUDENT");
        printf("\n\n\t\t\t UNIVERSITY ROLL NO: ");
        scanf("%s",&tempRoll);

        fseek(fp,0,SEEK_SET);
        while((fread(&s,sizeof(s),1,fp))==1)
        {
            if(strcmp(s.roll,tempRoll)==0)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            system("cls");
            printHead();

            printf("\033[1;32m");
            printf("\n\n\n\t\t\t SUCCESS! RECORD FOUND!");
            flag=1;
            sleep(2);

            system("cls");
            printHead();
            printf("\033[01;36m");
            printf("\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~ DETAILS OF STUDENT ~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            printf("\033[1;33m");
            printf("\n\n\t\t\t FULL NAME: %s",s.name);
            printf("\n\n\t\t\t FATHER'S NAME: %s",s.f_name);
            printf("\n\n\t\t\t UNIVERSITY ROLL NO: %s",s.roll);
            printf("\n\n\t\t\t ADDRESS: %s",s.address);
            printf("\n\n\t\t\t CONTACT: %s",s.contact);
            printf("\n\n\t\t\t BRANCH AND YEAR: %s",s.branch_year);
            printf("\n\n\t\t\t SGPA: ");
            for(int i=0;i<8;i++)
                printf("|%.2f|",s.sgpa[i]);
            printf("\n\n\t\t\t CGPA: %.2f",s.cgpa);
        }

        else
        {
            system("cls");
            printHead();
            printf("\033[1;31m");
            printf("\n\n\n\t\t\t ERROR! RECORD NOT FOUND");
            printf("\033[0m");
        }

        printf("\033[1;32m");
        printf("\n\n\n\t\t\t DO YOU WANT TO SEARCH FOR ANOTHER STUDENT RECORD....(Y/N)\n");
        printf("\033[0m");
        printLast();
        a=getch();
    }
}

//~~~~~~~~~~~~~~~~FUNCTION THAT WILL SEARCH FACULTY MEMBER INFORMATION IN DATABASE~~~~~~~~~~~~~~~

void searchRecordfacul(FILE *fp)
{
    int flag;
    struct faculty f;
    char tempRoll[30];
    char a='Y';

    while(a=='Y' || a=='y')
    {
        system("cls");
        printHead();

        printf("\033[01;36m");
        printf("\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~ FACULTY MEMBER RECORD SEARCHING PAGE ~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\033[01;33m");
        printf("\n\n\n\t\t\t ENTER FACULTY ID OF FACULTY MEMBER");
        printf("\n\n\t\t\t FACULTY ID: ");
        scanf("%s",&tempRoll);

        rewind(fp);
        while((fread(&f,sizeof(f),1,fp))==1)
        {
            if(strcmp(f.id,tempRoll)==0)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            system("cls");
            printHead();

            printf("\033[1;32m");
            printf("\n\n\n\t\t\t SUCCESS! RECORD FOUND!");
            flag=1;
            sleep(2);

            system("cls");
            printHead();
            printf("\033[01;36m");
            printf("\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~ DETAILS OF FACULTY MEMBER ~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            printf("\033[1;33m");
            printf("\n\n\t\t\t FULL NAME: %s",f.name);
            printf("\n\n\t\t\t FATHER'S NAME: %s",f.f_name);
            printf("\n\n\t\t\t FACULTY ID: %s",f.id);
            printf("\n\n\t\t\t ADDRESS: %s",f.address);
            printf("\n\n\t\t\t CONTACT: %s",f.contact);
            printf("\n\n\t\t\t BRANCH: %s",f.branch);
        }

        else
        {
            system("cls");
            printHead();
            printf("\033[1;31m");
            printf("\n\n\n\t\t\t ERROR! RECORD NOT FOUND");
            printf("\033[0m");
        }

        printf("\033[1;32m");
        printf("\n\n\n\t\t\t DO YOU WANT TO SEARCH FOR ANOTHER FACULTY MEMBER RECORD....(Y/N)\n");
        printf("\033[0m");
        printLast();
        a=getch();
    }
}

//~~~~~~~~~~~~~~~~FUNCTION THAT UPDATE USERNAME AND PASSWORD REGISTERED IN DATABASE~~~~~~~~~~~~~~~

void update_user_pass(FILE *pas)
{
    system("cls");
    printHead();

    char user[30];
    char pass[30];
    int flag;
    struct authentication p;

    printf("\033[01;36m");
    printf("\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~ USERNAME AND PASSWORD MODIFICATION PAGE ~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\033[01;33m");
    printf("\n\n\n\n\t\t\t ENTER YOUR EXISTING USERNAME : ");
    scanf("%s",&user);
    printf("\n\n\t\t\t ENTER YOUR EXISTING PASSWORD: ");
    scanf("%s",&pass);

    rewind(pas);
    while((fread(&p,sizeof(p),1,pas))==1)
    {
        if(strcmp(user,p.username)==0 && strcmp(pass,p.password)==0)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
    {
        system("cls");
        printHead();

        fseek(pas,-sizeof(p),SEEK_CUR);


        printf("\033[1;32m");
        printf("\n\n\n\t\t\t SUCCESS! USERNAME AND PASSWORD FOUND!");
        flag=1;
        sleep(2);

        system("cls");
        printHead();

        printf("\033[01;36m");
        printf("\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~ ENTER NEW USERNAME AND PASSWORD ~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\033[01;33m");
        printf("\n\n\n\t\t\t ENTER A NEW USERNAME: ");
        scanf("%s",p.username);
        printf("\n\n\t\t\t ENTER A NEW PASSWORD:");
        scanf("%s",p.password);

        fwrite(&p,sizeof(p),1,pas);
        printf("\033[1;32m");
        printf("\n\n\n\t\t\t SUCCESS! NEW USERNAME AND PASSWORD REGISTERED");
        printf("\033[0m");
    }
    else
    {
        system("cls");
        printHead();
        printf("\033[1;31m");
        printf("\n\n\n\t\t\t ERROR! NO SUCH USERNAME AND PASSWORD REGISTERED");
        printf("\033[0m");
    }
    printf("\n\n\n\t\t\t Press any key to continue....");
    getch();
    fclose(pas);
}

//~~~~~~~~~~~~~~~~FUNCTION THAT DELETE USERNAME AND PASSWORD REGISTERED IN DATABASE~~~~~~~~~~~~~~~

FILE *deletepass(FILE *pas)
{
    struct authentication p;
    int siz=sizeof(p);
    char user[30],pass[30];
    int flag;
    FILE *ft;
    char a='Y';

    while(a=='Y' || a=='y')
    {
        system("cls");
        printHead();
        ft=fopen("temp.txt","w+");

        printf("\033[01;36m");
        printf("\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~ USERNAME AND PASSWORD DELETION PAGE ~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\033[01;33m");
        printf("\n\n\n\n\t\t\t ENTER YOUR EXISTING USERNAME : ");
        scanf("%s",&user);
        printf("\n\n\t\t\t ENTER YOUR EXISTING PASSWORD: ");
        scanf("%s",&pass);

        rewind(pas);
        while((fread(&p,siz,1,pas))==1)
        {
            if(strcmp(user,p.username)==0 && strcmp(pass,p.password)==0)
            {
                flag=1;
                printf("\033[1;32m");
                printf("\n\n\n\t\t\t SUCCESS! USERNAME AND PASSWORD FOUND!");
                flag=1;
                sleep(2);

                system("cls");
                printHead();

                printf("\033[01;36m");
                printf("\n\n\n\t\t\t USERNAME AND PASSWORD FOR DELETION");
                printf("\033[1;31m");
                printf("\n\n\t\t\t USERNAME: %s",p.username);
                printf("\n\n\t\t\t PASSWORD: %s",p.password);
                printf("\033[0m");
                printf("\n\n\n\n\t\t\t Press any key to continue.... ");
                getch();
                printf("\033[1;32m");
                printf("\n\n\n\n\t\t\t USERNAME AND PASSWORD SUCCESSFULLY REMOVED FROM DATABASE!!!");
                printf("\033[0m");
                continue;
            }
            fwrite(&p,siz,1,ft);
        }

        fclose(pas);
        fclose(ft);

        remove("password.txt");
        rename("temp.txt","password.txt");

        if((pas=fopen("password.txt","rb+"))==NULL)
        {
            return  NULL;
        }

        if(flag==1)
        {


        }
        else
        {
            system("cls");
            printHead();
            printf("\033[1;31m");
            printf("\n\n\n\t\t\t ERROR! NO SUCH USERNAME AND PASSWORD REGISTERED");
            printf("\033[0m");
        }
        printf("\n\n\t\t\t DO YOU WANT TO REMOVE ANOTHER USERNAME AND PASSWORD....(Y/N)");
        a=getch();
    }
    return pas;
}

//~~~~~~~~~~~~~~~~LOADING SCREEN FUNCTION~~~~~~~~~~~~~~~
void loading_screen()
{
    for(int i=1;i<=10;i++)
    {
        system("cls");
        printHead();
        printf("\033[01;33m");
        printf("\n\n\n\n\t\t\t\t\t\t    LOADING: %d%%",10*i);
        printf("\n\n\t\t\t\t\t\t");
        printf("\033[01;36m");
        printChar('\xdb',2*i);
        if(i!=10)
        {
            printf("\033[1;32m");
            printf("\n\n\n\n\n\t\t\t\t\t\tPROGRAM IS LOADING......");
            printf("\033[0m");
            printf("\e[1;97m");
            printf("\n\n\n\n");
            printChar('=',120);
            printf("\n");
            printChar('\xdb',120);
            printf("\n");
            printChar('=',120);
            printf("\033[0m");
            sleep(1);
        }
    }
    printf("\033[1;32m");
    printf("\n\n\n\n\n\t\t\t\t\t\tPROGRAM LOADED......");
    printf("\033[0m");
    printf("\n\n\t\t\t\t\t\tPress any key to continue... ");
    printf("\e[1;97m");
    printf("\n\n\n\n");
    printChar('=',120);
    printf("\n");
    printChar('\xdb',120);
    printf("\n");
    printChar('=',120);
    printf("\033[0m");
    getch();

}

//~~~~~~~~~~~~~~~~FUNCTION THAT WILL DISPLAY INFORMATION REGARDING MINI PROJECT~~~~~~~~~~~~~~~

void information()
{
    system("cls");
    printHead();
    printf("\033[01;36m");
    printf("\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~ MINI PROJECT INFORMATION ~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\033[1;32m");
    printf("\n\n\t\t\t\t    MINI PROJECT ON COLLEGE DATABASE MANAGEMENT SYSTEM");
    printf("\n\n\t\t\t\t\t      CREATED BY MADHAV CHANDOK");
    printf("\033[01;33m");
    printf("\n\n\n\t\t\t ROLL NO:\t\t 1902160130023");
    printf("\n\n\t\t\t BRANCH AND YEAR:\t INFORMATION TECHNOLOGY(IT) 2ND YEAR 3RD SEMESTER");
    printf("\n\n\t\t\t SESSION:\t\t 2020-21");
    printf("\n\n\t\t\t COLLEGE:\t\t IIMT COLLEGE OF ENGINEERING, GREATER NOIDA - 201310");
    printf("\n\n\t\t\t UNIVERSITY:\t\t ABDUL KALAM TECHNICAL UNIVERSITY (AKTU), LUCKNOW - 226031");
    printf("\033[0m");
    printf("\n\n\n\t\t\t Press any key to continue....");
    getch();
}

void thanks()
{
    system("cls");
    printHead();
    printf("\033[01;36m");
    printf("\n\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~ < THANKS FOR USING APPLICATION > ~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\033[1;32m");
    printf("\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~ < COLLEGE DATABASE MANAGEMENT SYSTEM > ~~~~~~~~~~~~~~~~~~~~~");
    printf("\033[01;33m");
    printf("\n\n\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ < CREATED BY > ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ < MADHAV CHANDOK > ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\033[0m");
    sleep(2);
}

int main(void)
{
    information();
    int acc;
    int flag1,flag2,flag3,flag4;
    FILE *fp;
    if((fp=fopen("password.txt","r+"))==NULL)
    {
        if((fp=fopen("password.txt","w+"))==NULL)
        {
            printf("\n\n\t\t\t\t CAN'T OPEN FILE!....");
        }
    }

    acc=login(fp);
    fclose(fp);
    if(acc==1)
    {
        FILE *fp1, *fp2, *pas;
        int option;

        loading_screen();

        while(1)
        {
            if((fp1=fopen("StudentInfo.txt","r+"))==NULL)
            {
                if((fp1=fopen("StudentInfo.txt","w+"))==NULL)
                {
                    printf("\n\n\t\t\t\t CAN'T OPEN FILE!....");
                }
            }

            if((fp2=fopen("facultyInfo.txt","r+"))==NULL)
            {
                if((fp2=fopen("facultyInfo.txt","w+"))==NULL)
                {
                    printf("\n\n\t\t\t\t CAN'T OPEN FILE!....");
                }
            }

            if((pas=fopen("password.txt","r+"))==NULL)
            {
                if((pas=fopen("password.txt","w+"))==NULL)
                {
                    printf("\n\n\t\t\t\t CAN'T OPEN FILE!....");
                }
            }
            system("cls");
            printHead();
            printf("\e[01;36m");
            printf("\n\n\t\t\t\t~~~~~~~~~~~~~~~ WELCOME TO THE MAIN MENU ~~~~~~~~~~~~~~~");
            printf("\033[01;33m");
            printf("\n\n\t\t\t\t PRESS[1]-------> ADD RECORD IN DATABASE");
            printf("\n\n\t\t\t\t PRESS[2]-------> DELETE RECORD IN DATABASE");
            printf("\n\n\t\t\t\t PRESS[3]-------> UPDATE RECORD IN DATABASE");
            printf("\n\n\t\t\t\t PRESS[4]-------> DISPLAY RECORD IN DATABASE");
            printf("\n\n\t\t\t\t PRESS[5]-------> SEARCH RECORD IN DATABASE");
            printf("\n\n\t\t\t\t PRESS[6]-------> UPDATE USERNAME AND PASSWORD");
            printf("\n\n\t\t\t\t PRESS[7]-------> ADD NEW USERNAME AND PASSWORD");
            printf("\n\n\t\t\t\t PRESS[8]-------> REMOVE USERNAME AND PASSWORD");
            printf("\n\n\t\t\t\t PRESS[0]-------> EXIT FROM DATABASE SYSTEM");
            printf("\033[1;32m");
            printf("\n\n\t\t\t\t ENTER YOUR OPTION: ");
            scanf("%d",&option);
            printf("\033[0m");

            switch(option)
            {
                case 0: thanks();
                        return 0;
                        break;
                case 1: add(fp1,fp2);
                        break;
                case 2: flag1=1;
                        while(flag1==1)
                        {
                            system("cls");
                            printHead();
                            int x;

                            printf("\033[01;36m");
                            printf("\n\n\n\t\t\t\t~~~~~~~~~~~~~~~ RECORD DELETION MENU ~~~~~~~~~~~~~~~");
                            printf("\033[01;33m");
                            printf("\n\n\n\n\n\t\t\t\t PRESS[1]------->DELETE STUDENT RECORD");
                            printf("\n\n\t\t\t\t PRESS[2]------->DELETE FACULTY MEMBER RECORD");
                            printf("\n\n\t\t\t\t PRESS[3]------->RETURN TO MAIN MENU");
                            printf("\033[1;32m");
                            printf("\n\n\n\n\n\t\t\t\t ENTER YOUR OPTION: ");
                            scanf("%d",&x);
                            printf("\033[0m");
                            switch(x)
                            {
                                case 1:fp1=delstud(fp1);
                                        flag1=0;
                                        break;
                                case 2:fp2=delfacul(fp2);
                                        flag1=0;
                                        break;
                                case 3:flag1=0;
                                        break;
                                default:printf("\033[01;31m");
                                        printf("\n\n\n\t\t\t\t ERROR! YOU HAVE ENTERED WRONG OPTION!");
                                        printf("\n\n\t\t\t\t TRY AGAIN!");
                                        printLast();
                                        printf("\033[0m");
                                        sleep(1);
                                        flag1=1;
                                        break;
                            }
                        }
                        break;

                case 3: flag2=1;
                        while(flag2==1)
                        {
                            system("cls");
                            printHead();
                            int y;

                            printf("\033[01;36m");
                            printf("\n\n\n\t\t\t\t~~~~~~~~~~~~~~~ RECORD MODIFICATION MENU ~~~~~~~~~~~~~~~");
                            printf("\033[01;33m");
                            printf("\n\n\n\n\n\t\t\t\t PRESS[1]------->MODIFY STUDENT RECORD");
                            printf("\n\n\t\t\t\t PRESS[2]------->MODIFY FACULTY MEMBER RECORD");
                            printf("\n\n\t\t\t\t PRESS[3]------->RETURN TO MAIN MENU");
                            printf("\033[1;32m");
                            printf("\n\n\n\n\n\t\t\t\t ENTER YOUR OPTION: ");
                            scanf("%d",&y);
                            printf("\033[0m");
                            switch(y)
                            {
                                case 1: modifystud(fp1);
                                        flag2=0;
                                        break;
                                case 2: modifyfacul(fp2);
                                        flag2=0;
                                        break;
                                case 3: flag2=0;
                                        break;
                                default:printf("\033[01;31m");
                                        printf("\n\n\n\t\t\t\t ERROR! YOU HAVE ENTERED WRONG OPTION!");
                                        printf("\n\n\t\t\t\t TRY AGAIN!");
                                        printLast();
                                        printf("\033[0m");
                                        sleep(1);
                                        flag2=1;
                                        break;
                            }
                        }
                        break;
                case 4: flag3=1;
                        while(flag3==1)
                        {
                            system("cls");
                            printHead();
                            int z;

                            printf("\033[01;36m");
                            printf("\n\n\n\t\t\t\t~~~~~~~~~~~~~~~ RECORD DISPLAY MENU ~~~~~~~~~~~~~~~");
                            printf("\033[01;33m");
                            printf("\n\n\n\n\n\t\t\t\t PRESS[1]------->DISPLAY STUDENT RECORD");
                            printf("\n\n\t\t\t\t PRESS[2]------->DISPLAY FACULTY MEMBER RECORD");
                            printf("\n\n\t\t\t\t PRESS[3]------->RETURN TO MAIN MENU");
                            printf("\033[1;32m");
                            printf("\n\n\n\n\n\t\t\t\t ENTER YOUR OPTION: ");
                            scanf("%d",&z);
                            printf("\033[0m");
                            switch(z)
                            {
                                case 1: displayListstud(fp1);
                                        flag3=0;
                                        break;
                                case 2: displayListfacul(fp2);
                                        flag3=0;
                                        break;
                                case 3: flag3=0;
                                        break;
                                default:printf("\033[01;31m");
                                        printf("\n\n\n\t\t\t\t ERROR! YOU HAVE ENTERED WRONG OPTION!");
                                        printf("\n\n\t\t\t\t TRY AGAIN!");
                                        printLast();
                                        printf("\033[0m");
                                        sleep(1);
                                        flag2=1;
                                        break;
                            }
                        }
                        break;
                case 5: flag4=1;
                        while(flag4==1)
                        {
                            system("cls");
                            printHead();
                            int c;

                            printf("\033[01;36m");
                            printf("\n\n\n\t\t\t\t~~~~~~~~~~~~~~~ RECORD SEARCHING MENU ~~~~~~~~~~~~~~~");
                            printf("\033[01;33m");
                            printf("\n\n\n\n\n\t\t\t\t PRESS[1]------->SEARCH STUDENT RECORD");
                            printf("\n\n\t\t\t\t PRESS[2]------->SEARCH FACULTY MEMBER RECORD");
                            printf("\n\n\t\t\t\t PRESS[3]------->RETURN TO MAIN MENU");
                            printf("\033[1;32m");
                            printf("\n\n\n\n\n\t\t\t\t ENTER YOUR OPTION: ");
                            scanf("%d",&c);
                            printf("\033[0m");

                            switch(c)
                            {
                                case 1: searchRecordstud(fp1);
                                        flag4=0;
                                        break;
                                case 2: searchRecordfacul(fp2);
                                        flag4=0;
                                        break;
                                case 3: flag4=0;
                                        break;
                                default:printf("\033[01;31m");
                                        printf("\n\n\n\t\t\t\t ERROR! YOU HAVE ENTERED WRONG OPTION!");
                                        printf("\n\n\t\t\t\t TRY AGAIN!");
                                        printLast();
                                        printf("\033[0m");
                                        sleep(1);
                                        flag4=1;
                                        break;
                            }
                        }
                        break;
                case 6:update_user_pass(pas);
                        break;
                case 7:pass(pas);
                        break;
                case 8:pas=deletepass(pas);
                        break;
                default:system("cls");
                        printHead();
                        printf("\033[1;31m");
                        printf("\n\n\n\n\t\t\t\t ERROR! YOU HAVE ENTERED WRONG OPTION!");
                        printf("\n\n\t\t\t\t TRY AGAIN!");
                        printf("\033[0m");
                        printLast();
                        sleep(2);
                        break;
            }
            fclose(fp1);
            fclose(fp2);
            fclose(pas);
        }
    }
    else
    {
        system("cls");
        printHead();
        printf("\033[1;32m");
        printf("\n\n\n\t\t\t\t YOU HAVE ENTERED WRONG PASSWORD 3 TIMES CONSECUTIVELY!");
        sleep(3);
        printf("\033[0m");
        for(int i=5;i>0;i--)
        {
            system("cls");
            printHead();
            printf("\033[1;32m");
            printf("\n\n\n\n\t\t\t\t EXITING THE PROGRAM IN %d SECONDS........",i);
            printf("\033[0m");
            printLast();
            sleep(1);
        }
    }
}
