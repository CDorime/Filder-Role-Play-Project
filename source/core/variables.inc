enum E_PLAYER_INFO
{
    pID, // ������������ ID ���������.
    pNickName[MAX_PLAYER_NAME], // ������������ NickName ���������.
    pPassword[MAX_PLAYER_PASSWORD], // ������ ���������.
    pEmail[MAX_PLAYER_EMAIL], // ����� ���������
    pPoint, // ����� ���������.
    pSkin,
    pCapital,
    pScore,
    pExpirience,
    pRegistration_Date,
    pRegistration_IP,
};

enum E_CAMERA_SPAWN
{
    Float:CameraPos_X, // ������� ������ �� X.
    Float:CameraPos_Y, // ������� ������ �� Y.
    Float:CameraPos_Z // ������� ������ �� Z.
};
enum E_SPAWN_POSITION
{
    Float:SpawnPos_X,
    Float:SpawnPos_Y,
    Float:SpawnPos_Z,

    Float:SpawnPos_Angle
};

enum _:E_DIALOGUE_INFO
{
    DIALOGUE_NONE, // ������ ����������� = 0.
    DIALOGUE_REG_STAGE_ONE, // ������ ����������� ������� ���� || ������.
    DIALOGUE_REG_STAGE_TWO, // ������ ����������� ������� ��� || Email.
    DIALOGUE_REG_STAGE_THREE, // ������ ����������� ������� ��� || ����� ����.
    DIALOGUE_AUTORIZE // ������ �����������.
};


new
    g_PlayerInfo[MAX_PLAYERS][E_PLAYER_INFO], // ���������� ��� �������� �������� ������.
    MySQL:g_dbHandle,
    g_CameraLookAt[MAX_CAMERA_SPAWN][E_CAMERA_SPAWN] = // ���������� ��� ����������� ������ ������.
    {
        {1404.6460, -1584.3406, 82.1597}, // ����������� ������ ������ �� SetPlayerCameraPos.
        {1404.1823, -1583.4518, 82.3703} // ����������� ������ ������ �� SetPlayerCameraLookAt.
    },
    g_SpawnPlayerPosition[MAX_SPAWN_POSITION][E_SPAWN_POSITION] =
    {
        {1756.0754,-1896.9026,13.5565,268.5927}
    };