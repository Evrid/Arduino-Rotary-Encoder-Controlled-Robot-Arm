// Include the Servo Library
#include <Servo.h>


// Rotary Encoder 1 Inputs   left most
#define CLK1 53  
#define DT1 51  
#define SW1 49   

// Rotary Encoder 2 Inputs
#define CLK2 45 
#define DT2 43  
#define SW2 41   

// Rotary Encoder 3 Inputs
#define CLK3 50  
#define DT3 48  
#define SW3 46   

// Rotary Encoder 4 Inputs
#define CLK4 42  
#define DT4 40  
#define SW4 38   


// Rotary Encoder 5 Inputs
#define CLK5 34  
#define DT5 32  
#define SW5 30  

// Rotary Encoder 6 Inputs  right most
#define CLK6 26  //26
#define DT6 24  //24
#define SW6 22   //22
 
Servo baseservo;
Servo lowerwaistservo;
Servo elbowservo;
Servo lowesthandservo;
Servo middlehandservo;
Servo grabservo;

int counter1 = 0;
int counter2 = 0;
int counter3 = 0;
int counter4 = 0;
int counter5 = 0;
int counter6 = 0;

int currentStateCLK1;
int currentStateCLK2;
int currentStateCLK3;
int currentStateCLK4;
int currentStateCLK5;
int currentStateCLK6;

int lastStateCLK1;
int lastStateCLK2;
int lastStateCLK3;
int lastStateCLK4;
int lastStateCLK5;
int lastStateCLK6;

int SWdown1=0;   //set a variable  
int SWdown2=0;    
int SWdown3=0;  
int SWdown4=0;  
int SWdown5=0;   
int SWdown6=0;   


int rememberclickA1=0;  //set a variable 
int rememberclickA2=0; 
int rememberclickA3=0; 
int rememberclickA4=0; 
int rememberclickA5=0; 
int rememberclickA6=0; 

int rememberclickB1=0;  //set a variable  
int rememberclickB2=0; 
int rememberclickB3=0; 
int rememberclickB4=0; 
int rememberclickB5=0; 
int rememberclickB6=0; 

int rememberclickC6=0;  //we need 3 remember variable for the grab, one open, one grab, another open again

void setup() 
{
  
  // Set encoder pins as inputs
  pinMode(CLK1,INPUT);
  pinMode(DT1,INPUT);
  pinMode(SW1,INPUT);   //SW is the active low push button switch output. When the knob is pushed, the voltage goes LOW 

  pinMode(CLK2,INPUT);
  pinMode(DT2,INPUT);
  pinMode(SW2,INPUT); 

  pinMode(CLK3,INPUT);
  pinMode(DT3,INPUT);
  pinMode(SW3,INPUT); 

  pinMode(CLK4,INPUT);
  pinMode(DT4,INPUT);
  pinMode(SW4,INPUT); 

  pinMode(CLK5,INPUT);
  pinMode(DT5,INPUT);
  pinMode(SW5,INPUT); 

  pinMode(CLK6,INPUT);
  pinMode(DT6,INPUT);
  pinMode(SW6,INPUT); 
  
  
  pinMode(12,INPUT);  //for reset button, the left one
  pinMode(13,INPUT);  //for play button, the right one
  
  // Setup Serial Monitor
  Serial.begin(9600);
  
  // Attach servo on pins to the servo object
  
  baseservo.attach(7);//base servo , MG996
  lowerwaistservo.attach(6);//lower waist servo, MG996
  elbowservo.attach(5);//elbow servo, MG996
  lowesthandservo.attach(4);//lowest hand servo, rotate the hand,  SG90
  middlehandservo.attach(3);//middle hand servo, to rotate upper hand,  SG90
  grabservo.attach(2);//highest servo, for grab,  SG90
  
  baseservo.write(counter1);
  lowerwaistservo.write(counter2);
  elbowservo.write(counter3);
  lowesthandservo.write(counter4);
  middlehandservo.write(counter5);
  grabservo.write(counter6);
  
  // Read the initial state of CLK
  lastStateCLK1 = digitalRead(CLK1);
  lastStateCLK2 = digitalRead(CLK2);
  lastStateCLK3 = digitalRead(CLK3);
  lastStateCLK4 = digitalRead(CLK4);
  lastStateCLK5 = digitalRead(CLK5);
  lastStateCLK6 = digitalRead(CLK6);
}

