
// com_waves.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCom_wavesApp: 
// �йش����ʵ�֣������ com_waves.cpp
//

class CCom_wavesApp : public CWinApp
{
public:
	CCom_wavesApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCom_wavesApp theApp;