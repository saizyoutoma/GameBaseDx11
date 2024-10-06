#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class Enemy :
    public GameObject
{
    Text* pText_;
    int enemy_;
    float speed_;
public:
    //�R���X�g���N�^
    Enemy(GameObject* parent);
    //x���W��speed�t��
    Enemy(GameObject* parent, int x_, float s_);
    //�f�X�g���N�^
    ~Enemy();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

