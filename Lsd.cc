//
// Name: Leven Shtein Distance (LSD)
//
// File Name  : lsd.cc (definition file)
// Header file: lsd.h  (header file)
//
#include "Lsd.h"

// コンストラクタ
Lsd::Lsd(void){
  // ロケール設定
  // ja_JP.UTF-8を利用する
  setlocale(LC_CTYPE, "ja_JP.UTF-8");
}

// デストラクタ
Lsd::~Lsd(void){}

//
// 動的計画法(dynamic programming)
//
// 引数: 文字列1,文字列2 
// 返値: 編集距離
//
// 概要: 2つのSTL::string型を入力として編集距離を返すクラス関数。
//       アルゴリズムは編集距離の一般的なアルゴリズムの動的計画法
//       計算量はO(mn)である。
//       プログラム冒頭で２次元配列を動的に取得していて若干速度面で不利
//       予めサイズを定義しているといいかもしれないが、Rubyから呼ばれる
//       soライブラなので速度よりは汎用性重視。
//
//       注意点)
//       Rubyで渡されてくStringはマルチバイト文字列として渡されて
//       くるため、このままではC++側で日本語文字列がうまく
//       編集距離が算出できないので内部でワイド文字列(wstring)に
//       変換してから計算する。
//
int Lsd::dp(const string &str1, const string &str2){
  // 変数初期化
  int ret = 0;
  int cost = 0;
  // ワイド文字列
  wstring wstr1;
  wstring wstr2;

  // マルチバイト文字列から
  // ワイド文字列に変換
  widen(str1,wstr1);
  widen(str2,wstr2);
  
  // 動的配列を取得
  int** d = new int*[(unsigned int)wstr1.size() + 1];
  for(int i = 0; i < (unsigned int)wstr1.size() + 1; ++i)
    d[i]= new int[(unsigned int)wstr2.size() + 1];
  
  // テーブルの初期化
  for (int i = 0; i < (unsigned int)wstr1.size() + 1; i++) 
    d[i][0] = i;
  for (int i = 0; i < (unsigned int)wstr2.size() + 1; i++)
    d[0][i] = i;
  
  // O(mn)の計算が必要
  for (int i = 1; i <  (unsigned int)wstr1.size() + 1; i++){
    for (int j = 1; j <  (unsigned int)wstr2.size() + 1; j++){
      wstr1[i-1] == wstr2[j-1] ? cost = 0 : cost = 1;
      d[i][j] =  
	min(min(d[i-1][j] + 1,       // 文字の挿入
		d[i][j-1] + 1),      // 文字の削除
	    d[i-1][j-1] + cost);     // 文字の置換
    }
  }
  // 結果を一旦、変数へストア
  ret = d[(unsigned int)wstr1.size()][(unsigned int)wstr2.size()];
  
  // メモリ開放
  for (int i= 0; i < (unsigned int)wstr1.size() + 1; ++i)
    delete[] d[i];
  delete[] d;
  
  // 編集距離値を返却
  return ret;
}

// ワイド文字列化
// 引数: マルチバイト文字列,ワイド文字列
// 返値: なし
//
// 概要: マルチバイト文字列からワイド文字列に変換
//
void Lsd::widen(const string &src, wstring &dest){
  wchar_t *wcs = new wchar_t[src.length() + 1];
  mbstowcs(wcs, src.c_str(), src.length() + 1);
  dest = wcs;
  delete [] wcs;
}
