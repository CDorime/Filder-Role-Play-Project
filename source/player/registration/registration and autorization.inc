public OnPlayerConnect(playerid)
{
    static const
        PLAYER_TEAM = 0,
        PLAYER_SKIN = 0,
        
        Float:PLAYER_START_X = 0.0,
        Float:PLAYER_START_Y = 0.0,
        Float:PLAYER_START_Z = 0.0,
        Float:PLAYER_START_ANGLE = 0.0,

        PLAYER_WEAPONS = 0,
        PLAYER_WEAPON_AMMO = 0,
        
        TYPE_GAMETEXT_STYLE = 1,

        TIMER_INTERVAL = 2000;

    SetSpawnInfo(
        playerid,
        PLAYER_TEAM,
        PLAYER_SKIN,
        PLAYER_START_X,
        PLAYER_START_Y,
        PLAYER_START_Z,
        PLAYER_START_ANGLE, 
        PLAYER_WEAPONS, 
        PLAYER_WEAPON_AMMO, 
        PLAYER_WEAPONS, 
        PLAYER_WEAPON_AMMO,
        PLAYER_WEAPONS, 
        PLAYER_WEAPON_AMMO
    );
    GameTextForPlayer(
        playerid, 
        "~w~Welcome to~n~~pFilder RolePlay",
        TIMER_INTERVAL,
        TYPE_GAMETEXT_STYLE
    );
    SetTimerEx(
        "OnPlayerConnectToServer", 
        TIMER_INTERVAL, 
        false, 
        "i", 
        playerid
    );
    
    #if defined REG_OnPlayerConnect
        return REG_OnPlayerConnect(playerid);
    #else
        return true;
    #endif
}

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect REG_OnPlayerConnect
#if defined REG_OnPlayerConnect
    forward REG_OnPlayerConnect(playerid);
#endif

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case DIALOGUE_REG_STAGE_ONE:
        {
            if(!response) 
            { 
                SendClientMessage(
                    playerid, 
                    0xFF0000FF, 
                    "Вы были отключены от сервера. Причина: отказ от регистрации.");
                SetTimerEx("SetPlayerParamsKick", 2000, false, "i", playerid);
                return true; 
            }
	        if(strlen(inputtext) < MIN_PLAYER_PASSWORD || strlen(inputtext) > MAX_PLAYER_PASSWORD)
                return SendClientMessage(
                    playerid, 
                    0xC9C9C9FF, 
                    "Пароль должен содержать от 6 до 24 символов!");
            SendRegistrationStageOne(playerid); 
	        for(new i = strlen(inputtext)-1; i != -1; i--)
	        {
	            switch(inputtext[i])
	            {
	                case '0'..'9', 'a'..'z', 'A'..'Z': continue;
	                default: 
                    {
                        SendClientMessage(
                            playerid, 
                            0xC9C9C9FF, 
                            "Пароль должен содержать только английские символы!"
                            );
                        SendRegistrationStageOne(playerid);
                        return true; 
                    }
	            }
	        }
	        strmid(
                PlayerInfo[playerid][pPassword], 
                inputtext, 
                0, 
                strlen(inputtext), 
                MAX_PLAYER_PASSWORD
            );
        }
        case DIALOGUE_REG_STAGE_TWO:
	    {
	        if(!response) 
            { 
                SendClientMessage(
                    playerid, 
                    0xFF0000FF, 
                    "Вы были отключены от сервера. Причина: отказ от регистрации."
                ); 
                SetTimerEx("SetPlayerParamsKick", 2000, false, "i", playerid);
                return true; 
            }
	        if(!strlen(inputtext) || 
                strlen(inputtext) < MIN_PLAYER_EMAIL || 
                strlen(inputtext) > MAX_PLAYER_EMAIL) 
                return SendClientMessage(
                    playerid, 
                    0xC9C9C9FF, 
                    "Адрес электронной почты должен содержать от 6 до 35 символов!");
            SendRegistrationStageTwo(playerid);
	        for(new i = strlen(inputtext)-1; i != -1; i--)
	        {
	            switch(inputtext[i])
	            {
	                case '0'..'9', 'a'..'z', 'A'..'Z', '@', '.': continue;
	                default: 
                    { 
                        SendClientMessage(
                            playerid, 
                            0xC9C9C9FF, 
                            "Адрес электронной почты должен содержать только английские символы!"
                        );
                        return true; 
                    }
	            }
	        }
	        if(strfind(inputtext, "@", false))
	        {
				if(strfind(inputtext, ".", false))
				{
					strmid(
                        PlayerInfo[playerid][pEmail], 
                        inputtext, 
                        0, 
                        strlen(inputtext), 
                        MAX_PLAYER_EMAIL
                    );
					SendRegistrationStageThree(playerid);
				}
			}
	        else 
            {
                SendClientMessage(
                    playerid, 
                    0xC9C9C9FF, 
                    "Адрес электронной почты не соответствует требованиям!"
                ); 
                SendRegistrationStageTwo(playerid);
                return true;
            }
	    }
		case DIALOGUE_REG_STAGE_THREE:
		{
		    if(response)
			{
                const
                    POINT_MALE = 1;
				new 
                    start_skin_man[6] = {78, 79, 134, 137, 230};
                
                PlayerInfo[playerid][pPoint] = POINT_MALE;
				PlayerInfo[playerid][pSkin] = start_skin_man[random(sizeof(start_skin_man))];

				InsertPlayerAccount(playerid);
			}
		    else
			{
                const
                    POINT_FEMALE = 2;
				new
                    start_skin_woman[3] = {56, 64, 131};
                PlayerInfo[playerid][pPoint] = POINT_FEMALE;
				PlayerInfo[playerid][pSkin] = start_skin_woman[random(sizeof(start_skin_woman))];

				InsertPlayerAccount(playerid);
			}
		}
    }

    #if defined REG_OnDialogResponse
        return REG_OnDialogResponse(
            playerid, 
            dialogid, 
            response, 
            listitem, 
            inputtext[]
        );
    #else
        return true;
    #endif
}
#if defined _ALS_OnDialogResponse
    #undef OnDialogResponse
#else
    #define _ALS_OnDialogResponse
#endif

#define OnDialogResponse REG_OnDialogResponse
#if defined REG_OnDialogResponse
    forward REG_OnDialogResponse(
        playerid, 
        dialogid, 
        response, 
        listitem, 
        inputtext[]
    );
#endif