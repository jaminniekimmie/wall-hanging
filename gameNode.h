#pragma once
#include "image.h"

class gameNode
{
private:
	image * _backBuffer;		//백버퍼 이미지
	void setBackBuffer();		//백버퍼 세팅하기

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(HDC hdc);

	//백버퍼 이미지 얻기
	image* getBackBuffer(void) { return _backBuffer; }

	//메인 프로시져
	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

	gameNode() {}
	virtual ~gameNode() {} //소멸자에 virtual 키워드를 붙이는 이유 면접시 당골질문임
};

