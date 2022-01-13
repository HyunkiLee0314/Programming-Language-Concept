#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//define each tokens as unique number

#define DOLLAR 01
#define AT 02
#define PERCENT 03

#define DOUBLE_QUOTE 04

#define SINGLE_QUOTE 05


#define UNSIGNEDL 06
#define UNSIGNEDC 07
#define LONGL 40
#define LONGC 41
#define LONG_LONGL 10
#define LONG_LONGC 11

#define DOT 42
#define FLOATING_SUFFL 12
#define FLOATING_SUFFC 13
#define FLOATING_SUFLL 14
#define FLOATING_SUFLC 15


#define PLUS 16
#define EQUAL 17
#define MINUS 18
#define DIVISION 19
#define MULTI 20
#define MODULO 21
#define NOT 22
#define OPEN_CODE 23
#define CLOSE_CODE 24
#define OPEN_FUNC 25
#define CLOSE_FUNC 26
#define INCRE 27
#define DECRE 28
#define AND 29
#define OR 30
#define SPACE 31

#define IDENTIFIER 32
#define DIGIT 33
#define FLOATING 34

#define TOTAL 35

int numOfToken = 0;

//Create struct frame
struct list{
	char pick[35];
	int token;
};
//Type struct elements
struct list reference[TOTAL] = {
	{"$", DOLLAR},
	{"@", AT},
	{"%", PERCENT},
	
	{"\"", DOUBLE_QUOTE},
	
	{"'", SINGLE_QUOTE},
	
	{"u", UNSIGNEDL},
	{"U", UNSIGNEDC},
	{"l", LONGL},
	{"L", LONGC},
	{"ll", LONG_LONGL},
	{"LL", LONG_LONGC},
	
	{".", DOT},
	{"f", FLOATING_SUFFL},
	{"F", FLOATING_SUFFC},
	{"l", FLOATING_SUFLL},
	{"L", FLOATING_SUFLC},
	
	{"+", PLUS},
	{"=", EQUAL},
	{"-", MINUS},
	{"/", DIVISION},
	{"*", MULTI},
	{"%", MODULO},
	{"!", NOT},
	{":", OPEN_CODE},
	{";", CLOSE_CODE},
	{"(", OPEN_FUNC},
	{")", CLOSE_FUNC},
	{"++", INCRE},
	{"--", DECRE},
	{"&&", AND},
	{"||", OR},
	
};
// tokens category that where the tokens belong to (This is related to reference struct)
char tokenCategory[TOTAL+1][50]={
" ",
"Perl Style ID",
"Perl Style ID",
"Perl Style ID",

"Java Style String Literals",

"C Style Character Literals",

"C Style Integer Literals",
"C Style Integer Literals",
"C Style Integer Literals",
"C Style Integer Literals",
"C Style Integer Literals",
"C Style Integer Literals",

"C Style Floating point Literals",
"C Style Floating point Literals",
"C Style Floating point Literals",
"C Style Floating point Literals",
"C Style Floating point Literals",

"Non-Alphanumeric Special Symbols",
"Non-Alphanumeric Special Symbols",
"Non-Alphanumeric Special Symbols",
"Non-Alphanumeric Special Symbols",
"Non-Alphanumeric Special Symbols",
"Non-Alphanumeric Special Symbols",
"Non-Alphanumeric Special Symbols",
"Non-Alphanumeric Special Symbols",
"Non-Alphanumeric Special Symbols",
"Non-Alphanumeric Special Symbols",
"Non-Alphanumeric Special Symbols",
"Non-Alphanumeric Special Symbols",
"Non-Alphanumeric Special Symbols",
"Non-Alphanumeric Special Symbols",
"Non-Alphanumeric Special Symbols",

"Perl Style ID",
"C Style Integer Literals",
"C Style Floating point Literals",

};

//Finding tokens
int parsing(char lex[]){
	int i;
	for (i = 0; i < TOTAL; i++){
		if(strcmp(lex,reference[i].pick) == 0){
			return reference[i].token;
		}
	}
	return IDENTIFIER;
	
}


//function for printing result
void printResult(int num, char temp[]){
	printf("\n");
	printf("\t\t\t\t%d\t\t\t%s is %s\n",num,temp,tokenCategory[num]);
}

