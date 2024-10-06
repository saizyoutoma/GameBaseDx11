#pragma once
#include "Engine/GameObject.h"
#include "array"

class Stage :
    public GameObject
{
    double DEC_TIMER = 1.0 / 60.0;
    double rTimer_;
    double oTimer_;
    double osTimer_;
    float speed_;
    std::array<int, 3>xa = { -2,0,2 };

public:
    //コンストラクタ
    Stage(GameObject* parent);

    //デストラクタ
    ~Stage();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

