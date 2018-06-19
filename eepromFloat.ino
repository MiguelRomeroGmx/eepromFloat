#include <EEPROM.h>

float f = 0.00f; 
float dato;
int eeAddress = 2;
int segundos, minuto;
long millis_anteriores = 0;        //  Almacenara la ultima vez que el LED fue actualizado

// la siguiente variable es tipo long porque representa el tiempo, medido en milisegundos.
long intervalo = 1000;      

void setup() {
  Serial.begin(9600);

  Serial.print("Valor anterior: ");
  EEPROM.get( eeAddress, f );
  Serial.println( f, 3 ); 
  
}

void loop() {




unsigned long millis_actuales = millis();
 
  if(millis_actuales - millis_anteriores > intervalo) {
    // almacena la ultima vez que parpadeo el LED
    millis_anteriores = millis_actuales;  

   segundos++;

   if(segundos==30){
       segundos=0;
       minuto++;
       Serial.print( "minutos: " ); 
       Serial.println( minuto ); 
        f += 0.34;
       Serial.print( "memoria: " ); 
       Serial.println( f ); 
       EEPROM.put( eeAddress, f );

   }






  }
	

}