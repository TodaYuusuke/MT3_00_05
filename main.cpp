#include <Novice.h>
#include <Matrix4x4Func.h>

const char kWindowTitle[] = "MT3_00_05_確認課題_LE2B_21_トダ_ユウスケ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Vector3 scale{ 1.2f,0.79f,-2.1f };
	Vector3 rotate{ 0.4f,1.43f,-0.8f };
	Vector3 translate{ 2.7f,-4.15f,1.57f };
	Matrix4x4 worldMatrix = MakeAffineMatrix(scale, rotate, translate);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		Novice::DrawTriangle(0, 0, 0, 0, 0, 0, WHITE, kFillModeSolid);
		Novice::DrawTriangle(0, 0, 0, 0, 0, 0, WHITE, kFillModeSolid);
		Novice::DrawTriangle(0, 0, 0, 0, 0, 0, WHITE, kFillModeSolid);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		MatrixScreenPrintf(0, 0, worldMatrix, "worldMatrix");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
