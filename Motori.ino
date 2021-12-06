/**
 * Motori.ino
 * Massimo Giordano
 */

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

/**
 * funzione unica con parametro che sceglie quale movimento effettuare
 * ricordarsi di modificare le direzioni dei motori e la velocità per ogni pwm
 */
void movimento(char carattere) 
{
	switch(carattere)
	{
		case 'A':
			//Il robot deve andare avanti
			digitalWrite(DIR_A1, HIGH);
			digitalWrite(DIR_B1, LOW);
			analogWrite(PWM_1, HIGH);

			digitalWrite(DIR_A2, LOW);
			digitalWrite(DIR_B2, HIGH);
			analogWrite(PWM_2, HIGH);
		break;

		case 'I':
			//Il robot deve andare indietro
			digitalWrite(DIR_A1, LOW);
			digitalWrite(DIR_B1, HIGH);
			analogWrite(PWM_1, HIGH);

			digitalWrite(DIR_A2, HIGH);
			digitalWrite(DIR_B2, LOW);
			analogWrite(PWM_2, HIGH);
		break;

		case 'D':
			//Il robot deve girare a destra
			//Il motore di destra deve andare in dietro e quello di sinistra avanti
			digitalWrite(DIR_A1, HIGH);
			digitalWrite(DIR_B1, LOW);
			analogWrite(PWM_1, HIGH);

			digitalWrite(DIR_A2, HIGH);
			digitalWrite(DIR_B2, LOW);
			analogWrite(PWM_2, HIGH);
		break;

		case 'S':
			//Il robot deve girare a sinistra
			//Il motore di destra deve andare avanti e quello di sinistra indietro
			digitalWrite(DIR_A1, LOW);
			digitalWrite(DIR_B1, HIGH);
			analogWrite(PWM_1, HIGH);

			digitalWrite(DIR_A2, LOW);
			digitalWrite(DIR_B2, HIGH);
			analogWrite(PWM_2, HIGH);
		break;

		case 'F':
			digitalWrite(DIR_A1, HIGH);
			digitalWrite(DIR_B1, HIGH);
			analogWrite(PWM_1, LOW);

			digitalWrite(DIR_A2, HIGH);
			digitalWrite(DIR_B2, HIGH);
			analogWrite(PWM_2, LOW);
		break;
	}
}