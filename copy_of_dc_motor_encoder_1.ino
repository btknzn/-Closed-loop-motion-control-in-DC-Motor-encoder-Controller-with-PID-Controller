//Batu Kaan özen Hande yıldırım 141201079 -141202047
//Adjust TargetDegre from here which degre do you want
float targetDeg=360 ;
const int motorDirPin = 5; // Input 1
const int motorPWMPin = 6; // Input 2
const int EnablePin = 9;	// Enable
const int LED = 13;
// encoder pin
const int encoderPinA = 2;
const int encoderPinB = 3;
int encoderPos = 0;
float error;
float previouserror;
float cumerror;
// encoder value change motor turn angles
const float ratio = 360./188.611/48.;
// 360. -> 1 turn
// 188.611 -> Gear Ratio
// 48. -> Encoder: Countable Events Per Revolution (Motor Shaft)

// P control
float Kp = 30;
float Ki = 0.0001;
float kd = 10;
void doEncoderA()
{  
  encoderPos += (digitalRead(encoderPinA)==digitalRead(encoderPinB))?1:-1;
}
void doEncoderB()
{  
  encoderPos += (digitalRead(encoderPinA)==digitalRead(encoderPinB))?-1:1;
}

void doMotor(bool dir, int vel)
{
  digitalWrite(motorDirPin, dir);
  digitalWrite(LED, dir);
  analogWrite(motorPWMPin, dir?(255 - vel):vel);
}

void setup()
{
  Serial.begin(9600);
  pinMode(encoderPinA, INPUT_PULLUP);
  attachInterrupt(0, doEncoderA, CHANGE);
  
  pinMode(encoderPinB, INPUT_PULLUP);
  attachInterrupt(1, doEncoderB, CHANGE);
  
  pinMode(LED, OUTPUT);
  pinMode(motorDirPin, OUTPUT);
  pinMode(EnablePin, OUTPUT);
  cumerror=0;
  previouserror=0;
}

void loop()
{
  cumerror=cumerror+error;
  previouserror=error;
  float motorDeg = float(encoderPos)*ratio;
  error = targetDeg - motorDeg;
  float control = Kp*error+Ki*cumerror+kd*(error-previouserror);
  digitalWrite(EnablePin, 255);
  doMotor((control>=0)?HIGH:LOW, min(abs(control), 255));
  Serial.print("encoderPos : ");
  Serial.print(encoderPos);
  Serial.print("   motorDeg : ");
  Serial.print(float(encoderPos)*ratio);
  Serial.print("   error : ");
  Serial.println(error);
  
  if( abs(error) < 0.02 ){
    digitalWrite(LED,HIGH);
    while(1);
  }
}
