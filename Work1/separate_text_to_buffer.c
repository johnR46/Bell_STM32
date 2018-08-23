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

  strcpy(text, " The Company runs official accounts on social mediassssss  understanding that social media is a place for communication based on a tie among individuals and that information is disclosed to the public and cannot be completely eliminated once dispatched, encourThe Company runs official accounts on social media by understanding that social media is a place for communication based on a tie among individuals and that information is disclosed to the public and cannot be completely eliminated once dispatched, encourThe Company runs official accounts on social media by understanding that social media is a place for communication based on a tie among individuals and that information is disclosed to the public and cannot be completely eliminated once dispatched, encourThe Company runs official accounts on social media by understanding that social media is a place for communication based on a tie among individuals and that information is disclosed to the public and cannot be completely eliminated once dispatched, encourTheThe Company runs official accounts on social media by understanding that social media is a place for communication based on a tie among individuals and that information is disclosed to the public and cannot be completely eliminated once dispatched, encourThe Company runs official accounts on social media by understanding that social media is a place for communication based on a tie among individuals and that information is disclosed to the public and cannot be completely eliminated once dispatched, encourThe Company runs official accounts on social media by understanding that social media is a place for communication based on a tie among individuals and that information is disclosed to the public and cannot be completely eliminated once dispatched, encourThe Company runs official accounts on social media by understanding that social media is a place for communication based on a tie among individuals and that information is disclosed to the public and cannot be completely eliminated once dispatched, encourTheThe Company runs official accounts on social media by understanding that social media is a place for communication based on a tie among individuals and that information is disclosed to the public and cannot be completely eliminated once dispatched, encourThe Company runs official accounts on social media by understanding that social media is a place for communication based on a tie among individuals and that information is disclosed to the public and cannot be completely eliminated once dispatched, encourThe Company runs official accounts on social media by understanding that social media is a place for communication based on a tie among individuals and that information is disclosed to the public and cannot be completely eliminated once dispatched, encourThe Company runs official accounts on social media by understanding that social media is a place for communication based on a tie among individuals and that information is disclosed to the public and cannot be completely eliminated once dispatched, encourTheThe Company runs official accounts on social media by understanding that social media is a place for communication based on a tie among individuals and that information is disclosed to the public and cannot be completely eliminated once dispatched, encourThe Company runs official accounts on social media by understanding that social media is a place for communication based on a tie among individuals and that information is disclosed to the public and cannot be completely eliminated once dispatched, encourThe Company runs official accounts on social media by understanding that social media is a place for communication based on a tie among individuals and that information is disclosed to the public and cannot be completely eliminated once dispatched, encourThe Company runs official accounts on social media by understanding that social media is a place for communication based on a tie among individuals and that information is disclosed to the public and cannot be completely eliminated once dispatched, encourThe");


  convert_textto_buffer(text);

  printf("%s", Buffer);






}


