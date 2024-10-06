#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Engine/Camera.h"

enum CAM_TYPE
{
	FPS_TYPE,//�O�l��
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
	//���f���̓ǂݍ���
	hPlayer_ = Model::Load("Model\\Player.fbx");
	assert(hPlayer_ >= 0);
	//�����蔻��̂��߂̃R���W�����̐ݒ�
	SphereCollider* collision = new SphereCollider({ 0,0.3,0 }, 0.3f);
	AddCollider(collision);
	//�ʒu�Ƒ傫���̒���
	transform_.position_.y = 1.0;
	transform_.scale_ = XMFLOAT3(0.5, 0.5, 0.5);
}

void Player::Update()
{
	//A�������ꂽ�獶�Ɉړ�
	if (Input::IsKey(DIK_A)) {
		if (transform_.position_.x > -2) {
			transform_.position_.x -= 0.05;
		}
	}
	//D�������ꂽ��E�Ɉړ�
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
