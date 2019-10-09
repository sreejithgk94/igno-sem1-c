#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <curses.h>

struct Student
{
    /* data */
    char studentId[100];
    char studentName[100];
    int studentClass;
    char studentDivision;
    float lastClassMark;
    char contact[12];
};


void main()
{
    struct Student student;
    int ch;
    FILE *file;

    system("clear");
    printf("\n1.Add student Details");
    printf("\n2.Search By Student Details");
    printf("\n3.Class Details");
    printf("\n4.Modify the Student Details");
    printf("\nplease select the option Number:");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
                file = fopen ("student.dat", "w"); 
                if (file == NULL) 
                { 
                    fprintf(stderr, "\nError opend file\n"); 
                    exit (1); 
                } 

            printf("\nEnter the student id:");
            scanf("%s",&student.studentId);

            printf("\nEnter the student Name:");
            scanf("%s",&student.studentName);

            printf("\nEnter the student class (in integer):");
            scanf("%d",&student.studentClass);

            printf("\nEnter the student division:");
            scanf("%s",&student.studentDivision);

            printf("\nEnter the student last class total mark:");
            scanf("%f",&student.lastClassMark);

            printf("\nEnter the parents Contact number:");
            scanf("%s",&student.contact);

            printf("\nStdentId:%s",student.studentId);

            printf("\nstudent Name:%s",student.studentName);

            printf("\nstudent class:%d",student.studentClass);

            printf("\nStudent division:%c",student.studentDivision);

            printf("\nStudent last mark:%f",student.lastClassMark);

            printf("\nstudent parent contact:%s",student.contact);

            fwrite (&student, sizeof(struct Student), 1, file);
            if(fwrite != 0)  
                 printf("contents to file written successfully !\n"); 
            else 
                printf("error writing file !\n"); 
  
    // close file 
    fclose (file);
        break;
    
    default:printf("\n please check the input");
        break;
    }
    getch();
}

