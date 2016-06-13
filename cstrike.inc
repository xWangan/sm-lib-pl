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

#if defined _cstrike_included
  #endinput
#endif
#define _cstrike_included

#define CS_TEAM_NONE		0	/**< Brak drużyny */
#define CS_TEAM_SPECTATOR	1	/**< Obserwator */
#define CS_TEAM_T 			2	/**< Terrorysta */
#define CS_TEAM_CT			3	/**< CT */

#define CS_SLOT_PRIMARY		0	/**< Slot na główną broń */
#define CS_SLOT_SECONDARY	1	/**< Slot na zapasową broń */
#define CS_SLOT_KNIFE		2	/**< Slot na nóż */
#define CS_SLOT_GRENADE		3	/**< Slot na granat (Zwraca tylko 1 granat). */
#define CS_SLOT_C4			4	/**< Slot na c4 */

#define CS_DMG_HEADSHOT		(1 << 30)	/**< Headshot */

enum CSRoundEndReason
{
	CSRoundEnd_TargetBombed = 0,           /**< Udane zniszczenie celu! */
	CSRoundEnd_VIPEscaped,                 /**< VIP został uratowany! - Nie istnieje w CS:GO */
	CSRoundEnd_VIPKilled,                  /**< VIP został zamordowany! - Nie istnieje w CS:GO */
	CSRoundEnd_TerroristsEscaped,          /**< Terroriści uciekli! */
	CSRoundEnd_CTStoppedEscape,            /**< CT powstrzymało terrorystów przed ucieczką! */
	CSRoundEnd_TerroristsStopped,          /**< Wszyscy uciekająct terroryści zostali zneutralizowani! */
	CSRoundEnd_BombDefused,                /**< Bomba została rozbrojona! */
	CSRoundEnd_CTWin,                      /**< CT wygrało! */
	CSRoundEnd_TerroristWin,               /**< Terroryści wygrali! */
	CSRoundEnd_Draw,                       /**< Remis! */
	CSRoundEnd_HostagesRescued,            /**< Wszystkie hosty zostały uratowane! */
	CSRoundEnd_TargetSaved,                /**< Cel został zabezpieczony */
	CSRoundEnd_HostagesNotRescued,         /**< Hosty nie zostały uratowane! */
	CSRoundEnd_TerroristsNotEscaped,       /**< Terroryści nie zdołali uciec */
	CSRoundEnd_VIPNotEscaped,              /**< VIP nie zdołał uciec! - Nie istnieje w CS:GO */
	CSRoundEnd_GameStart,                  /**< Rozgrywka nadchodzi! */


	CSRoundEnd_TerroristsSurrender,        /**< Terroriści poddali się */
	CSRoundEnd_CTSurrender,                /**< CT poddało się */
	CSRoundEnd_TerroristsPlanted,		   /**< Terroryści podłożyli bombę */
	CSRoundEnd_CTsReachedHostage,		   /**< CT zdobyło hosty */
};

enum CSWeaponID
{
	CSWeapon_NONE = 0,
	CSWeapon_P228,
	CSWeapon_GLOCK,
	CSWeapon_SCOUT,
	CSWeapon_HEGRENADE,
	CSWeapon_XM1014,
	CSWeapon_C4,
	CSWeapon_MAC10,
	CSWeapon_AUG,
	CSWeapon_SMOKEGRENADE,
	CSWeapon_ELITE,
	CSWeapon_FIVESEVEN,
	CSWeapon_UMP45,
	CSWeapon_SG550,
	CSWeapon_GALIL,
	CSWeapon_FAMAS,
	CSWeapon_USP,
	CSWeapon_AWP,
	CSWeapon_MP5NAVY,
	CSWeapon_M249,
	CSWeapon_M3,
	CSWeapon_M4A1,
	CSWeapon_TMP,
	CSWeapon_G3SG1,
	CSWeapon_FLASHBANG,
	CSWeapon_DEAGLE,
	CSWeapon_SG552,
	CSWeapon_AK47,
	CSWeapon_KNIFE,
	CSWeapon_P90,
	CSWeapon_SHIELD,
	CSWeapon_KEVLAR,
	CSWeapon_ASSAULTSUIT,
	CSWeapon_NIGHTVISION,
	CSWeapon_GALILAR,
	CSWeapon_BIZON,
	CSWeapon_MAG7,
	CSWeapon_NEGEV,
	CSWeapon_SAWEDOFF,
	CSWeapon_TEC9,
	CSWeapon_TASER,
	CSWeapon_HKP2000,
	CSWeapon_MP7,
	CSWeapon_MP9,
	CSWeapon_NOVA,
	CSWeapon_P250,
	CSWeapon_SCAR17,
	CSWeapon_SCAR20,
	CSWeapon_SG556,
	CSWeapon_SSG08,
	CSWeapon_KNIFE_GG,
	CSWeapon_MOLOTOV,
	CSWeapon_DECOY,
	CSWeapon_INCGRENADE,
	CSWeapon_DEFUSER
};