//function for lexical analyzer
void lexi(char temp[], int tempLength){
	int i,j,k;
	int line = 2;
	char c,next;
	char lex[30];
	char z[300];
	//Tokenizing.
	for(i=0; i < tempLength;){
		c = temp[i];
		
		for(j=0; j<10; j++){
			z[j]='\0';
		}
		
		j=0;
		z[j++]=temp[i];
		z[j]='\0';
		
		//Using switch-case to distinguish each token
		switch(c){
			case' ':
				i++;
				printf("\n");
				break;
				
			case'\t':
				i++;
				printf("\n");
				break;
			
			case '$':
				i++;
				printResult(DOLLAR,z);
				break;
				
			case '@':
				i++;
				printResult(AT,z);
				break;
				
			case '%':
				i++;
				printResult(PERCENT,z);
				break;
				
			case '\"':
				i++;
				printResult(DOUBLE_QUOTE,z);
				break;
			
			case '.':
				i++;
				printResult(DOT,z);
				break;
			
			case '-':
				next = temp[++i];
				if(next=='-'){
					i++;
					printResult(DECRE,z);
					break;
				}else{
					i++;
					printResult(MINUS,z);
					break;
				}
			
			case '+':
				next = temp[++i];
				if(next=='+'){
					i++;
					printResult(INCRE,z);
					break;
				}else{
					i++;
					printResult(PLUS,z);
					break;
				}
				
				
			case '=':
				i++;
				printResult(EQUAL,z);
				break;
			
			case '/':
				i++;
				printResult(DIVISION,z);
				break;
				
			case '*':
				i++;
				printResult(MULTI,z);
				break;
				
			case '!':
				i++;
				printResult(NOT,z);
				break;
				
			case ':':
				i++;
				printResult(OPEN_CODE,z);
				break;
				
			case ';':
				i++;
				printResult(CLOSE_CODE,z);
				break;
				
			case '(':
				i++;
				printResult( OPEN_FUNC,z);
				break;
				
			case ')':
				i++;
				printResult(CLOSE_FUNC,z);
				break;
				
			case '&':
				i++;
				printResult(AND,z);
				break;
			
			case '|':
				i++;
				printResult(OR,z);
				break;
				
			//Set the default tokens. The two categories are alphabet and digits
			default:
				if(isalpha(temp[i])){
					k =0;
					while(isalpha(temp[i])){
						lex[k++] = temp[i++];
					}
					lex[k]='\0';
					printResult(parsing(lex),lex);
					break;
				
				//if the digit comes first. print an error.
				} if(isdigit(temp[0])){
					printf("\n");
					printf("Did not match with given Condition");
					
				}
					//if the digit comes and alphabet comes next, then print an error	
					if(isdigit(temp[i])){
						if(isalpha(temp[i+1])){
							printf("\n");
							printf("Did not match with given Condition");
							
						}
						k = 0;
					
						while(isdigit(temp[i])){
							lex[k++] = temp[i++];
						}
						if((temp[tempLength]=='u') || (temp[tempLength]=='U') || (temp[tempLength]=='l') || (temp[tempLength]=='L')){
							lex[k++] = temp[i++];
							break;
						}
						if(temp[i] !='.'){
							lex[k] = '\0';
							printResult(DIGIT,lex);
							break;
						}
						//Floating number conditions.
						else if(temp[i]=='.' && isdigit(temp[i+1])){
							int check=0;
							lex[k++]='.';
							i++;
							while(isdigit(temp[i])){
								lex[k++] = temp[i++];
							}
							if((temp[i] == 'e') || (temp[i] == 'E')){
								lex[k++] = temp[i++];
							}
							if((temp[tempLength-1]=='f') || (temp[tempLength-1]=='F') || (temp[tempLength-1]=='l') || (temp[tempLength-1]=='L')){
								lex[k++] = temp[i++];
							}
							
							while(isdigit(temp[i])){
								if(check==0)
								lex[k++] = temp[i];
								i++;
							}
							if(check==1){
								break;
							}
							lex[k] = '\0';
							printResult(FLOATING,lex);
							break;
						}
					}
			
				else if(temp[i]=='\n'){
					i++;
					if(temp[i+1] != '\n'){
						printf("\n\nLine No.=%d\n",line++);
						printf("\n");
					}
				}
				else if(temp[i]=='\t' || temp[i]==' '){
					i++;
				}
				
				else{
					i++;
				}
				
		}
		
	}
	for(i=0; i<10;i++){
		z[i]='\0';
	}
}

int main(){
	//ready to read file, create file pointer.
	FILE *fp;
	
	int i=0;
	int f;
	char temp[300];
	int tempLength;
	char g[30];
	
	printf("Test2 Question1\n");
	printf("\n");
	// open file
	fp = fopen("input.txt","r");
	// print an error when file does not exit
	if(fp == NULL){
		printf("Need a text file, the name should be 'input.txt'");
		printf("\n");
	}
	// check each character until end of file
	while((f = getc(fp)) != EOF){
		temp[i++] = f;
	}
	tempLength = i;
	//close file
	fclose(fp);
	printf("\nLine No.\t\t\tToken ID\t\tExplain\n");
	
	printf("Line No.=1\n");
	
	
	lexi(temp, tempLength);
	return 0;
}
