## ต้องการฟังชั่น `EnterLine();`

```c
int main(){
    int line;
    line = EnterLine();
    printf("%d",line);
    return 0;
}
```
- แสดงผลของการพิมพ์ในโหมดนั้น ทำงานแยกจากกันเป็นหลูป `while(1)`
    - ตัวอย่าง      หน้าจอแสดงผล (EnterLine: 10 /60)
- หลังจากการกด Enter หรือ ตกลง จะตัวแปร line จะต้องมีค่าเท่ากับค่าที่พิมพ์เข้าไป

#### Input
รับค่าตัวเลขจาก Keyboard Braille โดยค่าตัวเลขจะไม่เกินค่า Max 
กำหนดโดย
```c 
#define maxGTLine 60
```

#### Output 
เป็นตัวประเภท `int` number >=0 && number <= Max
