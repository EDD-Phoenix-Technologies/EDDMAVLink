
static long leftSpeed = 1000, rightSpeed = 1000;
static const char m = 'm', l = 'l', r = 'r',
                 t = 't';
static bool isLeftTest = false, isRightTest = false, isTest = false;



void setup() {
Serial.begin(115200); // set the baud rate
Serial.println("Ready"); // print "Ready" once
}



void loop() {
 parseMotorData();
 printMotorData();
}



/**
* Parses data in the format 'mlNUMBER' or 'mrNUMBER' and sets
* the speeds for the left or right motors, respectively, to NUMBER
*/
static inline void parseMotorData() {
 if(Serial.available()){
   if (Serial.peek() == t) {
     isTest = true;
     Serial.read();
   } else {
     isTest = false;
   }
   if (Serial.peek() == m) {
     Serial.read();
     if (Serial.peek() == l) {
       isLeftTest = isTest;
       Serial.read();
       leftSpeed = Serial.parseInt();
     } else if (Serial.peek() == r) {
       isRightTest = isTest;
       Serial.read();
       rightSpeed = Serial.parseInt();
     }
   } else {
     Serial.read();
   }
 }
}



/**
* Prints the motor speeds. Used mainly for testing and ensuring that the motors work
*/
static inline void printMotorData() {
 Serial.print("left speed: ");
 if (isLeftTest) {
   Serial.print("(test) ");
 }
 Serial.println(leftSpeed);
 Serial.print("right speed: ");
 if (isRightTest) {
   Serial.print("(test) ");
 }
 Serial.println(rightSpeed);
}

