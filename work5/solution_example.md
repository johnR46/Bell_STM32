##solution and example for work5.

#define MAX_LINE 60
int line;
int EnterLine(void);
int EnterLine() {
  int Line = 0;
  int state = 1;
  int curline = 0;
  int i = 0;
  char line[3];
  while (state) {
    notepad_readKey();       // key recieve
    if (countKey >= maxData) // do events
    { //Recieve & checking key
      seeHead = 0;
      if (checkKeyError == 0xff)
      { //clear error key
        countKey = 0;
        SeeHead = 0;
      }

      if (bufferKey3digit[0] == 0x80) {  // check key enter
         Line = atoi(line);
         if(Line >MAX_LINE ){
           printf("\r\n Over Max line !!\r\n");
           state = 1;
           memset(line,0,3);
         }else{
           state = 0;
         }
      }
      i = unicode_to_ASCII(bufferKey3digit[0]);  // convert key to ascii
      if (i >= 48 && i <= 57) { // check num 0 - 9
        line[curline] = i;
        curline++;
        if (curline == 3) {
          curline = 0;
        }
      }
      clearKeyValue(); 
    }
  }

  Line = atoi(line);

  return Line;
}



int main(){


  printf(" start test  EnterLine \r\n");

  line = EnterLine();

  printf("line = %d\r\n",line);
 

return 0;
}