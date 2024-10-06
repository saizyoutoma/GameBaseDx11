#pragma once
#include "Engine/GameObject.h"

class Road :
    public GameObject
{
    int hRoad_;
    float speed_;
public:
    //�R���X�g���N�^
    Road(GameObject* parent);

    //z���W�t
    Road(GameObject* parent, int z_);

    //�f�X�g���N�^
    ~Road();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};


