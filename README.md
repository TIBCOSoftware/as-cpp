as-cpp
======

C++ API for TIBCO ActiveSpaces

# Download and Setup
To install the c++ API, see instructions below. **Important** you can download the source code using:

```
git clone https://github.com/TIBCOSoftware/as-cpp.git
```

###Linux compile
After cloning, go to the repo

```
 $ export AS_HOME={path-to-as-installation}
 $ cd as-cpp
 $ make -j4
```

###Windows compile
```
define AS_HOME in environment variables
Open visual studio project (Visual studio 2013 or later) 
Compile the project producing the Debug/Release version of C++ api
```
Windows gives warning about classes in the std namespace. These can be ignored. 

###Using the library files
The c++ library files will be produced that can be used by clients applications

- Linux make sure LD_LIBRARY_PATH includes reference to as-cpp\lib folder
- Windows make sure Visual Studio project refers to {Debug|Release}\x64 location

