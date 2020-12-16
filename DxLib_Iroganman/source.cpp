#include "DxLib.h"
#include <math.h>
#include "resource1.h"


#define GAME_WIDTH			960
#define GAME_HEIGHT			640
#define GAME_COLOR			32	

#define GAME_HANKEI			200

#define GAME_WINDOW_BAR		0	
#define GAME_WINDOW_NAME	"イロガンマン"	

#define GAME_FPS			60	


#define MOUSE_BUTTON_CODE	129		


#define PATH_MAX			255	
#define NAME_MAX			255	


#define IMAGE_LOAD_ERR_TITLE	TEXT("画像読み込みエラー")

#define IMAGE_BACK_PATH			TEXT(".\\IMAGE\\utyu.png")
#define IMAGE_BACK_REV_PATH	TEXT(".\\IMAGE\\utyu.png")
#define IMAGE_BACK_NUM	4

#define IMAGE_BACK1_PATH		TEXT(".\\IMAGE\\utyu.png")



#define IMAGE_ENDBACK_PATH		TEXT(".\\IMAGE\\OIPNODBZ5LM.png")

#define IMAGE_PLAYER_PATH		TEXT(".\\IMAGE\\player.png")	


//敵
#define IMAGE_ENEMY_PATH		TEXT(".\\IMAGE\\hitome_red.png")	
#define IMAGE_ENEMY2_PATH		TEXT(".\\IMAGE\\enemy2.png")
#define IMAGE_ENEMY3_PATH		TEXT(".\\IMAGE\\pipo-enemy025a.png")
#define IMAGE_ENEMY4_PATH		TEXT(".\\IMAGE\\pipo-enemy040b.png")
#define IMAGE_ENEMY5_PATH		TEXT(".\\IMAGE\\pipo-enemy039.png")

#define IMAGE_syokusyu_PATH		TEXT(".\\IMAGE\\MAP2\\shokushu.png")
#define SHOKUSHU_NUM			5


//ハート
#define IMAGE_HEART_PATH		TEXT(".\\IMAGE\\heart_red.png")
#define HEART_NUM				3


//ギミック
#define IMAGE_WARP_PATH			TEXT(".\\IMAGE\\warp.png")

#define IMAGE_HUKIDASI_PATH		TEXT(".\\IMAGE\\吹き出し.png")
#define IMAGE_HUKIDASI2_PATH		TEXT(".\\IMAGE\\吹き出し２.png")
#define IMAGE_HUKIDASI3_PATH		TEXT(".\\IMAGE\\MAP2\\window2.png")


#define IMAGE_DENGER_TATE_PATH		TEXT(".\\IMAGE\\MAP2\\denger.tate.png")
#define IMAGE_DENGER_YOKO_PATH		TEXT(".\\IMAGE\\MAP2\\denger.yoko.png")
#define DENGER_TATE_NUM				5
#define DENGER_YOKO_NUM				5

#define IMAGE_SAFE_TATE_PATH			TEXT(".\\IMAGE\\MAP2\\safe.tate.png")
#define IMAGE_SAFE_YOKO_PATH			TEXT(".\\IMAGE\\MAP2\\safe.yoko.png")
#define SAFE_TATE_NUM				5
#define SAFE_YOKO_NUM				5





#define IMAGE_GOAL_PATH			TEXT(".\\IMAGE\\takara.png")




#define IMAGE_TITLE_BK_PATH		TEXT(".\\IMAGE\\pipo-battlebg020.png")
#define IMAGE_TITLE_ROGO_PATH	TEXT(".\\IMAGE\\titlerogo.png")
#define IMAGE_TITLE_ROGO_ROTA	0.005
#define IMAGE_TITLE_ROGO_ROTA_MAX	1.0
#define IMAGE_TITLE_ROGO_X_SPEED	1
#define IMAGE_TITLE_START_PATH	TEXT(".\\IMAGE\\title_start.png")
#define IMAGE_TITLE_START_CNT	1
#define IMAGE_TITLE_START_CNT_MAX	30


#define IMAGE_END_COMP_PATH		TEXT(".\\IMAGE\\mission_complete.png")
#define IMAGE_END_COMP_CNT		1
#define IMAGE_END_COMP_CNT_MAX	30

#define IMAGE_END_FAIL_PATH		TEXT(".\\IMAGE\\mission_failed.png")
#define IMAGE_END_FAIL_CNT	1
#define IMAGE_END_FAIL_CNT_MAX	30








#define TAMA_CHANGE_MAX 5
#define TAMA_MAX 16

#define TAMA_RED_PATH		TEXT(".\\IMAGE\\TAMA\\red.png")
#define TAMA_GREEN_PATH		TEXT(".\\IMAGE\\TAMA\\green.png")
#define TAMA_BRUE_PATH		TEXT(".\\IMAGE\\TAMA\\blue.png")
#define TAMA_YELLOW_PATH		TEXT(".\\IMAGE\\TAMA\\yellow.png")

#define TAMA_DIV_WIDTH		16
#define TAMA_DIV_HEIGHT		16

#define TAMA_DIV_TATE		3
#define TAMA_DIV_YOKO		1

#define TAMA_DIV_NUM	TAMA_DIV_TATE*TAMA_DIV_YOKO


#define MUSIC_LOAD_ERR_TITLE	TEXT("音楽読み込みエラー")


#define MUSIC_BGM_PATH			TEXT(".\\MUSIC\\game_maoudamashii_1_battle36.mp3")
#define MUSIC_STARTBGM_PATH		TEXT(".\\MUSIC\\game_maoudamashii_5_town18.mp3")
#define MUSIC_ENDBGM_PATH		TEXT(".\\MUSIC\\game_maoudamashii_7_event37.mp3")
#define MUSIC_PLAYER_SHOT_PATH	TEXT(".\\MUSIC\\se_maoudamashii_explosion06.mp3")
#define MUSIC_GREEN_SHOT_PATH	TEXT(".\\MUSIC\\se_zuzaan.mp3")
#define MUSIC_ENTER_PATH		TEXT(".\\MUSIC\\coin03.mp3")
#define MUSIC_MENU_PATH			TEXT(".\\MUSIC\\poka01.mp3")
#define MUSIC_MENUYES_PATH			TEXT(".\\MUSIC\\select03.mp3")
#define MUSIC_MENUNO_PATH			TEXT(".\\MUSIC\\select02.mp3")
#define MUSIC_GOAL_PATH			TEXT(".\\MUSIC\\jump02.mp3")
#define MUSIC_GAMEOVER_PATH		TEXT(".\\MUSIC\\requiem2.mp3")
#define MUSIC_VOICE_PATH		TEXT(".\\MUSIC\\line-girl1-ei1.mp3")
#define MUSIC_VOICE2_PATH		TEXT(".\\MUSIC\\line-girl1-yaa2.mp3")
#define MUSIC_GEKIHA_PATH		TEXT(".\\MUSIC\\monster5.mp3")


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




#define START_ERR_TITLE	TEXT("スタート位置エラー")
#define START_ERR_CAPTION	TEXT("スタート位置が決まっていません")



#define GOAL_ERR_TITLE	TEXT("ゴール位置エラー")
#define GOAL_ERR_CAPTION	TEXT("ゴール位置が決まっていません")



#define MOUSE_R_CLICK_TITLE	TEXT("ゲーム中断")
#define MOUSE_R_CLICK_CAPTION	TEXT("ゲームを中断し、タイトル画面に戻りますか？")






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
	GAME_SCENE_PLAY,
	GAME_SCENE_PLAY2,
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
	int x;
	int y;
	int width;
	int height;
	double radian;
	BOOL IsDraw;
}IMAGE;


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

	/*int CenterX;
	int CenterY;*/
	//RECT coll;	//当たり判定
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
	RECT coll;					//当たり判定
	iPOINT collBeforePt;		//当たる前の座標
}TAMA;




