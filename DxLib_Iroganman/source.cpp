#include "DxLib.h"
#include <math.h>
#include "resource1.h"


#define GAME_WIDTH			960
#define GAME_HEIGHT			640
#define GAME_COLOR			32	

#define GAME_HANKEI			200

#define GAME_WINDOW_BAR		0	
#define GAME_WINDOW_NAME	"�C���K���}��"	

#define GAME_FPS			60	


#define MOUSE_BUTTON_CODE	129		


#define PATH_MAX			255	
#define NAME_MAX			255	


#define IMAGE_LOAD_ERR_TITLE	TEXT("�摜�ǂݍ��݃G���[")


//�^�C�g�����
#define IMAGE_TITLE_BK_PATH		TEXT(".\\IMAGE\\pipo-battlebg020.png")
#define IMAGE_TITLE_ROGO_PATH	TEXT(".\\IMAGE\\titlerogo.png")
#define IMAGE_TITLE_ROGO_ROTA	0.005
#define IMAGE_TITLE_ROGO_ROTA_MAX	1.0
#define IMAGE_TITLE_ROGO_X_SPEED	1
#define IMAGE_TITLE_START_PATH	TEXT(".\\IMAGE\\title_start.png")
#define IMAGE_TITLE_START_CNT	1
#define IMAGE_TITLE_START_CNT_MAX	30


//�t�@�[�X�g�X�e�[�W
//�C�G���[�X�e�[�W

#define IMAGE_BACK_PATH			TEXT(".\\IMAGE\\utyu.png")//�v���C�w�i
#define IMAGE_BACK_REV_PATH	TEXT(".\\IMAGE\\utyu.png")
#define IMAGE_BACK_NUM	4



//���ԃ|�C���g
#define IMAGE_BACK1_PATH		TEXT(".\\IMAGE\\utyu.png")


//�G���h���
#define IMAGE_ENDBACK_PATH		TEXT(".\\IMAGE\\clear_back.png")

#define IMAGE_END_COMP_PATH		TEXT(".\\IMAGE\\mission_complete.png")
#define IMAGE_END_COMP_CNT		1
#define IMAGE_END_COMP_CNT_MAX	30

#define IMAGE_END_FAIL_PATH		TEXT(".\\IMAGE\\mission_failed.png")
#define IMAGE_END_FAIL_CNT	1
#define IMAGE_END_FAIL_CNT_MAX	30



//�v���C���[
#define IMAGE_PLAYER_PATH		TEXT(".\\IMAGE\\player.png")	


//�G
#define ENEMY_PATH		TEXT(".\\IMAGE\\ENEMY\\hitome_color.png")
#define Enemy_Bomb_PATH		TEXT(".\\IMAGE\\ENEMY\\bomb_color.png")
#define Enemy_Balor_PATH		TEXT(".\\IMAGE\\ENEMY\\balor_color.png")
#define IMAGE_ENEMYFIRE_PATH		TEXT(".\\IMAGE\\ENEMY\\el_fire.png")
//#define IMAGE_ENEMY5_PATH		TEXT(".\\IMAGE\\pipo-enemy039a.png")


#define Enemy_Ahriman_PATH		TEXT(".\\IMAGE\\ENEMY\\ahriman_color.png")
#define Enemy_Num				21

#define IMAGE_syokusyu_PATH		TEXT(".\\IMAGE\\MAP2\\shokushu.png")
#define IMAGE_syokusyubig_PATH		TEXT(".\\IMAGE\\MAP2\\shokushu_big.png")
#define SHOKUSHU_NUM			40




//HP�n�[�g
#define IMAGE_HEART_PATH		TEXT(".\\IMAGE\\heart_red.png")
#define HEART_NUM				3



//���M�~�b�N��

//���[�v�Q�[�g
#define IMAGE_WARP_PATH			TEXT(".\\IMAGE\\warp.png")
#define IMAGE_GATE_PATH			TEXT(".\\IMAGE\\GATE.png")
#define GATE_NUM				5
#define YERROWWARP_PATH			TEXT(".\\IMAGE\\pipo-mapeffect013a.png")
#define GoalGate_PATH			TEXT(".\\IMAGE\\GoalGate.png")


//�N���X�^��
#define IMAGE_YERROWCRYSTAL_PATH			TEXT(".\\IMAGE\\MAP2\\crystal.png")

//�ӂ������E���
#define IMAGE_HUKIDASI_PATH			TEXT(".\\IMAGE\\hukidasi.png")
#define IMAGE_HUKIDASI2_PATH		TEXT(".\\IMAGE\\window.png")
#define IMAGE_HUKIDASI3_PATH		TEXT(".\\IMAGE\\MAP2\\window2.png")
#define IMAGE_YAJIRUSI_PATH			TEXT(".\\IMAGE\\finger_silver.png")
#define TAMASOUSA_WINDOW_PATH		TEXT(".\\IMAGE\\tamasousa.png")
#define HUKIDASI_NUM				5

//�G���A
#define IMAGE_DENGER_TATE_PATH		TEXT(".\\IMAGE\\MAP2\\denger.tate.png")
#define IMAGE_DENGER_YOKO_PATH		TEXT(".\\IMAGE\\MAP2\\denger.yoko.png")
#define DENGER_TATE_NUM				20
#define DENGER_YOKO_NUM				20

#define IMAGE_SAFE_TATE_PATH			TEXT(".\\IMAGE\\MAP2\\safe.tate.png")
#define IMAGE_SAFE_YOKO_PATH			TEXT(".\\IMAGE\\MAP2\\safe.yoko.png")
#define SAFE_TATE_NUM				20
#define SAFE_YOKO_NUM				20


//�y�A�C�e���z

//�n�[�g
#define IMAGE_KAIHUKU_PATH			TEXT(".\\IMAGE\\heart_item.png")
//�|�[�V����
#define IMAGE_PORTION_PATH			TEXT(".\\IMAGE\\portion.png")


//�y�e�z

#define TAMA_CHANGE_MAX 5
#define TAMA_MAX 16

//�e�F�̒e�摜
#define TAMA_RED_PATH		TEXT(".\\IMAGE\\TAMA\\red.png")
#define TAMA_GREEN_PATH		TEXT(".\\IMAGE\\TAMA\\green.png")
#define TAMA_BLUE_PATH		TEXT(".\\IMAGE\\TAMA\\blue.png")
#define TAMA_YELLOW_PATH		TEXT(".\\IMAGE\\TAMA\\yellow.png")

//�摜�����ڍ�
#define TAMA_DIV_WIDTH		16
#define TAMA_DIV_HEIGHT		16

#define TAMA_DIV_TATE		3
#define TAMA_DIV_YOKO		1

#define TAMA_DIV_NUM	TAMA_DIV_TATE*TAMA_DIV_YOKO



//�����y��
#define MUSIC_LOAD_ERR_TITLE	TEXT("���y�ǂݍ��݃G���[")

//�V�[��BGM
#define MUSIC_BGM_PATH			TEXT(".\\MUSIC\\game_maoudamashii_1_battle36.mp3")
#define MUSIC_STARTBGM_PATH		TEXT(".\\MUSIC\\game_maoudamashii_5_town18.mp3")
#define MUSIC_ENDBGM_PATH		TEXT(".\\MUSIC\\game_maoudamashii_7_event37.mp3")

//�e�̔��ˉ�
#define MUSIC_PLAYER_SHOT_PATH	TEXT(".\\MUSIC\\se_maoudamashii_explosion06.mp3")
#define MUSIC_GREEN_SHOT_PATH	TEXT(".\\MUSIC\\se_zuzaan.mp3")

#define MUSIC_ENTER_PATH		TEXT(".\\MUSIC\\coin03.mp3")
#define MUSIC_MENU_PATH			TEXT(".\\MUSIC\\poka01.mp3")
#define MUSIC_MENUYES_PATH			TEXT(".\\MUSIC\\select03.mp3")
#define MUSIC_MENUNO_PATH			TEXT(".\\MUSIC\\select02.mp3")

#define MUSIC_GOAL_PATH			TEXT(".\\MUSIC\\jump02.mp3")
#define MUSIC_GAMEOVER_PATH		TEXT(".\\MUSIC\\requiem2.mp3")

//�G�֘A
#define MUSIC_GEKIHA_PATH		TEXT(".\\MUSIC\\monster5.mp3")
#define MUSIC_SYOKUSYU_PATH		TEXT(".\\MUSIC\\syokusyu.mp3")

//���̑�
#define MUSIC_KAIHUKU_PATH		TEXT(".\\MUSIC\\kaihuku.mp3")
#define MUSIC_WARP_PATH		TEXT(".\\MUSIC\\.mp3")
#define MUSIC_DAMAGE_PATH		TEXT(".\\MUSIC\\damage.mp3")
#define MUSIC_HAKAI_PATH		TEXT(".\\MUSIC\\hakai.mp3")



// ���}�b�v��
#define GAME_MAP_TATE_MAX 10
#define GAME_MAP_YOKO_MAX 15
#define GEME_MAP_KIND_MAX 2

#define GAME_MAP_PATH	TEXT(".\\IMAGE\\MAP\\map.png")

#define MAP_DIV_WIDTH	64
#define MAP_DIV_HEIGHT	64
#define MAP_DIV_TATE	10
#define MAP_DIV_YOKO	4


//#define GAME_MAP_TATE_MAX 20
//#define GAME_MAP_YOKO_MAX 32
//#define GEME_MAP_KIND_MAX 2
//
//#define GAME_MAP_PATH	TEXT(".\\IMAGE\\MAP\\mapchip1.png")
//
//#define MAP_DIV_WIDTH	32
//#define MAP_DIV_HEIGHT	32
//#define MAP_DIV_TATE	32
//#define MAP_DIV_YOKO	41
//
#define MAP_DIV_NUM MAP_DIV_TATE * MAP_DIV_YOKO




#define GAME_MAP2_TATE_MAX 9
#define GAME_MAP2_YOKO_MAX 15
#define GEME_MAP2_KIND_MAX 2

#define GAME_MAP2_PATH	TEXT(".\\IMAGE\\MAP\\map.png")

#define MAP2_DIV_WIDTH	64
#define MAP2_DIV_HEIGHT	64
#define MAP2_DIV_TATE	10
#define MAP2_DIV_YOKO	4
#define MAP2_DIV_NUM MAP2_DIV_TATE * MAP2_DIV_YOKO




#define START_ERR_TITLE	TEXT("�X�^�[�g�ʒu�G���[")
#define START_ERR_CAPTION	TEXT("�X�^�[�g�ʒu�����܂��Ă��܂���")



#define GOAL_ERR_TITLE	TEXT("�S�[���ʒu�G���[")
#define GOAL_ERR_CAPTION	TEXT("�S�[���ʒu�����܂��Ă��܂���")



#define MOUSE_R_CLICK_TITLE	TEXT("�Q�[�����f")
#define MOUSE_R_CLICK_CAPTION	TEXT("�Q�[���𒆒f���A�^�C�g����ʂɖ߂�܂����H")






enum GAME_MAP_KIND
{
	n = -1,
	k = 0,
	t = 9,
	s = 5,
	g = 3
};




enum GAME_SCENE {
	GAME_SCENE_START,
	GAME_SCENE_PLAY0,
	GAME_SCENE_PLAY,
	GAME_SCENE_PLAY2,
	GAME_SCENE_RED,
	GAME_SCENE_END,
};



enum GAME_END {
	GAME_END_COMP,
	GAME_END_FAIL
};




enum CHARA_SPEED {
	CHARA_SPEED_LOW = 1,
	CHARA_SPEED_MIDI = 2,
	CHARA_SPEED_HIGH = 3
};

enum CHARA_RELOAD {
	CHARA_RELOAD_LOW = 60,
	CHARA_RELOAD_MIDI = 30,
	CHARA_RELOAD_HIGH = 15
};

enum TAMA_HIKYORI {
	TAMA_HIKYORI_LONG = 400
};

typedef struct STRUCT_I_POINT
{
	int x = -1;
	int y = -1;
}iPOINT;

typedef struct STRUCT_MOUSE
{
	int InputValue = 0;
	int WheelValue = 0;
	iPOINT Point;
	iPOINT OldPoint;
	int OldButton[MOUSE_BUTTON_CODE] = { 0 };
	int Button[MOUSE_BUTTON_CODE] = { 0 };
}MOUSE;


typedef struct STRUCT_IMAGE
{
	char path[PATH_MAX];
	int handle;
	int m_handle[6];
	int x;
	int y;
	int width;
	int height;
	double radian;
	BOOL IsDraw;
}IMAGE;


typedef struct STRUCT_ANIME
{
	/*int handle[10];*/
	int x;
	int y;
	int width;
	int height;
	BOOL IsDraw;
}ANIME;


typedef struct STRUCT_ENEMY
{
	IMAGE image;
	int width;
	int height;
	int x;
	int y;
	BOOL IsDraw;
	int speed;
	double radian;
	int hp = 100;
	int enecolor[4];

	/*int CenterX;
	int CenterY;*/
	//RECT coll;	//�����蔻��
}ENEMY;



typedef struct STRUCT_MUSIC
{
	char path[PATH_MAX];
	int handle;
}MUSIC;



typedef struct STRUCT_TAMA
{
	IMAGE image;
	char path[PATH_MAX];
	int handle[TAMA_DIV_NUM];
	int x;
	int y;
	int width;
	int height;
	BOOL IsDraw;
	int nowImageKind;
	int changeImageCnt;
	int changeImageCntMAX;
	int speed;
	int ShotFrag;
	RECT coll;					//�����蔻��
	iPOINT collBeforePt;		//������O�̍��W
}TAMA;




typedef struct STRUCT_CHARA
{
	IMAGE image;
	BOOL IsDraw;
	int speed = 4;
	int CenterX;
	int CenterY;


	MUSIC musicShot;
	MUSIC greenshot;

	BOOL CanShot;
	int ShotReLoadCnt;
	int ShotReLoadCntMAX;


	TAMA tama[TAMA_MAX];
	TAMA tama2[TAMA_MAX];
	TAMA b_tama[TAMA_MAX];
	TAMA y_tama[TAMA_MAX];


	RECT coll;
	iPOINT collBeforePt;


}CHARA;



typedef struct STRUCT_IMAGE_BACK
{
	IMAGE image;
	BOOL IsDraw;
}IMAGE_BACK;



typedef struct STRUCT_IMAGE_ROTA
{
	IMAGE image;
	double angle;
	double angleMAX;
	double rate;
	double rateMAX;
}IMAGE_ROTA;

typedef struct STRUCT_IMAGE_BLINK
{
	IMAGE image;
	int Cnt;
	int CntMAX;
	BOOL IsDraw;
}IMAGE_BLINK;



typedef struct STRUCT_MAP_IMAGE
{
	char path[PATH_MAX];
	int handle[MAP_DIV_NUM];
	int kind[MAP_DIV_NUM];
	int width;
	int height;
}MAPCHIP;

typedef struct STRUCT_MAP
{
	GAME_MAP_KIND kind;
	int x;
	int y;
	int width;
	int height;

}MAP;



typedef struct STRUCT_MAP2_IMAGE
{
	char path[PATH_MAX];
	int handle[MAP2_DIV_NUM];
	int kind[MAP2_DIV_NUM];
	int width;
	int height;
}MAPCHIP2;

typedef struct STRUCT_MAP2
{
	GAME_MAP_KIND kind;
	int x;
	int y;
	int width;
	int height;

}MAP2;




int StartTimeFps;
int CountFps;
float CalcFps;
int SampleNumFps = GAME_FPS;

char AllKeyState[256] = { '\0' };
char OldAllKeyState[256] = { '\0' };

MOUSE mouse;

int GameScene;



int GameEndKind;

//�J�E���g
int St1count = 0.0;
int St2count = 0.0;
int mutekicount = 0.0;
int tyuukann_count = 0.0;
int warpcount = 0;
int leftcount = 1;
int rightcount = 0;
int bootscount;
int portioncount;
int windowcount;
int mojihyoujicount;

int muki = 3;


//�t���O
int hidariflag = FALSE;
int migiflag = FALSE;
int stopflag = FALSE;
int y_crystal_Flag = FALSE;
int FirstStIn = FALSE;

//�E�B���h�E
int EnterDraw = FALSE;
int setumei2 = FALSE;
int setumei3 = FALSE;
int warptext = FALSE;
int kaihukutext = FALSE;
int crystaltext = FALSE;
BOOL MojiDraw = FALSE;

//�A�j���[�V�����n���h��
int warphandle[15];
int y_warphandle[10];
int gatehandle[10];
int crystalhandle[20];

int heartnow = 3;
int hp = 500;


BOOL IsMuteki = FALSE;
BOOL Ishit = TRUE;
BOOL Sousa = TRUE;
BOOL AitemCount = FALSE;

RECT GoalRect = { -1,-1,-1,-1 };


IMAGE_BACK ImageBack[IMAGE_BACK_NUM];

IMAGE back1;
IMAGE STARTBACK;
IMAGE endback;

IMAGE ImageTitleBK;
IMAGE_ROTA ImageTitleROGO;
IMAGE_BLINK ImageTitleSTART;


IMAGE_BLINK ImageEndCOMP;
IMAGE_BLINK ImageEndFAIL;

ENEMY enemy[Enemy_Num];
ENEMY Enemy_Bomb[Enemy_Num];
ENEMY Enemy_Balor[Enemy_Num];
//ENEMY enemy4[Enemy_Num];
//ENEMY enemy5;
ENEMY Enemy_Ahriman[Enemy_Num];


IMAGE syokusyu[SHOKUSHU_NUM];

IMAGE syokusyu_big[SHOKUSHU_NUM];

IMAGE heart[HEART_NUM];

IMAGE denger_tate[DENGER_TATE_NUM];
IMAGE denger_yoko[DENGER_YOKO_NUM];

IMAGE safe_tate[SAFE_TATE_NUM];
IMAGE safe_yoko[SAFE_YOKO_NUM];

IMAGE goalgazou;
IMAGE y_crystal;
IMAGE kaihuku;
IMAGE portion;
//IMAGE gate[GATE_NUM];
IMAGE hukidasi[HUKIDASI_NUM];
IMAGE hukidasi2;
IMAGE hukidasi3;
IMAGE yajirusi;
IMAGE tamasousa_gazou;

ANIME y_warp;
ANIME warp;
ANIME gate[GATE_NUM];

CHARA player;


MUSIC BGM;
MUSIC STARTBGM;
MUSIC ENDBGM;
MUSIC ENTER;
MUSIC menu;
MUSIC menuyes;
MUSIC menuno;
MUSIC goal;
MUSIC gameover;
MUSIC damage;
MUSIC kaihuku_oto;
MUSIC hakai;
MUSIC gekiha;
MUSIC syokusyu_oto;


GAME_MAP_KIND mapData[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX]{
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,
	k,t,t,t,t,t,t,t,t,t,t,t,t,t,k,
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,
	k,t,t,t,k,t,t,t,t,t,k,t,t,t,k,
	k,t,t,t,t,t,t,t,t,t,t,t,t,t,k,
	k,t,t,t,t,t,t,t,t,t,t,t,t,t,k,
	k,t,t,t,k,t,t,t,t,t,k,t,t,t,k,
	k,k,k,k,k,k,k,k,k,k,k,t,t,t,k,
	k,t,t,t,k,t,t,t,t,t,k,t,t,t,k,
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k

};

GAME_MAP_KIND mapDataInit[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

MAPCHIP mapChip;

MAP map[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

iPOINT startPt{ -1,-1 };


RECT mapColl[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];



VOID MY_FPS_UPDATE(VOID);
VOID MY_FPS_DRAW(VOID);
VOID MY_FPS_WAIT(VOID);

VOID MY_ALL_KEYDOWN_UPDATE(VOID);
BOOL MY_KEY_DOWN(int);
BOOL MY_KEY_UP(int);
BOOL MY_KEYDOWN_KEEP(int, int);

VOID MY_MOUSE_UPDATE(VOID);
BOOL MY_MOUSE_DOWN(int);
BOOL MY_MOUSE_UP(int);
BOOL MY_MOUSEDOWN_KEEP(int, int);

VOID MY_START(VOID);
VOID MY_START_PROC(VOID);
VOID MY_START_DRAW(VOID);

VOID MY_PLAY(VOID);
VOID MY_PLAY_PROC(VOID);
VOID MY_PLAY_DRAW(VOID);

VOID MY_END(VOID);
VOID MY_END_PROC(VOID);
VOID MY_END_DRAW(VOID);

VOID MY_PLAY2(VOID);
VOID MY_PLAY2_PROC(VOID);
VOID MY_PLAY2_DRAW(VOID);


VOID MY_PLAY0(VOID);
VOID MY_PLAY0_PROC(VOID);
VOID MY_PLAY0_DRAW(VOID);


BOOL MY_LOAD_IMAGE(VOID);
VOID MY_DELETE_IMAGE(VOID);

BOOL MY_LOAD_MUSIC(VOID);
VOID MY_DELETE_MUSIC(VOID);


BOOL MY_CHECK_MAP1_PLAYER_COLL(RECT);
BOOL MY_CHECK_RECT_COLL(RECT, RECT);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{


	ChangeWindowMode(TRUE);
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);
	SetWindowStyleMode(GAME_WINDOW_BAR);
	SetMainWindowText(TEXT(GAME_WINDOW_NAME));
	SetAlwaysRunFlag(TRUE);
	SetWindowIconID(IDI_ICON1);


	if (DxLib_Init() == -1) { return -1; }

	if (MY_LOAD_IMAGE() == FALSE) { return -1; }
	if (MY_LOAD_MUSIC() == FALSE) { return -1; }



	//�����[�h
	player.CanShot = TRUE;
	player.ShotReLoadCnt = 0;

	if (AitemCount == TRUE)
	{
		player.ShotReLoadCntMAX = CHARA_RELOAD_HIGH;
	}
	else
	{
		player.ShotReLoadCntMAX = CHARA_RELOAD_MIDI;
	}



	SetMouseDispFlag(TRUE);


	GameScene = GAME_SCENE_START;

	SetDrawScreen(DX_SCREEN_BACK);


	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			if (mapData[tate][yoko] == s)
			{
				startPt.x = mapChip.width * yoko + mapChip.width / 2;
				startPt.y = mapChip.height * tate + mapChip.height / 2;
			}

			if (mapData[tate][yoko] == g)
			{
				GoalRect.left = mapChip.width * yoko;
				GoalRect.top = mapChip.width * tate;
				GoalRect.right = mapChip.width * (yoko + 1);
				GoalRect.bottom = mapChip.height * (tate + 1);
			}
		}
	}


	/*if (startPt.x == -1 && startPt.y == -1)
	{
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION, START_ERR_TITLE, MB_OK); return -1;
	}*/


	while (TRUE)
	{

		if (ProcessMessage() != 0) { break; }
		if (ClearDrawScreen() != 0) { break; }

		MY_ALL_KEYDOWN_UPDATE();

		MY_MOUSE_UPDATE();

		MY_FPS_UPDATE();


		switch (GameScene)
		{
		case GAME_SCENE_START:
			MY_START();
			break;
		case GAME_SCENE_PLAY0:
			MY_PLAY0();
			break;
		case GAME_SCENE_PLAY:
			MY_PLAY();
			break;
		case GAME_SCENE_PLAY2:
			MY_PLAY2();
			break;
		case GAME_SCENE_END:
			MY_END();
			break;
		}

		MY_FPS_DRAW();

		ScreenFlip();

		MY_FPS_WAIT();
	}


	MY_DELETE_IMAGE();


	MY_DELETE_MUSIC();


	DxLib_End();

	return 0;
}

