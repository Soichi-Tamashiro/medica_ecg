#define bluetooth Serial
int on = 0; // off
int contador=0;
int tiempo;
int tiempo2;
int ecg1;
int ecg2;
int bpm;
int estado=0;
char cmd[100];
int cmdIndex;
int limite=660;
boolean cmdStartsWith(char *st) {
  for(int i=0; ; i++) {
    if(st[i]==0) return true;
    if(cmd[i]==0) return false;
    if(cmd[i]!=st[i]) return false;;
  }
  return false;
}
void exeCmd() {
  
  if( cmdStartsWith("on") ) on = 1;
  if( cmdStartsWith("off") ) on = 0;
     
}
void setup() {
  Serial.begin(9600);
  delay(500); // wait for bluetooth module to start

  bluetooth.begin(9600); // Bluetooth default baud is 115200
  
  cmdIndex = 0;
}
void loop() {
  
  while(bluetooth.available()) {
    
    char c = (char)bluetooth.read();
    
    if(c=='\n') {
      cmd[cmdIndex] = 0;
      exeCmd();  // execute the command
      cmdIndex = 0; // reset the cmdIndex
    } else {      
      cmd[cmdIndex] = c;
      if(cmdIndex<99) cmdIndex++;
    }
    
  }
  
  if(on) {
   
    
if (analogRead(A0)>limite && analogRead(A0)<ecg2)
{
  Serial.print("led 1\n");
  estado=1;
  
}
if (analogRead(A0)<limite && estado==1)
{
  contador=contador+1;
  Serial.print("led 0\n");
  tiempo2=millis()-tiempo;
  estado=0;
  tiempo=millis();
  bpm=60000/tiempo2;
}

    
    bluetooth.print( (String)"A0 " + analogRead(A0) + "\n" );
  
     bluetooth.print( (String)"tiempo " + bpm + "\n" );
     ecg2=analogRead(A0);
    delay(10);
  }
  
}
