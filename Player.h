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
    //コンストラクタ
    Player(GameObject* parent);

    //デストラクタ
    ~Player();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //当たり判定
    void OnCollision(GameObject* pTarget) override;

    //ゲッター
    int GetScore() { return score_; }
};