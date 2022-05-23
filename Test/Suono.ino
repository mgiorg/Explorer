/**
 * Suono.ino
 * Massimo Giordano
 */
#define PIN_SUONO A5
#define SOGLIA_SUONO 700

int lettura_max = 0;

uint8_t handleSuono()
{
	//lettura sensore del suono e uscita dalla sorgente
	int lettura_suono = analogRead(PIN_SUONO);
	
	if(lettura_suono >= lettura_max)
	{
		lettura_max = lettura_suono;
	}

	Serial.print("Il suono rilevato: ");
	Serial.print(lettura_suono);
	Serial.print("		---		  Il massimo valore: ");
	Serial.println(lettura_max);

	/*if(lettura_suono >= SOGLIA_SUONO) //se ha sentito il suono
	{
		return 1;
	}
	else
	{
		return 0;
	}*/
	return lettura_suono;
}