/**
 * Wywoływane kiedy gracz usiłuje kupić przedmiot.
 * Zwrócenie Plugin_Continue pozwala, każda inna wyższa akcja blokuje.
 *
 * @param client	ID klienta.
 * @param weapon	Wprowadzona przez użytkownika nazwa broni.
 */
forward Action CS_OnBuyCommand(int client, const char[] weapon);

/**
 * Wywoływane kiedy CSWeaponDrop jest wywoływane.
 * Zwrócenie Plugin_Continue pozwala, każda inna wyższa akcja blokuje.
 *
 * @param client	ID klienta.
 * @param weaponIndex	ID broni.
 */
forward Action CS_OnCSWeaponDrop(int client, int weaponIndex);

/**
 * Wywoływane kiedy gra uzyskuje cene broni dla gracza.
 * Zwrócenie Plugin_Continue powoduje użycie standardowych wartości, każda inna wyższa akcja powoduje użycie nowo ustawionej ceny.
 *
 * @note Może być wywoływane wielokrotnie podczas kupowania broni.
 *
 * @param client	ID klienta.
 * @param weapon	Classname broni.
 * @param price		Buffor dla ceny broni.
 *
 * @note			Nie wszystkie "bronie" wywołują GetWeaponPrice, np. c4, knife, vest, vest helmet, night vision.
 */
forward Action CS_OnGetWeaponPrice(int client, const char[] weapon, int &price);

/**
 * Wywoływany kiedy TerminateRound jest wywoływane.
 * Zwrócenie Plugin_Continue spowoduje zignorowanie, zwrócenie Plugin_Changed spowoduje kontynuowanie (wykorzystywany do zmianny opóżnienia i powodu), zwrócenie Plugin_Handled blokuje TerminateRound przed wywołaniem
 *
 * @param delay		Czas (w sekundach) przed rozpoczęciem nowej rundy.
 * @param reason	Powdód zakończenia rundy.
 */
forward Action CS_OnTerminateRound(float &delay, CSRoundEndReason &reason);

/**
 * Ożywia gracza.
 *
 * @param client		ID klienta.
 * @error			Nieprawidłowe ID klienta, klient nie jest w grze.
 */
native void CS_RespawnPlayer(int client);

/**
 * Zmiennia drużynę gracza
 *
 * @param client		ID klienta.
 * @param team			ID drużyny.
 * @error			Nieprawidłowe ID klienta, klient nie jest w grze.
 */
native void CS_SwitchTeam(int client, int team);

/**
 * Zmusza gracza do porzucenia broni
 *
 * @param client		ID klienta.
 * @param weaponIndex	ID broni do wyrzucenia.
 * @param toss			True aby wyrzucić broń (wraz z prędkością), false aby tylko wyrzucić.
 * @param blockhook	  Ustawienie true spowoduje blokowanie wywoływania CS_OnCSWeaponDrop.
 *
 * @error				Nieprawidłowe ID klienta, klient nie jest w grze, nieprawidłowe ID broni.
 */
