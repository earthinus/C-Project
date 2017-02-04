//
//  main.c
//  C-Project
//
//  Created by Mai & Maki on 2017-02-02.
//

#include <stdio.h>
#include <stdlib.h>

void myLogin();
void operator();
void printMenu();
void printEnrolment();
void printCourses();
void printTranscript();
void printGPA();
void printRanking();
void ListAllCourses();
void ListAllStudents();
void myLogout();

char* userInputName;
char* userInputPassword;
int i;

#define FILE_STUDENTS "/Users/admin/Documents/Study/C/Project/C-Project/Students.txt"
#define FILE_STUDENTSCOURSES "/Users/admin/Documents/Study/C/Project/C-Project/StudentsCourses.txt"
#define FILE_ACCOUNTS "/Users/admin/Documents/Study/C/Project/C-Project/Accounts.txt"
#define FILE_COURSES "/Users/admin/Documents/Study/C/Project/C-Project/Courses.txt"

typedef struct student {
    char* studentID;
    char* firstName;
    char* lastName;
    char* passWord;
    char gender;
    double gpa;
    char* address;
    int admission_year;
    char* course;
} STUDENT;


int main(int argc, const char * argv[]) {
    
    myLogin();
    
    return 0;
}


void readFile(char *filename) {
    
    // Open file
    FILE* file = fopen(filename, "r");
    
    if (file != NULL) {
        
        // Maximum Character size on a line
        char maxCharCount[200];
        
        // Read each line by while loop
        while (fgets(maxCharCount, sizeof maxCharCount, file) != NULL) {
            
            fputs(maxCharCount, stdout);
        }
        
        fclose(file);
    }
}


/* Login Function */

void login(){
    
    printf("************************************************************");
    printf("Please enter your account to login");
    printf("************************************************************");
    scanf("Username:%s",userInputName);
    scanf("Password:%s",userInputPassword);
    
    if(userInputName == students[i].firstName && userInputPassword == students[i].passWord) {
        printf("************************************************************");
        printf("Welcome to Cornerstone International College of Canada.");
        printf("************************************************************");
        
        operator();
        
    } else {
        printf("************************************************************");
        printf("Your account does not exist. Please try again!");
        printf("************************************************************");
    }
}


void operator() {
    
    int input;
    
    while (input != 9) {
        
        printMenu();
        
        scanf("%d", &input);
        
        switch (input) {
            case 1:
                printEnrolment();
                break;
                
            case 2:
                printCourses();
                break;
                
            case 3:
                printTranscript();
                break;
                
            case 4:
                printGPA();
                break;
                
            case 5:
                printRanking();
                break;
                
            case 6:
                ListAllCourses();
                break;
                
            case 7:
                ListAllStudents();
                break;
                
            case 8:
                myLogout();
                break;
                
            case 9:
                printf("Exit. Thank you.\n\n");
                break;
                
            default:
                printf("Please enter the correct option.\n\n");
                break;
        }
    }
}


void printMenu() {
    
    printf("************************************************************\n");
    printf("Select from the options:\n");
    printf("************************************************************\n");
    printf("-[1] Print myenrolment certificate\n");
    printf("-[2] Print my courses\n");
    printf("-[3] Print my transcript\n");
    printf("-[4] Print my GPA\n");
    printf("-[5] Print my ranking among all studentsin the college\n");
    printf("-[6] List all available courses\n");
    printf("-[7] List all students\n");
    printf("-[8] Logout\n");
    printf("-[9] Exit\n");
    printf("************************************************************\n");
}


void printEnrolment() {
    
    // TODO: Print user's enrolment.
    printf("Dear Sir/Madam,\n\n");
    printf("This is to certify that Mr. Peter Brown with student id7813007 is a student at grade 1 at CICCC. ");
    printf("He was admitted to our college in 2011 and has taken 1 course(s). ");
    printf("Currently he resides at 850 West Vancouver, Vancouver.\n\n");
    printf("If you have any question, please don’t hesitate to contact us.");
    printf("\n\nThanks,\nWilliams,\n\n");
}


void printCourses() {
    
    // TODO: Print user's courses.
    printf("Hi Mr. Peter Brown,\n");
    printf("You have taken the following courses:\n");
    printf("1)MADP101: Objective-C\n");
    printf("2)MADP202:ProjectManagement\n");
    printf("3)MADP301:Java Programming\n");
    printf("4)MADP401:Android Programming\n\n");
}


void printTranscript() {
    
    // TODO: Print user's transcript.
    printf("Hi Mr. Peter Brown,\n");
    printf("Here is your transcript:\n");
    printf("1)MADP101: Objective-C: 80\n");
    printf("2)MADP202: Project Management: 45\n");
    printf("3)MADP301: Java Programming: 64\n");
    printf("4)MADP401: Android Programming: 70\n");
    printf("YOUR GPA IS: 64.75\n\n");
}


void printGPA() {
    
    // TODO: Print user's GPA.
    printf("Hi Mr. Peter Brown,\n");
    printf("Your GPA is 64.75\n\n");
}


void printRanking() {
    
    // TODO: Print ranking among all studentsin the college.
    printf("Hi Mr. Peter Brown,\n");
    printf("Your GPA is 64.75and therefore your rank is 3\n\n");
}


void ListAllCourses() {
    
    // TODO: List all available courses.
    // If the user entered ‘6’, the program will printthe list of all available courses in the college in the following format and then printthemenu.
//    printf("The following courses are offered in CICCC:\n");
//    printf("1)MADP101: Objective-C\n");
//    printf("2)MADP102: Object-Oriented Programming\n");
//    printf("3)MADP201: Problem Solving\n");
//    printf("4)MADP202: Project Management\n");
//    printf("5)MADP301: Java Programming\n");
//    printf("6)MADP302: Web Development\n");
//    printf("7)MADP401: Android Programming\n");
//    printf("8)MADP402: iOS Applications\n\n");
    
    for(int i = 0;i < 4;i++){
        printf("%s\n", students[i].course);
    }
}


void ListAllStudents() {
    
    // TODO: List all students.
    // If the user enters ‘7’, the program will printthe list of all students in the college in the following format and then printthe menu.
    
//    printf("There are 4 students in CICCC as following:\n");
//    printf("1)Peter Brown: 7813007\n");
//    printf("2)Joseph Rod: 812345\n");
//    printf("3)Cristina Li: 8012333\n");
//    printf("4)Adams Wang: 7812999\n\n");
    
    
    for(int i = 0; i < 8; i++){
        printf("First name:%s\n", students[i].firstName);
        printf("Last name:%s\n", students[i].lastName);
        printf("Student ID:%s\n", students[i].studentID);
        printf("Gender:%c\n", students[i].gender);
        printf("------------------\n");
    }
}


void myLogout() {
    
    // TODO: Call login function
    
    // If the user entered‘8’, the program will print the login menu and let the user login again with the same or different account.
    printf("Logout! Thank you.\n\n");
}
