public OnGameModeInit()
{
    LoadingVehiclesOnSpawn();
    LoadingMappingsOnSpawn();
    LoadingActorsOnSPawn();
    
    #if defined LDSPWN_OnGameModeInit
        return LDSPWN_OnGameModeInit();
    #else
        return 1;
    #endif
}
#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif

#define OnGameModeInit LDSPWN_OnGameModeInit
#if defined LDSPWN_OnGameModeInit
    forward LDSPWN_OnGameModeInit();
#endif