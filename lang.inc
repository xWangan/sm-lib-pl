/**
 * vim: set ts=4 :
 * =============================================================================
 * SourceMod (C)2004-2008 AlliedModders LLC.  All rights reserved.
 * =============================================================================
 *
 * This file is part of the SourceMod/SourcePawn SDK.
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, AlliedModders LLC gives you permission to link the
 * code of this program (as well as its derivative works) to "Half-Life 2," the
 * "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
 * by the Valve Corporation.  You must obey the GNU General Public License in
 * all respects for all other code used.  Additionally, AlliedModders LLC grants
 * this exception to all derivative works.  AlliedModders LLC defines further
 * exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
 * or <http://www.sourcemod.net/license.php>.
 *
 * Version: $Id$
 */

#if defined _lang_included
 #endinput
#endif
#define _lang_included

#define LANG_SERVER		0		/**< Wykorzystuj translacje zgodnie z językiem serwera */

/**
 * Ładuje translacje dla pluginu wykorzystującego ten natyw.
 * Jeśli nie podano rozszerzenia, domyślnie zakłada się rozszerzenie .txt
 *
 * @param file		         Plik z translacjami.
 */
native void LoadTranslations(const char[] file);

/**
 * Sets the global language target.  This is useful for creating functions
 * that will be compatible with the %t format specifier.  Note that invalid
 * indexes can be specified but the error will occur during translation,
 * not during this function call.
 *
 * @param client				     ID klienta lub LANG_SERVER.
 */
native void SetGlobalTransTarget(int client);

/**
 * Zwraca numer języka wykorzystywanego przez klienta.
 *
 * @param client				      ID klienta.
 * @return				          		Numer języka wykorzystywanego przez klienta.
 * @error						           Nieprawidłowe ID klienta, klient nie jest w grze.
 */
native int GetClientLanguage(int client);

/**
 * Zwraca język wykorzystywany przez serwer.
 *
 * @return					            Numer języka wykorzystywanego przez serwer.
 */
native int GetServerLanguage();

/**
 * Zwraca liczbę znanych języków w languages.cfg.
 *
 * @return						           Liczba języków.
 */
native int GetLanguageCount();

/**
 * Pobiera informacje o numerze języka.
 *
 * @param language			      Numer języka.
 * @param code				         Bufor kodu języka (zazwyczaj 2-3 znaki).
 * @param codeLen			       Maksymalna długość buforu kodu języka.
 * @param name				         Bufor nazwy języka.
 * @param nameLen			       Maksymalna długość buforu nazwy języka.
 * @error					             Nieprawidłowy numer języka.
 */
native void GetLanguageInfo(int language, char[] code="", int codeLen=0, char[] name="", int nameLen=0);

/**
 * Ustawia numer języka klientowi.
 *
 * @param client   	    		 ID klienta.
 * @param language	     		 Numer języka.
 * @error		               	Nieprawidłowe ID klienta, klient nie jest w grze.
 */
native void SetClientLanguage(int client, int language);

/**
 * Pobiera numer języka z kodu języka.
 *
 * @param code		      	    Kod języka (zazwyczaj 2-3 znaki).
 * @return			 		           Numer języka. -1 jeśli nie znaleziono.
 */
native int GetLanguageByCode(const char[] code);

/**
 * Pobiera numer języka z nazwy języka.
 *
 * @param name	 		       	Nazwa języka (rozróżnia wielkości liter).
 * @return		    	   	    	Numer języka. -1 jeśli nie znaleziono.
 */
native int GetLanguageByName(const char[] name);
