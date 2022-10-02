//***********************************************
#define output4 8
#define output3 7
#define output2 6
#define output1 5
#define bluetoothModuleRx 0
#define bluetoothModuleTx 1
#define trig 3
#define echo 4

//Functions Declarations
void moveForward();
void moveBackward();
void rotateLeft();
void rotateRight();
void stop_car();
int checkDistance();
char checkBluetooth();
/****************************************************************/
char input;
void setup() { // *****************Mazen**********************************
  pinMode(output4, OUTPUT);
  digitalWrite(output4, LOW);
  pinMode(output3, OUTPUT);
  digitalWrite(output3, LOW);
  pinMode(output2, OUTPUT);
  digitalWrite(output2, LOW);
  pinMode(output1, OUTPUT);
  digitalWrite(output1, LOW);
  pinMode(trig,OUTPUT);//take in setup
  pinMode(echo,INPUT);//take in setup
  Serial.begin(9600);
  Serial.setTimeout(10) ;
}
void loop() {
  input = checkBluetooth(); // take character from bluetooth
  if (checkDistance()) {
    switch (input) {
      case 'F':
        moveForward();
        break;
      case 'B':
        moveBackward();
        break;
      case 'L':
        rotateLeft();
        break;
      case 'R':
        rotateRight();
        break;
      case 'S':
        stop_car();
        break;
    }
  }
  else
  { stop_car();
    }
}//***********************************************************



//Function definitions
void moveForward(){//********Mazen**********************
   digitalWrite(output1,HIGH); // move the two motors in same direction forward
   digitalWrite(output2,LOW);
   digitalWrite(output3,HIGH);
   digitalWrite(output4,LOW);
}

void moveBackward(){ //******************Mazen************************
   digitalWrite(output1,LOW); // move the two motors in same direction backward
   digitalWrite(output2,HIGH);
   digitalWrite(output3,LOW);
   digitalWrite(output4,HIGH);
}

void rotateLeft(){//********Mazen**********************
   digitalWrite(output1,LOW); // stop the Left motor and  the right motor will make the car to rotate about it
   digitalWrite(output2,HIGH);
   digitalWrite(output3,LOW);
   digitalWrite(output4,LOW);
}

void rotateRight(){ //************Mazen************************
   digitalWrite(output1,LOW);// stop the Right motor and  the Left motor will make the car to rotate about it
   digitalWrite(output2,LOW);
   digitalWrite(output3,LOW);
   digitalWrite(output4,HIGH);
}

void stop_car() { // **************Mazen**************
  digitalWrite(output1,LOW); // Stop the two motors 
  digitalWrite(output2,LOW);
  digitalWrite(output3,LOW);
  digitalWrite(output4,LOW);  
}


int checkDistance(){ //*****************Sama************************************
int t=0,distance=0;
digitalWrite(trig,LOW);
delayMicroseconds(5);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
t=pulseIn(echo,HIGH);
distance=t/57;
if (distance<=5){
 return 0;}
else{return 1;
}
}
char checkBluetooth() //*******Mohamed*****************************
{ char Mode ;
  while(Serial.available())
  {
    Mode=Serial.read() ;
    Serial.println(Mode) ;
  }
    return Mode ;
  
}
/***********************************************/
