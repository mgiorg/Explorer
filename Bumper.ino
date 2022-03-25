/**
 * Bumper.ino
 */
#define BUMP_SX 11
#define BUMP_DX 12

void initBumper()
{
	//inizializzazione pin bumper
	pinMode(BUMP_SX, INPUT_PULLUP);
	pinMode(BUMP_DX, INPUT_PULLUP);
}

uint8_t handleBumper() //l'ho fatta in maniera molto semplice, la rendo più completa dopo le prive in campo
{
	//lettura bumper e correzione del movimento
	uint8_t lettura_bump_sx = digitalRead(BUMP_SX);
	uint8_t lettura_bump_dx = digitalRead(BUMP_DX);

	if(lettura_bump_sx == LOW) //se ha colpito la parete a sinistra
	{
		return 1;
	}
	else if(lettura_bump_dx == LOW) //se ha copito la parete a destra
	{
		return 2;
	}
	else
	{
		return 0;
	}
}	
