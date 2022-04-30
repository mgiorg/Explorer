/**
 * Gas.ino
 */

#define PIN_GAS A4
#define SOGLIA_GAS 700

uint8_t handleGas()
{
	int lettura_gas = analogRead(PIN_GAS);

	Serial.print("La lettura del gas: ");
	Serial.println(lettura_gas);

	if(lettura_gas >= SOGLIA_GAS) //se ha rilevato la presenza di gas
	{
		return 1; //GAS TROVATO
	}
	else //se non ha trovato niente
	{
		return 0; //nulla
	}
}