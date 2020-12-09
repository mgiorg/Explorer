/**
 * Explorer.ino
 */

/**
 * definizione pin motori
 */
#define DIR_SX 0
#define DIR_DX 0
#define PWM_SX 0
#define PWM_DX 0

/**
 * definizione pin sensori di luce
 */
#define LUCE_SX 0
#define LUCE_DX 0
#define LUCE_CN 0

/**
 * definizione pin sensore di suono
 */
#define SUONO 0

/**
 * definizione pin bumper
 */
#define BUMP_SX 0
#define BUMP_DX 0

/**
 * definizione pin led
 */
#define LED_ROSSO 0
#define LED_VERDE 0
#define LED_BLU 0

/**
 * blocco di costanti per il funzionamento del programma
 */
#define LED_TIME 3000 //tempo in cui il led deve rimanere acceso
#define TURN_TIME 500 //tempo in cui il robot deve girarsi

void setup()
{
	Serial.begin(9600);

	/**
	 * blocco di funzioni di inizializzazione
	 */
	initMotori();
	initLuci();
	initSuono();
	initBumper();
	initLed();

	delay(1000); //il robot parte dopo 1 secondo
}

void loop()
{
	avanti(); //il robot inizia andando avanti

	/**
	 * blocco di letture di tutti i sensori del robot
	 *
	 * lo scopo è quello di non usare delay() perché rallentano il programma 
	 * si usano solo millis()
	 */
	int lettura_luce = handleLuci();
	int lettura_suono = handleSuono();
	int lettura_bumper = handleBumper();

	if(lettura_luce)
	{
		//fermare il robot e accendere il led verde per 3 secondi
		switch(lettura_luce)
		{
			case 1: //quando ha letto la luce di sinistra
			fermo();
			ledVerde();
			delay(LED_TIME); //aspetta 3 secondi

			destra();
			delay(TURN_TIME); //gira di 90°
			avanti();
			break;

			case 2: //quando ha letto la luce di destra
			fermo();
			ledVerde();
			delay(LED_TIME); //aspetta 3 secondi

			sinistra();
			delay(TURN_TIME); //gira di 90°
			avanti();
			break;

			case 3: //quando ha letto la luce centrale
			fermo();
			ledVerde();
			delay(LED_TIME); //aspetta 3 secondi

			destra();
			delay(TURN_TIME); //gira di 90°
			delay(TURN_TIME); //gira di 90°
			avanti();
			break;
		}
	}
	else if(lettura_suono)
	{
		//fermare il robot e accendere il led verde per 3 secondi
	}
	else if(lettura_bumper)
	{
		//fermare il robot, andare poco indietro e girare nel verso opposto al bumper
		switch(lettura_bumper)
		{
			case 1: //quando ha letto il bumper di sinistra
			break;

			case 2: //quando ha letto il bumper di destra
			break;
		}
	}
}
