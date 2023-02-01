// Memory Management Scheme - Segmentation

#include <stdio.h>
#include <stdlib.h>

void main() {
    int base_address[20], limit[20], num_segments, memory_limit;
    int segment_number, displacement, physical_address;

    printf("Enter number of segments: ");
    scanf("%d", &num_segments);
    printf("Enter memory limit: ");
    scanf("%d", &memory_limit);

    printf("\nEnter base address and limit of each segment:\n");
    for (int i = 0; i < num_segments; i++) {
        printf("Segment %d: ", i);
        scanf("%d %d", &base_address[i], &limit[i]);
        if (base_address[i] + limit[i] > memory_limit) {
            printf("Invalid memory limit \n");
            exit(0);
        }
    }

    printf("\nEnter the segment number and displacement value: ");
    scanf("%d %d", &segment_number, &displacement);

    if (segment_number >= num_segments || displacement >= limit[segment_number]) {
        printf("Invalid segment number or displacement.\n");
        exit(0);
    }

    // Calculate the physical address
    physical_address = base_address[segment_number] + displacement;
    printf("\nSegment No.\tBase Address\tPhysical Address\n");
    printf("%d\t\t%d\t\t%d\n", segment_number, base_address[segment_number], physical_address);
}
