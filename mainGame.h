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
	bg _bgBack;					//��׶��� �̹���
	bg _miniMap;					//��׶��� �̹���
	bg _bgBuildAnim;			//��׶��� �̹���
	bg _bgGirlAnim;				//��׶��� �̹���
	int _alpha;					//���� �����ų ���İ�
	RECT temprc;
	//�����ӷ��� ����
	tagObstacle colliderRc[MAXOBSTACLE];
	RECT _radarRc;
	RECT _miniRc;
	character _ari[MAXSTATE];
	character _pipi[2];
	int _pipiIndex;
	int _count;					//������ ���� ī��Ʈ
	int _bgCount;
	int _index;					//������ �̹��� �ε���
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

