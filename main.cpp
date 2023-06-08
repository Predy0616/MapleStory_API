#define _AFXDLL
#include <afxinet.h>
#include <iostream>
#include <string>
#include <atlstr.h>

using namespace std;

int main()
{
	char* result =  new char[1024];
	string url, date = "2023-05-25", cursor, key, count, cursor;
	CString url2, date2, cursor2, key2, count2, cursor2;
	int cnt;
	//cin >> key >> cnt >> date;
	cin >> cnt;
	count = to_string(cnt);
	count2 = count.c_str();
	cursor2 = curcor.c_str();
	url2 = url.c_str();
	date2 = date.c_str();
	url2 = L"https://public.api.nexon.com/openapi/maplestory/v1/cube-use-results?count=" + count2 + "&date=" + date2 + "&cursor=" + cursor2;
	CInternetSession session(NULL, 1, INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, INTERNET_FLAG_DONT_CACHE);
	try
	{
		// 세션 클래스를 이용하여 열기
		CInternetFile* pinetFile = (CInternetFile*)session.OpenURL(url2);

		if (NULL != pinetFile)
		{
			char acRead[40960] = { 0, }; // return 값이 길 수 있으므로 충분히 입력
			memset(acRead, 0, sizeof(acRead));

			// json 읽는 부분
			UINT uiTotalRead = 0;
			int iIdex = 0;
			do
			{
				// 데이터를 1024씩 읽어 온다.
				uiTotalRead = pinetFile->Read(&acRead[iIdex], 1024);
				if (uiTotalRead <= 0)
					break;

				iIdex += uiTotalRead;
			} while (uiTotalRead > 0);

			// 읽은 json 표시를 위한 부분
			string strJson = acRead;
			cout << strJson;

			pinetFile->Close(); // Html 파일을 닫는다.			
			session.Close(); // 세션 종료

			delete pinetFile; // Html 파일 읽기에 사용한 객체를 파괴			
		}

	}
	catch (CInternetException* e)
	{
		// 에러
	}



	return 0;
}