typedef struct STRUCT_CHARA
{
	IMAGE image;
	BOOL IsDraw;
	int speed;
	int CenterX;
	int CenterY;


	MUSIC musicShot;
	MUSIC greenshot;

	BOOL CanShot;
	int ShotReLoadCnt;
	int ShotReLoadCntMAX;


	TAMA tama[TAMA_MAX];
	TAMA tama2[TAMA_MAX];


	RECT coll;
	iPOINT collBeforePt;

	BOOL IsMuteki;
	BOOL Ishit = FALSE;


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


//追加
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
//追加ここまで



int StartTimeFps;
int CountFps;
float CalcFps;
int SampleNumFps = GAME_FPS;

char AllKeyState[256] = { '\0' };
char OldAllKeyState[256] = { '\0' };

MOUSE mouse;

int GameScene;



int GameEndKind;


int enemycount;
int mutekicount = 0.0;
int map1count = 0.0;
int warphandle[10];



int heartnow = 2;



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

ENEMY enemy;
ENEMY enemy2;
ENEMY enemy3;
ENEMY enemy4;
ENEMY enemy5;

IMAGE syokusyu[SHOKUSHU_NUM];

IMAGE heart[HEART_NUM];

IMAGE denger_tate[DENGER_TATE_NUM];
IMAGE denger_yoko[DENGER_YOKO_NUM];

IMAGE safe_tate[SAFE_TATE_NUM];
IMAGE safe_yoko[SAFE_YOKO_NUM];

IMAGE gategazou;
IMAGE goalgazou;
IMAGE warp;
IMAGE hukidasi;
IMAGE hukidasi2;
IMAGE hukidasi3;

TAMA tama;

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
MUSIC voice_ei;
MUSIC voice_make;
MUSIC gekiha;


GAME_MAP_KIND mapData[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX]{
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,
	k,t,t,t,t,t,t,t,t,t,t,t,t,t,k,
	k,t,k,k,k,t,t,t,t,k,k,k,t,t,k,
	t,t,k,t,t,k,t,t,t,k,t,k,t,t,k,
	k,t,t,t,k,k,k,s,t,k,t,t,t,t,k,
	k,k,k,k,k,k,k,t,t,k,k,k,k,k,k,
	k,t,t,t,t,t,t,t,t,t,k,t,t,t,k,
	k,t,t,k,k,k,k,k,k,k,k,t,t,t,k,
	k,t,t,t,t,t,t,t,t,t,t,t,t,t,k,
	k,k,k,k,k,k,k,k,k,k,k,k,t,k,k

};

GAME_MAP_KIND mapDataInit[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

MAPCHIP mapChip;

MAP map[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

iPOINT startPt{ -1,-1 };


RECT mapColl[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];




//追加
GAME_MAP_KIND mapData2[GAME_MAP2_TATE_MAX][GAME_MAP2_YOKO_MAX]{
	k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,
	k,t,t,t,t,k,t,t,t,t,t,t,t,t,k,
	k,t,t,t,t,k,t,t,k,t,k,k,t,t,k,
	s,t,t,t,t,k,t,t,t,t,t,t,t,t,k,
	k,t,t,t,t,k,k,k,t,t,t,t,t,t,k,
	k,t,t,t,t,t,t,t,t,t,t,t,k,k,k,
	k,t,t,t,t,t,t,t,k,t,t,t,t,t,k,
	k,t,t,t,t,t,t,t,k,t,t,t,t,t,k,
	k,k,k,k,k,k,k,k,k,t,k,k,k,k,k
};

GAME_MAP_KIND mapData2Init[GAME_MAP2_TATE_MAX][GAME_MAP2_YOKO_MAX];

MAPCHIP2 mapChip2;

MAP2 map2[GAME_MAP2_TATE_MAX][GAME_MAP2_YOKO_MAX];

iPOINT startPt2{ -1,-1 };


//RECT mapColl[GAME_MAP2_TATE_MAX][GAME_MAP2_YOKO_MAX];
//追加ここまで



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
	int PlayerDamageCounter = 0;


	if (DxLib_Init() == -1) { return -1; }

	if (MY_LOAD_IMAGE() == FALSE) { return -1; }
	if (MY_LOAD_MUSIC() == FALSE) { return -1; }


	

	player.CanShot = TRUE;
	player.ShotReLoadCnt = 0;
	player.ShotReLoadCntMAX = CHARA_RELOAD_LOW;


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



	for (int tate = 0; tate < GAME_MAP2_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP2_YOKO_MAX; yoko++)
		{
			if (mapData2[tate][yoko] == s)
			{
				startPt2.x = mapChip2.width * yoko + mapChip2.width / 2;
				startPt2.y = mapChip2.height * tate + mapChip2.height / 2;
			}

		}
	}


	/////ここまで/////



	/*for (int tate = 0; tate < GAME_ENEMY_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_ENEMY_YOKO_MAX; yoko++)
		{
			EnemyRect.left = enemy.width * yoko;
			EnemyRect.top = enemy.width * tate;
			EnemyRect.right = enemy.width * (yoko + 1);
			EnemyRect.bottom = enemy.height * (tate + 1);
		}
	}*/

	if (startPt.x == -1 && startPt.y == -1)
	{
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION, START_ERR_TITLE, MB_OK); return -1;
	}


	/*if (GoalRect.left == -1)
	{
		MessageBox(GetMainWindowHandle(), GOAL_ERR_CAPTION, GOAL_ERR_TITLE, MB_OK); return -1;
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


	if ((mouse.InputValue & MOUSE_INPUT_LEFT) == MOUSE_INPUT_LEFT) { mouse.Button[MOUSE_INPUT_LEFT]++; }		//押している
	if ((mouse.InputValue & MOUSE_INPUT_LEFT) != MOUSE_INPUT_LEFT) { mouse.Button[MOUSE_INPUT_LEFT] = 0; }		//押していない


	if ((mouse.InputValue & MOUSE_INPUT_MIDDLE) == MOUSE_INPUT_MIDDLE) { mouse.Button[MOUSE_INPUT_MIDDLE]++; }	//押している
	if ((mouse.InputValue & MOUSE_INPUT_MIDDLE) != MOUSE_INPUT_MIDDLE) { mouse.Button[MOUSE_INPUT_MIDDLE] = 0; }	//押していない


	if ((mouse.InputValue & MOUSE_INPUT_RIGHT) == MOUSE_INPUT_RIGHT) { mouse.Button[MOUSE_INPUT_RIGHT]++; }		//押している
	if ((mouse.InputValue & MOUSE_INPUT_RIGHT) != MOUSE_INPUT_RIGHT) { mouse.Button[MOUSE_INPUT_RIGHT] = 0; }	//押していない


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


	//タイトルBGMを流す
	if (CheckSoundMem(STARTBGM.handle) == 0)
	{
		ChangeVolumeSoundMem(255 * 70 / 100, STARTBGM.handle);	//50%の音量にする


		PlaySoundMem(STARTBGM.handle, DX_PLAYTYPE_LOOP);
	}

	//エンターキー入力時、プレイシーンへ遷移
	if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
	{
		if (CheckSoundMem(STARTBGM.handle) != 0)
		{
			StopSoundMem(STARTBGM.handle);	//BGMを止める
		}

		MessageBox(NULL, TEXT("赤弾を上に放つ→キーボード１\n緑弾を左に放つ→キーボード２"), TEXT("操作説明"), MB_OK);

		SetMouseDispFlag(FALSE);

		player.CenterX = startPt.x;
		player.CenterY = startPt.y;

		player.image.x = player.CenterX;
		player.image.y = player.CenterY;

		player.collBeforePt.x = player.CenterX;
		player.collBeforePt.y = player.CenterY;


		/*SetMousePoint(player.image.x, player.image.y);*/


		for (int cnt = 0; cnt < TAMA_MAX; cnt++)
		{
			player.tama[cnt].IsDraw = FALSE;
			player.tama2[cnt].IsDraw = FALSE;
		}



		GameEndKind = GAME_END_FAIL;

		GameScene = GAME_SCENE_PLAY;

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

	DrawString(0, 0, "スタート画面(エンターキーを押して下さい)", GetColor(255, 255, 255));

	return;
}



//マップ１
VOID MY_PLAY(VOID)
{
	MY_PLAY_PROC();
	MY_PLAY_DRAW();

	return;
}


