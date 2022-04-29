/**
 * Suono.ino
 * Massimo Giordano
 */
#define PIN_SUONO A5
#define SOGLIA_SUONO 0

uint8_t handleSuono()
{
	//lettura sensore del suono e uscita dalla sorgente
	int lettura_suono = analogRead(PIN_SUONO);

	if(lettura_suono >= SOGLIA_SUONO) //se ha sentito il suono
	{
		return 1;
	}
	else
	{
		return 0;
	}
}