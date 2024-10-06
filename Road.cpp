#include "Road.h"
#include "Engine/Model.h"

Road::Road(GameObject* parent)
	:GameObject(parent, "Road"), hRoad_(-1)
{
}

Road::Road(GameObject* parent, int z_)
	:GameObject(parent, "Road"), hRoad_(-1)
{
	transform_.position_.z = z_;
}

Road::~Road()
{
}

void Road::Initialize()
{
	hRoad_ = Model::Load("Model\\road3.fbx");
	assert(hRoad_ >= 0);
	transform_.position_.y = 0;
}

void Road::Update()
{
	if (FindObject("Player") != nullptr) {
		transform_.position_.z -= 0.1;
		if (transform_.position_.z < -5) {
			KillMe();
		}
	}
}

void Road::Draw()
{
	Model::SetTransform(hRoad_, transform_);
	Model::Draw(hRoad_);
}

void Road::Release()
{
}
