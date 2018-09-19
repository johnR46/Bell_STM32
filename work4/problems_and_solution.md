## Work 4

## ปัญหาที่เจอ 
```c 
int CreateDir(char * dirName) 
/*
สร้างได้แค่ โฟล์เดอร์ตัวพิมพ์ใหญ่เท่านั้น 
หากสร้างตัวพิมพ์เล็ก ระบบจะตอบสนองแต่ไม่สร้างอะไรตามคำสั่งให้
เสร็จแล้ว
*/
int DelDir(char * dirName)
/*
Fn:ลบโฟลเดอร์ใน SD-card
ลบได้ให้ Output = 1 
ลบไม่ได้ให้ Output = 0


1. SET File name 00 57 AB 2F 
2. Double command to FOLDER DELETE 00 57 AB 35
เรียบร้อย 


*/



```

## solution

```c
char * upperASCII(char *str);
 /*
 แปลงตัวเล็กให้เป็นตัวใหญ่ ก่อนที่จะส่งไปสร้าง Folder 
 
 */

/*-----------------------------------------------------------------------------
  variable and function for  Create  DIR สร้าง DIR สำเร็จ return 1 ไม่สำเร็จ return 0 
  -------------------------------------------------------------------------------*/
int Folder_CREATE[]  = {0x00, 0x57, 0xab, 0x40};
int Set_nameFolder[] = {0x00, 0x57, 0xab, 0x2f,0x2f};
int Folder_Close[] = {0x00, 0x57, 0xab, 0x36, 0x00};
char buffascii[10];

void upperASCII(char *);
void setFoldername(char *);
int createFolder(char *);

int createFolder(char *name)
{
  int timeOut = 0; 
  int status_create = 0;
  command_ = 1;

  while(1){
  timeOut++;
if (command_ == 1)
  {

   
    SendCH370(checkConnection, sizeof(checkConnection));
    command_++; //2
    delay_ms(50);
  }
  else if (command_ == 2)
  {
    
    SendCH370(setSDCard, sizeof(setSDCard));
    command_++; //4
    delay_ms(50);
  }
  else if (command_ == 3)
  {

    SendCH370(USBDiskMount, sizeof(USBDiskMount));
    command_++; //6
    delay_ms(50);
  }
  else if (command_ == 4)
  {
    // setFoldername
    // convert uppercase to name
    upperASCII(name);
    setFoldername(buffascii);
    command_++; //8
    delay_ms(50);
  }
  else if (command_ == 5)
  {

    SendCH370(Folder_CREATE, sizeof(Folder_CREATE));
    delay_ms(80);
    command_++; //10
  }
  else if (command_ == 6)
  {
    // Folder_Close

    SendCH370(Folder_Close, sizeof(Folder_Close));
    command_++; //18
    delay_ms(50);
  }
  if (USART_GetITStatus(USART3, USART_IT_RXNE))
  {
    i1 = USART_ReceiveData(USART3);
   if(i1 == 0x82){
     printf("\r\n ERR_DISK_DISCON  \r\n");
   }
   if(i1 == 0xa8){
     printf("\r\n CMD_CHECK_EXIST \r\n");
   }
 
  }
  
  if(timeOut > 300){
    status_create = 0;
    printf("\r\nError Folder create\r\n");
    break;
  }
  if (command_ == 7 && i1 == 0x14){
    
  status_create = 1;
		printf("\r\nFolder create complete\r\n");
  break;
  }
  if(command_ == 7 && i1 != 14){
    if(i1 == 0x51){
    
    }
    command_ = 1;
  }

  }
  return status_create;
}

void setFoldername(char *filename)
{ //setFilenameForFunction //0x00 0x57 0xab 0x2f
  int loovar = 0;
  int tempLL[14];
  SendCH370(setFilenameForFunction, sizeof(setFilenameForFunction));
  while (filename[loovar] != '\0')
  {
    tempLL[loovar] = filename[loovar];
    loovar++;
  }
  tempLL[loovar] = '\0';
  SendCH370(tempLL, sizeof(tempLL));
}

void  upperASCII(char *str) {
  int i = 0;
  while (*str != '\0') {
    if (*str >= 97 && *str <= 122 ) {
      buffascii[i] = *str - 32;
    } else {
      buffascii[i] = *str;
    }
    i++;
    str++;
  }
}


/*
##end variable and function for CreateDIR
*/


/*
## Function Delete Folder 
*/
int DeleteFolder(char *name);

int DeleteFolder(char *name)
{
  int timeOut = 0; 
  int status_delete = 0;
  command_ = 1;

  while(1){
  timeOut++;
if (command_ == 1)
  {
    SendCH370(checkConnection, sizeof(checkConnection));
    command_++; //2
    delay_ms(50);
  }
  else if (command_ == 2)
  {
    SendCH370(setSDCard, sizeof(setSDCard));
    command_++; //4
    delay_ms(50);
  }
  else if (command_ == 3)
  {
    SendCH370(USBDiskMount, sizeof(USBDiskMount));
    command_++; //6
    delay_ms(50);
  }
  else if (command_ == 4)
  {
    // setFoldername
    // convert uppercase to name
    upperASCII(name);
    setFoldername(buffascii);
    command_++; //8
    delay_ms(50);
  }
  else if (command_ == 5)
  {
    SendCH370(Folder_DELETE, sizeof(Folder_DELETE));
    delay_ms(80);
    command_++; //10
  }
  else if (command_ == 6)
  {
    SendCH370(Folder_DELETE, sizeof(Folder_DELETE));
    delay_ms(80);
    command_++; //10
  }
  

  if (USART_GetITStatus(USART3, USART_IT_RXNE))
  {
    i1 = USART_ReceiveData(USART3);
    if(i1 == 0x41){
     printf("\r\n ERR_OPEN_DIR \r\n");
   }
   if(i1 == 0x82){
     printf("\r\n ERR_DISK_DISCON  \r\n");
   }
   if(i1 == 0xa8){
     printf("\r\n CMD_CHECK_EXIST \r\n");
   }
   
 
  }
  
  if(timeOut > 300){
    status_delete = 0;
    printf("\r\nError Folder Delete\r\n");
    break;
  }
  if (command_ == 7 && i1 == 0x14){
  status_delete = 1;
		printf("\r\nFolder Delete complete\r\n");
  break;
  }
  if(command_ == 7 && i1 != 14){
   
    command_ = 1;
  }

  }
  return status_delete;
}

/*
## end Function Delete Folder
*/

