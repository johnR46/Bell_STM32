## ต้องการฟังชั่น `EnterLine();`

```c
ืทำงานกับฟังก์ชั่น WriteFlash และ readSecter และ notepad_append
    -   writeFlash(int address) // sector*4096
่           ก่อนจะเขียนข้อมูล ให้ strcpy(SST25_buffer,"str");
           จากนั้นให้ writeFlash(sector) // เริ่มที่ sector 0
    - readSecter(ind address) // sector*4096
        จะอ่าน sector ไหนก็กำหนด address ตามที่ต้องการ
        พออ่านเสร็จ ข้อมูลจะถูกเก็บไว้ใน SST25_buffer
    - notepad_append 
        // insert string 


```
```
- รับค่าจาก Keyboard Braille ถ้าตัวที่รับมาเกิน 4096 แล้ว จะทำการเขียนส่วนหลังจาก 4096 ลงไปใน Rom
หากมีการ Insert ในส่วนนั้น ก็จะทำการอ่านขึ้นมาจากรอม

 ```   
    

#### Input

```c 

```

#### Output 
ตัวแปรประเภท String