VOID MY_FPS_UPDATE(VOID)
{
	if (CountFps == 0)
	{
		StartTimeFps = GetNowCount();
	}

	if (CountFps == SampleNumFps)
	{
		int now = GetNowCount();
		CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
		CountFps = 0;
		StartTimeFps = now;
	}
	CountFps++;
	return;
}

VOID MY_FPS_DRAW(VOID)
{
	DrawFormatString(0, GAME_HEIGHT - 20, GetColor(255, 255, 255), "FPS:%.1f", CalcFps);
	return;
}

VOID MY_FPS_WAIT(VOID)
{
	int resultTime = GetNowCount() - StartTimeFps;
	int waitTime = CountFps * 1000 / GAME_FPS - resultTime;

	if (waitTime > 0)
	{
		WaitTimer(waitTime);
	}
	return;
}


VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{


	char TempKey[256];


	for (int i = 0; i < 256; i++)
	{
		OldAllKeyState[i] = AllKeyState[i];
	}

	GetHitKeyStateAll(TempKey);

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)
		{
			AllKeyState[i]++;
		}
		else
		{
			AllKeyState[i] = 0;
		}
	}
	return;
}


BOOL MY_KEY_DOWN(int KEY_INPUT_)
{
	if (AllKeyState[KEY_INPUT_] != 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


BOOL MY_KEY_UP(int KEY_INPUT_)
{
	if (OldAllKeyState[KEY_INPUT_] >= 1
		&& AllKeyState[KEY_INPUT_] == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


BOOL MY_KEYDOWN_KEEP(int KEY_INPUT_, int DownTime)
{

	int UpdateTime = DownTime * GAME_FPS;

	if (AllKeyState[KEY_INPUT_] > UpdateTime)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


VOID MY_MOUSE_UPDATE(VOID)
{

	mouse.OldPoint = mouse.Point;


	for (int i = 0; i < MOUSE_BUTTON_CODE; i++) { mouse.OldButton[i] = mouse.Button[i]; }


	GetMousePoint(&mouse.Point.x, &mouse.Point.y);


	mouse.InputValue = GetMouseInput();


	if ((mouse.InputValue & MOUSE_INPUT_LEFT) == MOUSE_INPUT_LEFT) { mouse.Button[MOUSE_INPUT_LEFT]++; }		//�����Ă���
	if ((mouse.InputValue & MOUSE_INPUT_LEFT) != MOUSE_INPUT_LEFT) { mouse.Button[MOUSE_INPUT_LEFT] = 0; }		//�����Ă��Ȃ�


	if ((mouse.InputValue & MOUSE_INPUT_MIDDLE) == MOUSE_INPUT_MIDDLE) { mouse.Button[MOUSE_INPUT_MIDDLE]++; }	//�����Ă���
	if ((mouse.InputValue & MOUSE_INPUT_MIDDLE) != MOUSE_INPUT_MIDDLE) { mouse.Button[MOUSE_INPUT_MIDDLE] = 0; }	//�����Ă��Ȃ�


	if ((mouse.InputValue & MOUSE_INPUT_RIGHT) == MOUSE_INPUT_RIGHT) { mouse.Button[MOUSE_INPUT_RIGHT]++; }		//�����Ă���
	if ((mouse.InputValue & MOUSE_INPUT_RIGHT) != MOUSE_INPUT_RIGHT) { mouse.Button[MOUSE_INPUT_RIGHT] = 0; }	//�����Ă��Ȃ�


	mouse.WheelValue = GetMouseWheelRotVol();

	return;
}


BOOL MY_MOUSE_DOWN(int MOUSE_INPUT_)
{

	if (mouse.Button[MOUSE_INPUT_] != 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


BOOL MY_MOUSE_UP(int MOUSE_INPUT_)
{
	if (mouse.OldButton[MOUSE_INPUT_] >= 1
		&& mouse.Button[MOUSE_INPUT_] == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


BOOL MY_MOUSEDOWN_KEEP(int MOUSE_INPUT_, int DownTime)
{

	int UpdateTime = DownTime * GAME_FPS;

	if (mouse.Button[MOUSE_INPUT_] > UpdateTime)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}



VOID MY_START(VOID)
{
	MY_START_PROC();
	MY_START_DRAW();

	return;
}

VOID MY_START_PROC(VOID)
{


	//�^�C�g��BGM�𗬂�
	if (CheckSoundMem(STARTBGM.handle) == 0)
	{
		ChangeVolumeSoundMem(255 * 70 / 100, STARTBGM.handle);	//50%�̉��ʂɂ���


		PlaySoundMem(STARTBGM.handle, DX_PLAYTYPE_LOOP);
	}

	//�G���^�[�L�[���͎��A�v���C�V�[���֑J��
	if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
	{
		if (CheckSoundMem(STARTBGM.handle) != 0)
		{
			StopSoundMem(STARTBGM.handle);	//BGM���~�߂�
		}

		SetMouseDispFlag(FALSE);

		//�X�e�[�W�P�̃J�E���g��������
		St1count = 0;

		//�n�[�g�̐���������
		heartnow = 3;


		FirstStIn = TRUE;

		player.CenterX = 700;
		player.CenterY = 300;

		player.image.x = player.CenterX;
		player.image.y = player.CenterY;

		player.collBeforePt.x = player.CenterX;
		player.collBeforePt.y = player.CenterY;


		for (int cnt = 0; cnt < TAMA_MAX; cnt++)
		{
			player.tama[cnt].IsDraw = FALSE;
			player.tama2[cnt].IsDraw = FALSE;
			player.b_tama[cnt].IsDraw = FALSE;
			player.y_tama[cnt].IsDraw = FALSE;
		}


		//�n�[�g�̈ʒu
		for (int i = 0; i < HEART_NUM; i++)
		{
			heart[i] = heart[0];

			heart[0].x = 850;
			heart[0].y = 30;

			heart[1].x = 770;
			heart[1].y = 30;

			heart[2].x = 690;
			heart[2].y = 30;

		}

		//�ӂ�����
		for (int i = 0; i < HUKIDASI_NUM; i++)
		{
			hukidasi[i] = hukidasi[0];

			hukidasi[0].x = 410;
			hukidasi[0].y = 260;

			hukidasi[1].x = 60;
			hukidasi[1].y = 260;

		}


		//�G�i��ځj�̔z�u

		for (int kazu = 0; kazu < Enemy_Num; kazu++)
		{
			enemy[kazu].image = enemy[0].image;

			enemy[0].image.x = -100;
			enemy[0].image.y = 200;

			enemy[1].image.x = -100;
			enemy[1].image.y = 400;

			enemy[2].image.x = -100;
			enemy[2].image.y = 200;

			enemy[3].image.x = -100;
			enemy[3].image.y = 400;

			enemy[4].image.x = -100;
			enemy[4].image.y = 100;

			enemy[5].image.x = -200;
			enemy[5].image.y = 300;

			enemy[6].image.x = -300;
			enemy[6].image.y = 500;

		}


		//�q�m�^�}�̔z�u
		for (int kazu = 0; kazu < Enemy_Num; kazu++)
		{
			Enemy_Bomb[kazu].image = Enemy_Bomb[0].image;

			Enemy_Bomb[0].image.x = -100;

			Enemy_Bomb[1].image.x = -100;

			Enemy_Bomb[2].image.x = -100;

			Enemy_Bomb[3].image.x = -100;

			Enemy_Bomb[4].image.x = -300;

			Enemy_Bomb[5].image.x = -500;


		}


		for (int i = 0; i < GATE_NUM; i++)
		{
			gate[i] = gate[0];

			//�e�X�g�p
			/*gate[0].x = 300;
			gate[0].y = 340;*/

			//�{�ԗp
			gate[0].x = -200;
			gate[0].y = 340;
		}





		//�G�i�F�ω��j�̔z�u

		for (int kazu = 0; kazu < Enemy_Num; kazu++)
		{
			Enemy_Ahriman[kazu].image = Enemy_Ahriman[0].image;


			Enemy_Ahriman[0].image.x = -400;

			Enemy_Ahriman[1].image.x = -400;

			Enemy_Ahriman[2].image.x = -400;

			Enemy_Ahriman[3].image.x = -400;

		}




		GameEndKind = GAME_END_FAIL;

		GameScene = GAME_SCENE_PLAY0;

		PlaySoundMem(ENTER.handle, DX_PLAYTYPE_BACK);

		return;
	}




	if (ImageTitleROGO.rate < ImageTitleROGO.rateMAX)
	{
		ImageTitleROGO.rate += IMAGE_TITLE_ROGO_ROTA;
	}

	if (ImageTitleROGO.image.x < GAME_WIDTH / 2)
	{
		ImageTitleROGO.image.x += IMAGE_TITLE_ROGO_X_SPEED;
	}
	else
	{

		if (ImageTitleSTART.Cnt < ImageTitleSTART.CntMAX)
		{
			ImageTitleSTART.Cnt += IMAGE_TITLE_START_CNT;

		}
		else
		{
			if (ImageTitleSTART.IsDraw == FALSE)
			{
				ImageTitleSTART.IsDraw = TRUE;
			}
			else if (ImageTitleSTART.IsDraw == TRUE)
			{
				ImageTitleSTART.IsDraw = FALSE;
			}

			ImageTitleSTART.Cnt = 0;
		}
	}

	return;
}

VOID MY_START_DRAW(VOID)
{
	DrawGraph(ImageTitleBK.x, ImageTitleBK.y, ImageTitleBK.handle, TRUE);

	DrawRotaGraph(
		ImageTitleROGO.image.x, ImageTitleROGO.image.y,
		ImageTitleROGO.rate,
		ImageTitleROGO.angle,
		ImageTitleROGO.image.handle, TRUE);

	if (ImageTitleSTART.IsDraw == TRUE)
	{
		DrawGraph(ImageTitleSTART.image.x, ImageTitleSTART.image.y, ImageTitleSTART.image.handle, TRUE);
	}

	DrawString(0, 0, "�X�^�[�g���(�G���^�[�L�[�������ĉ�����)", GetColor(255, 255, 255));

	return;
}



//�X�e�[�W�P
VOID MY_PLAY0(VOID)
{
	MY_PLAY0_PROC();
	MY_PLAY0_DRAW();

	return;
}



VOID MY_PLAY0_PROC(VOID)
{

	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		ImageBack[num].image.x++;

		if (ImageBack[num].IsDraw == FALSE)
		{
			if (ImageBack[num].image.x + ImageBack[num].image.width > 0)
			{
				ImageBack[num].IsDraw = TRUE;
			}
		}

		if (ImageBack[num].image.x > GAME_WIDTH)
		{
			ImageBack[num].image.x = 0 - ImageBack[0].image.width * 3;
			ImageBack[num].IsDraw = FALSE;
		}
	}



	if (CheckSoundMem(BGM.handle) == 0)
	{
		PlaySoundMem(BGM.handle, DX_PLAYTYPE_LOOP);
	}


	if (mouse.Button[MOUSE_INPUT_RIGHT] == TRUE)
	{

		PlaySoundMem(menu.handle, DX_PLAYTYPE_BACK);

		iPOINT R_ClickPt = mouse.Point;

		SetMouseDispFlag(TRUE);

		int Ret = MessageBox(GetMainWindowHandle(), MOUSE_R_CLICK_CAPTION, MOUSE_R_CLICK_TITLE, MB_YESNO);

		if (Ret == IDYES)
		{
			PlaySoundMem(menuyes.handle, DX_PLAYTYPE_BACK);

			if (CheckSoundMem(BGM.handle) != 0)
			{
				StopSoundMem(BGM.handle);
			}

			SetMouseDispFlag(TRUE);

			GameScene = GAME_SCENE_START;
			return;
		}

		else if (Ret == IDNO)
		{
			PlaySoundMem(menuno.handle, DX_PLAYTYPE_BACK);

			SetMousePoint(R_ClickPt.x, R_ClickPt.y);

			SetMouseDispFlag(FALSE);
		}
	}


	//�v���C���[�̑��x&�L�[����ݒ�


	player.speed = 4;
	if (MY_KEY_DOWN(KEY_INPUT_UP) == TRUE)
	{
		player.CenterY -= player.speed;
	}
	if (MY_KEY_DOWN(KEY_INPUT_DOWN) == TRUE)
	{
		player.CenterY += player.speed;
	}
	if (MY_KEY_DOWN(KEY_INPUT_LEFT) == TRUE)
	{
		player.CenterX -= player.speed;
	}
	if (MY_KEY_DOWN(KEY_INPUT_RIGHT) == TRUE)
	{
		player.CenterX += player.speed;
	}

	BOOL IsMove = TRUE;

	if (IsMove == TRUE)
	{
		player.image.x = player.CenterX - player.image.width / 2;
		player.image.y = player.CenterY - player.image.height / 2;

		player.collBeforePt.x = player.CenterX;
		player.collBeforePt.y = player.CenterY;
	}


	for (int a = 0; a < Enemy_Num; a++)
	{
		RECT PlayerRect;
		int CollRange = 2;
		PlayerRect.left = player.image.x + player.image.width / 2 - CollRange;
		PlayerRect.top = player.image.y + player.image.height / 2 - CollRange;
		PlayerRect.right = player.image.x + player.image.width / 2 + CollRange;
		PlayerRect.bottom = player.image.y + player.image.height / 2 + CollRange;

		RECT EnemyRect;
		EnemyRect.left = enemy[a].image.x;
		EnemyRect.top = enemy[a].image.y;
		EnemyRect.right = enemy[a].image.x + enemy[a].image.width;
		EnemyRect.bottom = enemy[a].image.y + enemy[a].image.height;

		RECT Enemy_BombRect;
		Enemy_BombRect.left = Enemy_Bomb[a].image.x;
		Enemy_BombRect.top = Enemy_Bomb[a].image.y;
		Enemy_BombRect.right = Enemy_Bomb[a].image.x + Enemy_Bomb[a].image.width;
		Enemy_BombRect.bottom = Enemy_Bomb[a].image.y + Enemy_Bomb[a].image.height;

		RECT Enemy_AhrimanRect;
		Enemy_AhrimanRect.left = Enemy_Ahriman[a].image.x;
		Enemy_AhrimanRect.top = Enemy_Ahriman[a].image.y;
		Enemy_AhrimanRect.right = Enemy_Ahriman[a].image.x + Enemy_Ahriman[a].image.width;
		Enemy_AhrimanRect.bottom = Enemy_Ahriman[a].image.y + Enemy_Ahriman[a].image.height;

		RECT GateRect;
		GateRect.left = gate[0].x;
		GateRect.top = gate[0].y;
		GateRect.right = gate[0].x + 192;
		GateRect.bottom = gate[0].y + 192;


		//�Q�[�g�ڐG
		if (MY_CHECK_RECT_COLL(PlayerRect, GateRect) == TRUE)
		{
			//SPACE�A�C�R����\��
			hukidasi[2].IsDraw = TRUE;

			//SPACE�������ƒ��ԃ|�C���g�ֈړ�
			if (MY_KEY_DOWN(KEY_INPUT_SPACE) == TRUE)
			{
				PlaySoundMem(goal.handle, DX_PLAYTYPE_BACK);

				player.CenterX = 800;
				player.CenterY = 300;

				player.image.x = player.CenterX;
				player.image.y = player.CenterY;

				player.collBeforePt.x = player.CenterX;
				player.collBeforePt.y = player.CenterY;

				GameScene = GAME_SCENE_PLAY;
			}
		}
		else {
			hukidasi[2].IsDraw = FALSE;
		}


		//�q�g�c���̐ڐG�`�F�b�N
		if (MY_CHECK_RECT_COLL(PlayerRect, EnemyRect) == TRUE)
		{
			mutekicount = 0;
			heartnow -= 1;
			IsMuteki = TRUE;
			PlaySoundMem(damage.handle, DX_PLAYTYPE_BACK);
		}


		//�q�m�^�}�̐ڐG�`�F�b�N
		if (MY_CHECK_RECT_COLL(PlayerRect, Enemy_BombRect) == TRUE)
		{
			mutekicount = 0;
			heartnow -= 1;
			IsMuteki = TRUE;
			PlaySoundMem(damage.handle, DX_PLAYTYPE_BACK);
		}

		//�C���K�����̐ڐG
		if (MY_CHECK_RECT_COLL(PlayerRect, Enemy_AhrimanRect) == TRUE)
		{
			mutekicount = 0;
			heartnow -= 1;
			IsMuteki = TRUE;
			PlaySoundMem(damage.handle, DX_PLAYTYPE_BACK);
		}

	}



	//���G����
	if (IsMuteki == TRUE)
	{
		mutekicount++;
		if (mutekicount < 31)
		{
			Ishit = FALSE;
			if (player.IsDraw == TRUE)
			{
				player.IsDraw = FALSE;
			}
			else if (player.IsDraw == FALSE)
			{
				player.IsDraw = TRUE;
			}
		}
		if (mutekicount > 31)
		{
			Ishit = TRUE;
		}
	}


	//�n�[�g���S�ĂȂ��Ȃ�����Q�[���I�[�o�[
	if (heartnow == FALSE)
	{
		if (CheckSoundMem(BGM.handle) != 0)
		{
			StopSoundMem(BGM.handle);
		}

		GameEndKind = GAME_END_FAIL;	//�~�b�V�����t�H�[���g�I

		GameScene = GAME_SCENE_END;

		return;	//�����I�ɃG���h��ʂɔ��
	}



	//�v���C���[����ʊO�ɏo����
	if (player.image.x > GAME_WIDTH || player.image.y > GAME_HEIGHT
		|| player.image.x + player.image.width < 0 || player.image.y + player.image.height < 0)
	{
		if (CheckSoundMem(BGM.handle) != 0)
		{
			StopSoundMem(BGM.handle);
		}

		SetMouseDispFlag(TRUE);

		GameEndKind = GAME_END_FAIL;

		GameScene = GAME_SCENE_END;

		return;
	}






	//�Ԓe�𔭎�
	if (MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
	{
		if (player.CanShot == TRUE)
		{
			PlaySoundMem(player.greenshot.handle, DX_PLAYTYPE_BACK);
			player.CanShot = FALSE;


			for (int cnt = 0; cnt < TAMA_MAX; cnt++)
			{
				if (player.tama[cnt].IsDraw == FALSE)
				{
					player.tama[cnt].x = player.image.x - 10;

					player.tama[cnt].y = player.CenterY - 20;/* - player.tama[cnt].height*/;

					player.tama[cnt].IsDraw = TRUE;

					break;
				}

			}
		}
	}



	//�Βe�𔭎�
	if (MY_KEY_DOWN(KEY_INPUT_S) == TRUE)
	{
		if (player.CanShot == TRUE)
		{
			PlaySoundMem(player.greenshot.handle, DX_PLAYTYPE_BACK);
			player.CanShot = FALSE;


			for (int cnt = 0; cnt < TAMA_MAX; cnt++)
			{
				if (player.tama2[cnt].IsDraw == FALSE)
				{

					player.tama2[cnt].x = player.image.x - 10;

					player.tama2[cnt].y = player.CenterY - 20;

					player.tama2[cnt].IsDraw = TRUE;

					break;
				}
			}

		}
	}


	//�e
	if (MY_KEY_DOWN(KEY_INPUT_D) == TRUE)
	{
		if (player.CanShot == TRUE)
		{
			PlaySoundMem(player.greenshot.handle, DX_PLAYTYPE_BACK);
			player.CanShot = FALSE;


			for (int cnt = 0; cnt < TAMA_MAX; cnt++)
			{
				if (player.b_tama[cnt].IsDraw == FALSE)
				{

					player.b_tama[cnt].x = player.image.x - 10;

					player.b_tama[cnt].y = player.CenterY - 20;

					player.b_tama[cnt].IsDraw = TRUE;

					break;
				}
			}

		}
	}



	//���e
	if (MY_KEY_DOWN(KEY_INPUT_F) == TRUE)
	{
		if (player.CanShot == TRUE)
		{
			PlaySoundMem(player.greenshot.handle, DX_PLAYTYPE_BACK);
			player.CanShot = FALSE;


			for (int cnt = 0; cnt < TAMA_MAX; cnt++)
			{
				if (player.y_tama[cnt].IsDraw == FALSE)
				{

					player.y_tama[cnt].x = player.image.x - 10;

					player.y_tama[cnt].y = player.CenterY - 20;

					player.y_tama[cnt].IsDraw = TRUE;

					break;
				}
			}

		}
	}



	//�F�ς��ƒe�̓����蔻��
	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		for (int kazu = 0; kazu < Enemy_Num; kazu++)
		{

			//�Ԓe
			if (((player.tama[cnt].x > Enemy_Ahriman[kazu].image.x && player.tama[cnt].x < Enemy_Ahriman[kazu].image.x + Enemy_Ahriman[kazu].image.width) ||
				(Enemy_Ahriman[kazu].image.x > player.tama[cnt].x && Enemy_Ahriman[kazu].image.x < player.tama[cnt].x + player.tama[cnt].width)) &&
				((player.tama[cnt].y > Enemy_Ahriman[kazu].image.y && player.tama[cnt].y < Enemy_Ahriman[kazu].image.y + Enemy_Ahriman[kazu].image.height) ||
					(Enemy_Ahriman[kazu].image.y > player.tama[cnt].y && Enemy_Ahriman[kazu].image.y < player.tama[cnt].y + player.tama[cnt].height)))
			{
				if (kazu == 0)
				{

					if (Enemy_Ahriman[0].hp == 100)
					{
						player.tama[cnt].IsDraw = FALSE;
						player.tama[cnt].x = 0;
						player.tama[cnt].y = 1000;

						Enemy_Ahriman[0].hp -= 50;

					}

				}

				if (kazu == 3)
				{
					if (Enemy_Ahriman[3].hp == 50)
					{

						player.tama[cnt].IsDraw = FALSE;
						player.tama[cnt].x = 0;
						player.tama[cnt].y = 1000;

						PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

						Enemy_Ahriman[3].image.IsDraw = FALSE;
						Enemy_Ahriman[3].image.width = 0;
						Enemy_Ahriman[3].image.height = 0;
						Enemy_Ahriman[3].image.x = 1000;
					}
				}

			}

			//�Βe
			if (((player.tama2[cnt].x > Enemy_Ahriman[kazu].image.x && player.tama2[cnt].x < Enemy_Ahriman[kazu].image.x + Enemy_Ahriman[kazu].image.width) ||
				(Enemy_Ahriman[kazu].image.x > player.tama2[cnt].x && Enemy_Ahriman[kazu].image.x < player.tama2[cnt].x + player.tama2[cnt].width)) &&
				((player.tama2[cnt].y > Enemy_Ahriman[kazu].image.y && player.tama2[cnt].y < Enemy_Ahriman[kazu].image.y + Enemy_Ahriman[kazu].image.height) ||
					(Enemy_Ahriman[kazu].image.y > player.tama2[cnt].y && Enemy_Ahriman[kazu].image.y < player.tama2[cnt].y + player.tama2[cnt].height)))
			{
				if (kazu == 0)
				{
					if (Enemy_Ahriman[0].hp == 50)
					{

						player.tama2[cnt].IsDraw = FALSE;
						player.tama2[cnt].x = 0;
						player.tama2[cnt].y = 1000;

						PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

						Enemy_Ahriman[0].image.IsDraw = FALSE;
						Enemy_Ahriman[0].image.width = 0;
						Enemy_Ahriman[0].image.height = 0;
						Enemy_Ahriman[0].image.x = 1000;
					}
				}

				if (kazu == 2)
				{

					if (Enemy_Ahriman[2].hp == 100)
					{
						player.tama2[cnt].IsDraw = FALSE;
						player.tama2[cnt].x = 0;
						player.tama2[cnt].y = 1000;

						Enemy_Ahriman[2].hp -= 50;

					}

				}
			}

			//�e
			if (((player.b_tama[cnt].x > Enemy_Ahriman[kazu].image.x && player.b_tama[cnt].x < Enemy_Ahriman[kazu].image.x + Enemy_Ahriman[kazu].image.width) ||
				(Enemy_Ahriman[kazu].image.x > player.b_tama[cnt].x && Enemy_Ahriman[kazu].image.x < player.b_tama[cnt].x + player.b_tama[cnt].width)) &&
				((player.b_tama[cnt].y > Enemy_Ahriman[kazu].image.y && player.b_tama[cnt].y < Enemy_Ahriman[kazu].image.y + Enemy_Ahriman[kazu].image.height) ||
					(Enemy_Ahriman[kazu].image.y > player.b_tama[cnt].y && Enemy_Ahriman[kazu].image.y < player.b_tama[cnt].y + player.b_tama[cnt].height)))
			{
				if (kazu == 1)
				{
					if (Enemy_Ahriman[1].hp == 50)
					{

						player.b_tama[cnt].IsDraw = FALSE;
						player.b_tama[cnt].x = 0;
						player.b_tama[cnt].y = 1000;

						PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

						Enemy_Ahriman[1].image.IsDraw = FALSE;
						Enemy_Ahriman[1].image.width = 0;
						Enemy_Ahriman[1].image.height = 0;
						Enemy_Ahriman[1].image.x = 1000;
					}
				}

				if (kazu == 3)
				{

					if (Enemy_Ahriman[3].hp == 100)
					{
						player.b_tama[cnt].IsDraw = FALSE;
						player.b_tama[cnt].x = 0;
						player.b_tama[cnt].y = 1000;

						Enemy_Ahriman[3].hp -= 50;

					}

				}
			}

			//���e
			if (((player.y_tama[cnt].x > Enemy_Ahriman[kazu].image.x && player.y_tama[cnt].x < Enemy_Ahriman[kazu].image.x + Enemy_Ahriman[kazu].image.width) ||
				(Enemy_Ahriman[kazu].image.x > player.y_tama[cnt].x && Enemy_Ahriman[kazu].image.x < player.y_tama[cnt].x + player.y_tama[cnt].width)) &&
				((player.y_tama[cnt].y > Enemy_Ahriman[kazu].image.y && player.y_tama[cnt].y < Enemy_Ahriman[kazu].image.y + Enemy_Ahriman[kazu].image.height) ||
					(Enemy_Ahriman[kazu].image.y > player.y_tama[cnt].y && Enemy_Ahriman[kazu].image.y < player.y_tama[cnt].y + player.y_tama[cnt].height)))
			{
				if (kazu == 1)
				{

					if (Enemy_Ahriman[1].hp == 100)
					{
						player.y_tama[cnt].IsDraw = FALSE;
						player.y_tama[cnt].x = 0;
						player.y_tama[cnt].y = 1000;

						Enemy_Ahriman[1].hp -= 50;

					}
				}

				if (kazu == 2)
				{
					if (Enemy_Ahriman[2].hp == 50)
					{

						player.y_tama[cnt].IsDraw = FALSE;
						player.y_tama[cnt].x = 0;
						player.y_tama[cnt].y = 1000;

						PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

						Enemy_Ahriman[2].image.IsDraw = FALSE;
						Enemy_Ahriman[2].image.width = 0;
						Enemy_Ahriman[2].image.height = 0;
						Enemy_Ahriman[2].image.x = 1000;
					}
				}
			}


		}

	}



	//�q�g�c���ƒe�̓����蔻��
	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		for (int kazu = 0; kazu < Enemy_Num; kazu++)
		{
			//�Ԓe
			if (((player.tama[cnt].x > enemy[kazu].image.x && player.tama[cnt].x < enemy[kazu].image.x + enemy[kazu].image.width) ||
				(enemy[kazu].image.x > player.tama[cnt].x && enemy[kazu].image.x < player.tama[cnt].x + player.tama[cnt].width)) &&
				((player.tama[cnt].y > enemy[kazu].image.y && player.tama[cnt].y < enemy[kazu].image.y + enemy[kazu].image.height) ||
					(enemy[kazu].image.y > player.tama[cnt].y && enemy[kazu].image.y < player.tama[cnt].y + player.tama[cnt].height)))
			{

				if (kazu == 0)
				{
					player.tama[cnt].IsDraw = FALSE;
					player.tama[cnt].x = 0;
					player.tama[cnt].y = 1000;

					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

					enemy[0].image.width = 0;
					enemy[0].image.height = 0;
					enemy[0].image.x = 0;
					enemy[0].image.y = 1000;

				}

				if (kazu == 4)
				{
					player.tama[cnt].IsDraw = FALSE;
					player.tama[cnt].x = 0;
					player.tama[cnt].y = 1000;

					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

					enemy[4].image.width = 0;
					enemy[4].image.height = 0;
					enemy[4].image.x = 0;
					enemy[4].image.y = 1000;

				}
				else
				{
					player.tama[cnt].x = 0;
					player.tama[cnt].y = 1000;
				}
			}

			//�Βe
			if (((player.tama2[cnt].x > enemy[kazu].image.x && player.tama2[cnt].x < enemy[kazu].image.x + enemy[kazu].image.width) ||
				(enemy[kazu].image.x > player.tama2[cnt].x && enemy[kazu].image.x < player.tama2[cnt].x + player.tama2[cnt].width)) &&
				((player.tama2[cnt].y > enemy[kazu].image.y && player.tama2[cnt].y < enemy[kazu].image.y + enemy[kazu].image.height) ||
					(enemy[kazu].image.y > player.tama2[cnt].y && enemy[kazu].image.y < player.tama2[cnt].y + player.tama2[cnt].height)))
			{

				if (kazu == 1)
				{
					player.tama2[cnt].IsDraw = FALSE;
					player.tama2[cnt].x = 0;
					player.tama2[cnt].y = 1000;

					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

					enemy[1].image.width = 0;
					enemy[1].image.height = 0;
					enemy[1].image.x = 0;
					enemy[1].image.y = 1000;

				}
				if (kazu == 6)
				{
					player.tama2[cnt].IsDraw = FALSE;
					player.tama2[cnt].x = 0;
					player.tama2[cnt].y = 1000;

					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

					enemy[6].image.width = 0;
					enemy[6].image.height = 0;
					enemy[6].image.x = 0;
					enemy[6].image.y = 1000;

				}
				else
				{
					player.tama2[cnt].x = 0;
					player.tama2[cnt].y = 1000;
				}

			}


			//�e
			if (((player.b_tama[cnt].x > enemy[kazu].image.x && player.b_tama[cnt].x < enemy[kazu].image.x + enemy[kazu].image.width) ||
				(enemy[kazu].image.x > player.b_tama[cnt].x && enemy[kazu].image.x < player.b_tama[cnt].x + player.b_tama[cnt].width)) &&
				((player.b_tama[cnt].y > enemy[kazu].image.y && player.b_tama[cnt].y < enemy[kazu].image.y + enemy[kazu].image.height) ||
					(enemy[kazu].image.y > player.b_tama[cnt].y && enemy[kazu].image.y < player.b_tama[cnt].y + player.b_tama[cnt].height)))
			{
				if (kazu == 2)
				{
					player.b_tama[cnt].IsDraw = FALSE;
					player.b_tama[cnt].x = 0;
					player.b_tama[cnt].y = 1000;

					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

					enemy[2].image.width = 0;
					enemy[2].image.height = 0;
					enemy[2].image.x = 0;
					enemy[2].image.y = 1000;
				}
				if (kazu == 5)
				{
					player.b_tama[cnt].IsDraw = FALSE;
					player.b_tama[cnt].x = 0;
					player.b_tama[cnt].y = 1000;

					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

					enemy[5].image.width = 0;
					enemy[5].image.height = 0;
					enemy[5].image.x = 0;
					enemy[5].image.y = 1000;
				}
				else
				{
					player.b_tama[cnt].x = 0;
					player.b_tama[cnt].y = 1000;
				}
			}



			//���e
			if (((player.y_tama[cnt].x > enemy[kazu].image.x && player.y_tama[cnt].x < enemy[kazu].image.x + enemy[kazu].image.width) ||
				(enemy[kazu].image.x > player.y_tama[cnt].x && enemy[kazu].image.x < player.y_tama[cnt].x + player.y_tama[cnt].width)) &&
				((player.y_tama[cnt].y > enemy[kazu].image.y && player.y_tama[cnt].y < enemy[kazu].image.y + enemy[kazu].image.height) ||
					(enemy[kazu].image.y > player.y_tama[cnt].y && enemy[kazu].image.y < player.y_tama[cnt].y + player.y_tama[cnt].height)))
			{
				if (kazu == 0 || kazu == 1 || kazu == 2 || kazu == 4 || kazu == 5 || kazu == 6)
				{
					player.y_tama[cnt].IsDraw = FALSE;
					player.y_tama[cnt].x = 0;
					player.y_tama[cnt].y = 1000;
				}
				if (kazu == 3)
				{
					player.y_tama[cnt].IsDraw = FALSE;
					player.y_tama[cnt].x = 0;
					player.y_tama[cnt].y = 1000;

					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

					enemy[3].image.width = 0;
					enemy[3].image.height = 0;
					enemy[3].image.x = 0;
					enemy[3].image.y = 1000;

				}
				if (kazu == 7)
				{
					player.y_tama[cnt].IsDraw = FALSE;
					player.y_tama[cnt].x = 0;
					player.y_tama[cnt].y = 1000;

					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

					enemy[7].image.width = 0;
					enemy[7].image.height = 0;
					enemy[7].image.x = 0;
					enemy[7].image.y = 1000;
				}


			}

		}
	}




	//�q�m�^�}�ƒe�̓����蔻��
	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		for (int kazu = 0; kazu < Enemy_Num; kazu++)
		{
			//�Ԓe
			if (((player.tama[cnt].x > Enemy_Bomb[kazu].image.x && player.tama[cnt].x < Enemy_Bomb[kazu].image.x + Enemy_Bomb[kazu].image.width) ||
				(Enemy_Bomb[kazu].image.x > player.tama[cnt].x && Enemy_Bomb[kazu].image.x < player.tama[cnt].x + player.tama[cnt].width)) &&
				((player.tama[cnt].y > Enemy_Bomb[kazu].image.y && player.tama[cnt].y < Enemy_Bomb[kazu].image.y + Enemy_Bomb[kazu].image.height) ||
					(Enemy_Bomb[kazu].image.y > player.tama[cnt].y && Enemy_Bomb[kazu].image.y < player.tama[cnt].y + player.tama[cnt].height)))
			{

				if (kazu == 1)
				{

					player.tama[cnt].IsDraw = FALSE;
					player.tama[cnt].x = 0;
					player.tama[cnt].y = 1000;

					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

					Enemy_Bomb[1].image.width = 0;
					Enemy_Bomb[1].image.height = 0;
					Enemy_Bomb[1].image.x = 1000;
				}
				else
				{
					player.tama[cnt].x = 0;
					player.tama[cnt].y = 1000;
				}
			}

			//�Βe
			if (((player.tama2[cnt].x > Enemy_Bomb[kazu].image.x && player.tama2[cnt].x < Enemy_Bomb[kazu].image.x + Enemy_Bomb[kazu].image.width) ||
				(Enemy_Bomb[kazu].image.x > player.tama2[cnt].x && Enemy_Bomb[kazu].image.x < player.tama2[cnt].x + player.tama2[cnt].width)) &&
				((player.tama2[cnt].y > Enemy_Bomb[kazu].image.y && player.tama2[cnt].y < Enemy_Bomb[kazu].image.y + Enemy_Bomb[kazu].image.height) ||
					(Enemy_Bomb[kazu].image.y > player.tama2[cnt].y && Enemy_Bomb[kazu].image.y < player.tama2[cnt].y + player.tama2[cnt].height)))
			{
				if (kazu == 0)
				{

					player.tama2[cnt].IsDraw = FALSE;
					player.tama2[cnt].x = 0;
					player.tama2[cnt].y = 1000;

					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

					Enemy_Bomb[0].image.width = 0;
					Enemy_Bomb[0].image.height = 0;
					Enemy_Bomb[0].image.x = 1000;
				}

				if (kazu == 4)
				{

					player.tama2[cnt].IsDraw = FALSE;
					player.tama2[cnt].x = 0;
					player.tama2[cnt].y = 1000;

					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

					Enemy_Bomb[4].image.width = 0;
					Enemy_Bomb[4].image.height = 0;
					Enemy_Bomb[4].image.x = 1000;
				}
				else
				{
					player.tama2[cnt].x = 0;
					player.tama2[cnt].y = 1000;
				}
			}

			//�e
			if (((player.b_tama[cnt].x > Enemy_Bomb[kazu].image.x && player.b_tama[cnt].x < Enemy_Bomb[kazu].image.x + Enemy_Bomb[kazu].image.width) ||
				(Enemy_Bomb[kazu].image.x > player.b_tama[cnt].x && Enemy_Bomb[kazu].image.x < player.b_tama[cnt].x + player.b_tama[cnt].width)) &&
				((player.b_tama[cnt].y > Enemy_Bomb[kazu].image.y && player.b_tama[cnt].y < Enemy_Bomb[kazu].image.y + Enemy_Bomb[kazu].image.height) ||
					(Enemy_Bomb[kazu].image.y > player.b_tama[cnt].y && Enemy_Bomb[kazu].image.y < player.b_tama[cnt].y + player.b_tama[cnt].height)))
			{
				if (kazu == 3)
				{

					player.b_tama[cnt].IsDraw = FALSE;
					player.b_tama[cnt].x = 0;
					player.b_tama[cnt].y = 1000;

					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

					Enemy_Bomb[3].image.width = 0;
					Enemy_Bomb[3].image.height = 0;
					Enemy_Bomb[3].image.x = 1000;
				}
				else
				{
					player.b_tama[cnt].x = 0;
					player.b_tama[cnt].y = 1000;
				}
			}

			//���e
			if (((player.y_tama[cnt].x > Enemy_Bomb[kazu].image.x && player.y_tama[cnt].x < Enemy_Bomb[kazu].image.x + Enemy_Bomb[kazu].image.width) ||
				(Enemy_Bomb[kazu].image.x > player.y_tama[cnt].x && Enemy_Bomb[kazu].image.x < player.y_tama[cnt].x + player.y_tama[cnt].width)) &&
				((player.y_tama[cnt].y > Enemy_Bomb[kazu].image.y && player.y_tama[cnt].y < Enemy_Bomb[kazu].image.y + Enemy_Bomb[kazu].image.height) ||
					(Enemy_Bomb[kazu].image.y > player.y_tama[cnt].y && Enemy_Bomb[kazu].image.y < player.y_tama[cnt].y + player.y_tama[cnt].height)))
			{
				if (kazu == 2)
				{

					player.y_tama[cnt].IsDraw = FALSE;
					player.y_tama[cnt].x = 0;
					player.y_tama[cnt].y = 1000;

					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

					Enemy_Bomb[2].image.width = 0;
					Enemy_Bomb[2].image.height = 0;
					Enemy_Bomb[2].image.x = 1000;
				}

				if (kazu == 5)
				{

					player.y_tama[cnt].IsDraw = FALSE;
					player.y_tama[cnt].x = 0;
					player.y_tama[cnt].y = 1000;

					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

					Enemy_Bomb[5].image.width = 0;
					Enemy_Bomb[5].image.height = 0;
					Enemy_Bomb[5].image.x = 1000;
				}
				else
				{
					player.y_tama[cnt].x = 0;
					player.y_tama[cnt].y = 1000;
				}
			}
		}
	}



	if (player.CanShot == FALSE)
	{

		if (player.ShotReLoadCnt == player.ShotReLoadCntMAX)
		{
			player.ShotReLoadCnt = 0;
			player.CanShot = TRUE;
		}

		player.ShotReLoadCnt++;
	}





	//�X�e�[�W�\��

	if (FirstStIn == TRUE)
	{
		St1count++;
	}

	hukidasi2.x = 150;
	hukidasi2.y = 500;

	yajirusi.x = 10;
	yajirusi.y = 180 - 10*sin(yajirusi.radian);
	yajirusi.radian += 0.1;


	//�e�L�X�g�\��

	//1���
	if (St1count == 50)
	{
		FirstStIn = FALSE;
		hukidasi2.IsDraw = TRUE;
		MojiDraw = TRUE;

		if (windowcount < 80)
		{
			windowcount++;
		}

		if (windowcount == 80)
		{
			EnterDraw = TRUE;
		}

		if (EnterDraw == TRUE)
		{
			if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
			{
				PlaySoundMem(ENTER.handle, DX_PLAYTYPE_BACK);
				St1count += 1;
				windowcount = 0;
				EnterDraw = FALSE;
			}
		}

	}
	//�Q���
	if (St1count == 51)
	{
		MojiDraw = FALSE;
		setumei2 = TRUE;
		yajirusi.IsDraw = TRUE;
		if (windowcount < 80)
		{
			windowcount++;
		}
		if (windowcount == 80)
		{
			EnterDraw = TRUE;
		}
		if (EnterDraw == TRUE)
		{
			if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
			{
				PlaySoundMem(ENTER.handle, DX_PLAYTYPE_BACK);
				St1count += 1;
				windowcount = 0;
				EnterDraw = FALSE;
			}
		}
	}
	//3���
	if (St1count == 52)
	{
		setumei2 = FALSE;
		yajirusi.x = 650;
		yajirusi.y = 150 - 10 * sin(yajirusi.radian);
		setumei3 = TRUE;
		if (windowcount < 80)
		{
			windowcount++;
		}
		if (windowcount == 80)
		{
			EnterDraw = TRUE;
		}
		if (EnterDraw == TRUE)
		{
			if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
			{
				PlaySoundMem(ENTER.handle, DX_PLAYTYPE_BACK);
				FirstStIn = TRUE;
				setumei3 = FALSE;
				hukidasi2.IsDraw = FALSE;
				EnterDraw = FALSE;
				yajirusi.IsDraw = FALSE;
			}
		}
	}


	//�G�P�̏o��
	if (St1count > 300)
	{
		enemy[0].image.IsDraw = TRUE;
		if (St1count < 1500)
		{
			enemy[0].image.x++;
		}
	}

	//�G�Q�̏o��
	if (St1count > 600)
	{
		enemy[1].image.IsDraw = TRUE;
		enemy[1].image.x++;
	}

	//�G�R�ƓG�S�̏o��
	if (St1count > 900)
	{
		enemy[2].image.x++;
		enemy[3].image.x++;
	}

	//�G�T�A�G�U�A�G�V�̏o��
	if (St1count > 1300)
	{
		enemy[4].image.x++;
		enemy[5].image.x++;
		enemy[6].image.x++;
	}


	//�q�m�^�}
	Enemy_Bomb[0].image.y = 300 + 100 * sin(Enemy_Bomb[0].image.radian);
	Enemy_Bomb[0].image.radian += 0.02;
	if (St1count > 1700)
	{
		Enemy_Bomb[0].image.IsDraw = TRUE;

		if (Enemy_Bomb[0].image.x < 1200)
		{
			Enemy_Bomb[0].image.x++;
		}
	}

	Enemy_Bomb[1].image.y = 200 + 100 * sin(Enemy_Bomb[1].image.radian);
	Enemy_Bomb[1].image.radian += 0.02;
	if (St1count > 2100)
	{
		if (Enemy_Bomb[1].image.x < 1200)
		{
			Enemy_Bomb[1].image.x++;
		}
	}

	Enemy_Bomb[2].image.y = 400 - 100 * sin(Enemy_Bomb[2].image.radian);
	Enemy_Bomb[2].image.radian += 0.02;
	if (St1count > 2100)
	{
		if (Enemy_Bomb[2].image.x < 1200)
		{
			Enemy_Bomb[2].image.x++;
		}
	}

	Enemy_Bomb[3].image.y = 300 + 300 * sin(Enemy_Bomb[3].image.radian);
	Enemy_Bomb[3].image.radian += 0.02;
	if (St1count > 2400)
	{
		if (Enemy_Bomb[3].image.x < 1200)
		{
			Enemy_Bomb[3].image.x++;
		}
	}

	Enemy_Bomb[4].image.y = 450 - 300 * sin(Enemy_Bomb[4].image.radian);
	Enemy_Bomb[4].image.radian += 0.02;
	if (St1count > 2400)
	{
		if (Enemy_Bomb[4].image.x < 1200)
		{
			Enemy_Bomb[4].image.x++;
		}
	}

	Enemy_Bomb[5].image.y = 300 + 300 * sin(Enemy_Bomb[5].image.radian);
	Enemy_Bomb[5].image.radian += 0.02;
	if (St1count > 2400)
	{
		if (Enemy_Bomb[5].image.x < 1200)
		{
			Enemy_Bomb[5].image.x++;
		}
	}


	//�F�ς��

	Enemy_Ahriman[0].image.y = 200 + 70 * sin(Enemy_Ahriman[0].image.radian);
	Enemy_Ahriman[0].image.radian += 0.02;
	if (St1count > 3100)
	{
		if (Enemy_Ahriman[0].image.x < 1200)
		{
			Enemy_Ahriman[0].image.x++;
		}
	}


	Enemy_Ahriman[1].image.y = 200 + 70 * sin(Enemy_Ahriman[1].image.radian);
	Enemy_Ahriman[1].image.radian += 0.02;
	if (St1count > 3600)
	{
		if (Enemy_Ahriman[1].image.x < 1200)
		{
			Enemy_Ahriman[1].image.x++;
		}
	}


	Enemy_Ahriman[2].image.y = 150 + 70 * sin(Enemy_Ahriman[2].image.radian);
	Enemy_Ahriman[2].image.radian += 0.02;
	if (St1count > 4100)
	{
		if (Enemy_Ahriman[2].image.x < 1200)
		{
			Enemy_Ahriman[2].image.x++;
		}
	}


	Enemy_Ahriman[3].image.y = 300 - 70 * sin(Enemy_Ahriman[3].image.radian);
	Enemy_Ahriman[3].image.radian += 0.02;
	if (St1count > 4100)
	{
		if (Enemy_Ahriman[3].image.x < 1200)
		{
			Enemy_Ahriman[3].image.x++;
		}
	}



	if (St1count > 4900)
	{
		if (St1count < 5150)
		{
			gate[0].x++;
		}
	}

	hukidasi[2].x = gate[0].x+20;
	hukidasi[2].y = gate[0].y-20;

	return;

}


VOID MY_PLAY0_DRAW(VOID)
{
	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		if (ImageBack[num].IsDraw == TRUE)
		{
			DrawGraph(ImageBack[num].image.x, ImageBack[num].image.y, ImageBack[num].image.handle, TRUE);
		}
	}

	//�e�X�g�p
	/*DrawFormatString(600, 0, GetColor(255, 255, 255), "count:%d", St1count);
	DrawFormatString(600, 20, GetColor(255, 255, 255), "count:%d", windowcount);*/
	/*DrawFormatString(300, 40, GetColor(255, 255, 255), "portion:%d", portioncount);*/


	if (hukidasi2.IsDraw == TRUE)
	{
		DrawGraph(hukidasi2.x, hukidasi2.y, hukidasi2.handle, TRUE);
	}

	SetFontSize(20);


	if (EnterDraw == TRUE)
	{
		DrawString(700, 580, "ENTER", GetColor(255, 255, 255));
	}

	if (MojiDraw == TRUE)
	{
		DrawString(230, 520, "�G�Ɠ����F�̒e�𓖂Ă邱�ƂŁA�G��|�����Ƃ�\n�ł��邼�I", GetColor(255, 255, 255));
	}

	if (setumei2 == TRUE)
	{
		DrawString(230, 520, "�e�̔��˕��@�͂������m�F", GetColor(255, 255, 255));
	}

	if (setumei3 == TRUE)
	{
		DrawString(230, 520, "�n�[�g���S�Ė����Ȃ�����Q�[���I�[�o�[��", GetColor(255, 255, 255));
	}

	if (yajirusi.IsDraw == TRUE)
	{
		DrawGraph(yajirusi.x, yajirusi.y, yajirusi.handle, TRUE);
	}


	DrawGraph(tamasousa_gazou.x, tamasousa_gazou.y, tamasousa_gazou.handle, TRUE);


	//�Q�[�g
	int a;

	a = St1count % 40 / 5;

	if (a == 10)
	{
		a = 0;
	}


	DrawGraph(gate[0].x, gate[0].y, gatehandle[a], TRUE);


	for (int i = 0; i < HUKIDASI_NUM; i++)
	{
		if (hukidasi[i].IsDraw == TRUE)
		{
			DrawGraph(hukidasi[i].x, hukidasi[i].y, hukidasi[i].handle, TRUE);
		}
	}

	//�v���C���[�`��
	if (MY_KEY_DOWN(KEY_INPUT_LEFT) == TRUE)
	{
		muki = 4;
		leftcount++;
		rightcount = 0;
		stopflag = FALSE;
	}
	else if (MY_KEY_DOWN(KEY_INPUT_RIGHT) == TRUE)
	{
		muki = 1;
		rightcount++;
		leftcount = 0;
		stopflag = FALSE;
	}
	else
	{
		stopflag = TRUE;
	}


	if (leftcount > 0)
	{
		if (stopflag == TRUE)
		{
			muki = 3;
		}
		if (MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
		{
			muki = 5;
		}
		if (MY_KEY_DOWN(KEY_INPUT_S) == TRUE)
		{
			muki = 5;
		}
		if (MY_KEY_DOWN(KEY_INPUT_D) == TRUE)
		{
			muki = 5;
		}
		if (MY_KEY_DOWN(KEY_INPUT_F) == TRUE)
		{
			muki = 5;
		}
	}

	if (rightcount > 0)
	{
		if (stopflag == TRUE)
		{
			muki = 0;
		}
		if (MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
		{
			muki = 5;
		}
		if (MY_KEY_DOWN(KEY_INPUT_S) == TRUE)
		{
			muki = 5;
		}
		if (MY_KEY_DOWN(KEY_INPUT_D) == TRUE)
		{
			muki = 5;
		}
		if (MY_KEY_DOWN(KEY_INPUT_F) == TRUE)
		{
			muki = 5;
		}
	}


	/*DrawFormatString(400, 0, GetColor(255, 255, 255), "leftcount:%d", leftcount);*/


	if (player.IsDraw == TRUE)
	{
		DrawGraph(player.image.x, player.image.y, player.image.m_handle[muki], TRUE);
	}


	//�F�ω������X�^�[

	int color = 0;
	int color2 = 0;
	int color3 = 0;
	int color4 = 0;

	for (int kazu = 0; kazu < Enemy_Num; kazu++)
	{

		if (Enemy_Ahriman[kazu].image.IsDraw == TRUE)
		{
			DrawGraph(Enemy_Ahriman[0].image.x, Enemy_Ahriman[0].image.y, Enemy_Ahriman[0].enecolor[color], TRUE);
			if (Enemy_Ahriman[0].hp == 100)
			{

				color = 0;

			}
			if (Enemy_Ahriman[0].hp == 50)
			{
				color = 1;
			}

			DrawGraph(Enemy_Ahriman[1].image.x, Enemy_Ahriman[1].image.y, Enemy_Ahriman[1].enecolor[color2], TRUE);
			if (Enemy_Ahriman[1].hp == 100)
			{
				color2 = 3;
			}
			if (Enemy_Ahriman[1].hp == 50)
			{
				color2 = 2;
			}

			DrawGraph(Enemy_Ahriman[2].image.x, Enemy_Ahriman[2].image.y, Enemy_Ahriman[2].enecolor[color3], TRUE);
			if (Enemy_Ahriman[2].hp == 100)
			{

				color3 = 1;

			}
			if (Enemy_Ahriman[2].hp == 50)
			{
				color3 = 3;
			}

			DrawGraph(Enemy_Ahriman[3].image.x, Enemy_Ahriman[3].image.y, Enemy_Ahriman[3].enecolor[color4], TRUE);
			if (Enemy_Ahriman[3].hp == 100)
			{

				color4 = 2;

			}
			if (Enemy_Ahriman[3].hp == 50)
			{
				color4 = 0;
			}


		}

	}




	/*DrawFormatString(600, 0, GetColor(255, 255, 255), "enemyHP:%d", enemyHP);*/


	//��ڏ��m
	for (int kazu = 0; kazu < Enemy_Num; kazu++)
	{

		if (enemy[kazu].image.IsDraw == TRUE)
		{
			DrawGraph(enemy[0].image.x, enemy[0].image.y, enemy[0].enecolor[0], TRUE);
			DrawGraph(enemy[1].image.x, enemy[1].image.y, enemy[1].enecolor[1], TRUE);
			DrawGraph(enemy[2].image.x, enemy[2].image.y, enemy[2].enecolor[2], TRUE);
			DrawGraph(enemy[3].image.x, enemy[3].image.y, enemy[3].enecolor[3], TRUE);
			DrawGraph(enemy[4].image.x, enemy[4].image.y, enemy[4].enecolor[0], TRUE);
			DrawGraph(enemy[5].image.x, enemy[5].image.y, enemy[5].enecolor[2], TRUE);
			DrawGraph(enemy[6].image.x, enemy[6].image.y, enemy[6].enecolor[1], TRUE);
			DrawGraph(enemy[7].image.x, enemy[7].image.y, enemy[7].enecolor[3], TRUE);

		}
	}


	//�q�m�^�}
	for (int kazu = 0; kazu < Enemy_Num; kazu++)
	{

		if (Enemy_Bomb[kazu].image.IsDraw == TRUE)
		{

			DrawGraph(Enemy_Bomb[0].image.x, Enemy_Bomb[0].image.y, Enemy_Bomb[0].enecolor[2], TRUE);
			DrawGraph(Enemy_Bomb[1].image.x, Enemy_Bomb[1].image.y, Enemy_Bomb[1].enecolor[0], TRUE);
			DrawGraph(Enemy_Bomb[2].image.x, Enemy_Bomb[2].image.y, Enemy_Bomb[2].enecolor[3], TRUE);
			DrawGraph(Enemy_Bomb[3].image.x, Enemy_Bomb[3].image.y, Enemy_Bomb[3].enecolor[1], TRUE);
			DrawGraph(Enemy_Bomb[4].image.x, Enemy_Bomb[4].image.y, Enemy_Bomb[4].enecolor[2], TRUE);
			DrawGraph(Enemy_Bomb[5].image.x, Enemy_Bomb[5].image.y, Enemy_Bomb[5].enecolor[3], TRUE);
		}
	}


	

	if (heartnow > 0)
	{
		DrawGraph(heart[0].x, heart[0].y, heart[0].handle, TRUE);

		if (heartnow > 1)
		{
			DrawGraph(heart[1].x, heart[1].y, heart[1].handle, TRUE);

			if (heartnow > 2)
			{
				DrawGraph(heart[2].x, heart[2].y, heart[2].handle, TRUE);
			}
		}

	}

	/*DrawFormatString(600, 0, GetColor(255, 255, 255), "heartnow:%d", heartnow);*/


	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		if (player.tama[cnt].IsDraw == TRUE)
		{
			DrawGraph(
				player.tama[cnt].x,
				player.tama[cnt].y,
				player.tama[cnt].handle[player.tama[cnt].nowImageKind],
				TRUE);

			if (player.tama[cnt].changeImageCnt < player.tama[cnt].changeImageCntMAX)
			{
				player.tama[cnt].changeImageCnt++;
			}
			else
			{
				if (player.tama[cnt].nowImageKind < TAMA_DIV_NUM - 1)
				{
					player.tama[cnt].nowImageKind++;
				}
				else
				{
					player.tama[cnt].nowImageKind = 0;
				}

				player.tama[cnt].changeImageCnt = 0;
			}

			if (player.tama[cnt].x < player.CenterX - TAMA_HIKYORI_LONG || player.tama[cnt].x < 0)
			{
				player.tama[cnt].IsDraw = FALSE;
				player.tama[cnt].y = 1000;
			}
			else
			{
				player.tama[cnt].x -= player.tama[cnt].speed;

			}

		}
	}


	/*for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		DrawBox(player.tama[cnt].x, player.tama[cnt].y, player.tama[cnt].x + 16, player.tama[cnt].y + 16, GetColor(255, 255, 255), FALSE);
	}*/




	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		if (player.tama2[cnt].IsDraw == TRUE)
		{
			DrawGraph(
				player.tama2[cnt].x,
				player.tama2[cnt].y,
				player.tama2[cnt].handle[player.tama2[cnt].nowImageKind],
				TRUE);

			if (player.tama2[cnt].changeImageCnt < player.tama2[cnt].changeImageCntMAX)
			{
				player.tama2[cnt].changeImageCnt++;
			}
			else
			{
				if (player.tama2[cnt].nowImageKind < TAMA_DIV_NUM - 1)
				{
					player.tama2[cnt].nowImageKind++;
				}
				else
				{
					player.tama2[cnt].nowImageKind = 0;
				}

				player.tama2[cnt].changeImageCnt = 0;
			}

			if (player.tama2[cnt].x < player.CenterX - TAMA_HIKYORI_LONG || player.tama2[cnt].x < 0)
			{
				player.tama2[cnt].IsDraw = FALSE;
				player.tama2[cnt].y = 1000;
			}
			else
			{
				player.tama2[cnt].x -= player.tama[cnt].speed;

			}
		}
	}




	/*for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		DrawBox(player.tama2[cnt].x, player.tama2[cnt].y, player.tama2[cnt].x + 16, player.tama2[cnt].y + 16, GetColor(255, 255, 255), FALSE);
	}*/




	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		if (player.b_tama[cnt].IsDraw == TRUE)
		{
			DrawGraph(
				player.b_tama[cnt].x,
				player.b_tama[cnt].y,
				player.b_tama[cnt].handle[player.b_tama[cnt].nowImageKind],
				TRUE);

			if (player.b_tama[cnt].changeImageCnt < player.b_tama[cnt].changeImageCntMAX)
			{
				player.b_tama[cnt].changeImageCnt++;
			}
			else
			{
				if (player.b_tama[cnt].nowImageKind < TAMA_DIV_NUM - 1)
				{
					player.b_tama[cnt].nowImageKind++;
				}
				else
				{
					player.b_tama[cnt].nowImageKind = 0;
				}

				player.b_tama[cnt].changeImageCnt = 0;
			}

			if (player.b_tama[cnt].x < player.CenterX - TAMA_HIKYORI_LONG || player.b_tama[cnt].x < 0)
			{
				player.b_tama[cnt].IsDraw = FALSE;
				player.b_tama[cnt].y = 1000;
			}
			else
			{
				player.b_tama[cnt].x -= player.tama[cnt].speed;

			}
		}
	}


	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		if (player.y_tama[cnt].IsDraw == TRUE)
		{
			DrawGraph(
				player.y_tama[cnt].x,
				player.y_tama[cnt].y,
				player.y_tama[cnt].handle[player.y_tama[cnt].nowImageKind],
				TRUE);

			if (player.y_tama[cnt].changeImageCnt < player.y_tama[cnt].changeImageCntMAX)
			{
				player.y_tama[cnt].changeImageCnt++;
			}
			else
			{
				if (player.y_tama[cnt].nowImageKind < TAMA_DIV_NUM - 1)
				{
					player.y_tama[cnt].nowImageKind++;
				}
				else
				{
					player.y_tama[cnt].nowImageKind = 0;
				}

				player.y_tama[cnt].changeImageCnt = 0;
			}

			if (player.y_tama[cnt].x < player.CenterX - TAMA_HIKYORI_LONG || player.y_tama[cnt].x < 0)
			{
				player.y_tama[cnt].IsDraw = FALSE;
				player.y_tama[cnt].y = 1000;
			}
			else
			{
				player.y_tama[cnt].x -= player.tama[cnt].speed;

			}
		}
	}



	return;
}



//���ԃ|�C���g
VOID MY_PLAY(VOID)
{
	MY_PLAY_PROC();
	MY_PLAY_DRAW();

	return;
}


VOID MY_PLAY_PROC(VOID)
{


	if (CheckSoundMem(BGM.handle) == 0)
	{
		PlaySoundMem(BGM.handle, DX_PLAYTYPE_LOOP);
	}


	if (mouse.Button[MOUSE_INPUT_RIGHT] == TRUE)
	{

		PlaySoundMem(menu.handle, DX_PLAYTYPE_BACK);

		iPOINT R_ClickPt = mouse.Point;

		SetMouseDispFlag(TRUE);

		int Ret = MessageBox(GetMainWindowHandle(), MOUSE_R_CLICK_CAPTION, MOUSE_R_CLICK_TITLE, MB_YESNO);

		if (Ret == IDYES)
		{
			PlaySoundMem(menuyes.handle, DX_PLAYTYPE_BACK);

			if (CheckSoundMem(BGM.handle) != 0)
			{
				StopSoundMem(BGM.handle);
			}

			SetMouseDispFlag(TRUE);

			GameScene = GAME_SCENE_START;
			return;
		}

		else if (Ret == IDNO)
		{
			PlaySoundMem(menuno.handle, DX_PLAYTYPE_BACK);

			SetMousePoint(R_ClickPt.x, R_ClickPt.y);

			SetMouseDispFlag(FALSE);
		}
	}


	//�v���C���[�̑��x&�L�[����ݒ�

	if (Sousa == TRUE)
	{
		/*player.speed = 4;*/
		if (MY_KEY_DOWN(KEY_INPUT_UP) == TRUE)
		{
			player.CenterY -= player.speed;
		}
		if (MY_KEY_DOWN(KEY_INPUT_DOWN) == TRUE)
		{
			player.CenterY += player.speed;
		}
		if (MY_KEY_DOWN(KEY_INPUT_LEFT) == TRUE)
		{
			player.CenterX -= player.speed;
		}
		if (MY_KEY_DOWN(KEY_INPUT_RIGHT) == TRUE)
		{
			player.CenterX += player.speed;
		}
	}



	//�}�b�v�ƃv���C���[�̓����蔻��ݒ�
	player.coll.left = player.CenterX - mapChip.width / 2 + 5;
	player.coll.top = player.CenterY - mapChip.height / 2 + 5;
	player.coll.right = player.CenterX + mapChip.width / 2 - 5;
	player.coll.bottom = player.CenterY + mapChip.height / 2 - 5;


	BOOL IsMove = TRUE;

	if (MY_CHECK_MAP1_PLAYER_COLL(player.coll) == TRUE)
	{

		player.CenterX = player.collBeforePt.x;
		player.CenterY = player.collBeforePt.y;

		SetMousePoint(player.collBeforePt.x, player.collBeforePt.y);
		IsMove = FALSE;
	}

	if (IsMove == TRUE)
	{
		player.image.x = player.CenterX - player.image.width / 2;
		player.image.y = player.CenterY - player.image.height / 2;

		player.collBeforePt.x = player.CenterX;
		player.collBeforePt.y = player.CenterY;
	}


	//�����蔻��͈̔͐ݒ�
	RECT PlayerRect;
	int CollRange = 2;
	PlayerRect.left = player.image.x + player.image.width / 2 - CollRange;
	PlayerRect.top = player.image.y + player.image.height / 2 - CollRange;
	PlayerRect.right = player.image.x + player.image.width / 2 + CollRange;
	PlayerRect.bottom = player.image.y + player.image.height / 2 + CollRange;


	RECT WarpRect;
	WarpRect.left = warp.x;
	WarpRect.top = warp.y;
	WarpRect.right = warp.x + 120;
	WarpRect.bottom = warp.y + 120;

	RECT YwarpRect;
	YwarpRect.left = y_warp.x;
	YwarpRect.top = y_warp.y;
	YwarpRect.right = y_warp.x + 192;
	YwarpRect.bottom = y_warp.y + 192;

	RECT HEARTRect;
	HEARTRect.left = kaihuku.x;
	HEARTRect.top = kaihuku.y;
	HEARTRect.right = kaihuku.x + kaihuku.width;
	HEARTRect.bottom = kaihuku.y + kaihuku.height;


	//�񕜂ƃv���C���[�̐ڐG
	if (MY_CHECK_RECT_COLL(PlayerRect, HEARTRect) == TRUE)
	{
		kaihuku.IsDraw = FALSE;
		kaihuku.width = 0;
		kaihuku.height = 0;

		if (heartnow < 3)
		{
			heartnow += 1;
		}

		PlaySoundMem(kaihuku_oto.handle, DX_PLAYTYPE_BACK);

		kaihukutext = TRUE;
	}


	//�񕜃e�L�X�g�̕\��
	if (kaihukutext == TRUE)
	{
		if (mojihyoujicount < 100)
		{
			mojihyoujicount++;
		}
		else
		{
			kaihukutext = FALSE;
		}
	}


	//�u�[�c�ƃv���C���[�̐ڐG
	/*if (MY_CHECK_RECT_COLL(PlayerRect, HEARTRect) == TRUE)
	{
		bootscount++;
		if (bootscount < 200)
		{
			player.speed = 8;
		}

		kaihuku.IsDraw = FALSE;
		kaihuku.width = 0;
		kaihuku.height = 0;


	}*/


	//�S�[���Q�[�g�Ƃ̐ڐG����
	if (MY_CHECK_RECT_COLL(PlayerRect, WarpRect) == TRUE)
	{
		//SPACE�A�C�R����\��
		hukidasi[0].IsDraw = TRUE;

		//�S�[���Q�[�g�𒲂ׂ�
		if (MY_KEY_DOWN(KEY_INPUT_SPACE) == TRUE)
		{
			//�N���X�^����j�󂵂Ă��Ȃ��ꍇ�A�e�L�X�g��\������
			if (y_crystal_Flag == FALSE)
			{
				hukidasi2.IsDraw = TRUE;
				warptext = TRUE;
				EnterDraw = TRUE;
				Sousa = FALSE;
			}
			//�N���X�^����j�󂵂Ă����ꍇ�A�N���A��ʂ�
			if (y_crystal_Flag == TRUE)
			{

				PlaySoundMem(goal.handle, DX_PLAYTYPE_BACK);

				if (CheckSoundMem(BGM.handle) != 0)
				{
					StopSoundMem(BGM.handle);
				}

				SetMouseDispFlag(TRUE);

				GameEndKind = GAME_END_COMP;

				GameScene = GAME_SCENE_END;

				return;
			}
			
		}
	}
	else {
		hukidasi[0].IsDraw = FALSE;
	}

	if (hukidasi2.IsDraw == TRUE)
	{
		if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
		{
			hukidasi2.IsDraw = FALSE;
			warptext = FALSE;
			EnterDraw = FALSE;
			Sousa = TRUE;
		}
	}





	if (MY_CHECK_RECT_COLL(PlayerRect, YwarpRect) == TRUE)
	{
		hukidasi[1].IsDraw = TRUE;

		//�X�e�[�W�Q�֑J��
		if (MY_KEY_DOWN(KEY_INPUT_SPACE) == TRUE)
		{
			PlaySoundMem(goal.handle, DX_PLAYTYPE_BACK);


			St2count = 0;

			hukidasi[1].IsDraw = FALSE;

			player.CenterX = 700;
			player.CenterY = 300;

			player.image.x = player.CenterX;
			player.image.y = player.CenterY;


			//�e�X�g�p
			y_crystal.x = -120;
			y_crystal.y = 310;

			for (int i = 0; i < GATE_NUM; i++)
			{
				gate[i] = gate[0];

				gate[1].x = -250;
				gate[1].y = 200;
			}


			//�o���[���̔z�u

			for (int kazu = 0; kazu < Enemy_Num; kazu++)
			{
				Enemy_Balor[kazu].image = Enemy_Balor[0].image;

				//�e�X�g�p
				/*Enemy_Balor[0].image.x = -100;
				Enemy_Balor[0].image.y = 300;*/

				//������
				Enemy_Balor[0].image.x = -200;
				Enemy_Balor[0].image.y = 200;

				//������
				Enemy_Balor[1].image.x = -200;
				Enemy_Balor[1].image.y = 400;

				//�ォ��
				Enemy_Balor[2].image.x = 400;
				Enemy_Balor[2].image.y = -200;

				//�ォ��
				Enemy_Balor[3].image.x = 600;
				Enemy_Balor[3].image.y = -200;

				//������
				Enemy_Balor[4].image.x = -200;
				Enemy_Balor[4].image.y = 300;

				//������
				Enemy_Balor[5].image.x = -200;
				Enemy_Balor[5].image.y = 500;

				//����
				Enemy_Balor[6].image.x = -100;
				Enemy_Balor[6].image.y = 0;

				//����
				Enemy_Balor[7].image.x = -100;
				Enemy_Balor[7].image.y = 640;

				//������
				Enemy_Balor[8].image.x = -100;
				Enemy_Balor[8].image.y = 270;

				//������
				Enemy_Balor[9].image.x = 300;
				Enemy_Balor[9].image.y = 740;

				Enemy_Balor[10].image.x = 450;
				Enemy_Balor[10].image.y = -200;

				Enemy_Balor[11].image.x = 150;
				Enemy_Balor[11].image.y = 740;

				Enemy_Balor[12].image.x = -200;
				Enemy_Balor[12].image.y = 520;

				Enemy_Balor[13].image.x = -400;
				Enemy_Balor[13].image.y = 520;

				Enemy_Balor[14].image.x = -200;
				Enemy_Balor[14].image.y = 200;

				Enemy_Balor[15].image.x = -400;
				Enemy_Balor[15].image.y = 200;

				Enemy_Balor[16].image.x = -200;
				Enemy_Balor[16].image.y = 520;

				Enemy_Balor[17].image.x = -400;
				Enemy_Balor[17].image.y = 520;

				Enemy_Balor[18].image.x = -200;
				Enemy_Balor[18].image.y = 20;

				Enemy_Balor[19].image.x = -400;
				Enemy_Balor[19].image.y = 20;

				Enemy_Balor[20].image.x = -600;
				Enemy_Balor[20].image.y = 20;
			}


			for (int i = 0; i < SHOKUSHU_NUM; i++)
			{
				syokusyu[i] = syokusyu[0];

				syokusyu[0].x = 1000;
				syokusyu[0].y = 400;

				syokusyu[1].x = 1000;
				syokusyu[1].y = 100;

				syokusyu[2].x = 1000;
				syokusyu[2].y = 200;

				syokusyu[3].x = 1000;
				syokusyu[3].y = 400;

				syokusyu[4].x = 1000;
				syokusyu[4].y = 100;

				syokusyu[5].x = 1000;
				syokusyu[5].y = 300;

				syokusyu[6].x = 1000;
				syokusyu[6].y = 500;

				syokusyu[7].x = 1000;
				syokusyu[7].y = 200;

				syokusyu[8].x = 1000;
				syokusyu[8].y = 400;

				syokusyu[9].x = 1000;
				syokusyu[9].y = 600;

				syokusyu[10].x = 1000;
				syokusyu[10].y = 0;

				syokusyu[11].x = 1000;
				syokusyu[11].y = 190;

				syokusyu[12].x = 1000;
				syokusyu[12].y = 270;

				syokusyu[13].x = 1000;
				syokusyu[13].y = 350;

				syokusyu[14].x = 1000;
				syokusyu[14].y = 510;

				syokusyu[15].x = 1000;
				syokusyu[15].y = 590;



			}

			for (int i = 0; i < DENGER_YOKO_NUM; i++)
			{
				denger_yoko[i] = denger_yoko[0];

				denger_yoko[0].x = 0;
				denger_yoko[0].y = 400;

				denger_yoko[1].x = 0;
				denger_yoko[1].y = 100;

				denger_yoko[2].x = 0;
				denger_yoko[2].y = 200;

				denger_yoko[3].x = 0;
				denger_yoko[3].y = 400;

				denger_yoko[4].x = 0;
				denger_yoko[4].y = 100;

				denger_yoko[5].x = 0;
				denger_yoko[5].y = 300;

				denger_yoko[6].x = 0;
				denger_yoko[6].y = 500;

				denger_yoko[7].x = 0;
				denger_yoko[7].y = 200;

				denger_yoko[8].x = 0;
				denger_yoko[8].y = 400;

				denger_yoko[9].x = 0;
				denger_yoko[9].y = 600;




			}

			for (int i = 0; i < SHOKUSHU_NUM; i++)
			{
				syokusyu_big[i] = syokusyu_big[0];

				syokusyu_big[0].x = 900;
				syokusyu_big[0].y = 0;

				syokusyu_big[1].x = 900;
				syokusyu_big[1].y = -330;

				syokusyu_big[2].x = 900;
				syokusyu_big[2].y = 330;

				syokusyu_big[3].x = 900;
				syokusyu_big[3].y = -30;

				syokusyu_big[4].x = 900;
				syokusyu_big[4].y = 100;

			}




			for (int i = 0; i < SAFE_YOKO_NUM; i++)
			{
				safe_yoko[i] = safe_yoko[0];


				safe_yoko[0].x = 0;
				safe_yoko[0].y = 80;

				safe_yoko[1].x = 0;
				safe_yoko[1].y = 430;

				safe_yoko[2].x = 0;
				safe_yoko[2].y = 530;

				safe_yoko[3].x = 0;
				safe_yoko[3].y = 200;

				safe_yoko[4].x = 0;
				safe_yoko[4].y = 500;

				safe_yoko[5].x = 0;
				safe_yoko[5].y = 0;

			}



			for (int i = 0; i < DENGER_TATE_NUM; i++)
			{
				denger_tate[i] = denger_tate[0];


				denger_tate[0].x = 0;
				denger_tate[0].y = 0;

			}


			for (int i = 0; i < SAFE_TATE_NUM; i++)
			{
				safe_tate[i] = safe_tate[0];


				safe_tate[0].x = 0;
				safe_tate[0].y = 300;

			}


			GameScene = GAME_SCENE_PLAY2;

			return;
		}

	}
	else {
		hukidasi[1].IsDraw = FALSE;
	}


	//�v���C���[����ʊO�ɏo����
	if (player.image.x > GAME_WIDTH || player.image.y > GAME_HEIGHT
		|| player.image.x + player.image.width < 0 || player.image.y + player.image.height < 0)
	{
		if (CheckSoundMem(BGM.handle) != 0)
		{
			StopSoundMem(BGM.handle);
		}

		SetMouseDispFlag(TRUE);

		GameEndKind = GAME_END_FAIL;

		GameScene = GAME_SCENE_END;

		return;
	}



	warp.x = 420;
	warp.y = 300;

	y_warp.x = 30;
	y_warp.y = 280;


	kaihuku.x = 750;
	kaihuku.y = 500 - 10 * sin(kaihuku.radian);
	kaihuku.radian += 0.04;


	hukidasi2.x = 150;
	hukidasi2.y = 500;


	if (y_crystal_Flag == TRUE)
	{
		warpcount++;
	}


	return;
}

VOID MY_PLAY_DRAW(VOID)
{

	DrawGraph(back1.x, back1.y, back1.handle, TRUE);


	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			DrawGraph(
				map[tate][yoko].x,
				map[tate][yoko].y,
				mapChip.handle[map[tate][yoko].kind],
				TRUE);
		}
	}



	if (kaihuku.IsDraw == TRUE)
	{
		DrawGraph(kaihuku.x, kaihuku.y, kaihuku.handle, TRUE);
	}

	if (kaihukutext == TRUE)
	{
		DrawString(player.CenterX-80, player.CenterY-80, "�n�[�g���ЂƂ񕜂����I", GetColor(245, 145, 153));
	}


	tyuukann_count++;

	int a;
	int b;

	a = tyuukann_count % 40 / 5;
	b = warpcount % 40 / 5;

	if (a == 10)
	{
		a = 0;
	}

	if (b == 10)
	{
		b = 0;
	}

	DrawGraph(warp.x, warp.y, warphandle[b], TRUE);

	DrawGraph(y_warp.x, y_warp.y, y_warphandle[a], TRUE);


	if (MY_KEY_DOWN(KEY_INPUT_LEFT) == TRUE)
	{
		muki = 4;
		leftcount++;
		rightcount = 0;
		stopflag = FALSE;
	}
	else if (MY_KEY_DOWN(KEY_INPUT_RIGHT) == TRUE)
	{
		muki = 1;
		rightcount++;
		leftcount = 0;
		stopflag = FALSE;
	}
	else
	{
		stopflag = TRUE;

	}


	if (leftcount > 0)
	{
		if (stopflag == TRUE)
		{
			muki = 3;
		}
		if (MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
		{
			muki = 5;
		}
	}

	if (rightcount > 0)
	{
		if (stopflag == TRUE)
		{
			muki = 0;
		}
		if (MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
		{
			muki = 2;
		}
	}


	if (player.IsDraw == TRUE)
	{
		DrawGraph(player.image.x, player.image.y, player.image.m_handle[muki], TRUE);
	}



	if (heartnow > 0)
	{
		DrawGraph(heart[0].x, heart[0].y, heart[0].handle, TRUE);

		if (heartnow > 1)
		{
			DrawGraph(heart[1].x, heart[1].y, heart[1].handle, TRUE);

			if (heartnow > 2)
			{
				DrawGraph(heart[2].x, heart[2].y, heart[2].handle, TRUE);
			}
		}

	}

	//�e�X�g�p
	/*DrawFormatString(300, 0, GetColor(255, 255, 255), "count:%d", mojihyoujicount);
	DrawFormatString(600, 0, GetColor(255, 255, 255), "heartnow:%d", heartnow);*/


	for (int i = 0; i < HUKIDASI_NUM; i++)
	{
		if (hukidasi[i].IsDraw == TRUE)
		{
			DrawGraph(hukidasi[i].x, hukidasi[i].y, hukidasi[i].handle, TRUE);
		}
	}


	if (hukidasi2.IsDraw == TRUE)
	{
		DrawGraph(hukidasi2.x, hukidasi2.y, hukidasi2.handle, TRUE);
	}


	if (warptext == TRUE)
	{
		DrawString(230, 520, "�F�����甲���o�����[�v�z�[�����������I\n�������A�쓮������ɂ͉��F�̃N���X�^����j�󂷂�\n�K�v�����肻�����B", GetColor(255, 255, 255));
	}


	if (EnterDraw == TRUE)
	{
		DrawString(700, 580, "ENTER", GetColor(255, 255, 255));
	}


	if (goalgazou.IsDraw == TRUE)
	{
		DrawGraph(goalgazou.x, goalgazou.y, goalgazou.handle, TRUE);

	}


	return;
}


//�C�G���[�X�e�[�W(�G��j

VOID MY_PLAY2(VOID)
{
	MY_PLAY2_PROC();
	MY_PLAY2_DRAW();

	return;
}


VOID MY_PLAY2_PROC(VOID)
{

	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		ImageBack[num].image.x++;

		if (ImageBack[num].IsDraw == FALSE)
		{
			if (ImageBack[num].image.x + ImageBack[num].image.width > 0)
			{
				ImageBack[num].IsDraw = TRUE;
			}
		}

		if (ImageBack[num].image.x > GAME_WIDTH)
		{
			ImageBack[num].image.x = 0 - ImageBack[0].image.width * 3;
			ImageBack[num].IsDraw = FALSE;
		}
	}


	if (CheckSoundMem(BGM.handle) == 0)
	{
		PlaySoundMem(BGM.handle, DX_PLAYTYPE_LOOP);
	}


	if (mouse.Button[MOUSE_INPUT_RIGHT] == TRUE)
	{

		PlaySoundMem(menu.handle, DX_PLAYTYPE_BACK);

		iPOINT R_ClickPt = mouse.Point;

		SetMouseDispFlag(TRUE);

		int Ret = MessageBox(GetMainWindowHandle(), MOUSE_R_CLICK_CAPTION, MOUSE_R_CLICK_TITLE, MB_YESNO);

		if (Ret == IDYES)
		{
			PlaySoundMem(menuyes.handle, DX_PLAYTYPE_BACK);

			if (CheckSoundMem(BGM.handle) != 0)
			{
				StopSoundMem(BGM.handle);
			}

			SetMouseDispFlag(TRUE);

			GameScene = GAME_SCENE_START;
			return;
		}

		else if (Ret == IDNO)
		{
			PlaySoundMem(menuno.handle, DX_PLAYTYPE_BACK);

			SetMousePoint(R_ClickPt.x, R_ClickPt.y);

			SetMouseDispFlag(FALSE);
		}
	}


	//�v���C���[�̑��x&�L�[����ݒ�

	if (Sousa == TRUE)
	{
		player.speed = 4;
		if (MY_KEY_DOWN(KEY_INPUT_UP) == TRUE)
		{
			player.CenterY -= player.speed;
		}
		if (MY_KEY_DOWN(KEY_INPUT_DOWN) == TRUE)
		{
			player.CenterY += player.speed;
		}
		if (MY_KEY_DOWN(KEY_INPUT_LEFT) == TRUE)
		{
			player.CenterX -= player.speed;
		}
		if (MY_KEY_DOWN(KEY_INPUT_RIGHT) == TRUE)
		{
			player.CenterX += player.speed;
		}
	}
	

	BOOL IsMove = TRUE;


	if (IsMove == TRUE)
	{
		player.image.x = player.CenterX - player.image.width / 2;
		player.image.y = player.CenterY - player.image.height / 2;

		player.collBeforePt.x = player.CenterX;
		player.collBeforePt.y = player.CenterY;
	}


	//�����蔻��͈̔͐ݒ�

	for (int i = 0; i < SHOKUSHU_NUM; i++)
	{
			RECT PlayerRect;
			int CollRange = 2;
			PlayerRect.left = player.image.x + player.image.width / 2 - CollRange;
			PlayerRect.top = player.image.y + player.image.height / 2 - CollRange;
			PlayerRect.right = player.image.x + player.image.width / 2 + CollRange;
			PlayerRect.bottom = player.image.y + player.image.height / 2 + CollRange;

			RECT SyokushuRect;
			SyokushuRect.left = syokusyu[i].x;
			SyokushuRect.top = syokusyu[i].y;
			SyokushuRect.right = syokusyu[i].x + syokusyu[i].width;
			SyokushuRect.bottom = syokusyu[i].y + syokusyu[i].height;

			RECT BigSyokushuRect;
			BigSyokushuRect.left = syokusyu_big[i].x;
			BigSyokushuRect.top = syokusyu_big[i].y;
			BigSyokushuRect.right = syokusyu_big[i].x + syokusyu_big[i].width;
			BigSyokushuRect.bottom = syokusyu_big[i].y + syokusyu_big[i].height;

			RECT Gate1Rect;
			Gate1Rect.left = gate[1].x;
			Gate1Rect.top = gate[1].y;
			Gate1Rect.right = gate[1].x + 192;
			Gate1Rect.bottom = gate[1].y + 192;


			//�G��Ƃ̓����蔻��
			if (MY_CHECK_RECT_COLL(PlayerRect, SyokushuRect) == TRUE)
			{
				mutekicount = 0;
				heartnow -= 1;
				IsMuteki = TRUE;
				PlaySoundMem(damage.handle, DX_PLAYTYPE_BACK);
			}
			if (MY_CHECK_RECT_COLL(PlayerRect, BigSyokushuRect) == TRUE)
			{
				mutekicount = 0;
				heartnow -= 1;
				IsMuteki = TRUE;
				PlaySoundMem(damage.handle, DX_PLAYTYPE_BACK);
			}

			//�Q�[�g�Ƃ̓����蔻��
			if (MY_CHECK_RECT_COLL(PlayerRect, Gate1Rect) == TRUE)
			{
				hukidasi[3].IsDraw = TRUE;

				if (MY_KEY_DOWN(KEY_INPUT_SPACE) == TRUE)
				{
					PlaySoundMem(goal.handle, DX_PLAYTYPE_BACK);

					hukidasi[3].IsDraw = FALSE;

					player.CenterX = 800;
					player.CenterY = 300;

					player.image.x = player.CenterX;
					player.image.y = player.CenterY;

					player.collBeforePt.x = player.CenterX;
					player.collBeforePt.y = player.CenterY;

					GameScene = GAME_SCENE_PLAY;

					return;
				}
			}
			else
			{
				hukidasi[3].IsDraw = FALSE;
			}
	}



	for (int a = 0; a < Enemy_Num; a++)
	{

		RECT PlayerRect;
		int CollRange = 2;
		PlayerRect.left = player.image.x + player.image.width / 2 - CollRange;
		PlayerRect.top = player.image.y + player.image.height / 2 - CollRange;
		PlayerRect.right = player.image.x + player.image.width / 2 + CollRange;
		PlayerRect.bottom = player.image.y + player.image.height / 2 + CollRange;

		RECT Enemy_BalorRect;
		Enemy_BalorRect.left = Enemy_Balor[a].image.x;
		Enemy_BalorRect.top = Enemy_Balor[a].image.y;
		Enemy_BalorRect.right = Enemy_Balor[a].image.x + Enemy_Balor[a].image.width;
		Enemy_BalorRect.bottom = Enemy_Balor[a].image.y + Enemy_Balor[a].image.height;

		//�o���[���̐ڐG�`�F�b�N
		if (MY_CHECK_RECT_COLL(PlayerRect, Enemy_BalorRect) == TRUE)
		{
			mutekicount = 0;
			heartnow -= 1;
			IsMuteki = TRUE;
			PlaySoundMem(damage.handle, DX_PLAYTYPE_BACK);
		}
	}

	
	//���G����
	
	if (IsMuteki == TRUE)
	{

		mutekicount++;
		if (mutekicount < 31)
		{
			Ishit = FALSE;
			if (player.IsDraw == TRUE)
			{
				player.IsDraw = FALSE;
			}
			else if (player.IsDraw == FALSE)
			{
				player.IsDraw = TRUE;
			}
		}
		if (mutekicount > 31)
		{
			Ishit = TRUE;
		}
	}

	


	//�n�[�g���S�ĂȂ��Ȃ�����Q�[���I�[�o�[
	if (heartnow == FALSE)
	{
		if (CheckSoundMem(BGM.handle) != 0)
		{
			StopSoundMem(BGM.handle);
		}

		GameEndKind = GAME_END_FAIL;	//�~�b�V�����t�H�[���g�I

		GameScene = GAME_SCENE_END;

		return;	//�����I�ɃG���h��ʂɔ��
	}


	//�v���C���[����ʊO�ɏo����
	if (player.image.x > GAME_WIDTH || player.image.y > GAME_HEIGHT
		|| player.image.x + player.image.width < 0 || player.image.y + player.image.height < 0)
	{
		if (CheckSoundMem(BGM.handle) != 0)
		{
			StopSoundMem(BGM.handle);
		}

		SetMouseDispFlag(TRUE);

		GameEndKind = GAME_END_FAIL;

		GameScene = GAME_SCENE_END;

		return;
	}



	//�Ԓe�𔭎�
	if (MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
	{
		if (player.CanShot == TRUE)
		{
			PlaySoundMem(player.greenshot.handle, DX_PLAYTYPE_BACK);
			player.CanShot = FALSE;


			for (int cnt = 0; cnt < TAMA_MAX; cnt++)
			{
				if (player.tama[cnt].IsDraw == FALSE)
				{
					player.tama[cnt].x = player.image.x - 10;

					player.tama[cnt].y = player.CenterY - 20;

					player.tama[cnt].IsDraw = TRUE;

					break;
				}

			}
		}
	}



	//�Βe�𔭎�
	if (MY_KEY_DOWN(KEY_INPUT_S) == TRUE)
	{
		if (player.CanShot == TRUE)
		{
			PlaySoundMem(player.greenshot.handle, DX_PLAYTYPE_BACK);
			player.CanShot = FALSE;


			for (int cnt = 0; cnt < TAMA_MAX; cnt++)
			{
				if (player.tama2[cnt].IsDraw == FALSE)
				{

					player.tama2[cnt].x = player.image.x - 10;

					player.tama2[cnt].y = player.CenterY - 20;

					player.tama2[cnt].IsDraw = TRUE;

					break;
				}
			}

		}
	}


	//�e
	if (MY_KEY_DOWN(KEY_INPUT_D) == TRUE)
	{
		if (player.CanShot == TRUE)
		{
			PlaySoundMem(player.greenshot.handle, DX_PLAYTYPE_BACK);
			player.CanShot = FALSE;


			for (int cnt = 0; cnt < TAMA_MAX; cnt++)
			{
				if (player.b_tama[cnt].IsDraw == FALSE)
				{

					player.b_tama[cnt].x = player.image.x - 10;

					player.b_tama[cnt].y = player.CenterY - 20;

					player.b_tama[cnt].IsDraw = TRUE;

					break;
				}
			}

		}
	}



	//���e
	if (MY_KEY_DOWN(KEY_INPUT_F) == TRUE)
	{
		if (player.CanShot == TRUE)
		{
			PlaySoundMem(player.greenshot.handle, DX_PLAYTYPE_BACK);
			player.CanShot = FALSE;


			for (int cnt = 0; cnt < TAMA_MAX; cnt++)
			{
				if (player.y_tama[cnt].IsDraw == FALSE)
				{

					player.y_tama[cnt].x = player.image.x - 10;

					player.y_tama[cnt].y = player.CenterY - 20;

					player.y_tama[cnt].IsDraw = TRUE;

					break;
				}
			}

		}
	}


	//[[�J�E���g]]


	St2count += 1;



	//�G�̏o���J�E���g


	//�e�X�g�p
	/*if (St2count > 100)
	{
		Enemy_Balor[0].image.x += 2;
	}*/


	if (St2count > 400)
	{
		if (Enemy_Balor[0].image.x < 1000)
		{
			Enemy_Balor[0].image.x+=2;
		}
	}
	if (St2count > 600)
	{
		if (Enemy_Balor[1].image.x < 1200)
		{
			Enemy_Balor[1].image.x+=2;
		}
	}
	if (St2count > 1000)
	{
		if (Enemy_Balor[2].image.y < 800)
		{
			Enemy_Balor[2].image.y+=2;
		}		
	}
	if (St2count > 1400)
	{
		if (Enemy_Balor[3].image.y < 800)
		{
			Enemy_Balor[3].image.y+=2;
		}
	}
	if (St2count > 1700)
	{
		if (Enemy_Balor[4].image.x < 1200)
		{
			Enemy_Balor[4].image.x+=2;
		}
		if (Enemy_Balor[5].image.x < 1200)
		{
			Enemy_Balor[5].image.x += 2;
		}
	}

	if (St2count > 2000)
	{
		if (Enemy_Balor[6].image.x < 1200)
		{
			Enemy_Balor[6].image.x+=2;
			Enemy_Balor[6].image.y++;
		}
	}
	if (St2count > 2300)
	{
		if (Enemy_Balor[7].image.x < 1200)
		{
			Enemy_Balor[7].image.x+=2;
			Enemy_Balor[7].image.y-=2;
		}
	}

	if (St2count > 2700)
	{
		if (Enemy_Balor[8].image.x < 1200)
		{
			Enemy_Balor[8].image.x+=2;
		}

		Enemy_Balor[9].image.y -= 2;
	}

	if (St2count > 3200)
	{
		Enemy_Balor[10].image.y+=2;
		Enemy_Balor[11].image.y -= 2;
	}


	if (St2count > 3500)
	{
		Enemy_Balor[12].image.x+=2;
		Enemy_Balor[13].image.x += 2;
	}

	if (St2count > 4000)
	{
		Enemy_Balor[14].image.x+=2;
		Enemy_Balor[15].image.x += 2;
	}

	if (St2count > 4500)
	{
		Enemy_Balor[16].image.x += 2;
		Enemy_Balor[17].image.x += 2;
	}

	if (St2count > 5000)
	{
		Enemy_Balor[18].image.x += 2;
		Enemy_Balor[19].image.x += 2;
		Enemy_Balor[20].image.x += 2;
	}


	//�Ԃ͊댯�I�΂͈��S

	hukidasi3.x = 150;
	hukidasi3.y = 500;

	if (St2count > 50)
	{
		if (St2count < 300)
		{
			hukidasi3.IsDraw = TRUE;
		}
		if (St2count == 300)
		{
			hukidasi3.IsDraw = FALSE;
		}
	}


	//�ԃG���A�P��ڕ\��


	if (St2count > 350)
	{
		if (St2count < 550)
		{
			denger_yoko[0].IsDraw = TRUE;
		}
		if (St2count == 550)
		{
			denger_yoko[0].IsDraw = FALSE;
		}
	}


	//�G��P��ڂ̍U��

	if (St2count > 600)
	{
		syokusyu[0].IsDraw = TRUE;
		syokusyu[0].x -= 10;
	}


	//�ԃG���A�Q��ڕ\��

	if (St2count > 900)
	{
		if (St2count < 1100)
		{
			denger_yoko[1].IsDraw = TRUE;
		}
		if (St2count == 1100)
		{
			denger_yoko[1].IsDraw = FALSE;
		}
	}


	//�G��Q
	if (St2count > 1150)
	{

		syokusyu[1].IsDraw = TRUE;
		syokusyu[1].x -= 10;

	}


	//�ԃG���A�R��ڕ\��
	if (St2count > 1450)
	{
		if (St2count < 1650)
		{
			denger_yoko[2].IsDraw = TRUE;
			denger_yoko[3].IsDraw = TRUE;
		}
		if (St2count == 1650)
		{
			denger_yoko[2].IsDraw = FALSE;
			denger_yoko[3].IsDraw = FALSE;
		}
	}


	//�G��R
	if (St2count > 1700)
	{

		syokusyu[2].IsDraw = TRUE;
		syokusyu[2].x -= 10;
		syokusyu[3].IsDraw = TRUE;
		syokusyu[3].x -= 10;

	}


	//�ԃG���A�S��ڕ\��
	if (St2count > 2000)
	{
		if (St2count < 2200)
		{
			denger_yoko[4].IsDraw = TRUE;
			denger_yoko[5].IsDraw = TRUE;
			denger_yoko[6].IsDraw = TRUE;
		}
		if (St2count == 2200)
		{
			denger_yoko[4].IsDraw = FALSE;
			denger_yoko[5].IsDraw = FALSE;
			denger_yoko[6].IsDraw = FALSE;
		}
	}


	//�G��S
	if (St2count > 2250)
	{

		syokusyu[4].IsDraw = TRUE;
		syokusyu[4].x -= 10;
		syokusyu[5].IsDraw = TRUE;
		syokusyu[5].x -= 10;
		syokusyu[6].IsDraw = TRUE;
		syokusyu[6].x -= 10;

	}


	//�ԃG���A5��ڕ\��
	if (St2count > 2550)
	{
		if (St2count < 2750)
		{
			denger_yoko[7].IsDraw = TRUE;
			denger_yoko[8].IsDraw = TRUE;
			denger_yoko[9].IsDraw = TRUE;
		}
		if (St2count == 2750)
		{
			denger_yoko[7].IsDraw = FALSE;
			denger_yoko[8].IsDraw = FALSE;
			denger_yoko[9].IsDraw = FALSE;
		}
	}


	//�G��5
	if (St2count > 2800)
	{

		syokusyu[7].IsDraw = TRUE;
		syokusyu[7].x -= 10;
		syokusyu[8].IsDraw = TRUE;
		syokusyu[8].x -= 10;
		syokusyu[9].IsDraw = TRUE;
		syokusyu[9].x -= 10;

	}


	//�΃G���A1��ڕ\��
	if (St2count > 3100)
	{
		if (St2count < 3300)
		{
			safe_yoko[0].IsDraw = TRUE;
			safe_yoko[1].IsDraw = TRUE;
		}
		if (St2count == 3300)
		{
			safe_yoko[0].IsDraw = FALSE;
			safe_yoko[1].IsDraw = FALSE;
		}
	}

	//�G��6
	if (St2count > 3350)
	{

		syokusyu[10].IsDraw = TRUE;
		syokusyu[10].x -= 10;
		syokusyu[11].IsDraw = TRUE;
		syokusyu[11].x -= 10;
		syokusyu[12].IsDraw = TRUE;
		syokusyu[12].x -= 10;
		syokusyu[13].IsDraw = TRUE;
		syokusyu[13].x -= 10;
		syokusyu[14].IsDraw = TRUE;
		syokusyu[14].x -= 10;
		syokusyu[15].IsDraw = TRUE;
		syokusyu[15].x -= 10;

	}


	//�΃G���A2��ڕ\��
	if (St2count > 3650)
	{
		if (St2count < 3850)
		{
			safe_yoko[2].IsDraw = TRUE;
		}
		if (St2count == 3850)
		{
			safe_yoko[2].IsDraw = FALSE;
		}
	}


	//�G��7
	if (St2count > 3900)
	{

		syokusyu_big[0].IsDraw = TRUE;
		syokusyu_big[0].x -= 10;
	}


	//�΃G���A3��ڕ\��
	if (St2count > 4200)
	{
		if (St2count < 4400)
		{
			safe_yoko[3].IsDraw = TRUE;
		}
		if (St2count == 4400)
		{
			safe_yoko[3].IsDraw = FALSE;
		}
	}


	//�G��8
	if (St2count > 4450)
	{

		syokusyu_big[1].IsDraw = TRUE;
		syokusyu_big[1].x -= 10;

		syokusyu_big[2].IsDraw = TRUE;
		syokusyu_big[2].x -= 10;
	}


	//�΃G���A4��ڕ\��
	if (St2count > 4650)
	{
		if (St2count < 4750)
		{
			safe_yoko[4].IsDraw = TRUE;
		}
		if (St2count == 4750)
		{
			safe_yoko[4].IsDraw = FALSE;
		}
	}

	//�G��9
	if (St2count > 4800)
	{

		syokusyu_big[3].IsDraw = TRUE;
		syokusyu_big[3].x -= 10;

	}


	//�΃G���A5��ڕ\��
	if (St2count > 5000)
	{
		if (St2count < 5100)
		{
			safe_yoko[5].IsDraw = TRUE;
		}
		if (St2count == 5100)
		{
			safe_yoko[5].IsDraw = FALSE;
		}
	}


	//�G��10
	if (St2count > 5150)
	{

		syokusyu_big[4].IsDraw = TRUE;
		syokusyu_big[4].x -= 10;

	}


	//�C�G���[�N���X�^���o��
	if (St2count > 5600)
	{
		if (y_crystal.x < 400)
		{
			y_crystal.x++;
		}
	}


	//�o���[���ƒe�̓����蔻��
	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		for (int kazu = 0; kazu < Enemy_Num; kazu++)
		{
			//�Ԓe
			if (((player.tama[cnt].x > Enemy_Balor[kazu].image.x && player.tama[cnt].x < Enemy_Balor[kazu].image.x + Enemy_Balor[kazu].image.width) ||
				(Enemy_Balor[kazu].image.x > player.tama[cnt].x && Enemy_Balor[kazu].image.x < player.tama[cnt].x + player.tama[cnt].width)) &&
				((player.tama[cnt].y > Enemy_Balor[kazu].image.y && player.tama[cnt].y < Enemy_Balor[kazu].image.y + Enemy_Balor[kazu].image.height) ||
					(Enemy_Balor[kazu].image.y > player.tama[cnt].y && Enemy_Balor[kazu].image.y < player.tama[cnt].y + player.tama[cnt].height)))
			{

				if (kazu == 1)
				{
					player.tama[cnt].y = 1000;
					Enemy_Balor[1].image.x = 1000;
					Enemy_Balor[1].image.y = 1000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}
				if (kazu == 7)
				{
					player.tama[cnt].y = 1000;
					Enemy_Balor[7].image.x = 1000;
					Enemy_Balor[7].image.y = 2000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}
				if (kazu == 11)
				{
					player.tama[cnt].y = 1000;
					Enemy_Balor[11].image.x = 1000;
					Enemy_Balor[11].image.y = 1000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}
				if (kazu == 14)
				{
					player.tama[cnt].y = 1000;
					Enemy_Balor[14].image.x = 1000;
					Enemy_Balor[14].image.y = 1000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}
				if (kazu == 19)
				{
					player.tama[cnt].y = 1000;
					Enemy_Balor[19].image.x = 1000;
					Enemy_Balor[19].image.y = 1000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}

			}

			//�Βe
			if (((player.tama2[cnt].x > Enemy_Balor[kazu].image.x && player.tama2[cnt].x < Enemy_Balor[kazu].image.x + Enemy_Balor[kazu].image.width) ||
				(Enemy_Balor[kazu].image.x > player.tama2[cnt].x && Enemy_Balor[kazu].image.x < player.tama2[cnt].x + player.tama2[cnt].width)) &&
				((player.tama2[cnt].y > Enemy_Balor[kazu].image.y && player.tama2[cnt].y < Enemy_Balor[kazu].image.y + Enemy_Balor[kazu].image.height) ||
					(Enemy_Balor[kazu].image.y > player.tama2[cnt].y && Enemy_Balor[kazu].image.y < player.tama2[cnt].y + player.tama2[cnt].height)))
			{
				if (kazu == 3)
				{
					player.tama2[cnt].y = 1000;
					Enemy_Balor[3].image.x = 1000;
					Enemy_Balor[3].image.y = 1000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}
				if (kazu == 6)
				{
					player.tama2[cnt].y = 1000;
					Enemy_Balor[6].image.x = 0;
					Enemy_Balor[6].image.y = 1000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}
				if (kazu == 10)
				{
					player.tama2[cnt].y = 1000;
					Enemy_Balor[10].image.x = 0;
					Enemy_Balor[10].image.y = 1000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}
				if (kazu == 15)
				{
					player.tama2[cnt].y = 1000;
					Enemy_Balor[15].image.x = 0;
					Enemy_Balor[15].image.y = 1000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}
				if (kazu == 18)
				{
					player.tama2[cnt].y = 1000;
					Enemy_Balor[18].image.x = 0;
					Enemy_Balor[18].image.y = 1000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}
			}


			//�e
			if (((player.b_tama[cnt].x > Enemy_Balor[kazu].image.x && player.b_tama[cnt].x < Enemy_Balor[kazu].image.x + Enemy_Balor[kazu].image.width) ||
				(Enemy_Balor[kazu].image.x > player.b_tama[cnt].x && Enemy_Balor[kazu].image.x < player.b_tama[cnt].x + player.b_tama[cnt].width)) &&
				((player.b_tama[cnt].y > Enemy_Balor[kazu].image.y && player.b_tama[cnt].y < Enemy_Balor[kazu].image.y + Enemy_Balor[kazu].image.height) ||
					(Enemy_Balor[kazu].image.y > player.b_tama[cnt].y && Enemy_Balor[kazu].image.y < player.b_tama[cnt].y + player.b_tama[cnt].height)))
			{
				if (kazu == 0)
				{
					player.b_tama[cnt].y = 1000;
					Enemy_Balor[0].image.x = 0;
					Enemy_Balor[0].image.y = 1000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}
				if (kazu == 4)
				{
					player.b_tama[cnt].y = 1000;
					Enemy_Balor[4].image.x = 0;
					Enemy_Balor[4].image.y = 1000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}
				if (kazu == 8)
				{
					player.b_tama[cnt].y = 1000;
					Enemy_Balor[8].image.x = 0;
					Enemy_Balor[8].image.y = 1000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}
				if (kazu == 13)
				{
					player.b_tama[cnt].y = 1000;
					Enemy_Balor[13].image.x = 0;
					Enemy_Balor[13].image.y = 1000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}
				if (kazu == 16)
				{
					player.b_tama[cnt].y = 1000;
					Enemy_Balor[16].image.x = 0;
					Enemy_Balor[16].image.y = 1000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}
				if (kazu == 20)
				{
					player.b_tama[cnt].y = 1000;
					Enemy_Balor[20].image.x = 0;
					Enemy_Balor[20].image.y = 1000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}
			}



			//���e
			if (((player.y_tama[cnt].x > Enemy_Balor[kazu].image.x && player.y_tama[cnt].x < Enemy_Balor[kazu].image.x + Enemy_Balor[kazu].image.width) ||
				(Enemy_Balor[kazu].image.x > player.y_tama[cnt].x && Enemy_Balor[kazu].image.x < player.y_tama[cnt].x + player.y_tama[cnt].width)) &&
				((player.y_tama[cnt].y > Enemy_Balor[kazu].image.y && player.y_tama[cnt].y < Enemy_Balor[kazu].image.y + Enemy_Balor[kazu].image.height) ||
					(Enemy_Balor[kazu].image.y > player.y_tama[cnt].y && Enemy_Balor[kazu].image.y < player.y_tama[cnt].y + player.y_tama[cnt].height)))
			{
				if (kazu == 2)
				{
					player.y_tama[cnt].y = 1000;
					Enemy_Balor[2].image.x = 0;
					Enemy_Balor[2].image.y = 1000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}
				if (kazu == 5)
				{
					player.y_tama[cnt].y = 1000;
					Enemy_Balor[5].image.x = 0;
					Enemy_Balor[5].image.y = 1000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}
				if (kazu == 9)
				{
					player.y_tama[cnt].y = 1000;
					Enemy_Balor[9].image.x = 1000;
					Enemy_Balor[9].image.y = 1000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}
				if (kazu == 12)
				{
					player.y_tama[cnt].y = 1000;
					Enemy_Balor[12].image.x = 0;
					Enemy_Balor[12].image.y = 1000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}
				if (kazu == 17)
				{
					player.y_tama[cnt].y = 1000;
					Enemy_Balor[17].image.x = 0;
					Enemy_Balor[17].image.y = 1000;
					PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);
				}
			}

		}
	}


	if (player.CanShot == FALSE)
	{

		if (player.ShotReLoadCnt == player.ShotReLoadCntMAX)
		{
			player.ShotReLoadCnt = 0;
			player.CanShot = TRUE;
		}

		player.ShotReLoadCnt++;
	}


	//�C�G���[�N���X�^���Ɖ��e�̓����蔻��
	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		if (((player.y_tama[cnt].x > y_crystal.x && player.y_tama[cnt].x < y_crystal.x + y_crystal.width) ||
			(y_crystal.x > player.y_tama[cnt].x && y_crystal.x < player.y_tama[cnt].x + player.y_tama[cnt].width)) &&
			((player.y_tama[cnt].y > y_crystal.y && player.y_tama[cnt].y < y_crystal.y + y_crystal.height) ||
				(y_crystal.y > player.y_tama[cnt].y && y_crystal.y < player.y_tama[cnt].y + player.y_tama[cnt].height)))
		{
			player.y_tama[cnt].IsDraw = FALSE;
			player.y_tama[cnt].x = 0;
			player.y_tama[cnt].y = 1000;

			PlaySoundMem(hakai.handle, DX_PLAYTYPE_BACK);

			y_crystal.IsDraw = FALSE;
			y_crystal.y = 1000;

			//�N���X�^���j��e�L�X�g��\��
			hukidasi2.IsDraw = TRUE;
			crystaltext = TRUE;
			EnterDraw = TRUE;
			Sousa = FALSE;

		}
	}

	//�C�G���[�N���X�^�����j�󂳂ꂽ��
	if (y_crystal.IsDraw == FALSE)
	{
		//�N���X�^����j�󂵂��t���O��TRUE
		y_crystal_Flag = TRUE;

		if (gate[1].x < 200)
		{
			gate[1].x++;
		}
	}

	if (hukidasi2.IsDraw == TRUE)
	{
		if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
		{
			hukidasi2.IsDraw = FALSE;
			crystaltext = FALSE;
			EnterDraw = FALSE;
			Sousa = TRUE;
		}
	}

	hukidasi[3].x = gate[1].x + 20;
	hukidasi[3].y = gate[1].y - 20;

	return;
}

