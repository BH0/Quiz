/// Pre-build Dependancies 
#include <windows.h> 

//// Custom Dependancies 
#include "constants.h"
#include "data.h" // includes "Window Handlers/Instances & [IDs]" too 
#include "prototypes.h"  
#include "functions.h" 


/// Entry Point 
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
	
	reset(); 

	/// Initialzie Parent Window Class 
	WNDCLASSW wc = { 0 }; 
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW; 
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 
	wc.lpszClassName = L"WindowClass"; 
	wc.lpfnWndProc = WindowProcedure; 

	/// Ensure Window was loaded correctly 
	if (!RegisterClassW(&wc)) {
		return -1; 
	} 
	
	/// Create Window 
	CreateWindowW(L"WindowClass", L"Quiz", WS_OVERLAPPEDWINDOW | WS_VISIBLE, pw_x, pw_y, pw_width, pw_height, NULL, NULL, NULL, NULL);

	/// Handle messages 
	MSG msg = { 0 }; 
	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg); 
		DispatchMessage(&msg); 
	}

	return 0; 
} 

/// Window Procedure - event handling 
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_COMMAND: 
		switch (wp) { 
			case FILE_MENU_CLEAR: // clear / reset / restart 
				reset(); 
				break; 
			case FILE_MENU_EXIT:
				DestroyWindow(hWnd);
				break;
			case HELP: // help/information 
				MessageBox(NULL, "Help", "A quiz-app made by me", MB_OK);
				break; 
			case CONFIRM_BUTTON:
				confirmAnswer(); 
				break; 
		} 
		break;
	case WM_CREATE:
		AddMenus(hWnd);
		AddControls(hWnd); // questionWindow, answer-textbox, button, score 
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProcW(hWnd, msg, wp, lp);
	}
}



