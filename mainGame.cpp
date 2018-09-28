#include "stdafx.h"
#include "mainGame.h"

//=============================================================
//	## 초기화 ## init(void)
//=============================================================
HRESULT mainGame::init(void)
{
	gameNode::init();
	//이곳에서 초기화를 한다

	_bgBack.x = WINSIZEX - 864;
	_bgBack.y = WINSIZEY - 494;

	_bgBack.img = new image;
	_bgBack.img->init("image/bg_back_01.bmp", 864, 494);

	_miniMap.img = new image;
	_miniMap.img->init("image/bg_back_01.bmp", 864 / 7, 494 / 7);

	_bgBuildAnim.img = new image;
	_bgBuildAnim.frameY = 7;
	_bgBuildAnim.img->init("image/bg_buildings_sprite_01.bmp", 0.0f, 0.0f, 864, 3458, 1, _bgBuildAnim.frameY);

	_bgGirlAnim.img = new image;
	_bgGirlAnim.frameY = 15;
	_bgGirlAnim.img->init("image/bg_girl_sprite_01.bmp", 0.0f, 254.0f, 864, 3600, 1, _bgGirlAnim.frameY);

	colliderRc[0].rc = RectMake(257, 433, 602, 5);			//1층
	//colliderRc[1].rc = RectMake(427, 414, 38, 5);			//1층 박스1
	colliderRc[2].rc = RectMake(538, 408, 46, 5);			//1층 고양이 환풍기
	colliderRc[3].rc = RectMake(685, 408, 35, 5);			//1층 고양이 박스
	//colliderRc[4].rc = RectMake(353, 381 - 165, 50, 5);	//2층 사다리
	colliderRc[5].rc = RectMake(353, 398, 50, 5);			//2층 사다리
	colliderRc[6].rc = RectMake(5, 365, 460, 5);			//2층
	colliderRc[7].rc = RectMake(227, 348, 56, 5);		//2층 벤치
	colliderRc[8].rc = RectMake(202, 278, 149, 5);		//2층 정류장
	colliderRc[9].rc = RectMake(401, 302, 42, 5);			//2층 자판기
	colliderRc[10].rc = RectMake(475, 317, 10, 5);			//빨간집 벽
	//colliderRc[11].rc = RectMake(443, 285, 10, 5);			//빨간 지붕 끝
	//colliderRc[12].rc = RectMake(459, 272, 38, 5);		//빨간 지붕
	colliderRc[13].rc = RectMake(619, 272, 38, 5);		//빨간 지붕
	colliderRc[14].rc = RectMake(465, 252, 32, 5);		//에어콘
	colliderRc[15].rc = RectMake(837, 272, 159, 5);
	colliderRc[16].rc = RectMake(497, 165, 119, 5);
	colliderRc[17].rc = RectMake(507, 196, 40, 50);			//2층 빨간집 왼벽
	colliderRc[18].rc = RectMake(570, 196, 40, 50);			//2층 빨간집 오벽
	colliderRc[19].rc = RectMake(667, 204, 40, 40);			//2층 루프탑집 왼벽
	colliderRc[20].rc = RectMake(787, 204, 40, 40);			//2층 루프탑집 오벽
	colliderRc[21].rc = RectMake(635, 184, 220, 5);
	colliderRc[22].rc = RectMake(631, 138, 210, 5);		//루프탑

	for (int i = 0; i < MAXOBSTACLE; i++)
	{
		colliderRc[i].rc.left += _bgBack.x;
		colliderRc[i].rc.right += _bgBack.x;
		colliderRc[i].rc.top += _bgBack.y;
		colliderRc[i].rc.bottom += _bgBack.y;
		colliderRc[i].hangRc[0] = RectMake(colliderRc[i].rc.left, colliderRc[i].rc.top, 5, 5);
		colliderRc[i].hangRc[1] = RectMake(colliderRc[i].rc.right - 5, colliderRc[i].rc.top, 5, 5);
	}

	_ariX = WINSIZEX / 3 * 2;
	_ariY = WINSIZEY / 2;

	//알라딘 프레임 이미지 초기화
	for (int i = 0; i < MAXSTATE; i++)
		_ari[i].img = new image;

	_ari[IDLE].frameX = 4;
	_ari[IDLE].img->init("image/ari_idle_sprite_01.bmp", _ariX, _ariY, 108, 86, _ari[IDLE].frameX, 2);

	_ari[WALK].frameX = 8;
	_ari[WALK].img->init("image/ari_run_sprite_01.bmp", _ariX, _ariY, 256, 86, _ari[WALK].frameX, 2);

	_ari[HANG].frameX = 4;
	_ari[HANG].img->init("image/ari_hang_sprite_01.bmp", _ariX, _ariY, 116, 78, _ari[HANG].frameX, 2);

	_ari[JUMP_UP].frameX = 20;
	_ari[JUMP_UP].img->init("image/ari_hang_jump_sprite_01.bmp", _ariX, _ariY, 760, 96, _ari[JUMP_UP].frameX, 2);

	_ari[JUMP].frameX = 5;
	_ari[JUMP].img->init("image/ari_jump_sprite_01.bmp", _ariX, _ariY, 160, 82, _ari[JUMP].frameX, 2);

	_ari[FALL].frameX = 5;
	_ari[FALL].img->init("image/ari_fall_sprite_01.bmp", _ariX, _ariY, 160, 82, _ari[FALL].frameX, 2);

	_pipi[0].img = new image;
	_pipi[0].frameX = 2;
	_pipi[0].img->init("image/pipi_idle_sprite_01.bmp", _ariX, _ariY, 38, 60, _pipi[0].frameX, 2);

	_pipi[1].img = new image;
	_pipi[1].frameX = 2;
	_pipi[1].img->init("image/pipi_fly_sprite_01.bmp", _ariX, _ariY, 44, 48, _pipi[1].frameX, 2);

	for (int i = 0; i < MAXSTATE; i++) //벽잡는 rc
	{
		_ari[i].hangRc[0] = RectMake(_ari[i].img->boundingBoxWithFrame().left - 5, _ari[i].img->boundingBoxWithFrame().top, 5, 5);
		_ari[i].hangRc[1] = RectMake(_ari[i].img->boundingBoxWithFrame().right, _ari[i].img->boundingBoxWithFrame().top, 5, 5);
	}

	angle = 90.0f;
	speed = 7.0f;
	gravity = 0;
	_mapCorrX = _mapCorrY = 0;

	_state = IDLE;
	_isJump = 0;
	_isFall = 0;
	_isHang = 0;
	_count = _index = 0;
	_bgCount = _bgIndex = 0;
	_pipiIndex = 0;
	_dir = LEFT;

	return S_OK;
}

