/**
 * Test.ino
 * Massimo Giordano
 */
/**
 * blocco di costanti per il funzionamento dei motori
 */
#define LED_TIME 2800 //tempo in cui il led deve rimanere acceso

#define TURN_TIME 480 //tempo in cui il robot deve girarsi
#define SHORT_TIME 225
#define BACK_TIME 300 //tempo in cui il robot deve tornare indietro
#define STOP_TIME 200 //tempo in cui il robot sta fermo prima di girarsi

/**
 * dichiarazione costanti per spegnere i sensori di luce, suono e gas. 
 * valutare se far leggere il gas al robot
 *
 * dichiarazione di un'ulteriore variabile per far accendere il sensore dopo 
 * 10 secondi, tempo necessario a farlo scaldare
 */
#define DELAY_LIGHT 0 
#define DELAY_SOUND 0
uint8_t sound_counter = 0;

#define DELAY_GAS 0

unsigned long time_light = 0;
unsigned long time_sound = 0;
unsigned long time_gas = 0;
int prev_read_gas = 0;
uint16_t tot_read_gas = 0;
int grow_gas_millis = 0;

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

/**
 * programma per testare sensori e movimento 
 * usare questo per modificare velocità, stampare valori e regolare soglie
 */

void setup()
{
	Serial.begin(9600);

	/**
	 * blocco di funzioni di inizializzazione
	 */
	initMotori();
	initBumper();
	initLed();

	pinMode(A5, INPUT);
}

void loop()
{
	/**
	 * primo step 
	 * 
	 * testare se i motori girano alla stessa velocità
	 */
	//avanti();

	/**
	 * secondo step 
	 *
	 * verificare se girando a destra e a sinistra, con i diversi tempi effettua curve corrette
	 */
	//destra(); delay(SHORT_TIME);
	//avanti(); delay(1000); fermo(); delay(750);
	//destra(); delay(TURN_TIME);
	//avanti(); delay(1000); fermo(); delay(750);

	//sinistra(); delay(SHORT_TIME);
	//avanti(); delay(1000); fermo(); delay(750);
	//sinistra(); delay(TURN_TIME);
	//avanti(); delay(1000); fermo(); delay(750);
	
	/**
	 * terzo step
	 *
	 * controllare se le luci vengono lette in maniera corretta.
	 * nel pannello luci ci sono le stampe di tutte le letture corrette
	 */
	//uint8_t lettura_luci = handleLuci();
	
	/**
	 * quarto step
	 *
	 * controllare se il suono viene letto in maniera corretta
	 * anche qui nel pannello del suono abbiamo la stampa della lettura analogica
	 */
	//uint8_t lettura_suono = handleSuono();
	
	/**
	 * quinto step
	 *
	 * testare il corretto funzionamento del sensore di gas.
	 * verificare dopo quanto si attiva, se ha bisogno di scaldarsi e se legge correttamente i valori,
	 * altrimenti non verrà implementato
	 */
	uint8_t lettura_gas = handleGas();

	//Serial.print(" - Valore binario = ");
	//Serial.println(lettura_gas);

	/**
	 * RICORDARSI DI SCRIVERE UN PROGRAMMA CHE CONTROLLA LA VELOCITà DI SATURAZIONE DEL SENSORE
	 * DI GAS TRAMITE LA SOMMA DI TUTTI I VALORI LETTI IN UN CERTO INTERVALLO DI TEMPO STABILITO DA ME
	 * MISURANDO QUANTO TEMPO CI METTEVA IL SENSORE A PASSARE DA X ALLA SOGLIA
	 *
	 * VEDENDO LA SOMMA AUMENTARE AUMENTA ANCHE LA PENDENZA DELLA RETTA
	 */
	
	// int prev_read_gas = 0;
	// uint16_t tot_read_gas = 0;
	// int grow_gas_millis = 0;
	
	/**
	 * sesto step
	 *
	 * controllare il corretto funzionamento dei bumper
	 *
	 * una volta accertato che tutto funziona nel modo giusto verificare anche 
	 * l'uscita dagli angoli e impostare i corretti tempi di attesa
	 */
	// uint8_t lettura_bumper = handleBumper();
	
	// if(lettura_bumper)
	// {
	// 	if(time_bump == 0) //se ha letto per la prima volta
	// 	{
	// 		time_bump = millis(); //inizia il conteggio
	// 	}
	// 	bump_counter++; //incremento il contatore

	// 	if(bump_counter == MAX_COUNTER)
	// 	{
	// 		indietro(); delay(BACK_TIME);
	// 		destra(); delay(TURN_TIME); delay(TURN_TIME); //si gira di 180°
	// 		avanti();

	// 		lettura_bumper = 0;
	// 	}

	// 	//fermare il robot, andare poco indietro e girare nel verso opposto al bumper
	// 	switch(lettura_bumper)
	// 	{
	// 		case 1: //quando ha letto il bumper di sinistra
	// 		indietro(); delay(BACK_TIME); //torna indietro per BACK_TIMEms
	// 		destra(); delay(TURN_TIME); //gira a destra per TURN_TIMEms
	// 		avanti();
	// 		break;

	// 		case 2: //quando ha letto il bumper di destra
	// 		indietro(); delay(BACK_TIME); //torna indietro per BACK_TIMEms
	// 		sinistra(); delay(TURN_TIME); //gira a sinistra per TURN_TIMEms
	// 		avanti();
	// 		break;
	// 	}
	// }

	// if((millis() - time_bump) >= MAX_TIME_BUMP) //se è passato parecchio tempo
	// {
	// 	//azzero tutti i valori di conteggio dei bumper
	// 	bump_counter = 0;
	// 	time_bump = 0;
	// }
	// 
	// ledRosso();
	// ledVerde();
	// ledGiallo();
}
