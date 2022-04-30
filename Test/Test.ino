/**
 * Test.ino
 * Massimo Giordano
 */
/**
 * blocco di costanti per il funzionamento dei motori
 */
#define LED_TIME 2800 //tempo in cui il led deve rimanere acceso

#define TURN_TIME 500 //tempo in cui il robot deve girarsi
#define SHORT_TIME 250
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
#define TIME_GAS_ON 10000 //10 secondi

unsigned long time_light = 0;
unsigned long time_sound = 0;
unsigned long time_gas = 0;
unsigned long millis_gas_on = 0;

/**
 * per uscire dagli angoli è necessario avviare un conteggio appena uno switch
 * si attiva. il tempo che prendo in considerazione è MAX_TIME_BUMP
 *
 * impostare un corretto valore prendendo in considerazione i delay che ci sono
 */
#define MAX_TIME_BUMP 0 //definito un tempo in cui non ha letto nulla

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
}

void loop()
{
	/**
	 * primo step 
	 * 
	 * testare se i motori girano alla stessa velocità
	 */
	avanti();

	/**
	 * secondo step 
	 *
	 * verificare se girando a destra e a sinistra, con i diversi tempi effettua curve corrette
	 */
	//destra(); delay(SHORT_TIME);
	//destra(); delay(TURN_TIME);

	//sinistra(); delay(SHORT_TIME);
	//sinistra(); delay(TURN_TIME);
	
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
	//uint8_t lettura_gas = handleGas();
	
	/**
	 * sesto step
	 *
	 * controllare il corretto funzionamento dei bumper
	 *
	 * una volta accertato che tutto funziona nel modo giusto verificare anche 
	 * l'uscita dagli angoli e impostare i corretti tempi di attesa
	 */
	//uint8_t lettura_bumper = handleBumper();
	
}