native void CS_DropWeapon(int client, int weaponIndex, bool toss, bool blockhook = false);

/**
 * Wymusza koniec rundy wraz z powodem.
 *
 * @param delay			Czas (w sekundach) przed rozpoczęciem nowej rundy.
 * @param reason		Powdód zakończenia rundy.
 * @param blockhook		Ustawienie true spowoduje blokowanie wywoływania CS_OnTerminateRound.
 */
native void CS_TerminateRound(float delay, CSRoundEndReason reason, bool blockhook = false);

/**
 * Pobiera nazwe broni z aliansu broni.
 *
 * @param alias			Alians broni.
 * @param weapon		Buffor do przechowania nazwy broni.
 * @param size			Rozmiar bufforu.
 *
 * @note				Ustawi w bufforze alians jeśli nie będzie mógł pobrać nazwy z aliansu.
 */
native void CS_GetTranslatedWeaponAlias(const char[] alias, char[] weapon, int size);

/**
 * Pobiera cenę broni.
 *
 * @param client		ID klienta dla którgego pobieramy cene.
 * @param id			CSWeaponID broni której cene chcemy pobrać
 * @param defaultprice	Ustawienie true spowoduje że zostanie pobrana standardowa cena.
 * @return				Zwraca cenę broni (nawet jeśli była modyfikowana)
 *
 * @error				Nieprawidłowe ID klienta, błąd przy uzyskiwaniu informacji o broni, błąd przy uzyskiwaniu offsetu ceny.
 * @note				c4, knife i shield zawsze będą zwracać 0, vest, vest helmet i night vision zawsze będą zwracać standardową cenę.
 */
native int CS_GetWeaponPrice(int client, CSWeaponID id, bool defaultprice = false);

/**
 * Pobiera clan tag klienta
 * @param client		ID klienta.
 * @param buffer		Buffor do przechowania clan tagu.
 * @param size			Rozmiar buffora.
 * @return				Liczbe zapisanych (nie nullowych) byte'ów.
 *
 * @error				Nieprawidłowe ID klienta.
 */
native int CS_GetClientClanTag(int client, char[] buffer, int size);

/**
 * Ustawia clan tag klientowi
 * @param client		ID klienta.
 * @param tag			Tag do ustawienia.
 *
 * @error				Nieprawidłowe ID klienta.
 */
native void CS_SetClientClanTag(int client, const char[] tag);

/**
 * Pobiera ilość punktów drużyny.
 * @param team			ID drużyny.
 * @return				Zwraca wewnętrzną ilość punktów drużyny.
 *
 * @error				Nieprawidłowe ID drużyny.
 */
native int CS_GetTeamScore(int team);

/**
 * Ustawia ilość punktów drużyny
 * @param team			ID drużyny.
 * @param value			Wartość do ustawienia.
 *
 * @error				Nieprawidłowe ID drużyny.
 * @note				Scoreboard (tabela) zostaje zaktualizowana po wywołaniu funkcji od aktualizacji scoreboard.
 */
native void CS_SetTeamScore(int team, int value);

/**
 * Pobiera ilość MVP klienta.
 * @param client		ID klienta.
 * @return				Zwraca wewnętrzną ilość MVP klienta.
 *
 * @error				Nieprawidłowe ID klienta.
 */
native int CS_GetMVPCount(int client);

/**
 * Ustawia ilość MVP klienta.
 * @param client		ID klienta.
 * @param value			Wartość do ustawienia.
 *
 * @error				Nieprawidłowe ID klienta.
 */
native void CS_SetMVPCount(int client, int value);

/**
 * Pobiera ilość punktów udziału(?) klienta (tylko CS:GO).
 * @param client		ID klienta.
 * @return				Zwraca ilość punktów klienta.
 *
 * @error				Nieprawidłowe ID klienta.
 */
native int CS_GetClientContributionScore(int client);

