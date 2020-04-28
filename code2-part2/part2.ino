const int pin = 13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  static int timeInterval = 100;
  digitalWrite(pin, HIGH);
  delay(timeInterval);
  digitalWrite(pin, LOW);
  delay(timeInterval);
  static int dir = 1;
  dir = changeDir(dir, timeInterval);
  timeInterval+=dir*100;
  Serial.println(timeInterval);    
}
int changeDir(int dir, int timeInterval)
{
  if((timeInterval==0)||(timeInterval==500))
  {
    if(dir>0)
    dir=-1;
    else
    dir=1;
  }
  return(dir);
}