//=============================================================
//	## 해제 ## release(void)
//=============================================================
void mainGame::release(void)
{
	gameNode::release();
	//이미지 클래스 나갈때까진 사용할 일 없다
	//init함수에서 동적할당 new를 사용했다면 이곳에서 delete 사용한다

	SAFE_DELETE(_bgBack.img);
	SAFE_DELETE(_bgBuildAnim.img);
	SAFE_DELETE(_bgGirlAnim.img);
	for (int i = 0; i < MAXSTATE; i++)
		SAFE_DELETE(_ari[i].img);
}

//=============================================================
//	## 업데이트 ## update(void)
//=============================================================
void mainGame::update(void)
{
	gameNode::update();
	//이곳에서 계산식, 키보드, 마우스등등 업데이트를 한다
	//간단하게 이곳에서 코딩한다고 생각하면 된다

	for (int i = 0; i < MAXOBSTACLE; i++)
	{
		colliderRc[i].hangRc[0] = RectMake(colliderRc[i].rc.left, colliderRc[i].rc.top, 5, 5);
		colliderRc[i].hangRc[1] = RectMake(colliderRc[i].rc.right - 5, colliderRc[i].rc.top, 5, 5);
	}
	for (int i = 0; i < MAXSTATE; i++) //벽잡는 rc
	{
		_ari[i].hangRc[0] = RectMake(_ari[i].img->boundingBoxWithFrame().left - 5, _ari[i].img->boundingBoxWithFrame().top, 5, 5);
		_ari[i].hangRc[1] = RectMake(_ari[i].img->boundingBoxWithFrame().right, _ari[i].img->boundingBoxWithFrame().top, 5, 5);
	}

	_radarRc = RectMakeCenter(_ariX + _ari[_state].img->getFrameWidth() / 2, _ariY + _ari[_state].img->getFrameHeight() / 2, 300, 300);

	stateIdle();
	
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		//이미지 좌표를 움직이기
		if (!_isHang)
		{
			_dir = LEFT;
			stateWalk();
		}
	}
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		//이미지 좌표를 움직이기
		if (!_isHang)
		{
			_dir = RIGHT;
			stateWalk();
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (!_isJump && !_isFall)
		{
			gravity = 0.0f;
			_ariY -= 4;
			_isJump = true;
			if (_isHang)
			{
				_isHang = false;
			}
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (!_isFall)
		{
			_isFall = true;
		}
	}

	for (int i = 0; i < MAXSTATE; i++)
	{
		_ari[i].img->setX(_ariX);
		_ari[i].img->setY(_ariY);  
	}

	collideObject();
	stateJump();
	stateJumpUp();
	stateFall();
	stateHang();

	moveCameraXY();
	
	bgAnimLoop(&_bgBuildAnim);
	bgAnimLoop(&_bgGirlAnim);

	if (KEYMANAGER->isOnceKeyDown(VK_F5))
		init();
}

