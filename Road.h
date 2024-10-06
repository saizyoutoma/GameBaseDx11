#pragma once
#include "Engine/GameObject.h"

class Road :
    public GameObject
{
    int hRoad_;
    float speed_;
public:
    //コンストラクタ
    Road(GameObject* parent);

    //z座標付
    Road(GameObject* parent, int z_);

    //デストラクタ
    ~Road();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};