VOID MY_PLAY_PROC(VOID)
{

	/*map1count++;

	int a = map1count % 40 / 10;

	if (a == 10)
	{
		a = 0;
	}*/


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


	//プレイヤーの速度&キー操作設定

	player.speed = 2;
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


	//マップとプレイヤーの当たり判定設定
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


	//当たり判定の範囲設定
	RECT PlayerRect;
	int CollRange = 2;
	PlayerRect.left = player.image.x + player.image.width / 2 - CollRange;
	PlayerRect.top = player.image.y + player.image.height / 2 - CollRange;
	PlayerRect.right = player.image.x + player.image.width / 2 + CollRange;
	PlayerRect.bottom = player.image.y + player.image.height / 2 + CollRange;


	RECT EnemyRect;
	EnemyRect.left = enemy.image.x;
	EnemyRect.top = enemy.image.y;
	EnemyRect.right = enemy.image.x + enemy.image.width;
	EnemyRect.bottom = enemy.image.y + enemy.image.height;


	RECT Enemy2Rect;
	Enemy2Rect.left = enemy2.image.x;
	Enemy2Rect.top = enemy2.image.y;
	Enemy2Rect.right = enemy2.image.x + enemy2.image.width;
	Enemy2Rect.bottom = enemy2.image.y + enemy2.image.height;


	RECT Enemy3Rect;
	Enemy3Rect.left = enemy3.image.x;
	Enemy3Rect.top = enemy3.image.y;
	Enemy3Rect.right = enemy3.image.x + enemy3.image.width;
	Enemy3Rect.bottom = enemy3.image.y + enemy3.image.height;


	RECT Enemy4Rect;
	Enemy4Rect.left = enemy4.image.x;
	Enemy4Rect.top = enemy4.image.y;
	Enemy4Rect.right = enemy4.image.x + enemy4.image.width;
	Enemy4Rect.bottom = enemy4.image.y + enemy4.image.height;


	RECT Enemy5Rect;
	Enemy5Rect.left = enemy5.image.x;
	Enemy5Rect.top = enemy5.image.y;
	Enemy5Rect.right = enemy5.image.x + enemy5.image.width;
	Enemy5Rect.bottom = enemy5.image.y + enemy5.image.height;



	RECT TamaRect;
	TamaRect.left = tama.x + 10;
	TamaRect.top = tama.y + 10;
	TamaRect.right = tama.x + tama.width - 10;
	TamaRect.bottom = tama.y + tama.height - 10;

	RECT GoalRect2;
	GoalRect2.left = goalgazou.x;
	GoalRect2.top = goalgazou.y;
	GoalRect2.right = goalgazou.x + goalgazou.width;
	GoalRect2.bottom = goalgazou.y + goalgazou.height;


	RECT GateRect;
	GateRect.left = warp.x;
	GateRect.top = warp.y;
	GateRect.right = warp.x + warp.width;
	GateRect.bottom = warp.y + warp.height;


	

	//ゴールの接触チェック
	/*if (MY_CHECK_RECT_COLL(PlayerRect, GoalRect) == TRUE)
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
	}*/



	if (MY_CHECK_RECT_COLL(PlayerRect, GateRect) == TRUE)
	{
		hukidasi.IsDraw = TRUE;


		//閉まった扉を調べる
		if (MY_KEY_DOWN(KEY_INPUT_SPACE) == TRUE)
		{
			hukidasi2.IsDraw = TRUE;

		}
		else if (hukidasi2.IsDraw == TRUE)
		{
			if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
			{
				hukidasi2.IsDraw = FALSE;
			}
		}

		if (MY_KEY_DOWN(KEY_INPUT_ESCAPE) == TRUE)
		{
			player.CenterX = 700;
			player.CenterY = 300;

			player.image.x = player.CenterX;
			player.image.y = player.CenterY;

			for (int i = 0; i < SHOKUSHU_NUM; i++)
			{
				syokusyu[i] = syokusyu[0];

				syokusyu[0].x = 900;
				syokusyu[0].y = 400;

				syokusyu[1].x = 900;
				syokusyu[1].y = 100;

			}

			for (int i = 0; i < DENGER_YOKO_NUM; i++)
			{
				denger_yoko[i] = denger_yoko[0];

				denger_yoko[0].x = 0;
				denger_yoko[0].y = 400;

				denger_yoko[1].x = 0;
				denger_yoko[1].y = 100;

			}

			GameScene = GAME_SCENE_PLAY2;

			return;
		}
		
	}


	else {
		hukidasi.IsDraw = FALSE;
	}


	if (hukidasi2.IsDraw == TRUE)
	{
		if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
		{
			hukidasi2.IsDraw = FALSE;
		}
	}




	//敵1の接触チェック


	if (MY_CHECK_RECT_COLL(PlayerRect, EnemyRect) == TRUE)
	{	
		player.IsMuteki = TRUE;

		for (int i = 0; i < HEART_NUM; i++)
		{
			heart[i].IsDraw = FALSE;

		}
		
	}


	////敵２の接触チェック
	//if (MY_CHECK_RECT_COLL(PlayerRect, Enemy2Rect) == TRUE)
	//{
	//	if (CheckSoundMem(BGM.handle) != 0)
	//	{
	//		StopSoundMem(BGM.handle);
	//	}

	//	GameEndKind = GAME_END_FAIL;	//ミッションフォールト！

	//	GameScene = GAME_SCENE_END;

	//	return;	//強制的にエンド画面に飛ぶ

	//}


	////敵３の接触チェック
	//if (MY_CHECK_RECT_COLL(PlayerRect, Enemy3Rect) == TRUE)
	//{
	//	if (CheckSoundMem(BGM.handle) != 0)
	//	{
	//		StopSoundMem(BGM.handle);
	//	}

	//	GameEndKind = GAME_END_FAIL;	//ミッションフォールト！

	//	GameScene = GAME_SCENE_END;

	//	return;	//強制的にエンド画面に飛ぶ

	//}



	////敵４の接触チェック
	//if (MY_CHECK_RECT_COLL(PlayerRect, Enemy4Rect) == TRUE)
	//{
	//	if (CheckSoundMem(BGM.handle) != 0)
	//	{
	//		StopSoundMem(BGM.handle);
	//	}

	//	GameEndKind = GAME_END_FAIL;	//ミッションフォールト！

	//	GameScene = GAME_SCENE_END;

	//	return;	//強制的にエンド画面に飛ぶ

	//}



	////敵５の接触チェック
	//if (MY_CHECK_RECT_COLL(PlayerRect, Enemy5Rect) == TRUE)
	//{
	//	if (CheckSoundMem(BGM.handle) != 0)
	//	{
	//		StopSoundMem(BGM.handle);
	//	}

	//	GameEndKind = GAME_END_FAIL;	//ミッションフォールト！

	//	GameScene = GAME_SCENE_END;

	//	return;	//強制的にエンド画面に飛ぶ

	//}


	if (MY_CHECK_RECT_COLL(PlayerRect, GoalRect2) == TRUE)
	{
		if (CheckSoundMem(BGM.handle) != 0)
		{
			StopSoundMem(BGM.handle);
		}

		GameEndKind = GAME_END_COMP;

		GameScene = GAME_SCENE_END;

		return;	//強制的にエンド画面に飛ぶ
	}



	//プレイヤーが画面外に出たら
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


	//左に赤弾を発射
	if (MY_KEY_DOWN(KEY_INPUT_1) == TRUE)
	{
		if (player.CanShot == TRUE)
		{
			PlaySoundMem(player.musicShot.handle, DX_PLAYTYPE_BACK);
			player.CanShot = FALSE;


			for (int cnt = 0; cnt < TAMA_MAX; cnt++)
			{
				if (player.tama[cnt].IsDraw == FALSE)
				{
					player.tama[cnt].y = player.CenterY - player.tama[cnt].height / 2;

					player.tama[cnt].x = player.image.x;

					player.tama[cnt].IsDraw = TRUE;

					break;
				}

			}
		}
	}



	//左に緑弾を発射
	if (MY_KEY_DOWN(KEY_INPUT_2) == TRUE)
	{
		if (player.CanShot == TRUE)
		{
			PlaySoundMem(player.greenshot.handle, DX_PLAYTYPE_BACK);
			player.CanShot = FALSE;


			for (int cnt = 0; cnt < TAMA_MAX; cnt++)
			{
				if (player.tama2[cnt].IsDraw == FALSE)
				{

					player.tama2[cnt].y = player.CenterY - player.tama2[cnt].height / 2;

					player.tama2[cnt].x = player.image.x;

					player.tama2[cnt].IsDraw = TRUE;

					break;
				}
			}


		}
	}


	//敵１と赤弾の当たり判定
	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{

		if (((player.tama[cnt].x > enemy.image.x && player.tama[cnt].x < enemy.image.x + enemy.image.width) ||
			(enemy.image.x > player.tama[cnt].x && enemy.image.x < player.tama[cnt].x + player.tama[cnt].width)) &&
			((player.tama[cnt].y > enemy.image.y && player.tama[cnt].y < enemy.image.y + enemy.image.height) ||
				(enemy.image.y > player.tama[cnt].y && enemy.image.y < player.tama[cnt].y + player.tama[cnt].height)))
		{

			player.tama[cnt].IsDraw = FALSE;

			PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

			enemy.image.handle = FALSE;
			enemy.image.width = FALSE;
			enemy.image.height = FALSE;
			enemy.image.x = FALSE;
			enemy.image.y = FALSE;

			/*break;*/
		}

		

	}


	////敵２と弾２の当たり判定
	//for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	//{

	//	if (((player.tama2[cnt].x > enemy2.image.x && player.tama2[cnt].x < enemy2.image.x + enemy2.image.width) ||
	//		(enemy2.image.x > player.tama2[cnt].x && enemy2.image.x < player.tama2[cnt].x + player.tama2[cnt].width)) &&
	//		((player.tama2[cnt].y > enemy2.image.y && player.tama2[cnt].y < enemy2.image.y + enemy2.image.height) ||
	//			(enemy2.image.y > player.tama2[cnt].y && enemy2.image.y < player.tama2[cnt].y + player.tama2[cnt].height)))
	//	{

	//		player.tama2[cnt].IsDraw = FALSE;

	//		PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

	//		enemy2.image.IsDraw = FALSE;
	//		enemy2.image.width = FALSE;
	//		enemy2.image.height = FALSE;
	//		enemy2.image.x = FALSE;
	//		enemy2.image.y = FALSE;

	//		break;
	//	}

	//}


	////敵４と緑弾の当たり判定
	//for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	//{

	//	if (((player.tama2[cnt].x > enemy4.image.x && player.tama2[cnt].x < enemy4.image.x + enemy4.image.width) ||
	//		(enemy4.image.x > player.tama2[cnt].x && enemy4.image.x < player.tama2[cnt].x + player.tama2[cnt].width)) &&
	//		((player.tama2[cnt].y > enemy4.image.y && player.tama2[cnt].y < enemy4.image.y + enemy4.image.height) ||
	//			(enemy4.image.y > player.tama2[cnt].y && enemy4.image.y < player.tama2[cnt].y + player.tama2[cnt].height)))
	//	{

	//		player.tama2[cnt].IsDraw = FALSE;

	//		PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

	//		enemy4.image.IsDraw = FALSE;
	//		enemy4.image.width = FALSE;
	//		enemy4.image.height = FALSE;
	//		enemy4.image.x = FALSE;
	//		enemy4.image.y = FALSE;

	//		break;
	//	}


	//	//敵３と赤弾の当たり判定
	//	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	//	{

	//		if (((player.tama[cnt].x > enemy3.image.x && player.tama[cnt].x < enemy3.image.x + enemy3.image.width) ||
	//			(enemy3.image.x > player.tama[cnt].x && enemy3.image.x < player.tama[cnt].x + player.tama[cnt].width)) &&
	//			((player.tama[cnt].y > enemy3.image.y && player.tama[cnt].y < enemy3.image.y + enemy3.image.height) ||
	//				(enemy3.image.y > player.tama[cnt].y && enemy3.image.y < player.tama[cnt].y + player.tama[cnt].height)))
	//		{

	//			player.tama[cnt].IsDraw = FALSE;

	//			PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

	//			enemy3.image.IsDraw = FALSE;
	//			enemy3.image.width = FALSE;
	//			enemy3.image.height = FALSE;
	//			enemy3.image.x = FALSE;
	//			enemy3.image.y = FALSE;

	//			break;
	//		}
	//	}


	//	//敵５と緑弾の当たり判定
	//	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	//	{

	//		if (((player.tama2[cnt].x > enemy5.image.x && player.tama2[cnt].x < enemy5.image.x + enemy5.image.width) ||
	//			(enemy5.image.x > player.tama2[cnt].x && enemy5.image.x < player.tama2[cnt].x + player.tama2[cnt].width)) &&
	//			((player.tama2[cnt].y > enemy5.image.y && player.tama2[cnt].y < enemy5.image.y + enemy5.image.height) ||
	//				(enemy5.image.y > player.tama2[cnt].y && enemy5.image.y < player.tama2[cnt].y + player.tama2[cnt].height)))
	//		{

	//			player.tama2[cnt].IsDraw = FALSE;

	//			PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

	//			enemy5.image.IsDraw = FALSE;
	//			enemy5.image.width = FALSE;
	//			enemy5.image.height = FALSE;
	//			enemy5.image.x = FALSE;
	//			enemy5.image.y = FALSE;

	//			break;
	//		}
	//	}

	//}


	////ゴールの出現条件
	///*if (enemy.image.IsDraw == FALSE)
	//{
	//	if (enemy2.image.IsDraw == FALSE)
	//		{
	//		if (enemy3.image.IsDraw == FALSE)
	//			{
	//			if (enemy4.image.IsDraw == FALSE)
	//				{
	//					goalgazou.IsDraw = TRUE;

	//				}
	//			}
	//		}
	//}*/



	if (player.CanShot == FALSE)
	{

		if (player.ShotReLoadCnt == player.ShotReLoadCntMAX)
		{
			player.ShotReLoadCnt = 0;
			player.CanShot = TRUE;
		}

		player.ShotReLoadCnt++;
	}





	

	//敵１の配置
	enemy.image.x = 500;
	enemy.image.y = 200;
	


	////敵２の配置
	//enemy2.image.x = GAME_WIDTH / 1.8;
	//enemy2.image.y = GAME_HEIGHT / 8.5;


	//enemy3.image.x = GAME_WIDTH / 8 + GAME_HANKEI * sin(enemy3.image.radian) / 1.3;
	//enemy3.image.y = GAME_HEIGHT / 6 - enemy3.image.width / 2; GAME_HANKEI* sin(enemy3.image.radian);
	//enemy3.image.radian += 0.04;

	//enemy4.image.x = GAME_WIDTH / 2.5 - GAME_HANKEI * sin(enemy4.image.radian) / 1.5;
	//enemy4.image.y = GAME_HEIGHT / 1.6 - enemy4.image.width / 2; GAME_HANKEI* sin(enemy4.image.radian);
	//enemy4.image.radian += 0.02;


	//enemy5.image.x = GAME_WIDTH / 10 - GAME_HANKEI * sin(enemy5.image.radian) / 6;
	//enemy5.image.y = GAME_HEIGHT / 1.2 - enemy5.image.width / 2; GAME_HANKEI* sin(enemy5.image.radian);
	//enemy5.image.radian += 0.01;


	/*goalgazou.x = GAME_WIDTH / 5.2;
	goalgazou.y = GAME_HEIGHT / 1.8;*/


	warp.x = 400;
	warp.y = 30;



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


	

	if (player.image.IsDraw == TRUE)
	{
		player.image.IsDraw = FALSE;
	}
	/*else if (player.image.IsDraw == FALSE)
	{
		player.image.IsDraw = TRUE;
	}*/



	hukidasi.x = 430;
	hukidasi.y = 50;

	hukidasi2.x = 150;
	hukidasi2.y = 500;

	

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

	/*for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			if (mapData[tate][yoko] == k)
			{
				DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 0, 255), FALSE);
			}

			if (mapData[tate][yoko] == t)
			{
				DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 255, 0), FALSE);
			}

		}
	}*/



	/*DrawBox(GoalRect.left, GoalRect.top, GoalRect.right, GoalRect.bottom, GetColor(255, 255, 0), TRUE);*/

	

	if (warp.IsDraw == TRUE)
	{

		DrawGraph(warp.x, warp.y, warp.handle, TRUE);
	}
	

	map1count++;

	int a;
	
	a = map1count % 40 / 5;

	if (a == 10)
	{
		a = 0;
	}
	
	DrawGraph(360, 5, warphandle[a], TRUE);



	DrawGraph(player.image.x, player.image.y, player.image.handle, TRUE);

	DrawBox(player.coll.left, player.coll.top, player.coll.right, player.coll.bottom, GetColor(255, 0, 0), FALSE);


	if (enemy.image.IsDraw == TRUE)
	{
		DrawGraph(enemy.image.x, enemy.image.y, enemy.image.handle, TRUE);
	}



	if (enemy2.image.IsDraw == TRUE)
	{
		DrawGraph(enemy2.image.x, enemy2.image.y, enemy2.image.handle, TRUE);
	}

	if (enemy3.image.IsDraw == TRUE)
	{
		DrawGraph(enemy3.image.x, enemy3.image.y, enemy3.image.handle, TRUE);
	}


	if (enemy4.image.IsDraw == TRUE)
	{
		DrawGraph(enemy4.image.x, enemy4.image.y, enemy4.image.handle, TRUE);
	}


	if (enemy5.image.IsDraw == TRUE)
	{
		DrawGraph(enemy5.image.x, enemy5.image.y, enemy5.image.handle, TRUE);
	}


	for (int i = 0; i < HEART_NUM; i++)
	{
		if (heart[i].IsDraw == TRUE)
		{
			DrawGraph(heart[i].x, heart[i].y, heart[i].handle, TRUE);
		}
	}


	
		
	

	if (hukidasi.IsDraw == TRUE)
	{
		DrawGraph(hukidasi.x, hukidasi.y, hukidasi.handle, TRUE);
	}
		


	if (hukidasi2.IsDraw == TRUE)
	{
		DrawGraph(hukidasi2.x, hukidasi2.y, hukidasi2.handle, TRUE);
	}


	if (goalgazou.IsDraw == TRUE)
	{
		DrawGraph(goalgazou.x, goalgazou.y, goalgazou.handle, TRUE);

	}



	if (gategazou.IsDraw == TRUE)
	{
		DrawGraph(gategazou.x, gategazou.y, gategazou.handle, TRUE);
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

			if (player.tama[cnt].y < 0)
			{
				player.tama[cnt].IsDraw = FALSE;
			}
			else
			{
				player.tama[cnt].x -= player.tama[cnt].speed;
			}
		}
	}




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

			if (player.tama2[cnt].x < 0)
			{
				player.tama2[cnt].IsDraw = FALSE;
			}
			else
			{
				player.tama2[cnt].x -= player.tama2[cnt].speed;
			}
		}
	}





	return;
}