//=============================================================
//	## 렌더 ## render(HDC hdc)
//=============================================================
void mainGame::render(HDC hdc)
{
	//백버퍼 가져오기 (이건 렌더에 그냥 둘것!!)
	HDC memDC = this->getBackBuffer()->getMemDC();
	//흰색 빈 비트맵(이것도 렌더에 그냥 둘것!!)
	PatBlt(memDC, 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//=============================================================

	//백그라운드 렌더
	_bgBack.img->render(memDC, _bgBack.x, _bgBack.y);
	_bgBuildAnim.img->frameRender(memDC, _bgBack.x, _bgBack.y);

	if (KEYMANAGER->isToggleKey(VK_RETURN))
	{
		for (int i = 0; i < MAXOBSTACLE; i++)
		{
			Rectangle(memDC, colliderRc[i].rc);			//collider rect
			Rectangle(memDC, colliderRc[i].hangRc[0]);			//collider rect
			//Rectangle(memDC, colliderRc[i].hangRc[1]);
		}
		//Rectangle(memDC, _radarRc);
		Rectangle(memDC, _ari[_state].img->boundingBoxWithFrame());	//player rect
		Rectangle(memDC, _ari[_state].hangRc[0]);
		Rectangle(memDC, _ari[_state].hangRc[1]);
	}

	// pipi render

	//아리 프레임 이미지 렌더
	for (int i = 0; i < MAXSTATE; i++)
	{
		if (_state != i) continue;
		//_pipi[0].img->frameRender(memDC, _pipi[0].img->getX(), _pipi[0].img->getY());
		_ari[i].img->frameRender(memDC, _ari[i].img->getX(), _ari[i].img->getY());
	}

	_bgGirlAnim.img->frameRender(memDC, _bgBack.x, _bgBack.y + 254);

	_miniMap.img->render(memDC, 10, 10);

	if (IntersectRect(&_miniRc, &_bgBack.img->boundingBox(), &_ari[_state].img->boundingBoxWithFrame()))
	{
		EllipseMakeCenter(memDC, (_miniRc.left + _mapCorrX) / 7.5 + _miniMap.img->getWidth() / 2 + 5,
			(_miniRc.top + _mapCorrY) / 7.5 + _miniMap.img->getHeight() / 2 - 20, 5, 5);
	}//rgb 213, 84, 113

	//=============================================================
	//백버퍼의 내용을 HDC에 그린다 (이것도 렌더에 그냥 둘것!!)
	this->getBackBuffer()->render(hdc);
}

void mainGame::bgAnimLoop(bg* name)
{
	_bgCount++;
	if (_bgCount % 7 == 0)
	{
		_bgIndex--;
		if (_bgIndex < 0)
		{
			_bgIndex = name->frameY;
		}
		name->img->setFrameY(_bgIndex);
	}
}

void mainGame::characterAnimOnce(int dir, int state)
{
	if (dir == LEFT)
	{
		_count++;
		_ari[state].img->setFrameY(dir);
		if (_count % 8 == 0)
		{
			_index--;
			if (_index < 0)
			{
				_index = _ari[state].frameX;
			}
			_ari[state].img->setFrameX(_index);
		}
	}
	else//오른쪽프레임
	{
		_count++;
		_ari[state].img->setFrameY(dir);
		if (_count % 8 == 0)
		{
			_index++;
			if (_index > _ari[state].frameX)
			{
				_index = 0;
			}
			_ari[state].img->setFrameX(_index);
		}
	}
}

void mainGame::characterAnimLoop(int dir, int state)
{
	if (dir == LEFT)
	{
		_count++;
		_ari[state].img->setFrameY(dir);
		if (_count % 5 == 0)
		{
			_index--;
			if (_index < 0)
			{
				_index = _ari[state].frameX;
			}
			_ari[state].img->setFrameX(_index);
		}
	}
	else//오른쪽프레임
	{
		_count++;
		_ari[state].img->setFrameY(dir);
		if (_count % 5 == 0)
		{
			_index++;
			if (_index > _ari[state].frameX)
			{
				_index = 0;
			}
			_ari[state].img->setFrameX(_index);
		}
	}
}

void mainGame::stateIdle()
{
	_state = IDLE;
	characterAnimLoop(_dir, _state);
}

void mainGame::stateWalk()
{
	if (_state == IDLE || _state == WALK)
	{
		_state = WALK;
		characterAnimLoop(_dir, _state);
		if (_dir == LEFT)
			_ariX -= 2;
		else
			_ariX += 2;
	}
}

void mainGame::stateHang()
{
	if (_isHang)
	{
		_state = HANG;
		characterAnimOnce(_dir, _state);
	}
	if (KEYMANAGER->isOnceKeyDown('M'))
	{
		_state = IDLE;
		_isHang = false;
	}
}

void mainGame::stateJumpUp()
{
	if (_isJump)
	{
		if (_state == HANG)
		{
			_isHang = false;
			_state = JUMP_UP;

			characterAnimOnce(_dir, _state);

			gravity += 0.35f;
			_ariY -= sinf(angle) * speed;
			_ariY += gravity;
			if (_dir == LEFT)
			{
				_ariX -= 2;
			}
			else
			{
				_ariX += 2;
			}
		}
	}
}

void mainGame::stateJump()
{
	if (_isJump)
	{
		if (_state != HANG)
		{
			_state = JUMP;
			characterAnimOnce(_dir, _state);
			gravity += 0.45f;
			_ariY -= sinf(angle) * speed - gravity;
		}
	}
}

void mainGame::stateFall()
{
	if (_isFall && !_isJump)
	{
		_isHang = false;
		_state = FALL;
		characterAnimOnce(_dir, _state);
		gravity += 0.5f;
		_ariY += gravity;
	}
}

void mainGame::collideObject()
{
	_isFall = true;

	if (0 > _ari[_state].img->boundingBoxWithFrame().left)
		_ariX = 0;
	else if (_ari[_state].img->boundingBoxWithFrame().right > WINSIZEX)
		_ariX = WINSIZEX - _ari[_state].img->getFrameWidth();

	for (int j = 0; j < MAXOBSTACLE; j++)
	{
		/*if (IntersectRect(&temprc, &colliderRc[j].hangRc[1], &_ari[_state].hangRc[0]) && (_isJump || _isFall))	//플레이어의 왼쪽과 빌딩의 오른쪽이 부딪혔을 때
		{
			_ariX = colliderRc[j].hangRc[1].right;
			_ariY = colliderRc[j].hangRc[1].top - 4;
			//gravity = 0.0f;
			_dir = LEFT;
			_isJump = false;
			_isFall = false;
			_isHang = true;
		}
		else */if (IntersectRect(&temprc, &colliderRc[j].hangRc[0], &_ari[_state].hangRc[1]) && (_isJump || _isFall))	//플레이어의 오른쪽과 빌딩의 왼쪽이 부딪혔을 때
		{
			//_ariX = colliderRc[j].hangRc[0].left - _ari[HANG].img->getFrameWidth();
			//_ariY = colliderRc[j].hangRc[0].top - 4;
			gravity = 0.0f;
			_dir = RIGHT;
			_isJump = false;
			_isFall = false;
			_isHang = true;
		}
		if (IntersectRect(&temprc, &_ari[_state].img->boundingBoxWithFrame(), &colliderRc[j].rc))
		{
			if (j == 10 || j == 17 || j == 19)
				_ariX = colliderRc[j].rc.left - _ari[_state].img->getFrameWidth();
			else if (j == 18 || j == 20)
				_ariX = colliderRc[j].rc.right;
			else
			{
				if ((gravity == 0 && !_isJump) || (-sinf(angle) * speed * _isJump + gravity > 0) &&
					_ari[_state].img->boundingBoxWithFrame().bottom - (-sinf(angle) * speed * _isJump + gravity) <= colliderRc[j].rc.top &&
					_ari[_state].img->boundingBoxWithFrame().bottom > colliderRc[j].rc.top)
				{
					if (_isJump || _isFall)
					{
						_ariY = colliderRc[j].rc.top - _ari[_state].img->getFrameHeight() + 1;
						_isJump = false;
						_isFall = false;
						gravity = 0.0f;
					}
				}
			}
		}
	}
}

void mainGame::moveCameraXY()
{
	if (_radarRc.left < 0)
	{
		for (int i = 0; i < MAXOBSTACLE; i++)
		{
			colliderRc[i].rc.left -= _bgBack.x;
			colliderRc[i].rc.right -= _bgBack.x;
		}
		if (_bgBack.x >= 0)
		{
			_bgBack.x = 0;
		}
		else
		{
			_bgBack.x += 2;
			_ariX += 2;
			_mapCorrX -= 2;
		}
		for (int i = 0; i < MAXOBSTACLE; i++)
		{
			colliderRc[i].rc.left += _bgBack.x;
			colliderRc[i].rc.right += _bgBack.x;
		}
	}
	else if (_radarRc.right > WINSIZEX)
	{
		for (int i = 0; i < MAXOBSTACLE; i++)
		{
			colliderRc[i].rc.left -= _bgBack.x;
			colliderRc[i].rc.right -= _bgBack.x;
		}
		if (_bgBack.x + 864 <= WINSIZEX)
		{
			_bgBack.x = WINSIZEX - 864;
		}
		else
		{
			_bgBack.x -= 2;
			_ariX -= 2;
			_mapCorrX += 2;
		}
		for (int i = 0; i < MAXOBSTACLE; i++)
		{
			colliderRc[i].rc.left += _bgBack.x;
			colliderRc[i].rc.right += _bgBack.x;
		}
	}
}
