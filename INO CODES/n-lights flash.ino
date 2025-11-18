// arduino-led-multimethod/
// * YOU CAN ALWAYS ALTER THE DELAY FOR YOUR OWN SAKE 
// #1. GENERAL APPROACH

// 01_basic/basic_blink.ino

void setup() {
  pinMode(7, OUTPUT);
}
void loop() {
  digitalWrite(7, HIGH);
  delay(500);
  digitalWrite(7, LOW);
  delay(500);
}

// #2. BY VARIABLES
//02_variable/variable_led.ino

int ledPin = 7; 
void setup() {
  pinMode(ledPin, OUTPUT);
}
void loop() {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
}


// #3. BY ARRAYS
// 03_array/array_led.ino

int ledPins[] = {7};
int n = 1;
void setup() {
  for (int i = 0; i < n; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}
void loop() {
  for (int i = 0; i < n; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
  delay(500);
  for (int i = 0; i < n; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  delay(500);
}


// #4. BY CONSTANTS
// 04_const/const_led.ino

int ledPins[] = {7};
int n = 1;
void setup() {
  for (int i = 0; i < n; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}
void loop() {
  for (int i = 0; i < n; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
  delay(500);
  for (int i = 0; i < n; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  delay(500);
}


// #5. NO DELAY VERSION /STATE MACHINE
// 05_state_machine/ state_machine_led.ino

const int LED = 7;
unsigned long previousMillis = 0;
int state = LOW;
const long interval = 500;
void setup() {
  pinMode(LED, OUTPUT);
}
void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    state = !state;
    digitalWrite(LED, state);
  }
}

// #6. LOGICAL (if) 
// 06_if_logic/if_logic.ino

const int LED = 7;
void setup() { pinMode(LED, OUTPUT); }
void loop() {
  if (true) digitalWrite(LED, HIGH);
  delay(500);
  if (true) digitalWrite(LED, LOW);
  delay(500);
}

// #7. LOGICAL (while) 
// 07_while_method/ while_led.ino

void setup() { pinMode(7, OUTPUT); }
void loop() {
  int i = 0;
  while(i < 1) {
    digitalWrite(7, HIGH); delay(500);
    digitalWrite(7, LOW);  delay(500);
    i++;
  }
}

// #8. LOGICAL (for)
// 08_for_loop/for_led.ino

void setup() { pinMode(7, OUTPUT); }
void loop() {
  for(int i=0;i<1;i++){
    digitalWrite(7, HIGH);
    delay(500);
    digitalWrite(7, LOW);
    delay(500);
  }
}

// #9 MULTIPLE LED 
// 09_multi_led/multi_led_array.ino

int pins[] = {13, 7, 4, 2};
int n = 4;
void setup() {
  for(int i=0;i<n;i++) pinMode(pins[i],OUTPUT);
}
void loop() {
  for(int i=0;i<n;i++) digitalWrite(pins[i],HIGH);
  delay(500);
  for(int i=0;i<n;i++) digitalWrite(pins[i],LOW);
  delay(500);
}

// #10 RANDON LED LIGHTING (PREMISE:  #2,#4,#7 and #13 pin ~ you may change them if you want)
// 10_random_led/random_led.ino

int pins[] = {2,4,7,13};
int n = 4;
void setup() {
  for (int i=0;i<n;i++) pinMode(pins[i], OUTPUT);
  randomSeed(analogRead(0));
}
void loop() {
  int i = random(0,n);
  digitalWrite(pins[i], HIGH);
  delay(500);
  digitalWrite(pins[i], LOW);
}