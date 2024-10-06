#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), enemy_(-1), pText_(nullptr)
{
}

Enemy::Enemy(GameObject* parent, int x_, float s_)
	:GameObject(parent, "Enemy"), enemy_(-1), pText_(nullptr)
{
	transform_.position_.x = x_;
	speed_ = s_;
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	enemy_=Model::Load("Model\\Enemy.fbx");
	assert(enemy_ >= 0);
	//�����蔻��̂��߂̃R���W�����̐ݒ�
	SphereCollider* collision = new SphereCollider({ 0,0.5,0 }, 0.4f);
	AddCollider(collision);
	//�ʒu������A�傫���̒���
	transform_.position_.y = 5;
	transform_.position_.z = 30;
	transform_.rotate_.y = 180;
	transform_.scale_ = XMFLOAT3(1.5, 1.5, 1.5);
}

void Enemy::Update()
{
	if (FindObject("Player") != nullptr) {
		//�o�Ă������ɏォ�痎���Ă���悤��
		if (transform_.position_.y > 0.5) {
			transform_.position_.y -= 0.2;
		}
		//���������Ă߂荞�񂾂肵�Ȃ��悤��
		else if (transform_.position_.y < 0.5) {
			transform_.position_.y = 0.5;
		}

		//��ʉ������O�ɏ������߂Â��Ă���
		if (transform_.position_.y == 0.5) {
			transform_.position_.z -= speed_;
		}

		//��ʊO�ɏo�������
		if (transform_.position_.z < -5) {
			KillMe();
		}
	}
}

void Enemy::Draw()
{
	Model::SetTransform(enemy_, transform_);
	Model::Draw(enemy_);
}

void Enemy::Release()
{
}
