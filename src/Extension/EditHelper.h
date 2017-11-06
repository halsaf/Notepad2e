#pragma once
#include "stdafx.h"
#include "Scintilla.h"
#include "Edit.h"

#define ICON_FIND_OK 9
#define ICON_FIND_FAILED 26
#define FIND_INFO_INDEX 12

extern BOOL bUsePrefixInOpenDialog;
extern BOOL bHighlightSelection;
extern BOOL bCtrlWheelScroll;
extern BOOL bMoveCaretOnRightClick;
extern int iEvaluateMathExpression;
extern int iWordNavigationMode;
extern WCHAR wchLastHTMLTag[0xff];
extern WCHAR wchLastHTMLEndTag[0xff];

void n2e_StripHTMLTags(const HWND hwnd);
void n2e_JumpToOffset(const HWND hwnd, const int iNewPos);
void n2e_EditInsertNewLine(const HWND hwnd, const BOOL insertAbove);
BOOL n2e_ShowPromptIfSelectionModeIsRectangle(const HWND hwnd);
void n2e_FindNextWord(const HWND hwnd, LPCEDITFINDREPLACE lpref, const BOOL next);
int n2e_FindTextImpl(const HWND hwnd, const int searchFlags, const struct TextToFind* pttf);
BOOL n2e_CheckTextExists(const HWND hwnd, const int searchFlags, const struct TextToFind* pttf, const int iPos);
BOOL n2e_OpenNextFile(const HWND hwnd, LPCWSTR file, const BOOL next);
void n2e_UnwrapSelection(const HWND hwnd, const BOOL quote_mode);
void n2e_EscapeHTML(const HWND hwnd);
void n2e_UpdateFindIcon(const BOOL findOK);
void n2e_ResetFindIcon();
void n2e_EditString2Hex(const HWND hwnd);
void n2e_EditHex2String(const HWND hwnd);

void n2e_SaveCheckboxes(const HWND hwnd);
BOOL n2e_IsCheckboxChecked(const HWND hwnd, const UINT nCtrlID, const BOOL bCheckRestoredState);
void n2e_EditFindReplaceUpdateCheckboxes(const HWND hwnd, const UINT nCtrlID);
void n2e_EditFindReplaceInitialUpdateCheckboxes(const HWND hwnd);

BOOL n2e_IsSubclassedEditInCombo(const HWND hwnd);
BOOL n2e_SubclassEditInCombo(const HWND hwnd, const UINT idCombo);
BOOL n2e_SubclassOpenDialog(const HWND hwnd);

BOOL n2e_IsValidClosingTagA(LPCSTR pTag);
BOOL n2e_IsValidClosingTagW(LPCWSTR pwchTag);

void n2e_Init_EditInsertTagDlg(const HWND hwnd);
WCHAR* n2e_GetClosingTagText_EditInsertTagDlg(WCHAR* buf);
void n2e_SaveTagsData_EditInsertTagDlg(PTAGSDATA pdata);

void n2e_int2bin(unsigned int val, LPWSTR binString);
BOOL n2e_IsExpressionEvaluationEnabled();
int n2e_GetExpressionTextRange(int* piStart, int* piEnd);
