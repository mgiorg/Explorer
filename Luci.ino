/**
 * Luci.ino
 * Massimo Giordano
 */

uint8_t handleLuci()
{
	//lettura di tutte le fotoresistenze con ritorno della variabile di stato e uscita dalla fonte
	int lettura_luce_1 = analogRead(LUCE_1);
	int lettura_luce_2 = analogRead(LUCE_2);
	int lettura_luce_3 = analogRead(LUCE_3);
	int lettura_luce_4 = analogRead(LUCE_4);

	if(lettura_luce_1 >= SOGLIA_LUCE_1) //se ha letto la luce a sinistra
	{
		return 1; //nel loop, 1 vuol dire sinistra
	}
	else if(lettura_luce_2 >= SOGLIA_LUCE_2) //se ha letto la luce a destra
	{
		return 2; //nel loop, 2 vuol dire destra
	}
	else if(lettura_luce_3 >= SOGLIA_LUCE_3) //se ha letto la luce davanti
	{
		return 3; //nel loop, 3 vuol dire centro
	}
	else if(lettura_luce_4 >= SOGLIA_LUCE_4) //se ha letto la luce davanti
	{
		return 4; //nel loop, 3 vuol dire centro
	}
	else //se non ha letto luci
	{
		return 0; //nel loop, 0 vuol dire che non ha trovato nulla
	}

	/**
	 * inizializzazione variabili di lettura
	 */
	lettura_luce_1 = 0;
	lettura_luce_2 = 0;
	lettura_luce_3 = 0;
	lettura_luce_4 = 0;
}
