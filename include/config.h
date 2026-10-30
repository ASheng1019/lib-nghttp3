/* SPDX-License-Identifier: BSD-3-Clause */
#ifndef UK_NGHTTP3_CONFIG_H
#define UK_NGHTTP3_CONFIG_H
/* This port uses a libc with POSIX headers, endian.h and byteswap.h. */
#define HAVE_ARPA_INET_H 1
#define HAVE_NETINET_IN_H 1
#define HAVE_UNISTD_H 1
#define HAVE_ENDIAN_H 1
#define HAVE_BYTESWAP_H 1
#define HAVE_DECL_BE64TOH 1
#define HAVE_DECL_BSWAP_64 1
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define WORDS_BIGENDIAN 1
#endif
#endif
