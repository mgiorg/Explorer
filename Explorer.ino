/**
 * Explorer.ino
 */

/**
 * definizione pin motori
 */
#define DIR_A 0
#define DIR_B 0
#define PWM_A 0
#define PWM_B 0

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

	}
	else if(lettura_suono)
	{

	}
	else if(lettura_bumper)
	{

	}
}
