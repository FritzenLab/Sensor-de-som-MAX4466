const int sampleWindow = 50;  // Sample window width in mS (50 mS = 20Hz)
int const AMP_PIN = A1;       // Preamp output pin connected to A0
unsigned int sample;

void setup()
{
  Serial.begin(115200);
  pinMode(D8, OUTPUT);
  analogReadResolution(12);
}

void loop()
{
  unsigned long startMillis = millis(); // Start of sample window
  unsigned int peakToPeak = 0;   // peak-to-peak level

  unsigned int signalMax = 0;
  unsigned int signalMin = 3300;

  while (millis() - startMillis < sampleWindow)
  {
    sample = analogRead(AMP_PIN);

    if (sample > signalMax){
      signalMax = sample;
      
    }
    if (sample < signalMin){
      signalMin = sample;
      
    } 
  }

  peakToPeak = signalMax - signalMin;
  if(peakToPeak > 2000){
    digitalWrite(D8, HIGH);
  }else{
    digitalWrite(D8, LOW);
  }
  Serial.println(peakToPeak);

  //double volts = (peakToPeak * 5.0) / 1024;  // convert to volts
  //Serial.println(volts);
}