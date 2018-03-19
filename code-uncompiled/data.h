
/// Question-index, Score & Questions/Answers 
int question_index;
char scoreText[10] = "Score: ";
int questionsAnsweredCorrectly;
/*
Putting "thanks for playing" as the last index is actually a quick-fix/hack as beforehand whenever the player completed the game, it would ignore
the SetWindowText function and hQuestion would become "yes" possibly because the first index in the next closest array is "yes"
*/
char questions[][80] = { "Are cats blue?", "Are dons blue?", "Are cats orange?", "Thanks for playing" }; // the first "[]" is the number of questions/answersa
char answers[][30] = { "yes", "no", "no" };

/// Window Handlers/Instances & [IDs] 
HMENU hMenu;
HWND hQuestion, hInputAnswer, hConfirmButton, hScore; // hOutput - currently a MessageBox; 

/// Sizing & Positiong [Possibly styling too[ (Could possibly be stored in structs for organization purposes 
// Parent Window 
int pw_width = 400, pw_height = 400; 
int pw_x = 100, pw_y = 100; 

// Question Window 
int qw_x = 100, qw_y = 50;
int qw_width = 98, qw_height = 38; 

// Answer Window 
int aw_x = 100, aw_y = 90; 
int aw_width = 98, aw_height = 38; 

// Comfirm  [Button] Window 
int cw_x = 100, cw_y = 120;
int cw_width = 98, cw_height = 38; 

// Score Window 
int sw_x = 10, sw_y = 130;
int sw_width = 90, sw_height = 38; 

// note: some/all text is still hard-coded 
