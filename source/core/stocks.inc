stock SendRegistrationStageOne(playerid)
{
    static const 
        fmt_str[] = 
        "\
            {030598}Добро пожаловать на сервер "FULL_PROJECT_NAME".\n\n\
            {FFFFFF}Ваш аккаунт {030598}Не зарегистрирован{FFFFFF} на сервере.\n\n\
            {FFFFFF}Ваш логин: {030598}%s.\n\
            {FFFFFF}Статус аккаунта: {030598}Свободен.\n\n\
            {FFFFFF}Для продолжения придумайте пароль:\n\
            {030598}*{FFFFFF}Пароль должен содержать от {030598}6{FFFFFF} до {030598}24{FFFFFF} символов.\n\
            {030598}*{FFFFFF}Пароль должен содержать только символы английского алфавита.\
        ";
    
    new
        string[ sizeof fmt_str + ( ( -2 ) + MAX_PLAYER_NAME ) + 1 ];
    format(
        string,
        sizeof string,
        fmt_str,
        PlayerInfo[playerid][pNickName]
    );

    return ShowPlayerDialog(
        playerid,
        DIALOGUE_REG_STAGE_ONE,
        DIALOG_STYLE_PASSWORD,
        "{FFFFFF}Регистрация {030598}[1/3]{FFFFFF} | Пароль",
        string,
        "Далее", 
        "Выход"
    );
}
stock SendRegistrationStageTwo(playerid)
{
    ShowPlayerDialog(
        playerid,
        DIALOGUE_REG_STAGE_TWO,
        DIALOG_STYLE_INPUT,
        "{FFFFFF}Регистрация {030598}[2/3]{FFFFFF} | Почта",
        "\
            {FFFFFF}Введите ваш {030598}настоящий{FFFFFF} адрес электронной почты\n\n\
            {FFFFFF}Примечание:\n\
            {030598}*{FFFFFF}Почта нужна для восстановления пароля от аккаунта.\n\
            {030598}*{FFFFFF}Почта нужна для связи администрации с вами.\n\
            {030598}*{FFFFFF}Почта должна содержать от{030598}6{FFFFFF} до {030598}35{FFFFFF} символов.\
        ",
		"Далее", 
        "Выход"
    );   
}
stock SendRegistrationStageThree(playerid)
{
    ShowPlayerDialog(
        playerid,
        DIALOGUE_REG_STAGE_THREE,
        DIALOG_STYLE_MSGBOX,
        "{FFFFFF}Регистрация {030598}[3/3]{FFFFFF} | Выбор пола",
        "{FFFFFF}Выберите пол вашего будущего персонажа",
        "Мужской",
        "Женский"
    );
}
stock SendPlayerAutorization(playerid)
{
    static const fmt_str[] =
    "\
        {030598}Добро пожаловать на сервер "FULL_PROJECT_NAME".\n\n\
        {FFFFFF}Ваш аккаунт {030598}зарегистрирован{FFFFFF} на сервере.\n\n\
        {FFFFFF}Ваш логин: {030598}%s.\n\
        {FFFFFF}Статус аккаунта:{030598}Зарегистрирован.\n\n\
        {FFFFFF}Для продолжения введите пароль:\
    ";
    new 
        string[ sizeof fmt_str + ( ( -2 ) + MAX_PLAYER_NAME ) ];
    format(
        string, 
        sizeof string, 
        fmt_str,
        PlayerInfo[playerid][pNickName]
    );
    return ShowPlayerDialog(
        playerid, 
        DIALOGUE_AUTORIZE, 
        DIALOG_STYLE_PASSWORD, 
        "{FFFFFF}Авторизация", 
        string, 
        "Далее", 
        "Выход"
    );
}
stock SetPlayerParamsKick(playerid)
{
    return Kick(playerid);
}