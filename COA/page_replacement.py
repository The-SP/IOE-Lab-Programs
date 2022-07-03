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
    page_hits = len(pages) - page_faults
    hit_ratio = page_hits / (page_hits + page_faults)
    return hit_ratio


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
    page_hits = len(pages) - page_faults
    hit_ratio = page_hits / (page_hits + page_faults)
    return hit_ratio


def LFU(pages, capacity):
    page_faults = 0
    page_list = []
    hash = {}  # To store the pair (page, frequency)

    for page in pages:
        # MISS
        if page not in page_list:
            if len(page_list) == capacity:
                # Remove least frequently used element (first element)
                hash.pop(page_list[0])
                page_list.pop(0)
            # Store current page
            page_list.append(page)
            hash[page] = 0
            # Increment page fault
            page_faults += 1

        # HIT
        else:
            # Remove previous index of current page
            page_list.remove(page)
            # Apped it at last index
            page_list.append(page)
            # Increase frequency
            hash[page] += 1

        # Sort the pages based on their frequency (Insert current page)
        i = len(page_list) - 2
        while (hash[page_list[i]] > hash[page_list[i + 1]]) and i >= 0:
            page_list[i], page_list[i + 1] = page_list[i + 1], page_list[i]
            i -= 1

    page_hits = len(pages) - page_faults
    hit_ratio = page_hits / (page_hits + page_faults)
    return hit_ratio


if __name__ == "__main__":
    pages = [2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2]
    print("FIFO:", FIFO(pages, 3))
    print("LRU:", LRU(pages, 3))
    print("LFU:", LFU(pages, 3))
