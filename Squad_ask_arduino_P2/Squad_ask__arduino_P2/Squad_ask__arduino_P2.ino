/*************************/
// Project : simple car controller
// Authors : Squad Ask
/************************/

//defines
#define output4 2
#define output3 3
#define output2 5
#define output1 4
#define Backward 7
#define Forward 9
#define Right 8
#define Left 6
/*******************/

//Function declarations
void moveForward();
void moveBackward();
void rotateLeft();
void rotateRight();
/***********************/

//Main Program
void setup()
{
  pinMode(output4,OUTPUT);
  digitalWrite(output4,LOW);
  pinMode(output3,OUTPUT);
  digitalWrite(output3,LOW);
  pinMode(output2,OUTPUT);
  digitalWrite(output2,LOW);
  pinMode(output1,OUTPUT);
  digitalWrite(output1,LOW);
  pinMode(Forward,INPUT_PULLUP);
  pinMode(Backward,INPUT_PULLUP);
  pinMode(Right,INPUT_PULLUP);
  pinMode(Left,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  moveForward();
  moveBackward();
  rotateRight();
  rotateLeft();
  delay(100);//to improve simulation performance
  digitalWrite(output1,LOW); 
  digitalWrite(output2,LOW);
  digitalWrite(output3,LOW);
  digitalWrite(output4,LOW);
}
/***********************************/


//Function definitions 
void moveForward(){
  Serial.println(digitalRead(Forward));
  if(digitalRead(Forward) == LOW){
   digitalWrite(output1,HIGH); 
   digitalWrite(output2,LOW);
   digitalWrite(output3,HIGH);
   digitalWrite(output4,LOW);
  }
}


void moveBackward(){
  Serial.println(digitalRead(Backward));
  if(digitalRead(Backward) == LOW){
   digitalWrite(output1,LOW); 
   digitalWrite(output2,HIGH);
   digitalWrite(output3,LOW);
   digitalWrite(output4,HIGH);
  }
}


void rotateLeft(){
  Serial.println(digitalRead(Left));
  if(digitalRead(Left) == LOW){
   digitalWrite(output1,LOW); 
   digitalWrite(output2,LOW);
   digitalWrite(output3,HIGH);
   digitalWrite(output4,LOW);
  }
}


void rotateRight(){
  Serial.println(digitalRead(Right));
  if(digitalRead(Right) == LOW){
   digitalWrite(output1,HIGH); 
   digitalWrite(output2,LOW);
   digitalWrite(output3,LOW);
   digitalWrite(output4,LOW);
  }
}
