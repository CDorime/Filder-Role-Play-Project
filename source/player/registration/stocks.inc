stock SendRegistrationStageOne(playerid)
{
    static const 
        fmt_str[] = 
        "\
            {030598}����� ���������� �� ������ "FULL_PROJECT_NAME".\n\n\
            {FFFFFF}��� ������� {030598}�� ���������������{FFFFFF} �� �������.\n\n\
            {FFFFFF}��� �����: {030598}%s.\n\
            {FFFFFF}������ ��������: {030598}��������.\n\n\
            {FFFFFF}��� ����������� ���������� ������:\n\
            {030598}*{FFFFFF}������ ������ ��������� �� {030598}6{FFFFFF} �� {030598}24{FFFFFF} ��������.\n\
            {030598}*{FFFFFF}������ ������ ��������� ������ ������� ����������� ��������.\
        ";
    
    new
        string[ sizeof fmt_str + ( ( -2 ) + MAX_PLAYER_NAME ) + 1 ];
    format(
        string,
        sizeof string,
        fmt_str,
        g_PlayerInfo[playerid][pNickName]
    );

    return ShowPlayerDialog(
        playerid,
        DIALOGUE_REG_STAGE_ONE,
        DIALOG_STYLE_PASSWORD,
        "{FFFFFF}����������� {030598}[1/3]{FFFFFF} | ������",
        string,
        "�����", 
        "�����"
    );
}
stock SendRegistrationStageTwo(playerid)
{
    ShowPlayerDialog(
        playerid,
        DIALOGUE_REG_STAGE_TWO,
        DIALOG_STYLE_INPUT,
        "{FFFFFF}����������� {030598}[2/3]{FFFFFF} | �����",
        "\
            {FFFFFF}������� ��� {030598}���������{FFFFFF} ����� ����������� �����\n\n\
            {FFFFFF}����������:\n\
            {030598}*{FFFFFF}����� ����� ��� �������������� ������ �� ��������.\n\
            {030598}*{FFFFFF}����� ����� ��� ����� ������������� � ����.\n\
            {030598}*{FFFFFF}����� ������ ��������� ��{030598}6{FFFFFF} �� {030598}35{FFFFFF} ��������.\
        ",
		"�����", 
        "�����"
    );   
}
stock SendRegistrationStageThree(playerid)
{
    ShowPlayerDialog(
        playerid,
        DIALOGUE_REG_STAGE_THREE,
        DIALOG_STYLE_MSGBOX,
        "{FFFFFF}����������� {030598}[3/3]{FFFFFF} | ����� ����",
        "{FFFFFF}�������� ��� ������ �������� ���������",
        "�������",
        "�������"
    );
}
stock SendPlayerAutorization(playerid)
{
    static const fmt_str[] =
    "\
        {030598}����� ���������� �� ������ "FULL_PROJECT_NAME".\n\n\
        {FFFFFF}��� ������� {030598}���������������{FFFFFF} �� �������.\n\n\
        {FFFFFF}��� �����: {030598}%s.\n\
        {FFFFFF}������ ��������:{030598}���������������.\n\n\
        {FFFFFF}��� ����������� ������� ������:\
    ";
    new 
        string[ sizeof fmt_str + ( ( -2 ) + MAX_PLAYER_NAME ) ];
    format(
        string, 
        sizeof string, 
        fmt_str,
        g_PlayerInfo[playerid][pNickName]
    );
    return ShowPlayerDialog(
        playerid, 
        DIALOGUE_AUTORIZE, 
        DIALOG_STYLE_PASSWORD, 
        "{FFFFFF}�����������", 
        string, 
        "�����", 
        "�����"
    );
}
