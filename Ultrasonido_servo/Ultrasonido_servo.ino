

#include <Servo.h>
#define Pecho 6
#define Ptrig 7
long duracion, distancia;   
Servo brazos;
 
void setup() {                
  Serial.begin (9600);       // inicializa el puerto seria a 9600 baudios
  pinMode(Pecho, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(Ptrig, OUTPUT);    // define el pin 7 como salida  (triger)
  pinMode(3, OUTPUT);    // define el pin 7 como salida  (triger)
  pinMode(4, OUTPUT);    // define el pin 7 como salida  (triger)
  brazos.attach(9);
  brazos.write(0);
}
  
void loop() {

  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
  
  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion/2) / 29;            // calcula la distancia en centimetros
  
  if (distancia >= 45 || distancia < 0){  // si la distancia es mayor a 500cm o menor a 0cm 
    Serial.println("---");// no mide nada
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    brazos.write(0);
    delay(100);    
  }
  else{
    Serial.print(distancia);           // envia el valor de la distancia por el puerto serial
    Serial.println("cm");              // le coloca a la distancia los centimetros "cm"
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    brazos.write(180);  
    delay(7000); 
  }
  
  delay(200);                                // espera 400ms para que se logre ver la distancia en la consola
} 
