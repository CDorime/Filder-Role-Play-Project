stock InsertPlayerAccount(playerid)
{
    static const
        fmt_query[] = "INSERT INTO Accounts (pNickName, pPassword, pEmail, pPoint, pSkin, pCapital, pScore, pExpirience, pRegistration_Date, pRegistration_IP) VALUES (%s, %s, %s, %i, %i, %i, %i, %i, %s, %i)";
    new 
        date[MAX_LENGTH_DATE],
        year,
        month,
        day,
        hour,
        minute,
        
        ip[MAX_LENGTH_IP],
        query[sizeof fmt_query + ( ( -2 ) + MAX_PLAYER_NAME ) + ( ( -2 ) + ( MAX_PLAYER_PASSWORD ) ) + ( ( -2 ) + ( MAX_PLAYER_EMAIL ) ) + ( ( -2 ) + 1 ) + ( ( -2 ) + 3 ) + ( ( -2 ) + 8 ) + ( ( -2 ) + 8 ) + ( ( -2 ) + 8 ) + ( ( -2 ) + MAX_LENGTH_DATE ) + ( ( -2 ) + MAX_LENGTH_IP ) + 1];

    PlayerInfo[playerid][pCapital] = SET_START_CAPITAL;
    PlayerInfo[playerid][pScore] = SET_START_SCORE;

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
        PlayerInfo[playerid][pNickName],
        PlayerInfo[playerid][pPassword],
        PlayerInfo[playerid][pEmail],
        PlayerInfo[playerid][pPoint],
        PlayerInfo[playerid][pSkin],
        PlayerInfo[playerid][pCapital],
        PlayerInfo[playerid][pScore],
        PlayerInfo[playerid][pExpirience],
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
        PlayerInfo[playerid][pNickName], 
        sizeof PlayerInfo[playerid][pNickName]
    );
    cache_get_value_name(
        0, 
        "pPassword", 
        PlayerInfo[playerid][pPassword], 
        sizeof PlayerInfo[playerid][pPassword]
    );
    cache_get_value_name(
        0, 
        "pEmail", 
        PlayerInfo[playerid][pEmail], 
        sizeof PlayerInfo[playerid][pEmail]
    );
    cache_get_value_name(
        0, 
        "pPoint", 
        PlayerInfo[playerid][pPoint], 
        sizeof PlayerInfo[playerid][pPoint]
    );
    cache_get_value_name(
        0, 
        "pSkin", 
        PlayerInfo[playerid][pSkin], 
        sizeof PlayerInfo[playerid][pSkin]
    );
    cache_get_value_name(
        0, 
        "pCapital", 
        PlayerInfo[playerid][pCapital], 
        sizeof PlayerInfo[playerid][pCapital]
    );
    cache_get_value_name(
        0, 
        "pScore", 
        PlayerInfo[playerid][pScore], 
        sizeof PlayerInfo[playerid][pScore]
    );
    cache_get_value_name(
        0, 
        "pExpirience", 
        PlayerInfo[playerid][pExpirience], 
        sizeof PlayerInfo[playerid][pExpirience]
    );
    
    SpawnPlayer(playerid);
    
    
}
