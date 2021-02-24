# BattleRub
BattleRub

cocos2d-x 4.0

-- to create iOS project
// if cmake hasn't installed
brew install cmake 

// edit this file to fix the library issue
cocos2d/cmake/modules/CocosConfigDepend.cmake

--
elseif(IOS)
...
    find_library(WEBKIT_LIBRARY WebKit)
   
    find_library(ZLIB z)
    find_library(ICONVLIB iconv)
list(...
    ${COCOS_APPLE_LIBS}
    ${ZLIB}
    ${ICONVLIB}
    #"/usr/lib/libz.dylib"
    #"/usr/lib/libiconv.dylib"
--

cmake ../.. -GXcode -DCMAKE_SYSTEM_NAME=iOS -DCMAKE_OSX_SYSROOT=iphoneos
sudo xcode-select --reset
