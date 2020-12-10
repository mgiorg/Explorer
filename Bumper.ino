/**
 * Bumper.ino
 */

void initBumper()
{
	//inizializzazione pin bumper
	pinMode(BUMP_SX, INPUT);
	pinMode(BUMP_DX, INPUT);
}

uint8_t handleBumper() //l'ho fatta in maniera molto semplice, la rendo più completa dopo le prive in campo
{
	//lettura bumper e correzione del movimento
	uint8_t lettura_bump_sx = digitalRead(BUMP_SX);
	uint8_t lettura_bump_dx = digitalRead(BUMP_DX);

	if(lettura_bump_sx == HIGH) //se ha colpito la parete a sinistra
	{
		return 1;
	}
	else if(lettura_bump_dx == HIGH) //se ha copito la parete a destra
	{
		return 2;
	}
	else
	{
		return 0;
	}
}	
