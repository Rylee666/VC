
// 实验7.2（3）Doc.h : C实验72（3）Doc 类的接口
//


#pragma once


class C实验72（3）Doc : public CDocument
{
protected: // 仅从序列化创建
	C实验72（3）Doc();
	DECLARE_DYNCREATE(C实验72（3）Doc)

// 特性
public:

// 操作
public:
	CRect re;
	bool set;
	int a, b;
// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~C实验72（3）Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