//マップ２

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


	//プレイヤーの速度&キー操作設定

	player.speed = 2;
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


	//マップとプレイヤーの当たり判定設定
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


	//当たり判定の範囲設定
	RECT PlayerRect;
	int CollRange = 2;
	PlayerRect.left = player.image.x + player.image.width / 2 - CollRange;
	PlayerRect.top = player.image.y + player.image.height / 2 - CollRange;
	PlayerRect.right = player.image.x + player.image.width / 2 + CollRange;
	PlayerRect.bottom = player.image.y + player.image.height / 2 + CollRange;


	RECT EnemyRect;
	EnemyRect.left = enemy.image.x;
	EnemyRect.top = enemy.image.y;
	EnemyRect.right = enemy.image.x + enemy.image.width;
	EnemyRect.bottom = enemy.image.y + enemy.image.height;


	RECT Enemy2Rect;
	Enemy2Rect.left = enemy2.image.x;
	Enemy2Rect.top = enemy2.image.y;
	Enemy2Rect.right = enemy2.image.x + enemy2.image.width;
	Enemy2Rect.bottom = enemy2.image.y + enemy2.image.height;


	RECT Enemy3Rect;
	Enemy3Rect.left = enemy3.image.x;
	Enemy3Rect.top = enemy3.image.y;
	Enemy3Rect.right = enemy3.image.x + enemy3.image.width;
	Enemy3Rect.bottom = enemy3.image.y + enemy3.image.height;


	RECT Enemy4Rect;
	Enemy4Rect.left = enemy4.image.x;
	Enemy4Rect.top = enemy4.image.y;
	Enemy4Rect.right = enemy4.image.x + enemy4.image.width;
	Enemy4Rect.bottom = enemy4.image.y + enemy4.image.height;


	RECT Enemy5Rect;
	Enemy5Rect.left = enemy5.image.x;
	Enemy5Rect.top = enemy5.image.y;
	Enemy5Rect.right = enemy5.image.x + enemy5.image.width;
	Enemy5Rect.bottom = enemy5.image.y + enemy5.image.height;


	
	RECT SyokushuRect;
	SyokushuRect.left = syokusyu[0].x;
	SyokushuRect.top = syokusyu[0].y;
	SyokushuRect.right = syokusyu[0].x + syokusyu[0].width;
	SyokushuRect.bottom = syokusyu[0].y + syokusyu[0].height;


	RECT Syokushu2Rect;
	Syokushu2Rect.left = syokusyu[1].x;
	Syokushu2Rect.top = syokusyu[1].y;
	Syokushu2Rect.right = syokusyu[1].x + syokusyu[1].width;
	Syokushu2Rect.bottom = syokusyu[1].y + syokusyu[1].height;
	


	RECT TamaRect;
	TamaRect.left = tama.x + 10;
	TamaRect.top = tama.y + 10;
	TamaRect.right = tama.x + tama.width - 10;
	TamaRect.bottom = tama.y + tama.height - 10;



	//触手1との当たり判定

	
		if (MY_CHECK_RECT_COLL(PlayerRect, SyokushuRect) == TRUE)
		{
			player.IsMuteki = TRUE;


			/*int i = 0;

			while (i < 3) {

				heart[i].IsDraw = FALSE;

				if (heart[i].IsDraw == FALSE)
				{
					i++;
				}

			}*/

		}



		//触手２との当たり判定

		if (MY_CHECK_RECT_COLL(PlayerRect, Syokushu2Rect) == TRUE)
		{
			

			if (player.IsMuteki == FALSE)
			{
				player.IsMuteki = TRUE;
			}
			

			/*heart[heartnow].IsDraw = FALSE;*/

		}

		
		if (player.IsMuteki == TRUE)
		{

			switch (heartnow)
			{
			case 0:
				heart[0].IsDraw = FALSE;
				break;

			case 1:
				heart[1].IsDraw = FALSE;
				break;

			case 2:
				heart[2].IsDraw = FALSE;
				break;


				heartnow -= 1;

			/*default:
				break;*/
			}
		}
		
		


		/*if (mutekicount < 32)
		{
			if (player.IsMuteki == TRUE)
			{

				heartnow -= 1;
				heart[heartnow].IsDraw = FALSE;

		
				mutekicount += 1;
				player.Ishit = FALSE;
				if (player.IsDraw == TRUE)
				{
					player.IsDraw = FALSE;
				}
				else if (player.IsDraw == FALSE)
				{
					player.IsDraw = TRUE;
				}
			}
		}
		else if(mutekicount == 32)
		{
			mutekicount = 0;
		}*/

	





	

	




	

	
	
	


	//if (player.Ishit == TRUE && mutekicount == 0)
	//{
	//	mutekicount = 31;
	//}
	//

	//if (player.IsMuteki == TRUE)
	//{
	//	if (mutekicount > 0)
	//	{
	//		mutekicount-=1;

	//		if (player.IsDraw == TRUE)
	//		{
	//			player.IsDraw = FALSE;
	//		}
	//		else if (player.IsDraw == FALSE)
	//		{
	//			player.IsDraw = TRUE;
	//		}

	//		if (mutekicount <= 0)
	//		{
	//			mutekicount = 0;
	//			player.Ishit = FALSE;
	//		}
	//	}	

	//}

	

	//プレイヤーが画面外に出たら
	if (player.image.x > GAME_WIDTH || player.image.y > GAME_HEIGHT
		|| player.image.x + player.image.width < 0 || player.image.y + player.image.height < 0)
	{
		if (CheckSoundMem(BGM.handle) != 0)
		{
			StopSoundMem(BGM.handle);
		}

		SetMouseDispFlag(TRUE);

		GameEndKind = GAME_END_COMP;

		GameScene = GAME_SCENE_END;

		return;
	}


	//赤弾を発射
	if (MY_KEY_DOWN(KEY_INPUT_1) == TRUE)
	{
		if (player.CanShot == TRUE)
		{
			PlaySoundMem(player.musicShot.handle, DX_PLAYTYPE_BACK);
			PlaySoundMem(voice_ei.handle, DX_PLAYTYPE_BACK);
			ChangeVolumeSoundMem(255 * 150 / 100, voice_ei.handle);
			player.CanShot = FALSE;


			for (int cnt = 0; cnt < TAMA_MAX; cnt++)
			{
				if (player.tama[cnt].IsDraw == FALSE)
				{
					player.tama[cnt].x = player.CenterX - player.tama[cnt].width / 2;

					player.tama[cnt].y = player.image.y;

					player.tama[cnt].IsDraw = TRUE;

					break;
				}

			}
		}
	}



	//緑弾を発射
	if (MY_KEY_DOWN(KEY_INPUT_2) == TRUE)
	{
		if (player.CanShot == TRUE)
		{
			PlaySoundMem(player.greenshot.handle, DX_PLAYTYPE_BACK);
			PlaySoundMem(voice_make.handle, DX_PLAYTYPE_BACK);
			ChangeVolumeSoundMem(255 * 150 / 100, voice_ei.handle);
			player.CanShot = FALSE;


			for (int cnt = 0; cnt < TAMA_MAX; cnt++)
			{
				if (player.tama2[cnt].IsDraw == FALSE)
				{

					player.tama2[cnt].y = player.CenterY - player.tama2[cnt].height / 2;

					player.tama2[cnt].x = player.image.x;

					player.tama2[cnt].IsDraw = TRUE;

					break;
				}
			}


		}
	}


	////敵１と赤弾の当たり判定
	//for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	//{

	//	if (((player.tama[cnt].x > enemy.image.x && player.tama[cnt].x < enemy.image.x + enemy.image.width) ||
	//		(enemy.image.x > player.tama[cnt].x && enemy.image.x < player.tama[cnt].x + player.tama[cnt].width)) &&
	//		((player.tama[cnt].y > enemy.image.y && player.tama[cnt].y < enemy.image.y + enemy.image.height) ||
	//			(enemy.image.y > player.tama[cnt].y && enemy.image.y < player.tama[cnt].y + player.tama[cnt].height)))
	//	{

	//		player.tama[cnt].IsDraw = FALSE;

	//		PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

	//		enemy.image.handle = FALSE;
	//		enemy.image.width = FALSE;
	//		enemy.image.height = FALSE;
	//		enemy.image.x = FALSE;
	//		enemy.image.y = FALSE;

	//		/*break;*/
	//	}

	//}


	////敵２と弾２の当たり判定
	//for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	//{

	//	if (((player.tama2[cnt].x > enemy2.image.x && player.tama2[cnt].x < enemy2.image.x + enemy2.image.width) ||
	//		(enemy2.image.x > player.tama2[cnt].x && enemy2.image.x < player.tama2[cnt].x + player.tama2[cnt].width)) &&
	//		((player.tama2[cnt].y > enemy2.image.y && player.tama2[cnt].y < enemy2.image.y + enemy2.image.height) ||
	//			(enemy2.image.y > player.tama2[cnt].y && enemy2.image.y < player.tama2[cnt].y + player.tama2[cnt].height)))
	//	{

	//		player.tama2[cnt].IsDraw = FALSE;

	//		PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

	//		enemy2.image.IsDraw = FALSE;
	//		enemy2.image.width = FALSE;
	//		enemy2.image.height = FALSE;
	//		enemy2.image.x = FALSE;
	//		enemy2.image.y = FALSE;

	//		break;
	//	}

	//}


	////敵４と緑弾の当たり判定
	//for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	//{

	//	if (((player.tama2[cnt].x > enemy4.image.x && player.tama2[cnt].x < enemy4.image.x + enemy4.image.width) ||
	//		(enemy4.image.x > player.tama2[cnt].x && enemy4.image.x < player.tama2[cnt].x + player.tama2[cnt].width)) &&
	//		((player.tama2[cnt].y > enemy4.image.y && player.tama2[cnt].y < enemy4.image.y + enemy4.image.height) ||
	//			(enemy4.image.y > player.tama2[cnt].y && enemy4.image.y < player.tama2[cnt].y + player.tama2[cnt].height)))
	//	{

	//		player.tama2[cnt].IsDraw = FALSE;

	//		PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

	//		enemy4.image.IsDraw = FALSE;
	//		enemy4.image.width = FALSE;
	//		enemy4.image.height = FALSE;
	//		enemy4.image.x = FALSE;
	//		enemy4.image.y = FALSE;

	//		break;
	//	}


	//	//敵３と赤弾の当たり判定
	//	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	//	{

	//		if (((player.tama[cnt].x > enemy3.image.x && player.tama[cnt].x < enemy3.image.x + enemy3.image.width) ||
	//			(enemy3.image.x > player.tama[cnt].x && enemy3.image.x < player.tama[cnt].x + player.tama[cnt].width)) &&
	//			((player.tama[cnt].y > enemy3.image.y && player.tama[cnt].y < enemy3.image.y + enemy3.image.height) ||
	//				(enemy3.image.y > player.tama[cnt].y && enemy3.image.y < player.tama[cnt].y + player.tama[cnt].height)))
	//		{

	//			player.tama[cnt].IsDraw = FALSE;

	//			PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

	//			enemy3.image.IsDraw = FALSE;
	//			enemy3.image.width = FALSE;
	//			enemy3.image.height = FALSE;
	//			enemy3.image.x = FALSE;
	//			enemy3.image.y = FALSE;

	//			break;
	//		}
	//	}


	//	//敵５と緑弾の当たり判定
	//	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	//	{

	//		if (((player.tama2[cnt].x > enemy5.image.x && player.tama2[cnt].x < enemy5.image.x + enemy5.image.width) ||
	//			(enemy5.image.x > player.tama2[cnt].x && enemy5.image.x < player.tama2[cnt].x + player.tama2[cnt].width)) &&
	//			((player.tama2[cnt].y > enemy5.image.y && player.tama2[cnt].y < enemy5.image.y + enemy5.image.height) ||
	//				(enemy5.image.y > player.tama2[cnt].y && enemy5.image.y < player.tama2[cnt].y + player.tama2[cnt].height)))
	//		{

	//			player.tama2[cnt].IsDraw = FALSE;

	//			PlaySoundMem(gekiha.handle, DX_PLAYTYPE_BACK);

	//			enemy5.image.IsDraw = FALSE;
	//			enemy5.image.width = FALSE;
	//			enemy5.image.height = FALSE;
	//			enemy5.image.x = FALSE;
	//			enemy5.image.y = FALSE;

	//			break;
	//		}
	//	}

	//}



	if (player.CanShot == FALSE)
	{

		if (player.ShotReLoadCnt == player.ShotReLoadCntMAX)
		{
			player.ShotReLoadCnt = 0;
			player.CanShot = TRUE;
		}

		player.ShotReLoadCnt++;
	}


	//敵１の配置
	
		/*if (enemy.count < 100000)
		{
			enemy.count += 1;

			if (enemy.count > 400)
			{
				enemy.image.x++;
				enemy.image.y = 400;
			}
		}


		if (enemy.image.x > GAME_WIDTH)
		{
			enemy.image.IsDraw = FALSE;
		}*/


		
	//[[カウント]]


	enemycount += 1;


	//赤は危険！緑は安全

	hukidasi3.x = 150;
	hukidasi3.y = 500;

	if (enemycount > 50)
	{
		if (enemycount < 300)
		{
			hukidasi3.IsDraw = TRUE;
		}
		if (enemycount == 300)
		{
			hukidasi3.IsDraw = FALSE;
		}
	}


	//エリア配置

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
		safe_tate[0].y = 0;
	}



	for (int i = 0; i < SAFE_YOKO_NUM; i++)
	{
		safe_yoko[i] = safe_yoko[0];


		safe_yoko[0].x = 0;
		safe_yoko[0].y = 0;

	}


	


	//赤エリア１回目表示


	if (enemycount > 350)
	{
		if (enemycount < 550)
		{
			denger_yoko[0].IsDraw = TRUE;
		}
		if (enemycount == 550)
		{
			denger_yoko[0].IsDraw = FALSE;
		}
	}


	//触手１回目の攻撃

	if (enemycount > 600)
	{
			syokusyu[0].IsDraw = TRUE;
			syokusyu[0].x -= 10;				
	}


	//赤エリア２回目表示

	
	if (enemycount > 900)
	{
		if (enemycount < 1100)
		{
			denger_yoko[1].IsDraw = TRUE;
		}
		if (enemycount == 1100)
		{
			denger_yoko[1].IsDraw = FALSE;
		}
	}


	//触手２
	if (enemycount > 1150)
	{
					
		syokusyu[1].IsDraw = TRUE;
		syokusyu[1].x -= 10;

	}
	

	return;
}

