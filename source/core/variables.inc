enum E_PLAYER_INFO
{
    pID, // Персональный ID персонажа.
    pNickName[MAX_PLAYER_NAME], // Персональный NickName персонажа.
    pPassword[MAX_PLAYER_PASSWORD], // Пароль персонажа.
    pEmail[MAX_PLAYER_EMAIL], // Адрес персонажа
    pPoint, // Стать персонажа.
    pSkin,
    pCapital,
    pScore,
    pExpirience,
    pRegistration_Date,
    pRegistration_IP,
};

enum E_CAMERA_SPAWN
{
    Float:CameraPos_X, // Позиция камеры по X.
    Float:CameraPos_Y, // Позиция камеры по Y.
    Float:CameraPos_Z // Позиция камеры по Z.
};

enum _:E_DIALOGUE_INFO
{
    DIALOGUE_NONE, // Диалог отсутствует = 0.
    DIALOGUE_REG_STAGE_ONE, // Диалог регистрации уровень Один || Пароль.
    DIALOGUE_REG_STAGE_TWO, // Диалог регистрации уровень Два || Email.
    DIALOGUE_REG_STAGE_THREE, // Диалог регистрации уровень Три || Выбор пола.
    DIALOGUE_AUTORIZE // Диалог авторизации.
};


new
    PlayerInfo[MAX_PLAYERS][E_PLAYER_INFO], // Переменная для привязки аккаунта игрока.
    MySQL:g_dbHandle,
    CameraLookAt[MAX_CAMERA_SPAWN][E_CAMERA_SPAWN] = // Переменная для отображения камеры игрока.
    {
        {1404.6460, -1584.3406, 82.1597}, // Отображения камеры игрока по SetPlayerCameraPos.
        {1404.1823, -1583.4518, 82.3703} // Отображения камеры игрока по SetPlayerCameraLookAt.
    };