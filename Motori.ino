/**
 * Motori.ino
 * Massimo Giordano
 */
#define DIR_A2 4
#define DIR_B2 3
#define DIR_A1 7
#define DIR_B1 8
#define PWM_2 9
#define PWM_1 6

void initMotori()
{
	//inizializzazione pin motori
	pinMode(DIR_A1, OUTPUT);
	pinMode(DIR_B1, OUTPUT);
	pinMode(DIR_A2, OUTPUT);
	pinMode(DIR_B2, OUTPUT);
	pinMode(PWM_1, OUTPUT);
	pinMode(PWM_2, OUTPUT);
}

void avanti()
{
	digitalWrite(DIR_A1, LOW);
	digitalWrite(DIR_B1, HIGH);
	analogWrite(PWM_1, 252);

	digitalWrite(DIR_A2, LOW);
	digitalWrite(DIR_B2, HIGH);
	analogWrite(PWM_2, 255);
}

void indietro()
{
	digitalWrite(DIR_A1, HIGH);
	digitalWrite(DIR_B1, LOW);
	analogWrite(PWM_1, 255);

	digitalWrite(DIR_A2, HIGH);
	digitalWrite(DIR_B2, LOW);
	analogWrite(PWM_2, 255);
}

void destra()
{
	digitalWrite(DIR_A1, LOW);
	digitalWrite(DIR_B1, HIGH);
	analogWrite(PWM_1, 255);

	digitalWrite(DIR_A2, HIGH);
	digitalWrite(DIR_B2, LOW);
	analogWrite(PWM_2, 255);
}

void sinistra()
{
	digitalWrite(DIR_A1, HIGH);
	digitalWrite(DIR_B1, LOW);
	analogWrite(PWM_1, 255);

	digitalWrite(DIR_A2, LOW);
	digitalWrite(DIR_B2, HIGH);
	analogWrite(PWM_2, 255);
}

void fermo()
{
	digitalWrite(DIR_A1, HIGH);
	digitalWrite(DIR_B1, HIGH);
	analogWrite(PWM_1, 0);

	digitalWrite(DIR_A2, HIGH);
	digitalWrite(DIR_B2, HIGH);
	analogWrite(PWM_2, 0);
}