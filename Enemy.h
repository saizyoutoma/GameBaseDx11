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
    //コンストラクタ
    Enemy(GameObject* parent);
    //x座標とspeed付き
    Enemy(GameObject* parent, int x_, float s_);
    //デストラクタ
    ~Enemy();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

