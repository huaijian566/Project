// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 WIN32D_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// WIN32D_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef WIN32D_EXPORTS
#define WIN32D_API __declspec(dllexport)
#else
#define WIN32D_API __declspec(dllimport)
#endif

// 此类是从 Win32D.dll 导出的
class WIN32D_API CWin32D {
public:
	CWin32D(void);
	// TODO:  在此添加您的方法。
};

extern WIN32D_API int nWin32D;

WIN32D_API int fnWin32D(void);

WIN32D_API int GetInt();
