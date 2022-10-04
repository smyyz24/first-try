#include <Servo.h>
#define  SERVO_PIN  5           //宏定义舵机控制引脚
#define  SERVO2_PIN  9
#define SensorLeftPin1 = A2;
#define SensorRIGHTPin1 = A3;
#define STOP      0


Servo myservo;  // 定义Servo对象来控制
Servo myservo2;
int pos1 = 0;    // 角度存储变量
int pos2 = 0;
unsigned int PWM = 0;             //变量pwm用来存储舵机角度位置,PWM的500对应0度，2500对应舵机的最大角度
int trigPin = 12;      // trig pin of HC-SR04
int echoPin = 11;     // Echo pin of HC-SR04
int fwdleft9 = 9;       //ForWarD motion of Left motor
int revright5= 5;      //REVerse motion of Right motor
int distance  = pulseIn(echoPin,10);
void getDistance();//int dis[3];//距离
int SensorLeftvalue1 = 0;
int SensorRightvalue1 = 0;
float dis;//检测到距离障碍物的距离


 





void setup()
 {
    pinMode(13, OUTPUT);//PWM
    myservo.attach(SERVO_PIN);  // 控制线连接数字5
    myservo2.attach(SERVO2_PIN);
    myservo.writeMicroseconds(1000);
    myservo2.writeMicroseconds(1000);
    Serial.begin(9600);//超声波探测仪操作
    pinMode(fwdleft9, OUTPUT);      // set Motor pins as output
    pinMode(revright5, OUTPUT);
    pinMode(trigPin, OUTPUT);         // set trig pin as output
    pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    analogWrite(A2,HIGH);
    analogWrite(A3,HIGH);


  }

 
 void TURNLEFT()
  {
    myservo.writeMicroseconds(1000);
    myservo2.writeMicroseconds(1520);
    delay(2000);
  }


 void TURNRIGHT()
  {
    myservo.writeMicroseconds(1520);
    myservo2.writeMicroseconds(2000);
    delay(2000);
  }

 void MOVEFORWARD()
  {
    myservo.writeMicroseconds(1000);
    myservo2.writeMicroseconds(2000);
    delay(1000);
  }

 void MOVEROUND()
  {
    myservo.writeMicroseconds(1000);
    myservo2.writeMicroseconds(1000);
    delay(2000);
  }

  void turn()
   {
     digitalWrite(revright5,LOW);
     digitalWrite(fwdleft9,HIGH);
     analogWrite(fwdleft9,1000);
     delay(1000);
   }

  void stop()
   {
     digitalWrite(revright5,LOW);
     digitalWrite(fwdleft9,LOW);
     delay(2000);
   }
   

  void getDistance()
   {
     digitalWrite(trigPin,LOW);
     digitalWrite(echoPin,LOW);
     delayMicroseconds(2);
     digitalWrite(trigPin,HIGH);
     digitalWrite(echoPin,HIGH);
     delayMicroseconds(100);
     Serial. print("cm");
     Serial. println();
     delay(200);
      
   }
   
 

 void loop()
  {
    /*analogWrite(13, 1000);
    delayMicroseconds(100); // Approximately 10% duty cycle @ 1KHz
    analogWrite(13, 0);
    delayMicroseconds(1000- 100); //修改这里的1000可以调整频率

 /* for (pos1 = 0; pos <= 360; pos ++)
     { // 0°到180°
       // in steps of 1 degree
        myservo.write(pos);              // 舵机角度写入
        myservo2.write(pos);
        delay(5);                       // 等待转动到指定角度
       }
   for (pos2 = 0; pos <= 360; pos --)
      { // 从180°到0°
        myservo.write(pos);              // 舵机角度写入
        delay(5);                       // 等待转动到指定角度
       }*/
 
 
  /*for(PWM = 50; PWM <2000; PWM += 5)
      {   //舵机从50状态转到2450，每次增加5  
         myservo.writeMicroseconds(PWM);   //给舵机写入PWM  
         delay(5);                        //延时5ms让舵机转到指定位置
       }  
    for(PWM = 2450; PWM>50; PWM-=5)
      {     
         myservo2.writeMicroseconds(PWM);    
         delay(5);                       
       }    */ 

    
    /*//不同方向同速转动（原地旋转）
    for(pos1 = 0; pos1 <= 180; pos1 += 1)
      {  
         myservo.write(pos1);
         myservo2.write(180-pos2);         
         delay(15); 
         } 
         delay(3000);

     for(pos1 = 0; pos1>=55; pos1 -=1)
       {
         myservo.write(pos1);
         myservo2.write(180-pos1);     
         delay(15);                      
         } 
          delay(1000);*/
                 



/*//同向但转速不同（曲线行驶）
     for(pos1 = 0; pos1 <= 180; pos1 += 1)
       {  
         myservo.write(pos1);
         myservo2.write(pos2);         
         delay(15); 
         } 
          delay(3000);

      for(pos1 = 0; pos1 >=60; pos1 += 5)
        {
          myservo.write(pos1);
          myservo2.write(pos2);     
          delay(15);                      
         } 
          delay(1000);
   }*/
               
 
 
 
/*//主动避障
 myservo.writeMicroseconds(1000);
 myservo2.writeMicroseconds(3000);
 getDistance();


 if(distance >50)        // move forward
  {
     digitalWrite(revright5, LOW);
     digitalWrite(fwdleft9, HIGH); 
     delay(200);                                                                                     
  }
 if(distance <50)
  {
   /*digitalWrite(revright5,LOW);//stop
     digitalWrite(fwdleft9,LOW);
     delay(500);
     digitalWrite(revright5,HIGH);//movebackward
     digitalWrite(fwdleft9,LOW);
     delay(500);
     digitalWrite(revright5,LOW);//stop
     digitalWrite(fwdleft9,LOW);
     delay(100);
     digitalWrite(revright5,LOW);
     digitalWrite(fwdleft9,HIGH);
     delay(500); 
    
     MOVEFORWARD();
     TURNLEFT();
     MOVEFORWARD();
     TURNRIGHT();
     TURNRIGHT();
     MOVEFORWARD();
    


  }*/
 //循线+避障
   SensorLeftvalue1 = analogRead(A2);
   SensorRightvalue1 = analogRead(A3);


   if(A2 <100 && A3 <100 )//都是白直走
    {
       MOVEFORWARD();
     }

     else if(A2 <100 && A3 >=100 )   
      {
         TURNLEFT(); 
       }

     else if(A2 >=100 && A3 <100 )   
      {
         TURNRIGHT(); 
       }

     else if(A2 >100 && A3 >100 )   
      {
         turn();
         delay(1000);
         stop();
         delay(1000);
       }
   
  

   myservo.writeMicroseconds(1000);
   myservo2.writeMicroseconds(3000);
   getDistance();

   if (distance <30)
    {
       MOVEFORWARD();
       TURNLEFT();
       MOVEFORWARD();
       TURNRIGHT();
       TURNRIGHT();
       MOVEFORWARD(); 
    }



}

  
 









  
  
  