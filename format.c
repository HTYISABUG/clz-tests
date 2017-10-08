#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("./format execute min max\n");
        exit(EXIT_FAILURE);
    }

    int min = atoi(argv[2]);
    int max = atoi(argv[3]);

    FILE *ip, *op;
    char tmp[200], *tp, output[200];

    for (int i = min; i < max; i++) {
        // read .perf
        sprintf(tmp, ".tmp/%d.perf", i);
        ip = fopen(tmp, "r");

        // flush trash string
        fgets(tmp, 200, ip);
        fgets(tmp, 200, ip);
        fgets(tmp, 200, ip);
        fgets(tmp, 200, ip);
        fgets(tmp, 200, ip);

        // cycles
        sprintf(output, "%d ", i);
        fscanf(ip, "%s", tmp);
        tp = strtok(tmp, ",");
        while (tp != NULL) {
            strcat(output, tp);
            tp = strtok(NULL, ",");
        }
        strcat(output, "\n");
        strcpy(tmp, argv[1]);
        strcat(tmp, "-cycles.perf");
        op = fopen(tmp, "a");
        fputs(output, op);
        fclose(op);
        fgets(tmp, 200, ip);

        // flush instructions & branches
        fgets(tmp, 200, ip);
        fgets(tmp, 200, ip);

        // branch-misses
        sprintf(output, "%d ", i);
        fscanf(ip, "%s", tmp);
        fscanf(ip, "%s", tmp);
        fscanf(ip, "%s", tmp);
        fscanf(ip, "%s", tmp);
        tp = strtok(tmp, "%");
        while (tp != NULL) {
            strcat(output, tp);
            tp = strtok(NULL, "%");
        }
        strcat(output, "\n");
        strcpy(tmp, argv[1]);
        strcat(tmp, "-branch-misses.perf");
        op = fopen(tmp, "a");
        fputs(output, op);
        fclose(op);
        fgets(tmp, 200, ip);

        // time
        /*sprintf(output, "%d ", i);*/
        /*fscanf(ip, "%s", tmp);*/
        /*strcat(output, tmp);*/
        /*strcat(output, "\n");*/
        /*strcpy(tmp, argv[1]);*/
        /*strcat(tmp, "-time.perf");*/
        /*op = fopen(tmp, "a");*/
        /*fputs(output, op);*/
        /*fclose(op);*/

        // close ip
        fclose(ip);
    }

    return 0;
}
