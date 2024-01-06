#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// configure project setup here
#define COMPILER "clang"
#define CURRENT_WORKING_DIR "../"
#define SRC_DIR "src"
#define OUTPUT_DIR "output/"
#define PROGRAM_NAME "http-server"
#define C_FILES "http-server.c Networking/Server.c Networking/HttpRequest.c DataStructures/Common/Node.c DataStructures/Dictionary/Entry.c DataStructures/Dictionary/Dictionary.c DataStructures/Lists/LinkedList.c DataStructures/Lists/Queue.c DataStructures/Trees/BinarySearchTree.c"
#define INCLUDE "" 
#define LIB "-INetworking/Server.h"
#define FLAGS ""
#define RUN_PROGRAM_ON_COMPILE 1

//concatonation functions
#define STR(x) #x
#define COMPILE_COMMAND(compiler,current_working_dir,program_name) compiler " " LIB " " C_FILES " -o " current_working_dir OUTPUT_DIR program_name " " FLAGS " " INCLUDE
#define RUN_COMMAND(directory,program_name) directory program_name

int main() {
    remove(RUN_COMMAND(OUTPUT_DIR,PROGRAM_NAME));
    chdir(SRC_DIR);
    system(COMPILE_COMMAND(COMPILER,CURRENT_WORKING_DIR,PROGRAM_NAME));
    if (RUN_PROGRAM_ON_COMPILE == 1) {
        chdir(CURRENT_WORKING_DIR);
        chdir(OUTPUT_DIR);
        system(RUN_COMMAND("./",PROGRAM_NAME));
    }
}
