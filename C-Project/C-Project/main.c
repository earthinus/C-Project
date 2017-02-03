//
//  main.c
//  C-Project
//
//  Created by Mai & Maki on 2017-02-02.
//

#include <stdio.h>

void login();
void listAvarableCourses();
void listStudents();
void logOut();

char userInputName,userInputPassword;
int i;

typedef struct student{
    char* studentID;
    char* firstName;
    char* lastName;
    char* passWord;
    char gender;
    double gpa;
    char* address;
    int admission_year;
    char* course;
}STUDENT;

STUDENT students[9] = {
    {"taro123","Taro","Tanaka","pass1",'m',3.5,"Tokyo",2010,"IT"},
    {"ohana8","Hana","Yamada","pass2",'f',3.3,"Osaka",2011,"IT"},
    {"mary68","Mary","Smith","pass3",'f',3.4,"Kyoto",2012,"Literature"},
    {"katy14","Kate","Muller","pass4",'f',3.1,"Vancouver",2012,"Management"},
    {"johnnn","John","Duno","pass5",'m',3.0,"Madrid",2012,"Literature"},
    {"littleamy","Amy","Brown","pass6",'f',3.4,"Rome",2012,"Literature"},
    {"jack21","Jackey","Cheng","pass7",'f',3.2,"Paris",2012,"Literature"},
    {"lenasan","Lena","Maria","pass8",'f',3.6,"London",2012,"Literature"},
};

int main(int argc, const char * argv[]) {
    
    void login();
    void listStudents();
    void logOut();
    
    return 0;
}

/* Login Function */

void login(){
    
    printf("************************************************************");
    printf("Please enter your account to login");
    printf("************************************************************");
    scanf("Username:%c",&userInputName);
    scanf("Password:%c",&userInputPassword);
    
    if(userInputName == students[i].firstName && userInputPassword == students[i].passWord){
        printf("************************************************************");
        printf("Welcome to Cornerstone International College of Canada.");
        printf("************************************************************");
    }else{
        printf("************************************************************");
        printf("Your account does not exist. Please try again!");
        printf("************************************************************");
    }

}

void listAvarableCourses(){
    
    /*   option(6) List all courses   */
    printf("Avarable courses are:\n");
    
    for(int i = 0;i < 4;i++){
        printf("%c\n",students[i].course);
    }
}

void listStudents(){
    
    /*   option(7) List all students   */
    for(int i = 0; i < 8; i++){
        printf("First name:%c\n", students[i].firstName);
        printf("Last name:%c\n", students[i].lastName);
        printf("Student ID:%c\n", students[i].studentID);
        printf("Gender:%c\n", students[i].gender);
        printf("------------------\n");
    }

}


void logOut(){
    /*   option(8) Log out   */
    
}








