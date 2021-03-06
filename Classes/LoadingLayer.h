#pragma once
#include "CommonHeader.h"
#include "GameMediator.h"

class LoadingLayer :
	public Layer
{
public:
	LoadingLayer(void);
	~LoadingLayer(void);

	CREATE_FUNC(LoadingLayer);
	virtual bool init() override;
    
private:
	void onFrameEvent(Frame* frame) const;
};

