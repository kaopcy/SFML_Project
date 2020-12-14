//declare variables for the motor pins
int motorPin1 = 8; // Blue
int motorPin2 = 9; // Pink
int motorPin3 = 10; // Yellow
int motorPin4 = 11; // Orange
// Red
int motorSpeed = 5; //variable to set stepper speed
int stepCount = 0; // number of steps the motor has taken
void wavedrive();
void setup()
{
  pinMode(motorPin1, OUTPUT); //declare the motor pins as outputs
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  Serial.begin(115200); // initialize the serial port:
}

void loop()
{
  wavedrive();
  Serial.print("steps:" );
  Serial.println(stepCount);
  stepCount++;
}

void wavedrive()
{
  // 8
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, HIGH);
  delay(motorSpeed);
  // 7
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, HIGH);
  delay(motorSpeed);
  // 6
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, HIGH);
  delay (motorSpeed);
  // 5
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, HIGH);
  delay(motorSpeed);
  // 4
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, LOW);
  delay(motorSpeed);
  // 3
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, LOW);
  delay(motorSpeed);
  // 2
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, LOW);
  delay (motorSpeed);

  // 1
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, LOW);
  delay(motorSpeed);
}
