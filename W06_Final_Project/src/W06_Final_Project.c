/*
 ============================================================================
 Name        : W06_Final_Project.c
 Author      : Brayden Stokes
 Version     :
 Copyright   : Your copyright notice
 Description : Password Validation in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int spec_chars(char pw[], int n, int *a){
	int i, specflag = 0;
	//checks each character in the password to see if it includes a special character
   for (i = 0; i < n; ++i){
      if(pw[i] == '!' || pw[i] == '@' || pw[i] == '#' || pw[i] == '$'
      || pw[i] == '%' || pw[i] == '^' || pw[i] == '&' || pw[i] == '*'
      || pw[i] == '(' || pw[i] == ')' || pw[i] == '-' || pw[i] == '{'
      || pw[i] == '}' || pw[i] == '[' || pw[i] == ']' || pw[i] == ':'
      || pw[i] == ';' || pw[i] == '"' || pw[i] == '\'' || pw[i] == '<'
      || pw[i] == '>' || pw[i] == '.' || pw[i] == '/' || pw[i] == '?'
      || pw[i] == '~' || pw[i] == '`' ){
    	  specflag = 1; //requirement passed
    	  break;
      }
   }

   if (specflag == 0){
	   *a = 0; //if there is no special character
   }
   else if (specflag == 1) {
	   *a = 1; //requirement passed
   }
return 0;
}



int caps_chars(char pw[], int n, int *b){
	int i, capflag = 0;
	// checks each character in the password to see if it includes a capital letter
	for (i = 0; i <n; ++i) {
		if(pw[i] == 'A' || pw[i] == 'B' || pw[i] == 'C' || pw[i] == 'D'
		|| pw[i] == 'E' || pw[i] == 'F' || pw[i] == 'G' || pw[i] == 'H'
		|| pw[i] == 'I' || pw[i] == 'J' || pw[i] == 'K' || pw[i] == 'L'
		|| pw[i] == 'M' || pw[i] == 'N' || pw[i] == 'O' || pw[i] == 'P'
		|| pw[i] == 'Q' || pw[i] == 'R' || pw[i] == 'S' || pw[i] == 'T'
		|| pw[i] == 'U' || pw[i] == 'V' || pw[i] == 'W' || pw[i] == 'X'
		|| pw[i] == 'Y' || pw[i] == 'Z'){
			capflag = 1; //requirement passed
			break;
		}
	}
	if (capflag == 0){
		*b = 0; //if there is not a caps letter
	}
	else if (capflag == 1) {
		*b = 1; //requirement passed
	}
return 0;
}

int lower_chars(char pw[], int n, int *c){
	int i, lowflag = 0;
	// checks each character in the password to see if it includes a lowercase letter
	for (i = 0; i <n; ++i) {
		if(pw[i] == 'a' || pw[i] == 'b' || pw[i] == 'c' || pw[i] == 'd'
		|| pw[i] == 'e' || pw[i] == 'f' || pw[i] == 'g' || pw[i] == 'h'
		|| pw[i] == 'i' || pw[i] == 'j' || pw[i] == 'k' || pw[i] == 'l'
		|| pw[i] == 'm' || pw[i] == 'n' || pw[i] == 'o' || pw[i] == 'p'
		|| pw[i] == 'q' || pw[i] == 'r' || pw[i] == 's' || pw[i] == 't'
		|| pw[i] == 'u' || pw[i] == 'v' || pw[i] == 'w' || pw[i] == 'x'
		|| pw[i] == 'y' || pw[i] == 'z'){
			lowflag = 1; //requirement passed
			break;
		}
	}
	if (lowflag == 0){
		*c = 0; //if there is not a lowercase letter
	}
	else if (lowflag == 1) {
		*c = 1; //requirement passed
	}
return 0;
}

int number(char pw[], int n, int *d){
	int i, numflag = 0;
	// checks each character in the password to see if it includes a number
	for (i = 0; i <n; ++i) {
		if(pw[i] == '1' || pw[i] == '2' || pw[i] == '3' || pw[i] == '4'
		|| pw[i] == '5' || pw[i] == '6' || pw[i] == '7' || pw[i] == '8'
		|| pw[i] == '9' || pw[i] == '0') {
			numflag = 1; //requirement passed
			break;
		}
	}
	if (numflag == 0){
		*d = 0; //if there is not a number
	}
	else if (numflag == 1) {
		*d = 1; //requirement passed
	}
return 0;
}

int change_requirements(int *f, int *g, int *h, int *i, int *j){
	printf("Enter 1 for true, 0 for false for each of the following criteria:\n");
	printf("A Special Character is Required\n");
	scanf("%d", &*f);
	printf("A Capital Letter is Required\n");
	scanf("%d", &*g);
	printf("A Lowercase Letter is Required\n");
	scanf("%d", &*h);
	printf("A Number is Required\n");
	scanf("%d", &*i);
	printf("What is the minimum length requirement?\n");
	scanf("%d", &*j);
return 0;
}

int test_pw(char pw[], int n, int min_length, int req_spec_char, int req_cap_let, int req_low_let, int req_num){
	//variables used to verify if the password meets requirements
	int req1 = 1; //special character
	int req2 = 1; //capital letter
	int req3 = 1; //lowercase letter
	int req4 = 1; //number

	if(req_spec_char == 1){
		spec_chars(pw, n, &req1);
	}
	if(req_cap_let == 1){
		caps_chars(pw, n, &req2);
	}
	if(req_low_let ==1){
		lower_chars(pw, n, &req3);
	}
	if(req_num == 1){
		number(pw, n, &req4);
	}
	if(req1==1 && req2==1 && req3==1 && req4==1 && n>=min_length){
		printf("Your Password is valid.\n");
	}
	else{
		printf("Your Password is NOT valid.\n");
	}
return 0;
}

int options(char pw[],int min_length,int req_spec_char,int req_cap_let,int req_low_let,int req_num){
	int selection = 0;
	printf("\n What would you like to do?\n");
	printf("1. Test a Password\n");
	printf("2. View Current Password Requirements\n");
	printf("3. Change Password Requirements\n");
	printf("4. Close the program\n");
	scanf("%d", &selection);

	switch (selection)
		{
		case 1: //test
			printf("Enter your Password: ");
			scanf("%s", &*pw);
			int n = strlen(pw);
			test_pw(pw, n, min_length, req_spec_char, req_cap_let, req_low_let, req_num);
			options(pw, min_length, req_spec_char, req_cap_let, req_low_let, req_num);
			break;
		case 2: //view
			printf("1 = True, 0 = False\n");
			printf("Special Character Required: %d\n", req_spec_char);
			printf("Capital Letter Required: %d\n", req_cap_let);
			printf("Lowercase Letter Required: %d\n", req_low_let);
			printf("Number Required: %d\n", req_num);
			printf("Minimum Length: %d\n", min_length);
			options(pw, min_length, req_spec_char, req_cap_let, req_low_let, req_num);
			break;
		case 3: //change requirements
			change_requirements(&req_spec_char, &req_cap_let, &req_low_let, &req_num, &min_length);
			options(pw, min_length, req_spec_char, req_cap_let, req_low_let, req_num);
			break;
		case 4: //quit
			printf("Have a nice day.");
			break;
		default: //invalid option
			printf("Please Try again.\n");
			options(pw, min_length, req_spec_char, req_cap_let, req_low_let, req_num);
		}
		while (1) {}
return 0;
}

int main(void) {

	char pw[] = {""};
		//Password requirements that can be changed by user
	int req_spec_char = 1;
	int req_cap_let = 1;
	int req_low_let = 1;
	int req_num = 1;
	int min_length = 10;

	options(pw, min_length, req_spec_char, req_cap_let, req_low_let, req_num);

	return EXIT_SUCCESS;
}
