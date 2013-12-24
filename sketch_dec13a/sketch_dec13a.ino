int rFrontSensor = A0;
int rBackSensor = A1;
int forwardSensor = A2;
int leftMotor = 13;
int rightMotor = 12;
int en = 11;
int rFrontValue = 0;
int rBackValue = 0;
int forwardValue = 0;
 
void setup() {
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor,OUTPUT);
  pinMode(en, OUTPUT);
  Serial.begin(9600);
}

void loop () {  
  rFrontValue = analogRead(rFrontSensor);
  rBackValue = analogRead(rBackSensor);
  forwardValue = analogRead(forwardSensor);
  digitalWrite(en, HIGH);
  digitalWrite(leftMotor, HIGH);
  digitalWrite(rightMotor, HIGH);
  
  Serial.print(rFrontValue);
  Serial.print(" ");
  Serial.print(rBackValue);
  Serial.print(" ");
  Serial.print(forwardValue);
  Serial.println("");
  
  if (forwardValue < 800 && rFrontValue < 800 && rBackValue > 800){ //stuck in corner - move back, then turn left
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, LOW);
    delay(150);    
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, HIGH);
    delay(300);
    
  }else if(forwardValue < 800 && rFrontValue > 800 && rBackValue > 800){ //hits directly in wall straight
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, LOW);
    delay(150); 
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, HIGH);
    delay(300);
    
  }else if (forwardValue > 800 && rFrontValue < 800 && rBackValue > 800){
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, HIGH);
    delay(200);
    
  }else if(forwardValue > 800 && rFrontValue < 800 && rBackValue < 800){
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, HIGH);
    delay(300);
    
  }else if (forwardValue > 800 && rFrontValue > 800 && rBackValue < 800){ // back sensor only, turn right into wall
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, HIGH);
    delay(1000);
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, LOW);
    delay(200);
    
  }else if (forwardValue > 800 && rFrontValue > 800 && rBackValue > 800){ 
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, HIGH);
    
  }else if(forwardValue < 800 && rFrontValue < 800 && rBackValue < 800){
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, LOW);
    delay(100);
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, HIGH);
    delay(300);
    

  }else if (forwardValue < 800 && rFrontValue > 800 && rBackValue < 800){
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, LOW);
    delay(100);
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, HIGH);
    delay(300);
  }
  
}