void loop() 
{


//for baseservo, left most rotary encoder ----------------------------------------------------------------------------------------------
  // Read the current state of CLK
  currentStateCLK1 = digitalRead(CLK1);
  
  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK1 != lastStateCLK1  && currentStateCLK1 == 1){
    
    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT1) != currentStateCLK1) {
      counter1 --;
      if (counter1<0)
        counter1=0;
    } else {
      // Encoder is rotating CW so increment
      counter1 ++;
      if (counter1>179)
        counter1=179;
    }
    // Move the servo
    baseservo.write(counter1);
    Serial.print("Position: ");
    Serial.println(counter1);
  }
  
  // Remember last CLK state
  lastStateCLK1 = currentStateCLK1;


    if (digitalRead(SW1)==LOW)   //   *****
  {
    Serial.println("pressed down");
    SWdown1++;
    delay (1000);   //the best debounce pushbutton method is use delay
    if (SWdown1==1)
    {
      rememberclickA1=counter1;
      delay (500);   //the best debounce pushbutton method is use delay
    }
    if (SWdown1==2)
    {
    rememberclickB1=counter1;
    SWdown1=0;
    delay (500);   //the best debounce pushbutton method is use delay
    }
  }


  
//For lowerwaistservo, the second rotary encoder ----------------------------------------------------------------------------------------------
  
  // Read the current state of CLK
  currentStateCLK2 = digitalRead(CLK2);
  
  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK2 != lastStateCLK2  && currentStateCLK2 == 1){
    
    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT2) != currentStateCLK2) {
      counter2 --;
      if (counter2<0)
        counter2=0;
    } else {
      // Encoder is rotating CW so increment
      counter2 ++;
      if (counter2>179)
        counter2=179;
    }
    // Move the servo
    lowerwaistservo.write(counter2);
    Serial.print("Position: ");
    Serial.println(counter2);
  }
  
  // Remember last CLK state
  lastStateCLK2 = currentStateCLK2;


    if (digitalRead(SW2)==LOW)   //   *****
  {
    Serial.println("pressed down");
    SWdown2++;
    delay (1000);   //the best debounce pushbutton method is use delay
    if (SWdown2==1)
    {
      rememberclickA2=counter2;
      delay (500);   //the best debounce pushbutton method is use delay
    }
    if (SWdown2==2)
    {
    rememberclickB2=counter2;
    SWdown2=0;
    delay (500);   //the best debounce pushbutton method is use delay
    }
  }


//For elbowservo, the third rotary encoder ----------------------------------------------------------------------------------------------

  currentStateCLK3 = digitalRead(CLK3);
  
  if (currentStateCLK3 != lastStateCLK3  && currentStateCLK3 == 1){
    
    if (digitalRead(DT3) != currentStateCLK3) {
      counter3 --;
      if (counter3<0)
        counter3=0;
    } else {
      // Encoder is rotating CW so increment
      counter3 ++;
      if (counter3>179)
        counter3=179;
    }
    // Move the servo
    elbowservo.write(counter3);
    Serial.print("Position: ");
    Serial.println(counter3);
  }
  
  // Remember last CLK state
  lastStateCLK3 = currentStateCLK3;


    if (digitalRead(SW3)==LOW)   //   *****
  {
    Serial.println("pressed down");
    SWdown3++;
    delay (1000);   //the best debounce pushbutton method is use delay
    if (SWdown3==1)
    {
      rememberclickA3=counter3;
      delay (500);   //the best debounce pushbutton method is use delay
    }
    if (SWdown3==2)
    {
    rememberclickB3=counter3;
    SWdown3=0;
    delay (500);   //the best debounce pushbutton method is use delay
    }
  }


//For  lowesthandservo, the fourth rotary encoder ----------------------------------------------------------------------------------------------

  currentStateCLK4 = digitalRead(CLK4);
  
  if (currentStateCLK4 != lastStateCLK4  && currentStateCLK4 == 1){
    
    if (digitalRead(DT4) != currentStateCLK4) {
      counter4 --;
      if (counter4<0)
        counter4=0;
    } else {
      // Encoder is rotating CW so increment
      counter4 ++;
      if (counter4>179)
        counter4=179;
    }
    // Move the servo
    lowesthandservo.write(counter4);
    Serial.print("Position: ");
    Serial.println(counter4);
  }
  
  // Remember last CLK state
  lastStateCLK4 = currentStateCLK4;


    if (digitalRead(SW4)==LOW)   //   *****
  {
    Serial.println("pressed down");
    SWdown4++;
    delay (1000);   //the best debounce pushbutton method is use delay
    if (SWdown4==1)
    {
      rememberclickA4=counter4;
      delay (500);   //the best debounce pushbutton method is use delay
    }
    if (SWdown4==2)
    {
    rememberclickB4=counter4;
    SWdown4=0;
    delay (500);   //the best debounce pushbutton method is use delay
    }
  }


  
