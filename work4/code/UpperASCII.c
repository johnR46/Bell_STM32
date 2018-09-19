#include<stdio.h>
#include <ctype.h>
#include<string.h>

char x[10];
void upperASCII(char *str){
char ch[10];
char *buff;
int i = 0;	

while(*str != '\0'){
	if(*str >= 97){
     x[i] = *str-32;
  }else {
     x[i] = *str;
  }
	i++;
	str++;
}

	
}

int main(){
	upperASCII("aAvCV");
printf("%s",x);
return 0;
	
}
