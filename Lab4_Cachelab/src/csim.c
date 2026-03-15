/* Minseok_Yoon_202170116 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "cachelab.h"

typedef struct {
    int valid;	// true: 1, false: 0
    int tag;
    int timestamp;
} line_t;

typedef struct {
    line_t *lines;
} set_t;

typedef struct {
    set_t *sets;
    int set_num;  // Number of set
    int line_num; // Number of lines per set
} cache_t;

cache_t cache;
int set_bits = 0, block_bits = 0;
int hits = 0, misses = 0, evictions = 0; // results

void initCache() {
	cache.sets = malloc(sizeof(set_t) * cache.set_num);
	for (int i=0; i<cache.set_num; i++) {
    	cache.sets[i].lines = calloc(sizeof(line_t), cache.line_num);
	}
}

void freeCache() {
	for (int i=0; i<cache.set_num; i++) free(cache.sets[i].lines);
	free(cache.sets);
}

void updateTimestamp(set_t *set, int line_index) {	// LRU algorithm
	line_t *current = &set->lines[line_index];

	for (int i=0; i<cache.line_num; i++) {
		line_t *other = &set->lines[i];
		if (!other->valid) continue;
		if (other->timestamp <= current->timestamp) continue;

		other->timestamp--;
	}
	current->timestamp = cache.line_num - 1;
}

void cacheAccess(int addr) {
	int set_index = (0x7fffffff >> (31 - set_bits)) & (addr >> block_bits);
	int tag = 0xffffffff & (addr >> (set_bits + block_bits));
	
	set_t *set = &cache.sets[set_index];

	for (int i=0; i<cache.line_num; i++) {
		line_t *line = &set->lines[i];
		if (!line->valid) continue;
    	if (line->tag != tag) continue;
		
		// cache hit!
		hits++;
		updateTimestamp(set,i);
		return;
	}
	
	// cache miss!
	misses++;

	for (int i=0; i<cache.line_num; i++) {
		line_t *line = &set->lines[i];
		if (line->valid) continue;
		
		// cold miss
		line->valid = 1;
		line->tag = tag;
		updateTimestamp(set,i);
		return;
	}

	// no empty cache	
	evictions++;
	
	for (int i=0; i<cache.line_num; i++) {
		line_t *line = &set->lines[i];
		if (line->timestamp) continue;

		line->valid = 1;
		line->tag = tag;
		updateTimestamp(set,i);
		return;
	}
}

int main(int argc, char *argv[]) {
	FILE *file = NULL;
	int opt;
	while ((opt = getopt(argc, argv, "s:E:b:t:")) != -1) {
		switch (opt) {
			case 's':
				set_bits = atoi(optarg); // Number of set index bits
        		cache.set_num = 2 << set_bits; // Number of sets
        		break;
			case 'E':
        		cache.line_num = atoi(optarg); // Number of lines per set
        		break;
      		case 'b':
        		block_bits = atoi(optarg); // Number of block bits
        		break;
      		case 't': // Input filename
        		if (!(file = fopen(optarg, "r"))) exit(1);
        		break;
      		default:
        		exit(1);
		}
	}	
	if (!set_bits || !cache.line_num || !block_bits || !file) exit(1);
	
	initCache();
	
   	// Parse trace input
	char op;
	int addr;
	while (fscanf(file, " %c %x%*c%*d", &op, &addr) != EOF) {
		switch (op) {
			case 'L': 
				cacheAccess(addr);
				break;
			case 'M':
                 cacheAccess(addr);
				 cacheAccess(addr);
                 break;
			case 'S':
                 cacheAccess(addr);
                 break;
			default: 
				 break;
		}
	}
	 
	printSummary(hits, misses, evictions);
    
	fclose(file);

	freeCache();	

	return 0;
}