//For  middlehandservo, the fifth rotary encoder ----------------------------------------------------------------------------------------------

 currentStateCLK5  = digitalRead(CLK5);
  
  if (currentStateCLK5  != lastStateCLK5  && currentStateCLK5  == 1){
    
    if (digitalRead(DT5) != currentStateCLK5 ) {
      counter5 --;
      if (counter5<0)
        counter5=0;
    } else {
      // Encoder is rotating CW so increment
      counter5 ++;
      if (counter5>179)
        counter5=179;
    }
    // Move the servo
    middlehandservo.write(counter5);
    Serial.print("Position: ");
    Serial.println(counter5);
  }
  
  // Remember last CLK state
  lastStateCLK5 = currentStateCLK5 ;


    if (digitalRead(SW5)==LOW)   //   *****
  {
    Serial.println("pressed down");
    SWdown5++;
    delay (1000);   //the best debounce pushbutton method is use delay
    if (SWdown5==1)
    {
      rememberclickA5=counter5;
      delay (500);   //the best debounce pushbutton method is use delay
    }
    if (SWdown5==2)
    {
    rememberclickB5=counter5;
    SWdown5=0;
    delay (500);   //the best debounce pushbutton method is use delay
    }
  }


  
//For  grabservo, the sixth (roght most) rotary encoder ----------------------------------------------------------------------------------------------

 currentStateCLK6  = digitalRead(CLK6);
  
  if (currentStateCLK6  != lastStateCLK6  && currentStateCLK6  == 1){
    
    if (digitalRead(DT6) != currentStateCLK6 ) {
      counter6 --;
      if (counter6<0)
        counter6=0;
    } else {
      // Encoder is rotating CW so increment
      counter6 ++;
      if (counter6>179)
        counter6=179;
    }
    // Move the servo
    grabservo.write(counter6);
    Serial.print("Position: ");
    Serial.println(counter6);
  }
  
  // Remember last CLK state
  lastStateCLK6 = currentStateCLK6 ;


    if (digitalRead(SW6)==LOW)   //   *****
  {
    Serial.println("pressed down");
    SWdown6++;
    delay (1000);   //the best debounce pushbutton method is use delay
    if (SWdown6==1)
    {
      rememberclickA6=counter6;
      delay (500);   //the best debounce pushbutton method is use delay
    }
    
    if (SWdown6==2)
    {
    rememberclickB6=counter6;
    delay (500);   //the best debounce pushbutton method is use delay
    }
    
    if (SWdown6==3)
    {
    rememberclickC6=counter6;
    SWdown6=0;
    delay (500);   //the best debounce pushbutton method is use delay
    }
  }


  
//----------------------------------------------------------------------------------------------



  if (digitalRead(12)==LOW)  //reset
  {
  Serial.println("reset button down");
  rememberclickA1=0;  //reset remembered memory 
  rememberclickA2=0; 
  rememberclickA3=0; 
  rememberclickA4=0; 
  rememberclickA5=0; 
  rememberclickA6=0; 

  rememberclickB1=0;  //reset remembered memory 
  rememberclickB2=0; 
  rememberclickB3=0; 
  rememberclickB4=0; 
  rememberclickB5=0; 
  rememberclickB6=0; 
  delay (1000);   //the best debounce pushbutton method is use delay
  }


  if (digitalRead(13)==LOW)  //play
  {
  Serial.println("play button down");

  grabservo.write(rememberclickA6);  //  open ****   we put grab servo in front because the grab need to open first
  delay(500);  
  baseservo.write(rememberclickA1);
  delay(500);
  lowerwaistservo.write(rememberclickA2);
  delay(500);
  elbowservo.write(rememberclickA3);
  delay(500);
  lowesthandservo.write(rememberclickA4);
  delay(500);
  middlehandservo.write(rememberclickA5);
  delay(500);
  grabservo.write(rememberclickB6);  //grab ****  grab servo grab after the others are in position
  
  delay(1000);
  
  baseservo.write(rememberclickB1);
  delay(500);  //the best debounce pushbutton method is use delay
  lowerwaistservo.write(rememberclickB2);
  delay(500); 
  elbowservo.write(rememberclickB3);
  delay(500);  
  lowesthandservo.write(rememberclickB4);
  delay(500);
  middlehandservo.write(rememberclickB5);
  delay(500); 
  grabservo.write(rememberclickC6);  //open grab servo again to drop ****

  
  }


}
