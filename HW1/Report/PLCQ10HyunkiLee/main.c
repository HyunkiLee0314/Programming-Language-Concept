#include <stdio.h>
#include<string.h>
#define MAX 1000
int main(){

char c[MAX];
FILE *fp;
fp = fopen("Q12.txt", "r");
int i;
int size;

  if ( fp == NULL) {
  printf("Cannot open file");
  return -1;
  }

fscanf(fp, "%[^\n]", c);
size = strlen(c);

  for(i=0; i<size; i++){
    if((c[i]>='0'&& c[i]<='9')||(c[i]>='a'&& c[i]<='z')||(c[i]>='A'&& c[i]<='Z')){
    
      printf("%c",c[i]);
    }
    else if(c[i] == ' '){
      printf("\n");
    }
    else{
      printf("\n");
      printf("%c\n",c[i]);
    }
  }

fclose(fp);
return 0;

}
