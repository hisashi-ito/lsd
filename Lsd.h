//
// Name: Leven Shtein Distance (LSD)
//
// File Name  : lsd.h    (header file)
// Header file: lsd.cc   (definition file)
//
// 概要: 編集距離計算用クラスのHeaderファイル
//       編集距離算出関数はクラス関数として実装されてる
//
#ifndef _LSD_
#define _LSD_
#include <string>
using namespace std;
class Lsd{
 public:
  // コンストラクタ
  Lsd(void);
  // デストラクタ
  ~Lsd(void);
  // 動的計画法(dynamic programming)
  int dp(const string &str1,const string &str2);
 private:
  // マルチバイト文字列からワイド文字列へ変換
  void widen(const string &src,wstring &dest);
};
#endif /*_LSD_*/
