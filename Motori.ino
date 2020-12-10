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
	digitalWrite(DIR_SX, LOW); //il motore sinistro gira in senso antiorario
	digitalWrite(DIR_DX, HIGH); //il motore destro gira in senso orario
	digitalWrite(PWM_SX, HIGH); //potenza massima
	digitalWrite(PWM_DX, HIGH); //potenza massima
}

void indietro()
{
	//robot indietro
	digitalWrite(DIR_SX, HIGH); //il motore sinistro gira in senso orario
	digitalWrite(DIR_DX, LOW); //il motore destro gira in senso antiorario
	digitalWrite(PWM_SX, HIGH); //potenza massima
	digitalWrite(PWM_DX, HIGH); //potenza massima
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