#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

/*!
 * @brief     ホスト名を出力する
 * @return    0:success/-1:failure
 */
    static int
show_hostname(void)
{
    char hname[BUFSIZ];
    int rc = 0;

    rc = gethostname(hname, sizeof(hname));
    if(rc < 0){
        printf("Error: gethostname() %s\n", strerror(errno));
        return(-1);
    }

    fprintf(stdout, "hostname = %s\n", hname);

    return(0);
}

    int
main(int argc, char *argv[])
{
    int rc = 0;

    if(argc != 1){
        fprintf(stderr, "Usage: %s\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    rc = show_hostname();
    if(rc != 0) exit(EXIT_FAILURE);

    exit(EXIT_SUCCESS);
}
