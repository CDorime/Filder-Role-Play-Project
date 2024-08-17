public OnGameModeInit()
{
    g_dbHandle = mysql_connect(
        MYSQL_HOST, 
        MYSQL_USER, 
        MYSQL_PASS, 
        MYSQL_DATA
    );
    if(mysql_errno(g_dbHandle))
    {
        printf(
            "MYSQL не подключен. Ошибка: #%i", 
            mysql_errno(g_dbHandle)
        );
    }
    print("MYSQL подключен.");

    #if defined CMYSQL_OnGameModeInit
        return CMYSQL_OnGameModeInit();
    #else
        return 1;
      #endif
}
    #if defined _ALS_OnGameModeInit
        #undef OnGameModeInit
    #else
        #define _ALS_OnGameModeInit
    #endif

#define OnGameModeInit CMYSQL_OnGameModeInit
#if defined CMYSQL_OnGameModeInit
    forward CMYSQL_OnGameModeInit();
#endif