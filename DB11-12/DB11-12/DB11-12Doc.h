
// DB11-12Doc.h : CDB1112Doc ��Ľӿ�
//


#pragma once
#include "DB11-12Set.h"


class CDB1112Doc : public CDocument
{
protected: // �������л�����
	CDB1112Doc();
	DECLARE_DYNCREATE(CDB1112Doc)

// ����
public:
	CDB1112Set m_DB1112Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CDB1112Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