VOID MY_PLAY2_DRAW(VOID)
{

	//���X�N���[���w�i�̕`��
	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		if (ImageBack[num].IsDraw == TRUE)
		{
			DrawGraph(ImageBack[num].image.x, ImageBack[num].image.y, ImageBack[num].image.handle, TRUE);

		}
	}


	//�e��������E�B���h�E
	DrawGraph(tamasousa_gazou.x, tamasousa_gazou.y, tamasousa_gazou.handle, TRUE);



	if (hukidasi2.IsDraw == TRUE)
	{
		DrawGraph(hukidasi2.x, hukidasi2.y, hukidasi2.handle, TRUE);
	}

	if (crystaltext == TRUE)
	{
		DrawString(230, 520, "�N���X�^����j�󂵂��I\n�ǂ����̃��[�v�Q�[�g���쓮�����悤��", GetColor(255, 255, 255));
	}

	if (EnterDraw == TRUE)
	{
		DrawString(700, 580, "ENTER", GetColor(255, 255, 255));
	}


	//���������������������y�G���A�z��������������������


	for (int i = 0; i < DENGER_TATE_NUM; i++)
	{
		if (denger_tate[i].IsDraw == TRUE)
		{
			DrawGraph(denger_tate[i].x, denger_tate[i].y, denger_tate[i].handle, TRUE);
		}
	}


	for (int i = 0; i < DENGER_YOKO_NUM; i++)
	{
		if (denger_yoko[i].IsDraw == TRUE)
		{
			DrawGraph(denger_yoko[i].x, denger_yoko[i].y, denger_yoko[i].handle, TRUE);
		}
	}



	for (int i = 0; i < SAFE_TATE_NUM; i++)
	{
		if (safe_tate[i].IsDraw == TRUE)
		{
			DrawGraph(safe_tate[i].x, safe_tate[i].y, safe_tate[i].handle, TRUE);
		}
	}



	for (int i = 0; i < SAFE_YOKO_NUM; i++)
	{
		if (safe_yoko[i].IsDraw == TRUE)
		{
			DrawGraph(safe_yoko[i].x, safe_yoko[i].y, safe_yoko[i].handle, TRUE);
		}
	}



	if (heartnow > 0)
	{
		DrawGraph(heart[0].x, heart[0].y, heart[0].handle, TRUE);

		if (heartnow > 1)
		{
			DrawGraph(heart[1].x, heart[1].y, heart[1].handle, TRUE);

			if (heartnow > 2)
			{
				DrawGraph(heart[2].x, heart[2].y, heart[2].handle, TRUE);
			}
		}
	}

	//�e�X�g�p
	/*DrawFormatString(600, 0, GetColor(255, 255, 255), "heartnow:%d", heartnow);*/


	int a;

	a = St2count % 40 / 5;

	if (a == 10)
	{
		a = 0;
	}

	//�N���X�^���`��
	if (y_crystal.IsDraw == TRUE)
	{
		DrawGraph(y_crystal.x, y_crystal.y, crystalhandle[a], TRUE);
	}

	//�Q�[�g�`��

	DrawGraph(gate[1].x, gate[1].y, gatehandle[a], TRUE);


	for (int i = 0; i < SHOKUSHU_NUM; i++)
	{
		if (syokusyu[i].IsDraw == TRUE)
		{
			DrawGraph(syokusyu[i].x, syokusyu[i].y, syokusyu[i].handle, TRUE);
		}
	}


