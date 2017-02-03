//
//  main.c
//  C-Project
//
//  Created by Mai & Maki on 2017-02-02.
//

#include <stdio.h>

void operator();
void printMenu();
void printEnrolment();
void printCourses();
void printTranscript();
void printGPA();
void printRanking();
void ListAllCourses();
void ListAllStudents();
void mylogout();

int main(int argc, const char * argv[]) {
    
    operator();
    
    return 0;
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
                mylogout();
                break;
                
            case 9:
                printf("Exit. Thank you.\n");
                break;
                
            default:
                printf("Please enter the correct option.\n");
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
    printf("Print enrolment certificate ...\n");
}


void printCourses() {
    
    // TODO: Print user's courses.
    printf("Print courses ...\n");
}


void printTranscript() {
    
    // TODO: Print user's transcript.
    printf("Print transcript ...\n");
}


void printGPA() {
    
    // TODO: Print user's GPA.
    printf("Print GPA ...\n");
}


void printRanking() {
    
    // TODO: Print ranking among all studentsin the college.
    printf("Print ranking among all studentsin the college ...\n");
}



void ListAllCourses() {
    
    // TODO: List all available courses.
    // If the user entered ‘6’, the program will printthe list of all available courses in the college in the following format and then printthemenu.
    printf("List all available courses ...\n");
}


void ListAllStudents() {
    
    // TODO: List all students.
    // If the user enters ‘7’, the program will printthe list of all students in the college in the following format and then printthe menu.
    
    printf("There are 4 students in CICCC as following:\n");
    printf("1)Peter Brown: 7813007\n");
    printf("2)Joseph Rod: 812345\n");
    printf("3)Cristina Li: 8012333\n");
    printf("4)Adams Wang: 7812999\n\n");
}

void mylogout() {
    
    // TODO: logout.
    
    // If the user entered‘8’, the program will print the login menu and let the user login again with the same or different account.
    printf("Logout! Thank you.\n");
}

