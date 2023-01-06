// the setup function runs once when you press reset or power the board
void setup() {

  Serial.begin(9600);

  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
  digitalWrite(17, HIGH);
  digitalWrite(18, HIGH);
  digitalWrite(19, HIGH);
  delay(1000); 
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);
  digitalWrite(16, LOW);
  digitalWrite(17, LOW);
  digitalWrite(18, LOW);
  digitalWrite(19, LOW);
  delay(1000);   

  digitalWrite(14, HIGH);
  delay(1000); 
  digitalWrite(14, LOW);
  delay(1000);   

    digitalWrite(15, HIGH);
  delay(1000); 
  digitalWrite(15, LOW);
  delay(1000);   

    digitalWrite(16, HIGH);
  delay(1000); 
  digitalWrite(16, LOW);
  delay(1000);   

    digitalWrite(17, HIGH);
  delay(1000); 
  digitalWrite(17, LOW);
  delay(1000);   

    digitalWrite(18, HIGH);
  delay(1000); 
  digitalWrite(18, LOW);
  delay(1000);   

    digitalWrite(19, HIGH);
  delay(1000); 
  digitalWrite(19, LOW);
  delay(1000);    
}
