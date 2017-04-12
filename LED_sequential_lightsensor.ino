//array of LEDS

int LEDS[4] = {3, 5, 6, 9};

//int button = 13;
//int button2 = 12;

int cnt = 0;
const int light_sensor = A0;

int sensorhigh = 108;
int sensorlow = 0;



void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 4; i++) {
    pinMode(LEDS[i], OUTPUT);
    Serial.println("ready");
  }
  pinMode(light_sensor, INPUT);
}

void loop() {
  float reading = map(analogRead(light_sensor), sensorlow, sensorhigh, 0, 1024);

  if (reading > 30) {
    if (cnt % 4 == 0) {
      for (int a = 0; a < 4; a++) {
        digitalWrite(LEDS[a], LOW);
      }
    }
    //using example for fade
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      // sets the value (range from 0 to 255):
      analogWrite(LEDS[abs(cnt) % 4], fadeValue);
      // wait for 30 milliseconds to see the dimming effect
      delay(5);
    }
    Serial.println(cnt);
    cnt++;

  }
}
