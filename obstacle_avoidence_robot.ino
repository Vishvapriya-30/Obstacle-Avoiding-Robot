int trigPin = 9;    
int echoPin = A0;    

int revleft = 5;       
int fwdleft = 3;       
int revright = 6;      
int fwdright = 10;     

long duration;
int cm;

void setup() {
     
  Serial.begin(9600);
  pinMode(revleft, OUTPUT);     
  pinMode(fwdleft, OUTPUT);
  pinMode(revright, OUTPUT);
  pinMode(fwdright, OUTPUT);
  
  pinMode(trigPin, OUTPUT);                
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin, HIGH); 
  cm = (duration / 29)/2;  
  delay(10);
  
  if(cm<12)
  {
    Serial.print("Obstacle at distance:");
    Serial.println(cm); 
    analogWrite(fwdright, 0);                 
    analogWrite(revright, 0);
    analogWrite(fwdleft, 0);                                
    analogWrite(revleft, 0);
    Serial.println("Stopped"); 
    delay(500);
    analogWrite(fwdright, 0);     
    analogWrite(revright, 150);
    analogWrite(fwdleft, 0);                                
    analogWrite(revleft, 150);
    Serial.println("Backward"); 
    delay(1000);
    analogWrite(fwdright, 0);           
    analogWrite(revright, 0);
    analogWrite(fwdleft, 0);                                
    analogWrite(revleft, 0);  
    Serial.println("Stopped"); 
    delay(200);  
    analogWrite(fwdright, 0);       
    analogWrite(revright, 0);   
    analogWrite(revleft, 0);                                 
    analogWrite(fwdleft, 150);
    Serial.println("turning left");   
    delay(500);
    analogWrite(fwdright, 150);                    
    analogWrite(revright, 0);
    analogWrite(fwdleft, 150);                                
    analogWrite(revleft, 0);    
    Serial.println("Moving"); 
    delay(500);
    analogWrite(fwdright, 150);       
    analogWrite(revright, 0);   
    analogWrite(revleft, 0);                                 
    analogWrite(fwdleft, 0);
    Serial.println("turning right");   
    delay(500);
  }
  else
  {
    analogWrite(fwdright, 150);                    
    analogWrite(revright, 0);
    analogWrite(fwdleft, 150);                                
    analogWrite(revleft, 0);    
    Serial.println("Moving");                                                   
  }
}
