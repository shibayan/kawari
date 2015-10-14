//---------------------------------------------------------------------------
//
// "華和梨" for あれ以外の何か以外の何か
// コンパイラ依存
//
//      Programed by NAKAUE.T (Meister)
//
// そのうちautoconfに対応させたりするのだろうか?
//
//---------------------------------------------------------------------------
#ifndef CONFIG_H
#define CONFIG_H

//---------------------------------------------------------------------------
// autoconfigもどき

#ifdef NDEBUG
    #undef _STLP_DEBUG
#else
    #define _STLP_DEBUG 1
#endif

#if defined(__MSDOS__)
#	define KAWARI_MS
#elif defined(WIN32)||defined(_WIN32)||defined(_Windows)||defined(_MSC_VER)
#	define KAWARI_MS
#	define KAWARI_WIN32
#elif defined(__CYGWIN__)
#	define KAWARI_POSIX
#	define KAWARI_WIN32
#	define KAWARI_MS
#elif defined(linux)||defined(_linux)
#	define KAWARI_LINUX
#	define KAWARI_POSIX
#else
#	define KAWARI_POSIX
#endif

//---------------------------------------------------------------------------
#ifdef _MSC_VER

#if _MSC_VER < 1300
	// STLを使うと必ず出る識別名255文字超Warningを抑制
	#pragma warning(disable:4786)

	// forのスコープがANSIに準拠していない問題対策(篠原君考案の手法)
	// 参考文献 http://www.ksky.ne.jp/~seahorse/cpp/loopvar.html
	#ifndef for
	#define for if(0);else for
	#endif

	// cstdlib等がstd名前空間を使っていないために起こるエラーを抑制
	namespace std{}
#endif

	// POSIX opendir/readdir/closedirが無いため、代替品の指定
	#define NOHAVE_READDIR

    // stringstream は持ってる
    #define HAVE_SSTREAM_H

    // ネイティブさおりんを有効にする
    #define ENABLE_SAORI_NATIVE

#if !defined(DISABLE_ALL_HACK) && !defined(DISABLE_DEBUGGER)
    // デバッガを有効にする
    #define ENABLE_DEBUGGER
#endif

#if !defined(DISABLE_ALL_HACK) && !defined(DISABLE_FAST_OPTIMIZE)
    // 高速化を有効にする
    #define ENABLE_FAST_OPTIMIZE
#endif

#endif
//---------------------------------------------------------------------------
#ifdef __BORLANDC__
	// BCCのvectorはデフォルトで最初に1KBメモリーを確保するので
	// メモリー使用効率が悪化する
	// 参照 : BCC5.5.1 memory.stlの111行目付近
	#define _RWSTD_CONTAINER_BUFFER_SIZE 4
	
	#define STRING_APPEND_INATOMIC

#endif
//---------------------------------------------------------------------------
#ifdef __MINGW32__
# if defined(_WIN32)
	// 他のヘッダよりも先に windows.h を読み込む 
	// （でないと生成バイナリが例外で落ちるみたいなので） 
# include <windows.h>
# endif
	#define STRING_APPEND_INATOMIC
#endif
//---------------------------------------------------------------------------
#if defined(__GNUC__)
#	if (__GNUC__ >= 3)
#		define HAVE_SSTREAM_H
#	endif
#endif
//---------------------------------------------------------------------------
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#ifdef HAVE_SSTREAM_H
#include <sstream>
#else
#include <strstream>
#endif
//---------------------------------------------------------------------------
#if _MSC_VER >= 1300 && defined(ENABLE_FAST_OPTIMIZE)

//// 関数定義
//#define DEFINE_RTTI_FUNCTION virtual int Typeid() const; static const int _typeid;
//// 高速な RTTI 実装もどきを自動実装する
//#define FAST_RTTI_FUNCTION(name) const int name::_typeid = __COUNTER__; int name::Typeid() const { return name::_typeid; }

// 関数定義
#define DEFINE_RTTI_FUNCTION virtual int Typeid() const;
// 高速な RTTI 実装もどきを自動実装する
#define FAST_RTTI_FUNCTION(name) int name::Typeid() const { return __COUNTER__; }

#else

#define DEFINE_RTTI_FUNCTION

#endif
//---------------------------------------------------------------------------
#endif

