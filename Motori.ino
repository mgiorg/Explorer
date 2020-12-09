/**
 * Motori.ino
 */

void initMotori()
{
	//inizializzazione pin motori
	pinMode(DIR_SX, OUTPUT);
	pinMode(DIR_DX, OUTPUT);
	pinMode(PWM_SX, OUTPUT);
	pinMode(PWM_DX, OUTPUT);
}

void avanti()
{
	//robot avanti
}

void indietro()
{
	//robot indietro
}

void destra()
{
	//robot destra
}

void sinistra()
{
	//robot sinistra
}

void fermo()
{
	//robot fermo
	digitalWrite(PWM_SX, LOW);
	digitalWrite(PWM_DX, LOW);
}