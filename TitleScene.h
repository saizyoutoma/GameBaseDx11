#pragma once
#include "Engine/GameObject.h"

//�^�C�g���V�[�����Ǘ�����N���X
class TitleScene : public GameObject
{
	int tPict_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TitleScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};