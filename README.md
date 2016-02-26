# foo

## What is this

Library ABI (source/binary) compatibility checker.

## Why

You don't want segfaults, do you..?

## How to use

1. Add the following to the root `CMakeLists.txt` file:

        configure_file ( "${PROJECT_SOURCE_DIR}/debian/lib${CMAKE_PROJECT_NAME}${VERSION_MAJOR}.acc.in"
          "${PROJECT_SOURCE_DIR}/debian/lib${CMAKE_PROJECT_NAME}${VERSION_MAJOR}.acc"
        )

2. Create a new file `debian/<library-package-name>.acc.in`:

        <?xml version="1.0" encoding="utf-8"?>
        <descriptor>

        <version>
            ${VERSION_FULL}
        </version>

        <headers>
            include/${CMAKE_PROJECT_NAME}/
        </headers>

        <libs>
            ${PROJECT_BINARY_DIR}/lib/lib${CMAKE_PROJECT_NAME}.so
        </libs>

        </descriptor>

3. Create initial base ABI dump (only needs to be done once).

        abi-compliance-checker -l libfoo0 -v1 0.1.0 -dump debian/libfoo0.acc -dump-path debian/libfoo0.abi.tar.gz

4. Push changes to git.

From now on all subsequent builds of the library will be compared to the base
ABI dump (*.abi.tar.gz) and if there are compatibility (source/binary) issues
the build will fail:

    comparing ABIs ...
    comparing APIs ...
    creating compatibility report ...
    result: COMPATIBLE
    total "Binary" compatibility problems: 1, warnings: 1
    total "Source" compatibility problems: 0, warnings: 0
    see detailed report:
    debian/libfoo0/usr/lib/i386-linux-gnu/dh-acc/libfoo0_0.2.0_report.html
    preparation, please wait ...
    comparing ABIs ...
