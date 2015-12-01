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

	void setBackImageFor(int id);
	void changeBackImageFromTo(int fromId, int toId);
	void moveBackSprite(int stage);
	void moveRandomBackSprite();

private:
	void flyBackSprite(float dt, Vector<Sprite*>* vSprites, float duration);
	void flyRandomBackSprite(float dt, float duration);

private:
	Map<int, Layout*>	m_mBackImages;
	map<int, Vector<Sprite*>>	m_mBackSprites;

	Sprite*	m_pSpriteFly;

	int m_nCurStage;
};

