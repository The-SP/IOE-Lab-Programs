def FIFO(pages, capacity):
    # Store current pages in Queue
    queue = []
    page_faults = 0
    for page in pages:
        # MISS
        if page not in queue:
            # If the queue is full, remove oldest page
            if len(queue) == capacity:
                queue.pop(0)
            # Store current page into the queue
            queue.append(page)
            # Increment page fault
            page_faults += 1
    return page_faults


def LRU(pages, capacity):
    # Current pages in Main Memory
    page_list = []
    page_faults = 0

    for page in pages:
        # MISS
        if page not in page_list:
            if len(page_list) == capacity:
                page_list.pop(0)
            # Store current page
            page_list.append(page)
            # Increment page fault
            page_faults += 1

        # HIT
        else:
            # Remove previous index of current page
            page_list.remove(page)
            # Apped it at last index
            page_list.append(page)
    return page_faults


if __name__ == "__main__":
    pages = [7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2]
    print("FIFO:", FIFO(pages, 4))
    print("LRU:", LRU(pages, 4))
