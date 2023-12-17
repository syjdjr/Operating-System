# include "types.h"
# include "user.h"
# include "date.h"

int
main (int argc, char *argv[])
{

        struct rtcdate d;

        if (date(&d)) {
                printf(2, "date failed\n");
                exit();
        }else{

        printf(1, "Current time : %d-%d-%d %d:%d:%d\n", d.year, d.month, d.day, d.hour, d.minute, d.second);


        exit();
        }
}

