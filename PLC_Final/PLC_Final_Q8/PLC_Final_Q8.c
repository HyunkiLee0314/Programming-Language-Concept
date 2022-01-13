#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//define each tokens as unique number



#define PLUS 1
#define ASSIGNMENT 2
#define MINUS 3
#define DIVISION 4
#define MULTI 5
#define MODULO 6
#define NOT 7
#define OPEN_FUNC 8
#define CLOSE_FUNC 9
#define INCRE 10
#define DECRE 11
#define AND 12
#define OR 13
#define LEFT 14
#define RIGHT 15
#define LEFT_EQUAL 16
#define RIGHT_EQUAL 17
#define XOR 18
#define a1 19
#define b1 20
#define c1 21
#define d1 22
#define e1 23
#define SPACE 24

#define IDENTIFIER 25
#define DIGIT 26
#define FLOATING 27

#define TOTAL 28

int numOfToken = 0;

//Create struct frame
struct list{
	char pick[35];
	int token;
};
//Type struct elements
struct list reference[TOTAL] = {

	

	
	{"+", PLUS},
	{"=", ASSIGNMENT},
	{"-", MINUS},
	{"/", DIVISION},
	{"*", MULTI},
	{"%", MODULO},
	{"!", NOT},
	{"(", OPEN_FUNC},
	{")", CLOSE_FUNC},
	{"++", INCRE},
	{"--", DECRE},
	{"&&", AND},
	{"||", OR},
	{">", LEFT},
	{"<", RIGHT},
	{">=", LEFT_EQUAL},
	{"<=", RIGHT_EQUAL},
	{"~|", XOR},
	{"a", a1},
	{"b", b1},
	{"c", c1},
	{"d", d1},
	{"e", e1}
	
	
};
// tokens category that where the tokens belong to (This is related to reference struct)
char tokenCategory[TOTAL+1][50]={
" ",


"PLUS(4rd precedence)",
"ASSIGNMENT(Lowest precedence)",
"MINUS(4th precedence)",
"DIVISION(7th precedence)",
"MULTI(3rd precedence)",
"MODULO(5th precedence)",
"NOT(7th precedence)",
"OPEN_FUNC",
"CLOSE_FUNC",
"INCREMENT(1st precedence)",
"DECREMENT(1st precedence)",
"AND(3rd precedence)",
"OR(8th precedence)",
"LEFT(6th precedence)",
"RIGHT(6th precedence)",
"LEFT_EQUAL(3rd precedence)",
"RIGHT_EQUAL(4th precedence)",
"XOR(8th precedence)",
"5",
"7",
"11",
"-13",
"-2",
"SPACE",

"VARIABLES",
"DIGIT",
"FLOATING"


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
				
			case '>':
				next = temp[++i];
				if(next=='='){
					i++;
					printResult(LEFT_EQUAL,z);
					break;
				}else{
					i++;
					printResult(LEFT,z);
					break;
				}
			
			case '<':
				next = temp[++i];
				if(next=='='){
					i++;
					printResult(RIGHT_EQUAL,z);
					break;
				}else{
					i++;
					printResult(RIGHT,z);
					break;
				}
				
			case '~':
				next = temp[++i];
				if(next=='|'){
					i++;
					printResult(XOR,z);
					break;
				}
	
			case '=':
				i++;
				printResult(ASSIGNMENT,z);
				break;
			
			case '%':
				i++;
				printResult(MODULO,z);
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
				
				
				} if(isdigit(temp[0])){
					printf("\n");
					
					
				}
						
					if(isdigit(temp[i])){
						if(isalpha(temp[i+1])){
							printf("\n");
							
							
						}
						k = 0;
					
						while(isdigit(temp[i])){
							lex[k++] = temp[i++];
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
	
	printf("a=5, b=7, c=11, d=-13, e=-2");
	
	lexi(temp, tempLength);
	return 0;
}
