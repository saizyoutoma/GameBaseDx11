#include "TitleScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "PlayScene"), tPict_(-1)
{
}

//初期化
void TitleScene::Initialize()
{
	//画像データのロード
	tPict_ = Image::Load("Image\\Title.png");
	assert(tPict_ >= 0);
}

//更新
void TitleScene::Update()
{
	//SPACE押したらPlaySceneに移行
	if (Input::IsKeyDown(DIK_SPACE)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//描画
void TitleScene::Draw()
{
	//画像の表示
	Image::SetTransform(tPict_, transform_);
	Image::Draw(tPict_);
}

//開放
void TitleScene::Release()
{
}