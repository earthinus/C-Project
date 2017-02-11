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

void readFile();
char** splitKeyValue();
void storeStudent();
void storeCourse();
char* getHonorificTitle();
double getGPA();
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
} courses[7];


int main(int argc, const char * argv[]) {
    
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
        //printf("count = %d\n\n", count); // TODO: 後で消す
        
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
    
    // Count until the end of the line (which means until getting '\n' or '\0')
    while (readline[startIndex] != '\n' && readline[startIndex] != '\0') {
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
    *passWord = "password",
    *gender = "gender",
    *mark = "mark",
    *grade = "grade",
    *address = "address",
    *admission_year = "admission_year",
    *courses = "courses",
    *courseID = "courseID";
    
    // studentID
    if (strncmp(*result, studentID, strlen(studentID)) == 0) {
        students[studentIndex].studentID = *(result + 1);
        
    // Name
    } else if(strncmp(*result, name, strlen(name)) == 0) {
        students[studentIndex].name = *(result + 1);
        
    // Password
    } else if(strncmp(*result, passWord, strlen(passWord)) == 0) {
        students[studentIndex].passWord = *(result + 1);
        
    // Gender
    } else if(strncmp(*result, gender, strlen(gender)) == 0) {
        students[studentIndex].gender = *(result + 1);
        
    // Mark
    } else if(strncmp(*result, mark, strlen(mark)) == 0) {
        students[studentIndex].mark = *(result + 1);
        
    // Grade
    } else if(strncmp(*result, grade, strlen(grade)) == 0) {
        students[studentIndex].grade = *(result + 1);
       
    // Address
    } else if(strncmp(*result, address, strlen(address)) == 0) {
        students[studentIndex].address = *(result + 1);
        
    // Admission year
    } else if(strncmp(*result, admission_year, strlen(admission_year)) == 0) {
        students[studentIndex].admission_year = *(result + 1);
        
    // Courses or CourseID
    } else if(strncmp(*result, courses, strlen(courses)) == 0 || strncmp(*result, courseID, strlen(courseID)) == 0) {
        students[studentIndex].courses = *(result + 1);
    }
}


void storeCourse(int courseIndex, char** result) {
    
    char *courseID = "courseID",
    *name = "name";
    
    // courseID
    if (strncmp(*result, courseID, sizeof(*courseID)) == 0) {
        courses[courseIndex].courseID = *(result + 1);
        
    // Name
    } else if(strncmp(*result, name, sizeof(*name)) == 0) {
        courses[courseIndex].name = *(result + 1);
    }
}

char *getHonorificTitle(char* gender) {
    
    char *honorificTitle,
    *male   = "male",
    *female = "female";
    
    if (strcmp(gender, male) == 0) {
        honorificTitle = malloc(strlen(male) * sizeof(char));
        honorificTitle = "Mr.";
        
    } else if (strcmp(gender, female) == 0) {
        honorificTitle = malloc(strlen(female) * sizeof(char));
        honorificTitle = "Ms.";
    }
    return honorificTitle;
}


double getGPA(int studentIndex) {
    
    int courseCount = 0;
    char *comma = ",";
    char *copyMark = (char*)malloc(strlen(students[studentIndex].mark) + 1);
    strcpy(copyMark,students[studentIndex].mark);
    
    
    // Split string of student's mark by comma
    char *token = strtok(copyMark, comma);
    
    int totalMark = 0;
    
    while(token != NULL){
        
        totalMark += atoi(token);
        token = strtok(NULL, comma);
        courseCount++;
    }
    
    double gpa = (double)totalMark / courseCount;
    return gpa;
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
            
            // Get length of ID
            if (strlen(inputID) < strlen(students[i].studentID)) {
                maxLengthID = strlen(students[i].studentID);
                
            } else {
                maxLengthID = strlen(inputID);
            }
            
            // Get length of password
            if (strlen(inputPW) < strlen(students[i].passWord)) {
                maxLengthPW = strlen(students[i].passWord);
                
            } else {
                maxLengthPW = strlen(inputPW);
            }
            
            // Check ID & PW have been matched
            resultStrncmpID = strncmp(inputID, students[i].studentID, maxLengthID);
            resultStrncmpPW = strncmp(inputPW, students[i].passWord,  maxLengthPW);

            // Both matched
            if (resultStrncmpID == 0 && resultStrncmpPW == 0) {
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
    
    while (input != 8 && input != 9) {
        
        printMenu();
        
        scanf("%d", &input);
        
        switch (input) {
            case 1:
                printEnrolment(loginUserIndex);
                break;
                
            case 2:
                printCourses(loginUserIndex);
                break;
                
            case 3:
                printTranscript(loginUserIndex);
                break;
                
            case 4:
                printGPA(loginUserIndex);
                break;
                
            case 5:
                printRanking(loginUserIndex);
                break;
                
            case 6:
                ListAllCourses();
                break;
                
            case 7:
                ListAllStudents();
                break;
                
            case 8:
                printf("Logout! Thank you.\n\n");
                myLogin();
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
    
    printf("\n************************************************************\n");
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


void printEnrolment(int loginUserIndex) {
    
    readFile(FILE_STUDENTS);
    readFile(FILE_COURSES);

    // Get "Mr" or "Ms"
    char *honorificTitle = getHonorificTitle(students[loginUserIndex].gender);

    // Count user's courses
    int coursesCount;
    char* token = strtok(students[loginUserIndex].courses, ",");
    while (token != NULL) {
        coursesCount++;
        token = strtok(NULL, ",");
    }
    
    printf("\nDear Sir/Madam,\n\n");
    printf("Hi %s %s,\n", honorificTitle, students[loginUserIndex].name);
    printf("This is to certify that %s %s with student id %s is a student at grade %s at CICCC. ", honorificTitle, students[loginUserIndex].name, students[loginUserIndex].studentID, students[loginUserIndex].grade);
    printf("He/She was admitted to our college in %s and has taken %d course(s). ", students[loginUserIndex].admission_year, coursesCount);
    printf("Currently he/she resides at %s.\n\n", students[loginUserIndex].address);
    printf("If you have any question, please don’t hesitate to contact us.");
    printf("\n\nThanks,\nWilliams,\n");
}


void printCourses(int loginUserIndex) {
    // Prints all the courses the student has taken in the following format. And then printsthe above main menu again.
    
    readFile(FILE_STUDENTS);
    readFile(FILE_COURSES);
    
    char *honorificTitle = getHonorificTitle(students[loginUserIndex].gender);
    
    printf("Hi %s %s,\n", honorificTitle, students[loginUserIndex].name);
    printf("You have taken the following courses:\n");
    
    int no = 1,
    cousesCount = 7; // TODO:あとで動的にする
    char comma[] = ",",
    *token = strtok(students[loginUserIndex].courses, comma);
    
    while(token != NULL) {
        
        for (int i = 0; i < cousesCount; i++) {
            if (strncmp(token, courses[i].courseID, strlen(token)) == 0) {
                printf("%d)%s: %s\n", no, token, courses[i].name);
            }
        }
        
        token = strtok(NULL, comma);  // for after second time loop
        no++;
    }
}


void printTranscript(int loginUserIndex) {
    
    readFile(FILE_STUDENTS);
    readFile(FILE_STUDENTSCOURSES);
    readFile(FILE_COURSES);
    
    // Get "Mr" or "Ms"
    char *honorificTitle = getHonorificTitle(students[loginUserIndex].gender);
    
    
    int cousesCount = 1;
    char *comma = ",";
    char *strCouses = (char*) malloc(strlen(students[loginUserIndex].courses) + 1);
    if (strCouses == NULL) {
        return;
    }
    char *strMarks = (char*) malloc(strlen(students[loginUserIndex].mark) + 1);
    if (strMarks == NULL) {
        return;
    }
    
    // Copy couseID before split to keep the original data
    strcpy(strCouses, students[loginUserIndex].courses);
    strcpy(strMarks,  students[loginUserIndex].mark);
    
    // Count the number of couseID to allocate
    for(int m = 0; m < strlen(strCouses); m++) {
        if(strCouses[m] == *comma) {
            cousesCount++;
        }
    }
    
    // Split copied couseID by comma
    char *token = strtok(strCouses, comma);
    
    char **arrCourseIDs,
    **arrCourseNames,
    **arrMarks;
    
    // Allocate
    arrCourseIDs = (char**) malloc(cousesCount * sizeof(char*));
    arrCourseNames = (char**) malloc(cousesCount * sizeof(char*));
    arrMarks = (char**) malloc(cousesCount * sizeof(char*));
    if (arrCourseIDs == NULL) {
        return;
    }
    if (arrCourseNames == NULL) {
        return;
    }
    if (arrMarks == NULL) {
        return;
    }
    
    // Define arrays of courseID and couseName
    int i = 0;
    while(token != NULL) {
        
        arrCourseIDs[i] = token;
        
        for (int j = 0; j < 7; j++) {
            
            // if courseID of token matches with courseID, get the name of the course.
            if (strncmp(token, courses[j].courseID, strlen(token)) == 0) {
                arrCourseNames[i] = courses[j].name;
                break;
            }
        }
        
        token = strtok(NULL, comma);  // for after second time loop
        i++;
    }
    
    // Define arrays of mark
    char *token2 = strtok(strMarks, comma);
    int k = 0;
    while(token2 != NULL) {
        
        arrMarks[k] = token2;
        token2 = strtok(NULL, comma);  // for after second time loop
        k++;
    }
    
    // Print
    printf("\nHi %s %s,\n", honorificTitle, students[loginUserIndex].name);
    printf("Here is your transcript:\n");
    
    for (int no = 0; no < cousesCount; no++) {
        printf("%d)%s: %s: %s\n", no + 1, arrCourseIDs[no], arrCourseNames[no], arrMarks[no]);
    }
    
    printf("Your GPA is %.2f\n\n", getGPA(loginUserIndex));
    
//    printf("1)MADP101: Objective-C: 80\n");
//    printf("2)MADP202: Project Management: 45\n");
//    printf("3)MADP301: Java Programming: 64\n");
//    printf("4)MADP401: Android Programming: 70\n");
    
    free(strCouses);
    free(arrCourseIDs);
    free(arrCourseNames);
    free(arrMarks);
}


void printGPA(int loginUserIndex) {
    
    readFile(FILE_STUDENTS);
    readFile(FILE_STUDENTSCOURSES);
    
    printf("Hi Mr. %s\n",students[loginUserIndex].name);
    printf("Your GPA is %.2f\n\n", getGPA(loginUserIndex));
}


void printRanking(int loginUserIndex) {
    
    readFile(FILE_STUDENTS);
    readFile(FILE_STUDENTSCOURSES);
    
    int i, j;
    int rank = 0;
    double tmp;
    double number[3] = {getGPA(0),getGPA(1),getGPA(2)};
    
    for (i = 0; i < 3;++i) {
        for (j = i + 1;j < 3; ++j) {
            if (number[i] < number[j]) {
                tmp =  number[i];
                number[i] = number[j];
                number[j] = tmp;
            }
        }
    }
    
    printf("Hi Mr. %s,\n", students[loginUserIndex].name);
    printf("Your GPA is %.2f\n\n", getGPA(loginUserIndex));

    printf("All Students GPA Ranking:\n\n");
    for (i = 2; i >= 0;--i){
        printf("%.2f\n\n", number[i]);
        if(number[i] == getGPA(loginUserIndex)){
            rank = i + 1;
        }
    }
    printf("and therefore your rank is %d\n\n",rank);
}


void ListAllCourses() {
    
    // If the user entered ‘6’, the program will printthe list of all available courses in the college in the following format and then printthemenu.
    
    printf("List all courses\n\n");
    
    readFile(FILE_COURSES);
    
    int count = 7; // TODO: Change to a dynamic number later
    
    for(int i = 0; i < count; i++){
        printf("%d)%s: %s\n", i + 1, courses[i].courseID, courses[i].name);
    }
    printf("\n");
}


void ListAllStudents() {
    
    // If the user enters ‘7’, the program will printthe list of all students in the college in the following format and then printthe menu.
    
    printf("List all students\n\n");
    
    readFile(FILE_STUDENTS);
    
    int count = 3; // TODO: Change to a dynamic number later
    
    for(int i = 0; i < count; i++){
        printf("%d)%s: %s\n", i + 1, students[i].name, students[i].studentID);
    }
}
