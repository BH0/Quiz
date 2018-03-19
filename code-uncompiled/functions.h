
/// Functions 

void AddMenus(HWND hWnd) {
	// file: close + clear [and reset score to zero] as POPUP 
	// help: displays message-box 

	/// Create Menu [Windows] 
	hMenu = CreateMenu();
	HMENU hFileMenu = CreateMenu();

	/// Menu-item Options 
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_CLEAR, "Clear");
	AppendMenu(hFileMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_EXIT, "Exit");

	/// Main Menu Items 
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "File");
	AppendMenu(hMenu, MF_STRING, HELP, "Help");

	/// Assin menu to parent-window 
	SetMenu(hWnd, hMenu);
}

/// Controls / [Initialize/Define[ Windows] Functions 
void AddControls(HWND hWnd) {
	QuestionWindow(hWnd);
	OtherWindowComponents(hWnd);
}

void QuestionWindow(HWND hWnd) {
	hQuestion = CreateWindowW(L"static", L"Question", WS_VISIBLE | WS_CHILD, qw_x, qw_y, qw_width, qw_height, hWnd, NULL, NULL, NULL);
	SetWindowText(hQuestion, questions[question_index]);
}
void OtherWindowComponents(HWND hWnd) { // textbox, button, score 

										/// Textbox [for answer-input] 
	hInputAnswer = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, aw_x, aw_y, aw_width, aw_height, hWnd, NULL, NULL, NULL);

	/// Confirm answer button 
	hConfirmButton = CreateWindowW(L"button", L"Cofnrim answer", WS_VISIBLE | WS_CHILD | WS_BORDER, cw_x, cw_y, cw_width, cw_height, hWnd, (HMENU)CONFIRM_BUTTON, NULL, NULL);

	/// Score 
	hScore = CreateWindowW(L"static", L"Score", WS_VISIBLE | WS_CHILD | WS_BORDER, 10, 130, 90, 38, hWnd, (HMENU)CONFIRM_BUTTON, NULL, NULL);
}

/// Gneral [Custom] Functions 

void reset() {
	question_index = 0;
	questionsAnsweredCorrectly = 0; 
	SetWindowText(hQuestion, questions[question_index]);
	_itoa_s(questionsAnsweredCorrectly, scoreText, 10);
	SetWindowText(hScore, scoreText);
	SetWindowText(hInputAnswer, "");
}
void confirmAnswer() {
	if (question_index < 3) {
		char inputtedAnswer[10];
		GetWindowText(hInputAnswer, inputtedAnswer, 10);

		if (strcmp(inputtedAnswer, answers[question_index]) == 0) {
			MessageBox(NULL, "Correct", "corr", MB_OK);
			question_index += 1;
			questionsAnsweredCorrectly = question_index;
			SetWindowText(hQuestion, questions[question_index]);
			_itoa_s(questionsAnsweredCorrectly, scoreText, 10);
			SetWindowText(hScore, scoreText);
		}
		else {
			MessageBox(NULL, "Please try again", "Please try again", MB_OK);
		}
	}
}
