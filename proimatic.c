boolean stringComplete = false;
String inputString = ""; int n = 0;
#define BUZZ 5
void setup() { Serial.begin(9600); pinMode(BUZZ, OUTPUT); digitalWrite(BUZZ,HIGH); inputString.reserve(200);
}
void loop() {
if (stringComplete) {
Serial.println(inputString);
if (inputString.equals("0B0026E73EF4")) { //A
digitalWrite(BUZZ, !digitalRead(BUZZ)); }
if (inputString.equals("0B0027030B24")) { //B digitalWrite(BUZZ, !digitalRead(BUZZ));
}
stringComplete = false;
inputString = ""; }
}
void serialEvent() {
while (Serial.available()) {
n++;
char inChar = (char) Serial.read();
inputString += inChar; if (n >= 12) {
n = 0;
stringComplete = true; }
} }
int int=9;
int sensor = 8;
int led = 13; unsigned long t=0; void setup() {
Serial.begin(9600); pinMode(in1, OUTPUT); pinMode(sensor, INPUT); pinMode(led, OUTPUT); digitalWrite(in1,HIGH); digitalWrite(led,LOW); while(millis()<13000)
{ Serial.println("detecting"); digitalWrite(led,HIGH); delay(50); digitalWrite(led,LOW); delay(50);
}
digitalWrite(led,LOW);
}
void loop() {digitalWrite(in1,HIGH); digitalWrite(led,LOW); if(digitalRead(sensor)==HIGH) { t=millis(); while(millis()<(t+5000))
{
Serial.println("motion detected"); digitalWrite(in1,LOW); digitalWrite(led,HIGH);
if((millis()>(t+2300))&&(digitalRead(sensor)==HIGH)) {
t=millis(); }
}
}
}
