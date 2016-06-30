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
	// POSIX opendir/readdir/closedirが無いため、代替品の指定
	#define NOHAVE_READDIR

	#define HAVE_SSTREAM_H
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
#endif

