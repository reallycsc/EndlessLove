#pragma once
#include "CommonHeader.h"

class PlayerUpgradeScene :
	public Scene
{
public:
	PlayerUpgradeScene(void);
	~PlayerUpgradeScene(void);

	CREATE_FUNC(PlayerUpgradeScene);

	virtual bool init();  
};

