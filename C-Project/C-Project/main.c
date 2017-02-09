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
void storeCourse(int courseIndex, char** result);
void myLogin();
void operator(int loginUser);
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
    char* name;
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
    // TODO: ←後で動的にする（myLogin()でreturnする
    myLogin();
    
    return 0;
}


void readFile(char *filename) {
    
    char** result;
    int indexGroup = 0; // number of groups
    int count = 1;
    
    // Open file
    FILE* file = fopen(filename, "r");
    
    if (file != NULL) {
        
        // Max length of a line = 200
        char readline[200];
        
        // Cout the number of groups of data
        while (fgets(readline, 200, file) != NULL) {
            //printf("%s\n", readline);
            if (readline[0] == '\n') {
                count++;
            }
        }
        printf("count = %d\n\n", count); // TODO: 後で消す
        
        // Allocate
        result = (char**) malloc(2 * sizeof(char)); // 2 : to store key and value
        
        // Split keys and values on each line
        rewind(file);
        while (fgets(readline, 200, file) != NULL) {
            
            if (readline[0] != '\n') {
                
                result = splitKeyValue(readline); // result : studentID, 7813007
                
                // Store to structure
                if (filename == FILE_STUDENTS || filename == FILE_STUDENTSCOURSES || filename == FILE_STUDENTS || filename == FILE_ACCOUNTS) {
                    
                    // to student
                    storeStudent(indexGroup, result); // group = order of group, result = key & value
                    
                } else if (filename == FILE_COURSES) {
                    
                    // to couse
                    storeCourse(indexGroup, result);
                }
                
            } else {
                indexGroup++;
            }
        }
    }
    fclose(file);
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
    
    // Replace from \n to \0
    readline[startIndex] = '\0';
    
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
    
    return result; // result is the pointer of keys & values
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
        students[studentIndex].name = *(result + 1);
        
    // Password
    } else if(strncmp(*result, passWord, sizeof(*passWord)) == 0) {
        students[studentIndex].passWord = *(result + 1);
        
    // Gender
    } else if(strncmp(*result, gender, sizeof(*gender)) == 0) {
        students[studentIndex].gender = *(result + 1);
        
    // Mark
    } else if(strncmp(*result, mark, sizeof(*mark)) == 0) {
        students[studentIndex].mark = *(result + 1);
        
    // Grade
    } else if(strncmp(*result, grade, sizeof(*grade)) == 0) {
        students[studentIndex].grade = *(result + 1);
       
    // Address
    } else if(strncmp(*result, address, sizeof(*address)) == 0) {
        students[studentIndex].address = *(result + 1);
        
    // Admission year
    } else if(strncmp(*result, admission_year, sizeof(*admission_year)) == 0) {
        students[studentIndex].admission_year = *(result + 1);
        
    // Courses
    } else if(strncmp(*result, courses, sizeof(*courses)) == 0) {
        students[studentIndex].courses = *(result + 1);
    }
}


void storeCourse(int courseIndex, char** result) {
    
    char *courseID = "courseID",
    *name = "name";
    
    // courseID
    if (strncmp(*result, courseID, sizeof(*courseID)) == 0) {
        course[courseIndex].courseID = *(result + 1);
        
    // Name
    } else if(strncmp(*result, name, sizeof(*name)) == 0) {
        course[courseIndex].name = *(result + 1);
    }
}

/* Login Function */

void myLogin() {
    
    // read file
    readFile(FILE_ACCOUNTS);
    
    int count = 3; // TODO: Change to a dynamic number later

    int loginUserIndex = -1,
    resultStrncmpID,
    resultStrncmpPW;
    long maxLengthID,
    maxLengthPW;
    
    // Allocate
    char* inputID = malloc(100 * sizeof(char));
    char* inputPW = malloc(100 * sizeof(char));
    
    printf("************************************************************\n");
    printf("Please enter your account to login\n");
    printf("************************************************************\n");
    
    while(loginUserIndex == -1) {
        printf("ID      : ");
        scanf("%s", inputID);
        printf("Password: ");
        scanf("%s", inputPW);
        
        for(int i = 0; i < count; i++) {
            
            // Define length of ID
            if (strlen(inputID) < strlen(students[i].studentID)) {
                maxLengthID = strlen(students[i].studentID);
                
            } else {
                maxLengthID = strlen(inputID);
            }
            
            // Define length of password
            if (strlen(inputPW) < strlen(students[i].passWord)) {
                maxLengthPW = strlen(students[i].passWord);
                
            } else {
                maxLengthPW = strlen(inputPW);
            }
            
            // Check ID & PW that has been matched                  // ↓+1で9文字分確保出来る
            resultStrncmpID = strncmp(inputID, students[i].studentID, sizeof(maxLengthID) + 1);
            resultStrncmpPW = strncmp(inputPW, students[i].passWord,  sizeof(maxLengthPW) + 1);

            // Both matched
            if(resultStrncmpID == 0 && resultStrncmpPW == 0){
                loginUserIndex = i;
            }
        }
        
        if (loginUserIndex == -1) {
            printf("\n************************************************************\n");
            printf("Your account does not exist. Please try again!\n");
            printf("************************************************************\n\n");
        }
    }

    printf("\n\n************************************************************\n");
    printf("Welcome to Cornerstone International College of Canada.\n");
    printf("************************************************************\n");

    operator(loginUserIndex);
}


