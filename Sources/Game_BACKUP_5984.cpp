#include "Game.hpp"
#include "Settings.hpp"


// TODO: 砲台の位置を画面左に、ターゲットの位置を画面右に移動させる。(A)
// TODO: 雲の位置を左から右に動かす。見えなくなったら左端に戻す。(B)
// TODO: 砲台を青い壁に沿って上下に動かす。(C)
// TODO: 弾のスピードを速くし、弾が画面右端を通り越したら再度発射可能にする。(D)
// TODO: スコアのサイズを大きくする。(E)
// TODO: スコアを100点ずつ加算するようにし、5桁の表示に変える。(F)
// TODO: PlayBGM()関数を使って、BGMを再生する。(G)
// TODO: PlaySound()関数を使って、弾の発射時とターゲットに当たった時にSEを再生する。(H)


Vector2 cloudPos;       //!< 雲の位置
Vector2 cannonPos;      //!< 砲台の位置
Vector2 cannonInitPos;  //!< 砲台の初期位置(実装：HW15A062　菊地龍大)
Vector2 bulletPos;      //!< 弾の位置
Rect    targetRect;     //!< ターゲットの矩形
int     score;          //!< スコア
float   bulletSpeed;    //!< スピードの値

// ゲーム開始時に呼ばれる関数です。
void Start()
{
    cloudPos = Vector2(-320, 100);
    cannonPos = Vector2(-300, -150);// 砲台の位置を左に(実装：HW15A062　菊地龍大)
    cannonInitPos = cannonPos;// 砲台の初期位置を取得(実装：HW15A062　菊地龍大)
    targetRect = Rect(260, -140, 40, 40);// ターゲットの位置を右に(実装：HW15A062　菊地龍大)
    bulletPos.x = -999;
    score = 0;
<<<<<<< HEAD
    PlayBGM("bgm_maoudamashii_8bit07.mp3"); //ゲームのBGM（実装:HW15A213 山本 裕生）
=======
    // HW15A153 Noma Ryoji
    bulletSpeed = 500;
    //PlayBGM();　ゲームのBGM
>>>>>>> 218d3363e5379c939539da436e0396f6860ee972
}

// 1/60秒ごとに呼ばれる関数です。モデルの更新と画面の描画を行います。
void Update()
{
    // 弾の発射
    if (bulletPos.x <= -999 && Input::GetKeyDown(KeyMask::Space)) {
        bulletPos = cannonPos + Vector2(50, 10);
        PlaySound("se_maoudamashii_explosion03.mp3"); //弾発射時のSE（実装:HW15A213 山本 裕生）
    }

    // 弾の移動
    if (bulletPos.x > -999) {
        // HW15A153 Noma Ryoji (D)
        bulletPos.x += bulletSpeed * Time::deltaTime;

        // ターゲットと弾の当たり判定
        Rect bulletRect(bulletPos, Vector2(32, 20));
        if (targetRect.Overlaps(bulletRect)) {
<<<<<<< HEAD
            score += 1;         // スコアの加算
            PlaySound("se_maoudamashii_system27.mp3"); //スコア加算時のSE（実装:HW15A213 山本 裕生）
=======
            score += 100;         // スコアの加算 //HW16A007
            bulletPos.x = -999; // 弾を発射可能な状態に戻す
        }
        
        // HW15A153 Noma Ryoji (D)
        if (bulletPos.x > SCREEN_SIZE.x / 2) {
>>>>>>> 218d3363e5379c939539da436e0396f6860ee972
            bulletPos.x = -999; // 弾を発射可能な状態に戻す
            PlaySound("se_maoudamashii_system20.mp3"); //弾が当たった時のSE（実装:HW15A213 山本 裕生）
        }
    }

    // 背景の描画
    Clear(Color::cyan);
    FillRect(Rect(-320, -240, 640, 100), Color::green);

    // 雲の描画
    DrawImage("cloud1.png", cloudPos);
    cloudPos.x += 40 * Time::deltaTime; //HW16A007 Ikeda Yuto
    if(cloudPos.x >= SCREEN_SIZE.x/2){
        cloudPos.x =-320;               //HW16A007 IkedaYuto
    }

    // 弾の描画
    if (bulletPos.x > -999) {
        DrawImage("bullet.png", bulletPos);
    }

    // 砲台の描画
    FillRect(Rect(cannonInitPos.x-10, -140, 20, 100), Color::blue);// 描画位置を砲台の初期位置に(実装：HW15A062　菊地龍大)
    cannonPos.y = -160 + 100 * Mathf::PingPong(Time::time, 1.0f);// 砲台を自動的に上下移動させる(実装：HW15A062　菊地龍大)
    DrawImage("cannon.png", cannonPos);

    // ターゲットの描画
    FillRect(targetRect, Color::red);

    // スコアの描画
<<<<<<< HEAD
    SetFont("nicoca_v1.ttf", 20.0f);
    DrawText(FormatString("%02d", score), Vector2(-319, 199), Color::black);
    DrawText(FormatString("%02d", score), Vector2(-320, 200), Color::white);
    
=======
    //HW15A153 Noma Ryoji (E)
    SetFont("nicoca_v1.ttf", 100.0f);
    DrawText(FormatString("%05d", score), Vector2(-319, 150), Color::black); //HW16A007
    DrawText(FormatString("%05d", score), Vector2(-320, 150), Color::white); //HW16A007
>>>>>>> 218d3363e5379c939539da436e0396f6860ee972
}