/**
 * Ustawia ilość punktów udziału(?) klienta (tylko CS:GO).
 * @param client		ID klienta.
 * @param value			Wartość do ustawienia.
 *
 * @error				Nieprawidłowe ID klienta.
 */
native void CS_SetClientContributionScore(int client, int value);

/**
 * Pobiera ilość asyst klienta (tylko CS:GO).
 * @param client		ID klienta.
 * @return				Zwraca ilość asyst klienta.
 *
 * @error				Nieprawidłowe ID klienta.
 */
native int CS_GetClientAssists(int client);

/**
 * Ustawia ilość asyst klienta (tylko CS:GO)
 * @param client		ID klienta.
 * @param value			Wartość do ustawienia.
 *
 * @error				Nieprawidłowe ID klienta.
 */
native void CS_SetClientAssists(int client, int value);

/**
 * Pobiera CSWeaponID z aliansu.
 * @param alias			Alians broni.
 * @return				Zwraca CSWeaponID broni lub CSWeapon_NONE jeśli nie mogło znależć broni pasującej do danego aliansu.
 *
 * @note Dla najlepszego rezultatu użyj CS_GetTranslatedWeaponAlias, zanim przekażesz alians do tej funkcji.
 */
native CSWeaponID CS_AliasToWeaponID(const char[] alias);

/**
 * Pobiera alians z CSWeaponID broni.
 * @param weaponID		CSWeaponID broni.
 * @param destination	Buffor do przechowania aliansu broni.
 * @param len			Rozmiar bufforu.
 * @return				Zwraca ilość zapisanych komórek.
 */
native int CS_WeaponIDToAlias(CSWeaponID weaponID, char[] destination, int len);

/**
 * Zwraca czy CSWeaponID jest prawidłowy dla aktualnie uruchomionej modyfikacji (CSS lub CS:GO).
 * @param weaponID		CSWeaponID broni.
 * @return				Zwraca true jeśli jest prawidłowy, w przeciwnym wypadku false.
 *
 * @note Zawsze zwraca false dla CSWeapon_NONE
 */
native bool CS_IsValidWeaponID(CSWeaponID id);

/**
 * Ustawia model gracza na podstawie aktualnej klasy gracza.
 *
 * @param client		ID klienta.
 * @error			Nieprawidłowe ID klienta, klient nie jest w grze.
 */
native void CS_UpdateClientModel(int client);

/**
 * Do not edit below this line!
 */
public Extension __ext_cstrike =
{
	name = "cstrike",
	file = "games/game.cstrike.ext",
	autoload = 0,
#if defined REQUIRE_EXTENSIONS
	required = 1,
#else
	required = 0,
#endif
};

#if !defined REQUIRE_EXTENSIONS
public void __ext_cstrike_SetNTVOptional()
{
	MarkNativeAsOptional("CS_RespawnPlayer");
	MarkNativeAsOptional("CS_SwitchTeam");
	MarkNativeAsOptional("CS_DropWeapon");
	MarkNativeAsOptional("CS_TerminateRound");
	MarkNativeAsOptional("CS_GetTranslatedWeaponAlias");
	MarkNativeAsOptional("CS_GetWeaponPrice");
	MarkNativeAsOptional("CS_GetClientClanTag");
	MarkNativeAsOptional("CS_SetClientClanTag");
	MarkNativeAsOptional("CS_GetTeamScore");
	MarkNativeAsOptional("CS_SetTeamScore");
	MarkNativeAsOptional("CS_GetMVPCount");
	MarkNativeAsOptional("CS_SetMVPCount");
	MarkNativeAsOptional("CS_GetClientContributionScore");
	MarkNativeAsOptional("CS_SetClientContributionScore");
	MarkNativeAsOptional("CS_GetClientAssists");
	MarkNativeAsOptional("CS_SetClientAssists");
	MarkNativeAsOptional("CS_AliasToWeaponID");
	MarkNativeAsOptional("CS_WeaponIDToAlias");
	MarkNativeAsOptional("CS_IsValidWeaponID");
	MarkNativeAsOptional("CS_UpdateClientModel");
}
#endif
