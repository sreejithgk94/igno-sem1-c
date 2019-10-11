#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <curses.h>

typedef struct 
{
    /* data */
    char studentId[100],studentName[100], studentDivision,contact[12];
    int studentClass, fileleng;
    float lastClassMark;
}Student;
void main()
{
    Student student;
    int ch ,fileCount=0,status=0;
    int sizeOfStudent=sizeof(student);
    char  replay ,searchQuerry[100];
    FILE *file;

    system("cls");
    
    printf("\n1.Add student Details");
    printf("\n2.Search By Student Name");
    printf("\n3.Student Details List");
    printf("\n4.Modify the Student Details");
    printf("\n5.Exit");
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
            do
            {
                /* code */
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
            //gcc student.c -o student -lncurses
            fwrite (&student, sizeof(Student), 1, file);
            if(fwrite != 0)  {
                 printf("contents to file written successfully !\n"); 
                 printf("\nDo you want add more student details Y/N:");
                 scanf("%s", &replay );
            }
                //if the condition satisfy the message will be print

                
            else {
                printf("error writing file !\n"); 
            }

            } while (replay == 'Y');
            // close file 
            fclose (file);
            break;
            
            
        case 2:
                file= fopen("student.dat","r");
                if(file == NULL)
                {
                    fprintf(stderr,"\nOops file open error \n");
                    exit(1);
                }
                printf("\nEnter the student:");
                scanf("%s",&searchQuerry);
                fseek(file,0,SEEK_SET);
                 printf("\nSearch Result");
                printf("\n----------------\n");
                while (fread(&student,sizeOfStudent,1,file) == 1)
                {
                   fileCount++;
                   if(student.studentName == searchQuerry){
                       status = 1;
                       break;
                   }
                }
                if(status){
                    printf ("\nId=%s Name=%s Class=%d Division=%c TotalMark=%f contact=%s\n", 
                    student.studentId,student.studentName, student.studentClass, 
                    student.studentDivision,student.lastClassMark,student.contact);
                }
                else
                {
                    printf("\nNo data found\n");
                }
                fclose(file);
                break;
                
        case 3:
                file = fopen ("student.dat", "r"); 
                if (file == NULL) 
                { 
                    fprintf(stderr, "\nOops file open error\n"); 
                    exit (1); 
                } 
                
                // read file contents till end of file 
                //https://www.dreamincode.net/forums/topic/99843-searching-for-data-in-a-file-using-c/
                printf("\nStudents List Details");
                printf("\n---------------------");
                while(fread(&student, sizeof(Student), 1, file)) 
                    printf ("\nId=%s Name=%s Class=%d Division=%c TotalMark=%f contact=%s\n", 
                    student.studentId,student.studentName, student.studentClass, 
                    student.studentDivision,student.lastClassMark,student.contact); 
            
                // close file 
                fclose (file); 
                break; 

        case 4:exit(0);

        case 5 :exit(0);       
    
    default:printf("\n please check the input\n");
        break;
    }
    getch();

}


