# Codernix BLAKE3 PHP Extension

[![License](https://img.shields.io/badge/License-Apache_2.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![Latest Stable Version](https://img.shields.io/packagist/v/codernix/blake3-php-ext.svg?style=flat-square)](https://packagist.org/packages/codernix/blake3-php-ext)
[![Build Status](https://img.shields.io/travis/codernix/blake3-php-ext.svg?style=flat-square)](https://travis-ci.org/codernix/blake3-php-ext)

A high-performance PHP extension for the BLAKE3 cryptographic hash function.

BLAKE3 is a state-of-the-art cryptographic hash function that is significantly faster than MD5, SHA-1, SHA-2, and SHA-3, while providing a high level of security (128-bit security by default). This extension provides a direct binding to the highly optimized [blake3-c-wrapper](https://github.com/codernix/blake3-c-wrapper), which in turn uses the official Rust implementation.

For more details and articles, visit the **[official project page](https://codernix.com/open-source/cryptography/blake3-php-extension/)**.

## Features

* **Fast**: Blazing fast hashing, suitable for large files and data streams.
* **Secure**: Modern and secure design by top cryptographers.
* **Simple API**: A single function, `blake3_hash()`, for all your hashing needs.
* **Binary Output**: Returns a raw 32-byte (256-bit) hash.

## Requirements

* PHP 7.4 or newer (including PHP 8.0+).
* PHP development tools (`php-dev` on Debian/Ubuntu, `php-devel` on RHEL/CentOS).
* A C compiler (e.g., GCC or Clang).
* The [blake3-c-wrapper](https://github.com/codernix/blake3-c-wrapper) library must be installed.

## Installation

Installation is a three-step process: install the C library, compile and install the extension, and then enable it in your `php.ini`.

### Step 1: Install `blake3-c-wrapper`

First, you must compile and install the C wrapper library.
```bash
git clone [https://github.com/codernix/blake3-c-wrapper.git](https://github.com/codernix/blake3-c-wrapper.git)
cd blake3-c-wrapper
make
sudo make install
```
This typically installs the library to `/usr/local/lib` and headers to `/usr/local/include`.

### Step 2: Compile the PHP Extension

Now, compile the PHP extension itself.

```bash
# Clone the repository
git clone [https://github.com/codernix/blake3-php-ext.git](https://github.com/codernix/blake3-php-ext.git)
cd blake3-php-ext

# Prepare the build environment
phpize

# Configure the build.
# If you installed the wrapper to a custom location, specify it here.
# For a standard /usr/local installation, this is sufficient:
./configure --with-blake3

# For a custom path, for example /opt/blake3:
# ./configure --with-blake3=/opt/blake3

# Compile and install
make
sudo make install
```

### Step 3: Enable the Extension

Finally, add the following line to your `php.ini` file. You can find the location of this file by running `php --ini`.

```ini
extension=blake3.so
```

After adding the line, restart your web server or PHP-FPM process.

## Usage

The extension provides a single function: `blake3_hash()`.

**`blake3_hash(string $data): string`**

It takes a string of data and returns the 32-byte raw binary hash. To get a hex representation, simply use `bin2hex()`.

### Example

```php
<?php

// The input data to hash
$input = 'Hello, BLAKE3!';

// Generate the raw binary hash (32 bytes)
$binary_hash = blake3_hash($input);

// For display purposes, convert the binary hash to hexadecimal
$hex_hash = bin2hex($binary_hash);

echo "Input: " . $input . "\n";
echo "Binary Hash (length " . strlen($binary_hash) . "): " . $binary_hash . "\n";
echo "Hex Hash (length " . strlen($hex_hash) . "): " . $hex_hash . "\n";

// Expected Hex Output:
// 482c8e5432087612140a972c358b6c9e05869317d1b32d56a4891e06711516a7
?>
```

## License

This project is licensed under the Apache License 2.0. See the [LICENSE](LICENSE) file for details.

## Author

Created by Abou-Bakr Seddik Ouahabi. Visit [Codernix.com](https://codernix.com) for more open-source projects.