/*
  +----------------------------------------------------------------------+
  | BLAKE3 PHP Extension                                                 |
  +----------------------------------------------------------------------+
  | Copyright (c) 2025 The BLAKE3 PHP Extension Authors                  |
  +----------------------------------------------------------------------+
  | This source file is subject to the Apache 2.0 license that is        |
  | bundled with this package in the file LICENSE, and is available      |
  | through the world-wide-web at the following url:                     |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  |                                                                      |
  | If you did not receive a copy of the license and are unable to       |
  | obtain it through the world-wide-web, please send a note to          |
  | aboubakr@codernix.com so we can mail you a copy immediately.         |
  +----------------------------------------------------------------------+
  | Author: Abou-Bakr Seddik Ouahabi <aboubakr@codernix.com>             |
  | For the latest information, visit:                                   |
  | https://codernix.com/open-source/cryptography/blake3-php-extension/  |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_blake3.h"
#include "blake3_wrapper.h"

// Define arginfo for the PHP function
ZEND_BEGIN_ARG_INFO_EX(arginfo_blake3_hash, 0, 0, 1)
    ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

PHP_FUNCTION(blake3_hash) {
    char *input;
    size_t input_len;
    // Use the constant from the header file
    unsigned char output[BLAKE3_OUT_LEN];

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &input, &input_len) == FAILURE) {
        RETURN_FALSE;
    }

    // Call the library function
    blake3_hash((const uint8_t *)input, input_len, output);

    // Return the result as a binary-safe PHP string
    RETURN_STRINGL((const char *)output, BLAKE3_OUT_LEN);
}

const zend_function_entry blake3_functions[] = {
    PHP_FE(blake3_hash, arginfo_blake3_hash)
    PHP_FE_END
};

zend_module_entry blake3_module_entry = {
    STANDARD_MODULE_HEADER,
    "blake3",
    blake3_functions,
    NULL, NULL, NULL, NULL, NULL,
    // Use version from your header. We provide an updated header as we update the Wrapper version, but check for your own use case
    PHP_BLAKE3_VERSION,
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(blake3)