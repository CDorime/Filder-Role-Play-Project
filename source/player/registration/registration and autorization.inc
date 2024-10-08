public OnPlayerConnect(playerid)
{
    static const
        INVALID_PLAYER_TEAM = 0,
        STARTED_PLAYER_SKIN = 0,
        
        Float:STARTED_PLAYER_X = 0.0,
        Float:STARTED_PLAYER_Y = 0.0,
        Float:STARTED_PLAYER_Z = 0.0,
        Float:STARTED_PLAYER_ANGLE = 0.0,

        STARTED_PLAYER_WEAPONS = 0,
        STARTED_PLAYER_WEAPON_AMMO = 0,
        
        TYPE_GAMETEXT_STYLE = 1,

        TIMER_INTERVAL = 2000;

    SetSpawnInfo(
        playerid,
        INVALID_PLAYER_TEAM,
        STARTED_PLAYER_SKIN,
        STARTED_PLAYER_X,
        STARTED_PLAYER_Y,
        STARTED_PLAYER_Z,
        STARTED_PLAYER_ANGLE, 
        STARTED_PLAYER_WEAPONS, 
        STARTED_PLAYER_WEAPON_AMMO, 
        STARTED_PLAYER_WEAPONS, 
        STARTED_PLAYER_WEAPON_AMMO,
        STARTED_PLAYER_WEAPONS, 
        STARTED_PLAYER_WEAPON_AMMO
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
                    "�� ���� ��������� �� �������. �������: ����� �� �����������.");
                SetTimerEx("SetPlayerParamsKick", 2000, false, "i", playerid);
                return true; 
            }
	        if(strlen(inputtext) < MIN_PLAYER_PASSWORD || strlen(inputtext) > MAX_PLAYER_PASSWORD)
                return SendClientMessage(
                    playerid, 
                    0xC9C9C9FF, 
                    "������ ������ ��������� �� 6 �� 24 ��������!");
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
                            "������ ������ ��������� ������ ���������� �������!"
                            );
                        SendRegistrationStageOne(playerid);
                        return true; 
                    }
	            }
	        }
	        strmid(
                g_PlayerInfo[playerid][pPassword], 
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
                    "�� ���� ��������� �� �������. �������: ����� �� �����������."
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
                    "����� ����������� ����� ������ ��������� �� 6 �� 35 ��������!");
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
                            "����� ����������� ����� ������ ��������� ������ ���������� �������!"
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
                        g_PlayerInfo[playerid][pEmail], 
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
                    "����� ����������� ����� �� ������������� �����������!"
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
                
                g_PlayerInfo[playerid][pPoint] = POINT_MALE;
				g_PlayerInfo[playerid][pSkin] = start_skin_man[random(sizeof(start_skin_man))];

				InsertPlayerAccount(playerid);
			}
		    else
			{
                const
                    POINT_FEMALE = 2;
				new
                    start_skin_woman[3] = {56, 64, 131};
                g_PlayerInfo[playerid][pPoint] = POINT_FEMALE;
				g_PlayerInfo[playerid][pSkin] = start_skin_woman[random(sizeof(start_skin_woman))];

				InsertPlayerAccount(playerid);
			}
		}
        case DIALOGUE_AUTORIZE:
        {
            if(
                strlen(inputtext) > MAX_PLAYER_PASSWORD ||
                strlen(inputtext) < MIN_PLAYER_PASSWORD
            )
            {
                SendPlayerAutorization(playerid);
                return SendClientMessage(
                playerid, 
                0xC9C9C9FF, 
                "������ ������ ��������� �� 6 �� 24 ��������!");
            }
            if(strcmp(inputtext, g_PlayerInfo[playerid][pPassword], false))
            {
                SpawnPlayer(playerid);
            }
            SendPlayerAutorization(playerid);
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