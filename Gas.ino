/**
 * Gas.ino
 */

#define PIN_GAS A4
#define SOGLIA_GAS 220

int prev_read_gas = 0;

uint8_t handleGas()
{
	int lettura_gas = analogRead(PIN_GAS);

	Serial.print("La lettura del gas: ");
	Serial.print(lettura_gas);

	if(lettura_gas >= SOGLIA_GAS) //se ha rilevato la presenza di gas
	{
		if(lettura_gas > (prev_read_gas + 1)) 
		{
			prev_read_gas = lettura_gas;

			return 1; //GAS TROVATO
		}
		else 
		{
			prev_read_gas = lettura_gas;

			return 0;
		}
	}		
	else //se non ha trovato niente
	{
		prev_read_gas = lettura_gas;

		return 0; //nulla
	}
}