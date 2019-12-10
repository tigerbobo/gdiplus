// app.h

class CXXXApp : public CWinApp
{
// Implementation

	DECLARE_MESSAGE_MAP()
public:
	ULONG_PTR m_gdiplusToken;
public:
	virtual int ExitInstance();
};

// app.cpp

#pragma comment(lib,"gdiplus.lib")

BOOL CXXXApp::InitInstance()
{
  InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);

	CWinApp::InitInstance();
}

int CXXXApp::ExitInstance()
{
	// TODO: Add your specialized code here and/or call the base class
	Gdiplus::GdiplusShutdown(m_gdiplusToken);

	return CWinApp::ExitInstance();
}
