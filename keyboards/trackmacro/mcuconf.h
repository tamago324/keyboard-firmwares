#pragma once

#include_next <mcuconf.h>

#undef RP_SPI_USE_SPI0
#undef RP_SPI_USE_SPI1

// SPI0 か SPI1 かどちらを使うかを指定する (今回は SPI0 を使うように設定)
#define RP_SPI_USE_SPI0 FALSE
#define RP_SPI_USE_SPI1 TRUE