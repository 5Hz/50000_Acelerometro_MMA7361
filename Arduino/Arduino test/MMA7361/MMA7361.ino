#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 2);
#define ST 10
#define SLP 13
#define GSEL 11


const int analogInPinX = A3;  
const int analogInPinY = A4;  
const int analogInPinZ = A5;  

int sensorValue = 0;        
int outputValue = 0;        
int opcion = 0;
int barras;

int entrada;
void setup(){
  pinMode(ST,OUTPUT);
  digitalWrite(ST,LOW);
  Serial.begin(9600);
  
    pinMode(SLP,OUTPUT);
  digitalWrite(SLP,HIGH);
  
  pinMode(GSEL,OUTPUT);
  pinMode(GSEL,LOW);

//  do{
//  }while(Serial.available()==0);
//  if(Serial.available()>0){
    menu();
//  }
}

void loop(){
  if (opcion == 1)  // indica que se seleccionó una opción válida
    leer_sensor_x();
    if (opcion == 2)  // indica que se seleccionó una opción válida
    leer_sensor_y();
    if (opcion == 3)  // indica que se seleccionó una opción válida
    leer_sensor_z();
   
   if ((opcion == 4) || (opcion == 5)|| (opcion == 0)||(opcion == 6)||(opcion == 7)||(opcion == 8)||(opcion == 9))
    menu();
  if (Serial.available()){
    entrada=Serial.read();
    if(entrada=='*'){
      menu();
    }
    
  }
}


void menu(){
  int entradaMenu;
  Serial.println("-------------------5HZ ELECTRONICA---------------------------");
  Serial.println("");
  Serial.println("                     PRESENTA");
  Serial.println("");
  Serial.println("*************************************************************");
  Serial.println("");
  Serial.println("      BIEVENIDO AL PROGRAMA DE PRUEBAS DEL MMA7361");
  Serial.println("");
  Serial.println("            YA ESTAS LISTO? ");
Serial.println("");
    Serial.println("*************************************************************");
  Serial.println("");
  Serial.println("MENU PRINCIPAL");
  Serial.println("1- X");
  Serial.println("2- Y");
  Serial.println("3- Z");
  Serial.println("4- ACTIVAR SELFTEST");
  Serial.println("5- DESACTIVAR SELFTEST (MODO NORMAL)");
  Serial.println("6- A DORMIR");
  Serial.println("7- DESPERTAR");
  Serial.println("8- SENSIBILIDAD 1.5G");
  Serial.println("9- SENSIBILIDAD 6G");
  
 
  do{
  }while(Serial.available()==0);
      entradaMenu=Serial.read();
    switch(entradaMenu){
   
    case '4':
      digitalWrite(ST,HIGH);
       Serial.println("");
      Serial.println("SELF TEST Activado");
     
      delay(1000);
      opcion = 4;
      break;
      
    case '5':
       digitalWrite(ST,LOW);
      Serial.println("");
      Serial.println("MODO NORMAL DE OPERACION");
      Serial.println(".............");
      delay(1000);
      opcion = 5;
      break;

    case '6':
       digitalWrite(SLP,LOW);
      Serial.println("");
      Serial.println("ESTOY ZZzz.....");
      Serial.println(".............");
      delay(1000);
      opcion = 6;
      break;
      
    case '8':
       digitalWrite(GSEL,LOW);
      Serial.println("");
      Serial.println("ESTOY 1.5G SENSIBLE");
      Serial.println(".............");
      delay(1000);
      opcion = 8;
      break;
      
     case '7':
       digitalWrite(SLP,HIGH);
      Serial.println("");
      Serial.println("ON");
      Serial.println(".............");
      delay(1000);
      opcion = 7;
      break;
      
    case '9':
       digitalWrite(GSEL,HIGH);
      Serial.println("");
      Serial.println("ESTOY A 6G");
      Serial.println(".............");
      delay(1000);
      opcion = 9;
      break;
      
        case '1':
      Serial.println("");
      Serial.println("X");
      Serial.println(".............");
      delay(1000);
      opcion = 1;
      break;
      
      
        case '2':
 
      Serial.println("");
      Serial.println("Y");
      Serial.println(".............");
      delay(1000);
      opcion = 2;
      break;
      
      
        case '3':
     Serial.println("");
      Serial.println("Z");
      Serial.println(".............");
      delay(1000);
      opcion = 3;
      break;
      
      
    default:
      Serial.println("Opcion no válida ");
      opcion = 0;
      break;
    }
    
    if ((opcion == 1) || (opcion == 2) || (opcion == 3))
    Serial.println("Hola soy la TERMINAL DE 5Hz (teclea * para ir al menu) cuando termines ");
    delay(1000);

}

  
  
void leer_sensor_x() {
  // read the analog in value:
  sensorValue = analogRead(analogInPinX);            
  // map it to the range of the analog out:
//  outputValue = map(sensorValue, 0, 1023, 0, 255);  
  // change the analog out value:


  barras = sensorValue / 15;
  
  for (int i=0; i <= barras; i++)
     Serial.print("-");
  Serial.print(" ");
//  Serial.print("sensor = " );                       
  Serial.println(sensorValue);      
//  Serial.print("output = ");      
//  Serial.println(outputValue);   

  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10);   
}

void leer_sensor_y() {
  // read the analog in value:
  sensorValue = analogRead(analogInPinY);            
  // map it to the range of the analog out:
//  outputValue = map(sensorValue, 0, 1023, 0, 255);  
  // change the analog out value:


  barras = sensorValue / 15;
  
  for (int i=0; i <= barras; i++)
     Serial.print("-");
  Serial.print(" ");
//  Serial.print("sensor = " );                       
  Serial.println(sensorValue);      
//  Serial.print("output = ");      
//  Serial.println(outputValue);   

  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10);   
}

void leer_sensor_z() {
  // read the analog in value:
  sensorValue = analogRead(analogInPinZ);            
  // map it to the range of the analog out:
//  outputValue = map(sensorValue, 0, 1023, 0, 255);  
  // change the analog out value:


  barras = sensorValue / 15;
  
  for (int i=0; i <= barras; i++)
     Serial.print("-");
  Serial.print(" ");
//  Serial.print("sensor = " );                       
  Serial.println(sensorValue);      
//  Serial.print("output = ");      
//  Serial.println(outputValue);   

  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10);   
}
