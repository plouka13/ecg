// ECG final code

// Pin usage
#define LOminus 11
#define LOplus 10
#define ecg_read_pin A0 

// Variables
float x,output;
String colors[]={"R0G0B0","R0G150B0"}; //App Light colours for LOW and HIGH
String receive_chars="abcdefghijkl"; //so app knows which data goes where

void setup() {
  // initialize the serial communication:
  Serial.begin(9600); 
  pinMode(LOminus, INPUT); // Setup for leads off detection LO -
  pinMode(LOplus, INPUT); // Setup for leads off detection LO +
}

void loop() {
    
    //Read Digital Pins and Send results over Bluetooth
    for(int i=2;i<=13;i++){
     Serial.print("*"+String("a")+colors[digitalRead(2)]+"*");
     // }
    
    // Read in a value from the ECG sensors
    x = analogRead(ecg_read_pin)*0.4;
    output = x;
  

    Serial.print("*G" + (String)output + "," + "*");
    //Serial.println(output); //only for laptop communication
    
    // Wait for a bit to keep serial data from saturating
    delay(1);
  
}
