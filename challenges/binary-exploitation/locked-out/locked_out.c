#include <stdio.h>
#include <string.h>
#include <regex.h>

#define PASSWORD_LENGTH 16
#define FLAG_LENGTH 32

int login() {
  char *pattern = "give_[a-z]{5}_flag";

  regex_t regex;
  if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
    fprintf(stderr, "Failed to compile regex\n");
    return 1;
  }

  char pass[PASSWORD_LENGTH];
  char input[PASSWORD_LENGTH];

  FILE *pass_file = fopen("pass.txt", "r"); 
  fgets(pass, PASSWORD_LENGTH, pass_file);  

  printf("Password: ");
  fflush(stdout);
  gets(input);

  if (regexec(&regex, pass, 0, NULL, 0) == 0) {
    printf("Password matches! Logging in...\n");
    regfree(&regex);
    return 1;
  }
  regfree(&regex);
  return 0;
}

int main() {
  printf("             ________________________________________________\n");
  printf("            /                                                \\\n");
  printf("           |    _________________________________________     |\n");
  printf("           |   |                                         |    |\n");
  printf("           |   |                                         |    |\n");
  printf("           |   |                                         |    |\n");
  printf("           |   |                                         |    |\n");
  printf("           |   |                                         |    |\n");
  printf("           |   |           Incorrect password.           |    |\n");
  printf("           |   |            Please try again.            |    |\n");
  printf("           |   |                                         |    |\n");
  printf("           |   |                                         |    |\n");
  printf("           |   |                                         |    |\n");
  printf("           |   |                                         |    |\n");
  printf("           |   |_________________________________________|    |\n");
  printf("           |                                                  |\n");
  printf("           \\_________________________________________________/\n");
  printf("                   \\___________________________________/\n");
  printf("                ___________________________________________\n");
  printf("             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_  \n");
  printf("          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_  \n");
  printf("       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_  \n");
  printf("    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_  \n");
  printf(":-------------------------------------------------------------------------:\n");
  printf("`---._.-------------------------------------------------------------._.---'\n");
  printf("I seem to be locked out. Could you help me login?\n"); 
  fflush(stdout);

  if (login()) {
    printf("Logged in successfully!\n");
    
    char flag[FLAG_LENGTH];
    FILE *flag_file = fopen("flag.txt", "r"); 
    fgets(flag, FLAG_LENGTH, flag_file);  

    printf("Here is your reward for helping me!\n%s", flag);
  } else {
    printf("Too many attempts. Please try again!");
  }
}


