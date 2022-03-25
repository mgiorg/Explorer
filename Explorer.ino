/**
 * Explorer.ino
 * Massimo Giordano
 */
/**
 * definizione pin sensore di gas
 */
#define PIN_GAS 0

/**
 * definizione pin led
 */
#define LED_ROSSO 10
#define LED_VERDE 2
#define LED_GIALLO 5

/**
 * blocco di costanti per le soglie
 */
#define SOGLIA_GAS 0

/**
 * blocco di costanti per il funzionamento dei motori
 */
#define LED_TIME 2500 //tempo in cui il led deve rimanere acceso
#define TURN_TIME 500 //tempo in cui il robot deve girarsi
#define SHORT_TIME 250
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
	//uint8_t lettura_suono = handleSuono();
	//uint8_t lettura_bumper = handleBumper();
	
	if(lettura_luce)
	{
		//fermare il robot e accendere il led verde per 3 secondi
		switch(lettura_luce)
		{
			case 1: //quando ha letto la luce di sinistra
			fermo();
			ledVerde(); delay(LED_TIME); ledSpento();

			destra(); delay(TURN_TIME); //gira di 90°
			avanti();
			break;

			case 2: //quando ha letto la luce di destra
			fermo();
			ledVerde(); delay(LED_TIME); ledSpento();

			destra(); delay(SHORT_TIME); //gira di 90°
			avanti();
			break;

			case 3: //quando ha letto la luce centrale
			fermo();
			ledVerde(); delay(LED_TIME); ledSpento();

			sinistra(); delay(SHORT_TIME); //gira di 90
			avanti();
			break;

			case 4:
			fermo();
			ledVerde(); delay(LED_TIME); ledSpento();

			sinistra(); delay(TURN_TIME);
			avanti();

		}
	}
	/*else if(lettura_suono)
	{
		//fermare il robot e accendere il led giallo per 3 secondi
		fermo();
		ledGiallo(); delay(LED_TIME);

		avanti(); delay(TURN_TIME); 
	}*/
	/*if(lettura_bumper)
	{
		//fermare il robot, andare poco indietro e girare nel verso opposto al bumper
		switch(lettura_bumper)
		{
			case 1: //quando ha letto il bumper di sinistra
			indietro(); delay(BACK_TIME); //torna indietro per BACK_TIMEms
			destra(); delay(TURN_TIME); //gira a destra per TURN_TIMEms
			avanti();
			break;

			case 2: //quando ha letto il bumper di destra
			indietro(); delay(BACK_TIME); //torna indietro per BACK_TIMEms
			sinistra(); delay(TURN_TIME); //gira a sinistra per TURN_TIMEms
			avanti();
			break;
		}
	}*/
}
