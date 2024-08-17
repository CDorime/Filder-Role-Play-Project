stock InsertPlayerAccount(playerid)
{
    static const
        fmt_query[] = "INSERT INTO Accounts (pNickName, pPassword, pEmail, pPoint, pSkin, pCapital, pScore, pExpirience, pRegistration_Date, pRegistration_IP) VALUES \
        (%s, %s, %s, %i, %i, %i, %i, %i, %s, %i)";
    new 
        date[MAX_LENGTH_DATE],
        year,
        month,
        day,
        hour,
        minute,
        
        ip[MAX_LENGTH_IP],
        query[sizeof fmt_query + ( ( -2 ) + MAX_PLAYER_NAME ) + ( ( -2 ) + ( MAX_PLAYER_PASSWORD ) ) + ( ( -2 ) + ( MAX_PLAYER_EMAIL ) ) + ( ( -2 ) + 1 ) + ( ( -2 ) + 3 ) + ( ( -2 ) + 8 ) + ( ( -2 ) + 8 ) + ( ( -2 ) + 8 ) + ( ( -2 ) + MAX_LENGTH_DATE ) + ( ( -2 ) + MAX_LENGTH_IP ) + 1];

    g_PlayerInfo[playerid][pCapital] = SET_START_CAPITAL;
    g_PlayerInfo[playerid][pScore] = SET_START_SCORE;

    GetPlayerIp(
        playerid, 
        ip, 
        MAX_LENGTH_IP
    );
    
    format(
        date, 
        sizeof date, 
        "%02i.%02i.%04i %02i:%02i",
        day, month, year, hour, minute
    );
    mysql_format(
        g_dbHandle,
        query, 
        sizeof query, 
        fmt_query, 
        g_PlayerInfo[playerid][pNickName],
        g_PlayerInfo[playerid][pPassword],
        g_PlayerInfo[playerid][pEmail],
        g_PlayerInfo[playerid][pPoint],
        g_PlayerInfo[playerid][pSkin],
        g_PlayerInfo[playerid][pCapital],
        g_PlayerInfo[playerid][pScore],
        g_PlayerInfo[playerid][pExpirience],
        date,
        ip
    );
    mysql_tquery(
        g_dbHandle,
        query,
        "",
        ""
    );

}
stock LoadPlayerAccount(playerid)
{
    cache_get_value_name(
        0, 
        "pNickName", 
        g_PlayerInfo[playerid][pNickName], 
        sizeof g_PlayerInfo[playerid][pNickName]
    );
    cache_get_value_name(
        0, 
        "pPassword", 
        g_PlayerInfo[playerid][pPassword], 
        sizeof g_PlayerInfo[playerid][pPassword]
    );
    cache_get_value_name(
        0, 
        "pEmail", 
        g_PlayerInfo[playerid][pEmail], 
        sizeof g_PlayerInfo[playerid][pEmail]
    );
    cache_get_value_name(
        0, 
        "pPoint", 
        g_PlayerInfo[playerid][pPoint], 
        sizeof g_PlayerInfo[playerid][pPoint]
    );
    cache_get_value_name(
        0, 
        "pSkin", 
        g_PlayerInfo[playerid][pSkin], 
        sizeof g_PlayerInfo[playerid][pSkin]
    );
    cache_get_value_name(
        0, 
        "pCapital", 
        g_PlayerInfo[playerid][pCapital], 
        sizeof g_PlayerInfo[playerid][pCapital]
    );
    cache_get_value_name(
        0, 
        "pScore", 
        g_PlayerInfo[playerid][pScore], 
        sizeof g_PlayerInfo[playerid][pScore]
    );
    cache_get_value_name(
        0, 
        "pExpirience", 
        g_PlayerInfo[playerid][pExpirience], 
        sizeof g_PlayerInfo[playerid][pExpirience]
    );

    SetSpawnInfo(
        playerid,
        INVALID_PLAYER_TEAM,
        g_PlayerInfo[playerid][pSkin],
        
    );
    
    SpawnPlayer(playerid);
    
    SetPlayerPos(
        playerid,
        g_SpawnPlayerPosition[0][]
    );
}
public OnPlayerSpawn(playerid)
{

    #if defined SPWN_OnPlayerSpawn
        return SPWN_OnPlayerSpawn(playerid);
    #else
        return true;
    #endif
}

#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn SPWN_OnPlayerSpawn
#if defined SPWN_OnPlayerSpawn
    forward SPWN_OnPlayerSpawn(playerid);
#endif