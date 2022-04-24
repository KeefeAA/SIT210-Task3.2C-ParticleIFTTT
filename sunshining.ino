int led = A5; 
int photoresistor = A1;
int analogValue;

bool Is_Shining;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(photoresistor, INPUT);
  Is_Shining = false;
}


void loop() {
    analogValue = analogRead(photoresistor);
    if(analogValue > 250 && !Is_Shining)
    {
        digitalWrite(led, LOW);
        Particle.publish("Sunlight_lvl", "Sun_Shining");
        Is_Shining = true;
    }
    else if(analogValue < 250 && Is_Shining)
    {
        digitalWrite(led, HIGH); 
        Particle.publish("Sunlight_lvl", "Sun_Not_Shining");
        Is_Shining = false;
    }
    delay(5000);
}