//�v���C���[�`��
	if (MY_KEY_DOWN(KEY_INPUT_LEFT) == TRUE)
	{
		muki = 4;
		leftcount++;
		rightcount = 0;
		stopflag = FALSE;
	}
	else if (MY_KEY_DOWN(KEY_INPUT_RIGHT) == TRUE)
	{
		muki = 1;
		rightcount++;
		leftcount = 0;
		stopflag = FALSE;
	}
	else
	{
		stopflag = TRUE;
	}


	if (leftcount > 0)
	{
		if (stopflag == TRUE)
		{
			muki = 3;
		}
		if (MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
		{
			muki = 5;
		}
		if (MY_KEY_DOWN(KEY_INPUT_S) == TRUE)
		{
			muki = 5;
		}
		if (MY_KEY_DOWN(KEY_INPUT_D) == TRUE)
		{
			muki = 5;
		}
		if (MY_KEY_DOWN(KEY_INPUT_F) == TRUE)
		{
			muki = 5;
		}
	}

	if (rightcount > 0)
	{
		if (stopflag == TRUE)
		{
			muki = 0;
		}
		if (MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
		{
			muki = 5;
		}
		if (MY_KEY_DOWN(KEY_INPUT_S) == TRUE)
		{
			muki = 5;
		}
		if (MY_KEY_DOWN(KEY_INPUT_D) == TRUE)
		{
			muki = 5;
		}
		if (MY_KEY_DOWN(KEY_INPUT_F) == TRUE)
		{
			muki = 5;
		}
	}

	if (player.IsDraw == TRUE)
	{
		DrawGraph(player.image.x, player.image.y, player.image.m_handle[muki], TRUE);
	}



	//�o���[���̕`��
	for (int kazu = 0; kazu < Enemy_Num; kazu++)
	{

		if (Enemy_Balor[kazu].image.IsDraw == TRUE)
		{

			DrawGraph(Enemy_Balor[0].image.x, Enemy_Balor[0].image.y, Enemy_Balor[0].enecolor[2], TRUE);
			DrawGraph(Enemy_Balor[1].image.x, Enemy_Balor[1].image.y, Enemy_Balor[1].enecolor[0], TRUE);
			DrawGraph(Enemy_Balor[2].image.x, Enemy_Balor[2].image.y, Enemy_Balor[2].enecolor[3], TRUE);
			DrawGraph(Enemy_Balor[3].image.x, Enemy_Balor[3].image.y, Enemy_Balor[3].enecolor[1], TRUE);
			DrawGraph(Enemy_Balor[4].image.x, Enemy_Balor[4].image.y, Enemy_Balor[4].enecolor[2], TRUE);
			DrawGraph(Enemy_Balor[5].image.x, Enemy_Balor[5].image.y, Enemy_Balor[5].enecolor[3], TRUE);
			DrawGraph(Enemy_Balor[6].image.x, Enemy_Balor[6].image.y, Enemy_Balor[6].enecolor[1], TRUE);
			DrawGraph(Enemy_Balor[7].image.x, Enemy_Balor[7].image.y, Enemy_Balor[7].enecolor[0], TRUE);
			DrawGraph(Enemy_Balor[8].image.x, Enemy_Balor[8].image.y, Enemy_Balor[8].enecolor[2], TRUE);
			DrawGraph(Enemy_Balor[9].image.x, Enemy_Balor[9].image.y, Enemy_Balor[9].enecolor[3], TRUE);
			DrawGraph(Enemy_Balor[10].image.x, Enemy_Balor[10].image.y, Enemy_Balor[10].enecolor[1], TRUE);
			DrawGraph(Enemy_Balor[11].image.x, Enemy_Balor[11].image.y, Enemy_Balor[11].enecolor[0], TRUE);
			DrawGraph(Enemy_Balor[12].image.x, Enemy_Balor[12].image.y, Enemy_Balor[12].enecolor[3], TRUE);
			DrawGraph(Enemy_Balor[13].image.x, Enemy_Balor[13].image.y, Enemy_Balor[13].enecolor[2], TRUE);
			DrawGraph(Enemy_Balor[14].image.x, Enemy_Balor[14].image.y, Enemy_Balor[14].enecolor[0], TRUE);
			DrawGraph(Enemy_Balor[15].image.x, Enemy_Balor[15].image.y, Enemy_Balor[15].enecolor[1], TRUE);
			DrawGraph(Enemy_Balor[16].image.x, Enemy_Balor[16].image.y, Enemy_Balor[16].enecolor[2], TRUE);
			DrawGraph(Enemy_Balor[17].image.x, Enemy_Balor[17].image.y, Enemy_Balor[17].enecolor[3], TRUE);
			DrawGraph(Enemy_Balor[18].image.x, Enemy_Balor[18].image.y, Enemy_Balor[18].enecolor[1], TRUE);
			DrawGraph(Enemy_Balor[19].image.x, Enemy_Balor[19].image.y, Enemy_Balor[19].enecolor[0], TRUE);
			DrawGraph(Enemy_Balor[20].image.x, Enemy_Balor[20].image.y, Enemy_Balor[20].enecolor[2], TRUE);

		}
	}



	for (int i = 0; i < SHOKUSHU_NUM; i++)
	{
		if (syokusyu_big[i].IsDraw == TRUE)
		{
			DrawGraph(syokusyu_big[i].x, syokusyu_big[i].y, syokusyu_big[i].handle, TRUE);
		}
	}


	for (int i = 0; i < HUKIDASI_NUM; i++)
	{
		if (hukidasi[i].IsDraw == TRUE)
		{
			DrawGraph(hukidasi[i].x, hukidasi[i].y, hukidasi[i].handle, TRUE);
		}
	}


	if (hukidasi3.IsDraw == TRUE)
	{
		DrawGraph(hukidasi3.x, hukidasi3.y, hukidasi3.handle, TRUE);
	}


	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		if (player.tama[cnt].IsDraw == TRUE)
		{
			DrawGraph(
				player.tama[cnt].x,
				player.tama[cnt].y,
				player.tama[cnt].handle[player.tama[cnt].nowImageKind],
				TRUE);

			if (player.tama[cnt].changeImageCnt < player.tama[cnt].changeImageCntMAX)
			{
				player.tama[cnt].changeImageCnt++;
			}
			else
			{
				if (player.tama[cnt].nowImageKind < TAMA_DIV_NUM - 1)
				{
					player.tama[cnt].nowImageKind++;
				}
				else
				{
					player.tama[cnt].nowImageKind = 0;
				}

				player.tama[cnt].changeImageCnt = 0;
			}

			if (player.tama[cnt].x < player.CenterX - TAMA_HIKYORI_LONG || player.tama[cnt].x < 0)
			{
				player.tama[cnt].IsDraw = FALSE;
				player.tama[cnt].y = 1000;
			}
			else
			{
				player.tama[cnt].x -= player.tama[cnt].speed;

			}

		}
	}


	/*for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		DrawBox(player.tama[cnt].x, player.tama[cnt].y, player.tama[cnt].x + 16, player.tama[cnt].y + 16, GetColor(255, 255, 255), FALSE);
	}*/




	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		if (player.tama2[cnt].IsDraw == TRUE)
		{
			DrawGraph(
				player.tama2[cnt].x,
				player.tama2[cnt].y,
				player.tama2[cnt].handle[player.tama2[cnt].nowImageKind],
				TRUE);

			if (player.tama2[cnt].changeImageCnt < player.tama2[cnt].changeImageCntMAX)
			{
				player.tama2[cnt].changeImageCnt++;
			}
			else
			{
				if (player.tama2[cnt].nowImageKind < TAMA_DIV_NUM - 1)
				{
					player.tama2[cnt].nowImageKind++;
				}
				else
				{
					player.tama2[cnt].nowImageKind = 0;
				}

				player.tama2[cnt].changeImageCnt = 0;
			}

			if (player.tama2[cnt].x < player.CenterX - TAMA_HIKYORI_LONG || player.tama2[cnt].x < 0)
			{
				player.tama2[cnt].IsDraw = FALSE;
				player.tama2[cnt].y = 1000;
			}
			else
			{
				player.tama2[cnt].x -= player.tama[cnt].speed;

			}
		}
	}




	/*for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		DrawBox(player.tama2[cnt].x, player.tama2[cnt].y, player.tama2[cnt].x + 16, player.tama2[cnt].y + 16, GetColor(255, 255, 255), FALSE);
	}*/




	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		if (player.b_tama[cnt].IsDraw == TRUE)
		{
			DrawGraph(
				player.b_tama[cnt].x,
				player.b_tama[cnt].y,
				player.b_tama[cnt].handle[player.b_tama[cnt].nowImageKind],
				TRUE);

			if (player.b_tama[cnt].changeImageCnt < player.b_tama[cnt].changeImageCntMAX)
			{
				player.b_tama[cnt].changeImageCnt++;
			}
			else
			{
				if (player.b_tama[cnt].nowImageKind < TAMA_DIV_NUM - 1)
				{
					player.b_tama[cnt].nowImageKind++;
				}
				else
				{
					player.b_tama[cnt].nowImageKind = 0;
				}

				player.b_tama[cnt].changeImageCnt = 0;
			}

			if (player.b_tama[cnt].x < player.CenterX - TAMA_HIKYORI_LONG || player.b_tama[cnt].x < 0)
			{
				player.b_tama[cnt].IsDraw = FALSE;
				player.b_tama[cnt].y = 1000;
			}
			else
			{
				player.b_tama[cnt].x -= player.tama[cnt].speed;

			}
		}
	}


	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		if (player.y_tama[cnt].IsDraw == TRUE)
		{
			DrawGraph(
				player.y_tama[cnt].x,
				player.y_tama[cnt].y,
				player.y_tama[cnt].handle[player.y_tama[cnt].nowImageKind],
				TRUE);

			if (player.y_tama[cnt].changeImageCnt < player.y_tama[cnt].changeImageCntMAX)
			{
				player.y_tama[cnt].changeImageCnt++;
			}
			else
			{
				if (player.y_tama[cnt].nowImageKind < TAMA_DIV_NUM - 1)
				{
					player.y_tama[cnt].nowImageKind++;
				}
				else
				{
					player.y_tama[cnt].nowImageKind = 0;
				}

				player.y_tama[cnt].changeImageCnt = 0;
			}

			if (player.y_tama[cnt].x < player.CenterX - TAMA_HIKYORI_LONG || player.y_tama[cnt].x < 0)
			{
				player.y_tama[cnt].IsDraw = FALSE;
				player.y_tama[cnt].y = 1000;
			}
			else
			{
				player.y_tama[cnt].x -= player.tama[cnt].speed;

			}
		}
	}


	return;
}



