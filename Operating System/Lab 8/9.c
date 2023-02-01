// Memory Management Scheme - Paging

#include <stdio.h>
#include <stdlib.h>

int main() {
    int base_address, page_size, num_pages, mem_unit, memory_limit;
    int page_number, displacement, physical_address;
    int *page_table;

    printf("Program for Paging");
    printf("Enter:\n");

    printf("base address: ");
    scanf("%d", &base_address);

    printf("page size: ");
    scanf("%d", &page_size);

    printf("number of pages: ");
    scanf("%d", &num_pages);

    printf("memory unit: ");
    scanf("%d", &mem_unit);

    memory_limit = mem_unit * num_pages;
    if (memory_limit < base_address) {
        printf("Memory limit is less than base address.\n");
        return 0;
    }

    // Create the page table
    printf("\nPage Table:\nPageNo.\tBase Address");
    page_table = (int *)malloc(num_pages * sizeof(int));
    for (int i = 0; i < num_pages; i++) {
        page_table[i] = base_address + i * page_size;
        printf("\n%d\t%d", i, page_table[i]);
    }

    printf("\n\nEnter the page number and displacement value: ");
    scanf("%d %d", &page_number, &displacement);

    if (page_number >= num_pages || displacement >= page_size) {
        printf("Page not found or displacement should be less than page size.\n");
        return 0;
    }

    // Calculate the physical address
    physical_address = page_table[page_number] + displacement;
    printf("\nPage No.\tBase Address\tPhysical Address\n");
    printf("%d\t\t%d\t\t%d\n", page_number, page_table[page_number], physical_address);
    return 0;
}
