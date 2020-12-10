/**
 * Luci.ino
 */

uint8_t handleLuci()
{
	//lettura di tutte le fotoresistenze con ritorno della variabile di stato e uscita dalla fonte
	int lettura_luce_sx = analogRead(LUCE_SX);
	int lettura_luce_dx = analogRead(LUCE_DX);
	int lettura_luce_cn = analogRead(LUCE_CN);

	if(lettura_luce_sx >= SOGLIA_LUCE_SX) //se ha letto la luce a sinistra
	{
		return 1; //nel loop, 1 vuol dire sinistra
	}
	else if(lettura_luce_dx >= SOGLIA_LUCE_DX) //se ha letto la luce a destra
	{
		return 2; //nel loop, 2 vuol dire destra
	}
	else if(lettura_luce_cn >= SOGLIA_LUCE_CN) //se ha letto la luce davanti
	{
		return 3; //nel loop, 3 vuol dire centro
	}
	else //se non ha letto luci
	{
		return 0; //nel loop, 0 vuol dire che non ha trovato nulla
	}
}
