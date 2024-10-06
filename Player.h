#pragma once
#include "Engine/GameObject.h"

class Player :
    public GameObject
{
    double DEC_TIMER = 1.0 / 60.0;
    int hPlayer_;
    double timer_;
    XMFLOAT3 spc = { 0.0f,3.5f,-5.0f };
    XMFLOAT3 stc = { 0.0f,0.0f,5.0f };
    int camState_;
    int score_;
public:
    //�R���X�g���N�^
    Player(GameObject* parent);

    //�f�X�g���N�^
    ~Player();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����蔻��
    void OnCollision(GameObject* pTarget) override;

    //�Q�b�^�[
    int GetScore() { return score_; }
};