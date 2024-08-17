public OnPlayerConnectToServer(playerid)
{
    GetPlayerName(
        playerid,
        g_PlayerInfo[playerid][pNickName],
        MAX_PLAYER_NAME
    );
    static const
        fmt_query[] = "SELECT * FROM Accounts WHERE ID = %i";

    new
        query[ 56 + ( 8 + ( -2 ) ) + 1 ];

    mysql_format(
        g_dbHandle, 
        query, 
        sizeof query, 
        fmt_query, 
        g_PlayerInfo[playerid][pID]
    );
    mysql_tquery(
        g_dbHandle,
        query,
        "SearchPlayerAccount",
        "i",
        playerid
    );

    SetPlayerCameraPos(
        playerid, 
        g_CameraLookAt[0][CameraPos_X], 
        g_CameraLookAt[0][CameraPos_Y], 
        g_CameraLookAt[0][CameraPos_Z]
    );
	SetPlayerCameraLookAt(
        playerid, 
        g_CameraLookAt[1][CameraPos_X],
        g_CameraLookAt[1][CameraPos_Y],
        g_CameraLookAt[1][CameraPos_Z]
    );
    
    for(new i; i < 25; i++)
        return SendClientMessage(
            playerid, 
            0xFFFFFFFF, 
            ""
        );
	
    SendClientMessage(
        playerid, 
        0x030598FF, 
        "Добро пожаловать на сервер!"
    );

    return true;
}
public SearchPlayerAccount(playerid)
{
    new
        rows;
    
    cache_get_row_count(rows);
    if(!rows)
        return SendRegistrationStageOne(playerid);
    
    cache_get_value_name(
        0, 
        "Password", 
        g_PlayerInfo[playerid][pPassword], 
        MAX_PLAYER_PASSWORD
    );
    return SendPlayerAutorization(playerid);
}
