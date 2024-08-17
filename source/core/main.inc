/*
	Основа мода New.pwn ( 0.3.7-R5 ).
	Автор: D O R I M E ( https://t.me/mainmenuNBA ).

	Версия 0.0.1:
		Патч v0.0.1:
			- Система регистрации/авторизации.
			- Система IP и даты регистрации.
			- Спавн в гетто.
		Патч v0.0.2:
			- Маппинг для спавна
			- Аренда мопедов
			- RP комманды
*/

#include <a_samp>
#include <a_mysql>
#include <Pawn.CMD>
#include <time_t>
#include <streamer>

#include "../source/core/defines.inc"
#include "../source/core/variables.inc"
#include "../source/core/forwards.inc"
#include "../source/core/publics.inc"
#include "../source/core/stocks.inc"

// Registration || Stages!
#include "../source/player/registration/stocks.inc"
#include "../source/player/registration/publics.inc"
#include "../source/player/registration/registration and autorization.inc"
#include "../source/player/registration/interaction for player.inc"
main(){}