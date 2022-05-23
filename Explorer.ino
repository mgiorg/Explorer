/**
 * Explorer.ino
 * Massimo Giordano
 */

/**
 * blocco di costanti per il funzionamento dei motori
 */
#define LED_TIME 3000 //tempo in cui il led deve rimanere acceso

#define TURN_TIME 280 //tempo in cui il robot deve girarsi
#define SHORT_TIME 180
#define BACK_TIME 250 //tempo in cui il robot deve tornare indietro
#define STOP_TIME 150 //tempo in cui il robot sta fermo prima di girarsi

/**
 * dichiarazione costanti per spegnere i sensori di luce, suono e gas. 
 * valutare se far leggere il gas al robot
 *
 * dichiarazione di un'ulteriore variabile per far accendere il sensore dopo 
 * 10 secondi, tempo necessario a farlo scaldare
 */
#define DELAY_LIGHT 2000
#define DELAY_SOUND 2000
uint8_t sound_counter = 0;
uint8_t sound_counter2 = 0;

#define DELAY_GAS 10000

unsigned long time_light = 0;
unsigned long time_sound = 0;
unsigned long time_gas = 0;

/**
 * per uscire dagli angoli è necessario avviare un conteggio appena uno switch
 * si attiva. il tempo che prendo in considerazione è MAX_TIME_BUMP
 *
 * impostare un corretto valore prendendo in considerazione i delay che ci sono
 */
#define MAX_TIME_BUMP 5000 //definito un tempo in cui non ha letto nulla

unsigned long time_bump = 0;

uint8_t bump_counter = 0; //conta quante volte i bumper si sono attivati in un tempo specifico
#define MAX_COUNTER 4 //numero massimo di impatti nel tempo MAX_TIME_BUMP

unsigned long light_on_sound = 0;
#define LIGHT_ON_SOUND_DELAY 17000

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

	time_light = millis();
	time_sound = millis();
	time_gas = millis();

	light_on_sound = millis();
}

void loop()
{
	ledSpento();
	avanti(); //il robot inizia andando avanti

	/**
	 * iniziamo con la lettura dei sensori di luce
	 */
	uint8_t lettura_luce = handleLuci();
	
	if(lettura_luce)
	{
		if((millis() - time_light) >= DELAY_LIGHT)
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

				case 2: //quando ha letto la luce in alto a sinistra
				fermo();
				ledVerde(); delay(LED_TIME); ledSpento();

				destra(); delay(SHORT_TIME); //gira di 45°
				avanti();
				break;

				case 3: //quando ha letto la luce in alto a destra
				fermo();
				ledVerde(); delay(LED_TIME); ledSpento();

				sinistra(); delay(SHORT_TIME); //gira di 45°
				avanti();
				break;

				case 4: //quando ha letto la luce di destra
				fermo();
				ledVerde(); delay(LED_TIME); ledSpento();

				sinistra(); delay(TURN_TIME); //gira di 90°
				avanti();
			}
			time_light = millis(); //resetto la variabile di conteggio
		}
	}

	/**
	 * una volta terminato il blocco di controlli sulle luci
	 * leggiamo il sensore di suono
	 */
	uint8_t lettura_suono = handleSuono(); 

	if(lettura_suono)
	{
		/**
		 * algoritmo per spegnere il sensore di suono per il tempo necessario ad
		 * allontanarsi dalla sorgente
		 */
		if((millis() - time_sound) >= DELAY_SOUND)
		{
			sound_counter++;
			int resto = sound_counter % 2; //trova il resto dividendo il contatore per due
			//fermare il robot e accendere il led giallo per 3 secondi
			fermo();
			ledGiallo(); delay(LED_TIME); ledSpento();

			/**
			 * controlli per far variare la direzione del robot all'interno 
			 * del campo e per evitare che si incastri facendo sempre
			 * lo stesso giro
			 */
			if(resto == 1) //se il numero è dispari gira a destra
			{
				destra(); delay(TURN_TIME);
			}
			else //altrimenti gira a sinistra
			{
				sinistra(); delay(TURN_TIME);
			}
			avanti();

			time_sound = millis();
		}
	}

	if((millis() - light_on_sound) >= LIGHT_ON_SOUND_DELAY)
	{
			//fermare il robot e accendere il led giallo per 3 secondi
			fermo();
			ledGiallo(); delay(LED_TIME); ledSpento();

			avanti();

			light_on_sound = millis();
	}

	/**
	 * attivo il gas dopo 10 secondi
	 */
	
	/**
	 * controllo se il robot ha trovato il gas
	 */
	uint8_t lettura_gas = handleGas();

	if(lettura_gas)
	{
		/**
		 * algoritmo per spegnere il sensore per il tempo necessario ad
		 * allontanarsi dalla bocchetta del gas
		 */
		if((millis() - time_gas) >= DELAY_GAS)
		{
			//fermare il robot e accendere il led giallo per 3 secondi
			fermo();
			indietro(); delay(500); fermo();
			ledRosso(); delay(LED_TIME); ledSpento();

			avanti();

			time_gas = millis();
		}
	}
		
	/**
	 * ultimo controllo da fare è se il robot ha urtato con i bumper
	 */
	uint8_t lettura_bumper = handleBumper();
	
	if(lettura_bumper)
	{
		if(time_bump == 0) //se ha letto per la prima volta
		{
			time_bump = millis(); //inizia il conteggio
		}
		bump_counter++; //incremento il contatore

		if(bump_counter == MAX_COUNTER)
		{
			indietro(); delay(BACK_TIME);
			destra(); delay(TURN_TIME); delay(TURN_TIME); //si gira di 180°
			avanti();

	 		lettura_bumper = 0;
		}

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
	}

	if((millis() - time_bump) >= MAX_TIME_BUMP) //se è passato parecchio tempo
	{
		//azzero tutti i valori di conteggio dei bumper
		bump_counter = 0;
		time_bump = 0;
	}
}
