# What is pragma

* Anything that begins with hash is known as a pre-processor command or a pre-processor directive.
* This is going to be evaluated by the C++ pre-processor before it actually gets compiled.
``` 
#pragma once

``` 
is an instruction that is sent to the compiler
* It means only include this file once.
* **A header Guard** ,  **A single translation unit**.
* Avoiding duplicate errors.

* Older convention

```
#ifndef _headerName_h
 #define _headerName_h
 
 #endif
 ```