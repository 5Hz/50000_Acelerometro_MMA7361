/******************************************************************
** Código creado en Electrónica 5Hz                              **
** www.5hz-electronica.com                                       **
** Por: Rafael Almaguer                                          **
**                                                               **
** Descripción del código:                                       **
**                                                               **
** Ejemplo para el acelerómetro MMA7361                          **
**                                                               **
*******************************************************************
Conexiones:
UNO   MMA7361

3.3V  VCC
GND   GND
10    ST
12    GSEL
13    SLP
*/

//-----------------------------------------------------------definiciones
#define ST 10
#define SLP 13
#define GSEL 11

//--------------------------------------------------definiciones de pines
const int analogInPinX = A0;  
const int analogInPinY = A1;  
const int analogInPinZ = A2;  

//-------------------------------------definiciones de variables globales
int sensorValue = 0;        
int outputValue = 0;   

//----------------------------------------------------------configuracion
void setup()
{
  pinMode(ST,OUTPUT);
  digitalWrite(ST,LOW);
  Serial.begin(9600);
  
  pinMode(SLP,OUTPUT);
  digitalWrite(SLP,HIGH);
  
  pinMode(GSEL,OUTPUT);
  pinMode(GSEL,HIGH);
  Serial.println("Programa de ejemplo para el sensor MMA7361");
  Serial.println("valor x - valor y - valor z");
      digitalWrite(ST,HIGH);
      Serial.println("...");
      Serial.println("sensor ON");
      Serial.println(".............");
      delay(1000);

}

//#########################################################ciclo principal
void loop()
{
  Serial.print(analogRead(analogInPinX));
  Serial.print(" - ");
  Serial.print(analogRead(analogInPinY));
  Serial.print(" - ");
  Serial.println(analogRead(analogInPinZ));
  delay(100);
}
//##################################################fin del ciclo principal
