#include "zlog.h"
#include "zoptions.h"

#include "mhodb.h"
#include "tcpserver.h"

using namespace LibChaos;

int main(int argc, char **argv){
    ZLog::logLevelStdOut(ZLog::INFO, "%time% %thread% N %log%");
    ZLog::logLevelStdOut(ZLog::DEBUG, "\x1b[35m%time% %thread% D %log%\x1b[m");
    ZLog::logLevelStdErr(ZLog::ERRORS, "\x1b[31m%time% %thread% E [%function%|%file%:%line%] %log%\x1b[m");

    try {

        MhoDB db("psb.db");

        TCPServer server(4);
        server.run();

    } catch(ZException e){
        ELOG("EXCEPTION: " << e.what());
    }

    return 0;
}

