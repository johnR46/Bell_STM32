#include<stdio.h>
#include<string.h>



char text[4096]; //
char dest[40]; // test
#define line 96
#define size 40
char Buffer[line][size];



void convert_textto_buffer(char *str) {
  int count = 0;
  int Line = 0;
  int Size = 0;
 
  while (*str != '\0') {
	count++;
    str++;
    
    if(*str == '\r'){
    	Buffer[Line][Size] = '\r';
    	Size++;
    	Buffer[Line][Size] = '\n';
    	
		str++;
		Line++;
		Size = 0;
		count = 0;
		
		
			
	}
	
	if(Line == line){
		break;
	}
	if(Size == size){
		Line++;
		Size = 0;
		
	}
	
	if(count != Size){
		Buffer[Line][Size] = *str;
		Size++;
	}
}
}


void main() {

  strcpy(text,"aaaaaaaaaaaaaaaaaaaaaaaa\r\nbbbbbbbbbbbbbbbbbbbbb\r\nccccccccccc\r\n\r\n\r\nTEST");

  convert_textto_buffer(text);

printf("%s",Buffer[0]); // “aaaaaaaaaaaaaaaaaaaaaaaaa”
printf("%s",Buffer[1]); // “bbbbbbbbbbbbbbbbbbbbb”
printf("%s",Buffer[2]); // “ccccccccccc”
printf("%s",Buffer[3]); // ""
printf("%s",Buffer[4]); // ""
printf("%s",Buffer[5]); //“TEST”






}


