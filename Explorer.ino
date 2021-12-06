/**
 * Explorer.ino
 * Massimo Giordano
 */

/**
 * definizione pin motori
 */
#define DIR_A1 4
#define DIR_B1 3
#define DIR_A2 7
#define DIR_B2 8
#define PWM_1 9
#define PWM_2 6

/**
 * definizione pin sensori di luce
 */
#define LUCE_1 A0
#define LUCE_2 A1
#define LUCE_3 A2
#define LUCE_4 A3

/**
 * definizione pin sensore di suono
 */
#define PIN_SUONO 0

/**
 * definizione pin sensore di gas
 */
#define PIN_GAS 0

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
 * blocco di costanti per le soglie
 */
#define SOGLIA_LUCE_SX 0
#define SOGLIA_LUCE_DX 0
#define SOGLIA_LUCE_CN 0

#define SOGLIA_SUONO 0
#define SOGLIA_GAS 0

/**
 * blocco di costanti per il funzionamento dei motori
 */
#define LED_TIME 2500 //tempo in cui il led deve rimanere acceso
#define TURN_TIME 500 //tempo in cui il robot deve girarsi
#define BACK_TIME 300 //tempo in cui il robot deve tornare indietro
#define STOP_TIME 200 //tempo in cui il robot sta fermo prima di girarsi

void setup()
{
	Serial.begin(9600);

	/**
	 * blocco di funzioni di inizializzazione
	 */
	initMotori();
	initBumper();
	initLed();

	delay(1000); //il robot parte dopo 1 secondo
}

void loop()
{
	avanti(); //il robot inizia andando avanti

	/**
	 * blocco di letture di tutti i sensori del robot
	 */
	uint8_t lettura_luce = handleLuci();
	uint8_t lettura_suono = handleSuono();
	uint8_t lettura_bumper = handleBumper();

	if(lettura_luce)
	{
		//fermare il robot e accendere il led verde per 3 secondi
		switch(lettura_luce)
		{
			case 1: //quando ha letto la luce di sinistra
			fermo();
			ledVerde(); delay(LED_TIME); //aspetta 3 secondi

			destra(); delay(TURN_TIME); //gira di 90°
			avanti();
			break;

			case 2: //quando ha letto la luce di destra
			fermo();
			ledVerde(); delay(LED_TIME); //aspetta 3 secondi

			sinistra(); delay(TURN_TIME); //gira di 90°
			avanti();
			break;

			case 3: //quando ha letto la luce centrale
			fermo();
			ledVerde(); delay(LED_TIME); //aspetta 3 secondi

			destra(); delay(TURN_TIME); /* gira di 90° */ delay(TURN_TIME); /* gira di 90° */
			avanti();
			break;
		}
	}
	else if(lettura_suono)
	{
		//fermare il robot e accendere il led giallo per 3 secondi
		fermo();
		ledGiallo(); delay(LED_TIME);

		avanti(); delay(TURN_TIME); 
	}
	else if(lettura_bumper)
	{
		//fermare il robot, andare poco indietro e girare nel verso opposto al bumper
		switch(lettura_bumper)
		{
			case 1: //quando ha letto il bumper di sinistra
			fermo(); delay(STOP_TIME); //sta fermo per STOP_TIMEms
			indietro(); delay(BACK_TIME); //torna indietro per BACK_TIMEms
			destra(); delay(TURN_TIME); //gira a destra per TURN_TIMEms
			avanti();
			break;

			case 2: //quando ha letto il bumper di destra
			fermo(); delay(STOP_TIME); //sta fermo per STOP_TIMEms
			indietro(); delay(BACK_TIME); //torna indietro per BACK_TIMEms
			sinistra(); delay(TURN_TIME); //gira a sinistra per TURN_TIMEms
			avanti();
			break;
		}
	}
}
