#include "GameOver.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Player.h"

GameOver::GameOver(GameObject* parent)
	:GameObject(parent, "GameOver"), pText_(nullptr)
{
}

void GameOver::Initialize()
{
	rPict_ = Image::Load("Image\\GameOver.png");
	assert(rPict_ >= 0);

	pText_ = new Text;
	pText_->Initialize();
}

void GameOver::Update()
{
	//T押されたらタイトルシーンに移動
	if (Input::IsKey(DIK_T)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
	//R押されたらプレイシーンに移動
	else if (Input::IsKey(DIK_R)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void GameOver::Draw()
{
	Image::SetTransform(rPict_, transform_);
	Image::Draw(rPict_);
}

void GameOver::Release()
{
}
