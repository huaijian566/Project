// Win32D.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "Win32D.h"
#define PI 3.1415926

// ���ǵ���������һ��ʾ��
WIN32D_API int nWin32D=0;

// ���ǵ���������һ��ʾ����
WIN32D_API int fnWin32D(void)
{
    return 42;
}


WIN32D_API int GetInt(int n) {
	if (n == 0)return 1;
	return n*GetInt(n - 1);
	/*int m = 1;
	for (int i = n; n > 0; i--)
	m = m*i;
	return m;*/
}


float CWin32D::conver(float deg) {
	double i;
	i = (deg / 180)*PI;
	return i;

	
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� Win32D.h
CWin32D::CWin32D()
{
    return;
}
