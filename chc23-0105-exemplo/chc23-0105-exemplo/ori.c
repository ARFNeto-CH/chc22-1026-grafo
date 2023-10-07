#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR lpCmdLine, INT nCmdShow) {

    MSG  msg;
    WNDCLASSW wc = { 0 };
    wc.lpszClassName = L"Static Control";
    wc.hInstance = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc = WndProc;
    wc.hCursor = LoadCursor(0, IDC_ARROW);


    RegisterClassW(&wc);
    CreateWindowW(wc.lpszClassName, L"Exemplo",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        100, 100, 300, 300, 0, 0, hInstance, 0);

    while (GetMessage(&msg, NULL, 0, 0)) {

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
    WPARAM wParam, LPARAM lParam) {

    static wchar_t* texto = L"Feche essa janela";

    switch (msg) {

    case WM_CREATE:
        CreateWindowW(L"Static", texto,
            WS_CHILD | WS_VISIBLE | SS_LEFT,
            20, 20, 300, 230,
            hwnd, (HMENU)1, NULL, NULL);
        break;

    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        PostMessage(GetConsoleWindow(), WM_CLOSE, 0, 0);
        break;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}