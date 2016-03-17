int getBatteryLevel(String command);

float fBattery=0;
float fBatteryLast=0;
FuelGauge fuel;


void setup() {
  Serial.begin(9600);
  Serial.println("Starting up");
  //Particle.variable("batteryLevel", fBattery);
  bool success = Particle.function("batteryLevel", getBatteryLevel);
}

void loop() {
  fBattery=fuel.getSoC();

  if(fBatteryLast!=fBattery){
    Serial.print("Battery Level Changed! ");
    Serial.println(fBattery);
    Particle.publish("BatteryLevel",String(fBattery));
  }

  fBatteryLast=fBattery;
  delay(500);
}

int getBatteryLevel(String command){
  Serial.println("Fetching battery level");
  return (int)fBattery;
}
