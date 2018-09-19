## Work 1
```c
char text[4096];
#define line 96
#define size 40
```
เอาสตริงจาก text ยาวไม่เกิน 4096 ใส่ในอาเรย์ char Buffer[line][size]  เขียนเป็นฟังก์ชั่น 

## Input:
```c
text = “aaaaaaaaaaaaaaaaaaaaaaaa\r\nbbbbbbbbbbbbbbbbbbbbb\r\nccccccccccc\r\n\r\n\r\nTEST”
```
## Output:
```c
printf("%s",Buffer[0]); // “aaaaaaaaaaaaaaaaaaaaaaaaa”
printf("%s",Buffer[1]); // “bbbbbbbbbbbbbbbbbbbbb”
printf("%s",Buffer[2]); // “ccccccccccc”
printf("%s",Buffer[3]); // ""
printf("%s",Buffer[4]); // ""
printf("%s",Buffer[5]); //“TEST”
```
