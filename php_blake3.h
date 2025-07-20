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
#ifndef PHP_BLAKE3_H
#define PHP_BLAKE3_H

#define PHP_BLAKE3_VERSION "0.1.0"

extern zend_module_entry blake3_module_entry;
#define phpext_blake3_ptr &blake3_module_entry

#endif // PHP_BLAKE3_H