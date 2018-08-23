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


    if (Line == line) {
      break;
    } else {
      if (count != Size) {
        Buffer[Line][Size] = *str;
        Size++;
      }
      if (Size == size) {
        Line++;
        Size = 0;
        count = 0;

      }
    }
  }






}



void main() {

  strcpy(text, "abcccccccc\r\naaaaaaaaaaaaa\r\nbbbbbbbbbbbbb");
  convert_textto_buffer(text);

  printf("%s", Buffer[0]);






}


