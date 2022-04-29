/**
 * Gas.ino
 */

/**
 * definizione pin sensore di gas
 */
#define PIN_GAS A4

#define SOGLIA_GAS 0 //Impostare

uint8_t handleGas()
{
	int lettura_gas = analogRead(PIN_GAS);

	if(lettura_gas >= SOGLIA_GAS) //se ha rilevato la presenza di gas
	{
		return 1; //GAS TROVATO
	}
	else //se non ha trovato niente
	{
		return 0; //nulla
	}
}