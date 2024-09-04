#pragma once

#include_next <mcuconf.h>

// UART0 か UART1 のどちらを使うかを指定する (今回は UART0 を使う)
#undef RP_SIO_USE_UART0
#undef RP_SIO_USE_UART1

#define RP_SIO_USE_UART0 TRUE
#define RP_SIO_USE_UART1 FALSE

// SPI0 か SPI1 かどちらを使うかを指定する (今回は SPI1 を使うように設定)
#undef RP_SPI_USE_SPI0
#undef RP_SPI_USE_SPI1

#define RP_SPI_USE_SPI0 FALSE
#define RP_SPI_USE_SPI1 TRUE