#include "message.h"
#include "storage.h"
#include "cache.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char* policies[] = {"LRU", "RANDOM"};
    ReplacementPolicy policy_enums[] = {LRU_REPLACEMENT, RANDOM_REPLACEMENT};
    const char* output_files[] = {"results/lru_results.txt", "results/random_results.txt"};

    for (int p = 0; p < 2; ++p) {
        init_cache();
        set_replacement_policy(policy_enums[p]);

        FILE* input = fopen("data/input.txt", "r");
        if (!input) {
            perror("Failed to open data/input.txt");
            return 1;
        }

        FILE* output = fopen(output_files[p], "w");
        if (!output) {
            perror("Failed to open output file");
            fclose(input);
            return 1;
}


        if (!input || !output) {
            printf("Error opening input or output file.\n");
            return 1;
        }

        int hits = 0;
        int misses = 0;
        char id[128];

        while (fscanf(input, "%127s", id) == 1) {
            if (get_from_cache(id)) {
                hits++;
                fprintf(output, "[Cache] Message ID %s found in cache.\n", id);
            } else {
                misses++;
                Message* msg = create_msg(id, "AutoSender", "AutoReceiver", "Simulated content");

                if (msg != NULL) {
                    store_msg(msg);
                    free(msg);
                } else {
                    fprintf(stderr, "Failed to create message for ID %s\n", id);
                }
            }
        }

        double ratio = (hits + misses) ? (hits * 100.0 / (hits + misses)) : 0.0;

        fprintf(output, "\n=== Cache Test Report ===\n");
        fprintf(output, "Policy: %s\n", policies[p]);
        fprintf(output, "Total Accesses: %d\n", hits + misses);
        fprintf(output, "Cache Hits: %d\n", hits);
        fprintf(output, "Cache Misses: %d\n", misses);
        fprintf(output, "Hit Ratio: %.2f%%\n", ratio);

        fclose(input);
        fclose(output);
    }

    return 0;
}
