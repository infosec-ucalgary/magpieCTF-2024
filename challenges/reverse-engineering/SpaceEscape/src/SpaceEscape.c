#include <stdio.h>
#include <string.h>

char choice[30];
int result;
char left[5] = "left";
char right[6] = "right";
char password[20] = "r4r2";
char try[20];
char array[20] = "0Yr3Rvd1AM_S";


// referenced from https://www.geeksforgeeks.org/xor-cipher/

void encrypt(char inputstring[]){
    int length = strlen(inputstring);

    char xorkey = 'F';

    for (int i = 0; i < length; i++)
    {
        inputstring[i] = inputstring[i] ^ xorkey;
        printf("%c", inputstring[i]);
    }
}


int r4r1(){
    return 0;
}

int correctpath3(){
    printf("Awesome! You have arrived at the mainframe. \nYou rush to the main terminal to shut off HOL 8000, but it seems that there is a security passcode in place. You will have to enter the passcode to proceed, but you only have one attempt. \n");
    scanf("%s", try);
    result = strcmp(try, password);
    if (result == 0){
        printf("Success, you did it! HOL 8000 is disabled, now you can start on fixing up the ship and planning a course to to Earth. \n");
        printf("magpie{");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", array[7], array[9], array[10], array[11], array[0], array[2], array[4], array[1], array[10], array[6], array[8], array[5], array[3], '}');
        scanf("%s", try);
    } else {
        printf("Oh, that wasn't correct. HOL 8000 has now shut off your access, looks like this is the end. \n");
        scanf("%s", try);
    }
    return 0;
}

int r4r3(){

    printf("Game over, you've reached a dead end.");
    scanf("%s", try);
    return 0;
}

int r4r4(){

    printf("Game over, you've reached a dead end.");
    scanf("%s", try);
    return 0;
}

int r4r5(){

    printf("Game over, you've reached a dead end.");
    scanf("%s", try);
    return 0;
}

int r4r6(){

    printf("Game over, you've reached a dead end.");
    scanf("%s", try);
    return 0;
}

int r4r7(){

    printf("Game over, you've reached a dead end. Remember you're starting from the root and traveling forward from there.");
    scanf("%s", try);
    return 0;
}

int r4r8(){

    printf("Game over, you've reached a dead end.");
    scanf("%s", try);
    return 0;
}

int correctpath2(){
    printf("You are in the maintenance corridors. Nothing is operational, not even the lights. There is a room to the right and to the left of you. \n");
    printf("Which way would you like to go? (enter right or left): \n");
    scanf("%s", choice);
    result = strcmp(choice, left);
    if (result == 0){
        r4r1();
    } else {
        result = strcmp(choice, right);
        if (result == 0){
            correctpath3();
        } else {
            printf("Invalid choice. HOL 8000 blows you up I guess.");
        }
    return 0;
    }
}

int r3r2(){
    printf("You are in the research centre. Unfortunately all the terminals and equipment here are completely disabled. There is a room to the right and to the left of you. \n");
    printf("Which way would you like to go? (enter right or left): \n");
    scanf("%s", choice);
    result = strcmp(choice, left);
    if (result == 0){
        r4r3();
    } else {
        result = strcmp(choice, right);
        if (result == 0){
            r4r4();
        } else {
            printf("Invalid choice. HOL 8000 blows you up I guess.");
        }
    return 0;
    }
}

int r3r3(){
    printf("You are in the medical bay. You don't dare to take a closer look around. There is a room to the right and to the left of you. \n");
    printf("Which way would you like to go? (enter right or left): \n");
    scanf("%s", choice);
    result = strcmp(choice, left);
    if (result == 0){
        r4r5();
    } else {
        result = strcmp(choice, right);
        if (result == 0){
            r4r6();
        } else {
            printf("Invalid choice. HOL 8000 blows you up I guess.");
        }
    return 0;
    }
}

int r3r4(){
    printf("You are in the viewing room. Looking out at stars through the window provides you some comfort. There is a room to the right and to the left of you. \n");
    printf("Which way would you like to go? (enter right or left): \n");
    scanf("%s", choice);
    result = strcmp(choice, left);
    if (result == 0){
        r4r7();
    } else {
        result = strcmp(choice, right);
        if (result == 0){
            r4r8();
        } else {
            printf("Invalid choice. HOL 8000 blows you up I guess.");
        }
    return 0;
    }
}

int correctpath1(){
    printf("You are in the break room. Thank goodness, your Namco Galaxian arcade system is still completely intact. But now is not the time. There is a room to the right and to the left of you.\n");
    printf("Which way would you like to go? (enter right or left): \n");
    scanf("%s", choice);
    result = strcmp(choice, left);
    if (result == 0){
        correctpath2();
    } else {
        result = strcmp(choice, right);
        if (result == 0){
            r3r2();
        } else {
            printf("Invalid choice. HOL 8000 blows you up I guess.");
        }
    return 0;
    }
}

int r2r2(){
    printf("You are in the crew quarters. There is a room to the right and to the left of you.There is an eerie lack of anyone’s presence as you navigate past fallen-over lockers and debris. \n");
    printf("Which way would you like to go? (enter right or left): \n");
    scanf("%s", choice);
    result = strcmp(choice, left);
    if (result == 0){
        r3r3();
    } else {
        result = strcmp(choice, right);
        if (result == 0){
            r3r4();
        } else {
            printf("Invalid choice. HOL 8000 blows you up I guess.");
        }
    return 0;
    }
}

int r1(){
    printf("You are starting out in the bridge. There is a room to the right and to the left of you. \n");
    printf("Which way would you like to go? (enter right or left): \n");
    scanf("%s", choice);
    result = strcmp(choice, left);
    if (result == 0){
        correctpath1();
    } else {
        result = strcmp(choice, right);
        if (result == 0){
            r2r2();
        } else {
            printf("Invalid choice. HOL 8000 blows you up I guess.");
        }
    return 0;
    }
}


int main(){
    printf("Uh oh! Looks like the AI supercomputer HOL 8000 (definitely not an off-brand) has locked you inside your space craft. You have to sneak in to the mainframe from your current location and disable him \n");
    printf("\nYou know the following hint: the layout of this ship is just like an upside-down balanced binary search tree. Your starting room, the bridge, is the root. You'll be traveling forward from there.");
    printf("The mainframe is the second highest value in the 'tree'. The 'tree' has depth 3.\n \nBe wary of any destination that isn't the mainframe, bad things may await.");
    r1();
    return 0;
}
