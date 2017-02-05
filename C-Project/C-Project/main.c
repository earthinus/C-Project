//
//  main.c
//  C-Project
//
//  Created by Mai & Maki on 2017-02-02.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

void readFile(char *filename);
char** splitKeyValue(char* readline);
void storeStudent(int studentIndex, char** result);
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

#define FILE_STUDENTS "Students.txt"
#define FILE_STUDENTSCOURSES "StudentsCourses.txt"
#define FILE_ACCOUNTS "Accounts.txt"
#define FILE_COURSES "Courses.txt"

struct student {
    char* studentID;
    char* firstName;
    char* lastName;
    char* passWord;
    char* gender;
    char* grade;
    char* mark;
    char* address;
    char* admission_year;
    char* courses;
} students[3];

struct course {
    char* courseID;
    char* name;
} course[3];

int main(int argc, const char * argv[]) {
    
    // Read files
    readFile(FILE_STUDENTS);
    
    
    // Print students info
//    printf("Displaying Information:\n\n");
    
    
    //myLogin();
    
    printf("Storing was succeeded!\nstudents[0].studentID = %s\n", students[0].studentID);
    
    return 0;
}


void readFile(char *filename) {
    
    char** result;
    
    // Open file
    printf("============= Opened %s =============\n\n", filename);
    FILE* file = fopen(filename, "r");
    
    if (file != NULL) {
        
        // Max length of a line = 200
        char readline[200];
        
        // Split keys and values on each line
        while (fgets(readline, 200, file) != NULL) {
            
            // fputs(readline, stdout);
            
            result = splitKeyValue(readline);
            
            printf("key: %s\n", *result);
            printf("value: %s\n", *(result+1));
            
            // Store to struct Student
            storeStudent(0, result);
            
        }
        
        fclose(file);
    }
}


char** splitKeyValue(char* readline) { // readline is "studentID:”7813007”\n"
    
    char colon = ':';
    char doubleQuo = '\xe2';
    
    // Get key's length
    int keyLength = 0;
    while (readline[keyLength] != colon) {
        keyLength++;
    }
    
    // Get value's length
    int valueLength = 0;
    int startIndex = keyLength;
    bool hasDoubleQuo = false;
    while (readline[startIndex] != '\n') {
        valueLength++;
        startIndex++;
        
        // Check the double quotations
        if (readline[valueLength] == doubleQuo) {
            hasDoubleQuo = true;
        }
    }
    
    // Store key
    char* key   = (char*) malloc(keyLength * sizeof(char)); // Allocate key, value
    for (int i = 0; i < keyLength; i++) {
        key[i] = readline[i];
    }
    
    // Store value
    startIndex = keyLength + sizeof(colon);
    char* value = (char*) malloc(valueLength * sizeof(char)); // Allocate value
    for (int j = 0; j < valueLength; j++) {
        value[j] = readline[startIndex + j];
    }
    
    // Store result
    char** result;
    result = malloc(sizeof(char*) * 2);
    result[0] = key;
    result[1] = value;
    
    return result;
}


void storeStudent(int studentIndex, char** result) {
    
    char *studentID = "studentID",
    *name = "name",
    *passWord = "passWord",
    *gender = "gender",
    *mark = "mark",
    *grade = "grade",
    *address = "address",
    *admission_year = "admission_year",
    *courses = "courses";
    
    // ↓MEMO: stringの場合はswich文が使えないようなので、ifで対応
    
    // studentID
    if (strncmp(*result, studentID, sizeof(*studentID)) == 0) {
        students[studentIndex].studentID = *(result + 1);
        
    // Name
    } else if(strncmp(*result, name, sizeof(*name)) == 0) {
        
        // TODO: Split firstname and lastname
        
        students[studentIndex].firstName = *(result + 1);
        
    // Password
    } else if(strncmp(*result, passWord, sizeof(*passWord)) == 0) {
        students[studentIndex].passWord = *(result + 1);
        
    // Gender
    } else if(strncmp(*result, gender, sizeof(*gender)) == 0) {
        students[studentIndex].gender = *(result + 1);
        
    // Mark
    } else if(strncmp(*result, mark, sizeof(*mark)) == 0) {
        
        // TODO: casting from str to int
        
        students[studentIndex].mark = *(result + 1);
        
    // Grade
    } else if(strncmp(*result, grade, sizeof(*grade)) == 0) {
        
        // TODO: casting from str to int
        
        students[studentIndex].grade = *(result + 1);
       
    // Address
    } else if(strncmp(*result, address, sizeof(*address)) == 0) {
        students[studentIndex].address = *(result + 1);
        
    // Admission year
    } else if(strncmp(*result, admission_year, sizeof(*admission_year)) == 0) {
        
        // TODO: casting from str to int
        
        students[studentIndex].admission_year = *(result + 1);
        
    } else if(strncmp(*result, courses, sizeof(*courses)) == 0) {
        
        // TODO: split multiple cousers
        
        students[studentIndex].courses = *(result + 1);
    }
}


/* Login Function */

void login() {
    
    char* userInputName;
    char* userInputPassword;
    
    printf("************************************************************\n");
    printf("Please enter your account to login\n");
    printf("************************************************************\n");
    scanf("Username:%s", userInputName);
    scanf("Password:%s", userInputPassword);
    
    // TODO: ↓ @Mai / Compare with struct student by for loop
    
//    if(userInputName == students[i].firstName && userInputPassword == students[i].passWord) {
//        printf("************************************************************");
//        printf("Welcome to Cornerstone International College of Canada.");
//        printf("************************************************************");
//        
//        operator();
//        
//    } else {
//        printf("************************************************************");
//        printf("Your account does not exist. Please try again!");
//        printf("************************************************************");
//    }
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
    
    printf("The following courses are offered in CICCC:\n");
    printf("1)MADP101: Objective-C\n");
    printf("2)MADP102: Object-Oriented Programming\n");
    printf("3)MADP201: Problem Solving\n");
    printf("4)MADP202: Project Management\n");
    printf("5)MADP301: Java Programming\n");
    printf("6)MADP302: Web Development\n");
    printf("7)MADP401: Android Programming\n");
    printf("8)MADP402: iOS Applications\n\n");
    
//    for(int i = 0;i < 4;i++){
//        printf("%s\n", students[i].course);
//    }
}


void ListAllStudents() {
    
    // TODO: List all students.
    // If the user enters ‘7’, the program will printthe list of all students in the college in the following format and then printthe menu.
    
    printf("There are 4 students in CICCC as following:\n");
    printf("1)Peter Brown: 7813007\n");
    printf("2)Joseph Rod: 812345\n");
    printf("3)Cristina Li: 8012333\n");
    printf("4)Adams Wang: 7812999\n\n");
    
    
//    for(int i = 0; i < 8; i++){
//        printf("First name:%s\n", students[i].firstName);
//        printf("Last name:%s\n", students[i].lastName);
//        printf("Student ID:%s\n", students[i].studentID);
//        printf("Gender:%c\n", students[i].gender);
//        printf("------------------\n");
//    }
}


void myLogout() { // MEMO: ←logout()は予約語のようなので、代わりにmyLogoutにした。
    
    // TODO: Call login function
    
    // If the user entered‘8’, the program will print the login menu and let the user login again with the same or different account.
    printf("Logout! Thank you.\n\n");
}
