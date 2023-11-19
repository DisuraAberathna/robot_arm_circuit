#include <Servo.h>
//servo objects
Servo s1 = Servo();
Servo s2 = Servo();
Servo s3 = Servo();
Servo s4 = Servo();

#include <IRremote.h> 
IRrecv r = IRrecv(7);
decode_results d = decode_results(); //result object

int a1 = 90; //Base
int a2 = 180;  //Up,Down
int a3 = 0;    //Forward,Backword
int a4 = 10;   //Catch,Release

void setup() {
 r.enableIRIn();// start ir receive
 Serial.begin(9600);  
 s1.attach(2);//Base
 s2.attach(3);//Up,Down
 s3.attach(4);//Forward,Backward
 s4.attach(5);//Catch,Release

}

void loop() {
  // put your main code here, to run repeatedly:
  if (r.decode(&d)) {
   int v = d.value;
   Serial.println(v);//Serial Monitor
   
   //Base Rotate Left
   if (v == -16833) {
     for (int i = 0; i < 10; i++){
       a1 = a1 + 1;
       s1.write(a1);
       delay(100);
     }
  
     if (v == -7177) {
     for (int i = 0; i < 10; i++){
       a1 = a1 - 1;
       s1.write(a1);
       delay(100);
     }
     if(a1<180){
       a1=180;
     }
     }
     

     //Base Rotate Right
     if (v == -7177) {
      for (int i = 0; i < 10; i++) {
        a1 = a1 - 1;
        s1.write(a1);
        delay(100);
      }
      if (a1 < 0) {
        a1 == 0;
      }
    }




    //UpDown (UP)
    if (v == -1) {
      for (int i = 0; i < 10; i++) {
        a2 = a2 + 1;
        s2.write(a2);
        delay(100);
      }
      if (a2 > 180) {
        a2 == 180;
      }
    }
    //UpDown (Down)
    if (v == 25979) {
      for (int i = 0; i < 10; i++) {
        a2 = a2 - 1;
        s2.write(a2);
        delay(100);
      }
      if (a2 < 0) {
        a2 == 0;
      }
    }




    //Forward
    if (v == -1) {
      for (int i = 0; i < 10; i++) {
        a3 = a3 + 1;
        s3.write(a3);
        delay(100);
      }
      if (a3 > 180) {
        a3 == 180;
      }
    }
    //Backward
    if (v == -6241) {
      for (int i = 0; i < 10; i++) {
        a3 = a3 - 1;
        s3.write(a3);
        delay(100);
      }
      if (a3 < 0) {
        a3 == 0;
      }
    }    




     //Catch
    if (v == -1) {
      for (int i = 0; i < 10; i++) {
        a4 = a4 + 1;
        s4.write(a4);
        delay(100);
      }
      if (a4 > 180) {
        a4 == 180;
      }
    }
    //Release
    if (v == -1) {
      for (int i = 0; i < 10; i++) {
        a4 = a4 - 1;
        s4.write(a4);
        delay(100);
      }
      if (a4 < 0) {
        a4 == 0;
      }
    }


   r.resume();
  }
}
