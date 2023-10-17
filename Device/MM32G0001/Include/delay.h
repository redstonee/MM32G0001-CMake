#ifndef DELAY_H
#define DELAY_H

#include <mm32g0001.h>

#ifdef __cplusplus
extern "C"
{
#endif

    void initDelay(void);
    void delayMs(uint32_t Millisecond);

#ifdef __cplusplus
}
#endif

#endif // !DELAY_H