VOID MY_END(VOID)
{
	MY_END_PROC();
	MY_END_DRAW();
	return;
}

VOID MY_END_PROC(VOID)
{


	if (MY_KEY_DOWN(KEY_INPUT_ESCAPE) == TRUE)
	{
		if (CheckSoundMem(ENDBGM.handle) != 0)
		{
			StopSoundMem(ENDBGM.handle);	//BGM���~�߂�
		}

		if (CheckSoundMem(gameover.handle) != 0)
		{
			StopSoundMem(gameover.handle);	//BGM���~�߂�
		}


		SetMouseDispFlag(TRUE);


		GameScene = GAME_SCENE_START;

		return;
	}




	switch (GameEndKind)
	{
	case GAME_END_COMP:

		endback.IsDraw = TRUE;

		if (CheckSoundMem(ENDBGM.handle) == 0)
		{
			PlaySoundMem(ENDBGM.handle, DX_PLAYTYPE_LOOP);
		}


		if (ImageEndCOMP.Cnt < ImageEndCOMP.CntMAX)
		{
			ImageEndCOMP.Cnt += IMAGE_END_COMP_CNT;
		}
		else
		{
			if (ImageEndCOMP.IsDraw == FALSE)
			{
				ImageEndCOMP.IsDraw = TRUE;
			}
			else if (ImageEndCOMP.IsDraw == TRUE)
			{
				ImageEndCOMP.IsDraw = FALSE;
			}
			ImageEndCOMP.Cnt = 0;
		}
		break;

	case GAME_END_FAIL:

		if (CheckSoundMem(gameover.handle) == 0)
		{
			ChangeVolumeSoundMem(255 * 70 / 100, gameover.handle);	//50%�̉��ʂɂ���


			PlaySoundMem(gameover.handle, DX_PLAYTYPE_LOOP);
		}






		if (ImageEndFAIL.Cnt < ImageEndFAIL.CntMAX)
		{
			ImageEndFAIL.Cnt += IMAGE_END_FAIL_CNT;
		}
		else
		{
			if (ImageEndFAIL.IsDraw == FALSE)
			{
				ImageEndFAIL.IsDraw = TRUE;
			}
			else if (ImageEndFAIL.IsDraw == TRUE)
			{
				ImageEndFAIL.IsDraw = FALSE;
			}
			ImageEndFAIL.Cnt = 0;
		}
		break;
	}



	return;
}

