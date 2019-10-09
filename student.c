#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <curses.h>

struct Student
{
    /* data */
    char studentId[100],studentName[100], studentDivision,contact[12], searchKey,searchName[300], searchQuerry;
    int studentClass, fileleng ,i ,n;
    float lastClassMark;
};


void main()
{
    struct Student student;
    int ch;
    FILE *file;

    system("clear");
    printf("\n1.Add student Details");
    printf("\n2.Search By Student Name");
    printf("\n3.Student Details List");
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

            // write the files content to student structure data
            fwrite (&student, sizeof(struct Student), 1, file);
            if(fwrite != 0)  
                //if the condition satisfy the message will be print

                 printf("contents to file written successfully !\n"); 
            else 
                printf("error writing file !\n"); 
  
            // close file 
            fclose (file);
                break;
        case 2:
                file= fopen("student.dat","w+");
                if(file == NULL)
                {
                    fprintf(stderr,"\nOops file open error please check the database exist otherwise please create one\n");
                    exit(1);
                }
                i=sizeof(struct Student);
                printf("\nLength of dataBase:%d",&i);
                
                break;
                
        case 3:
                file = fopen ("student.dat", "r"); 
                if (file == NULL) 
                { 
                    fprintf(stderr, "\nOops file open error\n"); 
                    exit (1); 
                } 
                
                // read file contents till end of file 
                printf("\nStudents List Details");
                printf("\n---------------------");
                while(fread(&student, sizeof(struct Student), 1, file)) 
                    printf ("\nId=%s Name=%s Class=%d Division=%c TotalMark=%f contact=%s\n", 
                    student.studentId,student.studentName, student.studentClass, 
                    student.studentDivision,student.lastClassMark,student.contact); 
            
                // close file 
                fclose (file); 
                break; 
    
    default:printf("\n please check the input");
        break;
    }
    getch();
}

