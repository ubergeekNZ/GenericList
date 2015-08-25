# GenericList

Template list.

## Install google test and google mock to run unit test

Download:

    $ wget https://googlemock.googlecode.com/files/gmock-1.7.0.zip
    $ wget https://googletest.googlecode.com/files/gtest-1.7.0.zip 

Unzip:

    $ unzip gmock-1.7.0.zip
    $ unzip gtest-1.7.0.zip

Build:

    $ cd gmock-1.7.0
    $ ./configure
    $ make
    $ cd gtest-1.7.0
    $ ./configure
    $ make

Install headers and libs:

    $ sudo cp -a include/gtest /usr/include
    $ sudo cp -a lib/.libs/* /usr/lib/
    $ sudo cp -a include/gmock /usr/include
    $ sudo cp -a lib/.libs/* /usr/lib/

Update the cache of the linker:

    $ sudo ldconfig -v | grep gtest
    $ sudo ldconfig -v | grep gmock
    

Run unit test, just run the script which will build and run the unit test.
   
    $ ./buildtests
