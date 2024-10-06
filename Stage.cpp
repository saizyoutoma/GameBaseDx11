#include "Stage.h"
#include "Road.h"
#include "Enemy.h"
#include "Engine/Model.h"
#include "algorithm"
#include "random"

Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage")
{
}

Stage::~Stage()
{
}

void Stage::Initialize()
{
	Instantiate<Road>(this);
	speed_ = 0.1;
	for (int i = 0; i < 11; i++) {
		Instantiate<Road>(this, i * 5);
	}
}

void Stage::Update()
{
	if (FindObject("Player") != nullptr) {
		rTimer_ += DEC_TIMER;
		oTimer_ += DEC_TIMER;
		osTimer_ += DEC_TIMER;
		if (rTimer_ >= 0.8) {
			Instantiate<Road>(this, 50);
			rTimer_ = 0;
		}
		if (oTimer_ >= 2.0) {
			std::random_shuffle(std::begin(xa), std::end(xa));
			if (speed_ < 2.0) {
				if (osTimer_ >= 2.0) {
					speed_ += 0.1;
					osTimer_ = 0;
				}
			}
			for (int i = 0; i < 2; i++) {
				Instantiate<Enemy>(this, xa[i], speed_);
			}
			oTimer_ = 0;
		}
	}
}

void Stage::Draw()
{
}

void Stage::Release()
{
}