void operator(int loginUserIndex) {
    
    int input = 0;
    
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
                printGPA(loginUserIndex);
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
    
    printf("\n\n************************************************************\n");
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


void printTranscript(char *loginUser) {
    
    // TODO: Print user's transcript.
    printf("Hi Mr. Peter Brown,\n");
    printf("Here is your transcript:\n");
    printf("1)MADP101: Objective-C: 80\n");
    printf("2)MADP202: Project Management: 45\n");
    printf("3)MADP301: Java Programming: 64\n");
    printf("4)MADP401: Android Programming: 70\n");
    printGPA(loginUser);
}


void printGPA(int loginUserIndex) {
    
    readFile(FILE_STUDENTS);
    readFile(FILE_STUDENTSCOURSES);

    double gpa = 0.0;
    int courseCount = 1;
    
    char *s1 = students[loginUserIndex].mark;
    char s2[] = ",";
    char *tok;

    //tok = (int)strtok(s1,s2);
    
        // ↓s1をs2で区切ったやつをtokに代入
    tok = strtok(s1,s2);
    int totalMark = atoi(tok);
    
    while(tok != NULL){

        totalMark += atoi(tok);
        tok = strtok(NULL,s2);
        courseCount++;
    }
    
    gpa = (double)totalMark / courseCount;
    
    printf("Hi Mr. ");
    printf("%s\n",students[loginUserIndex].name);
    printf("Your GPA is :");
    printf("%.2f\n\n",gpa);
}


void printRanking(char *loginUser) {
    
    readFile(FILE_STUDENTS);
    
    int i = 0;
    int ranking;
    
    // Check the order of the loginUser
    while (strncmp(loginUser, students[i].studentID, sizeof(*students[i].studentID)) == 0) {
        i++;  // ↑string(array of char)同士を比較したい時にこうやって書く
    }
    
    printf("Hi Mr. %s,\n", students[i].name);
    
    // TODO: ↓ @Mai / GPAを求める
    printGPA(loginUser);
    printf("and therefore your rank is");
    printf("%d\n",ranking);
}


void ListAllCourses() {
    
    // If the user entered ‘6’, the program will printthe list of all available courses in the college in the following format and then printthemenu.
    
    printf("List all courses\n\n");
//    
//    printf("The following courses are offered in CICCC:\n");
//    printf("1)MADP101: Objective-C\n");
//    printf("2)MADP102: Object-Oriented Programming\n");
//    printf("3)MADP201: Problem Solving\n");
//    printf("4)MADP202: Project Management\n");
//    printf("5)MADP301: Java Programming\n");
//    printf("6)MADP302: Web Development\n");
//    printf("7)MADP401: Android Programming\n");
//    printf("8)MADP402: iOS Applications\n\n");
    
    readFile(FILE_COURSES);
    
    int count = 3; // TODO: Change to a dynamic number later
    
    for(int i = 0; i < count; i++){
        printf("%d)%s: %s\n", i + 1, course[i].courseID, course[i].name);
    }
    printf("\n");
}


void ListAllStudents() {
    
    // If the user enters ‘7’, the program will printthe list of all students in the college in the following format and then printthe menu.
    
    printf("List all students\n\n");
    
//    printf("There are 4 students in CICCC as following:\n");
//    printf("1)Peter Brown: 7813007\n");
//    printf("2)Joseph Rod: 812345\n");
//    printf("3)Cristina Li: 8012333\n");
//    printf("4)Adams Wang: 7812999\n\n");
    
    readFile(FILE_STUDENTS);
    
    int count = 3; // TODO: Change to a dynamic number later
    
    for(int i = 0; i < count; i++){
        printf("%d)%s: %s\n", i + 1, students[i].name, students[i].studentID);
    }
}


void myLogout() { // MEMO: ←logout()は予約語のようなので、代わりにmyLogoutにした。
    
    // TODO: Call login function
    
    // If the user entered‘8’, the program will print the login menu and let the user login again with the same or different account.
    printf("Logout! Thank you.\n\n");
}
