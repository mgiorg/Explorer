/**
 * Led.ino
 */
/**
 * definizione pin led
 */
#define LED_ROSSO 10 //GAS
#define LED_VERDE 2 //LUCE
#define LED_GIALLO 5 //SUONO

void initLed()
{
	//inizializzazione pin 
	pinMode(LED_ROSSO, OUTPUT);
	pinMode(LED_VERDE, OUTPUT);
	pinMode(LED_GIALLO, OUTPUT);

	digitalWrite(LED_ROSSO, LOW);
	digitalWrite(LED_VERDE, LOW);
	digitalWrite(LED_GIALLO, LOW);
}

void ledRosso()
{
	//accensione colore rosso del led
	digitalWrite(LED_ROSSO, HIGH);
	digitalWrite(LED_VERDE, LOW);
	digitalWrite(LED_GIALLO, LOW);
}

void ledVerde()
{
	//accensione colore verde del led
	digitalWrite(LED_ROSSO, LOW);
	digitalWrite(LED_VERDE, HIGH);
	digitalWrite(LED_GIALLO, LOW);
}

void ledGiallo()
{
	//accensione colore giallo del led
	digitalWrite(LED_ROSSO, HIGH);
	digitalWrite(LED_VERDE, HIGH);
	digitalWrite(LED_GIALLO, LOW);
}

void ledSpento()
{
	//spegni tutti i pin del led
	digitalWrite(LED_ROSSO, LOW);
	digitalWrite(LED_VERDE, LOW);
	digitalWrite(LED_GIALLO, LOW);
}
