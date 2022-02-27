int enA = 9;
int in1 = 8;
int in2 = 7;
int b1 = 11;
int b2 = 12;
int b3 = 13;
int ir_sensor = A1;
int s_val;

void setup() 
{
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void loop()
{
  int btn1 = digitalRead(b1);
  int btn2 = digitalRead(b2);
  int btn3 = digitalRead(b3);
  int s_val = digitalRead(ir_sensor);
  if(s_val == 1)
  {
    direction_l();
  }
  else if(s_val == 0)
    direction_r();
}

void direction_l() 
{
  analogWrite(enA, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(2000);
}

void direction_r()
{
  analogWrite(enA, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(2000);
}

void stop_motor()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
