#pragma once
#include "gameNode.h"

#define MAXSTATE 6
#define MAXOBSTACLE 25

enum state
{
	IDLE = 0,
	WALK,
	HANG,
	JUMP_UP,
	JUMP,
	FALL
};
enum direction
{
	RIGHT = 0,
	LEFT
};
struct bg
{
	image* img;
	int frameY;
	float x, y;
};
struct character
{
	image* img;
	RECT hangRc[2];
	int frameX;
};
struct tagObstacle
{
	RECT rc;
	RECT hangRc[2];
};
class mainGame : public gameNode
{
private:
	bg _bgBack;					//백그라운드 이미지
	bg _miniMap;					//백그라운드 이미지
	bg _bgBuildAnim;			//백그라운드 이미지
	bg _bgGirlAnim;				//백그라운드 이미지
	int _alpha;					//내가 변경시킬 알파값
	RECT temprc;
	//프레임렌더 사용법
	tagObstacle colliderRc[MAXOBSTACLE];
	RECT _radarRc;
	RECT _miniRc;
	character _ari[MAXSTATE];
	character _pipi[2];
	int _pipiIndex;
	int _count;					//프레임 돌릴 카운트
	int _bgCount;
	int _index;					//프레임 이미지 인덱스
	int _bgIndex;
	int _dir;
	bool _isJump;
	bool _isFall;
	bool _isHang;
	float _ariX, _ariY;
	float _mapCorrX, _mapCorrY;
	float angle;
	float speed;
	float gravity;
	state _state;



public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	void bgAnimLoop(bg* name);
	void characterAnimOnce(int dir, int state);
	void characterAnimLoop(int dir, int state);
	void stateIdle();
	void stateWalk();
	void stateHang();
	void stateJumpUp();
	void stateJump();
	void stateFall();
	void collideObject();
	void moveCameraXY();

	mainGame() {}
	~mainGame() {}
};

