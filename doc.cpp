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


void CCircleMeasuringDlg::UpdateImage(int result)
{
	CRect rect;
	CDC *pdc = GetDC();
	Gdiplus::Image *pImage;
	Gdiplus::Graphics graphics(pdc->m_hDC);

	GetClientRect(&rect);
	switch (result)
	{
	case IMAGE_OK:
		pImage = Gdiplus::Image::FromFile(L"img\\OK.png");
		break;
	case IMAGE_NG:
		pImage = Gdiplus::Image::FromFile(L"img\\NG.png");
		break;
	case IMAGE_RECHECK:
		pImage = Gdiplus::Image::FromFile(L"img\\RC.png");
		break;
	default:
		pImage = Gdiplus::Image::FromFile(L"img\\ER.png");
		break;
	}

	graphics.DrawImage(
		pImage,
		rect.Width() * 812 / 1000,
		rect.Height() * 676 / 1000,
		pImage->GetWidth(),
		pImage->GetHeight());

	delete pImage;
	ReleaseDC(pdc);
}