VOID MY_PLAY2_DRAW(VOID)
{
	
	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		if (ImageBack[num].IsDraw == TRUE)
		{
			DrawGraph(ImageBack[num].image.x, ImageBack[num].image.y, ImageBack[num].image.handle, TRUE);

		}
	}



	//◆◆◆◆◆◆◆◆◆◆【エリア】◆◆◆◆◆◆◆◆◆◆

	
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
		


	for (int i = 0; i < HEART_NUM; i++)
	{
		if (heart[i].IsDraw == TRUE)
		{
			DrawGraph(heart[i].x, heart[i].y, heart[i].handle, TRUE);
		}
	}


	/*for (int tate = 0; tate < GAME_MAP2_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP2_YOKO_MAX; yoko++)
		{
			DrawGraph(
				map2[tate][yoko].x,
				map2[tate][yoko].y,
				mapChip2.handle[map2[tate][yoko].kind],
				TRUE);
		}
	}*/

	/*for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			if (mapData[tate][yoko] == k)
			{
				DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 0, 255), FALSE);
			}

			if (mapData[tate][yoko] == t)
			{
				DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 255, 0), FALSE);
			}

		}
	}*/



	/*DrawBox(GoalRect.left, GoalRect.top, GoalRect.right, GoalRect.bottom, GetColor(255, 255, 0), TRUE);*/

	if (player.IsDraw == TRUE)
	{
		DrawGraph(player.image.x, player.image.y, player.image.handle, TRUE);
	}
		
	
	//DrawBox(player.coll.left, player.coll.top, player.coll.right, player.coll.bottom, GetColor(255, 0, 0), FALSE);


	

	for (int i = 0; i < SHOKUSHU_NUM; i++)
	{
		if (syokusyu[i].IsDraw == TRUE)
		{
			DrawGraph(syokusyu[i].x, syokusyu[i].y, syokusyu[i].handle, TRUE);
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

			if (player.tama[cnt].y < 0)
			{
				player.tama[cnt].IsDraw = FALSE;
			}
			else
			{
				player.tama[cnt].y -= player.tama[cnt].speed;
			}
		}
	}




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

			if (player.tama2[cnt].x < 0)
			{
				player.tama2[cnt].IsDraw = FALSE;
			}
			else
			{
				player.tama2[cnt].x -= player.tama2[cnt].speed;
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
			StopSoundMem(ENDBGM.handle);	//BGMを止める
		}

		if (CheckSoundMem(gameover.handle) != 0)
		{
			StopSoundMem(gameover.handle);	//BGMを止める
		}


		SetMouseDispFlag(TRUE);


		GameScene = GAME_SCENE_START;

		return;
	}




	switch (GameEndKind)
	{
	case GAME_END_COMP:

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
			ChangeVolumeSoundMem(255 * 70 / 100, gameover.handle);	//50%の音量にする


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


	MY_PLAY2_DRAW();

	switch (GameEndKind)
	{
	case GAME_END_COMP:

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



	DrawString(330, 400, "エンド画面(エスケープキーを押して下さい)", GetColor(255, 255, 255));

	return;
}

BOOL MY_LOAD_IMAGE(VOID)
{

	LoadDivGraph(
		"pipo-mapeffect015_192.png",
		10, 5, 2, 192, 192, warphandle);

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


	strcpy_s(back1.path, IMAGE_BACK1_PATH);
	back1.handle = LoadGraph(back1.path);			//読み込み
	if (back1.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_BACK1_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(back1.handle, &back1.width, &back1.height);	//画像の幅と高さを取得
	back1.x = GAME_WIDTH / 2 - back1.width / 2;		//左右中央揃え
	back1.y = GAME_HEIGHT / 2 - back1.height / 2;		//上下中央揃え



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


	//プレイヤーの配置
	strcpy_s(player.image.path, IMAGE_PLAYER_PATH);
	player.image.handle = LoadGraph(player.image.path);
	if (player.image.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_PLAYER_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(player.image.handle, &player.image.width, &player.image.height);	//画像の幅と高さを取得
	player.image.x = GAME_WIDTH / 2 - player.image.width / 2;		//左右中央揃え
	player.image.y = GAME_HEIGHT / 2 - player.image.height / 2;		//上下中央揃え
	player.CenterX = player.image.x + player.image.width / 2;		//画像の横の中心を探す
	player.CenterY = player.image.y + player.image.height / 2;		//画像の縦の中心を探す
	player.speed = CHARA_SPEED_LOW;
	player.IsDraw = TRUE;
	player.IsMuteki = FALSE;


	//敵の配置
	strcpy_s(enemy.image.path, IMAGE_ENEMY_PATH);
	enemy.image.handle = LoadGraph(enemy.image.path);
	if (enemy.image.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_ENEMY_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(enemy.image.handle, &enemy.image.width, &enemy.image.height);	//画像の幅と高さを取得

	enemy.radian = 0.0;
	enemycount = 0.0;
	enemy.speed = CHARA_SPEED_LOW;
	enemy.image.IsDraw = TRUE;



	strcpy_s(enemy2.image.path, IMAGE_ENEMY2_PATH);
	enemy2.image.handle = LoadGraph(enemy2.image.path);
	if (enemy2.image.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_ENEMY2_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(enemy2.image.handle, &enemy2.image.width, &enemy2.image.height);	//画像の幅と高さを取得

	enemy2.radian = 0.0;
	enemy2.speed = CHARA_SPEED_LOW;
	enemy2.image.IsDraw = TRUE;



	strcpy_s(enemy3.image.path, IMAGE_ENEMY3_PATH);
	enemy3.image.handle = LoadGraph(enemy3.image.path);
	if (enemy3.image.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_ENEMY3_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(enemy3.image.handle, &enemy3.image.width, &enemy3.image.height);	//画像の幅と高さを取得

	enemy3.radian = 0.0;
	enemy3.speed = CHARA_SPEED_LOW;
	enemy3.image.IsDraw = TRUE;



	strcpy_s(enemy4.image.path, IMAGE_ENEMY4_PATH);
	enemy4.image.handle = LoadGraph(enemy4.image.path);
	if (enemy4.image.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_ENEMY4_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(enemy4.image.handle, &enemy4.image.width, &enemy4.image.height);	//画像の幅と高さを取得

	enemy4.radian = 0.0;
	enemy4.speed = CHARA_SPEED_LOW;
	enemy4.image.IsDraw = TRUE;



	strcpy_s(enemy5.image.path, IMAGE_ENEMY5_PATH);
	enemy5.image.handle = LoadGraph(enemy5.image.path);
	if (enemy5.image.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_ENEMY5_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(enemy5.image.handle, &enemy5.image.width, &enemy5.image.height);	//画像の幅と高さを取得

	enemy5.radian = 0.0;
	enemy5.speed = CHARA_SPEED_LOW;
	enemy5.image.IsDraw = TRUE;


	//触手
	strcpy_s(syokusyu[0].path, IMAGE_syokusyu_PATH);
	syokusyu[0].handle = LoadGraph(syokusyu[0].path);
	if (syokusyu[0].handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_syokusyu_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(syokusyu[0].handle, &syokusyu[0].width, &syokusyu[0].height);	//画像の幅と高さを取得

	syokusyu[0].radian = 0.0;
	syokusyu[0].IsDraw = FALSE;


	//ハート
	strcpy_s(heart[0].path, IMAGE_HEART_PATH);
	heart[0].handle = LoadGraph(heart[0].path);
	if (heart[0].handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_HEART_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(heart[0].handle, &heart[0].width, &heart[0].height);	//画像の幅と高さを取得

	heart[0].IsDraw = TRUE;


	////エリア

	//赤エリア縦
	strcpy_s(denger_tate[0].path, IMAGE_DENGER_TATE_PATH);
	denger_tate[0].handle = LoadGraph(denger_tate[0].path);
	if (denger_tate[0].handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_DENGER_TATE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(denger_tate[0].handle, &denger_tate[0].width, &denger_tate[0].height);	//画像の幅と高さを取得
	denger_tate[0].IsDraw = FALSE;


	//赤エリア横
	strcpy_s(denger_yoko[0].path, IMAGE_DENGER_YOKO_PATH);
	denger_yoko[0].handle = LoadGraph(denger_yoko[0].path);
	if (denger_yoko[0].handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_DENGER_YOKO_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(denger_yoko[0].handle, &denger_yoko[0].width, &denger_yoko[0].height);	//画像の幅と高さを取得
	denger_yoko[0].IsDraw = FALSE;


	//緑エリア縦
	strcpy_s(safe_tate[0].path, IMAGE_SAFE_TATE_PATH);
	safe_tate[0].handle = LoadGraph(safe_tate[0].path);
	if (safe_tate[0].handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_SAFE_TATE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(safe_tate[0].handle, &safe_tate[0].width, &safe_tate[0].height);	//画像の幅と高さを取得
	safe_tate[0].IsDraw = FALSE;


	//緑エリア横
	
	strcpy_s(safe_yoko[0].path, IMAGE_SAFE_YOKO_PATH);
	safe_yoko[0].handle = LoadGraph(safe_yoko[0].path);
	if (safe_yoko[0].handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_SAFE_YOKO_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(safe_yoko[0].handle, &safe_yoko[0].width, &safe_yoko[0].height);	//画像の幅と高さを取得
	safe_yoko[0].IsDraw = FALSE;


	// 吹き出し
	strcpy_s(hukidasi.path, IMAGE_HUKIDASI_PATH);
	hukidasi.handle = LoadGraph(hukidasi.path);
	if (hukidasi.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_HUKIDASI_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(hukidasi.handle, &hukidasi.width, &hukidasi.height);
	hukidasi.IsDraw = FALSE;



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



	strcpy_s(goalgazou.path, IMAGE_GOAL_PATH);
	goalgazou.handle = LoadGraph(goalgazou.path);
	if (goalgazou.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_GOAL_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(goalgazou.handle, &goalgazou.width, &goalgazou.height);	//画像の幅と高さを取得

	goalgazou.IsDraw = FALSE;



	//ワープ

	strcpy_s(warp.path, IMAGE_WARP_PATH);
	warp.handle = LoadGraph(warp.path);
	if (warp.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_WARP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(warp.handle, &warp.width, &warp.height);	
	warp.IsDraw = TRUE;



	//赤弾の画像を分割
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

		player.tama[cnt].width = player.tama[0].width;

		player.tama[cnt].height = player.tama[0].height;

		player.tama[cnt].x = player.CenterX - player.tama[cnt].width / 2;

		player.tama[cnt].y = player.image.y;

		player.tama[cnt].IsDraw = FALSE;

		player.tama[cnt].changeImageCnt = 0;

		player.tama[cnt].changeImageCntMAX = TAMA_CHANGE_MAX;

		player.tama[cnt].nowImageKind = 0;

		player.tama[cnt].speed = CHARA_SPEED_LOW;

	}



	//緑弾の画像を分割

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

	GetGraphSize(player.tama2[0].handle[0], &player.tama2[0].width, &player.tama[0].height);

	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		strcpyDx(player.tama2[cnt].path, TEXT(TAMA_GREEN_PATH));

		for (int i_num = 0; i_num < TAMA_DIV_NUM; i_num++)
		{
			player.tama2[cnt].handle[i_num] = player.tama2[0].handle[i_num];
		}

		player.tama2[cnt].width = player.tama2[0].width;

		player.tama2[cnt].height = player.tama2[0].height;

		player.tama2[cnt].x = player.CenterY - player.tama2[cnt].height / 2;

		player.tama2[cnt].y = player.image.x;

		player.tama2[cnt].IsDraw = FALSE;

		player.tama2[cnt].changeImageCnt = 0;

		player.tama2[cnt].changeImageCntMAX = TAMA_CHANGE_MAX;

		player.tama2[cnt].nowImageKind = 0;

		player.tama2[cnt].speed = CHARA_SPEED_LOW;

	}



	//マップ１
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



	//マップ２
	int mapRes2 = LoadDivGraph(
		GAME_MAP2_PATH,
		MAP2_DIV_NUM, MAP2_DIV_TATE, MAP2_DIV_YOKO,
		MAP2_DIV_WIDTH, MAP2_DIV_HEIGHT,
		&mapChip2.handle[0]);

	if (mapRes2 == -1)
	{
		MessageBox(GetMainWindowHandle(), GAME_MAP2_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	GetGraphSize(mapChip2.handle[0], &mapChip2.width, &mapChip2.height);

	for (int tate = 0; tate < GAME_MAP2_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP2_YOKO_MAX; yoko++)
		{
			mapData2Init[tate][yoko] = mapData2[tate][yoko];

			map2[tate][yoko].kind = mapData2[tate][yoko];

			map2[tate][yoko].width = mapChip2.width;
			map2[tate][yoko].height = mapChip2.height;

			map2[tate][yoko].x = yoko * map2[tate][yoko].width;
			map2[tate][yoko].y = tate * map2[tate][yoko].height;
		}
	}


	/*for (int tate = 0; tate < GAME_MAP2_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP2_YOKO_MAX; yoko++)
		{
			mapColl[tate][yoko].left = (yoko + 0) * mapChip2.width + 1;
			mapColl[tate][yoko].top = (tate + 0) * mapChip2.height + 1;
			mapColl[tate][yoko].right = (yoko + 1) * mapChip2.width - 1;
			mapColl[tate][yoko].bottom = (tate + 1) * mapChip2.height - 1;

		}
	}*/



	return TRUE;
}



//画像削除

VOID MY_DELETE_IMAGE(VOID)
{
	for (int num = 0; num < IMAGE_BACK_NUM; num++)
	{
		DeleteGraph(ImageBack[0].image.handle);
	}

	DeleteGraph(player.image.handle);
	DeleteGraph(enemy.image.handle);
	DeleteGraph(enemy2.image.handle);
	DeleteGraph(enemy3.image.handle);
	DeleteGraph(enemy4.image.handle);
	DeleteGraph(enemy5.image.handle);
	DeleteGraph(goalgazou.handle);
	DeleteGraph(gategazou.handle);

	DeleteGraph(ImageTitleROGO.image.handle);
	DeleteGraph(ImageTitleSTART.image.handle);


	DeleteGraph(ImageEndCOMP.image.handle);
	DeleteGraph(ImageEndFAIL.image.handle);

	DeleteGraph(warp.handle);
	DeleteGraph(hukidasi.handle);
	DeleteGraph(hukidasi2.handle);
	DeleteGraph(hukidasi3.handle);
	

	for (int i = 0; i < SHOKUSHU_NUM; i++)
	{
		DeleteGraph(syokusyu[i].handle);
	}


	for (int i = 0; i < HEART_NUM; i++)
	{
		DeleteGraph(heart[i].handle);
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
	for (int i_num = 0; i_num < TAMA_DIV_NUM; i_num++) { DeleteGraph(player.tama2[0].handle[i_num]); }


	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip.handle[i_num]); }
	
	for (int i_num = 0; i_num < MAP2_DIV_NUM; i_num++) { DeleteGraph(mapChip2.handle[i_num]); }


	/*DeleteGraph(STARTBACK.handle);*/

	return;
}


//音楽

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


	/*strcpy_s(voice_make.path, MUSIC_VOICE2_PATH);
	voice_make.handle = LoadSoundMem(voice_make.path);
	if (voice_make.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_VOICE2_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}*/


	strcpy_s(gekiha.path, MUSIC_GEKIHA_PATH);
	gekiha.handle = LoadSoundMem(gekiha.path);
	if (gekiha.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_GEKIHA_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
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

	return;
}


//マップとプレイヤーの当たり判定をする関数

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
				else if (GameScene == GAME_SCENE_PLAY2)
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



//領域の当たり判定
BOOL MY_CHECK_RECT_COLL(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top)
	{
		
		return TRUE;
		player.Ishit = TRUE;
	
	}
	else
	{
		player.Ishit = FALSE;
	}

	return FALSE;
	
}