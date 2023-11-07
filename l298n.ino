// Motor A connections
int enA = 4;
int IN1 = 7;
int IN2 = 6;

void setup() {
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  Serial.begin(9600);
}



void den(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
void den1(int tocdo){
  tocdo = constrain(tocdo,0, 255);
  digitalWrite(IN1, HIGH);
  analogWrite(IN2, 255 - tocdo);
}
