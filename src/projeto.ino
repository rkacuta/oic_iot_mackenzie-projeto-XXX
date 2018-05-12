#include <Ultrasonic.h>


//Define os pinos para o trigger e echo
#define pino_trigger 2
#define pino_echo 3

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup()
{
  pinMode(13, OUTPUT);//red 1
  pinMode(12,OUTPUT);//yellow 1
  pinMode(11, OUTPUT);//green 1
  pinMode(10, OUTPUT);//red 2
  pinMode(8,OUTPUT);//yellow 2
  pinMode(7, OUTPUT);//green 2
  pinMode(6, OUTPUT);//branca
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}


void loop()
{
  int cont=0;
  //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  long microsec;
 
  //inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  digitalWrite(6,LOW);
  digitalWrite(10, LOW);
  digitalWrite(12,LOW);
  digitalWrite(13, HIGH);
  digitalWrite(7, HIGH);
  while (cont<3){
    //Exibe informacoes no serial monitor
  microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print("Distancia em cm: ");
  Serial.println(cmMsec);
  if (cmMsec<=10){
    digitalWrite(6,HIGH);
    delay(6000);
    //digitalWrite(7, LOW);
    //digitalWrite(8, HIGH);
    break;
  }else{
    cont+=1;
  }
  delay(1000);
  }
  cont= 0;
  delay(1000);
  digitalWrite(6,LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  delay(1000);
  while (cont <2){
    microsec = ultrasonic.timing();
    cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
    Serial.print("Distancia em cm fase 2: ");
    Serial.println(cmMsec);
    if (cmMsec<=10){
      digitalWrite(6,HIGH);
      delay(1000);
      digitalWrite(8, LOW);
      digitalWrite(10, HIGH);
      delay(2000);
    break;
  }else{
    cont+=1;
  }
  delay(1000);
  }
  digitalWrite(6,LOW);
  digitalWrite(8, LOW);
  digitalWrite(13, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  delay(3000); 
  digitalWrite(11, LOW); 
  digitalWrite(12, HIGH);
  delay(2000);
}

