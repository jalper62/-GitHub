#include "DxLib.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	//�L�[�擾�p�z��
	char key[256];

	//x���W
	int x = 300, y = 240;



	//�O���t�B�b�N�n���h���i�[�p�z��
	int gh[12];


	//�摜�ǂݍ���
	LoadDivGraph("pipo-halloweenchara2016_01.png", 12, 3, 4, 32, 32, gh);

	//�ړ��W��
	float move = 1.0f;

	//�������Əc�����̃J�E���g���B
	int xcount = 0, ycount = 0;
	//�Y���p�ϐ�
	int ix = 0, iy = 0, result = 0;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0) {

		if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT] == 1) {

			if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1) {
				//�ړ��W�����O�D�V�P�ɐݒ�
				move = 0.71f;
			}
			else {
				//�΂߂���Ȃ���΂P�D�O�ɐݒ�
				move = 1.0f;
			}
		}
		else if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1) {
			move = 1.0f;
		}


		if (key[KEY_INPUT_LEFT] == 1) {
			x -= (int)4 * move;
		}
		if (key[KEY_INPUT_RIGHT] == 1) {
			x += (int)4 * move;

		}
		if (key[KEY_INPUT_UP] == 1) {
			y -= (int)4 * move;

		}
		if (key[KEY_INPUT_DOWN] == 1) {
			y += (int)4 * move;

		}

		//���L�[��������ĂāA����xcount���O�ȏ�Ȃ�O�ɂ��Ă���P�����B
		//����ȊO�͂P����
		if (key[KEY_INPUT_LEFT] == 1) {
			if (xcount > 0)
				xcount = 0;
			--xcount;

		}
		//�E�L�[��������ĂāA����xcount���O�ȉ��Ȃ�O�ɂ��Ă���P�����B
		//����ȊO�͂P����
		if (key[KEY_INPUT_RIGHT] == 1) {
			if (xcount < 0)
				xcount = 0;
			++xcount;
		}
		//��L�[��������ĂāA����ycount���O�ȏ�Ȃ�O�ɂ��Ă���P�����B
		//����ȊO�͂P����
		if (key[KEY_INPUT_UP] == 1) {
			if (ycount > 0)
				ycount = 0;
			--ycount;
		}
		//���L�[��������ĂāA����ycount���O�ȉ��Ȃ�O�ɂ��Ă���P�����B
		//����ȊO�͂P����
		if (key[KEY_INPUT_DOWN] == 1) {
			if (ycount < 0)
				ycount = 0;
			++ycount;
		}


		//�J�E���g������Y�������߂�B
		ix = abs(xcount) % 30 / 10;
		iy = abs(ycount) % 30 / 10;

		//x�J�E���g���v���X�Ȃ�E�����Ȃ̂�2�s�ڂ̐擪�Y���ԍ��𑫂��B
		if (xcount > 0) {
			ix += 3;
			result = ix;
		}
		else if (xcount < 0) {
			//�}�C�i�X�Ȃ獶�����Ȃ̂ŁA4�s�ڂ̐擪�Y���ԍ��𑫂��B
			ix += 9;
			result = ix;
		}

		//y�J�E���g���v���X�Ȃ牺�����Ȃ̂ŁA3�s�ڂ̐擪�Y���ԍ��𑫂��B
		if (ycount > 0) {
			iy += 6;
			result = iy;
		}
		else if (ycount < 0) {
			//�P�s�ڂ̐擪�Y���ԍ��͂O�Ȃ̂ŉ�������K�v�Ȃ��B(������₷�����邽�߂ɏ����Ƃ��܂���)
			iy += 0;
			result = iy;
		}

		//�΂߈ړ��̏ꍇ�͉����D��
		if (move == 0.71f)
			result = ix;


		//�`��
		DrawGraph(x, y, gh[result], TRUE);


		//������ĂȂ���΃J�E���g���[���ɂ���B
		if (key[KEY_INPUT_LEFT] != 1 && key[KEY_INPUT_RIGHT] != 1) {
			xcount = 0;
		}
		if (key[KEY_INPUT_UP] != 1 && key[KEY_INPUT_DOWN] != 1) {
			ycount = 0;
		}


		if (key[KEY_INPUT_ESCAPE] == 1) {

			break;
		}

	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}