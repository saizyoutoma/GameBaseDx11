#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class PlayScene : public GameObject
{
	Text* pText_;
	double timer = 0;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	PlayScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};