VOID MY_END_DRAW(VOID)
{

	switch (GameEndKind)
	{
	case GAME_END_COMP:

		if (endback.IsDraw == TRUE)
		{
			DrawGraph(endback.x, endback.y, endback.handle, TRUE);

		}
		if (ImageEndCOMP.IsDraw == TRUE)
		{
			DrawGraph(ImageEndCOMP.image.x, ImageEndCOMP.image.y, ImageEndCOMP.image.handle, TRUE);
		}
		break;

	case GAME_END_FAIL:


		if (ImageEndFAIL.IsDraw == TRUE)
		{
			DrawGraph(ImageEndFAIL.image.x, ImageEndFAIL.image.y, ImageEndFAIL.image.handle, TRUE);
		}
		break;
	}

	


	return;
}



//�����������������������������������������������������摜�ǂݍ��݁�����������������������������������������������������������

BOOL MY_LOAD_IMAGE(VOID)
{

	// �w�i�摜
	strcpy_s(ImageTitleBK.path, IMAGE_TITLE_BK_PATH);
	ImageTitleBK.handle = LoadGraph(ImageTitleBK.path);
	if (ImageTitleBK.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitleBK.handle, &ImageTitleBK.width, &ImageTitleBK.height);
	ImageTitleBK.x = GAME_WIDTH / 2 - ImageTitleBK.width / 2;
	ImageTitleBK.y = GAME_HEIGHT / 2 - ImageTitleBK.height / 2;


	//�N���A�w�i
	strcpy_s(endback.path, IMAGE_ENDBACK_PATH);
	endback.handle = LoadGraph(endback.path);
	if (endback.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_ENDBACK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(endback.handle, &endback.width, &endback.height);
	endback.x = GAME_WIDTH / 2 - endback.width / 2;
	endback.y = GAME_HEIGHT / 2 - endback.height / 2;


	//���S
	strcpy_s(ImageTitleROGO.image.path, IMAGE_TITLE_ROGO_PATH);
	ImageTitleROGO.image.handle = LoadGraph(ImageTitleROGO.image.path);
	if (ImageTitleROGO.image.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_ROGO_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitleROGO.image.handle, &ImageTitleROGO.image.width, &ImageTitleROGO.image.height);
	ImageTitleROGO.image.x = 480;
	ImageTitleROGO.image.y = GAME_HEIGHT / 2;
	ImageTitleROGO.angle = DX_PI * 2;
	ImageTitleROGO.angleMAX = DX_PI * 2;
	ImageTitleROGO.rate = 0;
	ImageTitleROGO.rateMAX = IMAGE_TITLE_ROGO_ROTA_MAX;


	strcpy_s(ImageTitleSTART.image.path, IMAGE_TITLE_START_PATH);
	ImageTitleSTART.image.handle = LoadGraph(ImageTitleSTART.image.path);
	if (ImageTitleSTART.image.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_START_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	GetGraphSize(ImageTitleSTART.image.handle, &ImageTitleSTART.image.width, &ImageTitleSTART.image.height);
	ImageTitleSTART.image.x = GAME_WIDTH / 2 - ImageTitleSTART.image.width / 2;
	ImageTitleSTART.image.y = ImageTitleROGO.image.y + ImageTitleROGO.image.height / 2 + 10;
	ImageTitleSTART.Cnt = 0.0;
	ImageTitleSTART.CntMAX = IMAGE_TITLE_START_CNT_MAX;
	ImageTitleSTART.IsDraw = FALSE;


	strcpy_s(ImageEndCOMP.image.path, IMAGE_END_COMP_PATH);
	ImageEndCOMP.image.handle = LoadGraph(ImageEndCOMP.image.path);
	if (ImageEndCOMP.image.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_END_COMP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndCOMP.image.handle, &ImageEndCOMP.image.width, &ImageEndCOMP.image.height);
	ImageEndCOMP.image.x = GAME_WIDTH / 2 - ImageEndCOMP.image.width / 2;
	ImageEndCOMP.image.y = GAME_HEIGHT / 2 - ImageEndCOMP.image.height / 2;
	ImageEndCOMP.Cnt = 0.0;
	ImageEndCOMP.CntMAX = IMAGE_END_COMP_CNT_MAX;
	ImageEndCOMP.IsDraw = FALSE;

	strcpy_s(ImageEndFAIL.image.path, IMAGE_END_FAIL_PATH);
	ImageEndFAIL.image.handle = LoadGraph(ImageEndFAIL.image.path);
	if (ImageEndFAIL.image.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_END_FAIL_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndFAIL.image.handle, &ImageEndFAIL.image.width, &ImageEndFAIL.image.height);
	ImageEndFAIL.image.x = GAME_WIDTH / 2 - ImageEndFAIL.image.width / 2;
	ImageEndFAIL.image.y = GAME_HEIGHT / 2 - ImageEndFAIL.image.height / 2;
	ImageEndFAIL.Cnt = 0.0;
	ImageEndFAIL.CntMAX = IMAGE_END_FAIL_CNT_MAX;
	ImageEndFAIL.IsDraw = FALSE;


	//�����w�i
	strcpy_s(back1.path, IMAGE_BACK1_PATH);
	back1.handle = LoadGraph(back1.path);
	if (back1.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_BACK1_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(back1.handle, &back1.width, &back1.height);	//�摜�̕��ƍ������擾
	back1.x = GAME_WIDTH / 2 - back1.width / 2;		//���E��������
	back1.y = GAME_HEIGHT / 2 - back1.height / 2;		//�㉺��������



	strcpy_s(ImageBack[0].image.path, IMAGE_BACK_PATH);
	strcpy_s(ImageBack[1].image.path, IMAGE_BACK_REV_PATH);
	strcpy_s(ImageBack[2].image.path, IMAGE_BACK_PATH);
	strcpy_s(ImageBack[3].image.path, IMAGE_BACK_REV_PATH);

	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		ImageBack[num].image.handle = LoadGraph(ImageBack[num].image.path);
		if (ImageBack[num].image.handle == -1)
		{
			MessageBox(GetMainWindowHandle(), IMAGE_BACK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
			return FALSE;
		}

		GetGraphSize(ImageBack[num].image.handle, &ImageBack[num].image.width, &ImageBack[num].image.height);
	}

	ImageBack[0].image.x = 0 - ImageBack[0].image.width * 0;
	ImageBack[0].image.y = GAME_HEIGHT / 2 - ImageBack[0].image.height / 2;
	ImageBack[0].IsDraw = FALSE;

	ImageBack[1].image.x = 0 - ImageBack[0].image.width * 1;
	ImageBack[1].image.y = GAME_HEIGHT / 2 - ImageBack[1].image.height / 2;
	ImageBack[1].IsDraw = FALSE;

	ImageBack[2].image.x = 0 - ImageBack[0].image.width * 2;
	ImageBack[2].image.y = GAME_HEIGHT / 2 - ImageBack[2].image.height / 2;
	ImageBack[2].IsDraw = FALSE;

	ImageBack[3].image.x = 0 - ImageBack[0].image.width * 3;
	ImageBack[3].image.y = GAME_HEIGHT / 2 - ImageBack[3].image.height / 2;
	ImageBack[3].IsDraw = FALSE;


	//�v���C���[�̔z�u
	//strcpy_s(player.image.path, IMAGE_PLAYER_PATH);
	//player.image.handle = LoadGraph(player.image.path);
	//if (player.image.handle == -1)
	//{
	//	MessageBox(GetMainWindowHandle(), IMAGE_PLAYER_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
	//	return FALSE;
	//}
	//GetGraphSize(player.image.handle, &player.image.width, &player.image.height);	//�摜�̕��ƍ������擾
	//player.image.x = GAME_WIDTH / 2 - player.image.width / 2;		//���E��������
	//player.image.y = GAME_HEIGHT / 2 - player.image.height / 2;		//�㉺��������
	//player.CenterX = player.image.x + player.image.width / 2;		//�摜�̉��̒��S��T��
	//player.CenterY = player.image.y + player.image.height / 2;		//�摜�̏c�̒��S��T��
	//player.speed = CHARA_SPEED_LOW;
	//player.IsDraw = TRUE;


	//�v���C���[
	LoadDivGraph(".\\IMAGE\\iroganman.png", 6, 3, 2, 71, 100, player.image.m_handle);

	for (int i = 0; i < 12; i++)
	{
		GetGraphSize(player.image.m_handle[i], &player.image.width, &player.image.height);	//�摜�̕��ƍ������擾
		player.image.x = GAME_WIDTH / 2 - player.image.width / 2;		//���E��������
		player.image.y = GAME_HEIGHT / 2 - player.image.height / 2;		//�㉺��������
		player.CenterX = player.image.x + player.image.width / 2;		//�摜�̉��̒��S��T��
		player.CenterY = player.image.y + player.image.height / 2;		//�摜�̏c�̒��S��T��
	}
	/*player.speed = CHARA_SPEED_LOW;*/
	player.IsDraw = TRUE;



	//�������@�G�@������

	//��ڏ��m
	for (int kazu = 0; kazu < Enemy_Num; kazu++)
	{
		LoadDivGraph(ENEMY_PATH, 4, 4, 1, 80, 80, enemy[kazu].enecolor);

		for (int color = 0; color < 4; color++)
		{
			GetGraphSize(enemy[kazu].enecolor[color], &enemy[kazu].image.width, &enemy[kazu].image.height);
			enemy[kazu].image.IsDraw = FALSE;
		}
	}


	//�q�m�^�}
	for (int kazu = 0; kazu < Enemy_Num; kazu++)
	{
		LoadDivGraph(Enemy_Bomb_PATH, 4, 4, 1, 100, 100, Enemy_Bomb[kazu].enecolor);

		for (int color = 0; color < 4; color++)
		{
			GetGraphSize(Enemy_Bomb[kazu].enecolor[color], &Enemy_Bomb[kazu].image.width, &Enemy_Bomb[kazu].image.height);
			Enemy_Bomb[kazu].image.IsDraw = FALSE;
			Enemy_Bomb[kazu].radian = 0.0;
		}
	}


	//�A�[���}��
	for (int kazu = 0; kazu < Enemy_Num; kazu++)
	{
		LoadDivGraph(Enemy_Ahriman_PATH, 4, 4, 1, 200, 200, Enemy_Ahriman[kazu].enecolor);

		for (int color = 0; color < 4; color++)
		{
			GetGraphSize(Enemy_Ahriman[kazu].enecolor[color], &Enemy_Ahriman[kazu].image.width, &Enemy_Ahriman[kazu].image.height);
		}
		Enemy_Ahriman[kazu].image.IsDraw = TRUE;
	}


	//�o���[��
	for (int kazu = 0; kazu < Enemy_Num; kazu++)
	{
		LoadDivGraph(Enemy_Balor_PATH, 4, 4, 1, 100, 100, Enemy_Balor[kazu].enecolor);

		for (int color = 0; color < 4; color++)
		{
			GetGraphSize(Enemy_Balor[kazu].enecolor[color], &Enemy_Balor[kazu].image.width, &Enemy_Balor[kazu].image.height);
		}
		Enemy_Balor[kazu].image.IsDraw = TRUE;
	}


	//����
	//strcpy_s(enemy3[0].image.path, IMAGE_ENEMY3_PATH);
	//enemy3[0].image.handle = LoadGraph(enemy3[0].image.path);
	//if (enemy3[0].image.handle == -1)
	//{
	//	MessageBox(GetMainWindowHandle(), IMAGE_ENEMY3_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
	//	return FALSE;
	//}
	//GetGraphSize(enemy3[0].image.handle, &enemy3[0].image.width, &enemy3[0].image.height);	//�摜�̕��ƍ������擾

	//enemy3[0].radian = 0.0;
	//enemy3[0].speed = CHARA_SPEED_LOW;
	//enemy3[0].image.IsDraw = TRUE;



	//strcpy_s(enemy4.image.path, IMAGE_ENEMYFIRE_PATH);
	//enemy4.image.handle = LoadGraph(enemy4.image.path);
	//if (enemy4.image.handle == -1)
	//{
	//	MessageBox(GetMainWindowHandle(), IMAGE_ENEMYFIRE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
	//	return FALSE;
	//}
	//GetGraphSize(enemy4.image.handle, &enemy4.image.width, &enemy4.image.height);	//�摜�̕��ƍ������擾

	//enemy4.radian = 0.0;
	//enemy4.speed = CHARA_SPEED_LOW;
	//enemy4.image.IsDraw = FALSE;



	//strcpy_s(enemy5.image.path, IMAGE_ENEMY5_PATH);
	//enemy5.image.handle = LoadGraph(enemy5.image.path);
	//if (enemy5.image.handle == -1)
	//{
	//	MessageBox(GetMainWindowHandle(), IMAGE_ENEMY5_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
	//	return FALSE;
	//}
	//GetGraphSize(enemy5.image.handle, &enemy5.image.width, &enemy5.image.height);	//�摜�̕��ƍ������擾

	//enemy5.radian = 0.0;
	//enemy5.speed = CHARA_SPEED_LOW;
	//enemy5.image.IsDraw = FALSE;


	//�G��
	strcpy_s(syokusyu[0].path, IMAGE_syokusyu_PATH);
	syokusyu[0].handle = LoadGraph(syokusyu[0].path);
	if (syokusyu[0].handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_syokusyu_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(syokusyu[0].handle, &syokusyu[0].width, &syokusyu[0].height);	//�摜�̕��ƍ������擾

	syokusyu[0].radian = 0.0;
	syokusyu[0].IsDraw = FALSE;



	strcpy_s(syokusyu_big[0].path, IMAGE_syokusyubig_PATH);
	syokusyu_big[0].handle = LoadGraph(syokusyu_big[0].path);
	if (syokusyu_big[0].handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_syokusyubig_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(syokusyu_big[0].handle, &syokusyu_big[0].width, &syokusyu_big[0].height);	//�摜�̕��ƍ������擾

	syokusyu_big[0].radian = 0.0;
	syokusyu_big[0].IsDraw = FALSE;



	//�������@�v���C���[HP�@������

	//�n�[�g
	strcpy_s(heart[0].path, IMAGE_HEART_PATH);
	heart[0].handle = LoadGraph(heart[0].path);
	if (heart[0].handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_HEART_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(heart[0].handle, &heart[0].width, &heart[0].height);	//�摜�̕��ƍ������擾

	heart[0].IsDraw = TRUE;




	//�������@�M�~�b�N�@������

	//�ԃG���A�c
	strcpy_s(denger_tate[0].path, IMAGE_DENGER_TATE_PATH);
	denger_tate[0].handle = LoadGraph(denger_tate[0].path);
	if (denger_tate[0].handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_DENGER_TATE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(denger_tate[0].handle, &denger_tate[0].width, &denger_tate[0].height);	//�摜�̕��ƍ������擾
	denger_tate[0].IsDraw = FALSE;


	//�ԃG���A��
	strcpy_s(denger_yoko[0].path, IMAGE_DENGER_YOKO_PATH);
	denger_yoko[0].handle = LoadGraph(denger_yoko[0].path);
	if (denger_yoko[0].handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_DENGER_YOKO_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(denger_yoko[0].handle, &denger_yoko[0].width, &denger_yoko[0].height);	//�摜�̕��ƍ������擾
	denger_yoko[0].IsDraw = FALSE;


	//�΃G���A�c
	strcpy_s(safe_tate[0].path, IMAGE_SAFE_TATE_PATH);
	safe_tate[0].handle = LoadGraph(safe_tate[0].path);
	if (safe_tate[0].handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_SAFE_TATE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(safe_tate[0].handle, &safe_tate[0].width, &safe_tate[0].height);	//�摜�̕��ƍ������擾
	safe_tate[0].IsDraw = FALSE;


	//�΃G���A��

	strcpy_s(safe_yoko[0].path, IMAGE_SAFE_YOKO_PATH);
	safe_yoko[0].handle = LoadGraph(safe_yoko[0].path);
	if (safe_yoko[0].handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_SAFE_YOKO_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(safe_yoko[0].handle, &safe_yoko[0].width, &safe_yoko[0].height);	//�摜�̕��ƍ������擾
	safe_yoko[0].IsDraw = FALSE;



	//�������@���̑��@������

	// �����o��
	strcpy_s(hukidasi[0].path, IMAGE_HUKIDASI_PATH);
	hukidasi[0].handle = LoadGraph(hukidasi[0].path);
	if (hukidasi[0].handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_HUKIDASI_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(hukidasi[0].handle, &hukidasi[0].width, &hukidasi[0].height);
	hukidasi[0].IsDraw = FALSE;



	strcpy_s(hukidasi2.path, IMAGE_HUKIDASI2_PATH);
	hukidasi2.handle = LoadGraph(hukidasi2.path);
	if (hukidasi2.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_HUKIDASI2_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(hukidasi2.handle, &hukidasi2.width, &hukidasi2.height);
	hukidasi2.IsDraw = FALSE;



	strcpy_s(hukidasi3.path, IMAGE_HUKIDASI3_PATH);
	hukidasi3.handle = LoadGraph(hukidasi3.path);
	if (hukidasi3.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_HUKIDASI3_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(hukidasi3.handle, &hukidasi3.width, &hukidasi3.height);
	hukidasi3.IsDraw = FALSE;


	//���
	strcpy_s(yajirusi.path, IMAGE_YAJIRUSI_PATH);
	yajirusi.handle = LoadGraph(yajirusi.path);
	if (yajirusi.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_YAJIRUSI_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(yajirusi.handle, &yajirusi.width, &yajirusi.height);
	yajirusi.IsDraw = FALSE;


	//�e����E�B���h�E
	strcpy_s(tamasousa_gazou.path, TAMASOUSA_WINDOW_PATH);
	tamasousa_gazou.handle = LoadGraph(tamasousa_gazou.path);
	if (tamasousa_gazou.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), TAMASOUSA_WINDOW_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(tamasousa_gazou.handle, &tamasousa_gazou.width, &tamasousa_gazou.height);
	tamasousa_gazou.x = 0;
	tamasousa_gazou.y = 0;


	//�N���X�^��
	for (int i = 0; i < 20; i++)
	{
		crystalhandle[i] = LoadDivGraph(
			IMAGE_YERROWCRYSTAL_PATH, 20, 5, 4, 120, 120, gatehandle);
		GetGraphSize(crystalhandle[i], &y_crystal.width, &y_crystal.height);
	}	
	y_crystal.IsDraw = TRUE;
	y_crystal.width = 120;
	y_crystal.height = 120;



	//�������@�A�C�e���@������

	//�񕜃n�[�g
	strcpy_s(kaihuku.path, IMAGE_KAIHUKU_PATH);
	kaihuku.handle = LoadGraph(kaihuku.path);
	if (kaihuku.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_KAIHUKU_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(kaihuku.handle, &kaihuku.width, &kaihuku.height);
	kaihuku.IsDraw = TRUE;


	//�|�[�V����
	strcpy_s(portion.path, IMAGE_PORTION_PATH);
	portion.handle = LoadGraph(portion.path);
	if (portion.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_PORTION_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(portion.handle, &portion.width, &portion.height);
	portion.IsDraw = TRUE;


	//�Q�[�g
	for (int i = 0; i < 10; i++)
	{
		gatehandle[i] = LoadDivGraph(
			IMAGE_WARP_PATH, 10, 5, 2, 192, 192, gatehandle);
		GetGraphSize(gatehandle[i], &gate[0].width, &gate[0].height);
	}


	//�S�[���Q�[�g
	for (int i = 0; i < 10; i++)
	{
		warphandle[i] = LoadDivGraph(
			GoalGate_PATH, 15, 5, 3, 120, 120, warphandle);
		GetGraphSize(warphandle[i], &warp.width, &warp.height);
	}



	//���F���[�v

	for (int i = 0; i < 10; i++)
	{
		y_warphandle[i] = LoadDivGraph(
			YERROWWARP_PATH, 10, 5, 2, 192, 192, y_warphandle);
		GetGraphSize(y_warphandle[i], &y_warp.width, &y_warp.height);
	}



	//�������@�e�@������

	//�Ԓe�̉摜�𕪊�
	int tamaRedRes = LoadDivGraph(
		TAMA_RED_PATH,
		TAMA_DIV_NUM, TAMA_DIV_TATE, TAMA_DIV_YOKO,
		TAMA_DIV_WIDTH, TAMA_DIV_HEIGHT,
		&player.tama[0].handle[0]);


	if (tamaRedRes == -1)
	{
		MessageBox(GetMainWindowHandle(), TAMA_RED_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	GetGraphSize(player.tama[0].handle[0], &player.tama[0].width, &player.tama[0].height);

	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		strcpyDx(player.tama[cnt].path, TEXT(TAMA_RED_PATH));

		for (int i_num = 0; i_num < TAMA_DIV_NUM; i_num++)
		{
			player.tama[cnt].handle[i_num] = player.tama[0].handle[i_num];
		}

		/*player.tama[cnt].width = player.tama[0].width;

		player.tama[cnt].height = player.tama[0].height;*/

		player.tama[cnt].x = 0;/*player.image.x;*/

		player.tama[cnt].y = 1000/*player.CenterY - player.tama[cnt].width / 2*/;

		player.tama[cnt].IsDraw = FALSE;

		player.tama[cnt].changeImageCnt = 0;

		player.tama[cnt].changeImageCntMAX = TAMA_CHANGE_MAX;

		player.tama[cnt].nowImageKind = 0;

		player.tama[cnt].speed = 4;

	}



	//�Βe�̉摜�𕪊�

	int tamaGreenRes = LoadDivGraph(
		TAMA_GREEN_PATH,
		TAMA_DIV_NUM, TAMA_DIV_TATE, TAMA_DIV_YOKO,
		TAMA_DIV_WIDTH, TAMA_DIV_HEIGHT,
		&player.tama2[0].handle[0]);


	if (tamaGreenRes == -1)
	{
		MessageBox(GetMainWindowHandle(), TAMA_GREEN_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	GetGraphSize(player.tama2[0].handle[0], &player.tama2[0].width, &player.tama2[0].height);

	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		strcpyDx(player.tama2[cnt].path, TEXT(TAMA_GREEN_PATH));

		for (int i_num = 0; i_num < TAMA_DIV_NUM; i_num++)
		{
			player.tama2[cnt].handle[i_num] = player.tama2[0].handle[i_num];
		}

		/*player.tama2[cnt].width = player.tama2[0].width;

		player.tama2[cnt].height = player.tama2[0].height;*/

		player.tama2[cnt].x = 0;

		player.tama2[cnt].y = 1000;

		player.tama2[cnt].IsDraw = FALSE;

		player.tama2[cnt].changeImageCnt = 0;

		player.tama2[cnt].changeImageCntMAX = TAMA_CHANGE_MAX;

		player.tama2[cnt].nowImageKind = 0;

		player.tama2[cnt].speed = CHARA_SPEED_LOW;

	}




	//�e
	int tamaBlueRes = LoadDivGraph(
		TAMA_BLUE_PATH,
		TAMA_DIV_NUM, TAMA_DIV_TATE, TAMA_DIV_YOKO,
		TAMA_DIV_WIDTH, TAMA_DIV_HEIGHT,
		&player.b_tama[0].handle[0]);


	if (tamaBlueRes == -1)
	{
		MessageBox(GetMainWindowHandle(), TAMA_BLUE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	GetGraphSize(player.b_tama[0].handle[0], &player.b_tama[0].width, &player.b_tama[0].height);

	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		strcpyDx(player.b_tama[cnt].path, TEXT(TAMA_BLUE_PATH));

		for (int i_num = 0; i_num < TAMA_DIV_NUM; i_num++)
		{
			player.b_tama[cnt].handle[i_num] = player.b_tama[0].handle[i_num];
		}

		player.b_tama[cnt].x = 0;/*player.image.x;*/

		player.b_tama[cnt].y = 1000/*player.CenterY - player.tama[cnt].width / 2*/;

		player.b_tama[cnt].IsDraw = FALSE;

		player.b_tama[cnt].changeImageCnt = 0;

		player.b_tama[cnt].changeImageCntMAX = TAMA_CHANGE_MAX;

		player.b_tama[cnt].nowImageKind = 0;

		player.b_tama[cnt].speed = CHARA_SPEED_LOW;

	}




	//���e
	int tamaYellowRes = LoadDivGraph(
		TAMA_YELLOW_PATH,
		TAMA_DIV_NUM, TAMA_DIV_TATE, TAMA_DIV_YOKO,
		TAMA_DIV_WIDTH, TAMA_DIV_HEIGHT,
		&player.y_tama[0].handle[0]);


	if (tamaYellowRes == -1)
	{
		MessageBox(GetMainWindowHandle(), TAMA_YELLOW_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	GetGraphSize(player.y_tama[0].handle[0], &player.y_tama[0].width, &player.y_tama[0].height);

	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		strcpyDx(player.y_tama[cnt].path, TEXT(TAMA_YELLOW_PATH));

		for (int i_num = 0; i_num < TAMA_DIV_NUM; i_num++)
		{
			player.y_tama[cnt].handle[i_num] = player.y_tama[0].handle[i_num];
		}

		player.y_tama[cnt].x = 0;/*player.image.x;*/

		player.y_tama[cnt].y = 1000/*player.CenterY - player.tama[cnt].width / 2*/;

		player.y_tama[cnt].IsDraw = FALSE;

		player.y_tama[cnt].changeImageCnt = 0;

		player.y_tama[cnt].changeImageCntMAX = TAMA_CHANGE_MAX;

		player.y_tama[cnt].nowImageKind = 0;

		player.y_tama[cnt].speed = CHARA_SPEED_LOW;

	}


	//�}�b�v�P
	int mapRes = LoadDivGraph(
		GAME_MAP_PATH,
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,
		&mapChip.handle[0]);

	if (mapRes == -1)
	{
		MessageBox(GetMainWindowHandle(), GAME_MAP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	GetGraphSize(mapChip.handle[0], &mapChip.width, &mapChip.height);

	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			mapDataInit[tate][yoko] = mapData[tate][yoko];

			map[tate][yoko].kind = mapData[tate][yoko];

			map[tate][yoko].width = mapChip.width;
			map[tate][yoko].height = mapChip.height;

			map[tate][yoko].x = yoko * map[tate][yoko].width;
			map[tate][yoko].y = tate * map[tate][yoko].height;
		}
	}


	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			mapColl[tate][yoko].left = (yoko + 0) * mapChip.width + 1;
			mapColl[tate][yoko].top = (tate + 0) * mapChip.height + 1;
			mapColl[tate][yoko].right = (yoko + 1) * mapChip.width - 1;
			mapColl[tate][yoko].bottom = (tate + 1) * mapChip.height - 1;

		}
	}


	return TRUE;
}



//�摜�폜

VOID MY_DELETE_IMAGE(VOID)
{
	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		DeleteGraph(ImageBack[0].image.handle);
	}

	DeleteGraph(player.image.handle);

	/*DeleteGraph(enemy.image.handle);
	DeleteGraph(Enemy_Bomb.image.handle);*/

	/*DeleteGraph(enemy4.image.handle);
	DeleteGraph(enemy5.image.handle);*/
	DeleteGraph(goalgazou.handle);
	DeleteGraph(ImageTitleROGO.image.handle);
	DeleteGraph(ImageTitleSTART.image.handle);


	DeleteGraph(ImageEndCOMP.image.handle);
	DeleteGraph(ImageEndFAIL.image.handle);

	DeleteGraph(y_crystal.handle);
	DeleteGraph(kaihuku.handle);
	DeleteGraph(portion.handle);



	for (int i = 0; i < HUKIDASI_NUM; i++)
	{
		DeleteGraph(hukidasi[i].handle);
	}

	DeleteGraph(hukidasi2.handle);
	DeleteGraph(hukidasi3.handle);
	DeleteGraph(yajirusi.handle);
	DeleteGraph(tamasousa_gazou.handle);


	for (int i = 0; i < SHOKUSHU_NUM; i++)
	{
		DeleteGraph(syokusyu[i].handle);
	}

	for (int i = 0; i < SHOKUSHU_NUM; i++)
	{
		DeleteGraph(syokusyu_big[i].handle);
	}

	for (int i = 0; i < HEART_NUM; i++)
	{
		DeleteGraph(heart[i].handle);
	}


	for (int i = 0; i < Enemy_Num; i++)
	{
		DeleteGraph(Enemy_Balor[i].image.handle);
	}



	for (int i = 0; i < DENGER_TATE_NUM; i++)
	{
		DeleteGraph(denger_tate[i].handle);
	}

	for (int i = 0; i < DENGER_YOKO_NUM; i++)
	{
		DeleteGraph(denger_yoko[i].handle);
	}

	for (int i = 0; i < SAFE_TATE_NUM; i++)
	{
		DeleteGraph(safe_tate[i].handle);
	}

	for (int i = 0; i < SAFE_YOKO_NUM; i++)
	{
		DeleteGraph(safe_yoko[i].handle);
	}







	for (int i_num = 0; i_num < TAMA_DIV_NUM; i_num++) { DeleteGraph(player.tama[0].handle[i_num]); }
	for (int i_num = 0; i_num < TAMA_DIV_NUM; i_num++) { DeleteGraph(player.b_tama[0].handle[i_num]); }
	for (int i_num = 0; i_num < TAMA_DIV_NUM; i_num++) { DeleteGraph(player.y_tama[0].handle[i_num]); }
	for (int i_num = 0; i_num < TAMA_DIV_NUM; i_num++) { DeleteGraph(player.tama2[0].handle[i_num]); }


	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip.handle[i_num]); }


	/*DeleteGraph(STARTBACK.handle);*/

	return;
}


//���y

BOOL MY_LOAD_MUSIC(VOID)
{
	strcpy_s(BGM.path, MUSIC_BGM_PATH);
	BGM.handle = LoadSoundMem(BGM.path);
	if (BGM.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(STARTBGM.path, MUSIC_STARTBGM_PATH);
	STARTBGM.handle = LoadSoundMem(STARTBGM.path);
	if (STARTBGM.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_STARTBGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(ENDBGM.path, MUSIC_ENDBGM_PATH);
	ENDBGM.handle = LoadSoundMem(ENDBGM.path);
	if (ENDBGM.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_ENDBGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}


	strcpy_s(gameover.path, MUSIC_GAMEOVER_PATH);
	gameover.handle = LoadSoundMem(gameover.path);
	if (gameover.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_GAMEOVER_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(gekiha.path, MUSIC_GEKIHA_PATH);
	gekiha.handle = LoadSoundMem(gekiha.path);
	if (gekiha.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_GEKIHA_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}


	strcpy_s(kaihuku_oto.path, MUSIC_KAIHUKU_PATH);
	kaihuku_oto.handle = LoadSoundMem(kaihuku_oto.path);
	if (kaihuku_oto.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_KAIHUKU_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}


	strcpy_s(hakai.path, MUSIC_HAKAI_PATH);
	hakai.handle = LoadSoundMem(hakai.path);
	if (hakai.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_HAKAI_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}


	strcpy_s(syokusyu_oto.path, MUSIC_SYOKUSYU_PATH);
	syokusyu_oto.handle = LoadSoundMem(syokusyu_oto.path);
	if (syokusyu_oto.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_SYOKUSYU_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}


	strcpy_s(damage.path, MUSIC_DAMAGE_PATH);
	damage.handle = LoadSoundMem(damage.path);
	if (damage.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_DAMAGE_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}


	strcpy_s(player.musicShot.path, MUSIC_PLAYER_SHOT_PATH);
	player.musicShot.handle = LoadSoundMem(player.musicShot.path);
	if (player.musicShot.handle == -1)
	{

		MessageBox(GetMainWindowHandle(), MUSIC_PLAYER_SHOT_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}


	strcpy_s(player.greenshot.path, MUSIC_GREEN_SHOT_PATH);
	player.greenshot.handle = LoadSoundMem(player.greenshot.path);
	if (player.greenshot.handle == -1)
	{

		MessageBox(GetMainWindowHandle(), MUSIC_PLAYER_SHOT_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}


	strcpy_s(ENTER.path, MUSIC_ENTER_PATH);
	ENTER.handle = LoadSoundMem(ENTER.path);
	if (ENTER.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_ENTER_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(menu.path, MUSIC_MENU_PATH);
	menu.handle = LoadSoundMem(menu.path);
	if (menu.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_MENU_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(menuyes.path, MUSIC_MENUYES_PATH);
	menuyes.handle = LoadSoundMem(menuyes.path);
	if (menuyes.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_MENUYES_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(menuno.path, MUSIC_MENUNO_PATH);
	menuno.handle = LoadSoundMem(menuno.path);
	if (menuno.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_MENUNO_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	strcpy_s(goal.path, MUSIC_GOAL_PATH);
	goal.handle = LoadSoundMem(goal.path);
	if (goal.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_GOAL_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	/*strcpy_s(voice_ei.path, MUSIC_VOICE_PATH);
	voice_ei.handle = LoadSoundMem(voice_ei.path);
	if (voice_ei.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_VOICE_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}*/

	return TRUE;
}

VOID MY_DELETE_MUSIC(VOID)
{
	DeleteSoundMem(BGM.handle);
	DeleteSoundMem(STARTBGM.handle);
	DeleteSoundMem(ENDBGM.handle);
	DeleteSoundMem(player.musicShot.handle);
	DeleteSoundMem(player.greenshot.handle);
	DeleteSoundMem(ENTER.handle);
	DeleteSoundMem(menu.handle);
	DeleteSoundMem(menuyes.handle);
	DeleteSoundMem(menuno.handle);
	DeleteSoundMem(goal.handle);
	DeleteSoundMem(gameover.handle);
	DeleteSoundMem(gekiha.handle);
	DeleteSoundMem(kaihuku_oto.handle);
	DeleteSoundMem(damage.handle);
	DeleteSoundMem(syokusyu_oto.handle);
	DeleteSoundMem(hakai.handle);

	return;
}


//�}�b�v�ƃv���C���[�̓����蔻�������֐�

BOOL MY_CHECK_MAP1_PLAYER_COLL(RECT player)
{
	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			if (MY_CHECK_RECT_COLL(player, mapColl[tate][yoko]) == TRUE)
			{
				if (GameScene == GAME_SCENE_PLAY)
				{
					if (map[tate][yoko].kind == k)
					{
						return TRUE;
					}
				}
				else if (GameScene == GAME_SCENE_PLAY2 || GameScene == GAME_SCENE_PLAY0 || GameScene == GAME_SCENE_RED)
				{
					if (map[tate][yoko].kind == k)
					{
						return FALSE;
					}
				}

			}
		}
	}

	return FALSE;
}



//�̈�̓����蔻��
BOOL MY_CHECK_RECT_COLL(RECT a, RECT b)
{

	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top)
	{
		if (Ishit == TRUE)
		{
			return TRUE;
		}

	}

	return FALSE;

}