// crt_signal.c
// compile with: /EHsc /W4
// Use signal to attach a signal handler to the abort routine
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

void SignalHandler(int signal)
{
    if (signal == SIGABRT) {
        // abort signal handler code
        printf("Exception: ABORT\n");
    }
    else {
        // ...
    }
}

int main()
{
    typedef void (*SignalHandlerPointer)(int);

    SignalHandlerPointer previousHandler;
    previousHandler = signal(SIGABRT, SignalHandler);

    abort();
}