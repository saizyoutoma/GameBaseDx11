#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Engine/Camera.h"

enum CAM_TYPE
{
	FPS_TYPE,//三人称
};

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hPlayer_(-1),
	camState_(CAM_TYPE::FPS_TYPE)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	//モデルの読み込み
	hPlayer_ = Model::Load("Model\\Player.fbx");
	assert(hPlayer_ >= 0);
	//当たり判定のためのコリジョンの設定
	SphereCollider* collision = new SphereCollider({ 0,0.3,0 }, 0.3f);
	AddCollider(collision);
	//位置と大きさの調整
	transform_.position_.y = 1.0;
	transform_.scale_ = XMFLOAT3(0.5, 0.5, 0.5);
}

void Player::Update()
{
	//Aが押されたら左に移動
	if (Input::IsKey(DIK_A)) {
		if (transform_.position_.x > -2) {
			transform_.position_.x -= 0.05;
		}
	}
	//Dが押されたら右に移動
	else if (Input::IsKey(DIK_D)) {
		if (transform_.position_.x < 2)
			transform_.position_.x += 0.05;
	}

	switch (camState_)
	{
	case CAM_TYPE::FPS_TYPE:
	{
		XMFLOAT3 camPos;
		camPos.x = transform_.position_.x;
		camPos.y = transform_.position_.y + 1.0;
		camPos.z = transform_.position_.z + 0.2;
		Camera::SetPosition(camPos);
		Camera::SetTarget(XMFLOAT3(camPos.x, 0, 10));
	}
	}

	timer_ += DEC_TIMER;
	if (timer_ > 1.0f) {
		score_ += 10;
		timer_ = 0;
	}
}

void Player::Draw()
{
	Model::SetTransform(hPlayer_, transform_);
	Model::Draw(hPlayer_);
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Enemy") {
		this->KillMe();
	}
}
