//---------------------------------------------------------------------------
//
// "������" for ����ʳ��β����ʳ��β���
// ����ѥ����¸
//
//      Programed by NAKAUE.T (Meister)
//
// ���Τ���autoconf���б��������ꤹ��Τ�����?
//
//---------------------------------------------------------------------------
#ifndef CONFIG_H
#define CONFIG_H

//---------------------------------------------------------------------------
// autoconfig��ɤ�

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
	// STL��Ȥ���ɬ���Ф뼱��̾255ʸ��ĶWarning������
	#pragma warning(disable:4786)

	// for�Υ������פ�ANSI�˽�򤷤Ƥ��ʤ������к�(�ĸ����ͰƤμ�ˡ)
	// ����ʸ�� http://www.ksky.ne.jp/~seahorse/cpp/loopvar.html
	#ifndef for
	#define for if(0);else for
	#endif

	// cstdlib����std̾�����֤�ȤäƤ��ʤ�����˵����륨�顼������
	namespace std{}
#endif

	// POSIX opendir/readdir/closedir��̵�����ᡢ�����ʤλ���
	#define NOHAVE_READDIR

    // stringstream �ϻ��äƤ�
    #define HAVE_SSTREAM_H

    // �ͥ��ƥ��֤�������ͭ���ˤ���
    #define ENABLE_SAORI_NATIVE

#if !defined(DISABLE_ALL_HACK) && !defined(DISABLE_DEBUGGER)
    // �ǥХå���ͭ���ˤ���
    #define ENABLE_DEBUGGER
#endif

#if !defined(DISABLE_ALL_HACK) && !defined(DISABLE_FAST_OPTIMIZE)
    // ��®����ͭ���ˤ���
    #define ENABLE_FAST_OPTIMIZE
#endif

#endif
//---------------------------------------------------------------------------
#ifdef __BORLANDC__
	// BCC��vector�ϥǥե���ȤǺǽ��1KB���꡼����ݤ���Τ�
	// ���꡼���Ѹ�Ψ����������
	// ���� : BCC5.5.1 memory.stl��111�����ն�
	#define _RWSTD_CONTAINER_BUFFER_SIZE 4
	
	#define STRING_APPEND_INATOMIC

#endif
//---------------------------------------------------------------------------
#ifdef __MINGW32__
# if defined(_WIN32)
	// ¾�Υإå�������� windows.h ���ɤ߹��� 
	// �ʤǤʤ��������Х��ʥ꤬�㳰�������ߤ����ʤΤǡ� 
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

//// �ؿ����
//#define DEFINE_RTTI_FUNCTION virtual int Typeid() const; static const int _typeid;
//// ��®�� RTTI ������ɤ���ư��������
//#define FAST_RTTI_FUNCTION(name) const int name::_typeid = __COUNTER__; int name::Typeid() const { return name::_typeid; }

// �ؿ����
#define DEFINE_RTTI_FUNCTION virtual int Typeid() const;
// ��®�� RTTI ������ɤ���ư��������
#define FAST_RTTI_FUNCTION(name) int name::Typeid() const { return __COUNTER__; }

#else

#define DEFINE_RTTI_FUNCTION

#endif
//---------------------------------------------------------------------------
#endif

