#pragma once
#include "CommonHeader.h"

class BackLayer :
	public Layer
{
public:
	BackLayer(void);
	~BackLayer(void);

	virtual bool init();

	CREATE_FUNC(BackLayer);

	void moveBackSprite(int stage);
	void moveRandomBackSprite();

private:
	void flyBackSprite(float dt, Vector<Sprite*>* vSprites, float duration);
	void flyRandomBackSprite(float dt, float duration);

private:
	map<int, Vector<Sprite*>>	m_mBackSprites;

	int m_nCurStage;
};

