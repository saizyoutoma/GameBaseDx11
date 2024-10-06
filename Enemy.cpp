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
	//当たり判定のためのコリジョンの設定
	SphereCollider* collision = new SphereCollider({ 0,0.5,0 }, 0.4f);
	AddCollider(collision);
	//位置や向き、大きさの調整
	transform_.position_.y = 5;
	transform_.position_.z = 30;
	transform_.rotate_.y = 180;
	transform_.scale_ = XMFLOAT3(1.5, 1.5, 1.5);
}

void Enemy::Update()
{
	if (FindObject("Player") != nullptr) {
		//出てきた時に上から落ちてくるように
		if (transform_.position_.y > 0.5) {
			transform_.position_.y -= 0.2;
		}
		//落ちすぎてめり込んだりしないように
		else if (transform_.position_.y < 0.5) {
			transform_.position_.y = 0.5;
		}

		//画面奥から手前に少しずつ近づいてくる
		if (transform_.position_.y == 0.5) {
			transform_.position_.z -= speed_;
		}

		//画面外に出たら消す
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
